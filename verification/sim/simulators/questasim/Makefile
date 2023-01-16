ifndef PULPISSIMO_ROOT
$(error PULPISSIMO_ROOT is not defined. Please go to pulpissimos toplevel directory and run "source sourceme.sh" first.)
endif

BUILD_DIR = $(PULPISSIMO_ROOT)/build/questa
$(shell mkdir -p $(BUILD_DIR))

include $(PULPISSIMO_ROOT)/utils/utils.mk

## Configuration Variables for Bender, Questasim behavior
BENDER_SCRIPTS_ARGS += -t rtl -t test -t rtl_sim
VSIM_ARGS ?= -64
VLOG_ARGS += -suppress 2583 -suppress 13314 \"+incdir+\$$ROOT/rtl/includes\"
VCOM_ARGS += ""
VOPT_ARGS ?= +acc
VSIM_BIN ?= "vsim"
VSIM_USER_PLUSARGS ?= ""
RISCV_OBJCOPY_BIN ?= 'riscv32-unknown-elf-objcopy'



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
run_sim: $(BUILD_DIR)/app.s19
	ln -sf waves $(BUILD_DIR)/waves
ifeq ($(GUI), '0')
	cd $(BUILD_DIR) && $(VSIM_BIN) $(VSIM_ARGS) -c -do "vsim +BINARY_SREC_PATH='$< vopt_tb; run -all; exit"
else
	cd $(BUILD_DIR) && $(VSIM_BIN) $(VSIM_ARGS) -gui -do "vsim +BINARY_SREC_PATH='$< vopt_tb"
endif

## (Re)Compile PULPissimo using Questasim.
## @param VSIM_BIN=vsim The command to invoke vsim. Default: 'vsim'
## @param VSIM_ARGS='-64' Additional args to supply to vsim during tool invocation
## @param SIM_TOP='tb_pulp' The toplevel module to optimize for simulation. Default: tb_pulp
.PHONY: build
build: $(BUILD_DIR)/compile.tcl
	cd $(BUILD_DIR) && $(VSIM_BIN) $(VSIM_ARGS) -c -do 'source compile.tcl; quit'
	cd $(BUILD_DIR) && $(VSIM_BIN) $(VSIM_ARGS) -c -do 'vopt $(VOPT_ARGS) -o vopt_tb $(SIM_TOP) -work work'
	@echo "Finished building design $SIM_TOP. The optimized design has been stored in a unit called 'vopt_tb'."

## Invoke bender to generate the TCL scripts for compilation with questasim
## @param BENDER_SCRIPTS_ARGS A list of additional arguments for source file filtering supplied to bender.
## @param VLOG_ARGS="-suppress 2583" Additional flags to supply to vlog
## @param VCOM_ARGS="-suppress 2444" Additional flags to supply to vcom
scripts: $(BUILD_DIR)/compile.tcl

# Generate the compile scripts
.PHONY: $(BUILD_DIR)/compile.tcl
$(BUILD_DIR)/compile.tcl: $(PULPISSIMO_ROOT)/Bender.lock | $(PULPISSIMO_UTILS)/bender
	echo 'set ROOT [file normalize [file dirname [info script]]/..]' > $(BUILD_DIR)/compile.tcl
	$(PULPISSIMO_UTILS)/bender script vsim $(BENDER_SCRIPTS_ARGS) --vlog-arg="$(VLOG_ARGS)" --vcom-arg="" | grep -v "set ROOT" >> $(BUILD_DIR)/compile.tcl

# Convert the ELF binary to SREC format for simulation
$(BUILD_DIR)/app.s19: $(EXECUTABLE_PATH)
ifndef EXECUTABLE_PATH
	$(error EXECUTABLE_PATH not provided. Please specify which ELF binary to simulate.)
endif
	$(RISCV_OBJCOPY_BIN) -O srec $(EXECUTABLE_PATH) $(BUILD_DIR)/app.s19

HELP_TITLE=PULPissimo Questasim Simulation
HELP_DESCRIPTION="Invocation targets for compilation and simulation of PULPissimo usin Questasim."
include $(PULPISSIMO_ROOT)/utils/help.mk
.DEFAULT_GOAL := help
