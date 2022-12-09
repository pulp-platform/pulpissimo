//-----------------------------------------------------------------------------
// Title         : Simplified PULP Testbench
//-----------------------------------------------------------------------------
// File          : tb_pulp_simple.sv
// Author        : Manuel Eggimann  <meggimann@iis.ee.ethz.ch>
// Created       : 05.12.2022
//-----------------------------------------------------------------------------
// Description :
// This is a simplified RTL testbench for PULPissimo that support simulation of
// arbitrary binaries that have been converted to srec format. Checkout the
// available plusargs for more information.
//-----------------------------------------------------------------------------
// Copyright (C) 2013-2022 ETH Zurich, University of Bologna
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.
//-----------------------------------------------------------------------------

`timescale 1ns/100ps

module tb_pulp_simple;

  // Choose your core: 0 for RISCY, 1 for IBEX RV32IMC (formerly ZERORISCY), 2 for IBEX RV32EC (formerly MICRORISCY)
  parameter CORE_TYPE = 0;

  // if RI5CY is instantiated (CORE_TYPE == 0), USE_FPU enables the FPU
  parameter USE_FPU = 1;

  // if RI5CY uses ZFINX (merged float and integer register files)
  parameter USE_ZFINX = 0;

  // Enables/Disables the virtual stdout feature within PULPissimo. The virtual
  // stdout allows the TB to communicate through a stdout with the PULPissimo by
  // means of through hierarchy connections. This is way faster than UART
  // simulation but is purely virtual and cannot not be realized in hardware.
  parameter SIM_STDOUT = 1;

  // UART baud rate in bps
  parameter BAUDRATE = 115200;


  // Available plusargs:

  // +BOOTMODE="jtag_openocd"|"jtag_legacy"|"fastboot"
  // Description
  //
  // Selects the mode with which to bootstrap the firmware:
  // "jtag_openocd"
  //    communicates with the internal RISC-V debug unit to preload
  //    the binary into memory.
  // "jtag_legacy" uses the RISC-V debug unit to control
  //    the core but uses the faster legacy pulp_jtag_tap for binary preloading.
  // "fastboot"
  //   In this bootmode, the binary is preloaded by directly tougling the
  //   soc_interconnect debug bus by means of through-hierarchy connections to
  //   the TB. This bootmode is very fast but is not physical and thus does not
  //   verify that we could correctly communicate with a real chip.
  //
  // Default:
  // jtag_legacy

  // +BINARY_SREC_PATH="my_firmware.srec"
  // Description:
  //
  // The executable to execute on PULPissimo in Srecord format. Srecords is a
  // standardized format to represent binary data in ascii text format. Notably,
  // it also encodes also the entry point. GNU objcopy (part of binutils) can
  // easily convert and elf file to this format.
  //
  // Default:
  // None, this is a required plusarg for simulation of binaries.

  string    BOOTMODE;
  string    BINARY_SREC_PATH;

  // Parse plusargs
  initial begin : parse_plus_args
    if (!$value$plusargs("BOOTMODE=%s", BOOTMODE))
      BOOTMODE = "jtag_legacy";
    if (!$value$plusargs("BINARY_SREC_PATH=%s", BINARY_SREC_PATH))
      // At the moment, all bootmodes require a user provided binary. It is thus
      // an error not to provide one.
      $fatal("BINARY_SREC_PATH is a required plusarg. Please specify a binary to execute on PULPissimo", -1);
  end

  //////////////////////////////////////////////////////////
  // Fixed Parameters. Just changing these thus not work! //
  //////////////////////////////////////////////////////////

  // period of the external reference clock (32.769kHz)
  localparam time REF_CLK_PERIOD = 30517ns;
  localparam IO_PAD_COUNT = gpio_reg_pkg::GPIOCount; // Check the README on how
                                                     // to modify the pad count
  localparam logic [9:0] FC_CORE_ID = {5'd31, 5'd0};
  localparam             EXIT_SUCCESS = 0;
  localparam             EXIT_FAIL = 1;


  /////////////
  // Imports //
  /////////////
  import srec_pkg::*;
  
  /////////////////////////
  // Signal Declarations //
  /////////////////////////

  // TB signals
  logic [95:0] stimuli[$];  // array for the stimulus vectors
  jtag_pkg::test_mode_if_t test_mode_if    = new;
  jtag_pkg::debug_mode_if_t debug_mode_if  = new;
  pulp_tap_pkg::pulp_tap_if_soc_t pulp_tap = new;
  logic [255:0][31:0] jtag_data;

  // DUT Connection Signals
  wire                     w_pad_ref_clk;
  wire                     w_pad_clk_byp_en;
  wire                     w_pad_reset_n;
  wire [1:0]               w_bootsel;
  wire [1:0]               w_pad_hyper_csn;
  wire                     w_pad_hyper_reset_n;
  wire                     w_pad_hyper_ck;
  wire                     w_pad_hyper_ckn;
  wire [7:0]               w_pad_hyper_dq;
  wire                     w_pad_hyper_rwds;
  wire                     w_pad_jtag_tck;
  wire                     w_pad_jtag_tdi;
  wire                     w_pad_jtag_tdo;
  wire                     w_pad_jtag_tms;
  wire                     w_pad_jtag_trstn;
  wire [IO_PAD_COUNT-1:0]  w_pad_io;

  // DUT Control Signals
  // Clock, Reset & Bootmode
  logic                    s_clk_ref;
  logic                    s_hard_reset_n = 1'b0;
  logic [1:0]              s_bootsel;
  // JTAG
  logic                    s_jtag_tck = 1'b0;
  logic                    s_jtag_tdi = 1'b0;
  logic                    s_jtag_tdo;
  logic                    s_jtag_tms = 1'b0;
  logic                    s_jtag_trstn = 1'b0;
  // UART
  logic                    s_uart_rx_en = 1'b1;
  logic                    s_uart_chip2vip; // (from chip to TB) Connected to pad_io[0]
  logic                    s_uart_vip2chip; // (from TB to chip) Connected to pad_io[1]
  // HyperBus
  logic                    s_hyper_ck;
  logic                    s_hyper_ckn;
  logic [1:0]              s_hyper_csn;
  logic                    s_hyper_reset_n;
  logic                    s_hyper_rwds;
  logic [7:0]              s_hyper_dq_from_chip;
  logic [7:0]              s_hyper_dq_to_chip = '0;
  logic [7:0]              s_hyper_dq_tx_en = '0;

  //////////////////////
  // Wire Assignments //
  //////////////////////

  // Clock, Reset & Bootmode
  assign w_pad_ref_clk = s_clk_ref;
  assign w_pad_clk_byp_en = 1'b0; // Not used by this TB
  assign w_pad_reset_n    = s_hard_reset_n;
  assign w_bootsel = s_bootsel;

  // JTAG
  assign w_pad_jtag_tck   = s_jtag_tck;
  assign w_pad_jtag_tms   = s_jtag_tms;
  assign w_pad_jtag_trstn  = s_jtag_trstn;
  assign w_pad_jtag_tdi   = s_jtag_tdi;
  assign s_jtag_tdo = w_pad_jtag_tdo;

  // UART
  assign s_uart_chip2vip = w_pad_io[0];
  assign w_pad_io[1] = s_uart_vip2chip;

  // HyperBus (Not used at this point)
  assign s_hyper_ck = w_pad_hyper_ck;
  assign s_hyper_ckn = w_pad_hyper_ckn;
  for (genvar i = 0; i < 8; i++) begin: gen_assign_hyper_dq_wires
    assign s_hyper_dq_from_chip[i] = w_pad_hyper_dq[i];
    assign w_pad_hyper_dq[i]       = s_hyper_dq_tx_en[i]? s_hyper_dq_to_chip: 1'bz;
  end


  ////////////////////////////////
  // Reference Clock generation //
  ////////////////////////////////

  tb_clk_gen #(
    .CLK_PERIOD(REF_CLK_PERIOD)
  ) i_ref_clk_gen (
    .clk_o(s_clk_ref)
  );

  //////////
  // VIPs //
  //////////

  // UART receiver
  uart_sim #(
    .BAUD_RATE ( BAUDRATE ),
    .PARITY_EN ( 0        )
  ) i_uart_sim (
    .rx    ( s_uart_chip2vip ),
    .rx_en ( s_uart_rx_en    ),
    .tx    ( s_uart_vip2chip )
  );


  /////////
  // DUT //
  /////////

  pulpissimo #(
    .CORE_TYPE ( CORE_TYPE ),
    .USE_FPU   ( USE_FPU   ),
    .USE_ZFINX ( USE_ZFINX ),
    .USE_HWPE  ( 1'b0      ), //TODO Re-expose once debugged why it is not working
    .SIM_STDOUT(SIM_STDOUT)
  ) i_dut (
    .pad_ref_clk       ( w_pad_ref_clk      ),
    .pad_reset_n       ( w_pad_reset_n       ),
    .pad_clk_byp_en    ( w_pad_clk_byp_en    ),
    .pad_bootsel0      ( w_bootsel[0]        ),
    .pad_bootsel1      ( w_bootsel[1]        ),
    .pad_jtag_tck      ( w_pad_jtag_tck      ),
    .pad_jtag_tdi      ( w_pad_jtag_tdi      ),
    .pad_jtag_tdo      ( w_pad_jtag_tdo      ),
    .pad_jtag_tms      ( w_pad_jtag_tms      ),
    .pad_jtag_trstn    ( w_pad_jtag_trstn    ),
    .pad_hyper_csn     ( w_pad_hyper_csn     ),
    .pad_hyper_reset_n ( w_pad_hyper_reset_n ),
    .pad_hyper_ck      ( w_pad_hyper_ck      ),
    .pad_hyper_ckn     ( w_pad_hyper_ckn     ),
    .pad_hyper_dq      ( w_pad_hyper_dq      ),
    .pad_hyper_rwds    ( w_pad_hyper_rwds    ),
    .pad_io            ( w_pad_io            )
  );


  /////////////////////
  // TB Boot Process //
  /////////////////////

  initial begin: load_and_run_binary
    automatic srec_record_t records[$];
    int entry_point;
    int exit_code;

    // Set timing format for %t format specifiers
    $timeformat(-9, 0, "ns", 9);

    // Load Stimuli
    $display("[TB] %t: PULPissimo Testbench started with bootmode %s", $realtime, BOOTMODE);
    $display("[TB] %t: Loading Stimuli from stimuli file %s", $realtime, BINARY_SREC_PATH);
    srec_read(BINARY_SREC_PATH, records);
    srec_records_to_stimuli(records, stimuli, entry_point);
    $display("[TB] %t: Finished loading stimuli from SREC file. Binary contains %0d words and has entrypoint %08h", $realtime, stimuli.size(), entry_point);

    case (BOOTMODE)
      "jtag_legacy", "jtag_openocd": begin
        s_bootsel = 2'd1;
      end

      default: begin
        s_bootsel = 2'd0; // Boot in default mode which enables either zforth or
                          // SREC over UART booting. Depends on the enabled
                          // features in the bootrom.
      end
    endcase


    // Assert hard reset
    $display("[TB] %t: Asserting hard reset for 5 ref_clk cycles...", $realtime);
    s_hard_reset_n = 1'b0;
    #(REF_CLK_PERIOD*5);
    s_hard_reset_n = 1'b1;

    $display("[TB] %t: Hard reset released. Running some JTAG sanity tests", $realtime);
    #(REF_CLK_PERIOD*5); // Wait another couple of ref clock cycles for the SoC to
                         // become ready (FLL init).
    // before starting the actual boot procedure we do some light
    // testing on the jtag link
    jtag_sanity_tests(entry_point, s_jtag_tck, s_jtag_tms, s_jtag_trstn, s_jtag_tdi, s_jtag_tdo);

    $display("[TB] %t: Done. Starting boot sequence", $realtime);
    case (BOOTMODE)
      "jtag_legacy": begin
        boot_jtag_legacy(entry_point, stimuli, s_jtag_tck, s_jtag_tms, s_jtag_trstn, s_jtag_tdi, s_jtag_tdo);
      end

      "fastboot": begin
        boot_fast(entry_point, stimuli, s_jtag_tck, s_jtag_tms, s_jtag_trstn, s_jtag_tdi, s_jtag_tdo);
      end

      default: begin
        //boot_jtag_legacy(entry_point, stimuli, s_jtag_tck, s_jtag_tms, s_jtag_trstn, s_jtag_tdi, s_jtag_tdo);
      end
    endcase


    $display("[TB] %t: Waiting for end of computation", $realtime);
    wait_for_end_of_computation(s_jtag_tck, s_jtag_tms, s_jtag_trstn, s_jtag_tdi, s_jtag_tdo, exit_code);

    $display("[TB] %t: TB Execution finished with exit code %0d", $realtime, exit_code);
    $stop;
  end


  //////////////
  // TB Tasks //
  //////////////

  task automatic jtag_sanity_tests(
    int entry_point,
    ref logic s_tck,
    ref logic s_tms,
    ref logic s_trstn,
    ref logic s_tdi,
    ref logic s_tdo
  );

    jtag_pkg::jtag_reset(s_tck, s_tms, s_trstn, s_tdi);
    jtag_pkg::jtag_softreset(s_tck, s_tms, s_trstn, s_tdi);
    #5us;

    jtag_pkg::jtag_bypass_test(s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    #5us;

    jtag_pkg::jtag_get_idcode(s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    #5us;
    test_mode_if.init(s_tck, s_tms, s_trstn, s_tdi);
    $display("[TB] %t: Writing testpattern to L2 memory binary entrypoint", $realtime);
    pulp_tap.init(s_tck, s_tms, s_trstn, s_tdi);
    pulp_tap.write32(entry_point, 1, 32'hABBAABBA, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    #50us;
    pulp_tap.read32(entry_point, 1, jtag_data, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    if (jtag_data[0] != 32'hABBAABBA)
      $error("R/W Test of L2 memory entrypoint failed: %h != %h", jtag_data[0], 32'habbaabba);
    else
      $display("[TB] %t: Finished sanity tests", $realtime);
  endtask

  task automatic boot_jtag_legacy(
    int       entry_point,
    ref [95:0] stimuli[$],
    ref logic s_tck,
    ref logic s_tms,
    ref logic s_trstn,
    ref logic s_tdi,
    ref logic s_tdo
  );
    $display("[TB] %t: Starting boot procedure with legacy bootmode", $realtime);
    halt_hart_write_boot_addr(entry_point, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    $display("[TB] %t: Loading binary into memory uisng legacy pulp TAP", $realtime);
    pulp_tap_pkg::load_L2(0, stimuli, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    $display("[TB] %t: Done. Resuming HART", $realtime);
    // configure for debug module dmi access again
    debug_mode_if.init_dmi_access(s_tck, s_tms, s_trstn, s_tdi);
    // we have set dpc and loaded the binary, we can go now
    debug_mode_if.resume_harts(s_tck, s_tms, s_trstn, s_tdi, s_tdo);
  endtask // boot_jtag_legacy

  task automatic boot_fast(
    int       entry_point,
    ref [95:0] stimuli[$],
    ref logic s_tck,
    ref logic s_tms,
    ref logic s_trstn,
    ref logic s_tdi,
    ref logic s_tdo
  );
    $display("[TB] %t: Starting boot procedure in fastboot mode", $realtime);
    halt_hart_write_boot_addr(entry_point, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    $display("[TB] %t: Loading binary into memory uisng legacy pulp TAP", $realtime);
    fastboot_preload_l2(0, stimuli);
    $display("[TB] %t: Done. Resuming HART", $realtime);
    // configure for debug module dmi access again
    debug_mode_if.init_dmi_access(s_tck, s_tms, s_trstn, s_tdi);
    // we have set dpc and loaded the binary, we can go now
    debug_mode_if.resume_harts(s_tck, s_tms, s_trstn, s_tdi, s_tdo);
  endtask // boot_jtag_legacy


  task automatic halt_hart_write_boot_addr(
    int       entry_point,
    ref logic s_tck,
    ref logic s_tms,
    ref logic s_trstn,
    ref logic s_tdi,
    ref logic s_tdo
  );
    debug_mode_if.init_dmi_access(s_tck, s_tms, s_trstn, s_tdi);
    debug_mode_if.set_dmactive(1'b1, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    debug_mode_if.set_hartsel(FC_CORE_ID, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    $display("[TB] %t: Halting the core", $realtime);
    debug_mode_if.halt_harts(s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    $display("[TB] %t: Writing boot address into dpc", $realtime);
    debug_mode_if.write_reg_abstract_cmd(riscv::CSR_DPC, entry_point, s_tck, s_tms, s_trstn,
                                         s_tdi, s_tdo);

  endtask


  task automatic fastboot_preload_l2(input int stimuli_start_offset, ref logic [95:0] stimuli[$]);
    logic more_stim;
    static logic [95:0] stim_entry;
    more_stim = 1'b1;
    $display("[TB] %t: Preloading L2 with stimuli through direct access.", $realtime);
    while (more_stim == 1'b1) begin
      @(posedge i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.clk_i);
      stim_entry = stimuli[stimuli_start_offset];
      force i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.tcdm_debug.req = 1'b1;
      force i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.tcdm_debug.add = stim_entry[95:64];
      force i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.tcdm_debug.wdata = stim_entry[31:0];
      force i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.tcdm_debug.wen = 1'b0;
      force i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.tcdm_debug.be = '1;
      do begin
        @(posedge i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.clk_i);
      end while (~i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.tcdm_debug.gnt);
      force i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.tcdm_debug.add   = stim_entry[95:64]+4;
      force i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.tcdm_debug.wdata = stim_entry[63:32];
      do begin
        @(posedge i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.clk_i);
      end while (~i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.tcdm_debug.gnt);

      stimuli_start_offset = stimuli_start_offset + 1;
      if (stimuli_start_offset > $size(stimuli) || stimuli[stimuli_start_offset] === 96'bx) begin  // make sure we have more stimuli
        more_stim = 0;  // if not set variable to 0, will prevent additional stimuli to be applied
        break;
      end
    end  // while (more_stim == 1'b1)
    release i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.tcdm_debug.req;
    release i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.tcdm_debug.add;
    release i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.tcdm_debug.wdata;
    release i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.tcdm_debug.wen;
    release i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.tcdm_debug.be;
    @(posedge i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.clk_i);
  endtask

  task automatic wait_for_end_of_computation(
    ref logic  s_tck,
    ref logic  s_tms,
    ref logic  s_trstn,
    ref logic  s_tdi,
    ref logic  s_tdo,
    output int exit_status
  );
    int        rd_cnt = 0;
    // enable sb access for subsequent readMem calls
    debug_mode_if.set_sbreadonaddr(1'b1, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    jtag_data[0] = 0;
    while (jtag_data[0][31] == 0) begin
      // every 10th loop iteration, clear the debug module's SBA unit CSR to make
      // sure there's no error blocking our reads. Sometimes a TCDM read
      // request issued by the debug module takes longer than it takes
      // for the read request to the debug module to arrive and it
      // stores an error in the SBCS register. By clearing it
      // periodically we make sure the test can terminate.
      if (rd_cnt % 10 == 0) begin
        debug_mode_if.clear_sbcserrors(s_tck, s_tms, s_trstn, s_tdi, s_tdo);
      end
      debug_mode_if.readMem(32'h1A1040A0, jtag_data[0], s_tck, s_tms, s_trstn, s_tdi, s_tdo);
      rd_cnt++;
      #50us;
    end

    if (jtag_data[0][30:0] == 0) exit_status = EXIT_SUCCESS;
    else exit_status = EXIT_FAIL;
    $display("[TB] %t: Received status core: 0x%h", $realtime, jtag_data[0][30:0]);
  endtask

endmodule
