##################################################################################										
# (C) Copyright 2015, GLOBALFOUNDRIES, all rights reserved.  													
#										
# This material is provided by GLOBALFOUNDRIES solely on an "AS IS" basis. Neither	
# GLOBALFOUNDRIES nor any of its employees, makes any representations or warranty of	
# any kind, whether express or implied, or assumes any liability or		
# responsibility for the accuracy, completeness, suitability or usefulness of	
# this material or for any damages resulting form its use.			
#										
##################################################################################

# check with PDK Revision: 1.3_2.0 - all DFM relevant vias are defined!
# the 30xVias YV and YW are not DFM relevant 
## Placement options for DP ##
#setPlaceMode -dptFlow true
#setPlaceMode -colorAwarelegal true

## Prevent router modifying M1 pins shapes
setNanoRouteMode -routeWithViaInPin "1:1"
setNanoRouteMode -routeWithViaOnlyForStandardCellPin "1:1"
setNanoRouteMode -routeBottomRoutingLayer 2

## limit VIAs to ongrid only for VIA01 (V1)
setNanoRouteMode -drouteOnGridOnly "via 1:1"

## DFM Via settings
# These DFM via mapping apply to all stacks. 
# You may see "Cannot find VIA matching" warnings in the tool for a particular stack.
## weight multi cut use high and spend more time optimizing dcut use.
# ...ViaEffort low -> to not use multi cut via in detail route - see B-046438
setNanoRouteMode -drouteUseMultiCutViaEffort low
setNanoRouteMode -droutePostRouteSwapVia true

setNanoRouteMode -dbViaWeight "VIA*0_30_0_35_*V1_R 8"
setNanoRouteMode -dbViaWeight "VIA*0_30_0_40_*V1_R 10"
setNanoRouteMode -dbViaWeight "VIA*0_30_0_50_*V1_R 20"
setNanoRouteMode -dbViaWeight "VIA*0_30_0_60_*V1_R 22"
setNanoRouteMode -dbViaWeight "VIA*0_30_2_53_*AY_R 20"
setNanoRouteMode -dbViaWeight "VIA*0_30_2_63_*AY_R 22"
setNanoRouteMode -dbViaWeight "VIA*0_25_0_53_*A*_R 20"
setNanoRouteMode -dbViaWeight "VIA*0_25_0_63_*A*_R 22"

setNanoRouteMode -dbViaWeight "VIA*0_30_20_20_*X_V1 26"
setNanoRouteMode -dbViaWeight "VIA*0_30_20_20_*X_AY 26"
setNanoRouteMode -dbViaWeight "VIA*0_25_18_18_*X_A* 26"

setNanoRouteMode -dbViaWeight "*BAR_V_0_30_20_20_V1 28"
setNanoRouteMode -dbViaWeight "*BAR_H_0_30_22_22_AY_R 28"
setNanoRouteMode -dbViaWeight "*BAR*_22_22_A*_R 28"

setNanoRouteMode -dbViaWeight "VIA*0_30_20_20_*2CUT_V_V1 30"
setNanoRouteMode -dbViaWeight "VIA*0_30_20_20_*2CUT_H_AY 30"
setNanoRouteMode -dbViaWeight "VIA*0_25_18_18_*2CUT_*_A*_R 30"

setNanoRouteMode -dbViaWeight "*2CUT_*_YS 30"
setNanoRouteMode -dbViaWeight "*2CUT_*_WT 30"
setNanoRouteMode -dbViaWeight "*2CUT_*_WA 30"
setNanoRouteMode -dbViaWeight "*2CUT_*_YX 30"
setNanoRouteMode -dbViaWeight "*2CUT_*_YR 30"
setNanoRouteMode -dbViaWeight "*2CUT_*_XD 30"
setNanoRouteMode -dbViaWeight "*2CUT_*_YZ 30"
setNanoRouteMode -dbViaWeight "*2CUT_*_XA 30"
setNanoRouteMode -dbViaWeight "*2CUT_*_JQ 30"
