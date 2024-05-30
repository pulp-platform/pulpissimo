//-----------------------------------------------------------------------------
// Title         : Clock generation for Xilinx Ultrascale FPGAs
//-----------------------------------------------------------------------------
// File          : clock_gen_fpga.sv
// Author        : Manuel Eggimann  <meggimann@iis.ee.ethz.ch>
// Created       : 19.04.2022
//-----------------------------------------------------------------------------
// Description :
//
// This module wraps Xilinx clock wizard Logicore IPs for FPGA emulation of
// PULPissimo at fixed frequency.
//
//-----------------------------------------------------------------------------
// Copyright (C) 2022 ETH Zurich, University of Bologna
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.
// SPDX-License-Identifier: SHL-0.51
//-----------------------------------------------------------------------------


module clock_gen #(
  // address widht of the of configuration bus
  parameter int unsigned APB_ADDR_WIDTH,
  localparam int unsigned APB_DATA_WIDTH = 32
)(
  // Reference clock for internal clock generation. The frequency of this clock
  // is platform dependent (ASIC/RTL sim -> 32kHz)
  input logic  ref_clk_i,

  // Asynchronous active-low reset. Shall reset all clock generation config.
  // Typically connected to a POR.
  input logic  rst_ni,

  // DFT signals
  input logic  dft_test_en_i,

  // Configuration interface for clock generation
  input logic  cfg_clk_i,
  APB.Slave    cfg_bus_slave,


  // Output clocks
  // Slow clock is the 32 kHz clock used for the certain timers
  input logic  slow_byp_clk_i, // The clock used in bypass mode
  input logic  slow_clk_en_i,
  input logic  slow_clk_byp_en_i, // feed slow_clk_o directly from ref_clk_i
  output logic slow_clk_o,
  // The SoC clock drives the complete SoC domain (should be as fast or faster
  // than per_clk_o)
  input logic  soc_byp_clk_i, // The clock used in bypass mode
  input logic  soc_clk_en_i,
  input logic  soc_clk_byp_en_i,
  output logic soc_clk_o,

  // Clock that drives IO buffers within IO peripherals
  input logic  per_byp_clk_i, // The clock used in bypass mode
  input logic  per_clk_en_i,
  input logic  per_clk_byp_en_i,
  output logic per_clk_o
);

  logic        s_clk_fll_soc;
  logic        s_clk_soc_ungated;
  logic        s_clk_fll_per;
  logic        s_clk_per_ungated;
  logic        s_slow_clock;
  logic        s_slow_clk_ungated;

  // Tie-off APB port with error response
  assign cfg_bus_slave.pready  = 1'b1;
  assign cfg_bus_slave.prdata  = 32'hdeadda7a;
  assign cfg_bus_slave.pslverr = 1'b1;

  // Instantiate LogiCore clocking mngr IP
  xilinx_clk_mngr i_clk_manager (
     .resetn(rst_ni),
     .clk_in1(ref_clk_i),
     .clk_out1(s_clk_fll_soc),
     .clk_out2(s_clk_fll_per),
     .locked()
  );

  tc_clk_mux2 i_fll_soc_bypass_mux (
    .clk0_i    ( s_clk_fll_soc     ),
    .clk1_i    ( soc_byp_clk_i     ),
    .clk_sel_i ( soc_clk_byp_en_i  ),
    .clk_o     ( s_clk_soc_ungated )
  );

  tc_clk_gating #(.IS_FUNCTIONAL(1'b1)) i_soc_clk_en(
    .clk_i     ( s_clk_soc_ungated ),
    .en_i      ( soc_clk_en_i      ),
    .test_en_i ( dft_test_en_i     ),
    .clk_o     ( soc_clk_o         )
  );


  tc_clk_mux2 i_fll_per_bypass_mux (
    .clk0_i    ( s_clk_fll_per     ),
    .clk1_i    ( per_byp_clk_i     ),
    .clk_sel_i ( per_clk_byp_en_i  ),
    .clk_o     ( s_clk_per_ungated )
  );

  tc_clk_gating #(.IS_FUNCTIONAL(1'b1)) i_per_clk_en(
    .clk_i     ( s_clk_per_ungated ),
    .en_i      ( per_clk_en_i      ),
    .test_en_i ( dft_test_en_i     ),
    .clk_o     ( per_clk_o         )
  );

  ////////////////
  // Slow Clock //
  ////////////////
  logic        s_intermmediate_slow_clock;
  xilinx_slow_clk_mngr i_slow_clk_mngr (
   .resetn   ( rst_ni                     ),
   .clk_in1  ( ref_clk_i                  ),
   .clk_out1 ( s_intermmediate_slow_clock )
  );

  // Instantiate clock divider to divide 8.3886 MHz PLL clock down to 32 kHz
  clk_int_div #(
    .DIV_VALUE_WIDTH       ( 9    ),
    .DEFAULT_DIV_VALUE     ( 256  ),
    .ENABLE_CLOCK_IN_RESET ( 1'b1 )
  ) i_slow_clk_div (
    .clk_i          ( s_intermmediate_slow_clock ),
    .rst_ni,
    .en_i           ( 1'b1                       ),
    .test_mode_en_i ( dft_test_en_i              ),
    .div_i          ( 256                        ),
    .div_valid_i    ( 1'b0                       ), // We don't use the dynamic config port and only use the
                                                    // default div value. Should be optimized away.
    .div_ready_o    (                            ),
    .clk_o          ( s_slow_clock               ),
    .cycl_count_o   (                            )
  );

  tc_clk_mux2 i_slow_clk_bypass_mux (
    .clk0_i    ( s_slow_clock      ),
    .clk1_i    ( ref_clk_i         ),
    .clk_sel_i ( slow_clk_byp_en_i  ),
    .clk_o     ( s_slow_clk_ungated )
  );

  tc_clk_gating #(.IS_FUNCTIONAL(1'b1)) i_slow_clk_en(
    .clk_i     ( s_slow_clk_ungated ),
    .en_i      ( slow_clk_en_i      ),
    .test_en_i ( dft_test_en_i      ),
    .clk_o     ( slow_clk_o         )
  );

endmodule
