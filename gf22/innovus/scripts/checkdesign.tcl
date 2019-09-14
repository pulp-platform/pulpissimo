##########################################################################
#  Title       : finel check of the designe
#  Project     : gf 22 dz flow
##########################################################################
#  File        : checkdesign.tcl
#  Author      : Beat Muheim  <muheim@ee.ethz.ch>
#  Company     : Microelectronics Design Center (DZ), ETH Zurich
##########################################################################
#  Description : Ter will be do the finel check of the designe and 
#                some reports.
#  Inputs      : ($DESIGNNAME)
#                ($wellTap) 
#  Outputs     : reports
#  Rhesuses    : 
##########################################################################
#  Copyright (c) 2016 Microelectronics Design Center, ETH Zurich
##########################################################################
# v0.3 - <muheim@ee.ethz.ch> - Wed Dec 13 15:49:49 CET 2017
#  - add checkFiller
# v0.2 - <muheim@ee.ethz.ch> - Wed Sep 13 10:01:33 CEST 2017
#  - add checkPlace
# v0.1 - <muheim@ee.ethz.ch> - Wed Nov 23 10:36:09 CET 2016
#  - copy from gf28 v0.1 
##########################################################################

# is the design name specified ???
if { [ info exists DESIGNNAME ] } {
   set NAME "$DESIGNNAME"

} else {
    set NAME "final"

}

# create the verify under reports when not existing
if {![file exists reports/verify]} {
  file mkdir reports/verify
}

## verify
puts "porform Connectivity, Geometry, ProcessAntenna and WellTap Checks"
verifyConnectivity -type all -geomConnect -report reports/verify/${NAME}.connect.rpt
#verifyGeometry -antenna -report reports/verify/${NAME}_geom.rpt
  # *ERROR: (IMPVFG-250):  This design uses metal and cut layer DRC rules for a process node of 20nm and below that are not supported by verifyGeometry
verify_drc -report reports/verify/${NAME}.drc.rpt
verifyProcessAntenna -leffile reports/verify/${NAME}.antenna.lef -reportfile reports/verify/${NAME}.antenna.rpt 
verifyWellTap -report  reports/verify/${NAME}.wellTap.rpt 
checkPlace reports/verify/${NAME}.checkPlace.rpt 
checkFiller -file reports/verify/${NAME}.checkFiller.rpt 

## reports
puts ""
puts "Writing summary report"
summaryReport -noHtml -outfile reports/verify/summaryReport.rpt

puts ""
puts "Checking nets that exceed the default delay limit"
puts "There should be no nets in the report below"
report_net -min_fanout [lindex $rdaUseDefaultDelayLimit 0]

