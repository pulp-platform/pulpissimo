// Copyright 2018 ETH Zurich and University of Bologna.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

/*
 * tb_pulp.sv
 * Francesco Conti <fconti@iis.ee.ethz.ch>
 * Antonio Pullini <pullinia@iis.ee.ethz.ch>
 * Igor Loi <igor.loi@unibo.it>
 */

// timeunit 1ps;
//  1ps;

`define EXIT_SUCCESS  0
`define EXIT_FAIL     1
`define EXIT_ERROR   -1
//`define USE_DPI      1




module tb_pulp;

   parameter CONFIG_FILE = "NONE";

   /* simulation platform parameters */

   // Choose your core: 0 for RISCY, 1 for ZERORISCY
   parameter CORE_TYPE            = 0;
   // if RISCY is instantiated (CORE_TYPE == 0), RISCY_FPU enables the FPU
   parameter RISCY_FPU            = 1;

   // the following parameters can activate instantiation of the verification IPs for SPI, I2C and I2s
   // see the instructions in rtl/vip/{i2c_eeprom,i2s,spi_flash} to download the verification IPs
   parameter  USE_S25FS256S_MODEL = 0;
   parameter  USE_24FC1025_MODEL  = 0;
   parameter  USE_I2S_MODEL       = 0;

   // period of the external reference clock (32.769kHz)
   parameter  REF_CLK_PERIOD = 200ns;

   // how L2 is loaded. valid values are "JTAG" or "STANDALONE", the latter works only when USE_S25FS256S_MODEL is 1
   parameter  LOAD_L2 = "JTAG";

   parameter  EXEC_TEST = "";

   // enable DPI-based JTAG
   parameter  ENABLE_DPI = 0;

   // enable DPI-based peripherals
   parameter  ENABLE_DEV_DPI = 0;

   // enable DPI-based debug bridge
   parameter  ENABLE_EXTERNAL_DRIVER = 0;

   // UART baud rate in bps
   parameter  BAUDRATE = 625000;

   // use frequency-locked loop to generate internal clock
   parameter  USE_FLL = 1;

   // use camera verification IP
   parameter  USE_SDVT_CPI = 0;

   // files to be used to load the I2S verification IP, if instantiated
   parameter  I2S_FILENAME_0 = "i2s_buffer_0.hex";
   parameter  I2S_FILENAME_1 = "i2s_buffer_1.hex";
   parameter  I2S_FILENAME_2 = "i2s_buffer_2.hex";
   parameter  I2S_FILENAME_3 = "i2s_buffer_3.hex";

   // for PULPissimo, 1 core
   parameter NB_CORES = 1;

   // SPI standards, do not change
   parameter logic[1:0] SPI_STD     = 2'b00;
   parameter logic[1:0] SPI_QUAD_TX = 2'b01;
   parameter logic[1:0] SPI_QUAD_RX = 2'b10;

   // JTAG mux configuration, do not change
   parameter logic[1:0] JTAG_DPI    = 2'b01;
   parameter logic[1:0] JTAG_BRIDGE = 2'b10;

   /* simulation variables & flags */
   logic                 uart_tb_rx_en = 1'b0;
   logic                 uart_vip_rx_en = 1'b0;
   string                uart_drv_mon_sel = "TB";

   int                   num_stim;
   logic [95:0]          stimuli  [100000:0];                // array for the stimulus vectors

   logic [1:0]           jtag_mux = 2'b00;

   logic                 dev_dpi_en = 0;

   logic [255:0][31:0]   jtag_data;

   logic jtag_enable;

   int                   exit_status = `EXIT_ERROR; // modelsim exit code, will be overwritten when successfull

   jtag_pkg::test_mode_if_t  test_mode_if = new;
   jtag_pkg::debug_mode_if_t debug_mode_if = new;
   dbg_pkg::dbg_if_soc_t    dbg_if_soc = new;

   /* system wires */
   // the w_/s_ prefixes are used to mean wire/tri-type and logic-type (respectively)

   logic                 s_rst_n = 1'b0;
   logic                 s_rst_dpi_n;
   wire                  w_rst_n;

   logic                 s_clk_ref;
   wire                  w_clk_ref;

   tri                   w_spi_master_sdio0;
   tri                   w_spi_master_sdio1;
   tri                   w_spi_master_sdio2;
   tri                   w_spi_master_sdio3;
   tri                   w_spi_master_csn0;
   tri                   w_spi_master_csn1;
   tri                   w_spi_master_sck;

   wire                  w_i2c0_scl;
   wire                  w_i2c0_sda;

   tri                   w_i2c1_scl;
   tri                   w_i2c1_sda;

   logic [1:0]           s_padmode_spi_master = SPI_STD;

   tri                   w_uart_rx;
   tri                   w_uart_tx;

   wire                  w_cam_pclk;
   wire [7:0]            w_cam_data;
   wire                  w_cam_hsync;
   wire                  w_cam_vsync;

   // I2S 0
   wire                  w_i2s0_sck;
   wire                  w_i2s0_ws;
   wire                  w_i2s0_sdi;
   // I2S 1
   wire                  w_i2s1_sdi;

   wire                  w_i2s_sck;
   wire                  w_i2s_ws;
   wire           [7:0]  w_i2s_data;

   wire                  w_trstn;
   wire                  w_tck;
   wire                  w_tdi;
   wire                  w_tms;
   wire                  w_tdo;

   logic                 s_vpi_trstn;
   logic                 s_vpi_tck;
   logic                 s_vpi_tdi;
   logic                 s_vpi_tms;

   wire                  w_bridge_trstn;
   wire                  w_bridge_tdo;
   wire                  w_bridge_tck;
   wire                  w_bridge_tdi;
   wire                  w_bridge_tms;

   logic                 s_trstn = 1'b0;
   logic                 s_tck   = 1'b0;
   logic                 s_tdi   = 1'b0;
   logic                 s_tms   = 1'b0;
   logic                 s_tdo;
   logic                 s_mode_select;

   wire w_master_i2s_sck;
   wire w_master_i2s_ws ;

   wire w_bootsel;

   logic [8:0] jtag_conf_reg, jtag_conf_rego; //22bits but actually only the last 9bits are used
   localparam BEGIN_L2_INSTR = 32'h1C008080;
   logic sim_tck;
   logic sim_tms;
   logic sim_tdi;
   logic sim_trstn;
   logic sim_tdo;

   `ifdef USE_DPI
   generate
      if (CONFIG_FILE != "NONE") begin

         CTRL     ctrl();
         JTAG     jtag();
         UART     uart();
         CPI      cpi();

         QSPI     qspi_0  ();
         QSPI_CS  qspi_0_csn [0:1]  ();

         assign s_rst_dpi_n   = ~ctrl.reset;

         assign w_bridge_tck   = jtag.tck;
         assign w_bridge_tdi   = jtag.tdi;
         assign w_bridge_tms   = jtag.tms;
         assign w_bridge_trstn = jtag.trst;
         assign jtag.tdo       = w_bridge_tdo;

         assign w_uart_tx      = uart.tx;
         assign uart.rx        = w_uart_rx;

         assign w_spi_master_sdio0 = qspi_0.data_0_out;
         assign qspi_0.data_0_in = w_spi_master_sdio0;
         assign w_spi_master_sdio1 = qspi_0.data_1_out;
         assign qspi_0.data_1_in = w_spi_master_sdio1;
         assign w_spi_master_sdio2 = qspi_0.data_2_out;
         assign qspi_0.data_2_in = w_spi_master_sdio2;
         assign w_spi_master_sdio3 = qspi_0.data_3_out;
         assign qspi_0.data_3_in = w_spi_master_sdio3;
         assign qspi_0.sck = w_spi_master_sck;
         assign qspi_0_csn[0].csn = w_spi_master_csn0;
         assign qspi_0_csn[1].csn = w_spi_master_csn1;
         assign w_cam_pclk = cpi.pclk;
         assign w_cam_hsync = cpi.href;
         assign w_cam_vsync = cpi.vsync;
         assign w_cam_data[0] = cpi.data[0];
         assign w_cam_data[1] = cpi.data[1];
         assign w_cam_data[2] = cpi.data[2];
         assign w_cam_data[3] = cpi.data[3];
         assign w_cam_data[4] = cpi.data[4];
         assign w_cam_data[5] = cpi.data[5];
         assign w_cam_data[6] = cpi.data[6];
         assign w_cam_data[7] = cpi.data[7];

         initial
         begin

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
            i_tb_driver.build_from_json(CONFIG_FILE);

         end

      end

   endgenerate
   `endif



   pullup sda1_pullup_i (w_i2c1_sda);
   pullup scl1_pullup_i (w_i2c1_scl);

   assign w_rst_n   = (ENABLE_EXTERNAL_DRIVER == 1) ? s_rst_dpi_n : s_rst_n;
   assign w_clk_ref = s_clk_ref;

   assign s_cam_valid = 1'b0;

   assign w_trstn      = (ENABLE_EXTERNAL_DRIVER == 1) ? w_bridge_trstn : (jtag_enable ? sim_trstn    : s_trstn);
   assign w_tck        = (ENABLE_EXTERNAL_DRIVER == 1) ? w_bridge_tck   : (jtag_enable ? sim_tck      : s_tck);
   assign w_tdi        = (ENABLE_EXTERNAL_DRIVER == 1) ? w_bridge_tdi   : (jtag_enable ? sim_tdi      : s_tdi);
   assign w_tms        = (ENABLE_EXTERNAL_DRIVER == 1) ? w_bridge_tms   : (jtag_enable ? sim_tms      : s_tms);
   assign s_tdo        = w_tdo;
   assign w_bridge_tdo = w_tdo;

   if (CONFIG_FILE == "NONE") begin
      assign w_uart_tx = w_uart_rx;
   end
   assign w_bootsel = 1'b0;

   /* JTAG DPI-based verification IP */
   generate
      if(ENABLE_DPI == 1) begin
         jtag_dpi #(
            .TIMEOUT_COUNT ( 6'h2 )
         ) i_jtag (
            .clk_i    ( w_clk_ref          ),
            .enable_i ( jtag_mux == JTAG_DPI ),
            .tms_o    ( s_vpi_tms    ),
            .tck_o    ( s_vpi_tck    ),
            .trst_o   ( s_vpi_trstn  ),
            .tdi_o    ( s_vpi_tdi    ),
            .tdo_i    ( s_tdo        )
         );
      end
   endgenerate

   /* SPI flash model (not open-source, from Spansion) */
   generate
      if(USE_S25FS256S_MODEL == 1) begin
         s25fs256s #(
            .TimingModel   ( "S25FS256SAGMFI000_F_30pF" ),
            .mem_file_name ( "slm_files/flash_stim.slm" ),
            .UserPreload   (1)
         ) i_spi_flash_csn0 (
            .SI       ( w_spi_master_sdio0 ),
            .SO       ( w_spi_master_sdio1 ),
            .SCK      ( w_spi_master_sck   ),
            .CSNeg    ( w_spi_master_csn0  ),
            .WPNeg    ( w_spi_master_sdio2 ),
            .RESETNeg ( w_spi_master_sdio3 )
         );
      end
      else begin
         assign w_spi_master_sdio1 = 'z;
      end
   endgenerate

   if (CONFIG_FILE == "NONE") begin
      /* UART receiver */
      uart_tb_rx #(
         .BAUD_RATE ( BAUDRATE   ),
         .PARITY_EN ( 0          )
      ) i_rx_mod (
         .rx        ( w_uart_rx       ),
         .rx_en     ( uart_tb_rx_en ),
         .word_done (               )
      );
   end

   if (!ENABLE_DEV_DPI && CONFIG_FILE == "NONE") begin

      /* CPI verification IP */
      if (!USE_SDVT_CPI) begin
         cam_vip #(
            .HRES       ( 320 ),
            .VRES       ( 240 )
         ) i_cam_vip (
            .cam_pclk_o  ( w_cam_pclk  ),
            .cam_vsync_o ( w_cam_vsync ),
            .cam_href_o  ( w_cam_hsync ),
            .cam_data_o  ( w_cam_data  )
         );
      end

      /* I2C memory models */
      if(USE_24FC1025_MODEL) begin
         M24FC1025 i_i2c_mem_0 (
            .A0    ( 1'b0       ),
            .A1    ( 1'b0       ),
            .A2    ( 1'b1       ),
            .WP    ( 1'b0       ),
            .SDA   ( w_i2c0_sda ),
            .SCL   ( w_i2c0_scl ),
            .RESET ( 1'b0       )
         );
         M24FC1025 i_i2c_mem_1 (
            .A0    ( 1'b1       ),
            .A1    ( 1'b0       ),
            .A2    ( 1'b1       ),
            .WP    ( 1'b0       ),
            .SDA   ( w_i2c0_sda ),
            .SCL   ( w_i2c0_scl ),
            .RESET ( 1'b0       )
         );
      end

      /* I2S verification IPs */
      if(USE_I2S_MODEL) begin
         i2s_vip #(
            .I2S_CHAN ( 0              ),
            .FILENAME ( I2S_FILENAME_0 )
         ) i_i2s_vip_ch0 (
            .A0     ( 1'b0          ),
            .A1     ( 1'b1          ),
            .SDA    ( w_i2c0_sda    ),
            .SCL    ( w_i2c0_scl    ),
            .sck_i  ( w_i2s_sck     ),
            .ws_i   ( w_i2s_ws      ),
            .data_o ( w_i2s_data[0] ),
            .sck_o  (               ),
            .ws_o   (               )
         );

         i2s_vip #(
            .I2S_CHAN ( 1              ),
            .FILENAME ( I2S_FILENAME_1 )
         )
         i_i2s_vip_ch1 (
            .A0     ( 1'b1          ),
            .A1     ( 1'b1          ),
            .SDA    ( w_i2c0_sda    ),
            .SCL    ( w_i2c0_scl    ),
            .sck_i  ( w_i2s_sck     ),
            .ws_i   ( w_i2s_ws      ),
            .data_o ( w_i2s_data[1] ),
            .sck_o  (               ),
            .ws_o   (               )
         );

         i2s_vip #(
            .I2S_CHAN ( 2              ),
            .FILENAME ( I2S_FILENAME_2 )
         ) i_i2s_CAM_MASTER_SLAVE (
            .A0     ( 1'b0              ),
            .A1     ( 1'b0              ),
            .SDA    ( w_i2c0_sda        ),
            .SCL    ( w_i2c0_scl        ),
            .sck_i  ( w_i2s_sck         ),
            .ws_i   ( w_i2s_ws          ),
            .data_o ( s_master_i2s_sdi0 ),
            .sck_o  ( w_master_i2s_sck  ),
            .ws_o   ( w_master_i2s_ws   )
         );

         i2s_vip #(
            .I2S_CHAN ( 3              ),
            .FILENAME ( I2S_FILENAME_3 )
         )
         i_i2s_CAM_SLAVE
            (
               .A0     ( 1'b1             ),
               .A1     ( 1'b0             ),
               .SDA    ( w_i2c0_sda       ),
               .SCL    ( w_i2c0_scl       ),
               .sck_i  ( s_slave_i2s_sck  ),
               .ws_i   ( s_slave_i2s_ws   ),
               .data_o ( s_slave_i2s_sdi1 ),
               .sck_o  (                  ),
               .ws_o   (                  )
            );
      end

   end

   /* PULPissimo chip (design under test) */
   pulpissimo #(
      .CORE_TYPE ( CORE_TYPE ),
      .USE_FPU   ( RISCY_FPU )
   )
   i_dut (
      .pad_spim_sdio0     ( w_spi_master_sdio0 ),
      .pad_spim_sdio1     ( w_spi_master_sdio1 ),
      .pad_spim_sdio2     ( w_spi_master_sdio2 ),
      .pad_spim_sdio3     ( w_spi_master_sdio3 ),
      .pad_spim_csn0      ( w_spi_master_csn0  ),
      .pad_spim_csn1      ( w_spi_master_csn1  ),
      .pad_spim_sck       ( w_spi_master_sck   ),

      .pad_uart_rx        ( w_uart_tx          ),
      .pad_uart_tx        ( w_uart_rx          ),

      .pad_cam_pclk       ( w_cam_pclk         ),
      .pad_cam_hsync      ( w_cam_hsync        ),
      .pad_cam_data0      ( w_cam_data[0]      ),
      .pad_cam_data1      ( w_cam_data[1]      ),
      .pad_cam_data2      ( w_cam_data[2]      ),
      .pad_cam_data3      ( w_cam_data[3]      ),
      .pad_cam_data4      ( w_cam_data[4]      ),
      .pad_cam_data5      ( w_cam_data[5]      ),
      .pad_cam_data6      ( w_cam_data[6]      ),
      .pad_cam_data7      ( w_cam_data[7]      ),
      .pad_cam_vsync      ( w_cam_vsync        ),

      .pad_i2c0_sda       ( w_i2c0_sda         ),
      .pad_i2c0_scl       ( w_i2c0_scl         ),

      .pad_i2s0_sck       ( w_i2s0_sck         ),
      .pad_i2s0_ws        ( w_i2s0_ws          ),
      .pad_i2s0_sdi       ( w_i2s0_sdi         ),
      .pad_i2s1_sdi       ( w_i2s1_sdi         ),

      .pad_reset_n        ( w_rst_n            ),
      .pad_bootsel        ( w_bootsel          ),

      .pad_jtag_tck       ( w_tck              ),
      .pad_jtag_tdi       ( w_tdi              ),
      .pad_jtag_tdo       ( w_tdo              ),
      .pad_jtag_tms       ( w_tms              ),
      .pad_jtag_trst      ( w_trstn            ),

      .pad_xtal_in        ( w_clk_ref          )
   );

   tb_clk_gen #( .CLK_PERIOD(REF_CLK_PERIOD) ) i_ref_clk_gen (.clk_o(s_clk_ref) );

   /* testbench driver process */
   initial
      begin

         logic [1:0]  dm_op;
         logic [31:0] dm_data;
         logic [6:0]  dm_addr;

         force tb_pulp.i_dut.pad_frame_i.padinst_reset_n.O = 1'b0;
         jtag_enable = 1'b0;
         if (ENABLE_EXTERNAL_DRIVER == 0) begin

            // force fetch enable to 0 when doing JTAG preload (not particularly clean,   but works)
            if(LOAD_L2 == "JTAG")

            if (USE_FLL)
               $display("[TB] %t - Using FLL", $realtime);
            else
               $display("[TB] %t - Not using FLL", $realtime);

            if (USE_SDVT_CPI)
               $display("[TB] %t - Using CAM SDVT", $realtime);
            else
               $display("[TB] %t - Not using CAM SDVT", $realtime);

            if (LOAD_L2 == "STANDALONE")
               s_mode_select = 1'b1;
            else
               s_mode_select = 1'b0;

            $readmemh("/usr/scratch/larain5/pschiavo/pulpissimo/pulp-sdk/tests/riscv_tests/testPMP/build/pulpissimo/vectors/stim.txt", stimuli);  // read in the stimuli vectors  == address_value

         end

         $display("[TB] %t - Asserting hard reset", $realtime);

         #1ns

         release tb_pulp.i_dut.pad_frame_i.padinst_reset_n.O;
         uart_tb_rx_en   = 1'b1; // enable uart rx in testbench

         if (ENABLE_EXTERNAL_DRIVER == 0) begin

            //test_mode_if = new;
            //dbg_if_soc   = new;

            jtag_pkg::jtag_reset(
               s_tck,
               s_tms,
               s_trstn,
               s_tdi
            );
            jtag_pkg::jtag_softreset(
               s_tck,
               s_tms,
               s_trstn,
               s_tdi
            );
            #5us;

            jtag_pkg::jtag_bypass_test(
               s_tck,
               s_tms,
               s_trstn,
               s_tdi,
               s_tdo
            );
            #5us;

            jtag_pkg::jtag_get_idcode(
               s_tck,
               s_tms,
               s_trstn,
               s_tdi,
               s_tdo
            );
            #5us;


            s_rst_n = 1'b1;

            debug_mode_if.init(
               s_tck,
               s_tms,
               s_trstn,
               s_tdi
            );
            #5us;


            debug_mode_if.read_dtmcs(
               s_tck,
               s_tms,
               s_trstn,
               s_tdi,
               s_tdo
            );
            #5us;


            debug_mode_if.init_dmi(
               s_tck,
               s_tms,
               s_trstn,
               s_tdi
            );
            #5us;

            debug_mode_if.set_dmi(
               2'b01, //read
               7'h11, //DMStatus
               32'h0, //whatever
               {dm_addr, dm_data, dm_op},
               s_tck,
               s_tms,
               s_trstn,
               s_tdi,
               s_tdo
            );
            #5us;
           $display("PULPissimo Debug version: \
                 impebreak %x\n \
                 allhavereset %x\n \
                 anyhavereset %x\n \
                 allrunning %x\n \
                 anyrunning %x\n \
                 allhalted %x\n \
                 anyhalted %x\n \
                 version %x\n \
              ", dm_data[22], dm_data[19], dm_data[18], dm_data[11], dm_data[10], dm_data[9], dm_data[8], dm_data[3:0]);


            debug_mode_if.set_dmi(
               2'b10, //Write
               7'h10, //DMControl
               {1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 10'b0, 10'b0, 2'b0, 1'b0, 1'b0, 1'b0, 1'b1}, //dmactive
               {dm_addr, dm_data, dm_op},
               s_tck,
               s_tms,
               s_trstn,
               s_tdi,
               s_tdo
            );
            #5us

            debug_mode_if.set_dmi(
               2'b01, //read
               7'h38, //sbcs,
               32'h0, //whatever
               {dm_addr, dm_data, dm_op},
               s_tck,
               s_tms,
               s_trstn,
               s_tdi,
               s_tdo
            );
            #5us;
           $display("PULPissimo System Bus Access Control and Status: \
                 sbbusy  %x\n \
                 sbreadonaddr %x\n \
                 sbaccess  %x\n \
                 sbautoincrement  %x\n \
                 sbreadondata  %x\n \
                 sberror %x\n \
                 sbasize %x\n \
                 sbaccess32 %x\n \
              ", dm_data[21], dm_data[20], dm_data[19:17], dm_data[16], dm_data[15], dm_data[14:12], dm_data[11:5], dm_data[2]);

            dm_data[20] = 1'b1;

            debug_mode_if.set_dmi(
               2'b10, //write
               7'h38, //sbcs,
               dm_data, //whatever
               {dm_addr, dm_data, dm_op},
               s_tck,
               s_tms,
               s_trstn,
               s_tdi,
               s_tdo
            );
            #5us;

            //Read the BootAddress
            debug_mode_if.set_dmi(
               2'b10, //write
               7'h39, //sbaddress0,
               32'h1A104004, //bootaddress
               {dm_addr, dm_data, dm_op},
               s_tck,
               s_tms,
               s_trstn,
               s_tdi,
               s_tdo
            );
            #5us;
            debug_mode_if.set_dmi(
               2'b01, //read
               7'h3C, //sbdata0,
               32'h0, //whatever
               {dm_addr, dm_data, dm_op},
               s_tck,
               s_tms,
               s_trstn,
               s_tdi,
               s_tdo
            );

           $display("Debugger read at %x and the value is %x \n
              ", 32'h1A104004, dm_data);

            debug_mode_if.set_dmi(
               2'b10, //write
               7'h3C, //sbdata0,
               32'h1d008080, //whatever
               {dm_addr, dm_data, dm_op},
               s_tck,
               s_tms,
               s_trstn,
               s_tdi,
               s_tdo
            );


            //Read the BootAddress
            debug_mode_if.set_dmi(
               2'b10, //write
               7'h39, //sbaddress0,
               32'h1A104004, //bootaddress
               {dm_addr, dm_data, dm_op},
               s_tck,
               s_tms,
               s_trstn,
               s_tdi,
               s_tdo
            );

            #5us;
            debug_mode_if.set_dmi(
               2'b01, //read
               7'h3C, //sbdata0,
               32'h0, //whatever
               {dm_addr, dm_data, dm_op},
               s_tck,
               s_tms,
               s_trstn,
               s_tdi,
               s_tdo
            );
           $display("Debugger read again at %x and the value is %x \n
              ", 32'h1A104004, dm_data);

            if(LOAD_L2 == "JTAG") begin
               $display("[TB] %t - Loading L2", $realtime);
               debug_mode_if.load_L2(num_stim, stimuli, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
               $display("[TB] %t - Setting Boot Address", $realtime);
               //dbg_if_soc.write32(32'h1A104004, 1, BEGIN_L2_INSTR, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
               //$display("[TB] %t - Triggering fetch enable", $realtime);
               //dbg_if_soc.write32(32'h1A104008, 1, 32'h1, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
            end


            $stop();


            //FE and BootAddress
            force tb_pulp.i_dut.soc_domain_i.pulp_soc_i.soc_peripherals_i.apb_soc_ctrl_i.fc_bootaddr_o = 32'h1A000000;
            force tb_pulp.i_dut.soc_domain_i.pulp_soc_i.soc_peripherals_i.apb_soc_ctrl_i.fc_fetchen_o  = 1'b1;

            debug_mode_if.set_dmi(
               2'b10, //Write
               7'h10, //DMControl
               {1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 10'b0, 10'b0, 2'b0, 1'b0, 1'b0, 1'b0, 1'b1},//haltreq
               {dm_addr, dm_data, dm_op},
               s_tck,
               s_tms,
               s_trstn,
               s_tdi,
               s_tdo
            );
            #5us;


/*
            if(LOAD_L2 == "JTAG") begin
               $display("[TB] %t - Virtually removing ROM as JTAG boot was selected in testbench", $realtime);
               for(int i=0; i<2048; i++)
                  tb_pulp.i_dut.soc_domain_i.pulp_soc_i.boot_rom_i.rom_mem_i.MEM[i] = 32'h0;
            end
*/
/*
            test_mode_if.init(
               s_tck,
               s_tms,
               s_trstn,
               s_tdi
            );

            jtag_conf_reg = {USE_FLL ? 1'b0 : 1'b1, 6'b0, LOAD_L2 == "JTAG" ? 2'b11 : 2'b00};
            $display("[TB] %t - jtag_conf_reg is %x", $realtime, jtag_conf_reg);


            $display("[TB] %t - Enabling clock out via jtag", $realtime);
            test_mode_if.set_confreg(
               jtag_conf_reg,
               jtag_conf_rego,
               s_tck,
               s_tms,
               s_trstn,
               s_tdi,
               s_tdo
            );
            $display("[TB] %t - jtag_conf_reg is %x and jtag_conf_rego is %x", $realtime, jtag_conf_reg, jtag_conf_rego);

            if (ENABLE_DPI == 1)
               begin
                  jtag_mux = JTAG_DPI;
               end
*/
            #50000us;

            s_rst_n = 1'b1;
            jtag_enable = 1'b0;

            $display("[TB] %t - Releasing hard reset", $realtime);

            jtag_enable = 1'b1;

            #350us;

            //jtag_enable = 1'b1;

            #1000000000000us;
            $display("Too EARLY man %t",$realtime);

            dbg_if_soc.init(s_tck, s_tms, s_trstn, s_tdi);

            if(LOAD_L2 == "JTAG") begin
               $display("[TB] %t - Loading L2", $realtime);
               dbg_pkg::jtag_load_L2(num_stim, stimuli, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
               $display("[TB] %t - Setting Boot Address", $realtime);
               dbg_if_soc.write32(32'h1A104004, 1, BEGIN_L2_INSTR, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
               $display("[TB] %t - Triggering fetch enable", $realtime);
               dbg_if_soc.write32(32'h1A104008, 1, 32'h1, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
            end

            #300us;

            // Select UART driver/monitor
            if ($value$plusargs("uart_drv_mon=%s", uart_drv_mon_sel)) begin
               if (uart_drv_mon_sel == "VIP") begin
                  uart_tb_rx_en = 1'b0;
                  uart_vip_rx_en = 1'b1;
               end
            end

            // make sure that we can drive the SSPI lines when not in use
            s_padmode_spi_master = SPI_QUAD_RX;

            jtag_data[0] = 0;

            if(EXEC_TEST == "JTAG_DEBUG") begin
               $display("[TEST JTAG_DEBUG]",);
               #1000us
               debug_tests();
            end

            // wait for end of computation signal
            $display("[TB] %t - Waiting for end of computation", $realtime);
            while(jtag_data[0][31] == 0) begin
               dbg_if_soc.read32(32'h1A1040A0, 1, jtag_data, s_tck, s_tms, s_trstn, s_tdi, s_tdo);
               #50us;
            end

            if (jtag_data[0][30:0] == 0)
               exit_status = `EXIT_SUCCESS;
            else
               exit_status = `EXIT_FAIL;
            $display("[TB] %t - Received status core: 0x%h", $realtime, jtag_data[0][30:0]);

            $stop;

         end
         else begin // ENABLE_EXTERNAL_DRIVER != 0
            #1us
               dev_dpi_en <= 1;
         end

      end
/*
    SimJTAG i_SimJTAG (
        .clock                ( w_clk_ref            ),
        .reset                ( ~s_rst_n             ),
        .enable               ( jtag_enable          ),
        .init_done            ( s_rst_n              ),
        .jtag_TCK             ( sim_tck              ),
        .jtag_TMS             ( sim_tms              ),
        .jtag_TDI             ( sim_tdi              ),
        .jtag_TRSTn           ( sim_trstn            ),
        .jtag_TDO_data        ( sim_tdo              ),
        .jtag_TDO_driven      ( 1'b1                 ),
        .exit                 (                      )
    );
*/
   `ifndef USE_NETLIST
      /* File System access */
      logic r_stdout_pready;

      logic        fs_clk;
      logic        fs_rst_n;
      logic        fs_wen;
      logic [0:0]  fs_csn;
      logic [31:0] fs_add;
      logic [3:0]  fs_be;
      logic [31:0] fs_wdata;
      logic [31:0] fs_rdata;

      assign fs_clk = i_dut.soc_domain_i.pulp_soc_i.s_soc_clk;
      assign fs_rst_n = i_dut.soc_domain_i.pulp_soc_i.s_soc_rstn;

      assign fs_csn   = ~(i_dut.soc_domain_i.pulp_soc_i.soc_peripherals_i.s_stdout_bus.psel &
         i_dut.soc_domain_i.pulp_soc_i.soc_peripherals_i.s_stdout_bus.penable &
         r_stdout_pready);
      assign fs_wen   = ~i_dut.soc_domain_i.pulp_soc_i.soc_peripherals_i.s_stdout_bus.pwrite;
      assign fs_add   = i_dut.soc_domain_i.pulp_soc_i.soc_peripherals_i.s_stdout_bus.paddr;
      assign fs_wdata = i_dut.soc_domain_i.pulp_soc_i.soc_peripherals_i.s_stdout_bus.pwdata;
      assign fs_be    = 4'hF;
      assign i_dut.soc_domain_i.pulp_soc_i.soc_peripherals_i.s_stdout_bus.pready  = r_stdout_pready;
      assign i_dut.soc_domain_i.pulp_soc_i.soc_peripherals_i.s_stdout_bus.pslverr = 1'b0;
      assign i_dut.soc_domain_i.pulp_soc_i.soc_peripherals_i.s_stdout_bus.prdata  = fs_rdata;

      always_ff @(posedge fs_clk or negedge fs_rst_n) begin
         if(~fs_rst_n) begin
            r_stdout_pready <= 0;
         end
         else begin
            r_stdout_pready <= (i_dut.soc_domain_i.pulp_soc_i.soc_peripherals_i.s_stdout_bus.psel & i_dut.soc_domain_i.pulp_soc_i.soc_peripherals_i.s_stdout_bus.penable);
         end
      end

      tb_fs_handler #(
         .ADDR_WIDTH ( 32       ),
         .DATA_WIDTH ( 32       ),
         .NB_CORES   ( NB_CORES )
      ) i_fs_handler (
         .clk   ( fs_clk   ),
         .rst_n ( fs_rst_n ),
         .CSN   ( fs_csn   ),
         .WEN   ( fs_wen   ),
         .ADDR  ( fs_add   ),
         .WDATA ( fs_wdata ),
         .BE    ( fs_be    ),
         .RDATA ( fs_rdata )
      );
   `endif

   /* tracing */
   integer               IOFILE[NB_CORES];
   string                FILENAME[NB_CORES];
   string                FILE_ID;

   logic                 is_Read[NB_CORES];

   initial
      begin
         for(int index = 0; index < NB_CORES; index++) begin : _CREATE_IO_FILES_
            FILE_ID.itoa(index);
            FILENAME[index] = { "CORE_", FILE_ID, ".txt" };
            IOFILE[index]   = $fopen(FILENAME[index],"w");
            is_Read[index]  = 0;
         end
      end

      `include "tb_jtag_debug.sv"

endmodule // tb_pulp
