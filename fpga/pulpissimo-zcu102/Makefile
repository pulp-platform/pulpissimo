include fpga-settings.mk

PROJECT:=pulpissimo-$(BOARD)
VIVADO ?= vivado

.DEFAULT_GOAL:=help

.PHONY: help all gui ips clean-ips clk clean-clk clean

#Make sure BENDER environment variable is available for subprocesses in Make
export BENDER

all: ips ## Generate the bitstream for pulpissimo with vivado in batch mode. The vivado invocation command may be overriden with the env variable VIVADO.
	$(VIVADO) -mode batch -source tcl/run.tcl

gui: ips ## Generates the bitstream for pulpissimo with vivado in GUI mode. The vivado invocation command may be overriden with the env variable VIVADO.
	$(VIVADO) -mode gui -source tcl/run.tcl &

ips: clk ## Synthesizes necessary xilinx IP

clean-ips: clean-clk ## Clean all IPs

clk: ## Synthesizes the Xilinx Clocking Manager IPs
	$(MAKE) -C ips/xilinx_clk_mngr all
	$(MAKE) -C ips/xilinx_slow_clk_mngr all

clean-clk: ## Removes all Clocking Wizard IP outputs
	$(MAKE) -C ips/xilinx_clk_mngr clean
	$(MAKE) -C ips/xilinx_slow_clk_mngr clean

clean: ## Removes all bitstreams, *.log files and vivado related files (rm -rf vivado*)
	rm -rf ${PROJECT}.*[^'bit']
	rm -rf ${PROJECT}.*[^'bin']
	rm -rf *.log
	rm -rf vivado*

download: ## Download the bitstream into the FPGA
	$(VIVADO) -mode batch -source tcl/download_bitstream.tcl -tclargs $(PROJECT).runs/impl_1/xilinx_pulpissimo.bit pulpissimo_$(BOARD).bit

help:
	@grep -E -h '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
