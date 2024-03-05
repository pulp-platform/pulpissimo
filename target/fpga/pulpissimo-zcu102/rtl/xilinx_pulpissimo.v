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

module xilinx_pulpissimo
  (
   input wire  ref_clk_p,
   input wire  ref_clk_n,

   inout wire  pad_uart_rx,
   inout wire  pad_uart_tx,
   inout wire  pad_uart_rts, //Mapped to spim_csn0
   inout wire  pad_uart_cts, //Mapped to spim_sck

   inout wire  led0_o, //Mapped to spim_csn1
   inout wire  led1_o, //Mapped to cam_pclk
   inout wire  led2_o, //Mapped to cam_hsync
   inout wire  led3_o, //Mapped to cam_data0

   inout wire  switch0_i, //Mapped to cam_data1
   inout wire  switch1_i, //Mapped to cam_data2
   inout wire  switch2_i, //Mapped to cam_data7
   inout wire  switch3_i, //Mapped to cam_vsync

   inout wire  btn0_i, //Mapped to cam_data3
   inout wire  btn1_i, //Mapped to cam_data4
   inout wire  btn2_i, //Mapped to cam_data5
   inout wire  btn3_i, //Mapped to cam_data6

   inout wire  pad_i2c0_sda,
   inout wire  pad_i2c0_scl,

   inout wire  pad_pmod0_4, //Mapped to spim_sdio0
   inout wire  pad_pmod0_5, //Mapped to spim_sdio1
   inout wire  pad_pmod0_6, //Mapped to spim_sdio2
   inout wire  pad_pmod0_7, //Mapped to spim_sdio3

   inout wire  pad_pmod1_0, //Mapped to sdio_data0
   inout wire  pad_pmod1_1, //Mapped to sdio_data1
   inout wire  pad_pmod1_2, //Mapped to sdio_data2
   inout wire  pad_pmod1_3, //Mapped to sdio_data3
   inout wire  pad_pmod1_4, //Mapped to i2s0_sck
   inout wire  pad_pmod1_5, //Mapped to i2s0_ws
   inout wire  pad_pmod1_6, //Mapped to i2s0_sdi
   inout wire  pad_pmod1_7, //Mapped to i2s1_sdi

   inout wire  pad_hdmi_scl, //Mapped to sdio_clk
   inout wire  pad_hdmi_sda, //Mapped to sdio_cmd

   input wire  pad_reset,

   inout wire  pad_jtag_tck,
   inout wire  pad_jtag_tdi,
   inout wire  pad_jtag_tdo,
   inout wire  pad_jtag_tms
 );

  localparam CORE_TYPE = 0; // 0 for RISCY, 1 for ZERORISCY, 2 for MICRORISCY
  localparam USE_FPU   = 1;
  localparam USE_HWPE = 0;

  wire        ref_clk;
  wire        rst_n;

  assign rst_n = ~pad_reset;


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
    .pad_ref_clk    ( ref_clk      ),
    .pad_reset_n    ( rst_n        ),
    .pad_clk_byp_en ( 1'b0 ),

    .pad_bootsel0   ( ), // Tied to 0 in run.tcl
    .pad_bootsel1   ( ), // Tied to 0 in run.tcl

    .pad_jtag_tck   ( pad_jtag_tck ),
    .pad_jtag_tdi   ( pad_jtag_tdi ),
    .pad_jtag_tdo   ( pad_jtag_tdo ),
    .pad_jtag_tms   ( pad_jtag_tms ),
    .pad_jtag_trstn (  ), // Tied to 1 in run.tcl

    .pad_hyper_csn     (  ), // Tied to 0 in run.tcl
    .pad_hyper_reset_n (  ), // Tied to 0 in run.tcl
    .pad_hyper_ck      (  ), // Tied to 0 in run.tcl
    .pad_hyper_ckn     (  ), // Tied to 0 in run.tcl
    .pad_hyper_dq      (  ), // Tied to 0 in run.tcl
    .pad_hyper_rwds    (  ), // Tied to 0 in run.tcl

    .pad_io            ( {
      pad_i2c0_scl,   // io_31
      pad_i2c0_sda,   // io_30
      pad_pmod1_3,    // io_29
      pad_pmod1_2,    // io_28
      pad_pmod1_1,    // io_27
      pad_pmod1_0,    // io_26
      pad_hdmi_sda,   // io_25
      pad_hdmi_scl,   // io_24
      switch3_i,      // io_23
      pad_pmod1_7,    // io_22
      pad_pmod1_6,    // io_21
      pad_pmod1_5,    // io_20
      pad_pmod1_4,    // io_19
      switch2_i,      // io_18
      btn3_i,         // io_17
      btn2_i,         // io_16
      btn1_i,         // io_15
      btn0_i,         // io_14
      switch1_i,      // io_13
      switch0_i,      // io_12
      led3_o,         // io_11
      led2_o,         // io_10
      led1_o,         // io_09
      led0_o,         // io_08
      pad_pmod0_7,    // io_07
      pad_pmod0_6,    // io_06
      pad_pmod0_5,    // io_05
      pad_pmod0_4,    // io_04
      pad_uart_rts,   // io_03
      pad_uart_cts,   // io_02
      pad_uart_rx,    // io_01
      pad_uart_tx     // io_00
    } )
  );

endmodule
