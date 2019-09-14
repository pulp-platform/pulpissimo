echo "This is the backend flow for Pulpissimo with RNN extension (core only)"
set DESIGNNAMEorig  pulpissimoRNNCore
set RepDir "reports/"
set timeRepDir  "reports/timing"
set clockRepDir "reports/clock"
set powerRepDir "reports/power"
set prefix "riscv"
#set prefix "rnnext"
set netlist ../synopsys/netlists/${prefix}_RISCY_${SYNTH_PERIOD}final.v

set highEffort true

setMultiCpuUsage -localCpu max

set SYNTH_PERIOD 2100
set DESIGNNAME "${prefix}_${SYNTH_PERIOD}"


set defHierChar / 
eval "set init_verilog {$netlist}"

set CLK_PIN "clk_i"
set RST_PIN "rst_ni"

proc collection_to_list {a_collection} {
    set my_list {}
    foreach_in_collection item $a_collection {
        lappend my_list [get_object_name $item]
    }
    return $my_list
}


set init_lef_file {../technology/lef/22FDSOI_10M_2Mx_6Cx_2Ix_LB_104cpp_tech.lef \
                   ../technology/lef/GF22FDX_SC8T_104CPP_BASE_CSC20L.lef \
                   ../technology/lef/GF22FDX_SC8T_104CPP_BASE_CSC24L.lef \
                   ../technology/lef/GF22FDX_SC8T_104CPP_BASE_CSC28L.lef \
                   ../technology/lef/IN22FDX_GPIO18_10M3S30P.lef}

set init_mmmc_file ./src/mmmc.view.tcl    
set init_pwr_net {VDD VDDIO}                                                                    
set init_gnd_net {VSS VSSIO} 
setLibraryUnit -time 1ps
setLibraryUnit -cap  1pf

init_design

  if { [file isdirectory ${RepDir}] ^ 1 } { mkdir ${RepDir} }
  if { [file isdirectory ${timeRepDir}] ^ 1 } { mkdir ${timeRepDir} }
  if { [file isdirectory ${clockRepDir}] ^ 1 } { mkdir ${clockRepDir} }
  if { [file isdirectory ${powerRepDir}] ^ 1 } { mkdir ${powerRepDir} }

set floorX 350
set floorY 350
set floorMargin 0
floorPlan  -d $floorX $floorY $floorMargin $floorMargin $floorMargin $floorMargin

editPin -layer 5 -pin *
source scripts/special_cell_setting.tcl
set wellTap(name) "SC8T_TAPX8_CSC28L"
set_well_tap_mode -reset
set_well_tap_mode -cell $wellTap(name) -rule $wellTap(maxdis)
addEndCap

set wellspacing 29.952
#multiply of 0.104
addWellTap -cellInterval  $wellspacing -fixedGap

free_power_intent
read_power_intent -cpf src/rnn_singlecore_powerIntent.cpf

commit_power_intent

setAttribute -net BIAS_S    -skip_routing true -skip_antenna_fix true
setAttribute -net IOPWROK_S -skip_routing true -skip_antenna_fix true
setAttribute -net RETC_S    -skip_routing true -skip_antenna_fix true
setAttribute -net PWROK_S   -skip_routing true -skip_antenna_fix true
setNanoRouteMode -routeBottomRoutingLayer 2
setNanoRouteMode -routeTopRoutingLayer    8

# Prevent router modifying M1 pins shapes
  setNanoRouteMode -routeWithViaInPin "1:1"
  setNanoRouteMode -routeWithViaOnlyForStandardCellPin "1:1"
   
  ## limit VIAs to ongrid only for VIA01 (V1)
  setNanoRouteMode -drouteOnGridOnly "via 1:1"

  setNanoRouteMode -quiet -routeInsertAntennaDiode 1
  setNanoRouteMode -quiet -timingEngine {}
  setNanoRouteMode -quiet -routeWithTimingDriven 0
  setNanoRouteMode -quiet -routeWithSiPostRouteFix 0
  setNanoRouteMode -quiet -routeWithTimingDriven true
  setNanoRouteMode -quiet -routeWithSiDriven false
  saveDesign save/${DESIGNNAME}_floorplan.enc
  fit

  source scripts/power_grid.tcl


redraw

  saveDesign save/${DESIGNNAME}_floorplan_powergrid.enc

  # Place and optimize

  #if {$highEffort == true} {
  echo "INFO: SetPlaceMode with high effort"
  setPlaceMode -place_global_cong_effort high 
  
  #setPlaceMode -place_global_timing_effort high
  setPlaceMode -place_global_clock_power_driven true
  setOptMode -effort high -usefulSkewCCOpt medium
  # TODO fix deprecated => **WARN: (IMPOPT-7177):  Option medium in 'setOptMode -usefulSkewCCOpt' is deprecated. It still works, but it will be removed in the future release.
  setPlaceMode -place_global_cong_effort high \
               -place_global_timing_effort medium \
               -place_global_clock_gate_aware true \
               -place_global_ignore_scan true \
               -place_global_reorder_scan false \
               -place_global_place_io_pins false \
               -place_detail_color_aware_legal true \
               -place_detail_no_filler_without_implant true
#new ocmmands
setAnalysisMode -analysisType onChipVariation -cppr both

setAnalysisMode -aocv true


  set icgs  [filter_collection [all_registers] "is_integrated_clock_gating_cell == true"]
  set regs [all_registers]
  set ff  [remove_from_collection [all_registers -edge_triggered] $icgs]

  # group_path   -name Reg2Mem      -from $regs -to $mems
  # group_path   -name Mem2Reg      -from $mems -to $regs
  # group_path   -name Mem2Mem      -from $mems -to $mems
  #
  ##Create FF Path Groups
  # group_path   -name ff2ff        -from $ff -to $ff
  # group_path   -name reg2ff       -from $regs -to $ff
  # group_path   -name ff2reg       -from $ff -to $regs
  group_path   -name reg2reg       -from $regs -to $regs
  setPathGroupOptions reg2reg -effortLevel high

  createBasicPathGroups -expanded

# Don't use this cell type as it is creating minimum via spacing problems
  # with VSS when Innovus decides to place some vias there
  set_interactive_constraint_modes [all_constraint_modes -active]
  set_dont_use true [dbGet head.allCells.name SC8T_SDFFRQX1_A*]
  # those guys are also making problems
  set_dont_use true [dbGet head.allCells.name SC8T_AO222X1_MR*]

  # setting trial- and finale

  # place_opt_design -expandedViews -out_dir ${timeRepDir} -prefix ${DESIGNNAME}.preCTS-pod
  place_opt_design -out_dir ${timeRepDir} -prefix ${DESIGNNAME}.preCTS-pod

 
  addTieHiLo

  timeDesign -preCTS -expandedViews -outDir ${timeRepDir} -prefix ${DESIGNNAME}.preCTS
  # optDesign -drv -preCTS -expandedViews -outDir ${timeRepDir} -prefix ${DESIGNNAME}.preCTS-drv
  # optDesign -preCTS -expandedViews -outDir ${timeRepDir} -prefix ${DESIGNNAME}.preCTS-opt

  saveDesign save/${DESIGNNAME}_chip_timingOpt.enc

   #Clock Tree insertion
  ########################################

  source src/${DESIGNNAMEorig}.ccopt.spec

  ccopt_design -expandedViews -outDir ${timeRepDir} -prefix ${DESIGNNAME}.postCTS-ccopt

  setOptMode -fixClockDrv true 
  setOptMode -effort high
  optDesign -postCTS -drv 
  timeDesign -postCTS -expandedViews -outDir ${timeRepDir} -prefix ${DESIGNNAME}.postCTS-ccopt-drv
  setOptMode -fixClockDrv false


report_ccopt_clock_trees -filename ${clockRepDir}/${DESIGNNAME}_clock_trees.rpt
report_ccopt_skew_groups -filename ${clockRepDir}/${DESIGNNAME}_skew_groups.rpt

saveDesign    save/${DESIGNNAME}_chip.postCTS.enc
update_constraint_mode -name func_mode -sdc_files [list src/mmmc_functional_postCTS.sdc \
                                                        src/mmmc_shared.sdc ] 

timeDesign -postCTS -expandedViews -outDir ${timeRepDir} -prefix ${DESIGNNAME}.postCTS

optDesign -postCTS -expandedViews  -outDir ${timeRepDir} -prefix ${DESIGNNAME}.postCTS

#before Routing make a save point
saveDesign    save/${DESIGNNAME}_chip.postCTSopt.enc

# Start Routing
########################################
setNanoRouteMode -quiet -routeInsertAntennaDiode true
setNanoRouteMode -quiet -routeWithSiPostRouteFix false
setNanoRouteMode -quiet -routeWithTimingDriven true
setNanoRouteMode -quiet -routeWithSiDriven true
#setNanoRouteMode -quiet -drouteOnGridOnly true

## Prevent router modifying M1 pins shapes
setNanoRouteMode -routeWithViaInPin "1:1"
setNanoRouteMode -routeWithViaOnlyForStandardCellPin "1:1"

# limit VIAs to ongrid only for VIA01 (V1)
setNanoRouteMode -drouteOnGridOnly "via 1:1 wire 1:2"

routeDesign -globalDetail

update_constraint_mode -name func_mode -sdc_files [list src/mmmc_functional_postRoute.sdc \
                                                        src/mmmc_shared.sdc ]


saveDesign save/${DESIGNNAME}_chip.postRoute.enc

timeDesign -postRoute -expandedViews -outDir ${timeRepDir} -prefix ${DESIGNNAME}.postRoute
saveDesign save/${DESIGNNAME}_chip.postRoute-time.enc
#optimize again
optDesign -postRoute -expandedViews -outDir ${timeRepDir} -prefix ${DESIGNNAME}.postRoute-opt
saveDesign save/${DESIGNNAME}_chip.postRoute-time-opt.enc

#hold fixing
timeDesign -postRoute -hold -expandedViews -outDir ${timeRepDir} -prefix ${DESIGNNAME}.postRoute
saveDesign save/${DESIGNNAME}_chip.postRoute-time-hold.enc
optDesign -postRoute -hold -expandedViews -outDir ${timeRepDir} -prefix ${DESIGNNAME}.postRoute-opt
verify_drc -check_only regular

saveDesign save/${DESIGNNAME}_chip.postRouteoptimized.enc

# we are here:
# report area
report_area > ${RepDir}/area.rpt

# trim dangling wires
# editTrim -all

verify_drc
setNanoRouteMode -routeWithECO true
setNanoRouteMode -drouteFixAntenna true
globalDetailRoute
saveDesign save/${DESIGNNAME}_chip.prefiller.enc

setFillerMode -doDRC true
setFillerMode -ecoMode true

addFiller
checkFiller
addFiller -fixDRC -minHole true -diffCellViol true

#asdfasdfasdf
clearDrc
setNanoRouteMode -routeWithECO true
setNanoRouteMode -drouteFixAntenna true
globalDetailRoute
verify_drc

 ecoRoute -fix_drc
saveDesign save/${DESIGNNAME}_chip.withfiller.enc
setNanoRouteMode -droutePostRouteSwapVia multiCut
routeDesign -viaOpt

# check the design
source scripts/checkdesign.tcl 
saveDesign save/${DESIGNNAME}_chip_final.enc.dat
# rm out/*
source scripts/exportall.tcl
write_lef_abstract out/${DESIGNNAME}.lef.gz -stripePin

set_analysis_view -setup { func_view view_func_best_delay_rccCminDP_125C  \
                                     view_func_best_delay_rccRCminDP_125C \
                                     view_func_best_delay_rccCminDP_m40C  \
                                     view_func_best_delay_rccRCminDP_m40C \
                                     view_test_best_delay_rccCminDP_125C  \
                                     view_test_best_delay_rccRCminDP_125C \
                                     view_test_best_delay_rccCminDP_m40C  \
                                     view_test_best_delay_rccRCminDP_m40C \
                                     view_worst_delay_rccCmaxDP_125C      \
                                     view_worst_delay_rccRCmaxDP_125C     \
                                     view_worst_delay_rccCmaxDP_m40C      \
                                     view_worst_delay_rccRCmaxDP_m40C} \
                  -hold  { hold_view view_func_best_delay_rccCminDP_125C  \
                                     view_func_best_delay_rccRCminDP_125C \
                                     view_func_best_delay_rccCminDP_m40C  \
                                     view_func_best_delay_rccRCminDP_m40C \
                                     view_test_best_delay_rccCminDP_125C  \
                                     view_test_best_delay_rccRCminDP_125C \
                                     view_test_best_delay_rccCminDP_m40C  \
                                     view_test_best_delay_rccRCminDP_m40C \
                                     view_worst_delay_rccCmaxDP_125C      \
                                     view_worst_delay_rccRCmaxDP_125C     \
                                     view_worst_delay_rccCmaxDP_m40C      \
                                     view_worst_delay_rccRCmaxDP_m40C}

# END should ...
extractRC
rcOut -rc_corner rccCmaxDP_125C -spef out/${DESIGNNAME}_CmaxDP_125C.spef.gz
rcOut -rc_corner rccCminDP_125C -spef out/${DESIGNNAME}_CminDP_125C.spef.gz
rcOut -rc_corner rccRCmaxDP_125C -spef out/${DESIGNNAME}_RCmaxDP_125C.spef.gz
rcOut -rc_corner rccRCminDP_125C -spef out/${DESIGNNAME}_RCminDP_125C.spef.gz
rcOut -rc_corner rccCmaxDP_m40C -spef out/${DESIGNNAME}_CmaxDP_m40C.spef.gz
rcOut -rc_corner rccCminDP_m40C -spef out/${DESIGNNAME}_CminDP_m40C.spef.gz
rcOut -rc_corner rccRCmaxDP_m40C -spef out/${DESIGNNAME}_RCmaxDP_m40C.spef.gz
rcOut -rc_corner rccRCminDP_m40C -spef out/${DESIGNNAME}_RCminDP_m40C.spef.gz 
