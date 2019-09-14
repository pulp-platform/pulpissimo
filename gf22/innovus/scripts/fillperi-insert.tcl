###########################################################################
#  Title      : insert core filler cells
#  Project    : gf 22 dz flow
##########################################################################
#  File       : fillcore-insert.tcl 
#  Author     : Beat Muheim  <muheim@ee.ethz.ch>
#  Company    : Microelectronics Design Center (DZ), ETH Zurich
##########################################################################
#  Description : Insert the io filler cells, the _H types left/right and 
#                the _V types top/bottom.
#  Inputs      : 
#  Outputs     :
#  Resources   :
##########################################################################
#  Copyright (c) 2016 Microelectronics Design Center, ETH Zurich
##########################################################################
# v0.1  - <muheim@ee.ethz.ch> - Fri Jun 23 15:14:12 CEST 2017
#  - copy from the V04R30 arename 10M30P -> 10M3S30P
##########################################################################

addIoFiller -cell {IN22FDX_GPIO18_10M3S30P_FILL20_H IN22FDX_GPIO18_10M3S30P_FILL10_H IN22FDX_GPIO18_10M3S30P_FILL5_H IN22FDX_GPIO18_10M3S30P_FILL1_H} -side left   -prefix fillperi
addIoFiller -cell {IN22FDX_GPIO18_10M3S30P_FILL20_H IN22FDX_GPIO18_10M3S30P_FILL10_H IN22FDX_GPIO18_10M3S30P_FILL5_H IN22FDX_GPIO18_10M3S30P_FILL1_H} -side right  -prefix fillperi
addIoFiller -cell {IN22FDX_GPIO18_10M3S30P_FILL20_V IN22FDX_GPIO18_10M3S30P_FILL10_V IN22FDX_GPIO18_10M3S30P_FILL5_V IN22FDX_GPIO18_10M3S30P_FILL1_V} -side top    -prefix fillperi
addIoFiller -cell {IN22FDX_GPIO18_10M3S30P_FILL20_V IN22FDX_GPIO18_10M3S30P_FILL10_V IN22FDX_GPIO18_10M3S30P_FILL5_V IN22FDX_GPIO18_10M3S30P_FILL1_V} -side bottom -prefix fillperi
redraw
