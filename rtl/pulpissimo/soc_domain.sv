// Copyright 2018 ETH Zurich and University of Bologna.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

`include "pulp_soc_defines.sv"

module soc_domain #(
    parameter CORE_TYPE            = 0,
    parameter USE_FPU              = 1,
    parameter USE_ZFINX            = 1,
    parameter USE_HWPE             = 1,
    parameter USE_CLUSTER_EVENT    = 1,
    parameter SIM_STDOUT           = 1,
    parameter NB_CL_CORES          = 8,
    parameter AXI_ADDR_WIDTH       = 32,
    parameter AXI_DATA_IN_WIDTH    = 64,
    parameter AXI_DATA_OUT_WIDTH   = 32,
    parameter AXI_ID_IN_WIDTH      = 4,
    localparam AXI_ID_OUT_WIDTH    = pkg_soc_interconnect::AXI_ID_OUT_WIDTH, //Must be large enough to accomodate the additional
                                                                  //bits for the axi XBAR ($clog2(nr_master), rightnow
                                                                  //we have 9 masters 5 for fc_data, fc_instr, udma_rx,
                                                                  //udma_tx, debug_access and 4 for the 64-bit
                                                                  //cluster2soc axi plug
    parameter AXI_USER_WIDTH       = 6,
    parameter AXI_STRB_WIDTH_IN   = AXI_DATA_IN_WIDTH/8,
    parameter AXI_STRB_WIDTH_OUT  = AXI_DATA_OUT_WIDTH/8,

    parameter EVNT_WIDTH           = 8,
    parameter CDC_FIFOS_LOG_DEPTH  = 3,

    parameter int unsigned N_UART = 1,
    parameter int unsigned N_SPI  = 1,
    parameter int unsigned N_I2C  = 2,
    localparam C2S_AW_WIDTH       = AXI_ID_IN_WIDTH+AXI_ADDR_WIDTH+AXI_USER_WIDTH+$bits(axi_pkg::len_t)+$bits(axi_pkg::size_t)+$bits(axi_pkg::burst_t)+$bits(axi_pkg::cache_t)+$bits(axi_pkg::prot_t)+$bits(axi_pkg::qos_t)+$bits(axi_pkg::region_t)+$bits(axi_pkg::atop_t)+1,
    localparam C2S_W_WIDTH        = AXI_USER_WIDTH+AXI_STRB_WIDTH_IN+AXI_DATA_IN_WIDTH+1,
    localparam C2S_R_WIDTH        = AXI_ID_IN_WIDTH+AXI_DATA_IN_WIDTH+AXI_USER_WIDTH+$bits(axi_pkg::resp_t)+1,
    localparam C2S_B_WIDTH        = AXI_USER_WIDTH+AXI_ID_IN_WIDTH+$bits(axi_pkg::resp_t),
    localparam C2S_AR_WIDTH       = AXI_ID_IN_WIDTH+AXI_ADDR_WIDTH+AXI_USER_WIDTH+$bits(axi_pkg::len_t)+$bits(axi_pkg::size_t)+$bits(axi_pkg::burst_t)+$bits(axi_pkg::cache_t)+$bits(axi_pkg::prot_t)+$bits(axi_pkg::qos_t)+$bits(axi_pkg::region_t)+1,
    localparam S2C_AW_WIDTH       = AXI_ID_OUT_WIDTH+AXI_ADDR_WIDTH+AXI_USER_WIDTH+$bits(axi_pkg::len_t)+$bits(axi_pkg::size_t)+$bits(axi_pkg::burst_t)+$bits(axi_pkg::cache_t)+$bits(axi_pkg::prot_t)+$bits(axi_pkg::qos_t)+$bits(axi_pkg::region_t)+$bits(axi_pkg::atop_t)+1,
    localparam S2C_W_WIDTH        = AXI_USER_WIDTH+AXI_STRB_WIDTH_OUT+AXI_DATA_OUT_WIDTH+1,
    localparam S2C_R_WIDTH        = AXI_ID_OUT_WIDTH+AXI_DATA_OUT_WIDTH+AXI_USER_WIDTH+$bits(axi_pkg::resp_t)+1,
    localparam S2C_B_WIDTH        = AXI_USER_WIDTH+AXI_ID_OUT_WIDTH+$bits(axi_pkg::resp_t),
    localparam S2C_AR_WIDTH       = AXI_ID_OUT_WIDTH+AXI_ADDR_WIDTH+AXI_USER_WIDTH+$bits(axi_pkg::len_t)+$bits(axi_pkg::size_t)+$bits(axi_pkg::burst_t)+$bits(axi_pkg::cache_t)+$bits(axi_pkg::prot_t)+$bits(axi_pkg::qos_t)+$bits(axi_pkg::region_t)+1
)(

    input logic                           ref_clk_i,
    input logic                           slow_clk_i,
    input logic                           test_clk_i,

    input logic                           rstn_glob_i,

    input logic                           dft_test_mode_i,
    input logic                           dft_cg_enable_i,

    input logic                           mode_select_i,

    input logic [1:0]                     bootsel_i,

    input logic                           fc_fetch_en_valid_i,
    input logic                           fc_fetch_en_i,

    input logic                           jtag_tck_i,
    input logic                           jtag_trst_ni,
    input logic                           jtag_tms_i,
    input logic                           jtag_tdi_i,
    output logic                          jtag_tdo_o,

    output logic [NB_CL_CORES-1:0]        cluster_dbg_irq_valid_o,

    input logic [31:0]                    gpio_in_i,
    output logic [31:0]                   gpio_out_o,
    output logic [31:0]                   gpio_dir_o,
    output logic [191:0]                  gpio_cfg_o,

    output logic [127:0]                  pad_mux_o,
    output logic [383:0]                  pad_cfg_o,

    output logic                          uart_tx_o,
    input logic                           uart_rx_i,

    input logic                           cam_clk_i,
    input logic [7:0]                     cam_data_i,
    input logic                           cam_hsync_i,
    input logic                           cam_vsync_i,

    output logic [3:0]                    timer_ch0_o,
    output logic [3:0]                    timer_ch1_o,
    output logic [3:0]                    timer_ch2_o,
    output logic [3:0]                    timer_ch3_o,

    input logic [N_I2C-1:0]               i2c_scl_i,
    output logic [N_I2C-1:0]              i2c_scl_o,
    output logic [N_I2C-1:0]              i2c_scl_oe_o,
    input logic [N_I2C-1:0]               i2c_sda_i,
    output logic [N_I2C-1:0]              i2c_sda_o,
    output logic [N_I2C-1:0]              i2c_sda_oe_o,

    input logic                           i2s_slave_sd0_i,
    input logic                           i2s_slave_sd1_i,
    input logic                           i2s_slave_ws_i,
    output logic                          i2s_slave_ws_o,
    output logic                          i2s_slave_ws_oe,
    input logic                           i2s_slave_sck_i,
    output logic                          i2s_slave_sck_o,
    output logic                          i2s_slave_sck_oe,

    output logic [N_SPI-1:0]              spi_clk_o,
    output logic [N_SPI-1:0][3:0]         spi_csn_o,
    output logic [N_SPI-1:0][3:0]         spi_oen_o,
    output logic [N_SPI-1:0][3:0]         spi_sdo_o,
    input logic [N_SPI-1:0][3:0]          spi_sdi_i,

    output logic                          sdio_clk_o,
    output logic                          sdio_cmd_o,
    input logic                           sdio_cmd_i,
    output logic                          sdio_cmd_oen_o,
    output logic [3:0]                    sdio_data_o,
    input logic [3:0]                     sdio_data_i,
    output logic [3:0]                    sdio_data_oen_o,

    output logic [1:0]                    hyper_cs_no,
    output logic                          hyper_ck_o,
    output logic                          hyper_ck_no,
    output logic [1:0]                    hyper_rwds_o,
    input logic                           hyper_rwds_i,
    output logic [1:0]                    hyper_rwds_oe_o,
    input logic [15:0]                    hyper_dq_i,
    output logic [15:0]                   hyper_dq_o,
    output logic [1:0]                    hyper_dq_oe_o,
    output logic                          hyper_reset_no,

    // CLUSTER
    output logic                          cluster_clk_o,
    output logic                          cluster_rstn_o,
    input logic                           cluster_busy_i,
    output logic                          cluster_irq_o,

    output logic                          cluster_rtc_o,
    output logic                          cluster_fetch_enable_o,
    output logic [63:0]                   cluster_boot_addr_o,
    output logic                          cluster_test_en_o,
    output logic                          cluster_pow_o,
    output logic                          cluster_byp_o,
      // AXI4 SLAVE
    input logic [CDC_FIFOS_LOG_DEPTH:0]                        async_data_slave_aw_wptr_i,
    input logic [2**CDC_FIFOS_LOG_DEPTH-1:0][C2S_AW_WIDTH-1:0] async_data_slave_aw_data_i,
    output logic  [CDC_FIFOS_LOG_DEPTH:0]                      async_data_slave_aw_rptr_o,

    // READ ADDRESS CHANNEL
    input logic [CDC_FIFOS_LOG_DEPTH:0]                        async_data_slave_ar_wptr_i,
    input logic [2**CDC_FIFOS_LOG_DEPTH-1:0][C2S_AR_WIDTH-1:0] async_data_slave_ar_data_i,
    output logic [CDC_FIFOS_LOG_DEPTH:0]                       async_data_slave_ar_rptr_o,

    // WRITE DATA CHANNEL
    input logic [CDC_FIFOS_LOG_DEPTH:0]                        async_data_slave_w_wptr_i,
    input logic [2**CDC_FIFOS_LOG_DEPTH-1:0][C2S_W_WIDTH-1:0]  async_data_slave_w_data_i,
    output logic [CDC_FIFOS_LOG_DEPTH:0]                       async_data_slave_w_rptr_o,

    // READ DATA CHANNEL
    output logic [CDC_FIFOS_LOG_DEPTH:0]                        async_data_slave_r_wptr_o,
    output logic [2**CDC_FIFOS_LOG_DEPTH-1:0][C2S_R_WIDTH-1:0]  async_data_slave_r_data_o,
    input logic [CDC_FIFOS_LOG_DEPTH:0]                         async_data_slave_r_rptr_i,

    // WRITE RESPONSE CHANNEL
    output logic [CDC_FIFOS_LOG_DEPTH:0]                        async_data_slave_b_wptr_o,
    output logic [2**CDC_FIFOS_LOG_DEPTH-1:0][C2S_B_WIDTH-1:0]  async_data_slave_b_data_o,
    input logic [CDC_FIFOS_LOG_DEPTH:0]                         async_data_slave_b_rptr_i,

    // AXI4 MASTER
    output logic [CDC_FIFOS_LOG_DEPTH:0]                        async_data_master_aw_wptr_o,
    output logic [2**CDC_FIFOS_LOG_DEPTH-1:0][S2C_AW_WIDTH-1:0] async_data_master_aw_data_o,
    input logic  [CDC_FIFOS_LOG_DEPTH:0]                        async_data_master_aw_rptr_i,

    // READ ADDRESS CHANNEL
    output logic [CDC_FIFOS_LOG_DEPTH:0]                        async_data_master_ar_wptr_o,
    output logic [2**CDC_FIFOS_LOG_DEPTH-1:0][S2C_AR_WIDTH-1:0] async_data_master_ar_data_o,
    input logic [CDC_FIFOS_LOG_DEPTH:0]                         async_data_master_ar_rptr_i,

    // WRITE DATA CHANNEL
    output logic [CDC_FIFOS_LOG_DEPTH:0]                        async_data_master_w_wptr_o,
    output logic [2**CDC_FIFOS_LOG_DEPTH-1:0][S2C_W_WIDTH-1:0]  async_data_master_w_data_o,
    input logic [CDC_FIFOS_LOG_DEPTH:0]                         async_data_master_w_rptr_i,

    // READ DATA CHANNEL
    input logic [CDC_FIFOS_LOG_DEPTH:0]                        async_data_master_r_wptr_i,
    input logic [2**CDC_FIFOS_LOG_DEPTH-1:0][S2C_R_WIDTH-1:0]  async_data_master_r_data_i,
    output logic [CDC_FIFOS_LOG_DEPTH:0]                       async_data_master_r_rptr_o,

    // WRITE RESPONSE CHANNEL
    input logic [CDC_FIFOS_LOG_DEPTH:0]                        async_data_master_b_wptr_i,
    input logic [2**CDC_FIFOS_LOG_DEPTH-1:0][S2C_B_WIDTH-1:0]  async_data_master_b_data_i,
    output logic [CDC_FIFOS_LOG_DEPTH:0]                       async_data_master_b_rptr_o,

    // EVENT BUS
    output logic [CDC_FIFOS_LOG_DEPTH:0]                       async_cluster_events_wptr_o,
    input logic [CDC_FIFOS_LOG_DEPTH:0]                        async_cluster_events_rptr_i,
    output logic [EVNT_WIDTH-1:0][2**CDC_FIFOS_LOG_DEPTH-1:0]  async_cluster_events_data_o,

    output logic                          dma_pe_evt_ack_o,
    input logic                           dma_pe_evt_valid_i,

    output logic                          dma_pe_irq_ack_o,
    input logic                           dma_pe_irq_valid_i,

    output logic                          pf_evt_ack_o,
    input logic                           pf_evt_valid_i

    /*AUTOINOUT*/
);


    pulp_soc #(
      .CORE_TYPE           ( CORE_TYPE           ),
      .USE_FPU             ( USE_FPU             ),
      .USE_HWPE            ( USE_HWPE            ),
      .USE_CLUSTER_EVENT   ( USE_CLUSTER_EVENT   ),
      .SIM_STDOUT          ( SIM_STDOUT          ),
      .AXI_ADDR_WIDTH      ( AXI_ADDR_WIDTH      ),
      .AXI_DATA_IN_WIDTH   ( AXI_DATA_IN_WIDTH   ),
      .AXI_DATA_OUT_WIDTH  ( AXI_DATA_OUT_WIDTH  ),
      .AXI_ID_IN_WIDTH     ( AXI_ID_IN_WIDTH     ),
      .AXI_USER_WIDTH      ( AXI_USER_WIDTH      ),
      .AXI_STRB_WIDTH_IN   ( AXI_STRB_WIDTH_IN   ),
      .AXI_STRB_WIDTH_OUT  ( AXI_STRB_WIDTH_OUT  ),
      .CDC_FIFOS_LOG_DEPTH ( CDC_FIFOS_LOG_DEPTH ),
      .EVNT_WIDTH          ( EVNT_WIDTH          ),
      .NB_CORES            ( NB_CL_CORES         ),
      .NGPIO               ( 32                  ),
      .NPAD                ( 64                  ),
      .NBIT_PADCFG         ( 6                   ),
      .NBIT_PADMUX         ( 2                   ),
      .N_UART              ( N_UART              ),
      .N_SPI               ( N_SPI               ),
      .N_I2C               ( N_I2C               ),
      .USE_ZFINX           ( USE_ZFINX           )
    ) pulp_soc_i (
      .ref_clk_i,
      .slow_clk_i,
      .test_clk_i,
      .rstn_glob_i,
      .dft_test_mode_i,
      .dft_cg_enable_i,
      .mode_select_i,
      .boot_l2_i(1'b0),
      .bootsel_i,
      .fc_fetch_en_valid_i,
      .fc_fetch_en_i,
      .cluster_rtc_o,
      .cluster_fetch_enable_o,
      .cluster_boot_addr_o,
      .cluster_test_en_o,
      .cluster_pow_o,
      .cluster_byp_o,
      .cluster_rstn_o,
      .cluster_irq_o,
      .async_data_slave_aw_wptr_i,
      .async_data_slave_aw_data_i,
      .async_data_slave_aw_rptr_o,
      .async_data_slave_ar_wptr_i,
      .async_data_slave_ar_data_i,
      .async_data_slave_ar_rptr_o,
      .async_data_slave_w_wptr_i,
      .async_data_slave_w_data_i,
      .async_data_slave_w_rptr_o,
      .async_data_slave_r_wptr_o,
      .async_data_slave_r_data_o,
      .async_data_slave_r_rptr_i,
      .async_data_slave_b_wptr_o,
      .async_data_slave_b_data_o,
      .async_data_slave_b_rptr_i,
      .async_data_master_aw_wptr_o,
      .async_data_master_aw_data_o,
      .async_data_master_aw_rptr_i,
      .async_data_master_ar_wptr_o,
      .async_data_master_ar_data_o,
      .async_data_master_ar_rptr_i,
      .async_data_master_w_wptr_o,
      .async_data_master_w_data_o,
      .async_data_master_w_rptr_i,
      .async_data_master_r_wptr_i,
      .async_data_master_r_data_i,
      .async_data_master_r_rptr_o,
      .async_data_master_b_wptr_i,
      .async_data_master_b_data_i,
      .async_data_master_b_rptr_o,
      .async_cluster_events_wptr_o,
      .async_cluster_events_rptr_i,
      .async_cluster_events_data_o,
      .cluster_clk_o,
      .cluster_busy_i,
      .dma_pe_evt_ack_o,
      .dma_pe_evt_valid_i,
      .dma_pe_irq_ack_o,
      .dma_pe_irq_valid_i,
      .pf_evt_ack_o,
      .pf_evt_valid_i,
      .pad_mux_o,
      .pad_cfg_o,
      .gpio_in_i,
      .gpio_out_o,
      .gpio_dir_o,
      .gpio_cfg_o,
      .uart_tx_o,
      .uart_rx_i,
      .cam_clk_i,
      .cam_data_i,
      .cam_hsync_i,
      .cam_vsync_i,
      .timer_ch0_o,
      .timer_ch1_o,
      .timer_ch2_o,
      .timer_ch3_o,

      .i2c_scl_i,
      .i2c_scl_o,
      .i2c_scl_oe_o,
      .i2c_sda_i,
      .i2c_sda_o,
      .i2c_sda_oe_o,

      .i2s_slave_sd0_i,
      .i2s_slave_sd1_i,
      .i2s_slave_ws_i,
      .i2s_slave_ws_o,
      .i2s_slave_ws_oe,
      .i2s_slave_sck_i,
      .i2s_slave_sck_o,
      .i2s_slave_sck_oe,

      .spi_clk_o,
      .spi_csn_o,
      .spi_oen_o,
      .spi_sdo_o,
      .spi_sdi_i,

      .sdio_clk_o,
      .sdio_cmd_o,
      .sdio_cmd_i,
      .sdio_cmd_oen_o,
      .sdio_data_o,
      .sdio_data_i,
      .sdio_data_oen_o,

      .hyper_cs_no,
      .hyper_ck_o,
      .hyper_ck_no,
      .hyper_rwds_o,
      .hyper_rwds_i,
      .hyper_rwds_oe_o,
      .hyper_dq_i,
      .hyper_dq_o,
      .hyper_dq_oe_o,
      .hyper_reset_no,

      .jtag_tck_i,
      .jtag_trst_ni,
      .jtag_tms_i,
      .jtag_tdi_i,
      .jtag_tdo_o,
      .cluster_dbg_irq_valid_o
    );

endmodule
