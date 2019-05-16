/*
 * xilinx_pll.sv
 * Francesco Conti <fconti@iis.ee.ethz.ch>
 * Antonio Mastrandrea <a.mastrandrea@unibo.it>
 *
 * Copyright (C) 2018 ETH Zurich, University of Bologna
 * All rights reserved.
 */

module xilinx_pll (
  output logic        clk_o,
  input  logic        ref_clk_i,
  output logic        cfg_lock_o,     
  input  logic        cfg_req_i,    
  output logic        cfg_ack_o,  
  input  logic [1:0]  cfg_add_i,
  input  logic [31:0] cfg_data_i,
  output logic [31:0] cfg_r_data_o,
  input  logic        cfg_wrn_i,
  input  logic        rstn_glob_i
);

  always_ff @(posedge ref_clk_i_buf or negedge rstn_glob_i)
  begin
    if(~rstn_glob_i) begin
      cfg_ack_o    <= '0;
      cfg_r_data_o <= '0;
    end
    else if(cfg_req_i) begin
      cfg_ack_o    <= 1'b1;
      cfg_r_data_o <= '0;
    end
  end

    wire ref_clk_i_buf;

    wire clk_2083;
    wire clk01, clk02, clk03, clk04, clk05, clk0fb, lock0;
    wire clk10, clk11, clk12, clk13, clk14, clk15, clk1fb, lock1;
    wire clk_mux01, clk_mux23, clk_mux0123, clk_mux01234;
    logic [3:0] s;
 
    assign ref_clk_i_buf = ref_clk_i;

    PLLE2_BASE #(
      .BANDWIDTH          ( "OPTIMIZED" ),
      .CLKFBOUT_MULT      ( 40           ), // 6*40   
      .CLKFBOUT_PHASE     ( 0.0         ),
      .CLKIN1_PERIOD      ( 16.667      ), // 60 MHz
      .CLKOUT0_DIVIDE     ( 16          ), // 50 MHz
      .CLKOUT1_DIVIDE     ( 16          ), // 50 MHz
      .CLKOUT2_DIVIDE     ( 16          ), // 50 MHz
      .CLKOUT4_DIVIDE     ( 16          ), // 50 MHz
      .CLKOUT5_DIVIDE     ( 1           ),
      .CLKOUT0_DUTY_CYCLE ( 0.5         ),
      .CLKOUT1_DUTY_CYCLE ( 0.5         ),
      .CLKOUT2_DUTY_CYCLE ( 0.5         ),
      .CLKOUT3_DUTY_CYCLE ( 0.5         ),
      .CLKOUT4_DUTY_CYCLE ( 0.5         ),
      .CLKOUT5_DUTY_CYCLE ( 0.5         ),
      .CLKOUT0_PHASE      ( 0.0         ),
      .CLKOUT1_PHASE      ( 0.0         ),
      .CLKOUT2_PHASE      ( 0.0         ),
      .CLKOUT3_PHASE      ( 0.0         ),
      .CLKOUT4_PHASE      ( 0.0         ),
      .CLKOUT5_PHASE      ( 0.0         ),
      .DIVCLK_DIVIDE      ( 3           ), // 6*3
      .REF_JITTER1        ( 0.0         ),
      .STARTUP_WAIT       ( "TRUE"      )
    ) i_pll_1 (
      .CLKOUT0  ( clk10                 ), // 133.31 MHz
      .CLKOUT1  ( clk11                 ), // 66.655 MHz
      .CLKOUT2  ( clk12                 ), // 44.44 MHz
      .CLKOUT3  ( clk13                 ), // 33.3275 MHz
      .CLKOUT4  ( clk14                 ), // 10.25 MHz
      .CLKOUT5  ( clk15                 ),
      .CLKFBOUT ( clk1fb                ),
      .LOCKED   ( lock1                 ),
      .CLKIN1   ( ref_clk_i_buf         ),
      .PWRDWN   ( 1'b0                  ),
      .RST      ( ~rstn_glob_i          ),
      .CLKFBIN  ( clk1fb                )
    );

    

    // for the moment, select clk10
    assign s[0] = 1'b0;
    assign s[1] = 1'b0;
    assign s[2] = 1'b1;
    assign s[3] = 1'b0;

    BUFGMUX_CTRL i_buf_mux01 (
      .O  ( clk_mux01 ),
      .I0 ( clk10     ),
      .I1 ( clk11     ),
      .S  ( s[0]      )
    );

    BUFGMUX_CTRL i_buf_mux23 (
      .O  ( clk_mux23 ),
      .I0 ( clk12     ),
      .I1 ( clk13     ),
      .S  ( s[1]      )
    );

    BUFGMUX_CTRL i_buf_mux0123 (
      .O  ( clk_mux0123 ),
      .I0 ( clk_mux01   ),
      .I1 ( clk_mux23   ),
      .S  ( s[2]      )
    );

    BUFGMUX_CTRL i_buf_mux01234 (
      .O  ( clk_mux01234 ),
      .I0 ( clk_mux0123  ),
      .I1 ( clk14        ),
      .S  ( s[3]         )
    );

    BUFGCE i_bufgce (
      .O  ( clk_o        ), //s=0000 -> clk_o=clk10
      .CE ( lock1        ),
      .I  ( clk_mux01234 )
    );

    assign cfg_lock_o = lock1;

endmodule /* xilinx_pll */

