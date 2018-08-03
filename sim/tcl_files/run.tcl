#!/bin/bash
set TB "tb_pulp -L modelsim_lib -L L2_tcdm_hybrid_interco_lib -L adv_dbg_if_lib -L apb2per_lib -L apb_adv_timer_lib -L apb_fll_if_lib -L apb_gpio_lib -L apb_node_lib -L apb_interrupt_cntrl_lib -L axi_node_lib -L axi_slice_lib -L axi_slice_dc_lib -L timer_unit_lib -L common_cells_lib -L fpu_lib -L jtag_pulp_lib -L riscv_lib -L zero_riscy_lib -L scm_lib -L generic_FLL_lib -L tech_cells_generic_lib -L udma_core_lib -L udma_uart_lib -L udma_i2c_lib -L udma_i2s_lib -L udma_qspi_lib -L udma_sdio_lib -L udma_camera_lib -L hwpe_ctrl_lib -L hwpe_stream_lib -L hwpe_mac_engine_lib -L pulp_soc_lib -L tbtools_lib -L tb_lib -L vip_lib -L pulpissimo_lib"

source ./tcl_files/config/vsim.tcl


