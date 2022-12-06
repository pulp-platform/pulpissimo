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

module tb_pulp_simplified;
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
  localparam REF_CLK_PERIOD = 30517ns;
  localparam IO_PAD_COUNT = gpio_reg_pkg::GPIOCount; // Check the README on how
                                // to modify the pad count
  localparam logic [9:0] FC_CORE_ID = {5'd31, 5'd0};


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
  wire                     w_pad_ref_clk_in;
  wire                     w_pad_clk_byp_en;
  wire                     w_pad_reset_n;
  wire [1:0]               w_bootsel;
  wire                     w_pad_hyper_csn;
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
  logic                    s_jtag_tck;
  logic                    s_jtag_tdi;
  logic                    s_jtag_tdo;
  logic                    s_jtag_tms;
  logic                    s_jtag_trstn;
  // UART
  logic                    s_uart_rx_en;
  logic                    s_uart_tx; // (from chip to TB) Connected to pad_io[0]
  logic                    s_uart_rx; // (from TB to chip) Connected to pad_io[1]
  // HyperBus
  logic                    s_hyper_ck;
  logic                    s_hyper_ckn;
  logic                    s_hyper_csn;
  logic                    s_hyper_reset_n;
  logic                    s_hyper_rwds;
  logic [7:0]              s_hyper_dq_from_chip;
  logic [7:0]              s_hyper_dq_to_chip = '0;
  logic [7:0]              s_hyper_dq_tx_en = '0;

  //////////////////////
  // Wire Assignments //
  //////////////////////

  // Clock, Reset & Bootmode
  assign w_pad_ref_clk_in = s_clk_ref;
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
  assign s_uart_tx = w_pad_io[0];
  assign w_pad_io[1] = s_uart_rx;

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
    .rx    ( s_uart_tx    ),
    .rx_en ( s_uart_rx_en ),
    .tx    ( s_uart_tx    )
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
    .pad_ref_clk       ( w_pad_ref_clk_in    ),
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

    // Load Stimuli
    $info("PULPissimo Testbench started with bootmode %s", BOOTMODE);
    $info("Loading Stimuli from stimuli file %s", BINARY_SREC_PATH);
    srec_read(BINARY_SREC_PATH, records);
    srec_records_to_stimuli(records, stimuli, entry_point);
    $info("Finished loading stimuli from SREC file. Binary contains %0d words and has entrypoint %032h", stimuli.size(), entry_point);

    // Apply initial signal values
    s_hard_reset_n = 1'b1;
    s_uart_rx      = 1'b0;
    s_jtag_tck     = 1'b0;
    s_jtag_tms     = 1'b0;
    s_jtag_trstn   = 1'b0;
    s_jtag_tdi     = 1'b0;
    s_uart_rx_en   = 1'b1;
    s_uart_rx      = 1'b0;
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
    $info("Asserting hard reset for 2 ref_clk cycles...");
    s_hard_reset_n = 1'b0;
    #(REF_CLK_PERIOD*2);
    s_hard_reset_n = 1'b1;

    $info("Hard reset released. Running some JTAG sanity tests");
    // before starting the actual boot procedure we do some light
    // testing on the jtag link
    jtag_sanity_test(s_jtag_tck, s_jtag_tms, s_jtag_tdi);

    $info("Done. Starting boot sequence");
    case (BOOTMODE)
      "jtag_legacy", default: begin
        boot_jtag_legacy(entry_point, stimuli, s_jtag_tck, s_jtag_tms, s_jtag_trstn, s_jtag_tdi);
      end

      "fastboot": begin
        boot_fast(entry_point, stimuli, s_jtag_tck, s_jtag_tms, s_jtag_trstn, s_jtag_tdi);
      end
    endcase


    $info("Waiting for end of computation");
    wait_for_end_of_computation(s_jtag_tck, s_jtag_tms, s_jtag_trstn, s_jtag_tdi, exit_code);

    $info("TB Execution finished with exit code %0d", exit_code);
    $stop;
  end


  //////////////
  // TB Tasks //
  //////////////

  task automatic jtag_sanity_tests(
    ref logic s_tck,
    ref logic s_tms,
    ref logic s_trstn,
    ref logic s_tdi
  );

    jtag_pkg::jtag_reset(s_tck, s_tms, s_trstn, s_tdi);
    jtag_pkg::jtag_softreset(s_tck, s_tms, s_trstn, s_tdi);
    #5us;

    jtag_pkg::jtag_bypass_test(s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    #5us;

    jtag_pkg::jtag_get_idcode(s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    #5us;
    test_mode_if.init(s_tck, s_tms, s_trstn, s_tdi);
    $info("Writing testpattern to L2 memory binary entrypoint");
    pulp_tap.init(s_tck, s_tms, s_trstn, s_tdi);
    pulp_tap.write32(entry_point, 1, 32'hABBAABBA, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    #50us;
    pulp_tap.read32(entry_point, 1, jtag_data, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    if (jtag_data[0] != 32'hABBAABBA)
      $error("R/W Test of L2 memoery entrypoint failed: %h != %h", jtag_data[0], 32'habbaabba);
    else:
      $info("Finished sanity tests");
  endtask

  task automatic boot_jtag_legacy(
    int       entry_point,
    ref [95:0] stimuli[$],
    ref logic s_tck,
    ref logic s_tms,
    ref logic s_trstn,
    ref logic s_tdi
  );
    $info("Starting boot procedure with legacy bootmode");
    halt_hart_write_boot_addr(entry_point, s_tck, s_tms, s_trstn, s_tdi);
    $info("Loading binary into memory uisng legacy pulp TAP");
    pulp_tap_pkg::load_L2(stimuli.size(), stimuli, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    $info("Done. Resuming HART");
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
                                  ref logic s_tdi
                                  );
    $info("Starting boot procedure in fastboot mode");
    halt_hart_write_boot_addr(entry_point, s_tck, s_tms, s_trstn, s_tdi);
    $info("Loading binary into memory uisng legacy pulp TAP");
    preload_load_l2(stimuli.size(), stimuli);
    $info("Done. Resuming HART");
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
    ref logic s_tdi
  );
    debug_mode_if.init_dmi_access(s_tck, s_tms, s_trstn, s_tdi);
    debug_mode_if.set_dmactive(1'b1, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    debug_mode_if.set_hartsel(FC_CORE_ID, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    $info("Halting the core");
    debug_mode_if.halt_harts(s_tck, s_tms, s_trstn, s_tdi, s_tdo);
    $info("Writing boot address into dpc");
    debug_mode_if.write_reg_abstract_cmd(riscv::CSR_DPC, begin_l2_instr, s_tck, s_tms, s_trstn,
                                         s_tdi, s_tdo);

  endtask


  task automatic preload_l2(input int num_stim, ref logic [95:0] stimuli[$]);
    logic more_stim;
    static logic [95:0] stim_entry;
    more_stim = 1'b1;
    $info("Preloading L2 with stimuli through direct access.");
    while (more_stim == 1'b1) begin
      @(posedge i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.clk_i);
      stim_entry = stimuli[num_stim];
      force i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.tcdm_debug.req = 1'b1;
      force i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.tcdm_debug.add = stim_entry[95:64];
      force i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.tcdm_debug.wdata = stim_entry[31:0];
      force i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.tcdm_debug.wen = 1'b0;
      force i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.tcdm_debug.be = '1;
      do begin
        @(posedge i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.clk_i);
      end while (~i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.tcdm_debug.gnt);
      force i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.tcdm_debug.add   = stim_entry[95:64]+4;
      force i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.tcdm_debug.wdata = stim_entry[63:32];
      do begin
        @(posedge i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.clk_i);
      end while (~i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.tcdm_debug.gnt);

      num_stim = num_stim + 1;
      if (num_stim > $size(stimuli) || stimuli[num_stim] === 96'bx) begin  // make sure we have more stimuli
        more_stim = 0;  // if not set variable to 0, will prevent additional stimuli to be applied
        break;
      end
    end  // while (more_stim == 1'b1)
    release i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.tcdm_debug.req;
    release i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.tcdm_debug.add;
    release i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.tcdm_debug.wdata;
    release i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.tcdm_debug.wen;
    release i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.tcdm_debug.be;
    @(posedge i_dut.soc_domain_i.pulp_soc_i.i_soc_interconnect_wrap.clk_i);
  endtask

  task wait_for_end_of_computation(
    ref logic s_tck,
    ref logic s_tms,
    ref logic s_trstn,
    ref logic s_tdi,
    output int exit_status
  );
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
    $info("Received status core: 0x%h", $realtime, jtag_data[0][30:0]);
  endtask

endmodule
