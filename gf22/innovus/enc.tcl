###########################################################################
#  Title      : Innovus initial settings
#  Project    : gf 22 dz flow
##########################################################################
#  File       : enc.tcl
#  Author     : Beat Muheim  <muheim@ee.ethz.ch>
#  Company    : Microelectronics Design Center (DZ), ETH Zurich
##########################################################################
#  Description : This script is launched first when Innovus is starting
#  Inputs      : 
#  Outputs     : report_timing_format, timing_defer_mmmc_object_updates,
#                DelayCalMode, env(TMPDIR), DesignMode, ~dbgSitesPerGate
#  Rhesuses    : 
##########################################################################
#  Copyright (c) 2016 Microelectronics Design Center, ETH Zurich
##########################################################################
# v0.2 - <muheim@ee.ethz.ch> - Tue Nov 13 13:15:25 CET 2018
#  - add set multi cpu usage
# v0.1 - <muheim@ee.ethz.ch> - Fri Oct 28 10:36:32 CEST 2016
#  - copy
##########################################################################


# change report timing format to include also the load
set_global report_timing_format {instance arc cell slew load delay arrival}
#set_global timing_report_timing_header_detail_info extended

# alternatively you can also add fanout to the report
#set_global report_timing_format {instance arc cell slew load fanout delay arrival}

# to allowed after CTS to do the reload the constraint withe 
# "set_analysis_view -update_timing" after "update_constraint_mode ..."
set_global timing_defer_mmmc_object_updates true


# To prevent using the signal integrity for timing calculate.
# It also not asking for using Chip Variation doing the timing calculation after
# routing.
setDelayCalMode -siAware false

# set the temp dir
set env(TMPDIR) "$env(PWD)/../tmp"

# set the technology
setDesignMode -process 22

## # umc65 has 4 grid units per gate
## set dbgSitesPerGate 4

## The route settings are don in "encounter_route_options_DFM.tcl"


# set multi cpu usage
setMultiCpuUsage -localCpu max



# suppress message
