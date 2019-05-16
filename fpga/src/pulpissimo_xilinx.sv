// Copyright 2019 ETH Zurich and University of Bologna.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

module pulpissimo_xilinx
#(
  parameter CORE_TYPE   = 0, // 0 for RISCY, 1 for ZERORISCY, 2 for MICRORISCY
  parameter USE_FPU     = 1
  
)
(
//led 
`ifdef PULP_FPGA_DEBUG
    output logic xil_led0,
    output logic xil_led1,
    output logic xil_led2,
    output logic xil_led3,
    input  logic reset_led,
`endif

   inout  wire        xil_uart_rx,
   inout  wire        xil_uart_tx,

   inout  wire        xil_i2c0_sda,
   inout  wire        xil_i2c0_scl,

   input  logic        xil_reset_n,
   inout  logic        xil_bootsel,

   inout  wire        xil_jtag_tck,
   inout  wire        xil_jtag_tdi,
   inout  wire        xil_jtag_tdo,
   inout  wire        xil_jtag_tms,
   inout  wire        xil_jtag_trst,

   input logic clk_p,
   input logic clk_n

  );
   
   logic                  w_clk_ref;
   
   //led
   `ifdef PULP_FPGA_DEBUG
        logic clk_soc_led;
        logic clk_per_led;
        logic clk_soc_per_led;
        
        logic xil_led0_int;
        logic xil_led1_int;
        logic xil_led2_int;
        logic xil_led3_int;
    `endif

   pulpissimo #(
      .CORE_TYPE ( CORE_TYPE ),
      .USE_FPU   ( USE_FPU )
   )
   pulpissimo_i (
//led 
`ifdef PULP_FPGA_DEBUG
    .clk_soc_led(clk_soc_led),
    .clk_per_led(clk_per_led),
    .clk_soc_per_led(clk_soc_per_led),
`endif
      .pad_uart_rx        ( xil_uart_tx          ),
      .pad_uart_tx        ( xil_uart_rx          ),

      .pad_i2c0_sda       ( xil_i2c0_sda         ),
      .pad_i2c0_scl       ( xil_i2c0_scl         ),


      .pad_reset_n        ( xil_reset_n            ),
      .pad_bootsel        ( xil_bootsel          ),

      .pad_jtag_tck       ( xil_jtag_tck         ),
      .pad_jtag_tdi       ( xil_jtag_tdi         ),
      .pad_jtag_tdo       ( xil_jtag_tdo         ),
      .pad_jtag_tms       ( xil_jtag_tms         ),
      .pad_jtag_trst      ( xil_jtag_trst        ),

      .pad_xtal_in        ( w_clk_ref          )
   );


//clock
IBUFDS testbuf
(
    .O(w_clk_ref),
    .I(clk_p),
    .IB(clk_n)
);



//led:
`ifdef PULP_FPGA_DEBUG
count_clk
    #(
        .REF_V(45000000)
     )
     cont1
    (
        .clk(clk_soc_led),
        .reset(reset_led),
        .led(xil_led0_int)
    );
    
count_clk
    #(
        .REF_V(45000000)
     )
     cont2
    (
        .clk(clk_per_led),
        .reset(reset_led),
        .led(xil_led1_int)
    );


count_clk
    #(
        .REF_V(100000000)
     )
     cont3
    (
        .clk(w_clk_ref),
        .reset(reset_led),
        .led(xil_led2_int)
    );

count_clk
    #(
        .REF_V(100000000)
     )
     cont4
    (
        .clk(clk_soc_per_led),
        .reset(reset_led),
        .led(xil_led3_int)
    );
    
assign xil_led0 = xil_led0_int;
assign xil_led1 = xil_led1_int;
assign xil_led2 = xil_led2_int;
assign xil_led3 = xil_led3_int;
`endif

endmodule
