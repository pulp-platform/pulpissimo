###########################################################################
#  power grid creation
##########################################################################

#REF: 22FDX_Rev1.1_2.0_20170410.pdf

# start grid m3 to m9
#page 494, Cx.W.1
#even multiple of manufacturing grid (0.001000), setting to 0.046000.
set minC1_W 0.044
#page 493, Ax.S.1 for VIAs but for long lenght Cx.S.11 is used
set minC1_S 0.45
#page 494, Cx.W.1
set minC2_W 0.046
#page 493, Cx.S.11
set minC2_S 0.45

# set blockage_mem {{0 1255 2560 995.513} \
#                   {2372.089 995.513 2560 726.051} \
#                   {0 259.494 2560 0} \
#                   {2372.088 528.949 2560 259.494}}

# set blockage_mem {{0 1255 2560 995.513} \
#                   {2360 995.513 2560 726.051} \
#                   {0 259.494 2560 0} \
#                   {2360 528.949 2560 259.494}}

set blockage_mem {}
# {{2377.246 995.175 2559.682 985.29400} \
#              {2377.246 269.706 2559.682 259.44700}}

## let us start with a cleanup
deleteAllPowerPreroutes
clearDrc
setViaGenMode    -reset
setAddStripeMode -reset
setSrouteMode    -reset

setViaGenMode -optimize_cross_via true
setAddStripeMode -stacked_via_bottom_layer 2 -stacked_via_top_layer 3



# RING AROUND Blocks
# setAddRingMode -ring_target default -extend_over_row 0 -ignore_rows 0 -avoid_short 0 -skip_crossing_trunks none -stacked_via_top_layer LB \
-stacked_via_bottom_layer M2 -via_using_exact_crossover_size 1 -orthogonal_only true -skip_via_on_pin {  standardcell } \
-skip_via_on_wire_shape {  noshape }

# deselectAll
# Select all memories
# foreach mem_inst [dbFindInstsByName *in22fdx_mem*] {
#   selectInst $mem_inst
#   echo "Info: Select $mem_inst"
# }

########################
## Memory power rings (NO MEMORY POWER RINGS)
########################
# Ring Group 1 (First Row)
# for {set i 0} {$i < 8} {incr i} { selectInst ${mem_path}i_mem_tp_1_0/in22fdx_mem_$i }
# for {set i 0} {$i < 8} {incr i} { selectInst ${mem_path}i_mem_tp_1_1/in22fdx_mem_$i }
# for {set i 0} {$i < 7} {incr i} { selectInst ${mem_path}i_mem_tp_1_2/in22fdx_mem_$i }
# addRing -nets {VDD VSS} -type block_rings -around cluster -layer {top M2 bottom M2 left M2 right M2} \
# -width 0.35 -spacing 0.1 \
# -offset {top 0.7 bottom 0.7 left 1.30 right 1.30} -center 0 -extend_corner {} -threshold 0 -jog_distance 2 -snap_wire_center_to_grid None
# deselectAll

# # Ring Group 2 (Block Right)
# for {set i 7} {$i < 8} {incr i} { selectInst ${mem_path}i_mem_tp_1_2/in22fdx_mem_$i }
# for {set i 0} {$i < 5} {incr i} { selectInst ${mem_path}i_mem_tp_1_3/in22fdx_mem_$i }
# addRing -nets {VDD VSS} -type block_rings -around cluster -layer {top M2 bottom M2 left M2 right M2} \
# -width 0.35 -spacing 0.1 \
# -offset {top 0.7 bottom 0.7 left 1.30 right 1.30} -center 0 -extend_corner {} -threshold 0 -jog_distance 2 -snap_wire_center_to_grid None
# deselectAll

# # Ring Group 3 (Last Row)
# for {set i 5} {$i < 8} {incr i} { selectInst ${mem_path}i_mem_tp_1_3/in22fdx_mem_$i }
# for {set i 0} {$i < 8} {incr i} { selectInst ${mem_path}i_mem_tp_1_4/in22fdx_mem_$i }
# for {set i 0} {$i < 8} {incr i} { selectInst ${mem_path}i_mem_tp_1_5/in22fdx_mem_$i }
# for {set i 0} {$i < 4} {incr i} { selectInst ${mem_path}i_mem_tp_1_6/in22fdx_mem_$i }
# #-jog_distance 2 because the step in the memory board is ~1, so to have the right squared the jog must be bigger
# addRing -nets {VDD VSS} -type block_rings -around cluster -layer {top M2 bottom M2 left M2 right M2} \
# -width 0.35 -spacing 0.1 \
# -offset {top 0.7 bottom 0.7 left 1.30 right 1.30} -center 0 -extend_corner {} -threshold 0 -jog_distance 2 -snap_wire_center_to_grid None
# deselectAll

# # Ring Group 4 (Left)
# for {set i 4} {$i < 8} {incr i} { selectInst ${mem_path}i_mem_tp_1_6/in22fdx_mem_$i }
# addRing -nets {VDD VSS} -type block_rings -around cluster -layer {top M2 bottom M2 left M2 right M2} \
# -width 0.35 -spacing 0.1 \
# -offset {top 0.7 bottom 0.7 left 1.30 right 1.30} -center 0 -extend_corner {} -threshold 0 -jog_distance 2 -snap_wire_center_to_grid None
# deselectAll


setViaGenMode -optimize_cross_via true
setAddStripeMode -stacked_via_bottom_layer 2 -stacked_via_top_layer 3

#VBN VBP (M3)


set well_vnwn_c1_w      0.046
set well_vnwn_c1_offset 30.233
#0.285+0.027+29.952
set well_vnwp_c1_spacing 0.134

#0.128-0.027

#stop at 1200 and then restart from there as it was divergin from welltap PINS
addStripe -skip_via_on_pin {} \
          -set_to_set_distance $wellspacing -spacing  $well_vnwp_c1_spacing -start_offset  $well_vnwn_c1_offset  -width $well_vnwn_c1_w \
          -area_blockage $blockage_mem \
          -same_layer_target_only 1 -max_same_layer_jog_length 4 \
          -padcore_ring_bottom_layer_limit 1 -padcore_ring_top_layer_limit 6 \
          -block_ring_bottom_layer_limit 1 -block_ring_top_layer_limit 6 \
          -layer C1 \
          -nets {VNW_N VPW_P}

# addStripe -skip_via_on_pin {} \
#           -set_to_set_distance $wellspacing -spacing  0.32 -start_offset  1258.2 -width 0.046 \
#           -area_blockage $blockage_mem \
#           -same_layer_target_only 1 -max_same_layer_jog_length 4 \
#           -padcore_ring_bottom_layer_limit 1 -padcore_ring_top_layer_limit 6 \
#           -block_ring_bottom_layer_limit 1 -block_ring_top_layer_limit 6 \
#           -layer C1 \
#           -nets {VNW_N VPW_P}


# todo check via gen and largre amount of geometries warning

setViaGenMode    -reset
setAddStripeMode -reset

setAddStripeMode -ignore_block_check false -break_at none -route_over_rows_only false \
                 -rows_without_stripes_only false -extend_to_closest_target none -stop_at_last_wire_for_area false \
                 -partial_set_thru_domain false -ignore_nondefault_domains false -trim_antenna_back_to_shape none \
                 -spacing_type edge_to_edge -spacing_from_block 0 -stripe_min_length 0 -stacked_via_top_layer LB \
                 -stacked_via_bottom_layer M2 -via_using_exact_crossover_size false -split_vias false -orthogonal_only true \
                 -allow_jog { padcore_ring  block_ring }

set well_vdd_c1_w       0.190 
#0.190+0.027
set well_vdd_c1_offset  29.952

set well_vss_c1_w      0.233 

set well_vss_c1_offset 30.550
#29.952+0.598
#VDD GND GND (M3)
addStripe -skip_via_on_pin {} \
          -set_to_set_distance $wellspacing -spacing  0 -start_offset  $well_vdd_c1_offset  -width $well_vdd_c1_w \
          -area_blockage $blockage_mem \
          -same_layer_target_only 1 -max_same_layer_jog_length 4 \
          -padcore_ring_bottom_layer_limit 1 -padcore_ring_top_layer_limit 6 \
          -block_ring_bottom_layer_limit 1 -block_ring_top_layer_limit 6 \
          -layer C1 \
          -nets {VDD}

addStripe -skip_via_on_pin {} \
          -set_to_set_distance $wellspacing -spacing  0 -start_offset  $well_vss_c1_offset -width $well_vss_c1_w \
          -area_blockage $blockage_mem \
          -same_layer_target_only 1 -max_same_layer_jog_length 4 \
          -padcore_ring_bottom_layer_limit 1 -padcore_ring_top_layer_limit 6 \
          -block_ring_bottom_layer_limit 1 -block_ring_top_layer_limit 6 \
          -layer C1 \
          -nets {VSS}

# addStripe -skip_via_on_pin {} \
#           -set_to_set_distance 29.95 -spacing  0 -start_offset  11.056 -width 0.34 \
#           -area_blockage $blockage_mem \
#           -same_layer_target_only 1 -max_same_layer_jog_length 4 \
#           -padcore_ring_bottom_layer_limit 1 -padcore_ring_top_layer_limit 6 \
#           -block_ring_bottom_layer_limit 1 -block_ring_top_layer_limit 6 \
#           -layer C1 \
#           -nets {VSS}

# addStripe -skip_via_on_pin {} \
#           -set_to_set_distance 29.95 -spacing  0 -start  2370 -stop 2375 -width 0.34 \
#           -same_layer_target_only 1 -max_same_layer_jog_length 4 \
#           -padcore_ring_bottom_layer_limit 1 -padcore_ring_top_layer_limit 6 \
#           -block_ring_bottom_layer_limit 1 -block_ring_top_layer_limit 6 \
#           -layer C1 \
#           -nets {VSS}

# old stripes
# addStripe -skip_via_on_pin {} \
#           -set_to_set_distance 29.95 -spacing  0 -start_offset  0.986  -width 0.68 \
#           -area_blockage $blockage_mem \
#           -same_layer_target_only 1 -max_same_layer_jog_length 4 \
#           -padcore_ring_bottom_layer_limit 1 -padcore_ring_top_layer_limit 6 \
#           -block_ring_bottom_layer_limit 1 -block_ring_top_layer_limit 6 \
#           -layer C1 \
#           -nets {VDD}


# deselectAll

#big GRID, horizontal

addStripe -nets VDD -layer IA -direction horizontal -width 4.546 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 1250.38 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VDD_ARR -layer IA -direction horizontal -width 1.442 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 1243.834 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VDD_PER -layer IA -direction horizontal -width 1.442 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 1240.392 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VSS -layer IA -direction horizontal -width 4.546 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 1236.952 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VDD_ARR -layer IA -direction horizontal -width 1.442 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 1230.406 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VDD_PER -layer IA -direction horizontal -width 1.442 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 1226.964 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VDD -layer IA -direction horizontal -width 4.546 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 1223.522 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VNW_N -layer IA -direction horizontal -width 1.442 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 1216.976 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VPW_P -layer IA -direction horizontal -width 1.442 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 1213.534 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VSS -layer IA -direction horizontal -width 4.546 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 1210.092 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

# Via resize VDD
#M9->M8
editSelectVia -net VDD -cut_layer YX
editPowerVia -modify_vias 1 -selected_vias 1 -via_columns 1 -via_rows 2
deselectAll
  #M8->M7
editSelectVia -net VDD -cut_layer A5
editPowerVia -modify_vias 1 -selected_vias 1 -via_columns 6 -via_rows 9
deselectAll
  #M7->M6
editSelectVia -net VDD -cut_layer A4
editPowerVia -modify_vias 1 -selected_vias 1 -via_columns 6 -via_rows 9
deselectAll
  #M6->M5
editSelectVia -net VDD -cut_layer A3
editPowerVia -modify_vias 1 -selected_vias 1 -via_columns 6 -via_rows 9
deselectAll
  #M5->M4
editSelectVia -net VDD -cut_layer A2
editPowerVia -modify_vias 1 -selected_vias 1 -via_columns 6 -via_rows 9
deselectAll
  #M4->M3
editSelectVia -net VDD -cut_layer A1
editPowerVia -modify_vias 1 -selected_vias 1 -via_columns 6 -via_rows 9
deselectAll

# Via resize VSS
#VSS
  #M9->M8
editSelectVia -net VSS -cut_layer YX
editPowerVia -modify_vias 1 -selected_vias 1 -via_columns 1 -via_rows 2
deselectAll
  #M8->M7
editSelectVia -net VSS -cut_layer A5
editPowerVia -modify_vias 1 -selected_vias 1 -via_columns 2 -via_rows 6
deselectAll
  #M7->M6
editSelectVia -net VSS -cut_layer A4
editPowerVia -modify_vias 1 -selected_vias 1 -via_columns 2 -via_rows 6
deselectAll
  #M6->M5
editSelectVia -net VSS -cut_layer A3
editPowerVia -modify_vias 1 -selected_vias 1 -via_columns 2 -via_rows 6
deselectAll
  #M5->M4
editSelectVia -net VSS -cut_layer A2
editPowerVia -modify_vias 1 -selected_vias 1 -via_columns 2 -via_rows 6
deselectAll
  #M4->M3
editSelectVia -net VSS -cut_layer A1
editPowerVia -modify_vias 1 -selected_vias 1 -via_columns 2 -via_rows 6
deselectAll


# power_stripes_blocks_m7
#VBN VBP (M7) - memories

#Mem First Line

echo "warn: skipped special memories power grid"
# addStripe -nets {VDD_ARR VDD_PER VSS} -layer C5 -direction vertical -width 0.34 -spacing 2 -set_to_set_distance 10 \
# -area {21.282 1233.508 2521.36 955.962} -start_from left -switch_layer_over_obs false -max_same_layer_jog_length 2 \
# -padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 -use_wire_group 0 \
# -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets {VDD_ARR VDD_PER VSS} -layer C5 -direction vertical -width 0.34 -spacing 2 -set_to_set_distance 10 \
 -start_offset 11.282 -start_from left -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 -use_wire_group 0 \
-snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }
# -area $blockage_mem
addStripe -nets {VNW_N VPW_P} -layer C5 -direction vertical -width 0.34 -spacing 2 -set_to_set_distance 10 \
-start_offset 18.302 -start_from left -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 -use_wire_group 0 \
-snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets {VNW_N VPW_P} -layer C5 -direction vertical -width 0.34 -spacing 2 -set_to_set_distance 10 \
 -start_offset 18.302 -start_from left -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 -use_wire_group 0 \
-snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }



# addStripe -nets {VNW_N VPW_P} -layer C5 -direction vertical -width 0.17 -spacing 1 -set_to_set_distance 10 \
# -area {28.302 1233.508 2521.36 955.962} -start_from left -switch_layer_over_obs false -max_same_layer_jog_length 2 \
# -padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 -use_wire_group 0 \
# -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

# #block right 
# addStripe -nets {VDD_ARR VDD_PER VSS} -layer C5 -direction vertical -width 0.34 -spacing 2 -set_to_set_distance 10 \
# -area {2181.282 955.962 2521.36 395.5} -start_from left -switch_layer_over_obs false -max_same_layer_jog_length 2 \
# -padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 -use_wire_group 0 \
# -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

# addStripe -nets {VNW_N VPW_P} -layer C5 -direction vertical -width 0.17 -spacing 1 -set_to_set_distance 10 \
# -area {2188.302 955.962 2521.36 395.5} -start_from left -switch_layer_over_obs false -max_same_layer_jog_length 2 \
# -padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 -use_wire_group 0 \
# -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

# #block left
# addStripe -nets {VDD_ARR VDD_PER VSS} -layer C5 -direction vertical -width 0.34 -spacing 2 -set_to_set_distance 10 \
# -area {21.282 571 435 12} -start_from left -switch_layer_over_obs false -max_same_layer_jog_length 2 \
# -padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 -use_wire_group 0 \
# -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

# addStripe -nets {VNW_N VPW_P} -layer C5 -direction vertical -width 0.17 -spacing 1 -set_to_set_distance 10 \
# -area {28.302 571 435 12} -start_from left -switch_layer_over_obs false -max_same_layer_jog_length 2 \
# -padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 -use_wire_group 0 \
# -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

# # bottom
# addStripe -nets {VDD_ARR VDD_PER VSS} -layer C5 -direction vertical -width 0.34 -spacing 2 -set_to_set_distance 10 \
# -area {435 302 2520 12} -start_from left -switch_layer_over_obs false -max_same_layer_jog_length 2 \
# -padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 -use_wire_group 0 \
# -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

# addStripe -nets {VNW_N VPW_P} -layer C5 -direction vertical -width 0.17 -spacing 1 -set_to_set_distance 10 \
# -area {442.02 302 2520 12} -start_from left -switch_layer_over_obs false -max_same_layer_jog_length 2 \
# -padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 -use_wire_group 0 \
# -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }


# power_grid_m9_m10
setViaGenMode    -reset
setAddStripeMode -reset
setSrouteMode    -reset


setAddStripeMode -ignore_block_check false -break_at none -route_over_rows_only false \
                 -rows_without_stripes_only false -extend_to_closest_target none -stop_at_last_wire_for_area false \
                 -partial_set_thru_domain false -ignore_nondefault_domains false -trim_antenna_back_to_shape none \
                 -spacing_type edge_to_edge -spacing_from_block 0 -stripe_min_length 0 -stacked_via_top_layer LB \
                 -stacked_via_bottom_layer M2 -via_using_exact_crossover_size false -split_vias false -orthogonal_only true \
                 -allow_jog { padcore_ring  block_ring }


#prevent VIA from M10 to M8-M3, just do via on M9
setAddStripeMode -stacked_via_bottom_layer 9 -stacked_via_top_layer 10


#big GRID, vertical

addStripe -nets VDD -layer IB -direction vertical -width 4.546 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 1.9 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VDD_ARR -layer IB -direction vertical -width 1.442 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 8.446 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VDD_PER -layer IB -direction vertical -width 1.442 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 11.888 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VSS -layer IB -direction vertical -width 4.546 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 15.33 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VDD_ARR -layer IB -direction vertical -width 1.442 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 21.876 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VDD_PER -layer IB -direction vertical -width 1.442 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 25.318 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VDD -layer IB -direction vertical -width 4.546 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 28.76 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VNW_N -layer IB -direction vertical -width 1.442 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 35.306 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VPW_P -layer IB -direction vertical -width 1.442 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 38.748 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }

addStripe -nets VDD -layer IB -direction vertical -width 4.546 \
-spacing 0 -set_to_set_distance 50 -start_from top -start 42.19 -switch_layer_over_obs false -max_same_layer_jog_length 2 \
-padcore_ring_top_layer_limit LB -padcore_ring_bottom_layer_limit M1 -block_ring_top_layer_limit LB -block_ring_bottom_layer_limit M1 \
-use_wire_group 0 -snap_wire_center_to_grid None -skip_via_on_pin {  standardcell } -skip_via_on_wire_shape {  noshape }




# FOLOW PINS
setSrouteMode    -reset
sroute -connect { corePin } \
       -allowLayerChange 1 \
       -corePinLayer M1 \
       -targetViaLayerRange [list M1 C1] \
       -layerChangeRange {M1 C1} \
       -allowJogging 0 \
       -nets "VDD VSS"
redraw


