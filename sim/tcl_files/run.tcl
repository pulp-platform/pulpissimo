#!/bin/bash

set TB "vopt_tb -L models_lib -L vip_lib +no_glitch_msg -voptargs=\"+acc=pn\""
#set TB "vopt_tb -L models_lib -L vip_lib"


source ./tcl_files/config/vsim.tcl
