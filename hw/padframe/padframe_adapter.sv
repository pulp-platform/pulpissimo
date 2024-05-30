//-----------------------------------------------------------------------------
// Title         : Wrapper for the auto-generate padframe
//-----------------------------------------------------------------------------
// File          : padframe_wrap.sv
// Author        : Manuel Eggimann  <meggimann@iis.ee.ethz.ch>
// Created       : 05.12.2022
//-----------------------------------------------------------------------------
// Description :
// This module wraps the auto-generates padframe and assigns the control/IO
// signals from the udam structs to the padframe generated structs.
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

module padframe_adapter #(
  /// Have a look at the README in the GPIO repo in order to change the number of GPIOs.
  localparam int unsigned NGPIO = gpio_reg_pkg::GPIOCount
)(
  input logic              soc_clk_i,
  input logic              soc_rstn_synced_i,
  APB.Slave                apb_cfg_slave,
  // IO Pad Signals
  inout wire               pad_ref_clk,
  inout wire               pad_clk_byp_en,
  inout wire               pad_reset_n,
  inout wire               pad_bootsel0,
  inout wire               pad_bootsel1,
  inout wire               pad_jtag_tck,
  inout wire               pad_jtag_trstn,
  inout wire               pad_jtag_tms,
  inout wire               pad_jtag_tdi,
  inout wire               pad_jtag_tdo,
  inout wire [1:0]         pad_hyper_csn,
  inout wire               pad_hyper_reset_n,
  inout wire               pad_hyper_ck,
  inout wire               pad_hyper_ckn,
  inout wire [7:0]         pad_hyper_dq,
  inout wire               pad_hyper_rwds,
  inout wire [NGPIO-1:0]   pad_io,
  // SoC IO Signals
  output logic             ref_clk_o,
  output logic             global_rst_no,
  output logic             global_clk_byp_o,
  output logic [1:0]       bootsel_o,
  output logic             jtag_tck_o,
  output logic             jtag_trst_no,
  output logic             jtag_tms_o,
  output logic             jtag_tdi_o,
  input logic              jtag_tdo_i,

  // Timer PWM output signals (4 channels per timer)
  input logic [3:0]        timer_ch0_i,
  input logic [3:0]        timer_ch1_i,
  input logic [3:0]        timer_ch2_i,
  input logic [3:0]        timer_ch3_i,

  // GPIO
  output logic [NGPIO-1:0] gpio_o,
  input logic [NGPIO-1:0]  gpio_i,
  input logic [NGPIO-1:0]  gpio_tx_en_i,

  // uDMA Peripherals
  // UART
  input                    uart_pkg::uart_to_pad_t [udma_cfg_pkg::N_UART-1:0] uart_to_pad_i,
  output                   uart_pkg::pad_to_uart_t [udma_cfg_pkg::N_UART-1:0] pad_to_uart_o,
  // I2C
  input                    i2c_pkg::i2c_to_pad_t [udma_cfg_pkg::N_I2C-1:0] i2c_to_pad_i,
  output                   i2c_pkg::pad_to_i2c_t [udma_cfg_pkg::N_I2C-1:0] pad_to_i2c_o,
  // SDIO
  input                    sdio_pkg::sdio_to_pad_t [udma_cfg_pkg::N_SDIO-1:0] sdio_to_pad_i,
  output                   sdio_pkg::pad_to_sdio_t [udma_cfg_pkg::N_SDIO-1:0] pad_to_sdio_o,
  // I2S
  input                    i2s_pkg::i2s_to_pad_t [udma_cfg_pkg::N_I2S-1:0] i2s_to_pad_i,
  output                   i2s_pkg::pad_to_i2s_t [udma_cfg_pkg::N_I2S-1:0] pad_to_i2s_o,
  // QSPI
  input                    qspi_pkg::qspi_to_pad_t [udma_cfg_pkg::N_QSPIM-1:0] qspi_to_pad_i,
  output                   qspi_pkg::pad_to_qspi_t [udma_cfg_pkg::N_QSPIM-1:0] pad_to_qspi_o,
  // CPI
  output                   cpi_pkg::pad_to_cpi_t [udma_cfg_pkg::N_CPI-1:0] pad_to_cpi_o,
  // HYPER
  input                    hyper_pkg::hyper_to_pad_t [udma_cfg_pkg::N_HYPER-1:0] hyper_to_pad_i,
  output                   hyper_pkg::pad_to_hyper_t [udma_cfg_pkg::N_HYPER-1:0] pad_to_hyper_o
);
  import pkg_pulpissimo_padframe::*;
  `include "pulpissimo_padframe/assign.svh"
  `include "register_interface/typedef.svh"
  `include "register_interface/assign.svh"

  // Convert APB to regbus
  typedef logic [31:0] addr_t;
  typedef logic [31:0] data_t;
  typedef logic [3:0]  strb_t;
  `REG_BUS_TYPEDEF_ALL(regbus, addr_t, data_t, strb_t);
  regbus_req_t s_cfg_regbus_req;
  regbus_rsp_t s_cfg_regbus_rsp;

  REG_BUS #(.ADDR_WIDTH(32), .DATA_WIDTH(32)) s_cfg_regbus(.clk_i(soc_clk_i));
  apb_to_reg i_apb_to_regbus (
    .clk_i     ( soc_clk_i           ),
    .rst_ni    ( soc_rstn_synced_i   ),
    .penable_i ( apb_cfg_slave.penable ),
    .pwrite_i  ( apb_cfg_slave.pwrite  ),
    .paddr_i   ( apb_cfg_slave.paddr   ),
    .psel_i    ( apb_cfg_slave.psel    ),
    .pwdata_i  ( apb_cfg_slave.pwdata  ),
    .prdata_o  ( apb_cfg_slave.prdata  ),
    .pready_o  ( apb_cfg_slave.pready  ),
    .pslverr_o ( apb_cfg_slave.pslverr ),
    .reg_o     ( s_cfg_regbus.out    )
  );

  `REG_BUS_ASSIGN_TO_REQ(s_cfg_regbus_req, s_cfg_regbus)
  `REG_BUS_ASSIGN_FROM_RSP(s_cfg_regbus, s_cfg_regbus_rsp)

  // Assign signals to structs Here we make use of the autogenerates assign
  // macros from padrick. To use them we occasionally have to create
  // intermediate helper structs. Unfortunately, there is no easy way to connect
  // a parametric number of peripherals to padrick generated IPs because padrick
  // does not generate parametric ports (would make the software way more
  // complex). We thus only check, if the number of peripherals configured in
  // the PULP_IO package matches the number we expect and issue an elaboration
  // error if it doesn't. Maybe this part can be improved somehow in the future.
  localparam N_CONNECTED_QSPIM = 1;
  localparam N_CONNECTED_UART  = 1;
  localparam N_CONNECTED_I2C   = 1;
  localparam N_CONNECTED_SDIO  = 1;
  localparam N_CONNECTED_CPI   = 1;
  localparam N_CONNECTED_HYPER = 1;
  localparam N_CONNECTED_I2S = 0;

  if (udma_cfg_pkg::N_QSPIM != N_CONNECTED_QSPIM)
    $error("The number of QSPIM peripherals is %0d but we are only connecting %0d. Please change the padframe wrapper file.", udma_cfg_pkg::N_QSPIM);
  if (udma_cfg_pkg::N_UART != N_CONNECTED_UART)
    $error("The number of UART is %0d but we are only connecting %0d. Please change the padframe wrapper file.", udma_cfg_pkg::N_UART, N_CONNECTED_UART);
  if (udma_cfg_pkg::N_I2C != N_CONNECTED_I2C)
    $error("The number of I2C is %0d but we are only connecting %0d. Please change the padframe wrapper file.", udma_cfg_pkg::N_I2C, N_CONNECTED_I2C);
  if (udma_cfg_pkg::N_SDIO != N_CONNECTED_SDIO)
    $error("The number of SDIO is %0d but we are only connecting %0d. Please change the padframe wrapper file.", udma_cfg_pkg::N_SDIO, N_CONNECTED_SDIO);
  if (udma_cfg_pkg::N_CPI != N_CONNECTED_CPI)
    $error("The number of CPI is %0d but we are only connecting %0d. Please change the padframe wrapper file.", udma_cfg_pkg::N_CPI, N_CONNECTED_CPI);
  if (udma_cfg_pkg::N_HYPER != N_CONNECTED_HYPER)
    $error("The number of HYPER is %0d but we are only connecting %0d. Please change the padframe wrapper file.", udma_cfg_pkg::N_HYPER, N_CONNECTED_HYPER);
  if (udma_cfg_pkg::N_I2S != N_CONNECTED_I2S)
    $error("The number of I2S is %0d but we are only connecting %0d. Please change the padframe wrapper file.", udma_cfg_pkg::N_I2S, N_CONNECTED_I2S);

  static_connection_signals_soc2pad_t s_static_connections_soc2pad;
  static_connection_signals_pad2soc_t s_static_connections_pad2soc;
  // Static Connections
  assign global_clk_byp_o = s_static_connections_pad2soc.all_pads.clk_byp_en;
  assign global_rst_no    = s_static_connections_pad2soc.all_pads.rst_n;
  assign ref_clk_o        = s_static_connections_pad2soc.all_pads.ref_clk;
  assign bootsel_o[0]     = s_static_connections_pad2soc.all_pads.bootsel0;
  assign bootsel_o[1]     = s_static_connections_pad2soc.all_pads.bootsel1;
  // JTAG
  assign jtag_tck_o   = s_static_connections_pad2soc.all_pads.jtag_tck;
  assign jtag_tdi_o   = s_static_connections_pad2soc.all_pads.jtag_tdi;
  assign jtag_tms_o   = s_static_connections_pad2soc.all_pads.jtag_tms;
  assign jtag_trst_no = s_static_connections_pad2soc.all_pads.jtag_trstn;
  assign s_static_connections_soc2pad.all_pads.jtag_tdo = jtag_tdo_i;
  // HyperFlash/HyperRAM
  assign s_static_connections_soc2pad.all_pads.hyper_ck       = hyper_to_pad_i[0].hyper_ck_o;
  assign s_static_connections_soc2pad.all_pads.hyper_ckn      = hyper_to_pad_i[0].hyper_ck_no;
  assign s_static_connections_soc2pad.all_pads.hyper_cs0_no   = hyper_to_pad_i[0].hyper_cs0_no;
  assign s_static_connections_soc2pad.all_pads.hyper_cs1_no   = hyper_to_pad_i[0].hyper_cs1_no;
  assign s_static_connections_soc2pad.all_pads.hyper_dq0_o    = hyper_to_pad_i[0].hyper_dq0_o;
  assign s_static_connections_soc2pad.all_pads.hyper_dq1_o    = hyper_to_pad_i[0].hyper_dq1_o;
  assign s_static_connections_soc2pad.all_pads.hyper_dq2_o    = hyper_to_pad_i[0].hyper_dq2_o;
  assign s_static_connections_soc2pad.all_pads.hyper_dq3_o    = hyper_to_pad_i[0].hyper_dq3_o;
  assign s_static_connections_soc2pad.all_pads.hyper_dq4_o    = hyper_to_pad_i[0].hyper_dq4_o;
  assign s_static_connections_soc2pad.all_pads.hyper_dq5_o    = hyper_to_pad_i[0].hyper_dq5_o;
  assign s_static_connections_soc2pad.all_pads.hyper_dq6_o    = hyper_to_pad_i[0].hyper_dq6_o;
  assign s_static_connections_soc2pad.all_pads.hyper_dq7_o    = hyper_to_pad_i[0].hyper_dq7_o;
  assign s_static_connections_soc2pad.all_pads.hyper_dq_oe    = hyper_to_pad_i[0].hyper_dq_oe;
  assign s_static_connections_soc2pad.all_pads.hyper_reset_no = hyper_to_pad_i[0].hyper_reset_no;
  assign s_static_connections_soc2pad.all_pads.hyper_rwds_o   = hyper_to_pad_i[0].hyper_rwds_o;
  assign s_static_connections_soc2pad.all_pads.hyper_rwds_oe  = hyper_to_pad_i[0].hyper_rwds_oe;
  assign pad_to_hyper_o[0].hyper_dq0_i                           = s_static_connections_pad2soc.all_pads.hyper_dq0_i;
  assign pad_to_hyper_o[0].hyper_dq1_i                           = s_static_connections_pad2soc.all_pads.hyper_dq1_i;
  assign pad_to_hyper_o[0].hyper_dq2_i                           = s_static_connections_pad2soc.all_pads.hyper_dq2_i;
  assign pad_to_hyper_o[0].hyper_dq3_i                           = s_static_connections_pad2soc.all_pads.hyper_dq3_i;
  assign pad_to_hyper_o[0].hyper_dq4_i                           = s_static_connections_pad2soc.all_pads.hyper_dq4_i;
  assign pad_to_hyper_o[0].hyper_dq5_i                           = s_static_connections_pad2soc.all_pads.hyper_dq5_i;
  assign pad_to_hyper_o[0].hyper_dq6_i                           = s_static_connections_pad2soc.all_pads.hyper_dq6_i;
  assign pad_to_hyper_o[0].hyper_dq7_i                           = s_static_connections_pad2soc.all_pads.hyper_dq7_i;
  assign pad_to_hyper_o[0].hyper_rwds_i                          = s_static_connections_pad2soc.all_pads.hyper_rwds_i;

  // Muxed Signals
  port_signals_pad2soc_t s_port_signals_pad2soc;
  port_signals_soc2pad_t s_port_signals_soc2pad;

  // GPIO Signals
  struct packed {
    logic [NGPIO-1:0] gpio_in;
  } gpio_pad2soc_load;

  `ASSIGN_GPIO_PAD2SOC(gpio_pad2soc_load, s_port_signals_pad2soc.all_pads.gpio)
  assign gpio_o = gpio_pad2soc_load.gpio_in;
  struct packed {
    logic [NGPIO-1:0] gpio_out;
    logic [NGPIO-1:0] gpio_tx_en;
  } gpio_soc2pad_driver;

  assign gpio_soc2pad_driver.gpio_out = gpio_i;
  assign gpio_soc2pad_driver.gpio_tx_en = gpio_tx_en_i;
  `ASSIGN_GPIO_SOC2PAD(s_port_signals_soc2pad.all_pads.gpio, gpio_soc2pad_driver)

  // Timer Channels
  typedef struct packed {
    logic [3:0]  out;
  } timer_soc2pad_driver_t;

  timer_soc2pad_driver_t[3:0] timer_soc2pad_driver;
  assign timer_soc2pad_driver[0].out = timer_ch0_i;
  assign timer_soc2pad_driver[1].out = timer_ch1_i;
  assign timer_soc2pad_driver[2].out = timer_ch2_i;
  assign timer_soc2pad_driver[3].out = timer_ch3_i;
  `ASSIGN_TIMER0_SOC2PAD(s_port_signals_soc2pad.all_pads.timer0, timer_soc2pad_driver[0])
  `ASSIGN_TIMER1_SOC2PAD(s_port_signals_soc2pad.all_pads.timer1, timer_soc2pad_driver[1])
  `ASSIGN_TIMER2_SOC2PAD(s_port_signals_soc2pad.all_pads.timer2, timer_soc2pad_driver[2])
  `ASSIGN_TIMER3_SOC2PAD(s_port_signals_soc2pad.all_pads.timer3, timer_soc2pad_driver[3])

  // UART
  assign s_port_signals_soc2pad.all_pads.uart0.tx_o = uart_to_pad_i[0].tx_o;
  assign pad_to_uart_o[0].rx_i = s_port_signals_pad2soc.all_pads.uart0.rx_i;

  //I2C
  `ASSIGN_I2C0_PAD2SOC(pad_to_i2c_o[0], s_port_signals_pad2soc.all_pads.i2c0)

  //SDIO
  `ASSIGN_SDIO0_PAD2SOC(pad_to_sdio_o[0], s_port_signals_pad2soc.all_pads.sdio0)
  `ASSIGN_SDIO0_SOC2PAD(s_port_signals_soc2pad.all_pads.sdio0, sdio_to_pad_i[0])

  //I2S
  `ASSIGN_I2S0_PAD2SOC(pad_to_i2s_o[0], s_port_signals_pad2soc.all_pads.i2s0)
  `ASSIGN_I2S0_SOC2PAD(s_port_signals_soc2pad.all_pads.i2s0, i2s_to_pad_i[0])

  //QSPI Master
  `ASSIGN_QSPIM0_PAD2SOC(pad_to_qspi_o[0], s_port_signals_pad2soc.all_pads.qspim0)
  `ASSIGN_QSPIM0_SOC2PAD(s_port_signals_soc2pad.all_pads.qspim0, qspi_to_pad_i[0])

  //CPI
  `ASSIGN_CPI0_PAD2SOC(pad_to_cpi_o[0], s_port_signals_pad2soc.all_pads.cpi0)

  /////////////////////////////////////////
  // Instantiate Auto-generated Padframe //
  /////////////////////////////////////////

  pulpissimo_padframe #(
    .AW     ( 32           ),
    .DW     ( 32           ),
    .req_t  ( regbus_req_t ),
    .resp_t ( regbus_rsp_t )
  ) i_pulpissimo_pads (
    .clk_i                             ( soc_clk_i                    ),
    .rst_ni                            ( soc_rstn_synced_i            ),
    .config_req_i                      ( s_cfg_regbus_req             ),
    .config_rsp_o                      ( s_cfg_regbus_rsp             ),
    .static_connection_signals_pad2soc ( s_static_connections_pad2soc ),
    .static_connection_signals_soc2pad ( s_static_connections_soc2pad ),
    .port_signals_pad2soc              ( s_port_signals_pad2soc       ),
    .port_signals_soc2pad              ( s_port_signals_soc2pad       ),
    .pad_ref_clk,
    .pad_clk_byp_en,
    .pad_reset_n,
    .pad_bootsel0,
    .pad_bootsel1,
    .pad_jtag_tck,
    .pad_jtag_trstn,
    .pad_jtag_tms,
    .pad_jtag_tdi,
    .pad_jtag_tdo,
    .pad_hyper_csn0                    ( pad_hyper_csn[0]             ),
    .pad_hyper_csn1                    ( pad_hyper_csn[1]             ),
    .pad_hyper_reset_n,
    .pad_hyper_ck,
    .pad_hyper_ckn,
    .pad_hyper_dq0                     ( pad_hyper_dq[0]              ),
    .pad_hyper_dq1                     ( pad_hyper_dq[1]              ),
    .pad_hyper_dq2                     ( pad_hyper_dq[2]              ),
    .pad_hyper_dq3                     ( pad_hyper_dq[3]              ),
    .pad_hyper_dq4                     ( pad_hyper_dq[4]              ),
    .pad_hyper_dq5                     ( pad_hyper_dq[5]              ),
    .pad_hyper_dq6                     ( pad_hyper_dq[6]              ),
    .pad_hyper_dq7                     ( pad_hyper_dq[7]              ),
    .pad_hyper_rwds,
    .pad_io
  );




endmodule
