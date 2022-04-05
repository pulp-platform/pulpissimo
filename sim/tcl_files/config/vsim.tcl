# Copyright 2022 ETH Zurich and University of Bologna
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Define vsim path and custom variables passed via make
if {[info exists ::env(VSIM_PATH)]} {
    quietly set VSIM_SCRIPTS_PATH $::env(VSIM_PATH)
} {
    quietly set VSIM_SCRIPTS_PATH ./
}

if {[info exists ::env(VSIM_FLAGS)]} {
    quietly set VSIM_FLAGS_TCL $::env(VSIM_FLAGS)
} {
    quietly set VSIM_FLAGS_TCL ""
}

if {[info exists ::env(VSIM_RUNNER_FLAGS)]} {
    quietly set VSIM_FLAGS_TCL "$VSIM_FLAGS_TCL $::env(VSIM_RUNNER_FLAGS)"
}

quietly set vopt_acc_ena ""
if {[info exists ::env(VOPT_ACC_ENA)]} {
  if {$::env(VOPT_ACC_ENA) == "YES"} {
    quietly set vopt_acc_ena "YES"
  }
}


# TODO: The suppress 8386 is too broad and doesnt apply to all questa versions
quietly set warning_args "\
  +nowarnTRAN \
  +nowarnTSCALE \
  +nowarnTFMPC \
  -suppress 8386\
  "

quietly set define_args "\
  +UVM_NO_RELNOTES \
  "

quietly set common_args "\
  $warning_args \
  $define_args \
  "

quietly set custom_args "\
  $VSIM_FLAGS_TCL \
  "

quietly set vsim_custom_args "\
  "

quietly set vopt_args ""
if {$vopt_acc_ena == "YES"} {
  quietly append vopt_args $vopt_args "+acc \
                                       -assertdebug \
                                       -bitscalars \
                                       -fsmdebug \
                                       -linedebug"
}

if {$vopt_args != ""} {
  quietly set vsim_vopt_args "-voptargs=\"$vopt_args\""
} {
  quietly set vsim_vopt_args ""
}


set vsim_cmd "vsim -c -quiet $TB \
              -t ps \
              $common_args \
              $custom_args \
              $vsim_custom_args \
              $vsim_vopt_args \
              "

eval $vsim_cmd

# Added these variables to avoid dummy warnings in the FLL
set StdArithNoWarnings 1
set NumericStdNoWarnings 1

# check exit status in tb and quit the simulation accordingly
proc run_and_exit {} {
    run -all
    if {[info exists ::env(VSIM_EXIT_SIGNAL)]} {
        quit -code [examine -radix decimal sim:$::env(VSIM_EXIT_SIGNAL)]
    } else {
        quit -code [examine -radix decimal sim:/tb_pulp/exit_status]
    }
}
