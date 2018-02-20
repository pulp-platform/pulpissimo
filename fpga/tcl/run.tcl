# create project
create_project -force pulpissimo . -part xc7a35ticsg324-1L
set_property board_part digilentinc.com:arty:part0:1.1 [current_project]

# source tcl/ips_inc_dirs.tcl
# set_property include_dirs $INCLUDE_DIRS [current_fileset]
# set INCLUDE_DIRS_IPS $INCLUDE_DIRS
# source tcl/rtl_inc_dirs.tcl
set INCLUDE_DIRS [list \
	../rtl/includes \
	../ips/riscv/include \
	../ips/zero-riscy/include \
	../ips/pulp_soc/rtl/includes \
]
set_property include_dirs $INCLUDE_DIRS [current_fileset]

# set up meaningful errors
source tcl/messages.tcl

# setup source files for IPs, RTL
set IPS ../ips
source tcl/ips_src_files.tcl
source tcl/ips_add_files.tcl
set IPS ../rtl
source tcl/rtl_src_files.tcl
source tcl/rtl_add_files.tcl

# add constraints
add_files -fileset constrs_1 -norecurse /scratch/fconti/pulpissimo/fpga/tcl/io.xdc
add_files -fileset constrs_1 -norecurse /scratch/fconti/pulpissimo/fpga/tcl/constraints.xdc

# set pulpissimo as top
set_property top pulpissimo [current_fileset]
set_property source_mgmt_mode None [current_project]

# elaborate design
synth_design -rtl -name rtl_1 -verilog_define PULP_FPGA_EMUL=1 -generic CORE_TYPE=1 -generic USE_FPU=0 -generic USE_HWPE=0

# run synthesis
set_property STEPS.SYNTH_DESIGN.ARGS.FLATTEN_HIERARCHY none [get_runs synth_1]
#+ set_property STEPS.SYNTH_DESIGN.ARGS.GATED_CLOCK_CONVERSION on [get_runs synth_1]
#set_property -name {STEPS.SYNTH_DESIGN.ARGS.MORE OPTIONS} -value {-mode out_of_context} -objects [get_runs synth_1]
launch_runs synth_1 -jobs 8
wait_on_run synth_1
open_run synth_1

launch_runs impl_1 -jobs 8
