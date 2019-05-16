// Copyright 2019 ETH Zurich and University of Bologna.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.


module xilinx_bram_mem #(
    parameter MEM_SIZE_KB = 256*2   //if addr is 16 bits: MEM_SIZE_KB=4*2^(16)/1024
    )
    (
    input clock,
    input we,
    input [($clog2(MEM_SIZE_KB*1024/4)-1):0] addr,//[15:0] addr,
    input [31:0] data_in,
    output [31:0] data_out
    );

logic    [31:0] ram [((MEM_SIZE_KB*1024/4)-1):0];   //example: (16kW*4)*4B=256KB --> 64 bram
logic    [($clog2(MEM_SIZE_KB*1024/4)-1):0] read_a;
logic    [31:0] data_out_int; 
 
  always @(posedge clock) begin   
    if (we)   
      ram[addr] <= data_in;   
    read_a <= addr;   
  end   
  //assign data_out = ram[read_a];  
  always @(posedge clock) begin  
    data_out_int <= ram[read_a];
  end
  
  assign data_out = data_out_int;

endmodule
