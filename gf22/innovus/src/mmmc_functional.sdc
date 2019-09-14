#########################################################################
#  Title       : Sample MMMC sdc file.
#  Project     : gf 22 dz flow
##########################################################################
#  File        : mmmc_functional.sdc
#  Author      : Beat Muheim  <muheim@ee.ethz.ch>
#  Company     : Microelectronics Design Center (DZ), ETH Zurich
##########################################################################
#  Description : 
#    There are 4 files in this fictional MMMC (multi-mode multi-corner)
#    analysis setup:
#      - src/sample/mmmc_shared.sdc        SDC file with common constraints
#      - src/sample/mmmc_functional.sdc    Functional mode constraints
#      - src/sample/mmmc_test.sdc          Test mode constraints
#                                          (also used for hold timing analysis)
#      - src/sample/mmmc.view.tcl          Sample TCL file that can be adapted
#
#    Please note these are just for reference, develop your own scripts!
#
##########################################################################
#  Copyright (c) 2016 Microelectronics Design Center, ETH Zurich
##########################################################################
# v0.1  - bm - Tue Nov 15 15:37:48 CET 2016
#  - copy from gf28 and adapt 
#################################################################

## In our fictional example the circuit has a main operational mode
## In a standard SDC file (without MMMC) we would only use these
## constraints. 

#TODO for final tapeout use aocv and detailed timing corners
set PERIOD_PRECTS [expr "$SYNTH_PERIOD+100"]
create_clock -name master_clock -period ${PERIOD_PRECTS} [get_ports $CLK_PIN]

set_input_delay  80 -clock  master_clock [remove_from_collection [all_inputs] [get_ports $CLK_PIN]]
set_output_delay 80 -clock  master_clock [all_outputs]
set_input_delay 60 -clock  master_clock [get_ports $RST_PIN]
#set_clock_uncertainty 500  $CLK_PIN
#set_input_transition 250  $CLK_PIN -max 
#set_input_transition 150  $CLK_PIN -min

## In this mode, the following pin is always set to the given value
#set_case_analysis 0 [get_ports {ScanEn_TI}]
#set_case_analysis 0 [get_ports {RamTest_TI}]

## set_case_analysis sets a constant value
## ste_false_path removes it from timing calculation.
## Use set_false_path as a last resort. 
#set_false_path -from [get_ports {TestEn_TI}]
#set_false_path -from [get_ports {RamTest_TI}]


set_multicycle_path 2 -setup -through [get_pins id_stage_i/registers_i/riscv_register_file_i/mem*/Q]
set_multicycle_path 1 -hold  -through [get_pins id_stage_i/registers_i/riscv_register_file_i/mem*/Q]
