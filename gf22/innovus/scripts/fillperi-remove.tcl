###########################################################################
#  Title      : insert core filler cells
#  Project    : gf 22 dz flow
##########################################################################
#  File       : fillcore-insert.tcl 
#  Author     : Beat Muheim  <muheim@ee.ethz.ch>
#  Company    : Microelectronics Design Center (DZ), ETH Zurich
##########################################################################
#  Description : remove the io filler cells.
#  Inputs      : 
#  Outputs     :
#  Resources   :
##########################################################################
#  Copyright (c) 2016 Microelectronics Design Center, ETH Zurich
##########################################################################
# v0.1  - <muheim@ee.ethz.ch> - Thu Mar 23 12:06:38 CET 2017
#  - copy
##########################################################################

deleteIoFiller -prefix fillperi 
redraw
