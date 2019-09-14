###########################################################################
#  Title      : Setings for special cell
#  Project    : gf 22 dz flow
##########################################################################
#  File       : special_cell_setting.tcl
#  Author     : Beat Muheim  <muheim@ee.ethz.ch>
#  Company    : Microelectronics Design Center (DZ), ETH Zurich
##########################################################################
#  Description : Is doin the seting for the row end caps, well tap, tie cells 
#                and filler cels. It is not inserting it this have to be don
#                in the run script.
#  Inputs      :
#  Outputs     : ($endCap)
#                ($wellTap)
#                ($tieCell)
#                ($fillerCellList)
#  Rhesuses    : 
##########################################################################
#  Copyright (c) 2016 Microelectronics Design Center, ETH Zurich
##########################################################################
# v0.9 - <muheim@ee.ethz.ch> - Mon Dec 10 13:39:37 CET 2018
#  - adding '_CSC*' in the filler parsing to avoid that the IO filler
#    also taken.
# v0.8 - <muheim@ee.ethz.ch> - Mon Dec 10 12:07:56 CET 2018
#  - fix for the 7.5T library
# v0.7 - <muheim@ee.ethz.ch> - Thu Nov 15 12:04:05 CET 2018
#  - the roul for the set_well_tap_mode  is hafe of the tap to tap distances
# v0.6 - <muheim@ee.ethz.ch> - Tue Nov 13 12:31:46 CET 2018
#  - tap to tap distances set to 50um
#     (RX_PP_junction not over HYBRID) maximum distance to the RX_p-well_contact within the same PW <= 40
#     (RX _NP_junction over HYBRID) not over EFUSE) maximum distance to the RX _p-well_ contact) (over PW) <= 25
#       it is the antenna diod
# v0.5 - <muheim@ee.ethz.ch> - Mon Nov  5 09:35:11 CET 2018
#  - make it also runing for 7.5T library
#  - tap to tap distances set to 70um
# v0.4 - <muheim@ee.ethz.ch> - Fri Apr 20 16:45:11 CEST 2018
#  - remuve set_well_tap_mode -avoidAbutment true
# v0.3 - <muheim@ee.ethz.ch> - Fri Nov 10 13:47:30 CET 2017
#  - end cap edge, the left was with the right side cells was swapped
#  - add set_well_tap_mode -avoidAbutment true
# v0.2 - <muheim@ee.ethz.ch> - Tue Jun 20 11:19:13 CEST 2017
#  - change the end Cap from X10 to X9
# v0.1 - <muheim@ee.ethz.ch> - Fri Mar 31 10:23:12 CEST 2017
#  - this is replaseng the setings in "physical_cell-insert.tcl",
#    "tiehilo.tcl" and "fillcore-insert.tcl"
##########################################################################
# To report endcap cells (specified as 'CLASS ENDCAP' in LEF) :
set endCapList(left)  [dbGet [dbGet -p head.libCells.subclass coreEndCapPost].name]
set endCapList(right) [dbGet [dbGet -p head.libCells.subclass coreEndCapPre].name]

set endCapList(top) {}
set endCapList(bottom) {}
set endCapList(top:left:edge) {}
set endCapList(top:right:edge) {}
set endCapList(bottom:left:edge) {}
set endCapList(bottom:right:edge) {}
set endCapList(top:left:corner) {}
set endCapList(top:right:corner) {}
set endCapList(bottom:left:corner) {}
set endCapList(bottom:right:corner) {}
foreach cell [dbGet -p head.libCells.name *] {
  if [string match "*_COLCAPPX1_CSC*"          [dbGet ${cell}.name]]  { lappend endCapList(top) [dbGet ${cell}.name]}
  if [string match "*_COLCAPNX1_CSC*"          [dbGet ${cell}.name]]  { lappend endCapList(bottom) [dbGet ${cell}.name]}
  if [string match "*_CONCAVEPRX9_CSC*"        [dbGet ${cell}.name]]  { lappend endCapList(top:left:edge) [dbGet ${cell}.name]}
  if [string match "*_CONCAVEPLX9_CSC*"        [dbGet ${cell}.name]]  { lappend endCapList(top:right:edge) [dbGet ${cell}.name]}
  if [string match "*_CONCAVENRX9_CSC*"        [dbGet ${cell}.name]]  { lappend endCapList(bottom:left:edge) [dbGet ${cell}.name]}
  if [string match "*_CONCAVENLX9_CSC*"        [dbGet ${cell}.name]]  { lappend endCapList(bottom:right:edge) [dbGet ${cell}.name]}
  if [string match "*_CNREXTANTENNAPRX9_CSC*"  [dbGet ${cell}.name]]  { lappend endCapList(top:left:corner) [dbGet ${cell}.name]}
  if [string match "*_CNREXTANTENNAPLX9_CSC*"  [dbGet ${cell}.name]]  { lappend endCapList(top:right:corner) [dbGet ${cell}.name]}
  if [string match "*_CNREXTANTENNANRX9_CSC*"  [dbGet ${cell}.name]]  { lappend endCapList(bottom:left:corner) [dbGet ${cell}.name]}
  if [string match "*_CNREXTANTENNANLX9_CSC*"  [dbGet ${cell}.name]]  { lappend endCapList(bottom:right:corner) [dbGet ${cell}.name]}
}

foreach orint [list left right top bottom top:left:edge top:right:edge bottom:left:edge bottom:right:edge top:left:corner top:right:corner bottom:left:corner bottom:right:corner] {
  foreach type [list "*_CSC20SL" "*_CSC20L" "*_CSC24SL" "*_CSC24L" "*_CSC28SL" "*_CSC28L" "*_CSC32SL" "*_CSC32L"  "*_CSC36SL" "*_CSC36L"] {
    if {0 <= [lsearch $endCapList($orint) $type]} {set endCap($orint) [lsearch -inline $endCapList($orint) $type]}
  }
}

# To get names of well tap cells (specified as 'CLASS CORE WELLTAP ' in LEF)
set wellTapList(name)   [dbGet [dbGet -p head.libCells.subClass coreWellTap].name]
set wellTap(maxdis) 50

# SC8T_TAPX8_CSC24L  have to be externel conected. 
# SC8T_TAPZBX8_CSC24L will conect  PPLUS and NPLUS to VSS
set wellTap(name) [lsearch -inline $wellTapList(name) "*_TAPZBX8_CSC20SL"]
set wellTap(name) [lsearch -inline $wellTapList(name) "*_TAPZBX8_CSC20L"]
set wellTap(name) [lsearch -inline $wellTapList(name) "*_TAPZBX8_CSC24SL"]
set wellTap(name) [lsearch -inline $wellTapList(name) "*_TAPZBX8_CSC24L"]
set wellTap(name) [lsearch -inline $wellTapList(name) "*_TAPZBX?_CSC28SL"]
set wellTap(name) [lsearch -inline $wellTapList(name) "*_TAPZBX?_CSC28L"]
set wellTap(name) [lsearch -inline $wellTapList(name) "*_TAPZBX?_CSC32SL"]
set wellTap(name) [lsearch -inline $wellTapList(name) "*_TAPZBX?_CSC32L"]
set wellTap(name) [lsearch -inline $wellTapList(name) "*_TAPZBX?_CSC36SL"]
set wellTap(name) [lsearch -inline $wellTapList(name) "*_TAPZBX?_CSC36L"]

foreach type [list "*_CSC20SL" "*_CSC20L" "*_CSC24SL" "*_CSC24L" "*_CSC28SL" "*_CSC28L" "*_CSC32SL" "*_CSC32L"  "*_CSC36SL" "*_CSC36L"] {
  if {0 <= [lsearch $wellTapList(name) $type]} {set wellTap(name)  [lsearch -inline $wellTapList(name) $type]}
}


# to get names of tie high / tie low cells (specified as 'CLASS CORE TIEHIGH' or 'CLASS CORE TIELOW' in LEF), use
set tieCellList(high) [dbGet [dbGet -p head.libCells.subClass coreTieHigh].name]
set tieCellList(low)  [dbGet [dbGet -p head.libCells.subClass coreTieLow].name]

foreach hl [list high low] {
  foreach type [list "*_CSC20SL" "*_CSC20L" "*_CSC24SL" "*_CSC24L" "*_CSC28SL" "*_CSC28L" "*_CSC32SL" "*_CSC32L"  "*_CSC36SL" "*_CSC36L"] {
    if {0 <= [lsearch $tieCellList($hl) $type]} {set tieCell($hl) [lsearch -inline $tieCellList($hl) $type]}
  }
}

set tieCell(high:low) [list $tieCell(high) $tieCell(low)]


set fillerCellList(empty) {}
set fillerCellList(decoup) {}
foreach cell [dbGet -p head.libCells.name *] {
  if [string match "*_FILL*_CSC*"  [dbGet ${cell}.name]]  { lappend fillerCellList(empty)  [dbGet ${cell}.name]}
  if [string match "*_DECAP*_CSC*" [dbGet ${cell}.name]]  { lappend fillerCellList(decoup) [dbGet ${cell}.name]}
}
#set fillerCellList(decoup) { SC8T_DECAPX9_CSC20L SC8T_DECAPX8_CSC20L SC8T_DECAPX5_CSC20L SC8T_DECAPX16_CSC20L SC8T_DECAPX9_CSC20SL SC8T_DECAPX8_CSC20SL SC8T_DECAPX5_CSC20SL SC8T_DECAPX16_CSC20S}

set fillerCellList(decoup:empty) [list $fillerCellList(decoup) $fillerCellList(empty)]


#-------------------------------------------------------------------------------
# make the setings

setEndCapMode -reset
setEndCapMode \
  -bottomEdge           $endCap(bottom) \
  -topEdge              $endCap(top) \
  -rightBottomEdge      $endCap(bottom:right:edge) \
  -leftBottomEdge       $endCap(bottom:left:edge) \
  -rightTopEdge         $endCap(top:right:edge) \
  -leftTopEdge          $endCap(top:left:edge) \
  -leftBottomCorner     $endCap(bottom:left:corner) \
  -leftTopCorner        $endCap(top:left:corner) \
  -rightBottomCorner    $endCap(bottom:right:corner) \
  -rightTopCorner       $endCap(top:right:corner) \
  -rightEdge            $endCap(right) \
  -leftEdge             $endCap(left)
  # leftEdge means 'cell that has n-well cap on its left'
  # rightEdge means 'cell that has n-well cap on its right'
  # I think 'corner' and 'edge' other way around then expand


set_well_tap_mode -reset
set_well_tap_mode -cell $wellTap(name) -rule [expr $wellTap(maxdis) / 2] -bottom_tap_cell $endCap(bottom)  -top_tap_cell $endCap(top) 

#set_well_tap_mode -avoidAbutment true
#  # Davide Schiavone had god expirations with this option

if [llength $tieCell(high:low) ] {
  # set tiehilo mode and insert the new cells
  setTieHiLoMode -reset
  setTieHiLoMode -maxFanout 12 -maxDistance 250 -createHierPort true \
                 -cell $tieCell(high:low)
  # -createHierPort true - try
} else {
  puts "ERROR: find no Tie Cell!"
}

setFillerMode -reset
setFillerMode -core $fillerCellList(decoup:empty)  -distribute_implant_evenly true -ecoMode true
# -viaEnclosure true ??
