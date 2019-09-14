#########################################################################
#  Title       : Sample MMMC sdc file.
#  Project     : gf 22 dz flow
##########################################################################
#  File        : mmmc_test.sdc
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
# v0.1  - bm - Tue Nov 15 15:37:34 CET 2016
#  - copy from gf28 and adapt 
##########################################################################

## In our example, the test mode is projected to run much slower
create_clock -period  20000 [get_ports $CLK_PIN]

## for some reason I/O timing is different
set_input_delay  4000 -clock $CLK_PIN [remove_from_collection [all_inputs] [get_ports $CLK_PIN]]
set_output_delay 4000 -clock $CLK_PIN [all_outputs]

## In this mode, no case analysis should be set, to the fact that this mode is
## also used for hold timing analysis 

## note that the false paths from 'ScanEn_TI' and 'RamTest_TI' 
## in the functional mode are not declared here. But another path is
## disabled
