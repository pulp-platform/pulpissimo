//-----------------------------------------------------------------------------
// Title         : PULPissimo Verilog Wrapper
//-----------------------------------------------------------------------------
// File          : xilinx_pulpissimo.v
// Author        : Manuel Eggimann  <meggimann@iis.ee.ethz.ch>
// Created       : 21.05.2019
//-----------------------------------------------------------------------------
// Description :
// Verilog Wrapper of PULPissimo to use the module within Xilinx IP integrator.
//-----------------------------------------------------------------------------
// Copyright (C) 2013-2019 ETH Zurich, University of Bologna
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.
//-----------------------------------------------------------------------------

module xilinx_pulpissimo (
  input wire  ref_clk_p,
  input wire  ref_clk_n,

  // inout wire  pad_spim_sdio0,
  inout wire  pad_spim_sdio1,
  inout wire  pad_spim_sdio2,
  inout wire  pad_spim_sdio3,
  inout wire  pad_spim_csn0,
  inout wire  pad_spim_sck,

  inout wire  pad_uart_rx,
  inout wire  pad_uart_tx,

  inout wire  led0_o, //Mapped to spim_csn1
  inout wire  led1_o, //Mapped to cam_pclk
  inout wire  led2_o, //Mapped to cam_hsync
  inout wire  led3_o, //Mapped to cam_data0

  inout wire  switch0_i, //Mapped to cam_data1
  inout wire  switch1_i, //Mapped to cam_data2

  inout wire  btnc_i, //Mapped to cam_data3
  inout wire  btnd_i, //Mapped to cam_data4
  inout wire  btnl_i, //Mapped to cam_data5
  inout wire  btnr_i, //Mapped to cam_data6
  inout wire  btnu_i, //Mapped to cam_data7

  inout wire  oled_spim_sck_o, //Mapped to spim_sck
  inout wire  oled_spim_mosi_o, //Mapped to spim_sdio0
  inout wire  oled_rst_o, //Mapped to i2s0_sck
  inout wire  oled_dc_o, //Mapped to i2s0_ws
  inout wire  oled_vbat_o, // Mapped to i2s0_sdi
  inout wire  oled_vdd_o, // Mapped to i2s1_sdi

  inout wire  sdio_reset_o, //Reset signal for SD card need to be driven low to
                             //power the onboard sd-card. Mapped to cam_vsync.
  inout wire  pad_sdio_clk,
  inout wire  pad_sdio_cmd,
  inout wire  pad_sdio_data0,
  inout wire  pad_sdio_data1,
  inout wire  pad_sdio_data2,
  inout wire  pad_sdio_data3,

  inout wire  pad_i2c0_sda,
  inout wire  pad_i2c0_scl,

  input wire  pad_reset_n,

  inout wire  pad_jtag_tck,
  inout wire  pad_jtag_tdi,
  inout wire  pad_jtag_tdo,
  inout wire  pad_jtag_tms,
  inout wire  pad_jtag_trst
);

  localparam CORE_TYPE = 0; // 0 for RISCY, 1 for IBEX RV32IMC (formerly ZERORISCY), 2 for IBEX RV32EC (formerly MICRORISCY)
  localparam USE_FPU   = 1;
  localparam USE_HWPE = 0;

  wire        ref_clk;


  //Differential to single ended clock conversion
  IBUFGDS #(
    .IOSTANDARD("LVDS"),
    .DIFF_TERM("FALSE"),
    .IBUF_LOW_PWR("FALSE")
  ) i_sysclk_iobuf (
    .I(ref_clk_p),
    .IB(ref_clk_n),
    .O(ref_clk)
  );

  pulpissimo #(
    .CORE_TYPE(CORE_TYPE),
    .USE_FPU(USE_FPU),
    .USE_HWPE(USE_HWPE)
  ) i_pulpissimo (
    .pad_ref_clk       ( ref_clk     ),
    .pad_reset_n       ( pad_reset_n ),
    .pad_clk_byp_en    ( 1'b0 ),

    .pad_bootsel0      (  ), // Tied to 0 in run.tcl
    .pad_bootsel1      (  ), // Tied to 0 in run.tcl

    .pad_jtag_tck      ( pad_jtag_tck ),
    .pad_jtag_tdi      ( pad_jtag_tdi ),
    .pad_jtag_tdo      ( pad_jtag_tdo ),
    .pad_jtag_tms      ( pad_jtag_tms ),
    .pad_jtag_trstn    ( pad_jtag_trst ),

    .pad_hyper_csn     (  ), // Tied to 0 in run.tcl
    .pad_hyper_reset_n (  ), // Tied to 0 in run.tcl
    .pad_hyper_ck      (  ), // Tied to 0 in run.tcl
    .pad_hyper_ckn     (  ), // Tied to 0 in run.tcl
    .pad_hyper_dq      (  ), // Tied to 0 in run.tcl
    .pad_hyper_rwds    (  ), // Tied to 0 in run.tcl

    .pad_io            ( {
      pad_i2c0_scl,     // io_31
      pad_i2c0_sda,     // io_30
      pad_sdio_data3,   // io_29
      pad_sdio_data2,   // io_28
      pad_sdio_data1,   // io_27
      pad_sdio_data0,   // io_26
      pad_sdio_cmd,     // io_25
      pad_sdio_clk,     // io_24
      oled_vdd_o,       // io_23
      oled_vbat_o,      // io_22
      oled_dc_o,        // io_21
      oled_rst_o,       // io_20
      oled_spim_sck_o,  // io_19
      btnu_i,           // io_18
      btnr_i,           // io_17
      btnl_i,           // io_16
      btnd_i,           // io_15
      btnc_i,           // io_14
      switch1_i,        // io_13
      switch0_i,        // io_12
      led3_o,           // io_11
      led2_o,           // io_10
      led1_o,           // io_09
      led0_o,           // io_08
      pad_spim_sdio3,   // io_07
      pad_spim_sdio2,   // io_06
      pad_spim_sdio1,   // io_05
      oled_spim_mosi_o, // io_04
      pad_spim_csn0,    // io_03
      pad_spim_sck,     // io_02
      pad_uart_rx,      // io_01
      pad_uart_tx       // io_00
    } )
  );

endmodule
