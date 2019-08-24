# based on https://iis-git.ee.ethz.ch/pulp-platform/imperio/blob/master/synopsys/scripts/synth_onlycore.tcl

source scripts/setup/setup.tcl
rad
sh rm -rf WORK/*

set_host_options -max_cores $NUM_CORES

# create output folders
sh mkdir -p ./mapped_core
sh mkdir -p ./reports_core

# ------------------------------------------------------------------------------
# Analyze Design
# ------------------------------------------------------------------------------
source ./scripts/analyze/analyze.tcl


# ------------------------------------------------------------------------------
# Elaborate Design
# ------------------------------------------------------------------------------

if { $USE_CORE == "ZERO-RISCY" } {
   if { $MICRO_RISCY == "TRUE"} {
      elaborate zeroriscy_core -work work -parameters "RV32M=0, RV32E=1"
   } else {
      elaborate zeroriscy_core -work work -parameters "RV32M=1, RV32E=0"
   }
} else {
    if { $RISCV_FPU == "TRUE" } {
       elaborate riscv_core -work work -parameters FPU=1
    } else {
       elaborate riscv_core -work work -parameters FPU=0
    }
}

rename_design [current_design_name] pulp_core

set_multicycle_path 2 -setup -through [get_pins id_stage_i/registers_i/*/Q]
set_multicycle_path 1 -hold  -through [get_pins id_stage_i/registers_i/*/Q]

if { $USE_CORNER == "SLOW" } {
   set LIB GF22FDX_SC8T_104CPP_BASE_CSC28L_SSG_0P59V_0P00V_0P00V_0P00V_125C
} else {
    set LIB GF22FDX_SC8T_104CPP_BASE_CSC28L_TT_0P80V_0P00V_0P80V_M0P80V_25C
}

dz_set_pvt $LIB
create_clock      [get_ports clk_i] -period $CLOCK_SPEED -name REF_CLK
set_ideal_network [get_ports clk_i]

set_clock_uncertainty                 20                [get_clocks REF_CLK]
set_clock_transition                  200               [get_clocks REF_CLK]

set core_outputs [all_outputs]

set core_inputs  [remove_from_collection [all_inputs] [get_ports clk_i]]
set core_inputs  [remove_from_collection $core_inputs [get_ports rst_ni]]


set INPUT_DELAY  80 #[expr 0.1*$CLOCK_SPEED]
set OUTPUT_DELAY 80 #[expr 0.1*$CLOCK_SPEED]

set_input_delay  $INPUT_DELAY  $core_inputs  -clock [get_clock]
set_output_delay $OUTPUT_DELAY [all_outputs] -clock [get_clock]


set_ideal_network       -no_propagate    [all_connected  [get_ports rst_ni]]
set_ideal_network       -no_propagate    [get_nets rst_ni]
set_dont_touch_network  -no_propagate    [get_ports rst_ni]
set_multicycle_path 2   -from            [get_ports   rst_ni]
set_case_analysis   0                    [get_ports test_en_i]
set_case_analysis   1                    [get_ports clock_en_i]

# todo add input drivers
# set DRIV_CELL INVM24R
# set DRIV_PIN  Z
# set LOAD_CELL INVM24R
# set LOAD_PIN  A

# set_driving_cell  -no_design_rule -library ${LIB} -lib_cell ${DRIV_CELL} -pin ${DRIV_PIN} [all_inputs]
# set_load [load_of ${LIB}/${LOAD_CELL}/${LOAD_PIN}] $core_outputs

# compile_ultra -gate_clock -no_autoungroup
compile
# write out ddc file
write -f ddc -hierarchy  -output ./mapped_core/${DESIGN_NAME}.ddc


report_timing > ./reports_core/${DESIGN_NAME}_post_inc_timing.rpt
report_area -hierarchy -nosplit > ./reports_core/${DESIGN_NAME}_area.rpt
report_register -nosplit > ./reports_core/${DESIGN_NAME}_registers.rpt
report_clock_gating > ./reports_core/${DESIGN_NAME}_num_regs.rpt
report_resources -hierarchy > ./reports_core/${DESIGN_NAME}_resources.rpt

echo "Feedthrough paths report..."

sh rm -rf ./reports/${DESIGN_NAME}_feedthrough.rpt

foreach_in_collection corein [all_inputs] {
  foreach_in_collection coreout [all_outputs] {
    echo "Path from " [get_object_name $corein] " to " [get_object_name $coreout] >> ./reports_core/${DESIGN_NAME}_feedthrough.rpt
    report_timing -from [get_object_name $corein] -to [get_object_name $coreout] >> ./reports_core/${DESIGN_NAME}_feedthrough.rpt
  }
}

#check path data mem <-> instr mem OK
report_timing -from data_*_i  -to instr_*_o > tmp; exec cat tmp;
report_timing -from instr_*_i -to data_*_o > tmp; exec cat tmp;
#check path irq <-> instr mem OK (irq_sec) 
report_timing -from irq_*_i -to instr_*_o> tmp; exec cat tmp;
#check path debug <-> instr mem OK
report_timing -from debug* -to instr_*_o> tmp; exec cat tmp;
#critical path to Mem
report_timing -to data_*_o > tmp; exec cat tmp;
report_timing -to instr_*_o > tmp; exec cat tmp;


echo "\n********************* \n SAVE VERILOG NETLIST \n*********************\n"
define_name_rules verilog -add_dummy_nets
change_names -h -rules verilog
write -f verilog -h -o ./netlists/${DESIGN_NAME}final.v

 
echo "Finish :-)"
