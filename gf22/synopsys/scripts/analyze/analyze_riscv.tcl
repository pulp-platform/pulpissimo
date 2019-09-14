set search_path [ join "$RISCV_PATH/include $search_path" ]

#fp_new
analyze -format sverilog -work work [list                          \
    $IPS_PATH/common_cells/include/common_cells/registers.svh      \
    $RISCV_PATH/../../fpnew/src/fpnew_pkg.sv                       \
    $RISCV_PATH/../../fpnew/src/fpnew_cast_multi.sv                \
    $RISCV_PATH/../../fpnew/src/fpnew_classifier.sv                \
    $RISCV_PATH/../../fpnew/src/fpnew_divsqrt_multi.sv             \
    $RISCV_PATH/../../fpnew/src/fpnew_fma.sv                       \
    $RISCV_PATH/../../fpnew/src/fpnew_fma_multi.sv                 \
    $RISCV_PATH/../../fpnew/src/fpnew_noncomp.sv                   \
    $RISCV_PATH/../../fpnew/src/fpnew_opgroup_block.sv             \
    $RISCV_PATH/../../fpnew/src/fpnew_opgroup_fmt_slice.sv         \
    $RISCV_PATH/../../fpnew/src/fpnew_opgroup_multifmt_slice.sv    \
    $RISCV_PATH/../../fpnew/src/fpnew_pipe_in.sv                   \
    $RISCV_PATH/../../fpnew/src/fpnew_pipe_out.sv                  \
    $RISCV_PATH/../../fpnew/src/fpnew_pipe_inside_fma.sv           \
    $RISCV_PATH/../../fpnew/src/fpnew_pipe_inside_cast.sv          \
    $RISCV_PATH/../../fpnew/src/fpnew_rounding.sv                  \
    $RISCV_PATH/../../fpnew/src/fpnew_top.sv                       \
    ]  


analyze -format sverilog -work work [list                           \
                            $RISCV_PATH/include/apu_core_package.sv \
                            $RISCV_PATH/include/riscv_defines.sv    \
                            $RISCV_PATH/riscv_prefetch_buffer.sv          \
                            $RISCV_PATH/riscv_mult.sv                     \
                            $RISCV_PATH/riscv_load_store_unit.sv          \
                            $RISCV_PATH/riscv_if_stage.sv                 \
                            $RISCV_PATH/riscv_id_stage.sv                 \
                            $RISCV_PATH/riscv_hwloop_regs.sv              \
                            $RISCV_PATH/riscv_hwloop_controller.sv        \
                            $RISCV_PATH/riscv_int_controller.sv           \
                            $RISCV_PATH/riscv_ex_stage.sv                 \
                            $RISCV_PATH/riscv_decoder.sv                  \
                            $RISCV_PATH/riscv_cs_registers.sv             \
                            $RISCV_PATH/riscv_controller.sv               \
                            $RISCV_PATH/riscv_compressed_decoder.sv       \
                            $RISCV_PATH/riscv_alu.sv                      \
                            $RISCV_PATH/riscv_alu_div.sv                  \
                            $RISCV_PATH/riscv_apu_disp.sv                 \
                            ]

                            # $RISCV_PATH/riscv_debug_unit.sv               \                            
                            # $RISCV_PATH/riscv_alu_basic.sv                \
                            # 
analyze -format sverilog -work work $RISCV_PATH/riscv_core.sv               

analyze -format sverilog -work work ../sourcecode/cluster_clock_gating_gf22.sv
if { [string is true -strict $CORE_LATCH_RF] } {
  analyze -format sverilog -work work $RISCV_PATH/riscv_register_file_latch.sv
} else {
  analyze -format sverilog -work work $RISCV_PATH/riscv_register_file.sv
}
