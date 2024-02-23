# Copyright 2024 ETH Zurich and University of Bologna

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

#     http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

PULPISSIMO_ROOT ?= $(shell git rev-parse --show-toplevel)

QUESTA_BUILD_DIR = $(PULPISSIMO_ROOT)/build/questasim

include $(PULPISSIMO_ROOT)/utils/utils.mk

## Configuration Variables for Bender, Questasim behavior
BENDER_SCRIPTS_ARGS += -t rtl -t test -t rtl_sim
VSIM_ARGS ?= -64
VLOG_ARGS += -suppress 2583 -suppress 13314 \"+incdir+\$$ROOT/hw/includes\"
VCOM_ARGS += ""
VOPT_ARGS ?= +acc
VSIM_BIN ?= "vsim"
VSIM_USER_PLUSARGS ?= ""
RISCV_OBJCOPY_BIN ?= 'riscv32-unknown-elf-objcopy'
SIM_TOP ?= 'tb_pulp'



## @section Questasim Simulation

## Simulate the given executable using RTL simulationon with Siemens QuestaSIM.
## 
## The simulation can be invoked in various bootmode controllable via the
## bootmode parameter. The 'jtag_legacy' boot mode uses the legacy PULP JTAG TAP
## to preload the binary into L2 memory. 'jtag_openocd' uses the newer,
## standardized RISC-V JTAG debug module for preloading (much slower than legacy
## in simulation). 'fastboot' Uses virtual through hierarchy connection in the
## testbench to provide very fast preloading. However this mode is not
## physically possible and cannot be used in real systems. Don't use this for
## bootability verification!
##
## @param EXECUTABLE_PATH=/path/to/elf_binary/build/app The absolute path to the ELF binary to simulate
## @param GUI=1 If 1, start QuestaSIM in GUI mode, otherwise start in batch mode.
## @param VSIM_BIN=vsim The command to invoke the vsim binary.
## @param BOOTMODE=jtag The bootmode to use to start PULPissimo. Possible values: jtag_legacy, jtag_openocd or fastboot. 
.PHONY: run_sim
run_sim: $(QUESTA_BUILD_DIR)/app.s19
	ln -sf waves $(QUESTA_BUILD_DIR)/waves
ifeq ($(GUI), '0')
	cd $(QUESTA_BUILD_DIR) && $(VSIM_BIN) $(VSIM_ARGS) -c -do "vsim +BINARY_SREC_PATH='$< vopt_tb; run -all; exit"
else
	cd $(QUESTA_BUILD_DIR) && $(VSIM_BIN) $(VSIM_ARGS) -gui -do "vsim +BINARY_SREC_PATH='$< vopt_tb"
endif

## (Re)Compile PULPissimo using Questasim.
## @param VSIM_BIN=vsim The command to invoke vsim. Default: 'vsim'
## @param VSIM_ARGS='-64' Additional args to supply to vsim during tool invocation
## @param SIM_TOP='tb_pulp' The toplevel module to optimize for simulation. Default: tb_pulp
.PHONY: build
build: $(QUESTA_BUILD_DIR)/compile.tcl
	cd $(QUESTA_BUILD_DIR) && $(VSIM_BIN) $(VSIM_ARGS) -c -do 'source compile.tcl; quit'
	cd $(QUESTA_BUILD_DIR) && $(VSIM_BIN) $(VSIM_ARGS) -c -do 'vopt $(VOPT_ARGS) -o vopt_tb $(SIM_TOP) -work work; quit'
	@ln -s $(PULPISSIMO_ROOT)/target/sim/questasim/waves $(QUESTA_BUILD_DIR)/waves
	@ln -s $(PULPISSIMO_ROOT)/target/sim/questasim/tcl_files $(QUESTA_BUILD_DIR)/tcl_files
	@echo "Finished building design $(SIM_TOP). The optimized design has been stored in a unit called 'vopt_tb'."
ifneq ($(VSIM_PATH), $(PULPISSIMO_ROOT)/build/questasim)
	@echo ""
	@echo "To run a simulation directly with the PULP runtime or SDK \`make run\` commands execute the following:"
	@echo ""
	@echo "	export VSIM_PATH=$(PULPISSIMO_ROOT)/build/questasim"
ifneq (,$(wildcard /etc/iis.version))
	@echo "	export VSIM=\"$(VSIM_BIN)\""
endif
	@echo ""
endif

## Invoke bender to generate the TCL scripts for compilation with questasim
## @param BENDER_SCRIPTS_ARGS A list of additional arguments for source file filtering supplied to bender.
## @param VLOG_ARGS="-suppress 2583" Additional flags to supply to vlog
## @param VCOM_ARGS="-suppress 2444" Additional flags to supply to vcom
scripts: $(QUESTA_BUILD_DIR)/compile.tcl

.PHONY: clean_questasim clean
## Clean all
clean: clean_questasim
## Clean up files left to build and run simulation
clean_questasim:
	rm -rf $(QUESTA_BUILD_DIR)

# Generate the compile scripts
.PHONY: $(QUESTA_BUILD_DIR)/compile.tcl
$(QUESTA_BUILD_DIR)/compile.tcl: $(PULPISSIMO_ROOT)/Bender.lock | $(PULPISSIMO_UTILS)/bender
	mkdir -p $(QUESTA_BUILD_DIR)
	echo 'set ROOT [file normalize [file dirname [info script]]/../..]' > $(QUESTA_BUILD_DIR)/compile.tcl
	$(PULPISSIMO_UTILS)/bender script vsim $(BENDER_SCRIPTS_ARGS) --vlog-arg="$(VLOG_ARGS)" --vcom-arg="" | grep -v "set ROOT" >> $(QUESTA_BUILD_DIR)/compile.tcl

# Convert the ELF binary to SREC format for simulation
$(QUESTA_BUILD_DIR)/app.s19: $(EXECUTABLE_PATH)
ifndef EXECUTABLE_PATH
	$(error EXECUTABLE_PATH not provided. Please specify which ELF binary to simulate.)
endif
	$(RISCV_OBJCOPY_BIN) -O srec $(EXECUTABLE_PATH) $(QUESTA_BUILD_DIR)/app.s19

HELP_TITLE=PULPissimo Questasim Simulation
HELP_DESCRIPTION="Invocation targets for compilation and simulation of PULPissimo usin Questasim."
include $(PULPISSIMO_ROOT)/utils/help.mk
.DEFAULT_GOAL := help
