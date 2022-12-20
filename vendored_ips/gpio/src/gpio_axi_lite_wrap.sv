//-----------------------------------------------------------------------------
// Title         : GPIO AXI Lite Wrapper
//-----------------------------------------------------------------------------
// File          : gpio_axi_lite_wrap.sv
// Author        : Manuel Eggimann  <meggimann@iis.ee.ethz.ch>
// Created       : 06.05.2021
//-----------------------------------------------------------------------------
// Description :
// This file provides a wrapper around the GPIO peripheral with an AXI4-lite
// interface. The file contains two versions of the module, one structs for the
// AXI-lite interface and one using SystemVerilog Interfaces.
//-----------------------------------------------------------------------------
// Copyright (C) 2013-2021 ETH Zurich, University of Bologna
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.
//-----------------------------------------------------------------------------


`include "register_interface/typedef.svh"
`include "register_interface/assign.svh"
`include "axi/typedef.svh"
`include "axi/assign.svh"

module gpio_axi_lite_wrap # (
  /// ADDR_WIDTH of the AXI lite interface
  parameter int unsigned  ADDR_WIDTH = 32,
  /// DATA_WIDTH of the AXI lite interface
  parameter int unsigned  DATA_WIDTH = 32,
  /// Whether the AXI-Lite W channel should be decoupled with a register. This
  /// can help break long paths at the expense of registers.
  parameter bit           DECOUPLE_W = 1,
  /// AXI-Lite request struct type.
  parameter type axi_lite_req_t = logic,
  /// AXI-Lite response struct type.
  parameter type axi_lite_rsp_t = logic,
  localparam int unsigned NrGPIOs = gpio_reg_pkg::GPIOCount,
  localparam int unsigned STRB_WIDTH = DATA_WIDTH/8
)(
  input logic                clk_i,
  input logic                rst_ni,
  input logic [NrGPIOs-1:0]  gpio_in,
  output logic [NrGPIOs-1:0] gpio_out,
  output logic [NrGPIOs-1:0] gpio_tx_en_o, // 0 -> input, 1 -> output
  output logic [NrGPIOs-1:0] gpio_in_sync_o, // sampled and synchronized GPIO
  // input.
  output logic               global_interrupt_o,
  output logic [NrGPIOs-1:0] pin_level_interrupts_o,
  input axi_lite_req_t       axi_lite_req_i,
  output axi_lite_rsp_t      axi_lite_rsp_o
);

  if (STRB_WIDTH != DATA_WIDTH/8)
    $error("Unsupported AXI strobe width (%d) The underlying register bus protocol does not support strobe widths other than 8-bit.", STRB_WIDTH);

  typedef logic [ADDR_WIDTH-1:0] addr_t;
  typedef logic [DATA_WIDTH-1:0] data_t;
  typedef logic [STRB_WIDTH-1:0] strb_t;
  `REG_BUS_TYPEDEF_ALL(reg_bus, addr_t, data_t, strb_t)

  reg_bus_req_t s_reg_req;
  reg_bus_rsp_t s_reg_rsp;

  axi_lite_to_reg #(
    .ADDR_WIDTH(ADDR_WIDTH),
    .DATA_WIDTH(DATA_WIDTH),
    .BUFFER_DEPTH(1),
    .DECOUPLE_W(0),
    .axi_lite_req_t(axi_lite_req_t),
    .axi_lite_rsp_t(axi_lite_rsp_t),
    .reg_req_t(reg_bus_req_t),
    .reg_rsp_t(reg_bus_rsp_t)
  ) i_axi_lite_to_reg (
    .clk_i,
    .rst_ni,
    .axi_lite_req_i,
    .axi_lite_rsp_o,
    .reg_req_o(s_reg_req),
    .reg_rsp_i(s_reg_rsp)
  );


  gpio #(
    .DATA_WIDTH ( DATA_WIDTH ),
    .reg_req_t ( reg_bus_req_t ),
    .reg_rsp_t ( reg_bus_rsp_t )
  ) i_gpio (
    .clk_i,
    .rst_ni,
    .gpio_in,
    .gpio_out,
    .gpio_tx_en_o,
    .gpio_in_sync_o,
    .global_interrupt_o,
    .pin_level_interrupts_o,
    .reg_req_i ( s_reg_req ),
    .reg_rsp_o ( s_reg_rsp )
  );

endmodule

module gpio_axi_lite_wrap_intf # (
  /// ADDR_WIDTH of the AXI lite interface
  parameter int unsigned  ADDR_WIDTH = 32,
  /// DATA_WIDTH of the AXI lite interface
  parameter int unsigned  DATA_WIDTH = 32,
  /// Whether the AXI-Lite W channel should be decoupled with a register. This
  /// can help break long paths at the expense of registers.
  parameter bit           DECOUPLE_W = 1,
  localparam int unsigned NrGPIOs = gpio_reg_pkg::GPIOCount,
  localparam int unsigned STRB_WIDTH = DATA_WIDTH/8
)(
  input logic                clk_i,
  input logic                rst_ni,
  input logic [NrGPIOs-1:0]  gpio_in,
  output logic [NrGPIOs-1:0] gpio_out,
  output logic [NrGPIOs-1:0] gpio_tx_en_o, // 0 -> input, 1 -> output
  output logic [NrGPIOs-1:0] gpio_in_sync_o, // sampled and synchronized GPIO
  // input.
  output logic               global_interrupt_o,
  output logic [NrGPIOs-1:0] pin_level_interrupts_o,
  AXI_LITE.Slave             axi_i
);

  // Convert SV interface to structs
  // Declare axi_lite structs
  typedef logic [ADDR_WIDTH-1:0] addr_t;
  typedef logic [DATA_WIDTH-1:0] data_t;
  typedef logic [STRB_WIDTH-1:0] strb_t;
  `AXI_LITE_TYPEDEF_ALL(axi_lite, addr_t, data_t, strb_t)
  // Declare axi_lit struct signals
  axi_lite_req_t s_axi_lite_req;
  axi_lite_resp_t s_axi_lite_rsp;
  // Connect SV interface to structs
  `AXI_LITE_ASSIGN_TO_REQ(s_axi_lite_req, axi_i)
  `AXI_LITE_ASSIGN_FROM_RESP(axi_i, s_axi_lite_rsp)

  gpio_axi_lite_wrap #(
    .ADDR_WIDTH     ( ADDR_WIDTH      ),
    .DATA_WIDTH     ( DATA_WIDTH      ),
    .DECOUPLE_W     ( DECOUPLE_W      ),
    .axi_lite_req_t ( axi_lite_req_t  ),
    .axi_lite_rsp_t ( axi_lite_resp_t )
  ) i_gpio_axi_lite_wrap (
    .clk_i,
    .rst_ni,
    .gpio_in,
    .gpio_out,
    .gpio_tx_en_o,
    .gpio_in_sync_o,
    .global_interrupt_o,
    .pin_level_interrupts_o,
    .axi_lite_req_i ( s_axi_lite_req ),
    .axi_lite_rsp_o ( s_axi_lite_rsp )
   );

endmodule
