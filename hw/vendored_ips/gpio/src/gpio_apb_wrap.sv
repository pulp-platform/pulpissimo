//-----------------------------------------------------------------------------
// Title         : GPIO APB Wrapper
//-----------------------------------------------------------------------------
// File          : gpio_apb_wrap.sv
// Author        : Manuel Eggimann  <meggimann@iis.ee.ethz.ch>
// Created       : 06.05.2021
//-----------------------------------------------------------------------------
// Description :
// This file provides wrappers around the GPIO peripheral with an APB
// interface. The file contains two versions of the module, one structs for the
// APB interface and one using SystemVerilog Interfaces.
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
`include "apb/typedef.svh"
`include "apb/assign.svh"

module gpio_apb_wrap # (
  /// ADDR_WIDTH of the APB interface
  parameter int unsigned  ADDR_WIDTH = 32,
  /// DATA_WIDTH of the APB interface
  parameter int unsigned  DATA_WIDTH = 32,
  /// APB request struct type.
  parameter type apb_req_t = logic,
  /// APB response struct type.
  parameter type apb_rsp_t = logic,
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
  input                      apb_req_t apb_req_i,
  output                     apb_rsp_t apb_rsp_o
);

  // Convert APB to reg_bus
  REG_BUS #(.ADDR_WIDTH(ADDR_WIDTH), .DATA_WIDTH(DATA_WIDTH)) s_reg_bus(.clk_i);
  apb_to_reg i_abp_to_reg (
    .clk_i,
    .rst_ni,
    .penable_i ( apb_req_i.penable ),
    .pwrite_i  ( apb_req_i.pwrite  ),
    .paddr_i   ( apb_req_i.paddr   ),
    .psel_i    ( apb_req_i.psel    ),
    .pwdata_i  ( apb_req_i.pwdata  ),
    .prdata_o  ( apb_rsp_o.prdata  ),
    .pready_o  ( apb_rsp_o.pready  ),
    .pslverr_o ( apb_rsp_o.pslverr ),
    .reg_o     ( s_reg_bus         )
  );

  gpio_intf #(
    .ADDR_WIDTH ( ADDR_WIDTH ),
    .DATA_WIDTH ( DATA_WIDTH )
  ) i_gpio (
    .clk_i,
    .rst_ni,
    .gpio_in,
    .gpio_out,
    .gpio_tx_en_o,
    .gpio_in_sync_o,
    .global_interrupt_o,
    .pin_level_interrupts_o,
    .reg_bus(s_reg_bus)
  );
endmodule // gpio_apb_wrap


module gpio_apb_wrap_intf # (
  /// ADDR_WIDTH of the APB interface
  parameter int unsigned  ADDR_WIDTH = 32,
  /// DATA_WIDTH of the APB interface
  parameter int unsigned  DATA_WIDTH = 32,
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
  APB.Slave                  apb_slave
);

  // Convert SV Interface to structs
  typedef logic [ADDR_WIDTH-1:0] addr_t;
  typedef logic [DATA_WIDTH-1:0] data_t;
  typedef logic [DATA_WIDTH/8-1:0] strb_t; // The APB bus interface only
                                           // supports 8-bit strobe so we don't need to
                                           // check the strobe width of the intput bus.
  `APB_TYPEDEF_REQ_T(apb_req_t, addr_t, data_t, strb_t)
  `APB_TYPEDEF_RESP_T(apb_rsp_t, data_t)

  apb_req_t s_apb_req;
  apb_rsp_t s_apb_rsp;

  `APB_ASSIGN_TO_REQ(s_apb_req, apb_slave)
  `APB_ASSIGN_FROM_RESP(apb_slave, s_apb_rsp)

  gpio_apb_wrap #(
    .ADDR_WIDTH ( ADDR_WIDTH ),
    .DATA_WIDTH ( DATA_WIDTH ),
    .apb_req_t  ( apb_req_t  ),
    .apb_rsp_t  ( apb_rsp_t  )
  ) i_gpio_apb_wrap (
    .clk_i,
    .rst_ni,
    .gpio_in,
    .gpio_out,
    .gpio_tx_en_o,
    .gpio_in_sync_o,
    .global_interrupt_o,
    .pin_level_interrupts_o,
    .apb_req_i ( s_apb_req ),
    .apb_rsp_o ( s_apb_rsp )
  );

endmodule
