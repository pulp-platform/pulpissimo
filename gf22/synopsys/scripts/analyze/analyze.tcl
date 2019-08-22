source ./scripts/analyze/analyze_riscv.tcl
# source ./scripts/analyze/analyze_apb.tcl
# source ./scripts/analyze/analyze_pulpino.tcl
# source ./scripts/analyze/analyze_adv_debug_if.tcl
# source ./scripts/analyze/analyze_axi.tcl


analyze -format sverilog  -work work $RISCV_PATH/riscv_pmp.sv
analyze -format sverilog  -work work $RISCV_PATH/register_file_test_wrap.sv
analyze -format sverilog  -work work $RISCV_PATH/riscv_fetch_fifo.sv
analyze -format sverilog  -work work $IPS_PATH/common_cells/src/rr_arb_tree.sv
analyze -format sverilog  -work work $IPS_PATH/common_cells/src/lzc.sv
