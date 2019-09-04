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

rename_design [current_design_name] riscv_core
if { [string is true -strict $CORE_LATCH_RF] } {
set_multicycle_path 2 -setup -through [get_pins id_stage_i/registers_i/riscv_register_file_i/mem*/Q]
set_multicycle_path 1 -hold  -through [get_pins id_stage_i/registers_i/riscv_register_file_i/mem*/Q]


}
# TT_0P80V_0P00V_0P80V_M0P80V_25C
#set CLK_GATE_CELL    "GF22FDX_SC8T_104CPP_BASE_CSC28L_SSG_0P59V_0P00V_0P00V_0P00V_125C/SC8T_CKGPRELATNX4_CSC28L"
set CLK_GATE_CELL    "SC8T_CKGPRELATNX4_CSC28L"
set_attribute [get_cells core_clock_gate*/* ] is_clock_gating_cell true
set_attribute [get_cells id_stage_i/registers_i/riscv_register_file_i/CG* ] is_clock_gating_cell true
set_attribute [get_cells id_stage_i/registers_i/riscv_register_file_i/CG*/* ] is_clock_gating_cell true

set_attribute [get_cells  $CLK_GATE_CELL  ] is_clock_gating_cell true
set_clock_gating_style -minimum_bitwidth 3 -positive_edge_logic integrated:$CLK_GATE_CELL -control_point  before  -control_signal scan_enable  -max_fanout 256


echo "Setting clock gating variables"
set compile_clock_gating_through_hierarchy true ;
set power_cg_balance_stages false ;

set LIB [list GF22FDX_SC8T_104CPP_BASE_CSC20L_SSG_0P59V_0P00V_0P00V_0P00V_125C \
              GF22FDX_SC8T_104CPP_BASE_CSC24L_SSG_0P59V_0P00V_0P00V_0P00V_125C \
              GF22FDX_SC8T_104CPP_BASE_CSC28L_SSG_0P59V_0P00V_0P00V_0P00V_125C]


dz_set_pvt $LIB
create_clock      [get_ports clk_i] -period $CLOCK_SPEED -name REF_CLK
set_ideal_network [get_ports clk_i]

set_clock_uncertainty                 20                [get_clocks REF_CLK]
# set_clock_transition                  200               [get_clocks REF_CLK]

set core_outputs [all_outputs]

set core_inputs  [remove_from_collection [all_inputs] [get_ports clk_i]]
set core_inputs  [remove_from_collection $core_inputs [get_ports rst_ni]]


set INPUT_DELAY  300 
#[expr 0.1*$CLOCK_SPEED]
set OUTPUT_DELAY 300 
#[expr 0.1*$CLOCK_SPEED]

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
#compile
compile_ultra -no_autoungroup -gate_clock
# write out ddc file
write -f ddc -hierarchy  -output ./mapped_core/${DESIGN_NAME}.ddc

create_clock [get_ports clk_i] -period 0 -name REF_CLK
report_timing > ./reports_core/${DESIGN_NAME}_post_inc_timing.rpt
report_area -hierarchy -nosplit > ./reports_core/${DESIGN_NAME}_area.rpt
report_register -nosplit > ./reports_core/${DESIGN_NAME}_registers.rpt
report_clock_gating > ./reports_core/${DESIGN_NAME}_num_regs.rpt
report_resources -hierarchy > ./reports_core/${DESIGN_NAME}_resources.rpt

proc intersect_collection {a b} {
    return [remove_from_collection $a [remove_from_collection $a $b]]
}
proc extractPath {file} {
        try {
            exec cat $file | grep "No paths" >> tmp
            set num "-"
            
        } on error {result options} {
            set arrival_time  [exec cat $file | grep "data arrival time" -m 1 | awk "{print \$NF}"]
          
            set setup_time  [exec cat $file | grep "library setup time\\|output external delay" -m 1 | awk "{print \$4}"]
            # echo "${arrival_time}-(${setup_time})"
            set num [expr {${arrival_time}-(${setup_time})}]
        }
        return $num
        rm tmp
    }

# not implemented set fromMEM [intersect_collection [all_registers -clock_pins] [get_pins -regexp path_to_mem/in22.*/.*]]
set fromREG [remove_from_collection [all_registers -clock_pins] [get_pins -regexp id_stage_i/registers_i/riscv_register_file_i/mem.*/.*]]
set fromSCM [intersect_collection [all_registers -clock_pins] [get_pins -regexp id_stage_i/registers_i/riscv_register_file_i/mem.*/.*]]
set fromIN [all_inputs]

set toREG [remove_from_collection [all_registers -data_pins] [get_pins -regexp id_stage_i/registers_i/riscv_register_file_i/mem.*/.*]]
# not implemented set toMEM [intersect_collection [all_registers -data_pins] [get_pins -regexp i_computeTop_1/i_mem_tp.*/.*/.*]]
set toSCM [intersect_collection [all_registers -data_pins] [get_pins -regexp id_stage_i/registers_i/riscv_register_file_i/mem.*/.*]]
set toOUT [all_outputs]
set table_x {IN REG SCM}
set table_y {REG SCM OUT}

set thetable ""
    foreach x $table_x {
        set theheader [format "%7s" "f/t"]
        set thetable  [string cat $thetable [format "%7s" $x]]
        foreach y $table_y {
            echo "${x}2${y}";
            eval "report_timing -from \$from${x} -to \$to${y}"   > ./reports_core/${DESIGN_NAME}_post_inc_timing_${x}2${y}.rpt

            set tmp [extractPath "./reports_core/${DESIGN_NAME}_post_inc_timing_${x}2${y}.rpt"]
            if {$tmp == "-"} {
                set thetable  [string cat $thetable [format "%6s" $tmp]] 
            } else {
                set thetable  [string cat $thetable [format "%6.0f" $tmp]] 
            }
            
            set theheader [string cat $theheader [format "%6s" $y]]
        }
        
        set thetable  [string cat $thetable "\n"] 

    }
    echo "The timing information"
    set thetable  [string cat $theheader "\n" $thetable "\n"] 
    echo $thetable > ./reports_core/${DESIGN_NAME}_post_inc_timing_ALL.rpt
    echo $thetable
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
create_clock      [get_ports clk_i] -period $CLOCK_SPEED -name REF_CLK

echo "\n********************* \n SAVE VERILOG NETLIST \n*********************\n"
define_name_rules verilog -add_dummy_nets
change_names -h -rules verilog
write -f verilog -h -o ./netlists/${DESIGN_NAME}final.v

 
echo "Finish :-)"

