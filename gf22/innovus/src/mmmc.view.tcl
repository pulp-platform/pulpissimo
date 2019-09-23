#########################################################################
#  Title       : Sample to setup the MMMC view definition file.
#  Project     : gf 22 dz flow
##########################################################################
#  File        : mmmc.view.tcl
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
#    Please note these are just for reference, adapt according to your design!
#
##########################################################################
#  Copyright (c) 2016 Microelectronics Design Center, ETH Zurich
##########################################################################
# v0.3  - bm - Tue Nov 21 10:13:37 CET 2017
#  - corect mane for the update_delay_corner typical_delay
# v0.2  - bm - Fri Mar 18 08:41:33 CET 2016
#  - rename 'PD_default' to 'PD_core' amd add 'PD_pad'
# v0.1  - bm - Tue Jan 19 13:14:48 CET 2016
#  - copy from gf28 v0.4 and adapt 
##########################################################################

#################################################################
## INITIALIZATION
#################################################################

## Three delay calculation corners are defined here typical, best, worst
## the long command parses the 


#create_library_set -name typical_libs \
#                   -timing [ list \
#            ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC20L_TT_0P80V_0P00V_0P00V_0P00V_25C.lib.gz \
#            ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC24L_TT_0P80V_0P00V_0P00V_0P00V_25C.lib.gz \
#            ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC28L_TT_0P80V_0P00V_0P00V_0P00V_25C.lib.gz \
#            ../technology/lib/IN22FDX_GPIO18_10M3S30P_TT_0P8_1P8_25.lib \
#            ../memgen/output/model/timing/lib/IN22FDX_R2P_BFRG_W00256B112M02C064_104cpp_TT_0P800V_0P800V_0P000V_0P000V_025C.lib \
#            ../memgen/output/model/timing/lib/IN22FDX_S1D_BFRG_W01024B112M04C128_104cpp_TT_0P800V_0P800V_0P000V_0P000V_025C.lib \
#                           ]

create_library_set -name typical_libs \
                  -timing [ list \
      ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC20L_TT_0P65V_0P00V_0P00V_0P00V_25C.lib.gz \
           ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC24L_TT_0P65V_0P00V_0P00V_0P00V_25C.lib.gz \
           ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC28L_TT_0P65V_0P00V_0P00V_0P00V_25C.lib.gz \
                          ] \
                  -aocv [ list \
           ../technology/aocv/GF22FDX_SC8T_104CPP_BASE_CSC20L_TT_0P65V_0P00V_0P00V_0P00V_25C.aocv \
           ../technology/aocv/GF22FDX_SC8T_104CPP_BASE_CSC24L_TT_0P65V_0P00V_0P00V_0P00V_25C.aocv \
           ../technology/aocv/GF22FDX_SC8T_104CPP_BASE_CSC28L_TT_0P65V_0P00V_0P00V_0P00V_25C.aocv \
                          ]

create_library_set -name typical_fast_libs \
                  -timing [ list \
           ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC20L_TT_0P90V_0P00V_0P00V_0P00V_25C.lib.gz \
           ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC24L_TT_0P90V_0P00V_0P00V_0P00V_25C.lib.gz \
           ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC28L_TT_0P90V_0P00V_0P00V_0P00V_25C.lib.gz \
                          ] \
                  -aocv [ list \
           ../technology/aocv/GF22FDX_SC8T_104CPP_BASE_CSC20L_TT_0P90V_0P00V_0P00V_0P00V_25C.aocv \
           ../technology/aocv/GF22FDX_SC8T_104CPP_BASE_CSC24L_TT_0P90V_0P00V_0P00V_0P00V_25C.aocv \
           ../technology/aocv/GF22FDX_SC8T_104CPP_BASE_CSC28L_TT_0P90V_0P00V_0P00V_0P00V_25C.aocv \
                          ]


# use the worst case corner as typical
# create_library_set -name typical_libs \
#                    -timing [ list \
#             ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC20L_SSG_0P59V_0P00V_0P00V_0P00V_125C.lib.gz \
#             ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC24L_SSG_0P59V_0P00V_0P00V_0P00V_125C.lib.gz \
#             ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC28L_SSG_0P59V_0P00V_0P00V_0P00V_125C.lib.gz \
#             ../memgen/output/model/timing/lib/IN22FDX_S1D_BFRG_W01024B112M04C128_104cpp_SSG_0P590V_0P720V_0P800V_M0P800V_125C.lib \
#                            ]



#create_library_set -name best_libs \
#                   -timing [ list \
#            ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC20L_FFG_0P88V_0P00V_0P00V_0P00V_M40C.lib.gz \
#            ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC24L_FFG_0P88V_0P00V_0P00V_0P00V_M40C.lib.gz \
#            ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC28L_FFG_0P88V_0P00V_0P00V_0P00V_M40C.lib.gz \
#            ../technology/lib/IN22FDX_GPIO18_10M3S30P_FFG_0P88_1P98_M40.lib \
#            ../memgen/output/model/timing/lib/IN22FDX_R2P_BFRG_W00256B112M02C064_104cpp_TT_0P800V_0P800V_0P000V_0P000V_025C.lib \
#            ../memgen/output/model/timing/lib/IN22FDX_S1D_BFRG_W01024B112M04C128_104cpp_FFG_0P720V_0P880V_0P000V_0P000V_M40C.lib \
                           ]

create_library_set -name best_libs \
                   -timing [ list \
            ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC20L_FFG_0P88V_0P00V_0P00V_0P00V_125C.lib.gz \
            ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC24L_FFG_0P88V_0P00V_0P00V_0P00V_125C.lib.gz \
            ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC28L_FFG_0P88V_0P00V_0P00V_0P00V_125C.lib.gz \
                           ] \
                  -aocv [ list \
            ../technology/aocv/GF22FDX_SC8T_104CPP_BASE_CSC20L_FFG_0P88V_0P00V_0P00V_0P00V_125C.aocv \
            ../technology/aocv/GF22FDX_SC8T_104CPP_BASE_CSC24L_FFG_0P88V_0P00V_0P00V_0P00V_125C.aocv \
            ../technology/aocv/GF22FDX_SC8T_104CPP_BASE_CSC28L_FFG_0P88V_0P00V_0P00V_0P00V_125C.aocv \
            ]



#create_library_set -name worst_libs \
#                   -timing [ list \
#            ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC20L_SSG_0P72V_0P00V_0P00V_0P00V_125C.lib.gz \
#            ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC24L_SSG_0P72V_0P00V_0P00V_0P00V_125C.lib.gz \
#            ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC28L_SSG_0P72V_0P00V_0P00V_0P00V_125C.lib.gz \
#            ../technology/lib/IN22FDX_GPIO18_10M3S30P_SSG_0P72_1P62_125.lib \
#            ../memgen/output/model/timing/lib/IN22FDX_R2P_BFRG_W00256B112M02C064_104cpp_TT_0P800V_0P800V_0P000V_0P000V_025C.lib \
#            ../memgen/output/model/timing/lib/IN22FDX_S1D_BFRG_W01024B112M04C128_104cpp_SSG_0P720V_0P720V_0P000V_0P000V_125C.lib \
#                           ]

create_library_set -name worst_libs \
                   -timing [ list \
            ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC20L_SSG_0P59V_0P00V_0P00V_0P00V_125C.lib.gz \
            ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC24L_SSG_0P59V_0P00V_0P00V_0P00V_125C.lib.gz \
            ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC28L_SSG_0P59V_0P00V_0P00V_0P00V_125C.lib.gz \
                           ] \
                  -aocv [ list \
            ../technology/aocv/GF22FDX_SC8T_104CPP_BASE_CSC20L_SSG_0P59V_0P00V_0P00V_0P00V_125C.aocv \
            ../technology/aocv/GF22FDX_SC8T_104CPP_BASE_CSC24L_SSG_0P59V_0P00V_0P00V_0P00V_125C.aocv \
            ../technology/aocv/GF22FDX_SC8T_104CPP_BASE_CSC28L_SSG_0P59V_0P00V_0P00V_0P00V_125C.aocv \
                           ]



 #../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC20SL_TT_0P80V_0P00V_0P00V_0P00V_25C.lib \
#../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC24SL_TT_0P80V_0P00V_0P00V_0P00V_25C.lib \
#../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC28SL_TT_0P80V_0P00V_0P00V_0P00V_25C.lib \


# ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC20SL_FFG_0P88V_0P00V_0P00V_0P00V_M40C.lib \
# ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC24SL_FFG_0P88V_0P00V_0P00V_0P00V_M40C.lib \
# ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC28SL_FFG_0P88V_0P00V_0P00V_0P00V_M40C.lib \

# ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC20SL_SSG_0P72V_0P00V_0P00V_0P00V_125C.lib \
# ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC24SL_SSG_0P72V_0P00V_0P00V_0P00V_125C.lib \
# ../technology/lib/GF22FDX_SC8T_104CPP_BASE_CSC28SL_SSG_0P72V_0P00V_0P00V_0P00V_125C.lib \


# RC corners


create_rc_corner -name typical_rc -qx_tech_file ../technology/qrc/qrcTechFile_nominal


create_rc_corner -name best_rc    -qx_tech_file ../technology/qrc/qrcTechFile_FuncCminDP


create_rc_corner -name worst_rc   -qx_tech_file ../technology/qrc/qrcTechFile_FuncCmaxDP


## Three delay corners are defined here
create_delay_corner -name typical_delay -library_set typical_libs -rc_corner typical_rc
create_delay_corner -name best_delay    -library_set best_libs    -rc_corner best_rc
create_delay_corner -name worst_delay   -library_set worst_libs   -rc_corner worst_rc

create_delay_corner -name typical_fast_delay -library_set typical_fast_libs -rc_corner typical_rc
# update_delay_corner -name typical_delay    -library_set typical_libs -rc_corner typical_rc -power_domain PD_core
# update_delay_corner -name best_delay    -library_set best_libs    -rc_corner best_rc    -power_domain PD_core
# update_delay_corner -name worst_delay   -library_set worst_libs   -rc_corner worst_rc   -power_domain PD_core

# update_delay_corner -name typical_delay    -library_set typical_libs -rc_corner typical_rc -power_domain PD_pad
# update_delay_corner -name best_delay    -library_set best_libs    -rc_corner best_rc    -power_domain PD_pad
# update_delay_corner -name worst_delay   -library_set worst_libs   -rc_corner worst_rc   -power_domain PD_pad

#update_delay_corner -name typical_delay    -library_set typical_libs -rc_corner typical_rc -power_domain PD_cluster
#update_delay_corner -name best_delay    -library_set best_libs    -rc_corner best_rc    -power_domain PD_cluster
#update_delay_corner -name worst_delay   -library_set worst_libs   -rc_corner worst_rc   -power_domain PD_cluster

#################################################################
## LOAD CONSTRAINTS
#################################################################

## Here the SDC files that are part of MMMC flow are defined. 
## In this fictional example we have three modes 
##  1) functional: standard mode where the chip is functioning normally,
##                 timing paths from test inputs are disabled
##  2) test      : works with a slower clock, timing paths from test 
##                 inputs are enabled
##  3) hold      : Timing mode to check hold violations covers both cases.
##
## Each of the above mode will have their own constraints defined in a 
## separate SDC file. IN addition, there is a mmmc_shared.sdc that contains
## constraints that are common between two modes. These are just examples, 
## adjust according to your own requirements
##
create_constraint_mode -name func_mode -sdc_files [list src/mmmc_functional.sdc src/mmmc_shared.sdc ]   
create_constraint_mode -name test_mode -sdc_files [list src/mmmc_test.sdc src/mmmc_shared.sdc ]  

## now we create a view that combined the MODE with the CORNER
## hence the name Multi MODE multi CORNER.
##
## This example uses three views:
##
create_analysis_view -name func_view -delay_corner typical_delay         -constraint_mode func_mode
create_analysis_view -name test_view -delay_corner typical_delay         -constraint_mode test_mode
create_analysis_view -name hold_view -delay_corner best_delay            -constraint_mode test_mode
create_analysis_view -name func_fast -delay_corner typical_fast_delay    -constraint_mode func_mode

#################################################################
## SET ANALYSIS VIEWS
#################################################################

## This command determines which VIEWS will be used for analysis. In this
## example we use both 'functional' and 'test_mode' when doing setup analysis
## and we use only the 'hold' view when doing hold analysis. 

create_rc_corner -name rccCmaxDP_125C -T 125 -qx_tech_file ../technology/qrc/qrcTechFile_FuncCmaxDP
create_rc_corner -name rccCminDP_125C -T 125 -qx_tech_file ../technology/qrc/qrcTechFile_FuncCminDP
create_rc_corner -name rccRCmaxDP_125C -T 125 -qx_tech_file ../technology/qrc/qrcTechFile_FuncRCmaxDP
create_rc_corner -name rccRCminDP_125C -T 125 -qx_tech_file ../technology/qrc/qrcTechFile_FuncRCminDP
create_rc_corner -name rccCmaxDP_m40C -T -40 -qx_tech_file ../technology/qrc/qrcTechFile_FuncCmaxDP
create_rc_corner -name rccCminDP_m40C -T -40 -qx_tech_file ../technology/qrc/qrcTechFile_FuncCminDP
create_rc_corner -name rccRCmaxDP_m40C -T -40 -qx_tech_file ../technology/qrc/qrcTechFile_FuncRCmaxDP
create_rc_corner -name rccRCminDP_m40C -T -40 -qx_tech_file ../technology/qrc/qrcTechFile_FuncRCminDP

create_delay_corner -name best_delay_rccCminDP_125C    -library_set best_libs    -rc_corner rccCminDP_125C
create_delay_corner -name best_delay_rccRCminDP_125C   -library_set best_libs    -rc_corner rccRCminDP_125C
create_delay_corner -name best_delay_rccCminDP_m40C    -library_set best_libs    -rc_corner rccCminDP_m40C
create_delay_corner -name best_delay_rccRCminDP_m40C   -library_set best_libs    -rc_corner rccRCminDP_m40C

create_delay_corner -name worst_delay_rccCmaxDP_125C  -library_set worst_libs -rc_corner rccCmaxDP_125C 
create_delay_corner -name worst_delay_rccRCmaxDP_125C -library_set worst_libs -rc_corner rccRCmaxDP_125C
create_delay_corner -name worst_delay_rccCmaxDP_m40C  -library_set worst_libs -rc_corner rccCmaxDP_m40C 
create_delay_corner -name worst_delay_rccRCmaxDP_m40C -library_set worst_libs -rc_corner rccRCmaxDP_m40C

create_analysis_view -name view_func_best_delay_rccCminDP_125C  -delay_corner best_delay_rccCminDP_125C  -constraint_mode func_mode
create_analysis_view -name view_func_best_delay_rccRCminDP_125C -delay_corner best_delay_rccRCminDP_125C -constraint_mode func_mode 
create_analysis_view -name view_func_best_delay_rccCminDP_m40C  -delay_corner best_delay_rccCminDP_m40C  -constraint_mode func_mode 
create_analysis_view -name view_func_best_delay_rccRCminDP_m40C -delay_corner best_delay_rccRCminDP_m40C -constraint_mode func_mode 

create_analysis_view -name view_test_best_delay_rccCminDP_125C  -delay_corner best_delay_rccCminDP_125C  -constraint_mode test_mode
create_analysis_view -name view_test_best_delay_rccRCminDP_125C -delay_corner best_delay_rccRCminDP_125C -constraint_mode test_mode 
create_analysis_view -name view_test_best_delay_rccCminDP_m40C  -delay_corner best_delay_rccCminDP_m40C  -constraint_mode test_mode 
create_analysis_view -name view_test_best_delay_rccRCminDP_m40C -delay_corner best_delay_rccRCminDP_m40C -constraint_mode test_mode 

create_analysis_view -name view_worst_delay_rccCmaxDP_125C  -delay_corner worst_delay_rccCmaxDP_125C  -constraint_mode func_mode
create_analysis_view -name view_worst_delay_rccRCmaxDP_125C -delay_corner worst_delay_rccRCmaxDP_125C -constraint_mode func_mode 
create_analysis_view -name view_worst_delay_rccCmaxDP_m40C  -delay_corner worst_delay_rccCmaxDP_m40C  -constraint_mode func_mode 
create_analysis_view -name view_worst_delay_rccRCmaxDP_m40C -delay_corner worst_delay_rccRCmaxDP_m40C -constraint_mode func_mode 

set_analysis_view -setup { func_view test_view  } \
                  -hold  { hold_view view_func_best_delay_rccCminDP_125C  \
                                     view_func_best_delay_rccRCminDP_125C \
                                     view_func_best_delay_rccCminDP_m40C  \
                                     view_func_best_delay_rccRCminDP_m40C \
                                     view_test_best_delay_rccCminDP_125C  \
                                     view_test_best_delay_rccRCminDP_125C \
                                     view_test_best_delay_rccCminDP_m40C  \
                                     view_test_best_delay_rccRCminDP_m40C }
 
## *IMPORTANT* It is actually possible that due to the differences in modelling,
##             for some circuits it could actually be possible that hold violations
##             can occur for 'typical' or 'worst' timing. We would advise to create
##             hold views with three different delay corners, just to make sure that this
##             is not the case. 
                  
                  
## The MMMC will affect the way some of the commands are going to work:
## use:
##   timeDesign -expandedViews
## to get separate reports for each view

#set mems  [all_registers -macros ]
#set icgs  [filter_collection [all_registers] "is_integrated_clock_gating_cell == true"]
#set regs [all_registers]
#set ff  [remove_from_collection [all_registers -edge_triggered] $icgs]

#Create Mem Path Groups
#group_path   -name Reg2Mem      -from $regs -to $mems
#group_path   -name Mem2Reg      -from $mems -to $regs
#group_path   -name Mem2Mem      -from $mems -to $mems

#Create FF Path Groups
#group_path   -name ff2ff        -from $ff -to $ff
#group_path   -name reg2ff       -from $regs -to $ff
#group_path   -name ff2reg       -from $ff -to $regs
                #  
