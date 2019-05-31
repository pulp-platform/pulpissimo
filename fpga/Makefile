.DEFAULT_GOAL:=help

all: genesys2  ## Generates the bitstream for all supported boards board.

clean_all: clean_genesys2 ## Removes synthesis output and bitstreams for all boards.

genesys2: ## Generates the bistream for the genesys2 board
	cd pulpissimo-genesys2; make all
	cp pulpissimo-genesys2/pulpissimo.runs/impl_1/xilinx_pulpissimo.bit pulpissimo_genesys2.bit
	@echo "Bitstream generation for genesys2 board finished. The bitstream was copied to ./pulpissimo_genesys2.bit"

clean_genesys2: ## Removes all bitstreams, *.log files and vivado related files (rm -rf vivado*) for the genesys2 board.
	cd pulpissimo-genesys2; make clean

help: ## Show this help message
	@echo "PULPissimo on FPGA"
	@echo ""
	@echo "Call make with one of the supported FPGA boards as arguments to generate the bitstream in the corresponding folder. "
	@echo "E.g. 'make genesys2' to generate the bitstream for the genesys2 board in pulpissimo-genesy2 subdirectory."
	@echo ""
	@grep -E '^[a-zA-Z0-9_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
