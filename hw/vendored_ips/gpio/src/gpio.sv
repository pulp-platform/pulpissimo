//-----------------------------------------------------------------------------
// Title         : GPIO Peripheral
//-----------------------------------------------------------------------------
// File          : gpio.sv
// Author        : Manuel Eggimann  <meggimann@iis.ee.ethz.ch>
// Created       : 06.05.2021
//-----------------------------------------------------------------------------
// Description :
// This Module contains a very simple but clean implementation of a GPIO
// peripheral. The is controlled through a lightweight reg_bus interface. At the
// bottom of this file there is a SV interface wrapper for the module.
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

`define assert_condition(cond, rst_ni) \
assert(^cond !== 1'bx | rst_ni !== 1'b1) \
    else $error("Condition: %s = X in instance %m.", `"cond`")

module gpio #(
  /// Data width of the reg_bus
  parameter int unsigned DATA_WIDTH = 32,
  /// Regbus request struct type.
  parameter type reg_req_t          = logic,
  /// Regbus response struct type.
  parameter type reg_rsp_t          = logic,
  /// The number of GPIOs in this module. This parameter can only be changed if
  /// the corresponding register file is regenerated with the same number of
  /// GPIOs. The module will error out during elaboration if the given parameter
  /// does not match the number of defined GPIOs in the register file.
  localparam int unsigned NrGPIOs    = gpio_reg_pkg::GPIOCount
) (
  /// Primary input clock. The control interface is suposed to be synchronous to
  /// this clock.
  input logic                clk_i,
  /// Asynchronous active-low reset
  input logic                rst_ni,
  /// GPIO input signals from IO Pads (Pad -> SoC) signal.
  input logic [NrGPIOs-1:0]  gpio_in,
  /// GPIO output signals to IO Pads (SoC -> Pad) signal.
  output logic [NrGPIOs-1:0] gpio_out,
  /// GPIO tx enable signals. This signal is supposed to control the output
  /// buffer enable of the corresponding IO Pad. 0 -> RX (input), 1 -> TX (output).
  output logic [NrGPIOs-1:0] gpio_tx_en_o, // 0 -> input, 1 -> output
  /// Synchronized GPIO input signals. This port provides the `gpio_in` signal
  /// synchronized to `clk_i`.
  output logic [NrGPIOs-1:0] gpio_in_sync_o,
  /// Global interrupt line. The interrupt line is asserted for one `clk_i`
  /// whenever an unmasked interrupt on one of the GPIOs arrives.
  output logic               global_interrupt_o,
  output logic [NrGPIOs-1:0] pin_level_interrupts_o,
  /// Control interface request side using register_interface protocol.
  input                      reg_req_t reg_req_i,
  /// Control interface request side using register_interface protocol.
  output                     reg_rsp_t reg_rsp_o
);
  // The version number exposed via the INFO register
  localparam logic [9:0]     HW_VERSION = 2;

  import gpio_reg_pkg::*;

  // Internal Signals
  gpio_reg2hw_t s_reg2hw;
  gpio_hw2reg_t s_hw2reg;

  // Synchronized inputs
  logic [NrGPIOs-1:0]        s_gpio_in_sync;


  // Individual interrupt signals
  logic [NrGPIOs-1:0] s_gpio_rise_edge;
  logic [NrGPIOs-1:0] s_gpio_rise_intrpt_mask;
  logic [NrGPIOs-1:0] s_gpio_fall_edge;
  logic [NrGPIOs-1:0] s_gpio_fall_intrpt_mask;
  // for the level sensitive interrupts we can use the synchronized signal
  // directly, no need for an additional signal
  logic [NrGPIOs-1:0] s_gpio_high_intrpt_mask;
  logic [NrGPIOs-1:0] s_gpio_low_intrpt_mask;

  logic [NrGPIOs-1:0] s_gpio_rise_intrpt;
  logic [NrGPIOs-1:0] s_gpio_fall_intrpt;
  logic [NrGPIOs-1:0] s_gpio_high_intrpt;
  logic [NrGPIOs-1:0] s_gpio_low_intrpt;

  // Aggregated interrupts per GPIO
  logic [NrGPIOs-1:0] interrupts_edges; // Aggregates new interrupts
  logic [NrGPIOs-1:0] interrupts_pending; // Aggregates pending interrupts

  // Instantiate auto-generated register file
  gpio_reg_top #(
    .reg_req_t(reg_req_t),
    .reg_rsp_t(reg_rsp_t)
  ) i_reg_file (
    .clk_i,
    .rst_ni,
    .reg_req_i,
    .reg_rsp_o,
    .reg2hw(s_reg2hw),
    .hw2reg(s_hw2reg),
    .devmode_i(1'b1)
  );

  // Asign value to info register
  assign s_hw2reg.info.version.d = HW_VERSION;
  assign s_hw2reg.info.gpio_cnt.d = NrGPIOs[9:0];

  // Mask interrupts
  assign s_gpio_rise_intrpt = s_gpio_rise_edge & s_gpio_rise_intrpt_mask;
  assign s_gpio_fall_intrpt = s_gpio_fall_edge & s_gpio_fall_intrpt_mask;
  assign s_gpio_high_intrpt = s_gpio_in_sync & s_gpio_high_intrpt_mask;
  assign s_gpio_low_intrpt = ~s_gpio_in_sync & s_gpio_low_intrpt_mask;

  // Generate combined interrupt signal that combines all enabled interrupts for
  // each GPIO
  assign interrupts_edges = s_gpio_rise_intrpt | s_gpio_fall_intrpt | s_gpio_high_intrpt | s_gpio_low_intrpt;

  // Aggregate all pending interrupts. Aggregation of all sticky interrupts.
  assign interrupts_pending = s_reg2hw.intrpt_rise_status | s_reg2hw.intrpt_fall_status | s_reg2hw.intrpt_lvl_high_status | s_reg2hw.intrpt_lvl_low_status;

  // Assign interrupt output signal depending on inerrupt mode
  assign global_interrupt_o = (s_reg2hw.cfg.glbl_intrpt_mode.q)? |interrupts_pending : |interrupts_edges;
  assign pin_level_interrupts_o = (s_reg2hw.cfg.pin_lvl_intrpt_mode.q)? interrupts_pending : interrupts_edges;

  // Assign synchronized gpio inputs to external port
  assign gpio_in_sync_o = s_gpio_in_sync;

  // Instantiate logic for individual gpios in blocks of DATA_WIDTH
  for (genvar gpio_idx = 0; gpio_idx < NrGPIOs; gpio_idx++) begin : gen_gpios
      // Instantiate synchronizer to synchronize input to sampling clock
      gpio_input_stage #(
        .NrSyncStages(2)
      ) i_sync_gpio_input(
        .clk_i,
        .rst_ni,
        .en_i(s_reg2hw.gpio_en[gpio_idx].q && s_reg2hw.gpio_mode[gpio_idx].q == 0),
        .serial_i(gpio_in[gpio_idx]),
        .r_edge_o(s_gpio_rise_edge[gpio_idx]),
        .f_edge_o(s_gpio_fall_edge[gpio_idx]),
        .serial_o(s_gpio_in_sync[gpio_idx])
      );

      // Assign GPIO_IN register
      assign s_hw2reg.gpio_in[gpio_idx].d= s_gpio_in_sync[gpio_idx];

      // Control output with GPIO_OUT register
      assign gpio_out[gpio_idx] = s_reg2hw.gpio_out[gpio_idx].q;
      // Control gpio_tx_en_o depending on GPIO_MODE register value
      always_comb begin
          `assert_condition(s_reg2hw.gpio_mode[gpio_idx], rst_ni);
        case (s_reg2hw.gpio_mode[gpio_idx])
          2'b00: begin //INPUT_ONLY
            gpio_tx_en_o[gpio_idx] = 1'b0;
          end
          2'b01: begin //OUTPUT_ACTIVE
            gpio_tx_en_o[gpio_idx] = 1'b1;
          end
          2'b10: begin // OPEN_DRAIN0
            gpio_tx_en_o[gpio_idx] = s_reg2hw.gpio_out[gpio_idx].q;
          end
          2'b11: begin // OPEN_DRAIN1
            gpio_tx_en_o[gpio_idx] = ~s_reg2hw.gpio_out[gpio_idx].q;
          end
          default: begin
            gpio_tx_en_o[gpio_idx] = 1'b0;
          end
        endcase
      end

      // Wire individual masks
      assign s_gpio_rise_intrpt_mask[gpio_idx] = s_reg2hw.intrpt_rise_en[gpio_idx].q;
      assign s_gpio_fall_intrpt_mask[gpio_idx] = s_reg2hw.intrpt_fall_en[gpio_idx].q;
      assign s_gpio_high_intrpt_mask[gpio_idx] = s_reg2hw.intrpt_lvl_high_en[gpio_idx].q;
      assign s_gpio_low_intrpt_mask[gpio_idx] = s_reg2hw.intrpt_lvl_low_en[gpio_idx].q;

    // GPIO set, clear and toggle logic
    always_comb begin
      unique if (s_reg2hw.gpio_set[gpio_idx].qe && s_reg2hw.gpio_set[gpio_idx].q) begin
        `assert_condition(s_reg2hw.gpio_set[gpio_idx].qe && s_reg2hw.gpio_set[gpio_idx].q, rst_ni);
        s_hw2reg.gpio_out[gpio_idx].d = 1'b1;
        s_hw2reg.gpio_out[gpio_idx].de = 1'b1;
      end else if (s_reg2hw.gpio_clear[gpio_idx].qe && s_reg2hw.gpio_clear[gpio_idx].q) begin
        `assert_condition(s_reg2hw.gpio_clear[gpio_idx].qe && s_reg2hw.gpio_clear[gpio_idx].q, rst_ni);
        s_hw2reg.gpio_out[gpio_idx].d = 1'b0;
        s_hw2reg.gpio_out[gpio_idx].de = 1'b1;
      end else if (s_reg2hw.gpio_toggle[gpio_idx].qe && s_reg2hw.gpio_toggle[gpio_idx].q) begin
        `assert_condition(s_reg2hw.gpio_toggle[gpio_idx].qe && s_reg2hw.gpio_toggle[gpio_idx].q, rst_ni);
        s_hw2reg.gpio_out[gpio_idx].d = ~s_reg2hw.gpio_out[gpio_idx].q;
        s_hw2reg.gpio_out[gpio_idx].de = 1'b1;
      end else begin
        s_hw2reg.gpio_out[gpio_idx].d = s_reg2hw.gpio_out[gpio_idx].q;
        s_hw2reg.gpio_out[gpio_idx].de = 1'b0;
      end
    end

    //Wire interrupt status registers
    always_comb begin
      `assert_condition({s_reg2hw.intrpt_status[gpio_idx].qe && s_reg2hw.intrpt_status[gpio_idx].q}, rst_ni);
      //If we clear the aggregated, clear all individual interrupt status registers for the corresponding block of
      //GPIOs
      if (s_reg2hw.intrpt_status[gpio_idx].qe & (s_reg2hw.intrpt_status[gpio_idx].q == 1)) begin
        s_hw2reg.intrpt_rise_status[gpio_idx].d      = '0;
        s_hw2reg.intrpt_rise_status[gpio_idx].de     = 1'b1;
        s_hw2reg.intrpt_fall_status[gpio_idx].d      = '0;
        s_hw2reg.intrpt_fall_status[gpio_idx].de     = 1'b1;
        s_hw2reg.intrpt_lvl_high_status[gpio_idx].d  = '0;
        s_hw2reg.intrpt_lvl_high_status[gpio_idx].de = 1'b1;
        s_hw2reg.intrpt_lvl_low_status[gpio_idx].d   = '0;
        s_hw2reg.intrpt_lvl_low_status[gpio_idx].de  = 1'b1;
      end else begin
        // Set new bits of the the individual status registers when an interrupt
        // arrives. Only update the registers (de) if there are any new
        // interrupts of the given type.
        s_hw2reg.intrpt_rise_status[gpio_idx].d      = s_gpio_rise_intrpt[gpio_idx] | s_reg2hw.intrpt_rise_status[gpio_idx].q;
        s_hw2reg.intrpt_rise_status[gpio_idx].de     = |s_gpio_rise_intrpt[gpio_idx];
        s_hw2reg.intrpt_fall_status[gpio_idx].d      = s_gpio_fall_intrpt[gpio_idx] | s_reg2hw.intrpt_fall_status[gpio_idx].q;
        s_hw2reg.intrpt_fall_status[gpio_idx].de     = |s_gpio_fall_intrpt[gpio_idx];
        s_hw2reg.intrpt_lvl_high_status[gpio_idx].d  = s_gpio_high_intrpt[gpio_idx]   | s_reg2hw.intrpt_lvl_high_status[gpio_idx].q;
        s_hw2reg.intrpt_lvl_high_status[gpio_idx].de = |s_gpio_high_intrpt[gpio_idx];
        s_hw2reg.intrpt_lvl_low_status[gpio_idx].d   = s_gpio_low_intrpt[gpio_idx]  | s_reg2hw.intrpt_lvl_low_status[gpio_idx].q;
        s_hw2reg.intrpt_lvl_low_status[gpio_idx].de  = |s_gpio_low_intrpt[gpio_idx];
      end
    end // always_comb
    assign s_hw2reg.intrpt_status[gpio_idx].d = interrupts_pending[gpio_idx];
  end
endmodule : gpio

module gpio_intf #(
  /// ADDR_WIDTH of the reg_bus interface
  parameter int unsigned  ADDR_WIDTH = 32,
  /// DATA_WIDTH of the reg_bus interface
  parameter int unsigned  DATA_WIDTH = 32,
  localparam int unsigned NrGPIOs = gpio_reg_pkg::GPIOCount,
  localparam int unsigned STRB_WIDTH = DATA_WIDTH/8
) (
  input logic                clk_i,
  input logic                rst_ni,
  input logic [NrGPIOs-1:0]  gpio_in,
  output logic [NrGPIOs-1:0] gpio_out,
  output logic [NrGPIOs-1:0] gpio_tx_en_o, // 0 -> input, 1 -> output
  output logic [NrGPIOs-1:0] gpio_in_sync_o, // sampled and synchronized GPIO
  // input.
  output logic               global_interrupt_o,
  output logic [NrGPIOs-1:0] pin_level_interrupts_o,
  REG_BUS.in                 reg_bus
);

  // Define structs for reg_bus
  typedef logic [ADDR_WIDTH-1:0] addr_t;
  typedef logic [DATA_WIDTH-1:0] data_t;
  typedef logic [STRB_WIDTH-1:0] strb_t;
  `REG_BUS_TYPEDEF_ALL(reg_bus, addr_t, data_t, strb_t)

  reg_bus_req_t s_reg_req;
  reg_bus_rsp_t s_reg_rsp;

  // Assign SV interface to structs
  `REG_BUS_ASSIGN_TO_REQ(s_reg_req, reg_bus)
  `REG_BUS_ASSIGN_FROM_RSP(reg_bus, s_reg_rsp)

  gpio #(
    .reg_req_t(reg_bus_req_t),
    .reg_rsp_t(reg_bus_rsp_t)
  ) i_gpio (
     .clk_i,
     .rst_ni,
     .gpio_in,
     .gpio_out,
     .gpio_tx_en_o, // 0 -> input, 1 -> output
     .gpio_in_sync_o, // sampled and synchronized GPIO
     .global_interrupt_o,
     .pin_level_interrupts_o,
     .reg_req_i(s_reg_req),
     .reg_rsp_o(s_reg_rsp)
  );

endmodule : gpio_intf
