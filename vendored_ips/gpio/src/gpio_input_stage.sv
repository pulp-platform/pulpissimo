//-----------------------------------------------------------------------------
// Title         : GPIO Input Stage
//-----------------------------------------------------------------------------
// File          : gpio_input_stage.sv
// Author        : Manuel Eggimann  <meggimann@iis.ee.ethz.ch>
// Created       : 14.04.2022
//-----------------------------------------------------------------------------
// Description :
//
// This module implements the input synchronization stage for a single GPIO. It
// uses a two-stage synchronizer for meta-stability resolution. This version of
// the input stage instantiates a clock gate to disable input sampling when the
// corresponding GPIO is disabled. This clock gate instance (tc_clk_gating) is
// behavioraly implemented in the `pulp-plaform/common_cells` (on GitHub)
// repository. In case you want to tape-out this GPIO, you either have to map
// this behavioral clock gate cell to a dedicated ICG of your std cell library
// or use the alternative version (`gpio_input_stage_no_clk_gates.sv`) of the
// input stage that does not include any clock gates.
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


module gpio_input_stage #(
  parameter NrSyncStages=2
) (
   input logic  clk_i,
   input logic  rst_ni,
   input logic  en_i,
   input logic  serial_i,
   output logic r_edge_o,
   output logic f_edge_o,
   output logic serial_o
);

  logic         clk;
  logic         serial, serial_q;

  assign serial_o =  serial_q;
  assign f_edge_o = (~serial) & serial_q;
  assign r_edge_o = serial & (~serial_q);

  tc_clk_gating #(
    .IS_FUNCTIONAL(0) // The clock gate is not required for proper
                      // functionality. Just for power saving.
  ) i_clk_gate (
    .clk_i,
    .en_i,
    .test_en_i ( 1'b0 ),
    .clk_o     ( clk  )
  );

  sync #(
    .STAGES (NrSyncStages)
  ) i_sync (
    .clk_i(clk),
    .rst_ni,
    .serial_i,
    .serial_o ( serial )
  );

  always_ff @(posedge clk, negedge rst_ni) begin
    if (!rst_ni) begin
      serial_q <= 1'b0;
    end else begin
      serial_q <= serial;
    end
  end


endmodule : gpio_input_stage
