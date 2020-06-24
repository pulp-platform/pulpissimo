include fpga-settings.mk

PROJECT:=pulpissimo-$(BOARD)
VIVADO ?= vivado

.DEFAULT_GOAL:=help

.PHONY: help all gui ips clean-ips clk clean-clk ram clean-ram clean

all: ips ## Generate the bitstream for pulpissimo with vivado in batch mode. The vivado invocation command may be overriden with the env variable VIVADO.
	$(VIVADO) -mode batch -source tcl/run.tcl

gui: ips ## Generates the bitstream for pulpissimo with vivado in GUI mode. The vivado invocation command may be overriden with the env variable VIVADO.
	$(VIVADO) -mode gui -source tcl/run.tcl &

ips: clk ram ## Synthesizes necessary xilinx IP

clean-ips: clean-clk clean-ram ## Clean all IPs

clk: ## Synthesizes the Xilinx Clocking Manager IPs
	$(MAKE) -C ips/xilinx_clk_mngr all
	$(MAKE) -C ips/xilinx_slow_clk_mngr all

clean-clk: ## Removes all Clocking Wizard IP outputs
	$(MAKE) -C ips/xilinx_clk_mngr clean
	$(MAKE) -C ips/xilinx_slow_clk_mngr clean

ram: ## Synthesizes the Xilinx Block Memory Generator IPs for PULPissimo's L2 Ram
	$(MAKE) -C ips/xilinx_interleaved_ram all
	$(MAKE) -C ips/xilinx_private_ram all

clean-ram: ## Removes all Block Ram IP outputs related to l2 ram
	$(MAKE) -C ips/xilinx_interleaved_ram clean
	$(MAKE) -C ips/xilinx_private_ram clean

clean: ## Removes all bitstreams, *.log files and vivado related files (rm -rf vivado*)
	rm -rf ${PROJECT}.*[^'bit']
	rm -rf ${PROJECT}.*[^'bin']
	rm -rf *.log
	rm -rf vivado*

download: ## Download the bitstream into the FPGA
	$(VIVADO) -mode batch -source tcl/download_bitstream.tcl -tclargs $(PROJECT).runs/impl_1/xilinx_pulpissimo.bit pulpissimo_$(BOARD).bit

help:
	@grep -E -h '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
