//-----------------------------------------------------------------------------
// Title   : PULPissimo Top
// -----------------------------------------------------------------------------
// File    : pulpissimo.sv
// Author  : Manuel Eggimann <meggimann@iis.ee.ethz.ch>
// Created : 19.04.2022
// -----------------------------------------------------------------------------
// Description :
//
// This is the default toplevel of pulpissimo used as the basis for ASIC
// implementations and RTL simulation. It instantiates the following clock
// generation and pad multiplexing IP as well as the `soc_domain` (which wraps
// almost the entire logic of pulpissimo from the external pulp_soc repository).
// The `pulp_soc` repository is shared between the single core variant
// PULPissimo and the multi-core variant pulp-open.
//
//-----------------------------------------------------------------------------
// Copyright (C) 2022 ETH Zurich, University of Bologna Copyright and related
// rights are licensed under the Solderpad Hardware License, Version 0.51 (the
// "License"); you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law or
// agreed to in writing, software, hardware and materials distributed under this
// License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS
// OF ANY KIND, either express or implied. See the License for the specific
// language governing permissions and limitations under the License.
// SPDX-License-Identifier: SHL-0.51
// -----------------------------------------------------------------------------

module pulpissimo #(
  /// 0 for CV32E40P with XPULP Extensions, 1 for IBEX RV32IMC (formerly ZERORISCY),
  /// 2 for IBEX RV32EC (formerly MICRORISCY)
  parameter  int unsigned CORE_TYPE = 0,
  /// Enable XPULP extensions on CV32E40P. Has no effect if an IBEX core variant is use.
  parameter  bit          USE_XPULP = 1,
  /// Mutually exclusive with the use of IBEX. I.e. if an IBEX core variant is used, this parameter
  /// is ignored.
  parameter  bit          USE_FPU = 1,
  /// Standard RISC-V extension: Reuses the integer regfile for FPU usage instead of requiring a
  /// dedicated FPU regfile. Requires correct compiler settings for software to work!
  parameter  bit          USE_ZFINX = 1,
  parameter  bit          USE_HWPE = 0,
  /// Enable the virtual stdout interface for communication with simulated testbenches. This
  /// parameter must be disabled during any form of physical implementation.
  parameter  bit          SIM_STDOUT = 0,
  /// The number of GPIO pads in the system. Check the README on how to modify the pad count
  localparam int unsigned IO_PAD_COUNT = gpio_reg_pkg::GPIOCount
)(
  // Some platforms (e.g. Verilator) require to feed the clock externally. With
  // the EXTERNAL_CLOCK define we remove all internall clock generation logic.
`ifdef EXTERNAL_CLOCK
  input logic              ext_slow_clk_i,
  input logic              ext_soc_clk_i,
  input logic              ext_per_clk_i,
`else
   // Reference clock for clock internal clock generation
  inout wire               pad_ref_clk,
`endif
  // Active-low Asynchronous hard-reset
  inout wire               pad_reset_n,
  // Clock Bypass enable. If asserted (active-high) peripheral and soc clock
  // domain will be driven directly by pad_refclk_in (or verilator_slow_clk_i if
  // in built for VERILATOR).
  inout wire               pad_clk_byp_en,
  // Boot mode selection. Check bootcode repository for mapping of bootsel
  // values to actual boot mode.
  inout wire               pad_bootsel0,
  inout wire               pad_bootsel1,
  // JTAG in-system debug interface
  inout wire               pad_jtag_tck,
  inout wire               pad_jtag_tdi,
  inout wire               pad_jtag_tdo,
  inout wire               pad_jtag_tms,
  inout wire               pad_jtag_trstn,
  // HyperFlash/HyperRAM Pads
  inout wire [1:0]         pad_hyper_csn,
  inout wire               pad_hyper_reset_n,
  inout wire               pad_hyper_ck,
  inout wire               pad_hyper_ckn,
  inout wire [7:0]         pad_hyper_dq,
  inout wire               pad_hyper_rwds,
  // general purpose pads, since PULPissimo v8.0 any peripheral including
  // GPIO) can be mapped to any pad any-to-any muxing. Check the latest
  // README.md on description and how to modify the pad count)
  inout wire [IO_PAD_COUNT-1:0] pad_io
);
`include "soc_mem_map.svh"
`include "apb/assign.svh"
`include "register_interface/typedef.svh"
`include "register_interface/assign.svh"

  ////////////////////
  // Wiring Signals //
  ////////////////////
  // Clock, Bootmode & Reset Signals
  logic [1:0] s_bootsel;
  logic s_ref_clk;
  // Clock bypass control signals
  logic s_pad_global_clk_byp_en; // Controlled by dedicated IO Pad
  logic s_jtag_global_clk_byp_en; // Controlled by the legacy JTAG Tap in the
                                  // soc_domain

  logic s_global_rst_n;
  logic s_soc_clk_en;
  logic s_soc_clk_byp_en;
  logic s_soc_clk;
  logic s_soc_rstn_synced;
  logic s_per_clk_en;
  logic s_per_clk_byp_en;
  logic s_per_clk;
  logic s_per_rstn_synced;
  logic s_slow_clk_en;
  logic s_slow_clk_byp_en;
  logic s_slow_clk;
  logic s_slow_clk_rstn_synced;

   // DFT Signals

  // These signals remain unsued. We just add them for convenience if someone wants
  // to make use of it later on.
  logic s_dft_test_en;  // Connects to test_en pin of all IPs that expose it.
                        // This mostly bypasses
  assign s_dft_test_en = 1'b0; // This signal connects to all the test_en /
                               // test_mode_i pins in the system. Many of these
                               // do not actually do anything and are only ther
                               // for legacy reason or in order to connect to
                               // these signals in the DFT setup during
                               // synthesis. You should check every usage if you
                               // implement any DFT strategy!
  assign s_dft_cg_en = 1'b0;  // Same as dft_test_en but connects to all
                              // dft_cg_en signals. This signal is mostly used
                              // to force a hierarchical clock gate to enable (active-high)
                              // the output clock in order to enable scan
                              // testing.

  // JTAG Signals
  logic s_jtag_tck;
  logic s_jtag_trst_n;
  logic s_jtag_tms;
  logic s_jtag_tdi;
  logic s_jtag_tdo;

  // Timer Channels
  logic [3:0] s_timer_ch0;
  logic [3:0] s_timer_ch1;
  logic [3:0] s_timer_ch2;
  logic [3:0] s_timer_ch3;

  // GPIO
  logic [IO_PAD_COUNT-1:0] s_gpio_out;
  logic [IO_PAD_COUNT-1:0] s_gpio_tx_en;
  logic [IO_PAD_COUNT-1:0] s_gpio_in;

  // UART
  uart_pkg::uart_to_pad_t [udma_cfg_pkg::N_UART-1:0] s_uart_to_pad;
  uart_pkg::pad_to_uart_t [udma_cfg_pkg::N_UART-1:0] s_pad_to_uart;
  // I2C
  i2c_pkg::i2c_to_pad_t [udma_cfg_pkg::N_I2C-1:0] s_i2c_to_pad;
  i2c_pkg::pad_to_i2c_t [udma_cfg_pkg::N_I2C-1:0] s_pad_to_i2c;
  // SDIO
  sdio_pkg::sdio_to_pad_t [udma_cfg_pkg::N_SDIO-1:0] s_sdio_to_pad;
  sdio_pkg::pad_to_sdio_t [udma_cfg_pkg::N_SDIO-1:0] s_pad_to_sdio;
  // I2S
  i2s_pkg::i2s_to_pad_t [udma_cfg_pkg::N_I2S-1:0] s_i2s_to_pad;
  i2s_pkg::pad_to_i2s_t [udma_cfg_pkg::N_I2S-1:0] s_pad_to_i2s;
  // QSPI
  qspi_pkg::qspi_to_pad_t [udma_cfg_pkg::N_QSPIM-1:0] s_qspi_to_pad;
  qspi_pkg::pad_to_qspi_t [udma_cfg_pkg::N_QSPIM-1:0] s_pad_to_qspi;
  // CPI
  cpi_pkg::pad_to_cpi_t [udma_cfg_pkg::N_CPI-1:0] s_pad_to_cpi;
  // HYPER
  hyper_pkg::hyper_to_pad_t [udma_cfg_pkg::N_HYPER-1:0] s_hyper_to_pad;
  hyper_pkg::pad_to_hyper_t [udma_cfg_pkg::N_HYPER-1:0] s_pad_to_hyper;

  // Config. Interfaces
  APB #(.ADDR_WIDTH(32), .DATA_WIDTH(32)) s_apb_chip_ctrl_bus();
  APB #(.ADDR_WIDTH(6), .DATA_WIDTH(32)) s_apb_fll_ctrl_bus();
  APB #(.ADDR_WIDTH(32), .DATA_WIDTH(32)) s_apb_pads_ctrl_bus();

  ////////////////////////////
  // Chip Control Registers //
  ////////////////////////////
  // TODO Actually add some register file here to control high level aspects of
  // the SoC
  assign s_soc_clk_en = 1'b1;
  assign s_soc_clk_byp_en =1'b0;
  assign s_per_clk_en = 1'b1;
  assign s_per_clk_byp_en =1'b0;
  assign s_slow_clk_en = 1'b1;
  assign s_slow_clk_byp_en =1'b0;

  //////////////////////////////
  // Clock & Reset Generation //
  //////////////////////////////
`ifndef EXTERNAL_CLOCK
  clock_gen #(
    .APB_ADDR_WIDTH(6)
  ) i_clock_gen(
    .ref_clk_i         ( s_ref_clk                                                              ),
    .rst_ni            ( s_global_rst_n                                                         ),
    .dft_test_en_i     ( s_dft_test_en                                                          ),
    .cfg_clk_i         ( s_soc_clk                                                              ), // Interface is synchronous to SoC clock
    .cfg_bus_slave     ( s_apb_fll_ctrl_bus                                                     ),
    .slow_clk_en_i     ( s_slow_clk_en                                                          ),
    .slow_clk_byp_en_i ( s_slow_clk_byp_en | s_pad_global_clk_byp_en | s_jtag_global_clk_byp_en ),
    .slow_clk_o        ( s_slow_clk                                                             ),
    .soc_clk_en_i      ( s_soc_clk_en                                                           ),
    .soc_clk_byp_en_i  ( s_soc_clk_byp_en | s_pad_global_clk_byp_en | s_jtag_global_clk_byp_en  ),
    .soc_clk_o         ( s_soc_clk                                                              ),
    .per_clk_en_i      ( s_per_clk_en                                                           ),
    .per_clk_byp_en_i  ( s_per_clk_byp_en | s_pad_global_clk_byp_en | s_jtag_global_clk_byp_en  ),
    .per_clk_o         ( s_per_clk                                                              )
  );
`else
  assign s_soc_clk = ext_soc_clk_i;
  assign s_per_clk = ext_per_clk_i;
  assign s_slow_clk = ext_slow_clk_i;
`endif // !`ifndef EXTERNAL_CLOCK

  /////////////////////////
  // Reset Synchronizers //
  /////////////////////////
  //////////////////////////////////////////////////////////////////////////////
  // TODO Replace this with the digital power management unit to sequence the //
  // reset signal assertion..                                                 //
  //////////////////////////////////////////////////////////////////////////////

  // We use the same reset for all clock domains. This means we do not have to
  // care about reset_domain crossings. Do not just use seperately controlled
  // resets without thinking the reset strategy, its interaction with CDC IPs
  // and reset domain crossing through. You will introduce bugs!!!


  rstgen i_rstgen_slow_clk (
    .clk_i       ( s_slow_clk             ),
    .rst_ni      ( s_global_rst_n         ),
    .test_mode_i ( s_dft_test_en          ),
    .rst_no      ( s_slow_clk_rstn_synced ), // This reset is only needed for IPs
    .init_no     (                        ) // Unused
  );

  rstgen i_rstgen_soc_clk (
    .clk_i       ( s_soc_clk         ),
    .rst_ni      ( s_global_rst_n    ),
    .test_mode_i ( s_dft_test_en     ),
    .rst_no      ( s_soc_rstn_synced ), // This reset is only needed for IPs
    .init_no     (                   ) // Unused
  );

  rstgen i_rstgen_per_clk (
    .clk_i       ( s_per_clk         ),
    .rst_ni      ( s_global_rst_n    ),
    .test_mode_i ( s_dft_test_en     ),
    .rst_no      ( s_per_rstn_synced ), // This reset is only needed for IPs
    .init_no     (                   ) // Unused
  );


  ///////////////////////////////
  // APB Chip Control Demuxing //
  ///////////////////////////////

  // Demultiplex the APB bus to 2 regions
  // - Clock Control
  // - Pad Multiplexer Control

  typedef logic [31:0] addr_t;
  typedef logic [31:0] data_t;

  typedef struct packed {
    int unsigned idx;
    addr_t start_addr;
    addr_t end_addr;
  } addr_rule_t;

  localparam int unsigned N_CHIP_CTRL_DEMUX_SLAVES = 2;
  localparam int unsigned APB_DEMUX_SELECT_WIDTH = $clog2(N_CHIP_CTRL_DEMUX_SLAVES);
  localparam addr_rule_t[N_CHIP_CTRL_DEMUX_SLAVES-1:0] APB_DEMUX_ADDR_RULES = '{
       '{ idx: 1, start_addr: `SOC_MEM_MAP_CHIP_CTRL_FLL_START_ADDR, end_addr: `SOC_MEM_MAP_CHIP_CTRL_FLL_END_ADDR},
       '{ idx: 2, start_addr: `SOC_MEM_MAP_CHIP_CTRL_PAD_CFG_START_ADDR, end_addr: `SOC_MEM_MAP_CHIP_CTRL_PAD_CFG_END_ADDR}
  };

  logic [N_CHIP_CTRL_DEMUX_SLAVES-1:0] s_apb_demux_sel;
  APB #(.ADDR_WIDTH(32), .DATA_WIDTH(32)) s_apb_demuxed[N_CHIP_CTRL_DEMUX_SLAVES:0](); // +1 for error responses

  addr_decode #(
    .NoIndices ( N_CHIP_CTRL_DEMUX_SLAVES+1 ), // + 1 for error slave
    .NoRules   ( N_CHIP_CTRL_DEMUX_SLAVES   ),
    .addr_t    ( addr_t                     ),
    .rule_t    ( addr_rule_t                )
  ) i_apb_demux_addr_decode (
    .addr_i           ( s_apb_chip_ctrl_bus.paddr ),
    .addr_map_i       ( APB_DEMUX_ADDR_RULES      ),
    .idx_o            ( s_apb_demux_sel           ),
    .dec_valid_o      (                           ), // Ignored
    .dec_error_o      (                           ), // Ignored, we use a default error slave
    .en_default_idx_i ( 1'b1                      ),
    .default_idx_i    ( '0                        )
  );

  apb_demux_intf #(
    .APB_ADDR_WIDTH ( 32                         ),
    .APB_DATA_WIDTH ( 32                         ),
    .NoMstPorts     ( N_CHIP_CTRL_DEMUX_SLAVES+1 ) // +1 for the error slave
  ) i_demux (
    .slv      ( s_apb_chip_ctrl_bus ),
    .mst      ( s_apb_demuxed       ),
    .select_i ( s_apb_demux_sel     )
  );

  apb_err_slv_intf #(
    .APB_ADDR_WIDTH(32),
    .APB_DATA_WIDTH(32)
  ) i_err_slv (
    .slv(s_apb_demuxed[0])
  );

  `APB_ASSIGN(s_apb_fll_ctrl_bus, s_apb_demuxed[1])
  `APB_ASSIGN(s_apb_pads_ctrl_bus, s_apb_demuxed[2])

  /////////////////////
  // Pad Multiplexer //
  /////////////////////
  padframe_adapter i_padframe(
    // Config Interface
    .soc_clk_i        ( s_soc_clk                  ),
    .soc_rstn_synced_i( s_soc_rstn_synced          ),
    .apb_cfg_slave    ( s_apb_pads_ctrl_bus        ),
    //IO Pads
    .pad_ref_clk,
    .pad_clk_byp_en,
    .pad_reset_n,
    .pad_bootsel0,
    .pad_bootsel1,
    .pad_jtag_tck,
    .pad_jtag_trstn,
    .pad_jtag_tms,
    .pad_jtag_tdi,
    .pad_jtag_tdo,
    .pad_hyper_csn,
    .pad_hyper_reset_n,
    .pad_hyper_ck,
    .pad_hyper_ckn,
    .pad_hyper_dq,
    .pad_hyper_rwds,
    .pad_io,
    // SoC IO Signals
    .ref_clk_o        ( s_ref_clk               ),
    .global_rst_no    ( s_global_rst_n          ),
    .global_clk_byp_o ( s_pad_global_clk_byp_en ),
    .bootsel_o        ( s_bootsel               ),
    // JTAG
    .jtag_tck_o       ( s_jtag_tck              ),
    .jtag_trst_no     ( s_jtag_trst_n           ),
    .jtag_tms_o       ( s_jtag_tms              ),
    .jtag_tdi_o       ( s_jtag_tdi              ),
    .jtag_tdo_i       ( s_jtag_tdo              ),
    // Timers
    .timer_ch0_i      ( s_timer_ch0             ),
    .timer_ch1_i      ( s_timer_ch1             ),
    .timer_ch2_i      ( s_timer_ch2             ),
    .timer_ch3_i      ( s_timer_ch3             ),
    // GPIOs
    .gpio_o           ( s_gpio_in               ),
    .gpio_i           ( s_gpio_out              ),
    .gpio_tx_en_i     ( s_gpio_tx_en            ),
    // UART
    .uart_to_pad_i    ( s_uart_to_pad           ),
    .pad_to_uart_o    ( s_pad_to_uart           ),
    // I2C
    .i2c_to_pad_i     ( s_i2c_to_pad            ),
    .pad_to_i2c_o     ( s_pad_to_i2c            ),
    // SDIO
    .sdio_to_pad_i    ( s_sdio_to_pad           ),
    .pad_to_sdio_o    ( s_pad_to_sdio           ),
    // I2S
    .i2s_to_pad_i     ( s_i2s_to_pad            ),
    .pad_to_i2s_o     ( s_pad_to_i2s            ),
    // QSPI Master
    .qspi_to_pad_i    ( s_qspi_to_pad           ),
    .pad_to_qspi_o    ( s_pad_to_qspi           ),
    // CPI
    .pad_to_cpi_o     ( s_pad_to_cpi            ),
    // Hyperflash/Hyper RAM
    .hyper_to_pad_i   ( s_hyper_to_pad          ),
    .pad_to_hyper_o   ( s_pad_to_hyper          )
  );


  /////////////////
  // SoC Wrapper //
  /////////////////
  soc_domain #(
    .CORE_TYPE  ( CORE_TYPE  ),
    .USE_XPULP  ( USE_XPULP  ),
    .USE_FPU    ( USE_FPU    ),
    .USE_ZFINX  ( USE_ZFINX  ),
    .USE_HWPE   ( USE_HWPE   ),
    .SIM_STDOUT ( SIM_STDOUT )
  ) i_soc_domain (
    // Clock and reset signals
    .slow_clk_i             ( s_slow_clk             ),
    .slow_clk_rstn_synced_i ( s_slow_clk_rstn_synced ),
    .soc_clk_i              ( s_soc_clk              ),
    .soc_rstn_synced_i      ( s_soc_rstn_synced      ),
    .per_clk_i              ( s_per_clk              ),
    .per_rstn_synced_i      ( s_per_rstn_synced      ),

    // DFT signals (not used but just connected)
    .dft_test_mode_i ( s_dft_test_en ),
    .dft_cg_enable_i ( s_dft_cg_en   ),

    // Boot Mode selection (check bootcode repo for documentation what bootmodes
    // are available and how they are mapped)
    .bootsel_i ( s_bootsel ),

    // Timer PWM Output signals
    .timer_ch0_o ( s_timer_ch0 ),
    .timer_ch1_o ( s_timer_ch1 ),
    .timer_ch2_o ( s_timer_ch2 ),
    .timer_ch3_o ( s_timer_ch3 ),

    // GPIO
    .gpio_i       ( s_gpio_in    ),
    .gpio_o       ( s_gpio_out   ),
    .gpio_tx_en_o ( s_gpio_tx_en ),

    // UART
    .uart_to_pad_o ( s_uart_to_pad ),
    .pad_to_uart_i ( s_pad_to_uart ),

    // I2C
    .i2c_to_pad_o ( s_i2c_to_pad ),
    .pad_to_i2c_i ( s_pad_to_i2c ),

    // SDIO
    .sdio_to_pad_o ( s_sdio_to_pad ),
    .pad_to_sdio_i ( s_pad_to_sdio ),

    // I2S
    .i2s_to_pad_o ( s_i2s_to_pad ),
    .pad_to_i2s_i ( s_pad_to_i2s ),

    // QSPI Master
    .qspi_to_pad_o ( s_qspi_to_pad ),
    .pad_to_qspi_i ( s_pad_to_qspi ),

    // CPI
    .pad_to_cpi_i ( s_pad_to_cpi ),

    // HyperFlash/HyperRAM
    .hyper_to_pad_o ( s_hyper_to_pad ),
    .pad_to_hyper_i ( s_pad_to_hyper ),

    // fll bypass bit in legacy pulp JTAG TAP. Can be used to control FLL
    // bypassing via JTAG instead of dedicated pad
    .jtag_tap_bypass_fll_clk_o ( s_jtag_global_clk_byp_en ),

    // APB port to control various aspects of PULPissimo which are platform
    // dependent (e.g. pad multiplexer, clock generation etc.). Check
    // soc_mem_map.svh for the global address space region which is mapped to
    // this port.
    .apb_chip_ctrl_master ( s_apb_chip_ctrl_bus ),

    // JTAG Signals (connets to risc-v debug unit legacy pulp debug TAP)
    .jtag_tck_i   ( s_jtag_tck    ),
    .jtag_trst_ni ( s_jtag_trst_n ),
    .jtag_tms_i   ( s_jtag_tms    ),
    .jtag_tdi_i   ( s_jtag_tdi    ),
    .jtag_tdo_o   ( s_jtag_tdo    )
  );

endmodule
