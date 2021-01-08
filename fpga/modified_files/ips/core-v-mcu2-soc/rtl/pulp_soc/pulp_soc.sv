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

module pulp_soc import dm::*; #(
    parameter CORE_TYPE               = 0,
    parameter USE_FPU                 = 1,
    parameter USE_HWPE                = 1,
    parameter USE_CLUSTER_EVENT       = 1,
    parameter AXI_ADDR_WIDTH          = 32,
    parameter AXI_DATA_IN_WIDTH       = 64,
    parameter AXI_DATA_OUT_WIDTH      = 32,
    parameter AXI_ID_IN_WIDTH         = 6,
    localparam AXI_ID_OUT_WIDTH       = pkg_soc_interconnect::AXI_ID_OUT_WIDTH,
    parameter AXI_USER_WIDTH          = 6,
    parameter AXI_STRB_WIDTH_IN       = AXI_DATA_IN_WIDTH/8,
    parameter AXI_STRB_WIDTH_OUT      = AXI_DATA_OUT_WIDTH/8,
    parameter BUFFER_WIDTH            = 8,
    parameter EVNT_WIDTH              = 8,
    parameter NB_CORES                = 8,
    parameter NB_HWPE_PORTS           = 4,
    parameter NGPIO                   = 43,
    parameter NPAD                    = 64, //Must not be changed as other parts
                                       //downstreams are not parametrci
    parameter NBIT_PADCFG             = 6, //Must not be changed as other parts
                                      //downstreams are not parametrci
    parameter NBIT_PADMUX             = 2,

    parameter int unsigned N_UART     = 1,
    parameter int unsigned N_SPI      = 1,
    parameter int unsigned N_I2C      = 2,
    parameter USE_ZFINX               = 1,
    parameter bit ISOLATE_CLUSTER_CDC = 0 // If 0, ties the cluster <-> soc AXI CDC isolation signal to 0 statically
                                          // disabling the connection. For PULPissimo (MCU without a cluster) this should be set
                                          // to 0.
) (
    input  logic                          ref_clk_i,
    input  logic                          slow_clk_i,
    input  logic                          test_clk_i,
    input  logic                          rstn_glob_i,

    input  logic                          dft_test_mode_i,
    input  logic                          dft_cg_enable_i,
    input  logic                          mode_select_i,
    input  logic                          boot_l2_i,
    input  logic                          bootsel_i,

    input  logic                          fc_fetch_en_valid_i,
    input  logic                          fc_fetch_en_i,

    output logic                          cluster_rtc_o,
    output logic                          cluster_fetch_enable_o,
    output logic [63:0]                   cluster_boot_addr_o,
    output logic                          cluster_test_en_o,
    output logic                          cluster_pow_o,
    output logic                          cluster_byp_o,
    output logic                          cluster_rstn_o,
    output logic                          cluster_irq_o,
    // AXI4 SLAVE
    input  logic [7:0]                    data_slave_aw_writetoken_i,
    input  logic [AXI_ADDR_WIDTH-1:0]     data_slave_aw_addr_i,
    input  logic [2:0]                    data_slave_aw_prot_i,
    input  logic [3:0]                    data_slave_aw_region_i,
    input  logic [7:0]                    data_slave_aw_len_i,
    input  logic [2:0]                    data_slave_aw_size_i,
    //input  logic [5:0]                    data_slave_aw_atop_i,
    input  logic [1:0]                    data_slave_aw_burst_i,
    input  logic                          data_slave_aw_lock_i,
    input  logic [3:0]                    data_slave_aw_cache_i,
    input  logic [3:0]                    data_slave_aw_qos_i,
    input  logic [AXI_ID_IN_WIDTH-1:0]    data_slave_aw_id_i,
    input  logic [AXI_USER_WIDTH-1:0]     data_slave_aw_user_i,
    output logic [7:0]                    data_slave_aw_readpointer_o,
    input  logic [7:0]                    data_slave_ar_writetoken_i,
    input  logic [AXI_ADDR_WIDTH-1:0]     data_slave_ar_addr_i,
    input  logic [2:0]                    data_slave_ar_prot_i,
    input  logic [3:0]                    data_slave_ar_region_i,
    input  logic [7:0]                    data_slave_ar_len_i,
    input  logic [2:0]                    data_slave_ar_size_i,
    input  logic [1:0]                    data_slave_ar_burst_i,
    input  logic                          data_slave_ar_lock_i,
    input  logic [3:0]                    data_slave_ar_cache_i,
    input  logic [3:0]                    data_slave_ar_qos_i,
    input  logic [AXI_ID_IN_WIDTH-1:0]    data_slave_ar_id_i,
    input  logic [AXI_USER_WIDTH-1:0]     data_slave_ar_user_i,
    output logic [7:0]                    data_slave_ar_readpointer_o,
    input  logic [7:0]                    data_slave_w_writetoken_i,
    input  logic [AXI_DATA_IN_WIDTH-1:0]  data_slave_w_data_i,
    input  logic [AXI_STRB_WIDTH_IN-1:0]  data_slave_w_strb_i,
    input  logic [AXI_USER_WIDTH-1:0]     data_slave_w_user_i,
    input  logic                          data_slave_w_last_i,
    output logic [7:0]                    data_slave_w_readpointer_o,
    output logic [7:0]                    data_slave_r_writetoken_o,
    output logic [AXI_DATA_IN_WIDTH-1:0]  data_slave_r_data_o,
    output logic [1:0]                    data_slave_r_resp_o,
    output logic                          data_slave_r_last_o,
    output logic [AXI_ID_IN_WIDTH-1:0]    data_slave_r_id_o,
    output logic [AXI_USER_WIDTH-1:0]     data_slave_r_user_o,
    input  logic [7:0]                    data_slave_r_readpointer_i,
    output logic [7:0]                    data_slave_b_writetoken_o,
    output logic [1:0]                    data_slave_b_resp_o,
    output logic [AXI_ID_IN_WIDTH-1:0]    data_slave_b_id_o,
    output logic [AXI_USER_WIDTH-1:0]     data_slave_b_user_o,
    input  logic [7:0]                    data_slave_b_readpointer_i,

    // AXI4 MASTER
    output logic [7:0]                    data_master_aw_writetoken_o,
    output logic [AXI_ADDR_WIDTH-1:0]     data_master_aw_addr_o,
    output logic [2:0]                    data_master_aw_prot_o,
    output logic [3:0]                    data_master_aw_region_o,
    output logic [7:0]                    data_master_aw_len_o,
    output logic [2:0]                    data_master_aw_size_o,
    // output logic [5:0]                    data_master_aw_atop_o,
    output logic [1:0]                    data_master_aw_burst_o,
    output logic                          data_master_aw_lock_o,
    output logic [3:0]                    data_master_aw_cache_o,
    output logic [3:0]                    data_master_aw_qos_o,
    output logic [AXI_ID_OUT_WIDTH-1:0]   data_master_aw_id_o,
    output logic [AXI_USER_WIDTH-1:0]     data_master_aw_user_o,
    input  logic [7:0]                    data_master_aw_readpointer_i,
    output logic [7:0]                    data_master_ar_writetoken_o,
    output logic [AXI_ADDR_WIDTH-1:0]     data_master_ar_addr_o,
    output logic [2:0]                    data_master_ar_prot_o,
    output logic [3:0]                    data_master_ar_region_o,
    output logic [7:0]                    data_master_ar_len_o,
    output logic [2:0]                    data_master_ar_size_o,
    output logic [1:0]                    data_master_ar_burst_o,
    output logic                          data_master_ar_lock_o,
    output logic [3:0]                    data_master_ar_cache_o,
    output logic [3:0]                    data_master_ar_qos_o,
    output logic [AXI_ID_OUT_WIDTH-1:0]   data_master_ar_id_o,
    output logic [AXI_USER_WIDTH-1:0]     data_master_ar_user_o,
    input  logic [7:0]                    data_master_ar_readpointer_i,
    output logic [7:0]                    data_master_w_writetoken_o,
    output logic [AXI_DATA_OUT_WIDTH-1:0] data_master_w_data_o,
    output logic [AXI_STRB_WIDTH_OUT-1:0] data_master_w_strb_o,
    output logic [AXI_USER_WIDTH-1:0]     data_master_w_user_o,
    output logic                          data_master_w_last_o,
    input  logic [7:0]                    data_master_w_readpointer_i,
    input  logic [7:0]                    data_master_r_writetoken_i,
    input  logic [AXI_DATA_OUT_WIDTH-1:0] data_master_r_data_i,
    input  logic [1:0]                    data_master_r_resp_i,
    input  logic                          data_master_r_last_i,
    input  logic [AXI_ID_OUT_WIDTH-1:0]   data_master_r_id_i,
    input  logic [AXI_USER_WIDTH-1:0]     data_master_r_user_i,
    output logic [7:0]                    data_master_r_readpointer_o,
    input  logic [7:0]                    data_master_b_writetoken_i,
    input  logic [1:0]                    data_master_b_resp_i,
    input  logic [AXI_ID_OUT_WIDTH-1:0]   data_master_b_id_i,
    input  logic [AXI_USER_WIDTH-1:0]     data_master_b_user_i,
    output logic [7:0]                    data_master_b_readpointer_o,

    output logic [BUFFER_WIDTH-1:0]       cluster_events_wt_o,
    input  logic [BUFFER_WIDTH-1:0]       cluster_events_rp_i,
    output logic [EVNT_WIDTH-1:0]         cluster_events_da_o,
    output logic                          cluster_clk_o,
    input  logic                          cluster_busy_i,
    output logic                          dma_pe_evt_ack_o,
    input  logic                          dma_pe_evt_valid_i,
    output logic                          dma_pe_irq_ack_o,
    input  logic                          dma_pe_irq_valid_i,
    output logic                          pf_evt_ack_o,
    input  logic                          pf_evt_valid_i,
    ///////////////////////////////////////////////////
    //      To I/O Controller and padframe           //
    ///////////////////////////////////////////////////
    output logic [127:0]                  pad_mux_o,
    output logic [383:0]                  pad_cfg_o,
    input  logic [NGPIO-1:0]              gpio_in_i,
    output logic [NGPIO-1:0]              gpio_out_o,
    output logic [NGPIO-1:0]              gpio_dir_o,
    output logic [191:0]                  gpio_cfg_o,
    output logic                          uart_tx_o,
    input  logic                          uart_rx_i,
    input  logic                          cam_clk_i,
    input  logic [7:0]                    cam_data_i,
    input  logic                          cam_hsync_i,
    input  logic                          cam_vsync_i,
    output logic [3:0]                    timer_ch0_o,
    output logic [3:0]                    timer_ch1_o,
    output logic [3:0]                    timer_ch2_o,
    output logic [3:0]                    timer_ch3_o,

    input  logic [N_I2C-1:0]              i2c_scl_i,
    output logic [N_I2C-1:0]              i2c_scl_o,
    output logic [N_I2C-1:0]              i2c_scl_oe_o,
    input  logic [N_I2C-1:0]              i2c_sda_i,
    output logic [N_I2C-1:0]              i2c_sda_o,
    output logic [N_I2C-1:0]              i2c_sda_oe_o,

    input  logic                          i2s_slave_sd0_i,
    input  logic                          i2s_slave_sd1_i,
    input  logic                          i2s_slave_ws_i,
    output logic                          i2s_slave_ws_o,
    output logic                          i2s_slave_ws_oe,
    input  logic                          i2s_slave_sck_i,
    output logic                          i2s_slave_sck_o,
    output logic                          i2s_slave_sck_oe,

    output logic [N_SPI-1:0]              spi_clk_o,
    output logic [N_SPI-1:0][3:0]         spi_csn_o,
    output logic [N_SPI-1:0][3:0]         spi_oen_o,
    output logic [N_SPI-1:0][3:0]         spi_sdo_o,
    input  logic [N_SPI-1:0][3:0]         spi_sdi_i,

    output logic                          sdio_clk_o,
    output logic                          sdio_cmd_o,
    input  logic                          sdio_cmd_i,
    output logic                          sdio_cmd_oen_o,
    output logic                    [3:0] sdio_data_o,
    input  logic                    [3:0] sdio_data_i,
    output logic                    [3:0] sdio_data_oen_o,

    ///////////////////////////////////////////////////
    ///////////////////////////////////////////////////
    // From JTAG Tap Controller to axi_dcb module    //
    ///////////////////////////////////////////////////
    input  logic                          jtag_tck_i,
    input  logic                          jtag_trst_ni,
    input  logic                          jtag_tms_i,
    input  logic                          jtag_tdi_i,
    output logic                          jtag_tdo_o,
    output logic [NB_CORES-1:0]           cluster_dbg_irq_valid_o
    ///////////////////////////////////////////////////
);

    localparam FLL_ADDR_WIDTH        = 32;
    localparam FLL_DATA_WIDTH        = 32;
    localparam NB_L2_BANKS = `NB_L2_CHANNELS;
    //The L2 parameter do not influence the size of the memories. Change them in the l2_ram_multibank. This parameters
    //are only here to save area in the uDMA by only storing relevant bits.
    localparam L2_BANK_SIZE          = 29184;            // in 32-bit words
    localparam L2_MEM_ADDR_WIDTH     = $clog2(L2_BANK_SIZE * NB_L2_BANKS) - $clog2(NB_L2_BANKS);    // 2**L2_MEM_ADDR_WIDTH rows (64bit each) in L2 --> TOTAL L2 SIZE = 8byte * 2^L2_MEM_ADDR_WIDTH
    localparam NB_L2_BANKS_PRI       = 2;

    localparam ROM_ADDR_WIDTH        = 13;

    localparam FC_CORE_CLUSTER_ID    = 6'd31;
    localparam CL_CORE_CLUSTER_ID    = 6'd0;

    localparam FC_CORE_CORE_ID       = 4'd0;
    localparam FC_CORE_MHARTID       = {FC_CORE_CLUSTER_ID, 1'b0, FC_CORE_CORE_ID};


    //  PULP RISC-V cores have not continguos MHARTID.
    //  This leads to set the number of HARTS >= the maximum value of the MHARTID.
    //  In this case, the MHARD ID is {FC_CORE_CLUSTER_ID,1'b0,FC_CORE_CORE_ID} --> 996 (1024 chosen as power of 2)
    //  To avoid paying 1024 flip flop for each number of harts's related register, we implemented
    //  the masking parameter, aka SELECTABLE_HARTS.
    //  In One-Hot-Encoding way, you select 1 when that MHARTID-related HART can actally be selected.
    //  e.g. if you have 2 core with MHART 10 and 5, you select NrHarts=16 and SELECTABLE_HARTS = (1<<10) | (1<<5).
    //  This mask will be used to generated only the flip flop needed and the constant-propagator engine of the synthesizer
    //  will remove the other flip flops and related logic.

    localparam NrHarts                               = 1024;

    // this is a constant expression
    function logic [NrHarts-1:0] SEL_HARTS_FX();
        SEL_HARTS_FX = (1 << FC_CORE_MHARTID);
        for (int i = 0; i < NB_CORES; i++) begin
            SEL_HARTS_FX |= (1 << {CL_CORE_CLUSTER_ID, 1'b0, i[3:0]});
        end
    endfunction

    // Each hart with hartid=x sets the x'th bit in SELECTABLE_HARTS
    localparam logic [NrHarts-1:0] SELECTABLE_HARTS = SEL_HARTS_FX();

    // cluster core ids gathere as vector for convenience
    logic [NB_CORES-1:0][10:0] cluster_core_id;
    for (genvar i = 0; i < NB_CORES; i++) begin : gen_cluster_core_id
        assign cluster_core_id[i] = {CL_CORE_CLUSTER_ID, 1'b0, i[3:0]};
    end


    localparam dm::hartinfo_t RI5CY_HARTINFO = '{
       zero1:        '0,
       nscratch:      2, // Debug module needs at least two scratch regs
       zero0:        '0,
       dataaccess: 1'b1, // data registers are memory mapped in the debugger
       datasize: dm::DataCount,
       dataaddr: dm::DataAddr
    };

    dm::hartinfo_t [NrHarts-1:0] hartinfo;

    /*
       This module has been tested only with the default parameters.
    */

    //********************************************************
    //***************** SIGNALS DECLARATION ******************
    //********************************************************
    logic [ 1:0]           s_fc_hwpe_events;
    logic [31:0]           s_fc_events;

    logic [7:0]            s_soc_events_ack;
    logic [7:0]            s_soc_events_val;

    logic                  s_timer_lo_event;
    logic                  s_timer_hi_event;

    logic [EVNT_WIDTH-1:0] s_cl_event_data ;
    logic                  s_cl_event_valid;
    logic                  s_cl_event_ready;

    logic [EVNT_WIDTH-1:0] s_fc_event_data ;
    logic                  s_fc_event_valid;
    logic                  s_fc_event_ready;

    logic [7:0][31:0]      s_apb_mpu_rules;
    logic                  s_supervisor_mode;

    logic [31:0]           s_fc_bootaddr;

    logic [NGPIO-1:0][NBIT_PADCFG-1:0] s_gpio_cfg;
    logic [63:0][1:0]      s_pad_mux;
    logic [63:0][5:0]      s_pad_cfg;

    logic                  s_periph_clk;
    logic                  s_periph_rstn;
    logic                  s_soc_clk;
    logic                  s_soc_rstn;
    logic                  s_cluster_clk;
    logic                  s_cluster_rstn;
    logic                  s_cluster_rstn_soc_ctrl;
    logic                  s_sel_fll_clk;

    logic                  s_dma_pe_evt;
    logic                  s_dma_pe_irq;
    logic                  s_pf_evt;

    logic                  s_fc_fetchen;
    logic [NrHarts-1:0]    dm_debug_req;

    logic                  jtag_req_valid;
    logic                  debug_req_ready;
    logic                  jtag_resp_ready;
    logic                  jtag_resp_valid;
    dm::dmi_req_t          jtag_dmi_req;
    dm::dmi_resp_t         debug_resp;
    logic                  slave_grant, slave_valid, dm_slave_req , dm_slave_we;
    logic                  [31:0] dm_slave_addr, dm_slave_wdata, dm_slave_rdata;
    logic                  [3:0]  dm_slave_be;
    logic                  lint_riscv_jtag_bus_master_we;
    logic                  int_td;

    logic                  master_req;
    logic [31:0]           master_add;
    logic                  master_we;
    logic [31:0]           master_wdata;
    logic [3:0]            master_be;
    logic                  master_gnt;
    logic                  master_r_valid;
    logic [31:0]           master_r_rdata;


    logic [7:0]            soc_jtag_reg_tap;
    logic [7:0]            soc_jtag_reg_soc;


    logic                  spi_master0_csn3, spi_master0_csn2;

    // tap to lint wrap
    logic                  s_jtag_shift_dr;
    logic                  s_jtag_update_dr;
    logic                  s_jtag_capture_dr;
    logic                  s_jtag_axireg_sel;
    logic                  s_jtag_axireg_tdi;
    logic                  s_jtag_axireg_tdo;


    APB_BUS                s_apb_eu_bus ();
    APB_BUS                s_apb_hwpe_bus ();
    APB_BUS                s_apb_debug_bus();

    AXI_BUS_ASYNC #(
        .AXI_ADDR_WIDTH ( AXI_ADDR_WIDTH     ),
        .AXI_DATA_WIDTH ( AXI_DATA_OUT_WIDTH ),
        .AXI_ID_WIDTH   ( AXI_ID_OUT_WIDTH   ),
        .AXI_USER_WIDTH ( AXI_USER_WIDTH     ),
        .BUFFER_WIDTH   ( BUFFER_WIDTH       )
    ) s_data_master ();

    AXI_BUS_ASYNC #(
        .AXI_ADDR_WIDTH ( AXI_ADDR_WIDTH    ),
        .AXI_DATA_WIDTH ( AXI_DATA_IN_WIDTH ),
        .AXI_ID_WIDTH   ( AXI_ID_IN_WIDTH   ),
        .AXI_USER_WIDTH ( AXI_USER_WIDTH     ),
        .BUFFER_WIDTH   ( BUFFER_WIDTH       )
    ) s_data_slave ();

    AXI_BUS #(
        .AXI_ADDR_WIDTH ( AXI_ADDR_WIDTH    ),
        .AXI_DATA_WIDTH ( AXI_DATA_IN_WIDTH ),
        .AXI_ID_WIDTH   ( AXI_ID_IN_WIDTH   ),
        .AXI_USER_WIDTH ( AXI_USER_WIDTH    )
    ) s_data_in_bus ();


    AXI_BUS #(
        .AXI_ADDR_WIDTH ( AXI_ADDR_WIDTH    ),
        .AXI_DATA_WIDTH ( AXI_DATA_OUT_WIDTH),
        .AXI_ID_WIDTH   ( AXI_ID_OUT_WIDTH  ),
        .AXI_USER_WIDTH ( AXI_USER_WIDTH    )
    ) s_data_out_bus ();

    //assign s_data_out_bus.aw_atop = 6'b0;

    FLL_BUS #(
        .FLL_ADDR_WIDTH ( FLL_ADDR_WIDTH ),
        .FLL_DATA_WIDTH ( FLL_DATA_WIDTH )
    ) s_soc_fll_master ();

    FLL_BUS #(
        .FLL_ADDR_WIDTH ( FLL_ADDR_WIDTH ),
        .FLL_DATA_WIDTH ( FLL_DATA_WIDTH )
    ) s_per_fll_master ();

    FLL_BUS #(
        .FLL_ADDR_WIDTH ( FLL_ADDR_WIDTH ),
        .FLL_DATA_WIDTH ( FLL_DATA_WIDTH )
    ) s_cluster_fll_master ();

    APB_BUS s_apb_periph_bus ();

    XBAR_TCDM_BUS s_mem_rom_bus ();

    XBAR_TCDM_BUS  s_mem_l2_bus[NB_L2_BANKS-1:0]();
    XBAR_TCDM_BUS  s_mem_l2_pri_bus[NB_L2_BANKS_PRI-1:0]();

    XBAR_TCDM_BUS s_lint_debug_bus();
    XBAR_TCDM_BUS s_lint_pulp_jtag_bus();
    XBAR_TCDM_BUS s_lint_riscv_jtag_bus();
    XBAR_TCDM_BUS s_lint_udma_tx_bus ();
    XBAR_TCDM_BUS s_lint_udma_rx_bus ();
    XBAR_TCDM_BUS s_lint_fc_data_bus ();
    XBAR_TCDM_BUS s_lint_fc_instr_bus ();
    XBAR_TCDM_BUS s_lint_hwpe_bus[NB_HWPE_PORTS-1:0]();

    `ifdef REMAP_ADDRESS
        logic [3:0] base_addr_int;
        assign base_addr_int = 4'b0001; //FIXME attach this signal somewhere in the soc peripherals --> IGOR
    `endif



    logic s_cluster_isolate_dc;
    logic s_rstn_cluster_sync_soc;


    assign cluster_clk_o  = s_cluster_clk;
    assign cluster_rstn_o = s_cluster_rstn && s_cluster_rstn_soc_ctrl;
    assign s_rstn_cluster_sync_soc = s_cluster_rstn && s_cluster_rstn_soc_ctrl;

    assign cluster_rtc_o     = ref_clk_i;
    assign cluster_test_en_o = dft_test_mode_i;
    // isolate dc if the cluster is down
    assign s_cluster_isolate_dc = ISOLATE_CLUSTER_CDC;
//cluster_byp_o;
    // If you want to connect a real PULP cluster you also need a cluster_busy_i signal

    // cluster to soc
    axi_slice_dc_master_wrap  #(
        .AXI_ADDR_WIDTH ( AXI_ADDR_WIDTH    ),
        .AXI_DATA_WIDTH ( AXI_DATA_IN_WIDTH ),
        .AXI_ID_WIDTH   ( AXI_ID_IN_WIDTH   ),
        .AXI_USER_WIDTH ( AXI_USER_WIDTH    ),
        .BUFFER_WIDTH   ( BUFFER_WIDTH      )
    ) dc_fifo_dataout_bus_i (
        .clk_i           ( s_soc_clk                ),
        .rst_ni          ( s_cluster_rstn           ),
        .isolate_i       ( s_cluster_isolate_dc     ),
        .test_cgbypass_i ( 1'b0                     ),
        .clock_down_i    ( 1'b0                     ),
        .incoming_req_o  (                          ),
        .axi_master      ( s_data_in_bus            ),
        .axi_slave_async ( s_data_slave             )
    );

    // SOC TO CLUSTER
    axi_slice_dc_slave_wrap #(
        .AXI_ADDR_WIDTH ( AXI_ADDR_WIDTH     ),
        .AXI_DATA_WIDTH ( AXI_DATA_OUT_WIDTH ),
        .AXI_ID_WIDTH   ( AXI_ID_OUT_WIDTH   ),
        .AXI_USER_WIDTH ( AXI_USER_WIDTH     ),
        .BUFFER_WIDTH   ( BUFFER_WIDTH       )
    ) dc_fifo_datain_bus_i (
        .clk_i            ( s_soc_clk               ),
        .rst_ni           ( s_rstn_cluster_sync_soc ),
        .test_cgbypass_i  ( 1'b0                    ),
        .isolate_i        ( s_cluster_isolate_dc    ),
        .axi_slave        ( s_data_out_bus          ),
        .axi_master_async ( s_data_master           )
    );

    //********************************************************
    //********************* SOC L2 RAM ***********************
    //********************************************************

    l2_ram_multi_bank #(
        .NB_BANKS              ( NB_L2_BANKS )
    ) l2_ram_i (
        .clk_i           ( s_soc_clk          ),
        .rst_ni          ( s_soc_rstn         ),
        .init_ni         ( 1'b1               ),
        .test_mode_i     ( dft_test_mode_i    ),
        .mem_slave       ( s_mem_l2_bus       ),
        .mem_pri_slave   ( s_mem_l2_pri_bus   )
    );


    //********************************************************
    //******              SOC BOOT ROM             ***********
    //********************************************************

    boot_rom #(
        .ROM_ADDR_WIDTH(ROM_ADDR_WIDTH)
    ) boot_rom_i (
        .clk_i       ( s_soc_clk       ),
        .rst_ni      ( s_soc_rstn      ),
        .init_ni     ( 1'b1            ),
        .mem_slave   ( s_mem_rom_bus   ),
        .test_mode_i ( dft_test_mode_i )
    );

    //********************************************************
    //********************* SOC PERIPHERALS ******************
    //********************************************************

    soc_peripherals #(
        .MEM_ADDR_WIDTH     ( L2_MEM_ADDR_WIDTH+$clog2(NB_L2_BANKS) ),
        .APB_ADDR_WIDTH     ( 32                                    ),
        .APB_DATA_WIDTH     ( 32                                    ),
        .NB_CORES           ( NB_CORES                              ),
        .NB_CLUSTERS        ( `NB_CLUSTERS                          ),
        .EVNT_WIDTH         ( EVNT_WIDTH                            ),
        .NGPIO              ( NGPIO                                 ),
        .NPAD               ( NPAD                                  ),
        .NBIT_PADCFG        ( NBIT_PADCFG                           ),
        .NBIT_PADMUX        ( NBIT_PADMUX                           ),
        .N_UART             ( N_UART                                ),
        .N_SPI              ( N_SPI                                 ),
        .N_I2C              ( N_I2C                                 )
    ) soc_peripherals_i (

        .clk_i                  ( s_soc_clk              ),
        .periph_clk_i           ( s_periph_clk           ),
        .rst_ni                 ( s_soc_rstn             ),
        .sel_fll_clk_i          ( s_sel_fll_clk          ),
        .ref_clk_i              ( ref_clk_i              ),
        .slow_clk_i             ( slow_clk_i             ),

        .dft_test_mode_i        ( dft_test_mode_i        ),
        .dft_cg_enable_i        ( 1'b0                   ),

        .boot_l2_i              ( boot_l2_i              ),
        .bootsel_i              ( bootsel_i              ),

        .fc_fetch_en_valid_i    ( fc_fetch_en_valid_i    ),
        .fc_fetch_en_i          ( fc_fetch_en_i          ),

        .fc_bootaddr_o          ( s_fc_bootaddr          ),
        .fc_fetchen_o           ( s_fc_fetchen           ),

        .apb_slave              ( s_apb_periph_bus       ),

        .apb_eu_master          ( s_apb_eu_bus           ),
        .apb_debug_master       ( s_apb_debug_bus        ),
        .apb_hwpe_master        ( s_apb_hwpe_bus         ),

        .l2_rx_master           ( s_lint_udma_rx_bus     ),
        .l2_tx_master           ( s_lint_udma_tx_bus     ),

        .soc_jtag_reg_i         ( soc_jtag_reg_tap       ),
        .soc_jtag_reg_o         ( soc_jtag_reg_soc       ),

        .fc_hwpe_events_i       ( s_fc_hwpe_events       ),
        .fc_events_o            ( s_fc_events            ),

        .dma_pe_evt_i           ( s_dma_pe_evt           ),
        .dma_pe_irq_i           ( s_dma_pe_irq           ),
        .pf_evt_i               ( s_pf_evt               ),

        .soc_fll_master         ( s_soc_fll_master       ),
        .per_fll_master         ( s_per_fll_master       ),
        .cluster_fll_master     ( s_cluster_fll_master   ),

        .gpio_in                ( gpio_in_i              ),
        .gpio_out               ( gpio_out_o             ),
        .gpio_dir               ( gpio_dir_o             ),
        .gpio_padcfg            ( s_gpio_cfg             ),

        .pad_mux_o              ( s_pad_mux              ),
        .pad_cfg_o              ( s_pad_cfg              ),

        //CAMERA
        .cam_clk_i              ( cam_clk_i              ),
        .cam_data_i             ( cam_data_i             ),
        .cam_hsync_i            ( cam_hsync_i            ),
        .cam_vsync_i            ( cam_vsync_i            ),

        //UART
        .uart_tx                ( uart_tx_o              ),
        .uart_rx                ( uart_rx_i              ),

        //I2C
        .i2c_scl_i              ( i2c_scl_i              ),
        .i2c_scl_o              ( i2c_scl_o              ),
        .i2c_scl_oe_o           ( i2c_scl_oe_o           ),
        .i2c_sda_i              ( i2c_sda_i              ),
        .i2c_sda_o              ( i2c_sda_o              ),
        .i2c_sda_oe_o           ( i2c_sda_oe_o           ),

        //I2S
        .i2s_slave_sd0_i        ( i2s_slave_sd0_i        ),
        .i2s_slave_sd1_i        ( i2s_slave_sd1_i        ),
        .i2s_slave_ws_i         ( i2s_slave_ws_i         ),
        .i2s_slave_ws_o         ( i2s_slave_ws_o         ),
        .i2s_slave_ws_oe        ( i2s_slave_ws_oe        ),
        .i2s_slave_sck_i        ( i2s_slave_sck_i        ),
        .i2s_slave_sck_o        ( i2s_slave_sck_o        ),
        .i2s_slave_sck_oe       ( i2s_slave_sck_oe       ),

         //SPI
        .spi_clk_o              ( spi_clk_o              ),
        .spi_csn_o              ( spi_csn_o              ),
        .spi_oen_o              ( spi_oen_o              ),
        .spi_sdo_o              ( spi_sdo_o              ),
        .spi_sdi_i              ( spi_sdi_i              ),

        //SDIO
        .sdclk_o                ( sdio_clk_o             ),
        .sdcmd_o                ( sdio_cmd_o             ),
        .sdcmd_i                ( sdio_cmd_i             ),
        .sdcmd_oen_o            ( sdio_cmd_oen_o         ),
        .sddata_o               ( sdio_data_o            ),
        .sddata_i               ( sdio_data_i            ),
        .sddata_oen_o           ( sdio_data_oen_o        ),

        .timer_ch0_o            ( timer_ch0_o            ),
        .timer_ch1_o            ( timer_ch1_o            ),
        .timer_ch2_o            ( timer_ch2_o            ),
        .timer_ch3_o            ( timer_ch3_o            ),

        .cl_event_data_o        ( s_cl_event_data        ),
        .cl_event_valid_o       ( s_cl_event_valid       ),
        .cl_event_ready_i       ( s_cl_event_ready       ),

        .fc_event_data_o        ( s_fc_event_data        ),
        .fc_event_valid_o       ( s_fc_event_valid       ),
        .fc_event_ready_i       ( s_fc_event_ready       ),

        .cluster_pow_o          ( cluster_pow_o          ),
        .cluster_byp_o          ( cluster_byp_o          ),
        .cluster_boot_addr_o    ( cluster_boot_addr_o    ),
        .cluster_fetch_enable_o ( cluster_fetch_enable_o ),
        .cluster_rstn_o         ( s_cluster_rstn_soc_ctrl),
        .cluster_irq_o          ( cluster_irq_o          )
    );



    dc_token_ring_fifo_din #(
        .DATA_WIDTH   ( EVNT_WIDTH   ),
        .BUFFER_DEPTH ( BUFFER_WIDTH )
    ) u_event_dc (
        .clk          ( s_soc_clk               ),
        .rstn         ( s_rstn_cluster_sync_soc ),
        .data         ( s_cl_event_data         ),
        .valid        ( s_cl_event_valid        ),
        .ready        ( s_cl_event_ready        ),
        .write_token  ( cluster_events_wt_o     ),
        .read_pointer ( cluster_events_rp_i     ),
        .data_async   ( cluster_events_da_o     )
    );


    edge_propagator_rx ep_dma_pe_evt_i (
        .clk_i   ( s_soc_clk               ),
        .rstn_i  ( s_rstn_cluster_sync_soc ),
        .valid_o ( s_dma_pe_evt            ),
        .ack_o   ( dma_pe_evt_ack_o        ),
        .valid_i ( dma_pe_evt_valid_i      )
    );

    edge_propagator_rx ep_dma_pe_irq_i (
        .clk_i   ( s_soc_clk               ),
        .rstn_i  ( s_rstn_cluster_sync_soc ),
        .valid_o ( s_dma_pe_irq            ),
        .ack_o   ( dma_pe_irq_ack_o        ),
        .valid_i ( dma_pe_irq_valid_i      )
    );
`ifndef PULP_FPGA_EMUL
    edge_propagator_rx ep_pf_evt_i (
        .clk_i   ( s_soc_clk               ),
        .rstn_i  ( s_rstn_cluster_sync_soc ),
        .valid_o ( s_pf_evt                ),
        .ack_o   ( pf_evt_ack_o            ),
        .valid_i ( pf_evt_valid_i          )
    );
`endif

    fc_subsystem #(
        .CORE_TYPE  ( CORE_TYPE          ),
        .USE_FPU    ( USE_FPU            ),
        .CORE_ID    ( FC_CORE_CORE_ID    ),
        .CLUSTER_ID ( FC_CORE_CLUSTER_ID ),
        .USE_HWPE   ( USE_HWPE           )
//        .USE_ZFINX  ( USE_ZFINX          )
    ) fc_subsystem_i (
        .clk_i               ( s_soc_clk           ),
        .rst_ni              ( s_soc_rstn          ),

        .test_en_i           ( dft_test_mode_i     ),

        .boot_addr_i         ( s_fc_bootaddr       ),

        .fetch_en_i          ( s_fc_fetchen        ),

        .l2_data_master      ( s_lint_fc_data_bus  ),
        .l2_instr_master     ( s_lint_fc_instr_bus ),
        .l2_hwpe_master      ( s_lint_hwpe_bus     ),
        .apb_slave_eu        ( s_apb_eu_bus        ),
        .apb_slave_hwpe      ( s_apb_hwpe_bus      ),
        .debug_req_i         ( dm_debug_req[FC_CORE_MHARTID] ),

        .event_fifo_valid_i  ( s_fc_event_valid    ),
        .event_fifo_fulln_o  ( s_fc_event_ready    ),
        .event_fifo_data_i   ( s_fc_event_data     ),
        .events_i            ( s_fc_events         ),
        .hwpe_events_o       ( s_fc_hwpe_events    ),

        .supervisor_mode_o   ( s_supervisor_mode   )
    );

    soc_clk_rst_gen i_clk_rst_gen (
        .ref_clk_i                  ( ref_clk_i                     ),
        .test_clk_i                 ( test_clk_i                    ),
        .sel_fll_clk_i              ( s_sel_fll_clk                 ),

        .rstn_glob_i                ( rstn_glob_i                   ),
        .rstn_soc_sync_o            ( s_soc_rstn                    ),
        .rstn_cluster_sync_o        ( s_cluster_rstn                ),

        .clk_cluster_o              ( s_cluster_clk                 ),
        .test_mode_i                ( dft_test_mode_i               ),
        .shift_enable_i             ( 1'b0                          ),

        .soc_fll_slave_req_i        ( s_soc_fll_master.req          ),
        .soc_fll_slave_wrn_i        ( s_soc_fll_master.wrn          ),
        .soc_fll_slave_add_i        ( s_soc_fll_master.add[1:0]     ),
        .soc_fll_slave_data_i       ( s_soc_fll_master.data         ),
        .soc_fll_slave_ack_o        ( s_soc_fll_master.ack          ),
        .soc_fll_slave_r_data_o     ( s_soc_fll_master.r_data       ),
        .soc_fll_slave_lock_o       ( s_soc_fll_master.lock         ),

        .per_fll_slave_req_i        ( s_per_fll_master.req          ),
        .per_fll_slave_wrn_i        ( s_per_fll_master.wrn          ),
        .per_fll_slave_add_i        ( s_per_fll_master.add[1:0]     ),
        .per_fll_slave_data_i       ( s_per_fll_master.data         ),
        .per_fll_slave_ack_o        ( s_per_fll_master.ack          ),
        .per_fll_slave_r_data_o     ( s_per_fll_master.r_data       ),
        .per_fll_slave_lock_o       ( s_per_fll_master.lock         ),

        .cluster_fll_slave_req_i    ( s_cluster_fll_master.req      ),
        .cluster_fll_slave_wrn_i    ( s_cluster_fll_master.wrn      ),
        .cluster_fll_slave_add_i    ( s_cluster_fll_master.add[1:0] ),
        .cluster_fll_slave_data_i   ( s_cluster_fll_master.data     ),
        .cluster_fll_slave_ack_o    ( s_cluster_fll_master.ack      ),
        .cluster_fll_slave_r_data_o ( s_cluster_fll_master.r_data   ),
        .cluster_fll_slave_lock_o   ( s_cluster_fll_master.lock     ),

        .clk_soc_o                  ( s_soc_clk                     ),
        .clk_per_o                  ( s_periph_clk                  )
    );

    soc_interconnect_wrap #(
      .NR_HWPE_PORTS(NB_HWPE_PORTS),
      .NR_L2_PORTS(NB_L2_BANKS),
      .AXI_IN_ID_WIDTH(AXI_ID_IN_WIDTH),
      .AXI_USER_WIDTH(AXI_USER_WIDTH)
    ) i_soc_interconnect_wrap (
        .clk_i                 ( s_soc_clk           ),
        .rst_ni                ( s_soc_rstn          ),
        .test_en_i             ( dft_test_mode_i     ),
        .tcdm_fc_data          ( s_lint_fc_data_bus  ),
        .tcdm_fc_instr         ( s_lint_fc_instr_bus ),
        .tcdm_udma_rx          ( s_lint_udma_rx_bus  ),
        .tcdm_udma_tx          ( s_lint_udma_tx_bus  ),
        .tcdm_debug            ( s_lint_debug_bus    ),
        .tcdm_hwpe             ( s_lint_hwpe_bus     ),
        .axi_master_plug       ( s_data_in_bus       ),
        .axi_slave_plug        ( s_data_out_bus      ),
        .apb_peripheral_bus    ( s_apb_periph_bus    ),
        .l2_interleaved_slaves ( s_mem_l2_bus        ),
        .l2_private_slaves     ( s_mem_l2_pri_bus    ),
        .boot_rom_slave        ( s_mem_rom_bus       )
        );

    /* Debug Subsystem */

    dmi_jtag #(
        .IdcodeValue          ( `DMI_JTAG_IDCODE    )
    ) i_dmi_jtag (
        .clk_i                ( s_soc_clk           ),
        .rst_ni               ( s_soc_rstn          ),
        .testmode_i           ( 1'b0                ),
        .dmi_req_o            ( jtag_dmi_req        ),
        .dmi_req_valid_o      ( jtag_req_valid      ),
        .dmi_req_ready_i      ( debug_req_ready     ),
        .dmi_resp_i           ( debug_resp          ),
        .dmi_resp_ready_o     ( jtag_resp_ready     ),
        .dmi_resp_valid_i     ( jtag_resp_valid     ),
        .dmi_rst_no           (                     ), // not connected
        .tck_i                ( jtag_tck_i          ),
        .tms_i                ( jtag_tms_i          ),
        .trst_ni              ( jtag_trst_ni        ),
        .td_i                 ( jtag_tdi_i          ),
        .td_o                 ( int_td              ),
        .tdo_oe_o             (                     )
    );

    // set hartinfo
    always_comb begin: set_hartinfo
        for (int hartid = 0; hartid < NrHarts; hartid = hartid + 1) begin
            hartinfo[hartid] = RI5CY_HARTINFO;
        end
    end

    // redirect debug request from dm to correct cluster core
    for (genvar dbg_var = 0; dbg_var < NB_CORES; dbg_var = dbg_var + 1) begin : gen_debug_valid
        assign cluster_dbg_irq_valid_o[dbg_var] = dm_debug_req[cluster_core_id[dbg_var]];
    end

    dm_top #(
       .NrHarts           ( NrHarts                   ),
       .BusWidth          ( 32                        ),
       .SelectableHarts   ( SELECTABLE_HARTS          )
    ) i_dm_top (

       .clk_i             ( s_soc_clk                 ),
       .rst_ni            ( s_soc_rstn                ),
       .testmode_i        ( 1'b0                      ),
       .ndmreset_o        (                           ),
       .dmactive_o        (                           ), // active debug session
       .debug_req_o       ( dm_debug_req              ),
       .unavailable_i     ( ~SELECTABLE_HARTS         ),
       .hartinfo_i        ( hartinfo                  ),

       .slave_req_i       ( dm_slave_req                 ),
       .slave_we_i        ( dm_slave_we                  ),
       .slave_addr_i      ( dm_slave_addr                ),
       .slave_be_i        ( dm_slave_be                  ),
       .slave_wdata_i     ( dm_slave_wdata               ),
       .slave_rdata_o     ( dm_slave_rdata               ),

       .master_req_o      ( s_lint_riscv_jtag_bus.req      ),
       .master_add_o      ( s_lint_riscv_jtag_bus.add      ),
       .master_we_o       ( lint_riscv_jtag_bus_master_we  ),
       .master_wdata_o    ( s_lint_riscv_jtag_bus.wdata    ),
       .master_be_o       ( s_lint_riscv_jtag_bus.be       ),
       .master_gnt_i      ( s_lint_riscv_jtag_bus.gnt      ),
       .master_r_valid_i  ( s_lint_riscv_jtag_bus.r_valid  ),
       .master_r_rdata_i  ( s_lint_riscv_jtag_bus.r_rdata  ),

       .dmi_rst_ni        ( s_soc_rstn                ),
       .dmi_req_valid_i   ( jtag_req_valid            ),
       .dmi_req_ready_o   ( debug_req_ready           ),
       .dmi_req_i         ( jtag_dmi_req              ),
       .dmi_resp_valid_o  ( jtag_resp_valid           ),
       .dmi_resp_ready_i  ( jtag_resp_ready           ),
       .dmi_resp_o        ( debug_resp                )
    );
    assign s_lint_riscv_jtag_bus.wen = ~lint_riscv_jtag_bus_master_we;

    jtag_tap_top jtag_tap_top_i
    (
        .tck_i                    ( jtag_tck_i         ),
        .trst_ni                  ( jtag_trst_ni       ),
        .tms_i                    ( jtag_tms_i         ),
        .td_i                     ( int_td             ),
        .td_o                     ( jtag_tdo_o         ),

        .test_clk_i               ( 1'b0               ),
        .test_rstn_i              ( s_soc_rstn         ),

        .jtag_shift_dr_o          ( s_jtag_shift_dr    ),
        .jtag_update_dr_o         ( s_jtag_update_dr   ),
        .jtag_capture_dr_o        ( s_jtag_capture_dr  ),

        .axireg_sel_o             ( s_jtag_axireg_sel  ),
        .dbg_axi_scan_in_o        ( s_jtag_axireg_tdi  ),
        .dbg_axi_scan_out_i       ( s_jtag_axireg_tdo  ),
        .soc_jtag_reg_i           ( soc_jtag_reg_soc   ),
        .soc_jtag_reg_o           ( soc_jtag_reg_tap   ),
        .sel_fll_clk_o            ( s_sel_fll_clk      )
    );

    lint_jtag_wrap i_lint_jtag (
        .tck_i                    ( jtag_tck_i           ),
        .tdi_i                    ( s_jtag_axireg_tdi    ),
        .trstn_i                  ( jtag_trst_ni         ),
        .tdo_o                    ( s_jtag_axireg_tdo    ),
        .shift_dr_i               ( s_jtag_shift_dr      ),
        .pause_dr_i               ( 1'b0                 ),
        .update_dr_i              ( s_jtag_update_dr     ),
        .capture_dr_i             ( s_jtag_capture_dr    ),
        .lint_select_i            ( s_jtag_axireg_sel    ),
        .clk_i                    ( s_soc_clk            ),
        .rst_ni                   ( s_soc_rstn           ),
        .jtag_lint_master         ( s_lint_pulp_jtag_bus )
    );

    tcdm_arbiter_2x1 jtag_lint_arbiter_i
     (
        .clk_i(s_soc_clk),
        .rst_ni(s_soc_rstn),
        .tcdm_bus_1_i(s_lint_riscv_jtag_bus),
        .tcdm_bus_0_i(s_lint_pulp_jtag_bus),
        .tcdm_bus_o(s_lint_debug_bus)
    );

    apb2per #(
        .PER_ADDR_WIDTH ( 32  ),
        .APB_ADDR_WIDTH ( 32  )
    ) apb2per_newdebug_i (
        .clk_i                ( s_soc_clk               ),
        .rst_ni               ( s_soc_rstn              ),

        .PADDR                ( s_apb_debug_bus.paddr   ),
        .PWDATA               ( s_apb_debug_bus.pwdata  ),
        .PWRITE               ( s_apb_debug_bus.pwrite  ),
        .PSEL                 ( s_apb_debug_bus.psel    ),
        .PENABLE              ( s_apb_debug_bus.penable ),
        .PRDATA               ( s_apb_debug_bus.prdata  ),
        .PREADY               ( s_apb_debug_bus.pready  ),
        .PSLVERR              ( s_apb_debug_bus.pslverr ),

        .per_master_req_o     ( dm_slave_req               ),
        .per_master_add_o     ( dm_slave_addr              ),
        .per_master_we_o      ( dm_slave_we                ),
        .per_master_wdata_o   ( dm_slave_wdata             ),
        .per_master_be_o      ( dm_slave_be                ),
        .per_master_gnt_i     ( slave_grant             ),
        .per_master_r_valid_i ( slave_valid             ),
        .per_master_r_opc_i   ( '0                      ),
        .per_master_r_rdata_i ( dm_slave_rdata             )
     );

     assign slave_grant = dm_slave_req;
     always_ff @(posedge s_soc_clk or negedge s_soc_rstn) begin : apb2per_valid
         if(~s_soc_rstn) begin
             slave_valid <= 0;
         end else begin
             slave_valid <= slave_grant;
         end
     end

    //********************************************************
    //*** PAD AND GPIO CONFIGURATION SIGNALS PACK ************
    //********************************************************

    for (genvar i = 0; i < 32; i++) begin : gen_gpio_cfg_outer
        for (genvar j = 0; j < 6; j++) begin : gen_gpip_cfg_inner
            assign gpio_cfg_o[j+6*i] = s_gpio_cfg[i][j];
        end
    end

    for (genvar i = 0; i < 64; i++) begin : gen_pad_mux_outer
        for (genvar j = 0; j < 2; j++) begin : gen_pad_mux_innter
            assign pad_mux_o[j+2*i] = s_pad_mux[i][j];
        end
    end

    for (genvar i = 0; i < 64; i++) begin : gen_pad_cfg_outer
        for (genvar j = 0; j < 6; j++) begin : gen_pad_cfg_inner
            assign pad_cfg_o[j+6*i] = s_pad_cfg[i][j];
        end
    end

    //********************************************************
    //*** AXI DATA SLAVE INTERFACE UNPACK ********************
    //********************************************************

    // AXI DATA SLAVE
    assign s_data_slave.aw_writetoken  = data_slave_aw_writetoken_i  ;
    assign s_data_slave.aw_addr        = data_slave_aw_addr_i        ;
    assign s_data_slave.aw_prot        = data_slave_aw_prot_i        ;
    assign s_data_slave.aw_region      = data_slave_aw_region_i      ;
    assign s_data_slave.aw_len         = data_slave_aw_len_i         ;
    assign s_data_slave.aw_size        = data_slave_aw_size_i        ;
    assign s_data_slave.aw_burst       = data_slave_aw_burst_i       ;
     //assign s_data_slave.aw_atop        = data_slave_aw_atop_i        ;
    assign s_data_slave.aw_lock        = data_slave_aw_lock_i        ;
    assign s_data_slave.aw_cache       = data_slave_aw_cache_i       ;
    assign s_data_slave.aw_qos         = data_slave_aw_qos_i         ;
    assign s_data_slave.aw_id          = data_slave_aw_id_i          ;
    assign s_data_slave.aw_user        = data_slave_aw_user_i        ;
    assign data_slave_aw_readpointer_o = s_data_slave.aw_readpointer ;

    assign s_data_slave.ar_writetoken  = data_slave_ar_writetoken_i  ;
    assign s_data_slave.ar_addr        = data_slave_ar_addr_i        ;
    assign s_data_slave.ar_prot        = data_slave_ar_prot_i        ;
    assign s_data_slave.ar_region      = data_slave_ar_region_i      ;
    assign s_data_slave.ar_len         = data_slave_ar_len_i         ;
    assign s_data_slave.ar_size        = data_slave_ar_size_i        ;
    assign s_data_slave.ar_burst       = data_slave_ar_burst_i       ;
    assign s_data_slave.ar_lock        = data_slave_ar_lock_i        ;
    assign s_data_slave.ar_cache       = data_slave_ar_cache_i       ;
    assign s_data_slave.ar_qos         = data_slave_ar_qos_i         ;
    assign s_data_slave.ar_id          = data_slave_ar_id_i          ;
    assign s_data_slave.ar_user        = data_slave_ar_user_i        ;
    assign data_slave_ar_readpointer_o = s_data_slave.ar_readpointer ;

    assign s_data_slave.w_writetoken   = data_slave_w_writetoken_i   ;
    assign s_data_slave.w_data         = data_slave_w_data_i         ;
    assign s_data_slave.w_strb         = data_slave_w_strb_i         ;
    assign s_data_slave.w_user         = data_slave_w_user_i         ;
    assign s_data_slave.w_last         = data_slave_w_last_i         ;
    assign data_slave_w_readpointer_o  = s_data_slave.w_readpointer  ;

    assign data_slave_r_writetoken_o   = s_data_slave.r_writetoken   ;
    assign data_slave_r_data_o         = s_data_slave.r_data         ;
    assign data_slave_r_resp_o         = s_data_slave.r_resp         ;
    assign data_slave_r_last_o         = s_data_slave.r_last         ;
    assign data_slave_r_id_o           = s_data_slave.r_id           ;
    assign data_slave_r_user_o         = s_data_slave.r_user         ;
    assign s_data_slave.r_readpointer  = data_slave_r_readpointer_i  ;

    assign data_slave_b_writetoken_o   = s_data_slave.b_writetoken   ;
    assign data_slave_b_resp_o         = s_data_slave.b_resp         ;
    assign data_slave_b_id_o           = s_data_slave.b_id           ;
    assign data_slave_b_user_o         = s_data_slave.b_user         ;
    assign s_data_slave.b_readpointer  = data_slave_b_readpointer_i  ;

    //********************************************************
    //*** AXI DATA MASTER INTERFACE UNPACK *******************
    //********************************************************

    assign data_master_aw_writetoken_o  = s_data_master.aw_writetoken ;
    assign data_master_aw_addr_o        = s_data_master.aw_addr       ;
    assign data_master_aw_prot_o        = s_data_master.aw_prot       ;
    assign data_master_aw_region_o      = s_data_master.aw_region     ;
    assign data_master_aw_len_o         = s_data_master.aw_len        ;
    assign data_master_aw_size_o        = s_data_master.aw_size       ;
    //assign data_master_aw_atop_o        = s_data_master.aw_atop       ;
    assign data_master_aw_burst_o       = s_data_master.aw_burst      ;
    assign data_master_aw_lock_o        = s_data_master.aw_lock       ;
    assign data_master_aw_cache_o       = s_data_master.aw_cache      ;
    assign data_master_aw_qos_o         = s_data_master.aw_qos        ;
    assign data_master_aw_id_o          = s_data_master.aw_id         ;
    assign data_master_aw_user_o        = s_data_master.aw_user       ;
    assign s_data_master.aw_readpointer = data_master_aw_readpointer_i;

    assign data_master_ar_writetoken_o  = s_data_master.ar_writetoken ;
    assign data_master_ar_addr_o        = s_data_master.ar_addr       ;
    assign data_master_ar_prot_o        = s_data_master.ar_prot       ;
    assign data_master_ar_region_o      = s_data_master.ar_region     ;
    assign data_master_ar_len_o         = s_data_master.ar_len        ;
    assign data_master_ar_size_o        = s_data_master.ar_size       ;
    assign data_master_ar_burst_o       = s_data_master.ar_burst      ;
    assign data_master_ar_lock_o        = s_data_master.ar_lock       ;
    assign data_master_ar_cache_o       = s_data_master.ar_cache      ;
    assign data_master_ar_qos_o         = s_data_master.ar_qos        ;
    assign data_master_ar_id_o          = s_data_master.ar_id         ;
    assign data_master_ar_user_o        = s_data_master.ar_user       ;
    assign s_data_master.ar_readpointer = data_master_ar_readpointer_i;

    assign data_master_w_writetoken_o   = s_data_master.w_writetoken  ;
    assign data_master_w_data_o         = s_data_master.w_data        ;
    assign data_master_w_strb_o         = s_data_master.w_strb        ;
    assign data_master_w_user_o         = s_data_master.w_user        ;
    assign data_master_w_last_o         = s_data_master.w_last        ;
    assign s_data_master.w_readpointer  = data_master_w_readpointer_i ;

    assign s_data_master.r_writetoken   = data_master_r_writetoken_i  ;
    assign s_data_master.r_data         = data_master_r_data_i        ;
    assign s_data_master.r_resp         = data_master_r_resp_i        ;
    assign s_data_master.r_last         = data_master_r_last_i        ;
    assign s_data_master.r_id           = data_master_r_id_i          ;
    assign s_data_master.r_user         = data_master_r_user_i        ;
    assign data_master_r_readpointer_o  = s_data_master.r_readpointer ;

    assign s_data_master.b_writetoken   = data_master_b_writetoken_i  ;
    assign s_data_master.b_resp         = data_master_b_resp_i        ;
    assign s_data_master.b_id           = data_master_b_id_i          ;
    assign s_data_master.b_user         = data_master_b_user_i        ;
    assign data_master_b_readpointer_o  = s_data_master.b_readpointer ;

endmodule
