//-----------------------------------------------------------------------------
// Title         : Wrapper of ETH custom FLL IP models
//-----------------------------------------------------------------------------
// File          : clock_gen_asic.sv
// Author        : Manuel Eggimann  <meggimann@iis.ee.ethz.ch>
// Created       : 19.04.2022
//-----------------------------------------------------------------------------
// Description :
//
// This module wraps the behavioral FLL models for the technology specific FLLs
// used for ETH/Unibo ASIC tapeouts. If you want to port PULPissimo to a
// different, please provide your own implementation of this module. You can use
// the config `register_interface` to connect to internal register files that
// controll your clock generation IP. In that case,  you will have to modify the
// pulp-runtime/SDK to use your custom FLL configuration interface (i.e. you
// need to provide a driver on how to talk to your PLL/FLL). Vanila
// pulp-runtime/SDK is developed to communicate with this behavioral model.
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
  parameter int unsigned  APB_ADDR_WIDTH,
  localparam int unsigned APB_DATA_WIDTH = 32
)(
  // Reference clock for internal clock generation. The frequency of this clock
  // is platform dependent (the asic version `clock_gen_asic.sv` requires a
  // 32kHz ref clk)
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
  input logic  slow_clk_en_i,
  input logic  slow_clk_byp_en_i, // feed slow_clk_o directly from ref_clk_i,
                                  // this particular implementation already uses
                                  // a ref clock of 32kHz so this port is
                                  // unconnected.
  output logic slow_clk_o,
  // The SoC clock drives the complete SoC domain (should be as fast or faster
  // than per_clk_o)
  input logic  soc_clk_en_i,
  input logic  soc_clk_byp_en_i,
  output logic soc_clk_o,

  // Clock that drives IO buffers within IO peripherals
  input logic  per_clk_en_i,
  input logic  per_clk_byp_en_i,
  output logic per_clk_o
);

  logic        s_clk_fll_soc;
  logic        s_clk_soc_ungated;
  logic        s_clk_fll_per;
  logic        s_clk_per_ungated;

  // Convert APB interface to FLL native interface
  FLL_BUS fll_bus[2](.clk_i(cfg_clk_i));

  apb_to_fll #(
    .APB_ADDR_WIDTH(APB_ADDR_WIDTH),
    .NR_FLLS(2)
  ) apb2fll_if_i (
    .clk_i    ( cfg_clk_i     ),
    .rst_ni,
    .apb      ( cfg_bus_slave ),
    .fll_intf ( fll_bus       )
  );



  // FLL model instantiation

  ///////////////
  // SoC Clock //
  ///////////////

  
  // Behavioral model of ETH internal FLL (the name is for legacy reasons,
  // interface is the same for all technologies the FLL has been ported to.)
  gf22_FLL i_fll_soc (
    .FLLCLK ( s_clk_fll_soc        ),
    .FLLOE  ( 1'b1                 ),
    .REFCLK ( ref_clk_i            ),
    .LOCK   ( fll_bus[0].lock     ),
    .CFGREQ ( fll_bus[0].req      ),
    .CFGACK ( fll_bus[0].ack      ),
    .CFGAD  ( fll_bus[0].addr[1:0] ),
    .CFGD   ( fll_bus[0].wdata    ),
    .CFGQ   ( fll_bus[0].rdata    ),
    .CFGWEB ( fll_bus[0].wrn      ),
    .RSTB   ( rst_ni               ),
    .PWD    ( 1'b0                 ),
    .RET    ( 1'b0                 ),
    .TM     ( dft_test_en_i       ),
    .TE     ( 1'b0                 ),
    .TD     ( 1'b0                 ),
    .TQ     (                      ),
    .JTD    ( 1'b0                 ),
    .JTQ    (                      )
  );

  tc_clk_mux2 i_fll_soc_bypass_mux (
    .clk0_i    ( s_clk_fll_soc     ),
    .clk1_i    ( ref_clk_i         ),
    .clk_sel_i ( soc_clk_byp_en_i  ),
    .clk_o     ( s_clk_soc_ungated )
  );

  tc_clk_gating #(.IS_FUNCTIONAL(1'b1)) i_soc_clk_en(
    .clk_i     ( s_clk_soc_ungated ),
    .en_i      ( soc_clk_en_i      ),
    .test_en_i ( dft_test_en_i     ),
    .clk_o     ( soc_clk_o         )
  );


  //////////////////////
  // Peripheral Clock //
  //////////////////////

  // Behavioral model of ETH internal FLL (the name is for legacy reasons,
  // interface is the same for all technologies the FLL has been ported to.)
  gf22_FLL i_fll_per (
    .FLLCLK ( s_clk_fll_per        ),
    .FLLOE  ( 1'b1                 ),
    .REFCLK ( ref_clk_i            ),
    .LOCK   ( fll_bus[1].lock     ),
    .CFGREQ ( fll_bus[1].req      ),
    .CFGACK ( fll_bus[1].ack      ),
    .CFGAD  ( fll_bus[1].addr[1:0] ),
    .CFGD   ( fll_bus[1].wdata    ),
    .CFGQ   ( fll_bus[1].rdata    ),
    .CFGWEB ( fll_bus[1].wrn      ),
    .RSTB   ( rst_ni               ),
    .PWD    ( 1'b0                 ),
    .RET    ( 1'b0                 ),
    .TM     ( dft_test_en_i       ),
    .TE     ( 1'b0                 ),
    .TD     ( 1'b0                 ),
    .TQ     (                      ),
    .JTD    ( 1'b0                 ),
    .JTQ    (                      )
  );

  tc_clk_mux2 i_fll_per_bypass_mux (
    .clk0_i    ( s_clk_fll_per     ),
    .clk1_i    ( ref_clk_i         ),
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

  tc_clk_gating #(.IS_FUNCTIONAL(1'b1)) i_slow_clk_en(
    .clk_i     ( ref_clk_i     ),
    .en_i      ( slow_clk_en_i ),
    .test_en_i ( dft_test_en_i ),
    .clk_o     ( slow_clk_o    )
  );

  // This implementation does not need the bypass signal since slow clock already == ref_clk
  unread i_unused_slow_clk_bypass_en(.d_i(slow_clk_byp_en_i));
endmodule
