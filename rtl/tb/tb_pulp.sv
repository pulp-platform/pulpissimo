// Copyright 2022 ETH Zurich and University of Bologna.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

// tb_pulp.sv
// Francesco Conti <fconti@iis.ee.ethz.ch>
// Antonio Pullini <pullinia@iis.ee.ethz.ch>
// Igor Loi <igor.loi@unibo.it>
// Robert Balas <balasr@iis.ee.ethz.ch>


module tb_pulp;
  import srec_pkg::*;
  timeunit 1ns;
  timeprecision 100ps;

  parameter CONFIG_FILE = "NONE";

  // simulation platform parameters

  // Choose your core: 0 for RISCY, 1 for IBEX RV32IMC (formerly ZERORISCY), 2 for IBEX RV32EC (formerly MICRORISCY)
  parameter CORE_TYPE = 0;

  // if RI5CY is instantiated (CORE_TYPE == 0), USE_FPU enables the FPU
  parameter USE_FPU = 1;

  // if RI5CY uses ZFINX (merged float and integer register files)
  parameter USE_ZFINX = 0;

  // if we are using a simulated stdout
  parameter SIM_STDOUT = 1;

  // period of the external reference clock (32.769kHz)
  parameter realtime REF_CLK_PERIOD = 30517ns;

  // UART baud rate in bps
  parameter BAUDRATE = 115200;

  // use frequency-locked loop to generate internal clock
  parameter USE_FLL = 1;

  // use camera verification IP
  parameter USE_SDVT_CPI = 0;

  // files to be used to load the I2S verification IP, if instantiated
  localparam I2S_FILENAME_0 = "i2s_buffer_0.hex";
  localparam I2S_FILENAME_1 = "i2s_buffer_1.hex";
  localparam I2S_FILENAME_2 = "i2s_buffer_2.hex";
  localparam I2S_FILENAME_3 = "i2s_buffer_3.hex";

  // for PULPissimo, 1 core
  localparam int NB_CORES = 1;

  // exit
  localparam int EXIT_SUCCESS = 0;
  localparam int EXIT_FAIL = 1;
  localparam int EXIT_ERROR = -1;


  // SPI standards, do not change
  localparam logic [1:0] SPI_STD = 2'b00;
  localparam logic [1:0] SPI_QUAD_TX = 2'b01;
  localparam logic [1:0] SPI_QUAD_RX = 2'b10;


  // Check the README on how to modify the pad count
  localparam IO_PAD_COUNT = gpio_reg_pkg::GPIOCount; 

  // simulation variables & flags
  string bootmode;
  logic uart_tb_rx_en = 1'b0;

  // contains the program code
  string stimuli_path, srec_path;
  int num_stim;
  logic [95:0] stimuli[$];  // array for the stimulus vectors

  logic dev_dpi_en = 0;

  logic [255:0][31:0] jtag_data;


  int exit_status = EXIT_ERROR;  // modelsim exit code, will be overwritten when successfull

  jtag_pkg::test_mode_if_t test_mode_if = new;
  jtag_pkg::debug_mode_if_t debug_mode_if = new;
  pulp_tap_pkg::pulp_tap_if_soc_t pulp_tap = new;

  // system wires
  // the w_/s_ prefixes are used to mean wire/tri-type and logic-type (respectively)

  logic s_rst_n = 1'b0;
  logic s_rst_dpi_n;
  wire w_rst_n;

  logic s_clk_ref;
  wire w_clk_ref;
  wire w_clk_byp_en;
  assign w_clk_byp_en = 1'b0;

  wire [IO_PAD_COUNT-1:0] w_pad_io;
  wire w_spi_master_sdio0;
  wire w_spi_master_sdio1;
  wire w_spi_master_sdio2;
  wire w_spi_master_sdio3;
  wire w_spi_master_csn0;
  wire w_spi_master_csn1;
  wire w_spi_master_sck;

  wire w_sdio_data0;

  wire w_i2c0_scl;
  wire w_i2c0_sda;

  wire w_i2c1_scl;
  wire w_i2c1_sda;

  wire w_uart_rx;
  wire w_uart_tx;

  wire w_cam_pclk;
  wire [7:0] w_cam_data;
  wire w_cam_hsync;
  wire w_cam_vsync;

  // I2S 0
  wire w_i2s0_sck;
  wire w_i2s0_ws;
  wire w_i2s0_sdi;
  // I2S 1
  wire w_i2s1_sdi;

  wire w_i2s_sck;
  wire w_i2s_ws;
  wire [7:0] w_i2s_data;

  // HyperBus/Flash
  wire [1:0] w_pad_hyper_csn;
  wire       w_pad_hyper_reset_n;
  wire       w_pad_hyper_ck;
  wire       w_pad_hyper_ckn;
  wire [7:0] w_pad_hyper_dq;
  wire       w_pad_hyper_rwds;

  // HyperBus
  logic      s_hyper_ck;
  logic      s_hyper_ckn;
  logic [1:0] s_hyper_csn;
  logic       s_hyper_reset_n;
  logic       s_hyper_rwds;
  logic [7:0] s_hyper_dq_from_chip;
  logic [7:0] s_hyper_dq_to_chip = '0;
  logic [7:0] s_hyper_dq_tx_en = '0;


  wire w_trstn;
  wire w_tck;
  wire w_tdi;
  wire w_tms;
  wire w_tdo;

  logic s_vpi_trstn;
  logic s_vpi_tck;
  logic s_vpi_tdi;
  logic s_vpi_tms;

  wire w_bridge_trstn;
  wire w_bridge_tdo;
  wire w_bridge_tck;
  wire w_bridge_tdi;
  wire w_bridge_tms;

  logic s_trstn = 1'b0;
  logic s_tck = 1'b0;
  logic s_tdi = 1'b0;
  logic s_tms = 1'b0;
  logic s_tdo;

  // jtag openocd bridge signals
  logic sim_jtag_tck;
  logic sim_jtag_tms;
  logic sim_jtag_tdi;
  logic sim_jtag_trstn;
  logic sim_jtag_tdo;
  logic [31:0] sim_jtag_exit;
  logic sim_jtag_enable;

  // tmp signals for assignment to wires
  logic tmp_rst_n;
  logic tmp_clk_ref;
  logic tmp_trstn;
  logic tmp_tck;
  logic tmp_tdi;
  logic tmp_tms;
  logic tmp_tdo;
  logic tmp_bridge_tdo;



  wire w_master_i2s_sck;
  wire w_master_i2s_ws;

  wire [1:0] w_bootsel;
  logic [1:0] s_bootsel;


  logic [8:0] jtag_conf_reg, jtag_conf_rego;  //22bits but actually only the last 9bits are used


`ifdef TARGET_RT_DPI
  `define USE_DPI
  generate
    if (CONFIG_FILE != "NONE") begin
      CTRL ctrl ();
      JTAG jtag ();
      UART uart ();
      CPI cpi ();

      QSPI qspi_0 ();
      QSPI_CS qspi_0_csn[0:1] ();

      GPIO gpio_22 ();

      assign s_rst_dpi_n        = ~ctrl.reset;

      assign w_bridge_tck       = jtag.tck;
      assign w_bridge_tdi       = jtag.tdi;
      assign w_bridge_tms       = jtag.tms;
      assign w_bridge_trstn     = jtag.trst;
      assign jtag.tdo           = w_bridge_tdo;

      assign w_uart_tx          = uart.tx;
      assign uart.rx            = w_uart_rx;

      assign w_spi_master_sdio0 = qspi_0.data_0_out;
      assign qspi_0.data_0_in   = w_spi_master_sdio0;
      assign w_spi_master_sdio1 = qspi_0.data_1_out;
      assign qspi_0.data_1_in   = w_spi_master_sdio1;
      assign w_spi_master_sdio2 = qspi_0.data_2_out;
      assign qspi_0.data_2_in   = w_spi_master_sdio2;
      assign w_spi_master_sdio3 = qspi_0.data_3_out;
      assign qspi_0.data_3_in   = w_spi_master_sdio3;
      assign qspi_0.sck         = w_spi_master_sck;
      assign qspi_0_csn[0].csn  = w_spi_master_csn0;
      assign qspi_0_csn[1].csn  = w_spi_master_csn1;
      assign w_cam_pclk         = cpi.pclk;
      assign w_cam_hsync        = cpi.href;
      assign w_cam_vsync        = cpi.vsync;
      assign w_cam_data[0]      = cpi.data[0];
      assign w_cam_data[1]      = cpi.data[1];
      assign w_cam_data[2]      = cpi.data[2];
      assign w_cam_data[3]      = cpi.data[3];
      assign w_cam_data[4]      = cpi.data[4];
      assign w_cam_data[5]      = cpi.data[5];
      assign w_cam_data[6]      = cpi.data[6];
      assign w_cam_data[7]      = cpi.data[7];

      assign w_sdio_data0       = gpio_22.data_out;

      initial begin
        automatic tb_driver::tb_driver i_tb_driver = new;
        qspi_0.data_0_out = 'bz;
        qspi_0.data_1_out = 'bz;
        qspi_0.data_2_out = 'bz;
        qspi_0.data_3_out = 'bz;

        i_tb_driver.register_qspim_itf(0, qspi_0, qspi_0_csn);
        i_tb_driver.register_uart_itf(0, uart);
        i_tb_driver.register_jtag_itf(0, jtag);
        i_tb_driver.register_cpi_itf(0, cpi);
        i_tb_driver.register_ctrl_itf(0, ctrl);
        i_tb_driver.register_gpio_itf(22, gpio_22);
        i_tb_driver.build_from_json(CONFIG_FILE);
      end
    end
  endgenerate
`endif



  pullup sda0_pullup_i (w_i2c0_sda);
  pullup scl0_pullup_i (w_i2c0_scl);

  pullup sda1_pullup_i (w_i2c1_sda);
  pullup scl1_pullup_i (w_i2c1_scl);

  always_comb begin
    sim_jtag_enable = 1'b0;

    if ($test$plusargs("jtag_openocd")) begin
      tmp_rst_n       = s_rst_n;
      tmp_clk_ref     = s_clk_ref;
      tmp_trstn       = sim_jtag_trstn;
      tmp_tck         = sim_jtag_tck;
      tmp_tdi         = sim_jtag_tdi;
      tmp_tms         = sim_jtag_tms;
      tmp_tdo         = w_tdo;
      tmp_bridge_tdo  = w_tdo;
      sim_jtag_enable = 1'b1;
    end else begin
      tmp_rst_n      = s_rst_n;
      tmp_clk_ref    = s_clk_ref;

      tmp_trstn      = s_trstn;
      tmp_tck        = s_tck;
      tmp_tdi        = s_tdi;
      tmp_tms        = s_tms;
      tmp_tdo        = w_tdo;
      tmp_bridge_tdo = w_tdo;
    end
  end

  assign w_rst_n      = tmp_rst_n;
  assign w_clk_ref    = tmp_clk_ref;
  assign s_cam_valid  = 1'b0;
  assign w_trstn      = tmp_trstn;
  assign w_tck        = tmp_tck;
  assign w_tdi        = tmp_tdi;
  assign w_tms        = tmp_tms;
  assign s_tdo        = tmp_tdo;
  assign w_bridge_tdo = tmp_bridge_tdo;
  assign sim_jtag_tdo = tmp_tdo;

  // HyperBus (Not used at this point)
  assign s_hyper_ck = w_pad_hyper_ck;
  assign s_hyper_ckn = w_pad_hyper_ckn;
  for (genvar i = 0; i < 8; i++) begin: gen_assign_hyper_dq_wires
    assign s_hyper_dq_from_chip[i] = w_pad_hyper_dq[i];
    assign w_pad_hyper_dq[i]       = s_hyper_dq_tx_en[i]? s_hyper_dq_to_chip: 1'bz;
  end


  if (CONFIG_FILE == "NONE") begin
    assign w_uart_tx = w_uart_rx;
  end


  assign w_bootsel = s_bootsel;

  // SPI flash model (not open-source, from Spansion)
`ifdef TARGET_FLASH_VIP
  s25fs256s #(
    .TimingModel  ("S25FS256SAGMFI000_F_30pF"),
    .mem_file_name("./vectors/qspi_stim.slm"),
    .UserPreload  (1)
  ) i_spi_flash_csn0 (
    .SI      (w_spi_master_sdio0),
    .SO      (w_spi_master_sdio1),
    .SCK     (w_spi_master_sck),
    .CSNeg   (w_spi_master_csn0),
    .WPNeg   (w_spi_master_sdio2),
    .RESETNeg(w_spi_master_sdio3)
  );
`else
  assign w_spi_master_sdio1 = 'z;
`endif

  // UART receiver
  uart_sim #(
    .BAUD_RATE(BAUDRATE),
    .PARITY_EN(0)
  ) i_uart_sim (
    .rx       (w_uart_rx),
    .rx_en    (uart_tb_rx_en),
    .tx()
  );

  // I2C memory models
`ifdef TARGET_I2C_VIP
  M24FC1025 i_i2c_mem_0 (
    .A0   (1'b0),
    .A1   (1'b0),
    .A2   (1'b1),
    .WP   (1'b0),
    .SDA  (w_i2c0_sda),
    .SCL  (w_i2c0_scl),
    .RESET(1'b0)
  );

  M24FC1025 i_i2c_mem_1 (
    .A0   (1'b1),
    .A1   (1'b0),
    .A2   (1'b1),
    .WP   (1'b0),
    .SDA  (w_i2c0_sda),
    .SCL  (w_i2c0_scl),
    .RESET(1'b0)
  );
`endif

  // CPI verification IP
  if (!USE_SDVT_CPI) begin
    cam_vip #(
      .HRES(320),
      .VRES(240)
    ) i_cam_vip (
      .cam_pclk_o (w_cam_pclk),
      .cam_vsync_o(w_cam_vsync),
      .cam_href_o (w_cam_hsync),
      .cam_data_o (w_cam_data)
    );
  end

  // I2S verification IPs
`ifdef TARGET_I2S_VIP
  i2s_vip #(
    .I2S_CHAN(0),
    .FILENAME(I2S_FILENAME_0)
  ) i_i2s_vip_ch0 (
    .A0    (1'b0),
    .A1    (1'b1),
    .SDA   (w_i2c0_sda),
    .SCL   (w_i2c0_scl),
    .sck_i (w_i2s_sck),
    .ws_i  (w_i2s_ws),
    .data_o(w_i2s_data[0]),
    .sck_o (),
    .ws_o  ()
  );

  i2s_vip #(
    .I2S_CHAN(1),
    .FILENAME(I2S_FILENAME_1)
  ) i_i2s_vip_ch1 (
    .A0    (1'b1),
    .A1    (1'b1),
    .SDA   (w_i2c0_sda),
    .SCL   (w_i2c0_scl),
    .sck_i (w_i2s_sck),
    .ws_i  (w_i2s_ws),
    .data_o(w_i2s_data[1]),
    .sck_o (),
    .ws_o  ()
  );

  i2s_vip #(
    .I2S_CHAN(2),
    .FILENAME(I2S_FILENAME_2)
  ) i_i2s_CAM_MASTER_SLAVE (
    .A0    (1'b0),
    .A1    (1'b0),
    .SDA   (w_i2c0_sda),
    .SCL   (w_i2c0_scl),
    .sck_i (w_i2s_sck),
    .ws_i  (w_i2s_ws),
    .data_o(s_master_i2s_sdi0),
    .sck_o (w_master_i2s_sck),
    .ws_o  (w_master_i2s_ws)
  );

  i2s_vip #(
    .I2S_CHAN(3),
    .FILENAME(I2S_FILENAME_3)
  ) i_i2s_CAM_SLAVE (
    .A0    (1'b1),
    .A1    (1'b0),
    .SDA   (w_i2c0_sda),
    .SCL   (w_i2c0_scl),
    .sck_i (s_slave_i2s_sck),
    .ws_i  (s_slave_i2s_ws),
    .data_o(s_slave_i2s_sdi1),
    .sck_o (),
    .ws_o  ()
  );
`endif

  // jtag calls from dpi
  SimJTAG #(
    .TICK_DELAY(1),
    .PORT      (4567)
  ) i_sim_jtag (
    .clock          (w_clk_ref),
    .reset          (~s_rst_n),
    .enable         (sim_jtag_enable),
    .init_done      (s_rst_n),
    .jtag_TCK       (sim_jtag_tck),
    .jtag_TMS       (sim_jtag_tms),
    .jtag_TDI       (sim_jtag_tdi),
    .jtag_TRSTn     (sim_jtag_trstn),
    .jtag_TDO_data  (sim_jtag_tdo),
    .jtag_TDO_driven(1'b1),
    .exit           (sim_jtag_exit)
  );


  // PULPissimo chip (design under test)
  pulpissimo #(
    .CORE_TYPE ( CORE_TYPE ),
    .USE_FPU   ( USE_FPU   ),
    .USE_ZFINX ( USE_ZFINX ),
    .USE_HWPE  ( 1'b0      ), //TODO Re-expose once debugged why it is not working
    .SIM_STDOUT(SIM_STDOUT)
  ) i_dut (
    .pad_ref_clk       ( w_clk_ref           ),
    .pad_reset_n       ( w_rst_n             ),
    .pad_clk_byp_en    ( w_clk_byp_en        ),
    .pad_bootsel0      ( w_bootsel[0]        ),
    .pad_bootsel1      ( w_bootsel[1]        ),
    .pad_jtag_tck      ( w_tck               ),
    .pad_jtag_tdi      ( w_tdi               ),
    .pad_jtag_tdo      ( w_tdo               ),
    .pad_jtag_tms      ( w_tms               ),
    .pad_jtag_trstn    ( w_trstn             ),
    .pad_hyper_csn     ( w_pad_hyper_csn     ),
    .pad_hyper_reset_n ( w_pad_hyper_reset_n ),
    .pad_hyper_ck      ( w_pad_hyper_ck      ),
    .pad_hyper_ckn     ( w_pad_hyper_ckn     ),
    .pad_hyper_dq      ( w_pad_hyper_dq      ),
    .pad_hyper_rwds    ( w_pad_hyper_rwds    ),
    .pad_io            ( w_pad_io            )
  );

  // UART pads as assigned by default in bootrom's io mux config routine. User
  // programs need to configure this themselves.
  alias w_pad_io[0]  = w_uart_rx;
  alias w_pad_io[1]  = w_uart_tx;

  // SPI pads as assigned by default in bootrom's io mux config routine. User
  // programs need to configure this themselves.
  alias w_pad_io[2]  = w_spi_master_sck;
  alias w_pad_io[3]  = w_spi_master_csn0;
  alias w_pad_io[4]  = w_spi_master_sdio0;
  alias w_pad_io[5]  = w_spi_master_sdio1;
  alias w_pad_io[6]  = w_spi_master_sdio2;
  alias w_pad_io[7]  = w_spi_master_sdio3;
  alias w_pad_io[8]  = w_spi_master_csn1;

  // CPI Pads
  alias w_pad_io[9]  = w_cam_pclk;
  alias w_pad_io[10] = w_cam_hsync;
  alias w_pad_io[11] = w_cam_data[0];
  alias w_pad_io[12] = w_cam_data[1];
  alias w_pad_io[13] = w_cam_data[2];
  alias w_pad_io[14] = w_cam_data[3];
  alias w_pad_io[15] = w_cam_data[4];
  alias w_pad_io[16] = w_cam_data[5];
  alias w_pad_io[17] = w_cam_data[6];
  alias w_pad_io[18] = w_cam_data[7];
  alias w_pad_io[19] = w_cam_vsync;

  // I2C
  alias w_pad_io[20] = w_i2c0_sda;
  alias w_pad_io[21] = w_i2c0_scl;

  // GPIO 22
  alias w_pad_io[22] = w_sdio_data0;

  // I2S
  alias w_pad_io[23] = w_i2s0_sck;
  alias w_pad_io[24] = w_i2s0_ws;
  alias w_pad_io[25] = w_i2s0_sdi;
  alias w_pad_io[26] = w_i2s1_sdi;
  
  tb_clk_gen #(
    .CLK_PERIOD(REF_CLK_PERIOD)
  ) i_ref_clk_gen (
    .clk_o(s_clk_ref)
  );

  initial begin : timing_format
    $timeformat(-9, 0, "ns", 9);
  end : timing_format

  // testbench driver process
  initial begin

    logic [1:0]  dm_op;
    logic [6:0]  dm_addr;
    logic [31:0] dm_data;
    logic error;
    int   num_err;
    int   rd_cnt;

    int          entry_point;
    logic [31:0] begin_l2_instr;
    automatic logic [9:0] FC_CORE_ID;
    automatic srec_record_t records[$];
    automatic string jtag_tap_type;

    FC_CORE_ID    = {5'd31, 5'd0};
    uart_tb_rx_en = 1'b1;  // enable uart rx in testbench
    error         = 1'b0;
    num_err       = 0;
    rd_cnt        = 0;

    // read boot mode from commandline
    // read entry point from commandline
    if (!$value$plusargs("bootmode=%s", bootmode))
      bootmode = "jtag";

    if ($value$plusargs("ENTRY_POINT=%h", entry_point))
      begin_l2_instr = entry_point;
    else
      begin_l2_instr = 32'h1C008080;

    $display("[TB  ] %t - Asserting hard reset", $realtime);
    s_rst_n = 1'b0;

    #1ns;


    if ($test$plusargs("jtag_openocd")) begin
      // Use openocd to interact with the simulation
      s_bootsel = 2'b01;
      $display("[TB  ] %t - Releasing hard reset", $realtime);
      s_rst_n = 1'b1;

    end else begin
      // Use only the testbench to do the loading and running

      // determine if we want to load the binary with jtag or from flash
      if (bootmode == "spi_flash" || bootmode == "hyper_flash") begin
        // jtag reset needed anyway
        jtag_pkg::jtag_reset(s_tck, s_tms, s_trstn, s_tdi);
        jtag_pkg::jtag_softreset(s_tck, s_tms, s_trstn, s_tdi);
        #5us;

        if (bootmode == "hyper_flash") begin
          $display("[TB  ] %t - HyperFlash boot: Setting bootsel to 2'b?", $realtime);
          $fatal(1, "[TB  ] %t - HyperFlash boot: Not supported yet", $realtime);
        end else if (bootmode == "spi_flash") begin
          $display("[TB  ] %t - QSPI boot: Setting bootsel to 1'b10", $realtime);
          s_bootsel = 2'b10;
        end

        $display("[TB  ] %t - Releasing hard reset", $realtime);
        s_rst_n = 1'b1;
        debug_mode_if.init_dmi_access(s_tck, s_tms, s_trstn, s_tdi);
        debug_mode_if.set_dmactive(1'b1, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
        #10us;

      end else if (bootmode == "jtag") begin
        s_bootsel = 2'b01;
      end else if (bootmode == "fast_debug_preload") begin
        s_bootsel = 2'b01;
      end else begin
        $error("Unknown bootmode: %s", bootmode);
      end

      if (bootmode == "jtag" || bootmode == "fast_debug_preload") begin
        if (USE_FLL) $display("[TB  ] %t - Using FLL", $realtime);
        else $display("[TB  ] %t - Not using FLL", $realtime);

        if (USE_SDVT_CPI) $display("[TB  ] %t - Using CAM SDVT", $realtime);
        else $display("[TB  ] %t - Not using CAM SDVT", $realtime);

        // read in the stimuli vectors  == address_value
        // we support two formats:
        // 
        // 1. stim.txt where each text line is 96 bits encoded in ascii. The
        // first 32 bits are the address the remaining 64 bits the data payload
        // 2. *.srec. Srecords is a standardized format to represent binary data
        // in ascii text format. Notably, it also encodes also the entry point
        // so we don't have to supply it manully with +ENTRY_POINT. GNU objcopy
        // (part of binutils) can easily convert and elf file to this format.
        if ($value$plusargs("stimuli=%s", stimuli_path)) begin
          $display("[TB  ] %t - Loading custom stimuli from %s", $realtime, stimuli_path);
          load_stim(stimuli_path, stimuli);
        end else if ($value$plusargs("srec=%s", srec_path)) begin
          $display("[TB  ] %t - Loading srec from %s", $realtime, srec_path);
          srec_read(srec_path, records);
          srec_records_to_stimuli(records, stimuli, entry_point);
          if (!$test$plusargs("srec_ignore_entry"))
            begin_l2_instr = entry_point;
        end else begin
          $display("[TB  ] %t - Loading default stimuli", $realtime);
          load_stim("./vectors/stim.txt", stimuli);
        end

        $display("[TB  ] %t - Entry point is set to 0x%h", $realtime, begin_l2_instr);

        // before starting the actual boot procedure we do some light
        // testing on the jtag link
        jtag_pkg::jtag_reset(s_tck, s_tms, s_trstn, s_tdi);
        jtag_pkg::jtag_softreset(s_tck, s_tms, s_trstn, s_tdi);
        #5us;

        jtag_pkg::jtag_bypass_test(s_tck, s_tms, s_trstn, s_tdi, s_tdo);
        #5us;

        jtag_pkg::jtag_get_idcode(s_tck, s_tms, s_trstn, s_tdi, s_tdo);
        #5us;

        test_mode_if.init(s_tck, s_tms, s_trstn, s_tdi);

        $display("[TB  ] %t - Enabling clock out via jtag", $realtime);

        // TODO: currently no supported in the bootrom
        // The boot code installed in the ROM checks the JTAG register value.
        // If jtag_conf_reg is set to 0, the debug module will take over the boot process
        // The image file can be loaded also from SPI flash and Hyper flash
        // even though this is not the stand-alone boot

        // jtag_conf_reg = (STIM_FROM == "JTAG")           ? {1'b0, 4'b0, 3'b001, 1'b0}:
        //                        (STIM_FROM == "SPI_FLASH")      ? {1'b0, 4'b0, 3'b111, 1'b0}:
        //                        (STIM_FROM == "HYPER_FLASH")    ? {1'b0, 4'b0, 3'b101, 1'b0}: '0;
        // test_mode_if.set_confreg(jtag_conf_reg, jtag_conf_rego, s_tck, s_tms, s_trstn, s_tdi,
        //                          s_tdo);

        $display("[TB  ] %t - jtag_conf_reg set to %x", $realtime, jtag_conf_reg);

        $display("[TB  ] %t - Releasing hard reset", $realtime);
        s_rst_n = 1'b1;

        //test if the PULP tap che write to the L2
        pulp_tap.init(s_tck, s_tms, s_trstn, s_tdi);

        $display("[TB  ] %t - Init PULP TAP", $realtime);

        pulp_tap.write32(begin_l2_instr, 1, 32'hABBAABBA, s_tck, s_tms, s_trstn, s_tdi, s_tdo);

        $display("[TB  ] %t - Write32 PULP TAP", $realtime);

        #50us;
        pulp_tap.read32(begin_l2_instr, 1, jtag_data, s_tck, s_tms, s_trstn, s_tdi, s_tdo);

        if (jtag_data[0] != 32'hABBAABBA)
          $display("[JTAG] %t - R/W test of L2 failed: %h != %h", $realtime, jtag_data[0], 32'hABBAABBA);
        else $display("[JTAG] %t - R/W test of L2 succeeded", $realtime);

        // From here on starts the actual jtag booting

        // Setup debug module and hart, halt hart and set dpc (return point
        // for boot).
        // Halting the fc hart transfers control of the program execution to
        // the debug module. This might take a bit until the debug request
        // signal is propagated so meanwhile the core is executing stuff
        // from the bootrom. For jtag booting (what we are doing right now),
        // bootsel is low so the code that is being executed in said bootrom
        // is only a busy wait or wfi until the debug unit grabs control.
        debug_mode_if.init_dmi_access(s_tck, s_tms, s_trstn, s_tdi);

        debug_mode_if.set_dmactive(1'b1, s_tck, s_tms, s_trstn, s_tdi, s_tdo);

        debug_mode_if.set_hartsel(FC_CORE_ID, s_tck, s_tms, s_trstn, s_tdi, s_tdo);

        $display("[TB  ] %t - Halting the Core", $realtime);
        debug_mode_if.halt_harts(s_tck, s_tms, s_trstn, s_tdi, s_tdo);

        $display("[TB  ] %t - Writing the boot address into dpc", $realtime);
        debug_mode_if.write_reg_abstract_cmd(riscv::CSR_DPC, begin_l2_instr, s_tck, s_tms, s_trstn,
                                             s_tdi, s_tdo);

        // long debug module + jtag tests
        if ($test$plusargs("jtag_dm_tests")) begin
          debug_mode_if.run_dm_tests(FC_CORE_ID, begin_l2_instr, error, num_err, s_tck, s_tms,
                                     s_trstn, s_tdi, s_tdo);
          // we don't have any program to load so we finish the testing
          if (num_err == 0) begin
            exit_status = EXIT_SUCCESS;
          end else begin
            exit_status = EXIT_FAIL;
            $error("Debug Module: %d tests failed", num_err);
          end
          $stop;
        end

        if (bootmode == "jtag") begin
          $display("[TB  ] %t - Loading L2 via JTAG", $realtime);
          if (!$value$plusargs("jtag_load_tap=%s", jtag_tap_type))
            jtag_tap_type = "pulp"; // default
          if (jtag_tap_type == "riscv") begin
            // use debug module to load binary
            debug_mode_if.load_L2(num_stim, stimuli, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
          end else if (jtag_tap_type == "pulp") begin
            // use pulp tap to load binary, put debug module in bypass
            pulp_tap_pkg::load_L2(num_stim, stimuli, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
          end else begin
            $fatal(1, "Unknown tap type +jtag_load_tap=%s", jtag_tap_type);
          end
        end else if (bootmode == "fast_debug_preload") begin
          $warning(
            "[TB  ] - Preloading the memory via direct simulator access. \nNEVER EVER USE THIS MODE TO VERIFY THE BOOT BEHAVIOR OF A CHIP. THIS BOOTMODE IS IMPOSSIBLE ON A PHYSICAL CHIP!!!");
          preload_l2(num_stim, stimuli);
        end else begin
          $error("Unknown L2 loading mechnism chosen (bootmode == %s)", bootmode);
        end

        // configure for debug module dmi access again
        debug_mode_if.init_dmi_access(s_tck, s_tms, s_trstn, s_tdi);

        // we have set dpc and loaded the binary, we can go now
        $display("[TB  ] %t - Resuming the CORE", $realtime);
        debug_mode_if.resume_harts(s_tck, s_tms, s_trstn, s_tdi, s_tdo);
      end

      #500us;

      // enable sb access for subsequent readMem calls
      debug_mode_if.set_sbreadonaddr(1'b1, s_tck, s_tms, s_trstn, s_tdi, s_tdo);

      // wait for end of computation signal
      $display("[TB  ] %t - Waiting for end of computation", $realtime);

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
      $display("[TB  ] %t - Received status core: 0x%h", $realtime, jtag_data[0][30:0]);

      $stop;

    end
  end

  task load_stim(input string stim, output logic [95:0] stimuli[$]);
    int stim_fd, ret;
    logic [95:0] rdata;
    stim_fd = $fopen(stim, "r");

    if (stim_fd == 0)
      $fatal(1, "Could not open stimuli file!");

    while (!$feof(stim_fd)) begin
      ret= $fscanf(stim_fd, "%h\n", rdata);
      stimuli.push_back(rdata);
    end

    $fclose(stim_fd);
  endtask  // load_stim

  task automatic preload_l2(input int num_stim, ref logic [95:0] stimuli[$]);
    logic more_stim;
    static logic [95:0] stim_entry;
    more_stim = 1'b1;
    $display("[TB] %t: Preloading L2 with stimuli through direct access.", $realtime);
    while (more_stim == 1'b1) begin
      @(posedge i_dut.i_soc_domain.i_pulp_soc.i_soc_interconnect_wrap.clk_i);
      stim_entry = stimuli[num_stim];
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

      num_stim = num_stim + 1;
      if (num_stim > $size(stimuli) || stimuli[num_stim] === 96'bx) begin  // make sure we have more stimuli
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


endmodule  // tb_pulp
