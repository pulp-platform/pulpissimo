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
  input  wire pad_reset,

  output wire test_clk_o,
  output wire obs1_o,
  output wire obs2_o,

  // PMOD JE
  inout  wire pad_jtag_tck,
  inout  wire pad_jtag_tdi,
  inout  wire pad_jtag_tdo,
  inout  wire pad_jtag_tms,

  // PMOD JE
  inout  wire pad_uart_rx,
  inout  wire pad_uart_tx,
  inout  wire pad_uart_rts,
  inout  wire pad_uart_cts,

  inout  wire led0_o,
  inout  wire led1_o,
  inout  wire led2_o,
  inout  wire led3_o,

  inout  wire switch0_i,
  inout  wire switch1_i,
  inout  wire switch2_i,
  inout  wire switch3_i,

  // PMOD JC
  inout  wire pad_pmodc_1,
  inout  wire pad_pmodc_2,
  inout  wire pad_pmodc_3,
  inout  wire pad_pmodc_4,
  inout  wire pad_pmodc_7,
  inout  wire pad_pmodc_8,
  inout  wire pad_pmodc_9,
  inout  wire pad_pmodc_10,

  inout  wire btn1_i,
  inout  wire btn2_i,
  inout  wire btn3_i,

  // PMOD JD
  inout  wire pad_pmodd_1,

  // PMOD JB
  inout  wire pad_pmodb_1,
  inout  wire pad_pmodb_2,
  inout  wire pad_pmodb_3,
  inout  wire pad_pmodb_4,
  inout  wire pad_pmodb_7,
  inout  wire pad_pmodb_8,
  inout  wire pad_pmodb_9,
  inout  wire pad_pmodb_10 
);

  localparam CORE_TYPE = 0; // 0 for RISCY, 1 for IBEX RV32IMC (formerly ZERORISCY), 2 for IBEX RV32EC (formerly MICRORISCY)
  localparam USE_FPU   = 0;
  localparam USE_HWPE  = 1;

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
      pad_pmodd_1,    // io_31
      pad_pmodc_10,   // io_30
      pad_pmodc_9,    // io_29
      pad_pmodc_8,    // io_28
      pad_pmodc_7,    // io_27
      pad_pmodc_4,    // io_26
      pad_pmodc_3,    // io_25
      pad_pmodc_2,    // io_24
      pad_pmodc_1,    // io_23
      pad_pmodb_10,   // io_22
      pad_pmodb_9,    // io_21
      pad_pmodb_8,    // io_20
      pad_pmodb_7,    // io_19
      pad_pmodb_4,    // io_18
      pad_pmodb_3,    // io_17
      pad_pmodb_2,    // io_16
      pad_pmodb_1,    // io_15
      switch3_i,      // io_14
      switch2_i,      // io_13
      switch1_i,      // io_12
      switch0_i,      // io_11
      btn3_i,         // io_10
      btn2_i,         // io_09
      btn1_i,         // io_08
      led3_o,         // io_07
      led2_o,         // io_06
      led1_o,         // io_05
      led0_o,         // io_04
      pad_uart_rts,   // io_03
      pad_uart_cts,   // io_02
      pad_uart_rx,    // io_01
      pad_uart_tx     // io_00
    } )
  );

endmodule
