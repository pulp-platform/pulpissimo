# detect board
if [info exists ::env(BOARD)] {
    set BOARD $::env(BOARD)
}
if [info exists ::env(XILINX_BOARD)] {
    set XILINX_BOARD $::env(XILINX_BOARD)
}

# create project
create_project pulpissimo . -force -part $::env(XILINX_PART)
set_property board_part $XILINX_BOARD [current_project]

# set up meaningfull errors
source tcl/messages.tcl

# set up includes
source tcl/ips_inc_dirs.tcl
set_property include_dirs $INCLUDE_DIRS [current_fileset]
set_property include_dirs $INCLUDE_DIRS [current_fileset -simset]

# setup and add IP source files
source tcl/ips_src_files.tcl
source tcl/ips_add_files.tcl

# setup and add RTL source files
source tcl/rtl_src_files.tcl
source tcl/rtl_add_files.tcl


# TODO remove unneeded files - we have our own wrappers


# Set Verilog Defines.
set DEFINES "FPGA_TARGET_XILINX=1 PULP_FPGA_EMUL=1 AXI4_XCHECK_OFF=1"
if { $BOARD == "genesys2" } {
    set DEFINES "$DEFINES GENESYS2=1"
}
set_property verilog_define $DEFINES [current_fileset]

# detect target clock
if [info exists ::env(CLK_PERIOD_NS)] {
    set CLK_PERIOD_NS $::env(CLK_PERIOD_NS)
} else {
    set CLK_PERIOD_NS 10.000
}
set CLK_HALFPERIOD_NS [expr ${CLK_PERIOD_NS} / 2.0]

# TODO Add toplevel wrapper
# source tcl/ic_wrapper_bd.tcl

# validate
validate_bd_design

# TODO generate ips

# TODO add clock_manager

# TODO set top

# Elaborate design
synth_design -rtl -name rtl_1 -sfcu

# launch synthesis
launch_runs synth_1
wait_on_run synth_1
open_run synth_1 -name netlist_1
set_property needs_refresh false [get_runs synth_1]

# TODO run implementation
# source tcl/impl.tcl
