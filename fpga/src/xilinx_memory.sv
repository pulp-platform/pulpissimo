// Copyright 2018 ETH Zurich and University of Bologna.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

module generic_memory
#(
  parameter ADDR_WIDTH = 12,
  parameter DATA_WIDTH = 32,
  parameter BE_WIDTH   = DATA_WIDTH/8
)
(
  input  logic                  CLK,
  input  logic                  INITN,

  input  logic                  CEN,
  input  logic [ADDR_WIDTH-1:0] A,
  input  logic                  WEN,
  input  logic [DATA_WIDTH-1:0] D,
  input  logic [BE_WIDTH-1:0]   BEN,

  output logic [DATA_WIDTH-1:0] Q
);

  logic [BE_WIDTH-1:0] wea;
  assign wea = ~WEN ? BEN : '0;

  xpm_memory_spram # (
    .MEMORY_SIZE        ( (2**(ADDR_WIDTH-$clog2(DATA_WIDTH/8)))*8 ), //it is in bits
    .MEMORY_PRIMITIVE   ( "block"                              ),
    .MEMORY_INIT_FILE   ( "none"                               ),
    .MEMORY_INIT_PARAM  ( ""                                   ),
    .USE_MEM_INIT       ( 1                                    ),
    .WAKEUP_TIME        ( "disable_sleep"                      ),
    .MESSAGE_CONTROL    ( 0                                    ),
    .WRITE_DATA_WIDTH_A ( DATA_WIDTH                           ),
    .READ_DATA_WIDTH_A  ( DATA_WIDTH                           ),
    .BYTE_WRITE_WIDTH_A ( 8                                    ),
//    .ADDR_WIDTH_A       ( ADDR_WIDTH-$clog2(DATA_WIDTH/8)      ),
    .ADDR_WIDTH_A       ( ADDR_WIDTH                           ),
    .READ_RESET_VALUE_A ( "0"                                  ),
    .ECC_MODE           ( "no_ecc"                             ),
    .AUTO_SLEEP_TIME    ( 0                                    ),
    .READ_LATENCY_A     ( 1                                    ),
    .WRITE_MODE_A       ( "read_first"                         )
  ) i_bram (
    .sleep          ( 1'b0                                 ),
    .clka           ( CLK                                  ),
    .rsta           ( ~INITN                               ),
    .ena            ( ~CEN                                 ),
    .regcea         ( 1'b1                                 ),
    .wea            ( wea                                  ),
//    .addra          ( A[ADDR_WIDTH-1:$clog2(DATA_WIDTH/8)] ),
    .addra          ( A[ADDR_WIDTH-1:0]                    ),
    .dina           ( D                                    ),
    .injectsbiterra ( 1'b0                                 ),
    .injectdbiterra ( 1'b0                                 ),
    .douta          ( Q                                    ),
    .sbiterra       (                                      ),
    .dbiterra       (                                      )
  );

endmodule

