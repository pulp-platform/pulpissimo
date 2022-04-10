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

mkfile_path := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))

VSIM            ?= vsim
VSIM_FLAGS	= -gLOAD_L2=JTAG
VSIM_SUPPRESS   = -suppress vsim-3009 -suppress vsim-8683 -suppress vsim-8386

VLOG            ?= vlog
VLOG_FLAGS      =

VOPT            ?= vopt
VOPT_FLAGS      ?= +acc

VLIB            ?= vlib
VMAP            ?= vmap

SVLIB	    =  ../rtl/tb/remote_bitbang/librbs

# top-level (tesbench)
SIM_TOP     = tb_pulp

## Compile RTL with Questasim
all: lib build opt

# build the bitbang library, needed for simulating a jtag bridge to OpenOCD
.PHONY: build-deps
build-deps:
	$(MAKE) -C ../rtl/tb/remote_bitbang all

.PHONY: clean-deps
clean-deps:
	$(MAKE) -C ../rtl/tb/remote_bitbang clean

## vsim targets
.PHONY: sim
## Simulate RTL with Questasim (GUI)
sim:
	$(VSIM) -64 -gui vopt_tb \
		$(VSIM_SUPPRESS) \
		+UVM_NO_RELNOTES -stats -t ps \
		-sv_lib $(SVLIB) $(VSIM_FLAGS) \
		-do "set StdArithNoWarnings 1; set NumericStdNoWarnings 1"
.PHONY: simc
## Simulate RTL with Questasim
simc:
	$(VSIM) -64 -c vopt_tb \
		$(VSIM_SUPPRESS) \
		+UVM_NO_RELNOTES -stats -t ps \
		-sv_lib $(SVLIB) $(VSIM_FLAGS) \
		-do "set StdArithNoWarnings 1; set NumericStdNoWarnings 1" \
		-do "run -all" \
		-do "quit -code [examine -radix decimal sim:/tb_pulp/exit_status]"

.PHONY: opt
opt:
	$(VOPT) $(VOPT_FLAGS) -o vopt_tb $(SIM_TOP) -work work

.PHONY: opt
build: build-deps
	$(VSIM) -c -do 'source compile.tcl; quit'

.PHONY: lib
lib:


.PHONY: clean
## Remove all compiled RTL
clean: clean-deps
	$(RM) -r work 
	$(RM) modelsim.ini


.PHONY: help
help: Makefile
	@printf "PULPissimo\n"
	@printf "Available targets\n\n"
	@awk '/^[a-zA-Z\-\_0-9]+:/ { \
		helpMessage = match(lastLine, /^## (.*)/); \
		if (helpMessage) { \
			helpCommand = substr($$1, 0, index($$1, ":")-1); \
			helpMessage = substr(lastLine, RSTART + 3, RLENGTH); \
			printf "%-15s %s\n", helpCommand, helpMessage; \
		} \
	} \
	{ lastLine = $$0 }' $(MAKEFILE_LIST)
