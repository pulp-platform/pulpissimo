if ![info exists PULP_FPGA_SIM] {
    set RTL ../rtl
    set IPS ../ips
    set FPGA_IPS ../ips
    set FPGA_RTL ../rtl
}

puts "../fpga/tcl/rtl_src_files.tcl"
set dircorr [pwd]
puts $dircorr


# soc_interconnect
set SRC_SOC_INTERCONNECT " \
    $IPS/L2_tcdm_hybrid_interco/RTL/l2_tcdm_demux.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/lint_2_apb.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/lint_2_axi.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/axi_2_lint/axi64_2_lint32.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/axi_2_lint/axi_read_ctrl.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/axi_2_lint/axi_write_ctrl.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/axi_2_lint/lint64_to_32.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_L2/AddressDecoder_Req_L2.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_L2/AddressDecoder_Resp_L2.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_L2/ArbitrationTree_L2.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_L2/FanInPrimitive_Req_L2.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_L2/FanInPrimitive_Resp_L2.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_L2/MUX2_REQ_L2.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_L2/RequestBlock_L2_1CH.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_L2/RequestBlock_L2_2CH.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_L2/ResponseBlock_L2.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_L2/ResponseTree_L2.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_L2/RR_Flag_Req_L2.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_L2/XBAR_L2.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_BRIDGE/AddressDecoder_Req_BRIDGE.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_BRIDGE/AddressDecoder_Resp_BRIDGE.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_BRIDGE/ArbitrationTree_BRIDGE.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_BRIDGE/FanInPrimitive_Req_BRIDGE.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_BRIDGE/FanInPrimitive_Resp_BRIDGE.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_BRIDGE/MUX2_REQ_BRIDGE.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_BRIDGE/RequestBlock1CH_BRIDGE.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_BRIDGE/RequestBlock2CH_BRIDGE.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_BRIDGE/ResponseBlock_BRIDGE.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_BRIDGE/ResponseTree_BRIDGE.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_BRIDGE/RR_Flag_Req_BRIDGE.sv \
    $IPS/L2_tcdm_hybrid_interco/RTL/XBAR_BRIDGE/XBAR_BRIDGE.sv \
"

# adv_dbg_if
set SRC_ADV_DBG_IF " \
    $IPS/adv_dbg_if/rtl/adbg_axi_biu.sv \
    $IPS/adv_dbg_if/rtl/adbg_axi_module.sv \
    $IPS/adv_dbg_if/rtl/adbg_lint_biu.sv \
    $IPS/adv_dbg_if/rtl/adbg_lint_module.sv \
    $IPS/adv_dbg_if/rtl/adbg_crc32.v \
    $IPS/adv_dbg_if/rtl/adbg_or1k_biu.sv \
    $IPS/adv_dbg_if/rtl/adbg_or1k_module.sv \
    $IPS/adv_dbg_if/rtl/adbg_or1k_status_reg.sv \
    $IPS/adv_dbg_if/rtl/adbg_top.sv \
    $IPS/adv_dbg_if/rtl/bytefifo.v \
    $IPS/adv_dbg_if/rtl/syncflop.v \
    $IPS/adv_dbg_if/rtl/syncreg.v \
    $IPS/adv_dbg_if/rtl/adbg_tap_top.v \
    $IPS/adv_dbg_if/rtl/adv_dbg_if.sv \
    $IPS/adv_dbg_if/rtl/adbg_axionly_top.sv \
    $IPS/adv_dbg_if/rtl/adbg_lintonly_top.sv \
"
set INC_ADV_DBG_IF " \
    $IPS/adv_dbg_if/rtl \
"

# apb2per
set SRC_APB2PER " \
    $IPS/apb/apb2per/apb2per.sv \
"

# apb_adv_timer
set SRC_APB_ADV_TIMER " \
    $IPS/apb/apb_adv_timer/adv_timer_apb_if.sv \
    $IPS/apb/apb_adv_timer/comparator.sv \
    $IPS/apb/apb_adv_timer/lut_4x4.sv \
    $IPS/apb/apb_adv_timer/out_filter.sv \
    $IPS/apb/apb_adv_timer/up_down_counter.sv \
    $IPS/apb/apb_adv_timer/input_stage.sv \
    $IPS/apb/apb_adv_timer/prescaler.sv \
    $IPS/apb/apb_adv_timer/apb_adv_timer.sv \
    $IPS/apb/apb_adv_timer/timer_cntrl.sv \
    $IPS/apb/apb_adv_timer/timer_module.sv \
"
set INC_APB_ADV_TIMER " \
    $IPS/apb/apb_adv_timer/. \
"

# apb_fll_if
set SRC_APB_FLL_IF " \
    $IPS/apb/apb_fll_if/apb_fll_if.sv \
"

# apb_gpio
set SRC_APB_GPIO " \
    $IPS/apb/apb_gpio/rtl/apb_gpio.sv \
"

# apb_node
set SRC_APB_NODE " \
    $IPS/apb/apb_node/apb_node.sv \
    $IPS/apb/apb_node/apb_node_wrap.sv \
"

# apb_interrupt_cntrl
set SRC_APB_INTERRUPT_CNTRL " \
    $IPS/apb_interrupt_cntrl/apb_interrupt_cntrl.sv \
"

# axi_node
set SRC_AXI_NODE " \
    $IPS/axi/axi_node/apb_regs_top.sv \
    $IPS/axi/axi_node/axi_address_decoder_AR.sv \
    $IPS/axi/axi_node/axi_address_decoder_AW.sv \
    $IPS/axi/axi_node/axi_address_decoder_BR.sv \
    $IPS/axi/axi_node/axi_address_decoder_BW.sv \
    $IPS/axi/axi_node/axi_address_decoder_DW.sv \
    $IPS/axi/axi_node/axi_AR_allocator.sv \
    $IPS/axi/axi_node/axi_ArbitrationTree.sv \
    $IPS/axi/axi_node/axi_AW_allocator.sv \
    $IPS/axi/axi_node/axi_BR_allocator.sv \
    $IPS/axi/axi_node/axi_BW_allocator.sv \
    $IPS/axi/axi_node/axi_DW_allocator.sv \
    $IPS/axi/axi_node/axi_FanInPrimitive_Req.sv \
    $IPS/axi/axi_node/axi_multiplexer.sv \
    $IPS/axi/axi_node/axi_node.sv \
    $IPS/axi/axi_node/axi_node_wrap.sv \
    $IPS/axi/axi_node/axi_node_wrap_with_slices.sv \
    $IPS/axi/axi_node/axi_regs_top.sv \
    $IPS/axi/axi_node/axi_request_block.sv \
    $IPS/axi/axi_node/axi_response_block.sv \
    $IPS/axi/axi_node/axi_RR_Flag_Req.sv \
"
set INC_AXI_NODE " \
    $IPS/axi/axi_node/. \
"

# axi_slice
set SRC_AXI_SLICE " \
    $IPS/axi/axi_slice/axi_ar_buffer.sv \
    $IPS/axi/axi_slice/axi_aw_buffer.sv \
    $IPS/axi/axi_slice/axi_b_buffer.sv \
    $IPS/axi/axi_slice/axi_buffer.sv \
    $IPS/axi/axi_slice/axi_r_buffer.sv \
    $IPS/axi/axi_slice/axi_slice.sv \
    $IPS/axi/axi_slice/axi_w_buffer.sv \
    $IPS/axi/axi_slice/axi_slice_wrap.sv \
"

# axi_slice_dc
set SRC_AXI_SLICE_DC " \
    $IPS/axi/axi_slice_dc/axi_slice_dc_master.sv \
    $IPS/axi/axi_slice_dc/axi_slice_dc_slave.sv \
    $IPS/axi/axi_slice_dc/dc_data_buffer.sv \
    $IPS/axi/axi_slice_dc/dc_full_detector.v \
    $IPS/axi/axi_slice_dc/dc_synchronizer.v \
    $IPS/axi/axi_slice_dc/dc_token_ring_fifo_din.v \
    $IPS/axi/axi_slice_dc/dc_token_ring_fifo_dout.v \
    $IPS/axi/axi_slice_dc/dc_token_ring.v \
    $IPS/axi/axi_slice_dc/axi_slice_dc_master_wrap.sv \
    $IPS/axi/axi_slice_dc/axi_slice_dc_slave_wrap.sv \
    $IPS/axi/axi_slice_dc/axi_cdc.sv \
"

# timer_unit
set SRC_TIMER_UNIT " \
    $IPS/timer_unit/timer_unit.sv \
    $IPS/timer_unit/timer_unit_counter.sv \
    $IPS/timer_unit/timer_unit_counter_presc.sv \
"

# common_cells_all
set SRC_COMMON_CELLS_ALL " \
	$IPS/common_cells/src/cdc_2phase.sv \
	$IPS/common_cells/src/cdc_fifo_2phase.sv \
	$IPS/common_cells/src/cdc_fifo_gray.sv \
	$IPS/common_cells/src/clk_div.sv \
	$IPS/common_cells/src/counter.sv \
	$IPS/common_cells/src/edge_detect.sv \
	$IPS/common_cells/src/edge_propagator_rx.sv \
	$IPS/common_cells/src/edge_propagator.sv \
	$IPS/common_cells/src/edge_propagator_tx.sv \
	$IPS/common_cells/src/fall_through_register.sv \
	$IPS/common_cells/src/fifo_v1.sv \
	$IPS/common_cells/src/fifo_v2.sv \
	$IPS/common_cells/src/fifo_v3.sv \
	$IPS/common_cells/src/graycode.sv \
	$IPS/common_cells/src/id_queue.sv \
	$IPS/common_cells/src/lfsr_16bit.sv \
	$IPS/common_cells/src/lfsr_8bit.sv \
	$IPS/common_cells/src/lzc.sv \
	$IPS/common_cells/src/mv_filter.sv \
	$IPS/common_cells/src/onehot_to_bin.sv \
	$IPS/common_cells/src/popcount.sv \
	$IPS/common_cells/src/rrarbiter.sv \
	$IPS/common_cells/src/rstgen_bypass.sv \
	$IPS/common_cells/src/rstgen.sv \
	$IPS/common_cells/src/serial_deglitch.sv \
	$IPS/common_cells/src/shift_reg.sv \
	$IPS/common_cells/src/spill_register.sv \
	$IPS/common_cells/src/sram.sv \
	$IPS/common_cells/src/stream_arbiter_flushable.sv \
	$IPS/common_cells/src/stream_arbiter.sv \
	$IPS/common_cells/src/stream_delay.sv \
	$IPS/common_cells/src/stream_demux.sv \
	$IPS/common_cells/src/stream_filter.sv \
	$IPS/common_cells/src/stream_fork.sv \
	$IPS/common_cells/src/stream_mux.sv \
	$IPS/common_cells/src/stream_register.sv \
	$IPS/common_cells/src/sync.sv \
	$IPS/common_cells/src/sync_wedge.sv \
	$IPS/common_cells/src/unread.sv \
	$IPS/common_cells/src/deprecated/generic_fifo.sv \
	$IPS/common_cells/src/deprecated/pulp_sync_wedge.sv \
	$IPS/common_cells/src/deprecated/clock_divider_counter.sv \
	$IPS/common_cells/src/deprecated/clock_divider.sv \
	$IPS/common_cells/src/deprecated/find_first_one.sv \
	$IPS/common_cells/src/deprecated/generic_fifo_adv.sv \
	$IPS/common_cells/src/deprecated/generic_fifo.sv \
	$IPS/common_cells/src/deprecated/generic_LFSR_8bit.sv \
	$IPS/common_cells/src/deprecated/pulp_sync.sv \
"

# fpu
set SRC_FPU_NEW " \
	$IPS//common_cells/include/common_cells/registers.svh \
	$IPS/fpnew/src/fpnew_pkg.sv \
	$IPS/fpnew/src/fpnew_cast_multi.sv \
	$IPS/fpnew/src/fpnew_classifier.sv \
	$IPS/fpnew/src/fpnew_divsqrt_multi.sv \
	$IPS/fpnew/src/fpnew_f2fcast.sv \
	$IPS/fpnew/src/fpnew_f2icast.sv \
	$IPS/fpnew/src/fpnew_fma_multi.sv \
	$IPS/fpnew/src/fpnew_fma.sv \
	$IPS/fpnew/src/fpnew_i2fcast.sv \
	$IPS/fpnew/src/fpnew_noncomp.sv \
	$IPS/fpnew/src/fpnew_opgroup_block.sv \
	$IPS/fpnew/src/fpnew_opgroup_fmt_slice.sv \
	$IPS/fpnew/src/fpnew_opgroup_multifmt_slice.sv \
	$IPS/fpnew/src/fpnew_pipe_in.sv \
	$IPS/fpnew/src/fpnew_pipe_out.sv \
	$IPS/fpnew/src/fpnew_rounding.sv \
	$IPS/fpnew/src/fpnew_top.sv \   
"

set SRC_FPU_DIV_SQRT_MVP " \
	$IPS/fpu_div_sqrt_mvp/hdl/defs_div_sqrt_mvp.sv \
	$IPS/fpu_div_sqrt_mvp/hdl/control_mvp.sv \
	$IPS/fpu_div_sqrt_mvp/hdl/div_sqrt_mvp_wrapper.sv \
	$IPS/fpu_div_sqrt_mvp/hdl/div_sqrt_top_mvp.sv \
	$IPS/fpu_div_sqrt_mvp/hdl/iteration_div_sqrt_mvp.sv \
	$IPS/fpu_div_sqrt_mvp/hdl/norm_div_sqrt_mvp.sv \
	$IPS/fpu_div_sqrt_mvp/hdl/nrbd_nrsc_mvp.sv \
	$IPS/fpu_div_sqrt_mvp/hdl/preprocess_mvp.sv \
"

set INC_FPU " \
    $IPS/fpnew/. \
    $IPS/fpu_div_sqrt_mvp/ \
"

# jtag_pulp
set SRC_JTAG_PULP " \
    $IPS/jtag_pulp/src/bscell.sv \
    $IPS/jtag_pulp/src/jtag_axi_wrap.sv \
    $IPS/jtag_pulp/src/jtag_enable.sv \
    $IPS/jtag_pulp/src/jtag_enable_synch.sv \
    $IPS/jtag_pulp/src/jtagreg.sv \
    $IPS/jtag_pulp/src/jtag_rst_synch.sv \
    $IPS/jtag_pulp/src/jtag_sync.sv \
    $IPS/jtag_pulp/src/tap_top.v \
"
set INC_JTAG_PULP " \
    $IPS/jtag_pulp/../../rtl/includes \
"

# riscv
set SRC_RISCV " \
	$IPS/riscv/rtl/include/apu_core_package.sv \
	$IPS/riscv/rtl/include/riscv_defines.sv \
	$IPS/riscv/rtl/include/riscv_tracer_defines.sv \
	$IPS/riscv/rtl/register_file_test_wrap.sv \
	$IPS/riscv/rtl/riscv_alu_basic.sv \
	$IPS/riscv/rtl/riscv_alu_div.sv \
	$IPS/riscv/rtl/riscv_alu.sv \
	$IPS/riscv/rtl/riscv_apu_disp.sv \
	$IPS/riscv/rtl/riscv_compressed_decoder.sv \
	$IPS/riscv/rtl/riscv_controller.sv \
	$IPS/riscv/rtl/riscv_core.sv \
	$IPS/riscv/rtl/riscv_cs_registers.sv \
	$IPS/riscv/rtl/riscv_decoder.sv \
	$IPS/riscv/rtl/riscv_ex_stage.sv \
	$IPS/riscv/rtl/riscv_fetch_fifo.sv \
	$IPS/riscv/rtl/riscv_hwloop_controller.sv \
	$IPS/riscv/rtl/riscv_hwloop_regs.sv \
	$IPS/riscv/rtl/riscv_id_stage.sv \
	$IPS/riscv/rtl/riscv_if_stage.sv \
	$IPS/riscv/rtl/riscv_int_controller.sv \
	$IPS/riscv/rtl/riscv_L0_buffer.sv \
	$IPS/riscv/rtl/riscv_load_store_unit.sv \
	$IPS/riscv/rtl/riscv_mult.sv \
	$IPS/riscv/rtl/riscv_pmp.sv \
	$IPS/riscv/rtl/riscv_prefetch_buffer.sv \
	$IPS/riscv/rtl/riscv_prefetch_L0_buffer.sv \
	$IPS/riscv/rtl/riscv_register_file_latch.sv \
	$IPS/riscv/rtl/riscv_register_file.sv \
"
set INC_RISCV " \
    $IPS/riscv/rtl/include \
    $IPS/riscv/../../rtl/includes \
"

set SRC_RISCV_DBG " \
	$IPS/riscv-dbg/src/dm_pkg.sv \
	$IPS/riscv-dbg/debug_rom/debug_rom.sv \
	$IPS/riscv-dbg/src/dm_csrs.sv \
	$IPS/riscv-dbg/src/dmi_cdc.sv \
	$IPS/riscv-dbg/src/dmi_jtag.sv \
	$IPS/riscv-dbg/src/dmi_jtag_tap.sv \
	$IPS/riscv-dbg/src/dm_mem.sv \
	$IPS/riscv-dbg/src/dm_sba.sv \
	$IPS/riscv-dbg/src/dm_top.sv \
"


# riscv_regfile_fpga
set SRC_RISCV_REGFILE_FPGA " \
    $IPS/riscv/rtl/riscv_register_file.sv \
"
#set INC_RISCV_REGFILE_FPGA " \
#    $IPS/riscv/rtl/include \
#"

# zeroriscy
set SRC_ZERORISCY " \
	$IPS/zero-riscy/include/zeroriscy_defines.sv \
    $IPS/zero-riscy/include/zeroriscy_tracer_defines.sv \
	$IPS/zero-riscy/zeroriscy_alu.sv \
	$IPS/zero-riscy/zeroriscy_compressed_decoder.sv \
	$IPS/zero-riscy/zeroriscy_controller.sv \
	$IPS/zero-riscy/zeroriscy_cs_registers.sv \
	$IPS/zero-riscy/zeroriscy_debug_unit.sv \
	$IPS/zero-riscy/zeroriscy_decoder.sv \
	$IPS/zero-riscy/zeroriscy_int_controller.sv \
	$IPS/zero-riscy/zeroriscy_ex_block.sv \
	$IPS/zero-riscy/zeroriscy_id_stage.sv \
	$IPS/zero-riscy/zeroriscy_if_stage.sv \
	$IPS/zero-riscy/zeroriscy_load_store_unit.sv \
	$IPS/zero-riscy/zeroriscy_multdiv_fast.sv \
	$IPS/zero-riscy/zeroriscy_multdiv_slow.sv \
	$IPS/zero-riscy/zeroriscy_prefetch_buffer.sv \
	$IPS/zero-riscy/zeroriscy_fetch_fifo.sv \
	$IPS/zero-riscy/zeroriscy_core.sv \
"
set INC_ZERORISCY " \
    $IPS/zero-riscy/include \
"



# zeroriscy_regfile_fpga
set SRC_ZERORISCY_REGFILE_FPGA " \
    $IPS/zero-riscy/zeroriscy_register_file_ff.sv \
"
set INC_ZERORISCY_REGFILE_FPGA " \
    $IPS/zero-riscy/include \
"


# scm_fpga
set SRC_SCM_FPGA " \
	$IPS/scm/fpga_scm/register_file_1r_1w_1row.sv \
	$IPS/scm/fpga_scm/register_file_1r_1w_all.sv \
	$IPS/scm/fpga_scm/register_file_1r_1w_be.sv \
	$IPS/scm/fpga_scm/register_file_1r_1w_raw.sv \
	$IPS/scm/fpga_scm/register_file_1r_1w.sv \
	$IPS/scm/fpga_scm/register_file_1w_64b_1r_32b.sv \
	$IPS/scm/fpga_scm/register_file_1w_64b_multi_port_read_32b.sv \
	$IPS/scm/fpga_scm/register_file_1w_multi_port_read.sv \
	$IPS/scm/fpga_scm/register_file_2r_1w_asymm.sv \
	$IPS/scm/fpga_scm/register_file_2r_1w_asymm_test_wrap.sv \
	$IPS/scm/fpga_scm/register_file_2r_2w.sv \
	$IPS/scm/fpga_scm/register_file_3r_2w.sv \
"



# tech_cells_fpga
set SRC_TECH_CELLS_FPGA " \
	$IPS/tech_cells_generic/cluster_clock_and2.sv \
	$IPS/tech_cells_generic/cluster_clock_buffer.sv \
	$IPS/tech_cells_generic/cluster_clock_gating.sv \
	$IPS/tech_cells_generic/cluster_clock_gating_xilinx.sv \
	$IPS/tech_cells_generic/cluster_clock_inverter.sv \
	$IPS/tech_cells_generic/cluster_clock_mux2.sv \
	$IPS/tech_cells_generic/cluster_clock_xor2.sv \
	$IPS/tech_cells_generic/cluster_level_shifter_in_clamp.sv \
	$IPS/tech_cells_generic/cluster_level_shifter_in.sv \
	$IPS/tech_cells_generic/cluster_level_shifter_out_clamp.sv \
	$IPS/tech_cells_generic/cluster_level_shifter_out.sv \
	$IPS/tech_cells_generic/generic_memory.sv \
	$IPS/tech_cells_generic/generic_rom.sv \
	$IPS/tech_cells_generic/pad_functional.sv \
	$IPS/tech_cells_generic/pulp_buffer.sv \
	$IPS/tech_cells_generic/pulp_clock_and2.sv \
	$IPS/tech_cells_generic/pulp_clock_buffer.sv \
	$IPS/tech_cells_generic/pulp_clock_gating_async.sv \
	$IPS/tech_cells_generic/pulp_clock_gating.sv \
	$IPS/tech_cells_generic/pulp_clock_gating_xilinx.sv \
	$IPS/tech_cells_generic/pulp_clock_inverter.sv \
	$IPS/tech_cells_generic/pulp_clock_mux2.sv \
	$IPS/tech_cells_generic/pulp_clock_mux2_xilinx.sv \
	$IPS/tech_cells_generic/pulp_clock_xor2.sv \
	$IPS/tech_cells_generic/pulp_level_shifter_in_clamp.sv \
	$IPS/tech_cells_generic/pulp_level_shifter_in.sv \
	$IPS/tech_cells_generic/pulp_level_shifter_out_clamp.sv \
	$IPS/tech_cells_generic/pulp_level_shifter_out.sv \
	$IPS/tech_cells_generic/pulp_power_gating.sv \
"

# udma_core
set SRC_UDMA_CORE " \
	$IPS/udma/udma_core/rtl/core/udma_arbiter.sv \
	$IPS/udma/udma_core/rtl/core/udma_ch_addrgen.sv \
	$IPS/udma/udma_core/rtl/core/udma_core.sv \
	$IPS/udma/udma_core/rtl/core/udma_rx_channels.sv \
	$IPS/udma/udma_core/rtl/core/udma_stream_unit.sv \
	$IPS/udma/udma_core/rtl/core/udma_tx_channels.sv \
	$IPS/udma/udma_core/rtl/common/io_clk_gen.sv \
	$IPS/udma/udma_core/rtl/common/io_event_counter.sv \
	$IPS/udma/udma_core/rtl/common/io_generic_fifo.sv \
	$IPS/udma/udma_core/rtl/common/io_shiftreg.sv \
	$IPS/udma/udma_core/rtl/common/io_tx_fifo_dc.sv \
	$IPS/udma/udma_core/rtl/common/io_tx_fifo_mark.sv \
	$IPS/udma/udma_core/rtl/common/io_tx_fifo.sv \
	$IPS/udma/udma_core/rtl/common/udma_apb_if.sv \
	$IPS/udma/udma_core/rtl/common/udma_clk_div_cnt.sv \
	$IPS/udma/udma_core/rtl/common/udma_clkgen.sv \
	$IPS/udma/udma_core/rtl/common/udma_ctrl.sv \
	$IPS/udma/udma_core/rtl/common/udma_dc_fifo.sv \
"

# udma_uart
set SRC_UDMA_UART " \
    $IPS/udma/udma_uart/rtl/udma_uart_reg_if.sv \
    $IPS/udma/udma_uart/rtl/udma_uart_top.sv \
    $IPS/udma/udma_uart/rtl/udma_uart_rx.sv \
    $IPS/udma/udma_uart/rtl/udma_uart_tx.sv \
"

# udma_i2c
set SRC_UDMA_I2C " \
    $IPS/udma/udma_i2c/rtl/udma_i2c_reg_if.sv \
    $IPS/udma/udma_i2c/rtl/udma_i2c_bus_ctrl.sv \
    $IPS/udma/udma_i2c/rtl/udma_i2c_control.sv \
    $IPS/udma/udma_i2c/rtl/udma_i2c_top.sv \
"

# udma_i2s
set SRC_UDMA_I2S " \
	$IPS/udma/udma_i2s/rtl/cic_comb.sv \
	$IPS/udma/udma_i2s/rtl/cic_integrator.sv \
	$IPS/udma/udma_i2s/rtl/cic_top.sv \
	$IPS/udma/udma_i2s/rtl/i2s_clk_gen.sv \
	$IPS/udma/udma_i2s/rtl/i2s_clkws_gen.sv \
	$IPS/udma/udma_i2s/rtl/i2s_rx_channel.sv \
	$IPS/udma/udma_i2s/rtl/i2s_tx_channel.sv \
	$IPS/udma/udma_i2s/rtl/i2s_txrx.sv \
	$IPS/udma/udma_i2s/rtl/i2s_ws_gen.sv \
	$IPS/udma/udma_i2s/rtl/pdm_top.sv \
	$IPS/udma/udma_i2s/rtl/udma_i2s_reg_if.sv \
	$IPS/udma/udma_i2s/rtl/udma_i2s_top.sv \
"

# udma_qspi
set SRC_UDMA_QSPI " \
	$IPS/udma/udma_qspi/rtl/udma_spim_clk_div_cnt.sv \
	$IPS/udma/udma_qspi/rtl/udma_spim_clkgen.sv \
	$IPS/udma/udma_qspi/rtl/udma_spim_ctrl.sv \
	$IPS/udma/udma_qspi/rtl/udma_spim_defines.sv \
	$IPS/udma/udma_qspi/rtl/udma_spim_reg_if.sv \
	$IPS/udma/udma_qspi/rtl/udma_spim_top.sv \
	$IPS/udma/udma_qspi/rtl/udma_spim_txrx.sv \
"

# udma_sdio
set SRC_UDMA_SDIO " \
    $IPS/udma/udma_sdio/rtl/sdio_crc7.sv \
    $IPS/udma/udma_sdio/rtl/sdio_crc16.sv \
    $IPS/udma/udma_sdio/rtl/sdio_txrx_cmd.sv \
    $IPS/udma/udma_sdio/rtl/sdio_txrx_data.sv \
    $IPS/udma/udma_sdio/rtl/sdio_txrx.sv \
    $IPS/udma/udma_sdio/rtl/udma_sdio_reg_if.sv \
    $IPS/udma/udma_sdio/rtl/udma_sdio_top.sv \
"

# udma_camera
set SRC_UDMA_CAMERA " \
    $IPS/udma/udma_camera/rtl/camera_reg_if.sv \
    $IPS/udma/udma_camera/rtl/camera_if.sv \
"

# udma_external_per
set SRC_UDMA_EXTERNAL_PER " \
	$IPS/udma/udma_external_per/rtl/udma_external_per_reg_if.sv \
	$IPS/udma/udma_external_per/rtl/udma_external_per_top.sv \
	$IPS/udma/udma_external_per/rtl/udma_external_per_wrapper.sv \
	$IPS/udma/udma_external_per/rtl/udma_traffic_gen_rx.sv \
	$IPS/udma/udma_external_per/rtl/udma_traffic_gen_tx.sv \
"

# udma_filter
set SRC_UDMA_FILTER " \
	$IPS/udma/udma_filter/rtl/udma_filter_au.sv \
	$IPS/udma/udma_filter/rtl/udma_filter_bincu.sv \
	$IPS/udma/udma_filter/rtl/udma_filter_reg_if.sv \
	$IPS/udma/udma_filter/rtl/udma_filter_rx_dataout.sv \
	$IPS/udma/udma_filter/rtl/udma_filter.sv \
	$IPS/udma/udma_filter/rtl/udma_filter_tx_datafetch.sv \
"
# hwpe-ctrl
set SRC_HWPE_CTRL " \
    $IPS/hwpe-ctrl/rtl/hwpe_ctrl_package.sv \
    $IPS/hwpe-ctrl/rtl/hwpe_ctrl_interfaces.sv \
    $IPS/hwpe-ctrl/rtl/hwpe_ctrl_regfile.sv \
    $IPS/hwpe-ctrl/rtl/hwpe_ctrl_regfile_latch.sv \
    $IPS/hwpe-ctrl/rtl/hwpe_ctrl_slave.sv \
    $IPS/hwpe-ctrl/rtl/hwpe_ctrl_seq_mult.sv \
    $IPS/hwpe-ctrl/rtl/hwpe_ctrl_ucode.sv \
"
set INC_HWPE_CTRL " \
    $IPS/hwpe-ctrl/rtl \
"


# hwpe-stream
set SRC_HWPE_STREAM " \
	$IPS/hwpe-stream/rtl/hwpe_stream_package.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_addressgen.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_buffer.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_demux_static.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_fence.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_fifo_earlystall_sidech.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_fifo_earlystall.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_fifo_scm.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_fifo_sidech.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_fifo.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_interfaces.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_merge.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_mux_static.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_sink_realign.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_sink.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_source_realign.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_source.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_split.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_tcdm_fifo_load_sidech.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_tcdm_fifo_load.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_tcdm_fifo_store.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_tcdm_mux_static.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_tcdm_mux.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_tcdm_reorder_static.sv \
	$IPS/hwpe-stream/rtl/hwpe_stream_tcdm_reorder.sv \
"
set INC_HWPE_STREAM " \
    $IPS/hwpe-stream/rtl \
"



# hw-mac-engine
set SRC_HW_MAC_ENGINE " \
    $IPS/hwpe-mac-engine/rtl/mac_package.sv \
    $IPS/hwpe-mac-engine/rtl/mac_fsm.sv \
    $IPS/hwpe-mac-engine/rtl/mac_ctrl.sv \
    $IPS/hwpe-mac-engine/rtl/mac_streamer.sv \
    $IPS/hwpe-mac-engine/rtl/mac_engine.sv \
    $IPS/hwpe-mac-engine/rtl/mac_top.sv \
    $IPS/hwpe-mac-engine/wrap/mac_top_wrap.sv \
"
set INC_HW_MAC_ENGINE " \
    $IPS/hwpe-mac-engine/rtl \
"

# pulp_soc
set SRC_PULP_SOC " \
    $IPS/pulp_soc/rtl/pulp_soc/soc_interconnect.sv \
    $IPS/pulp_soc/rtl/pulp_soc/boot_rom.sv \
    $IPS/pulp_soc/rtl/pulp_soc/l2_ram_multi_bank.sv \
    $IPS/pulp_soc/rtl/pulp_soc/lint_jtag_wrap.sv \
    $IPS/pulp_soc/rtl/pulp_soc/periph_bus_wrap.sv \
    $IPS/pulp_soc/rtl/pulp_soc/soc_clk_rst_gen.sv \
    $IPS/pulp_soc/rtl/pulp_soc/soc_event_arbiter.sv \
    $IPS/pulp_soc/rtl/pulp_soc/soc_event_generator.sv \
    $IPS/pulp_soc/rtl/pulp_soc/soc_event_queue.sv \
    $IPS/pulp_soc/rtl/pulp_soc/soc_interconnect_wrap.sv \
    $IPS/pulp_soc/rtl/pulp_soc/soc_peripherals.sv \
    $IPS/pulp_soc/rtl/pulp_soc/pulp_soc.sv \
"
set INC_PULP_SOC " \
    $IPS/pulp_soc/../../rtl/includes \
"

# udma_subsystem
set SRC_UDMA_SUBSYSTEM " \
    $IPS/pulp_soc/rtl/udma_subsystem/udma_subsystem.sv \
"
set INC_UDMA_SUBSYSTEM " \
    $IPS/pulp_soc/../../rtl/includes \
    $IPS/pulp_soc/. \
"

# fc
set SRC_FC " \
    $IPS/pulp_soc/rtl/fc/fc_demux.sv \
    $IPS/pulp_soc/rtl/fc/fc_subsystem.sv \
    $IPS/pulp_soc/rtl/fc/fc_hwpe.sv \
"
set INC_FC " \
    $IPS/pulp_soc/../../rtl/includes \
    $IPS/pulp_soc/. \
"

# components
set SRC_COMPONENTS " \
$IPS/pulp_soc/rtl/components/apb_clkdiv.sv \
$IPS/pulp_soc/rtl/components/apb_dummy.sv \
$IPS/pulp_soc/rtl/components/apb_soc_ctrl.sv \
$IPS/pulp_soc/rtl/components/apb_timer_unit.sv \
$IPS/pulp_soc/rtl/components/axi_slice_dc_master_wrap.sv \
$IPS/pulp_soc/rtl/components/axi_slice_dc_slave_wrap.sv \
$IPS/pulp_soc/rtl/components/freq_meter.sv \
$IPS/pulp_soc/rtl/components/glitch_free_clk_mux.sv \
$IPS/pulp_soc/rtl/components/glitch_free_clk_mux_xilinx.sv \
$IPS/pulp_soc/rtl/components/memory_models.sv \
$IPS/pulp_soc/rtl/components/pulp_interfaces.sv \
$IPS/pulp_soc/rtl/components/scm_2048x32.sv \
$IPS/pulp_soc/rtl/components/scm_512x32.sv \
$IPS/pulp_soc/rtl/components/tcdm_arbiter_2x1.sv \
"
set INC_COMPONENTS " \
    $IPS/pulp_soc/../../rtl/includes \
"


