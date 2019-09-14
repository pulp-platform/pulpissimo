delete_ccopt_clock_tree_spec

#-----------------------------------------------------------------------------------------
# CCOpt Clock Tree Config based on EDI ckSpec
# generated on Tue, Jun 09, 2015 02:29:17 pm CEST
# by Native Mode version 036
#-----------------------------------------------------------------------------------------
if { [dbGet head.routeTypes.name default_route_type_leaf] != "default_route_type_leaf" } {
create_route_type -name default_route_type_leaf -bottom_preferred_layer 1 -top_preferred_layer 6 
}
if { [dbGet head.routeTypes.name default_route_type_nonleaf] != "default_route_type_nonleaf" } {
create_route_type -name default_route_type_nonleaf -bottom_preferred_layer 5 -top_preferred_layer 6
}


# global constraints
#-----------------------------------------------------------------------------------------
# Add that the pads are transparent.
#set_ccopt_property trace_through_to pad_$CLK_PIN/Y -pin pad_$CLK_PIN/PAD
#set_ccopt_property library_trace_through_to IN22FDX_GPIO18_10M30P_IO_V/Y -lib_pin IN22FDX_GPIO18_10M30P_IO_V/PAD
#set_ccopt_property library_trace_through_to IN22FDX_GPIO18_10M30P_IO_H/Y -lib_pin IN22FDX_GPIO18_10M30P_IO_H/PAD

# buffer/inverter/clock_gating cells
set_ccopt_property buffer_cells [ list \
                                  SC8T_CKBUFX10_CSC28L SC8T_CKBUFX12_CSC28L SC8T_CKBUFX16_CSC28L SC8T_CKBUFX1_MR_CSC28L SC8T_CKBUFX1_CSC28L SC8T_CKBUFX20_CSC28L SC8T_CKBUFX2_CSC28L SC8T_CKBUFX4_CSC28L SC8T_CKBUFX6_CSC28L SC8T_CKBUFX8_CSC28L \
                                  SC8T_CKBUFX10_CSC24L SC8T_CKBUFX12_CSC24L SC8T_CKBUFX16_CSC24L SC8T_CKBUFX1_MR_CSC24L SC8T_CKBUFX1_CSC24L SC8T_CKBUFX20_CSC24L SC8T_CKBUFX2_CSC24L SC8T_CKBUFX4_CSC24L SC8T_CKBUFX6_CSC24L SC8T_CKBUFX8_CSC24L \
                                  SC8T_CKBUFX10_CSC20L SC8T_CKBUFX12_CSC20L SC8T_CKBUFX16_CSC20L SC8T_CKBUFX1_MR_CSC20L SC8T_CKBUFX1_CSC20L SC8T_CKBUFX20_CSC20L SC8T_CKBUFX2_CSC20L SC8T_CKBUFX4_CSC20L SC8T_CKBUFX6_CSC20L SC8T_CKBUFX8_CSC20L \
                                ]
set_ccopt_property inverter_cells [ list \
                                    SC8T_CKINVX10_CSC28L SC8T_CKINVX12_CSC28L SC8T_CKINVX16_CSC28L SC8T_CKINVX1_MR_CSC28L SC8T_CKINVX1_CSC28L SC8T_CKINVX20_CSC28L SC8T_CKINVX2_CSC28L SC8T_CKINVX4_CSC28L SC8T_CKINVX6_CSC28L SC8T_CKINVX8_CSC28L \
                                    SC8T_CKINVX10_CSC24L SC8T_CKINVX12_CSC24L SC8T_CKINVX16_CSC24L SC8T_CKINVX1_MR_CSC24L SC8T_CKINVX1_CSC24L SC8T_CKINVX20_CSC24L SC8T_CKINVX2_CSC24L SC8T_CKINVX4_CSC24L SC8T_CKINVX6_CSC24L SC8T_CKINVX8_CSC24L \
                                    SC8T_CKINVX10_CSC20L SC8T_CKINVX12_CSC20L SC8T_CKINVX16_CSC20L SC8T_CKINVX1_MR_CSC20L SC8T_CKINVX1_CSC20L SC8T_CKINVX20_CSC20L SC8T_CKINVX2_CSC20L SC8T_CKINVX4_CSC20L SC8T_CKINVX6_CSC20L SC8T_CKINVX8_CSC20L \
                                  ]
set_ccopt_property clock_gating_cells [ list \
                                        SC8T_CKGPRELATNX1_CSC28L SC8T_CKGPRELATNX2_CSC28L SC8T_CKGPRELATNX4_CSC28L \
                                        SC8T_CKGPRELATNX1_CSC24L SC8T_CKGPRELATNX2_CSC24L SC8T_CKGPRELATNX4_CSC24L \
                                        SC8T_CKGPRELATNX1_CSC20L SC8T_CKGPRELATNX2_CSC20L SC8T_CKGPRELATNX4_CSC20L \
                                      ]

#get ignore and case_analysis pin information from create_ccopt_clock_tree_spec -views func_view
#set_ccopt_property sink_type -pin Clk_CO ignore

#get ignore and case_analysis pin information from create_ccopt_clock_tree_spec -views func_view

# from local ThroughPin constraints (locality only effects skew groups not clock trees)
# and from any local Unsync/Excluded/LeafPin constraints which no other clock passes through
# and so are on the boundary of the clock network
#set_ccopt_property sink_type -pin XXXX stop


# MacroModel constraints
#-----------------------------------------------------------------------------------------

 

# clock tree definitions
#-----------------------------------------------------------------------------------------

# In EDI when two AutoCTSRootPins trace over a common sub-tree the AutoCTSRootPin which appears
# first in the spec file owns the sub-tree for the purposes of DRV/NDR (maxTrans, non-default rules, etc.)
# In CCOpt define_clock_tree is greedy and steels common sub-trees from previously defined clock_tees.
# Also, in CCOpt clock_trees are global and cannot overlap - i.e. they determine only what is in or out
# of the clock network and what DRV/NDRs to apply to different bits of the clock network.
# CCOpt has a separate skew_group construct for defining balancing constraints, and these can overlap.

# There are two side effects of these differences in behavior between EDI and CCOpt:

#  1. We need to reverse the order of define_clock_tree definitions compared to AutoCTSRootPin definitions.

#  2. We need to handle the case where there are dis-continous AutoCTSRootPins, e.g. where
#     the first AutoCTSRootPin to reach a clock mux input has that input as a local UnsyncPin,
#     but another AutoCTSRootPin defined later in the spec file reaches the same mux input and
#     doesn't have a local UnsyncPin. In these situations we need to explicitly define a generated
#     clock_tree on the mux output and explicitly copy over the DRV/NDR settings from the first
#     AutoCTSRootPin to it.

create_ccopt_clock_tree -name clk     -source $CLK_PIN

# promote any clock trees whose source is within one combinational arc of
# another clock tree sink to generated clock trees


# skew group modification based on local constraints
#-----------------------------------------------------------------------------------------
#create_ccopt_skew_group -name SG_clk01 -balance_skew_groups {clk1 clk0}


# skew group skew and ID targets
#-----------------------------------------------------------------------------------------
#set_ccopt_property target_skew -skew_group * 250ps -delay_corner *


# DRV/NDR constraints for clock trees
#-----------------------------------------------------------------------------------------
set_ccopt_property  target_max_trans -clock_tree * 250ps

set_ccopt_property  route_type -net_type trunk -clock_tree * default_route_type_nonleaf
set_ccopt_property  route_type -net_type top   -clock_tree * default_route_type_nonleaf
set_ccopt_property  route_type -net_type leaf  -clock_tree * default_route_type_leaf

set_ccopt_property source_input_max_trans -delay_corner * -clock_tree clk 500.0ps


# ClockGroup constraints
#-----------------------------------------------------------------------------------------


# LeafPinGroup constraints
#-----------------------------------------------------------------------------------------


# DynamicMacroModel constraints
#-----------------------------------------------------------------------------------------


# Preserve* and DontTouchNet constraints
#-----------------------------------------------------------------------------------------


# CellHalo constraints for clock trees
#-----------------------------------------------------------------------------------------


# maxfanout constraints for clock trees
#-----------------------------------------------------------------------------------------

#turn off move_clock_gates" "move_logic" to improve timing
set_ccopt_property move_clock_gates false
set_ccopt_property move_logic false
