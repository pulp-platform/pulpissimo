# create project
create_project pulpissimo . -part xc7a35ticsg324-1L
operty board_part digilentinc.com:arty:part0:1.1 [current_project]
# create_project pulpissimo . -force -part $::env(XILINX_PART)
# set_property board_part $::env(XILINX_BOARD) [current_project]

source tcl/ips_inc_dirs.tcl
set_property include_dirs $INCLUDE_DIRS [current_fileset]
set INCLUDE_DIRS_IPS $INCLUDE_DIRS
source tcl/rtl_inc_dirs.tcl
set_property include_dirs [list $INCLUDE_DIRS_IPS $INCLUDE_DIRS] [current_fileset]

# set up meaningful errors
# source tcl/messages.tcl

# setup source files for IPs, RTL
set IPS ../ips
source tcl/ips_src_files.tcl
source tcl/ips_add_files.tcl
set IPS ../rtl
source tcl/rtl_src_files.tcl
source tcl/rtl_add_files.tcl

# set pulpissimo as top
set_property top pulpissimo [current_fileset]

# add memory cuts
#read_ip $FPGA_IPS/xilinx_ic_ram_128x32/ip/xilinx_ic_ram_128x32.xci
#+ read_ip $FPGA_IPS/xilinx_tcdm_bank_2048x32/ip/xilinx_tcdm_bank_2048x32.xci
read_ip $FPGA_IPS/xilinx_tcdm_bank_1024x32/ip/xilinx_tcdm_bank_1024x32.xci
#+ read_ip $FPGA_IPS/xilinx_tcdm_bank_512x32/ip/xilinx_tcdm_bank_512x32.xci
#+ read_ip $FPGA_IPS/xilinx_tcdm_bank_256x32/ip/xilinx_tcdm_bank_256x32.xci
#+ read_ip $FPGA_IPS/xilinx_tcdm_bank_128x32/ip/xilinx_tcdm_bank_128x32.xci
read_ip $FPGA_IPS/xilinx_icache_bank_data_16x128/ip/xilinx_icache_bank_data_16x128.xci 
read_ip $FPGA_IPS/xilinx_icache_bank_tag_16x8/ip/xilinx_icache_bank_tag_16x8.xci 
#synth_ip [get_ips xilinx_ic_ram_128x32]
#+ synth_ip [get_ips xilinx_tcdm_bank_2048x32]
synth_ip [get_ips xilinx_tcdm_bank_1024x32]
#+ synth_ip [get_ips xilinx_tcdm_bank_512x32]
#+ synth_ip [get_ips xilinx_tcdm_bank_256x32]
#+ synth_ip [get_ips xilinx_tcdm_bank_128x32]
synth_ip [get_ips xilinx_icache_bank_data_16x128]
synth_ip [get_ips xilinx_icache_bank_tag_16x8]

# add ulpcluster
add_files -norecurse -scan_for_includes $SRC_ULPCLUSTER

# set ulpcluster as top
set_property top ulpcluster [current_fileset]

# needed only if used in batch mode
update_compile_order -fileset sources_1
update_compile_order -fileset sim_1

# # add constraints
add_files -fileset constrs_1 -norecurse tcl/constraints.xdc
set_property target_constrs_file tcl/constraints.xdc [current_fileset -constrset]
# create path groups
#+ add_files -fileset constrs_1 -norecurse tcl/create_path_groups.xdc
#+ set_property target_constrs_file tcl/create_path_groups.xdc [current_fileset -constrset]

# elaborate design
# FIXME find why we need to repeat this command twice to be successfull
catch {synth_design -rtl -name rtl_1 -verilog_define PULP_FPGA_EMUL=1 -verilog_define PERF_COUNTERS=1 -verilog_define RISCV=1}
update_compile_order -fileset sources_1
synth_design -rtl -name rtl_1 -verilog_define PULP_FPGA_EMUL=1 -verilog_define PERF_COUNTERS=1 -verilog_define RISCV=1

# run synthesis
set_property STEPS.SYNTH_DESIGN.ARGS.FLATTEN_HIERARCHY none [get_runs synth_1]
#+ set_property STEPS.SYNTH_DESIGN.ARGS.GATED_CLOCK_CONVERSION on [get_runs synth_1]
#set_property -name {STEPS.SYNTH_DESIGN.ARGS.MORE OPTIONS} -value {-mode out_of_context} -objects [get_runs synth_1]
launch_runs synth_1
wait_on_run synth_1
open_run synth_1

# remove unused ID ports
#+ disconnect_net -objects { data_slave_aw_id[9] data_slave_aw_id[8] data_slave_aw_id[7] data_slave_aw_id[6] data_slave_aw_id[5] data_slave_aw_id[4] }
#+ disconnect_net -objects { data_slave_ar_id[9] data_slave_ar_id[8] data_slave_ar_id[7] data_slave_ar_id[6] data_slave_ar_id[5] data_slave_ar_id[4] }
#+ disconnect_net -objects { data_slave_r_id[9] data_slave_r_id[8] data_slave_r_id[7] data_slave_r_id[6] data_slave_r_id[5] data_slave_r_id[4] }
#+ disconnect_net -objects { data_slave_b_id[9] data_slave_b_id[8] data_slave_b_id[7] data_slave_b_id[6] data_slave_b_id[5] data_slave_b_id[4] }
#+ remove_port { data_slave_aw_id[9] data_slave_aw_id[8] data_slave_aw_id[7] data_slave_aw_id[6] data_slave_aw_id[5] data_slave_aw_id[4] }
#+ remove_port { data_slave_ar_id[9] data_slave_ar_id[8] data_slave_ar_id[7] data_slave_ar_id[6] data_slave_ar_id[5] data_slave_ar_id[4] }
#+ remove_port { data_slave_r_id[9] data_slave_r_id[8] data_slave_r_id[7] data_slave_r_id[6] data_slave_r_id[5] data_slave_r_id[4] }
#+ remove_port { data_slave_b_id[9] data_slave_b_id[8] data_slave_b_id[7] data_slave_b_id[6] data_slave_b_id[5] data_slave_b_id[4] }
#+ disconnect_net -objects { data_master_aw_id[9] data_master_aw_id[8] data_master_aw_id[7] }
#+ disconnect_net -objects { data_master_ar_id[9] data_master_ar_id[8] data_master_ar_id[7] }
#+ disconnect_net -objects { data_master_r_id[9] data_master_r_id[8] data_master_r_id[7] }
#+ disconnect_net -objects { data_master_b_id[9] data_master_b_id[8] data_master_b_id[7] }
#+ remove_port { data_master_aw_id[9] data_master_aw_id[8] data_master_aw_id[7] }
#+ remove_port { data_master_ar_id[9] data_master_ar_id[8] data_master_ar_id[7] }
#+ remove_port { data_master_r_id[9] data_master_r_id[8] data_master_r_id[7] }
#+ remove_port { data_master_b_id[9] data_master_b_id[8] data_master_b_id[7] }

# save EDIF netlist
write_edif -force ulpcluster.edf
write_verilog -force -mode synth_stub ulpcluster_stub.v
write_verilog -force -mode funcsim ulpcluster_funcsim.v

# reports
exec mkdir -p reports/
exec rm -rf reports/*
check_timing                                                            -file reports/ulpcluster.check_timing.rpt 
report_timing -max_paths 100 -nworst 100 -delay_type max -sort_by slack -file reports/ulpcluster.timing_WORST_100.rpt
report_timing -nworst 1 -delay_type max -sort_by group                  -file reports/ulpcluster.timing.rpt
report_utilization -hierarchical                                        -file reports/ulpcluster.utilization.rpt
