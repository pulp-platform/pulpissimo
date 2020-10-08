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

   input  wire pad_jtag_tck,
   input  wire pad_jtag_tdi,
   output wire pad_jtag_tdo,
   input  wire pad_jtag_tms
 );

  localparam CORE_TYPE = 0; // 0 for RISCY, 1 for IBEX RV32IMC (formerly ZERORISCY), 2 for IBEX RV32EC (formerly MICRORISCY)
  localparam USE_FPU   = 1;
  localparam USE_HWPE  = 0;

  wire ref_clk_int;
  wire tck_int;
  wire rst_n;
  assign rst_n = ~pad_reset;

  // Input clock buffer
  BUFG i_sysclk_bufg (
     .I(ref_clk_i),
     .O(ref_clk_int)
  );

  // TCK clock buffer (dedicated route is false in constraints)
  IBUF i_tck_iobuf (
    .I(pad_jtag_tck),
    .O(tck_int)
  );

  // PULPissimo instance
  pulpissimo #(
    .CORE_TYPE(CORE_TYPE),
    .USE_FPU(USE_FPU),
    .USE_HWPE(USE_HWPE)
  ) i_pulpissimo (
    .pad_spim_sdio0(led4_o),
    .pad_spim_sdio1(led5_o),
    .pad_spim_sdio2(led6_o),
    .pad_spim_sdio3(led7_o),
    .pad_spim_csn0(pad_uart_rts),
    .pad_spim_csn1(led0_o),
    .pad_spim_sck(pad_uart_cts),
    .pad_uart_rx(pad_uart_rx),
    .pad_uart_tx(pad_uart_tx),
    .pad_cam_pclk(led1_o),
    .pad_cam_hsync(led2_o),
    .pad_cam_data0(led3_o),
    .pad_cam_data1(switch0_i),
    .pad_cam_data2(switch1_i),
    .pad_cam_data3(btnu_i),
    .pad_cam_data4(btnr_i),
    .pad_cam_data5(btnd_i),
    .pad_cam_data6(btnl_i),
    .pad_cam_data7(switch2_i),
    .pad_cam_vsync(switch3_i),
    .pad_sdio_clk(pad_i2c1_scl),
    .pad_sdio_cmd(pad_i2c1_sda),
    .pad_sdio_data0(switch4_i),
    .pad_sdio_data1(switch5_i),
    .pad_sdio_data2(switch6_i),
    .pad_sdio_data3(switch7_i),
    .pad_i2c0_sda(pad_i2c0_sda),
    .pad_i2c0_scl(pad_i2c0_scl),
    .pad_i2s0_sck(pad_pmod1_4),
    .pad_i2s0_ws(pad_pmod1_5),
    .pad_i2s0_sdi(pad_pmod1_6),
    .pad_i2s1_sdi(pad_pmod1_7),
    .pad_reset_n(rst_n),
    .pad_jtag_tck(tck_int),
    .pad_jtag_tdi(pad_jtag_tdi),
    .pad_jtag_tdo(pad_jtag_tdo),
    .pad_jtag_tms(pad_jtag_tms),
    .pad_jtag_trst(1'b1),
    .pad_xtal_in(ref_clk_int),
    .pad_bootsel()
  );

endmodule
