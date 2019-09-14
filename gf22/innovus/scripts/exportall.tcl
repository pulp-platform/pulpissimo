###########################################################################
#  Title      : Export all relevant design data.
#  Project    : gf 22 dz flow
##########################################################################
#  File       : exportall.tcl
#  Author     : Beat Muheim  <muheim@ee.ethz.ch>
#  Company    : Microelectronics Design Center (DZ), ETH Zurich
##########################################################################
#  Description : 
#  Inputs      : $DESIGNNAME
#  Outputs     : sdc, netlist, gds
#  Rhesuses    : 
##########################################################################
#  Copyright (c) 2016 Microelectronics Design Center, ETH Zurich
##########################################################################
# v0.7 - <muheim@ee.ethz.ch> - Thu Dec 21 14:09:46 CET 2017
#  - adding to the excludeCellInstList "SC8T_CONCAVE*"
# v0.6 - <muheim@ee.ethz.ch> - Tue Dec  5 10:38:50 CET 2017
#  - the VIAs will be writen out as top structure name and lef via name
# v0.5 - <muheim@ee.ethz.ch> - Wed Nov 29 15:15:02 CET 2017
#  - Use "22FDSOI_edi2gds_colored.layermap" for the gds export map
#    inste "22FDSOI_edi2gds_multicolor.layermap"      
# v0.4 - <muheim@ee.ethz.ch> - Wed Sep 13 10:44:26 CEST 2017
#  - add -virtualConnection false to setStreamOutMode
#    to avoid appending a (:) to the pin label of power ground
# v0.3 - <muheim@ee.ethz.ch> - Tue Jun 27 08:30:42 CEST 2017
#  - add WA problems withe the sdf  and following cells:
#      IN22FDX_GPIO18_10M30P_SPVDDIO_V IN22FDX_GPIO18_10M30P_SPVDDIO_H
#  - remove '-remashold' on the write_sdf again
#  - add excludeCellInstList to exclude the emty cells for the lvs
#  - cahnge the layer map file to the multicolor version
# v0.2 - <muheim@ee.ethz.ch> - Wed May 18 09:16:46 CEST 2016
#  - add filter for bond pad, add commented out, save netlist for
#    simulation withe power connections
#    add -remashold to the write_sdf
# v0.1 - <muheim@ee.ethz.ch> - Tue Jan 19 11:03:35 CET 2016
#  - copy from gf28 v0.4
##########################################################################


# is the design name specified ???
if { [ info exists DESIGNNAME ] } {
   set NAME "$DESIGNNAME"

} else {
    set NAME "final"

}

# get the names of cells to ecluding in the lvs netlist
set excludeCellInstList {}
foreach cell [dbGet -p head.libCells.name *] {
  if [string match "SC8T_FILL*"          [dbGet ${cell}.name]]  { lappend excludeCellInstList  [dbGet ${cell}.name]}
  if [string match "*30P_FILL*"          [dbGet ${cell}.name]]  { lappend excludeCellInstList  [dbGet ${cell}.name]}
  if [string match "SC8T*COLCAPPX1_CSC*" [dbGet ${cell}.name]]  { lappend excludeCellInstList  [dbGet ${cell}.name]}
  if [string match "SC8T_COLCAPNX1_CSC*" [dbGet ${cell}.name]]  { lappend excludeCellInstList  [dbGet ${cell}.name]}
  if [string match "SC8T_CONCAVE*"       [dbGet ${cell}.name]]  { lappend excludeCellInstList  [dbGet ${cell}.name]}
}

#lappend excludeCellInstList "IN22FDX_GPIO18_10M3S30P_CORNER"


# RC will be extracted, if not ready don, using the
# Integrated QRC (IQRC) engine.
#setExtractRCMode -effortLevel high


# global variable for written the sdf checks checks correctly with a triple
set_global timing_recompute_sdf_in_setuphold_mode true
# Write out SDF, take the first analysis_views from the hold and the setup list
write_sdf -precision 4 -min_period_edges posedge -recompute_parallel_arcs -nonegchecks \
          -min_view [lindex [all_hold_analysis_views]  0] \
          -typ_view [lindex [all_setup_analysis_views] 0] \
          -max_view [lindex [all_setup_analysis_views] 0] \
          out/${NAME}.sdf.gz

# This netlist do not contains the filler cells, physical cells.
# This can be used for simulation (normal/with power connections) 
saveNetlist out/${NAME}.v -excludeLeafCell
#saveNetlist out/${NAME}_pwr.v -excludeLeafCell -excludeCellInst $excludeCellInstList -includePowerGround

# This netlist contains all filler cells and everything.
# This have to be used for LVS 
saveNetlist out/${NAME}_lvs.v -excludeLeafCell -excludeCellInst $excludeCellInstList -includePhysicalInst -phys


# layout
#setStreamOutMode -SEvianames ON -specifyViaName %t_VIA -virtualConnection false
setStreamOutMode -SEvianames true -specifyViaName %t_%v -virtualConnection false

# you can set an alternative top name with -structureName 
# streamOut out/${NAME}.gds.gz -structureName sem01w0 
# for design with a macro merged by cockpit
streamOut out/${NAME}.gds.gz  -mapFile ../technology/22FDSOI_edi2gds_colored.layermap -outputMacros -merge {  \
  /usr/pack/gf-22-kgf/dz/../gf/pdk-22FDX-V1.3_2.2/ChipKit/MetrologyCells/PCI/GDSII/TGPCI_10M_2Mx_6Cx_2Ix_LB.gds \
  /usr/pack/gf-22-kgf/invecas/std/V05R00/GF22FDX_SC8T_104CPP_BASE_CSC20L/gds/GF22FDX_SC8T_104CPP_BASE_CSC20L.gds \
  /usr/pack/gf-22-kgf/invecas/std/V05R00/GF22FDX_SC8T_104CPP_BASE_CSC24L/gds/GF22FDX_SC8T_104CPP_BASE_CSC24L.gds \
  /usr/pack/gf-22-kgf/invecas/std/V05R00/GF22FDX_SC8T_104CPP_BASE_CSC28L/gds/GF22FDX_SC8T_104CPP_BASE_CSC28L.gds \
  /usr/pack/gf-22-kgf/invecas/io/V04R40/IN22FDX_GPIO18_10M3S30P_FDK_RELV04R40/gds/IN22FDX_GPIO18_10M3S30P.gds \
  }

