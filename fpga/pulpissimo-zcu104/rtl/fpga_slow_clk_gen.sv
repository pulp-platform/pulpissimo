//-----------------------------------------------------------------------------
// Title         : FPGA slow clk generator for PULPissimo
//-----------------------------------------------------------------------------
// File          : fpga_slow_clk_gen.sv
// Author        : Manuel Eggimann  <meggimann@iis.ee.ethz.ch>
// Created       : 20.05.2019
//-----------------------------------------------------------------------------
// Description : Instantiates Xilinx Clocking Wizard IP to generate the slow_clk
// signal since for certain boards the available clock sources are to fast to
// use directly.
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


module fpga_slow_clk_gen
  (input logic ref_clk_i,
   input logic rst_ni,
   output logic slow_clk_o
   );

  xilinx_slow_clk_mngr i_slow_clk_mngr
    (
     .resetn(rst_ni),
     .clk_in1(ref_clk_i),
     .clk_out1(slow_clk_o)
     );

endmodule : fpga_slow_clk_gen
