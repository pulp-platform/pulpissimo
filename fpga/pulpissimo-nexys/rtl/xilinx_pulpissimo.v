//-----------------------------------------------------------------------------
// Title         : PULPissimo Verilog Wrapper
//-----------------------------------------------------------------------------
// File          : xilinx_pulpissimo.v
// Author        : Manuel Eggimann  <meggimann@iis.ee.ethz.ch>
// Created       : 21.05.2019
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

module xilinx_pulpissimo
  (
   input wire  sys_clk,

   inout wire  pad_spim_sdio0,
   inout wire  pad_spim_sdio1,
   inout wire  pad_spim_sdio2,
   inout wire  pad_spim_sdio3,
   inout wire  pad_spim_csn0,
   inout wire  pad_spim_sck,
   
   inout  wire pad_uart_rx,  //Mapped to uart_rx
   inout  wire pad_uart_tx,  //Mapped to uart_tx
   //inout  wire pad_uart_cts,  //Not mapped, optional
   //inout  wire pad_uart_rts,  //Not mapped, optional

   inout wire  led0_o, //Mapped to spim_csn1
   inout wire  led1_o, //Mapped to cam_pclk
   inout wire  led2_o, //Mapped to cam_hsync
   inout wire  led3_o, //Mapped to cam_data0

   inout wire  switch0_i, //Mapped to cam_data1
   inout wire  switch1_i, //Mapped to cam_data2

   inout wire  btnc_i, //Mapped to cam_data3
   inout wire  btnd_i, //Mapped to cam_data4
   inout wire  btnl_i, //Mapped to cam_data5
   inout wire  btnr_i, //Mapped to cam_data6
   inout wire  btnu_i, //Mapped to cam_data7


   inout wire  sdio_reset_o, //Reset signal for SD card need to be driven low to
                             //power the onboard sd-card. Mapped to cam_vsync.
   inout wire  pad_sdio_clk,
   inout wire  pad_sdio_cmd,
   inout wire  pad_sdio_data0,
   inout wire  pad_sdio_data1,
   inout wire  pad_sdio_data2,
   inout wire  pad_sdio_data3,

	 inout wire	 pad_i2c0_sda, 
   inout wire  pad_i2c0_scl, 

   inout wire  pad_i2s0_sck,
   inout wire  pad_i2s0_ws,
   inout wire  pad_i2s0_sdi,
   inout wire  pad_i2s1_sdi,

   input wire  pad_reset_n,
   inout wire  pad_bootsel,

   input wire  pad_jtag_tck,
   input wire  pad_jtag_tdi,
   output wire pad_jtag_tdo,
   input wire  pad_jtag_tms
   //input wire  pad_jtag_trst
 );

  localparam CORE_TYPE = 0; // 0 for RISCY, 1 for IBEX RV32IMC (formerly ZERORISCY), 2 for IBEX RV32EC (formerly MICRORISCY)
  localparam USE_FPU   = 0;
  localparam USE_HWPE  = 0;

  wire        ref_clk;
  wire        tck_int;
  //wire        pad_spim_sck;

  // Input clock buffer
  IBUFG
    #(
      .IOSTANDARD("LVCMOS33"),
      .IBUF_LOW_PWR("FALSE"))
  i_sysclk_iobuf
    (
     .I(sys_clk),
     .O(ref_clk)
     );

	//JTAG TCK clock buffer (dedicated route is false in constraints)
	IBUF i_tck_iobuf (
		  .I(pad_jtag_tck),
		  .O(tck_int)
		);

  // The SPI-Flash SCK Pin P8 is a configuration pin
  // Therefore we must use a primitive to access it
  // Thes SPI flash is currently not in use as an extended modification of the pad_frame is nessecary
  // (IOBUF of the Pads can only drive signal connected to an I/O pin and not a signal to another primitive).
  
  //wire  [3:0] su_nc;  // Startup primitive output, no connect
  // STARTUPE2 #(
  //     .PROG_USR("FALSE"),  // Activate program event security feature. Requires encrypted bitstreams.
  //     .SIM_CCLK_FREQ(0.0)  // Set the Configuration Clock Frequency(ns) for simulation.
  //  )
  //  STARTUPE2_inst (
  //     .CFGCLK(su_nc[0]),       // 1-bit output: Configuration main clock output
  //     .CFGMCLK(su_nc[1]),     // 1-bit output: Configuration internal oscillator clock output
  //     .EOS(su_nc[2]),             // 1-bit output: Active high output signal indicating the End Of Startup.
  //     .PREQ(su_nc[3]),           // 1-bit output: PROGRAM request to fabric output
  //     .CLK(1'b0),             // 1-bit input: User start-up clock input
  //     .GSR(1'b0),             // 1-bit input: Global Set/Reset input (GSR cannot be used for the port name)
  //     .GTS(1'b0),             // 1-bit input: Global 3-state input (GTS cannot be used for the port name)
  //     .KEYCLEARB(1'b0), // 1-bit input: Clear AES Decrypter Key input from Battery-Backed RAM (BBRAM)
  //     .PACK(1'b0),           // 1-bit input: PROGRAM acknowledge input
  //     .USRCCLKO(pad_spim_sck),   // 1-bit input: User CCLK input -> the access to SPI SCK
  //     .USRCCLKTS(1'b0), // 1-bit input: User CCLK 3-state enable input
  //     .USRDONEO(1'b1),   // 1-bit input: User DONE pin output control
  //     .USRDONETS(1'b1)  // 1-bit input: User DONE 3-state enable outpu

  //  );

  pulpissimo
    #(.CORE_TYPE(CORE_TYPE),
      .USE_FPU(USE_FPU),
      .USE_HWPE(USE_HWPE)
      ) i_pulpissimo
      (
       .pad_spim_sdio0(pad_spim_sdio0),
       .pad_spim_sdio1(pad_spim_sdio1),
       .pad_spim_sdio2(pad_spim_sdio2),
       .pad_spim_sdio3(pad_spim_sdio3),
       .pad_spim_csn0(pad_spim_csn0),
       .pad_spim_csn1(led0_o),
       .pad_spim_sck(pad_spim_sck),
       .pad_uart_rx(pad_uart_rx),
       .pad_uart_tx(pad_uart_tx),
       .pad_cam_pclk(led1_o),
       .pad_cam_hsync(led2_o),
       .pad_cam_data0(led3_o),
       .pad_cam_data1(switch0_i),
       .pad_cam_data2(switch1_i),
       .pad_cam_data3(btnc_i),
       .pad_cam_data4(btnd_i),
       .pad_cam_data5(btnl_i),
       .pad_cam_data6(btnr_i),
       .pad_cam_data7(btnu_i),
       .pad_cam_vsync(sdio_reset_o),
       .pad_sdio_clk(pad_sdio_clk),
       .pad_sdio_cmd(pad_sdio_cmd),
       .pad_sdio_data0(pad_sdio_data0),
       .pad_sdio_data1(pad_sdio_data1),
       .pad_sdio_data2(pad_sdio_data2),
       .pad_sdio_data3(pad_sdio_data3),
			 .pad_i2c0_sda(pad_i2c0_sda),
			 .pad_i2c0_scl(pad_i2c0_scl),
			 .pad_i2s0_sck(pad_i2s0_sck),
			 .pad_i2s0_ws(pad_i2s0_ws),
			 .pad_i2s0_sdi(pad_i2s0_sdi),
			 .pad_i2s1_sdi(pad_i2s1_sdi),
       .pad_reset_n(pad_reset_n),
       .pad_jtag_tck(tck_int),
       .pad_jtag_tdi(pad_jtag_tdi),
       .pad_jtag_tdo(pad_jtag_tdo),
       .pad_jtag_tms(pad_jtag_tms),
       //.pad_jtag_trst(pad_jtag_trst),
			 .pad_jtag_trst(1'b1),
       .pad_xtal_in(ref_clk),
       .pad_bootsel()
       );

endmodule
