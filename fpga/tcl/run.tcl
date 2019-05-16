# create project

# artix:
#create_project -force pulpissimo . -part xc7a35ticsg324-1L
#set_property board_part digilentinc.com:arty:part0:1.1 [current_project]

# genesys 2:
create_project -force pulpissimo_genesys2 . -part xc7k325tffg900-2
set_property board_part digilentinc.com:genesys2:part0:1.1 [current_project]



set dircorr [pwd]
puts $dircorr
puts ciao

set INCLUDE_DIRS [list \
	../rtl/includes \
	../ips/riscv/rtl/include \
	../ips/common_cells/include/common_cells \
	../ips/zero-riscy/include \
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
add_files -fileset constrs_1 -norecurse tcl/io_genesys2.xdc
#TODO constraints_genesys2:
#add_files -fileset constrs_1 -norecurse tcl/constraints_genesys2.xdc



# set pulpissimo_xilinx as top
set_property top pulpissimo_xilinx [current_fileset]
set_property source_mgmt_mode None [current_project]

# elaborate design
# CORE_TYPE=0 --> ri5cy
# CORE_TYPE=1 --> zeroriscy
#synth_design -rtl -name rtl_1 -verilog_define PULP_FPGA_EMUL=1 -generic CORE_TYPE=0 -generic USE_FPU=0 -generic USE_HWPE=0
synth_design -rtl -name rtl_1 -verilog_define PULP_FPGA=1 -verilog_define PULP_FPGA_DEBUG=1 -generic CORE_TYPE=0 -generic USE_FPU=0

# run synthesis
set_property STEPS.SYNTH_DESIGN.ARGS.FLATTEN_HIERARCHY none [get_runs synth_1]
#+ set_property STEPS.SYNTH_DESIGN.ARGS.GATED_CLOCK_CONVERSION on [get_runs synth_1]
#set_property -name {STEPS.SYNTH_DESIGN.ARGS.MORE OPTIONS} -value {-mode out_of_context} -objects [get_runs synth_1]
launch_runs synth_1 -jobs 12
wait_on_run synth_1
if {[get_property PROGRESS [get_runs synth_1]] != "100%"} {
	error "ERROR: synth_1 failed"
}
open_run synth_1

launch_runs impl_1 -jobs 12
wait_on_run impl_1
if {[get_property PROGRESS [get_runs impl_1]] != "100%"} {
	error "ERROR: impl_1 failed"
}

#launch_runs impl_1 -to_step write_bitstream -jobs 12
