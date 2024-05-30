//-----------------------------------------------------------------------------
// Title         : PULPissimo Verilog Wrapper
//-----------------------------------------------------------------------------
// File          : xilinx_pulpissimo.v
// Author        : Manuel Eggimann  <meggimann@iis.ee.ethz.ch>
//               : Marek Pikuła  <marek.pikula@sent.tech>
// Created       : 08.10.2019
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
   input  wire ref_clk_i,

   inout  wire pad_uart_rx,  //Mapped to uart_rx
   inout  wire pad_uart_tx,  //Mapped to uart_tx
   inout  wire pad_uart_rts, //Mapped to spim_csn0
   inout  wire pad_uart_cts, //Mapped to spim_sck

   inout  wire led0_o, //Mapped to spim_csn1
   inout  wire led1_o, //Mapped to cam_pclk
   inout  wire led2_o, //Mapped to cam_hsync
   inout  wire led3_o, //Mapped to cam_data0
   inout  wire led4_o, //Mapped to spim_sdio0
   inout  wire led5_o, //Mapped to spim_sdio1
   inout  wire led6_o, //Mapped to spim_sdio2
   inout  wire led7_o, //Mapped to spim_sdio3

   inout  wire switch0_i, //Mapped to cam_data1
   inout  wire switch1_i, //Mapped to cam_data2
   inout  wire switch2_i, //Mapped to cam_data7
   inout  wire switch3_i, //Mapped to cam_vsync
   inout  wire switch4_i, //Mapped to sdio_data0
   inout  wire switch5_i, //Mapped to sdio_data1
   inout  wire switch6_i, //Mapped to sdio_data2
   inout  wire switch7_i, //Mapped to sdio_data3

   inout  wire btnu_i, //Mapped to cam_data3
   inout  wire btnr_i, //Mapped to cam_data4
   inout  wire btnd_i, //Mapped to cam_data5
   inout  wire btnl_i, //Mapped to cam_data6

   inout  wire pad_i2c0_sda, //Mapped to i2c0_sda
   inout  wire pad_i2c0_scl, //Mapped to i2c0_scl
   inout  wire pad_i2c1_scl, //Mapped to sdio_clk
   inout  wire pad_i2c1_sda, //Mapped to sdio_cmd
   inout  wire pad_pmod1_4,  //Mapped to i2s0_sck
   inout  wire pad_pmod1_5,  //Mapped to i2s0_ws
   inout  wire pad_pmod1_6,  //Mapped to i2s0_sdi
   inout  wire pad_pmod1_7,  //Mapped to i2s1_sdi

   input  wire pad_reset,

   inout  wire pad_jtag_tck,
   inout  wire pad_jtag_tdi,
   inout  wire pad_jtag_tdo,
   inout  wire pad_jtag_tms
 );

  localparam CORE_TYPE = 0; // 0 for RISCY, 1 for IBEX RV32IMC (formerly ZERORISCY), 2 for IBEX RV32EC (formerly MICRORISCY)
  localparam USE_FPU   = 1;
  localparam USE_HWPE  = 0;

  wire ref_clk_int;
  wire rst_n;
  assign rst_n = ~pad_reset;

  // Input clock buffer
  BUFG i_sysclk_bufg (
    .I(ref_clk_i),
    .O(ref_clk_int)
  );


  // PULPissimo instance
  pulpissimo #(
    .CORE_TYPE(CORE_TYPE),
    .USE_FPU(USE_FPU),
    .USE_HWPE(USE_HWPE)
  ) i_pulpissimo (
    .pad_ref_clk    ( ref_clk_int  ),
    .pad_reset_n    ( rst_n        ),
    .pad_clk_byp_en ( 1'b0 ),

    .pad_bootsel0   ( ),
    .pad_bootsel1   ( ),

    .pad_jtag_tck   ( pad_jtag_tck ),
    .pad_jtag_tdi   ( pad_jtag_tdi ),
    .pad_jtag_tdo   ( pad_jtag_tdo ),
    .pad_jtag_tms   ( pad_jtag_tms ),
    .pad_jtag_trstn (  ), // Tied to 1 in run.tcl

    .pad_hyper_csn     (  ),
    .pad_hyper_reset_n (  ),
    .pad_hyper_ck      (  ),
    .pad_hyper_ckn     (  ),
    .pad_hyper_dq      (  ),
    .pad_hyper_rwds    (  ),

    .pad_io            ( {
      pad_i2c0_scl,   // io_31
      pad_i2c0_sda,   // io_30
      switch7_i,      // io_29
      switch6_i,      // io_28
      switch5_i,      // io_27
      switch4_i,      // io_26
      pad_i2c1_sda,   // io_25
      pad_i2c1_scl,   // io_24
      switch3_i,      // io_23
      pad_pmod1_7,    // io_22
      pad_pmod1_6,    // io_21
      pad_pmod1_5,    // io_20
      pad_pmod1_4,    // io_19
      switch2_i,      // io_18
      btnu_i,         // io_17
      btnr_i,         // io_16
      btnl_i,         // io_15
      btnd_i,         // io_14
      switch1_i,      // io_13
      switch0_i,      // io_12
      led3_o,         // io_11
      led2_o,         // io_10
      led1_o,         // io_09
      led0_o,         // io_08
      led7_o,         // io_07
      led6_o,         // io_06
      led5_o,         // io_05
      led4_o,         // io_04
      pad_uart_rts,   // io_03
      pad_uart_cts,   // io_02
      pad_uart_rx,    // io_01
      pad_uart_tx     // io_00
    } )
  );

endmodule
