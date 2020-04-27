# required argument: path to bitstream file
open_hw
connect_hw_server
open_hw_target [lindex [get_hw_targets -of_objects [get_hw_servers localhost:*]] 0]
set device [lindex [get_hw_devices] 1]
set_property PROGRAM.FILE [lindex $argv 0] $device
set_property PROBES.FILE {} $device
# set_property FULL_PROBES.FILE {} $device
program_hw_devices $device
exit
