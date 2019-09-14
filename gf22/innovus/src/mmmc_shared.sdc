#########################################################################
#  Title       : Sample MMMC sdc file.
#  Project     : gf 22 dz flow
##########################################################################
#  File        : mmmc_shared.sdc
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
# v0.1  - bm - Tue Jan 19 13:28:48 CET 2016
#  - copy from gf28 and adapt 
##########################################################################


## You can use a separate file to keep options that are common between
## multiple modes. In this example we will assume that the output load 
## and input transition are the same.

#set_input_transition 1.0 [all_inputs]
#set_load 0.02 [all_outputs]

