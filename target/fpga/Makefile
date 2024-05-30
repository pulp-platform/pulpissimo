.DEFAULT_GOAL:=help

PULPISSIMO_ROOT ?= $(shell git rev-parse --show-toplevel)
.DEFAULT_GOAL := help
PULPISSIMO_FPGA_ROOT = $(PULPISSIMO_ROOT)/target/fpga
include $(PULPISSIMO_ROOT)/utils/utils.mk

## @section FPGA Bitstream Generation

all: genesys2 zcu104 nexys_video nexys zedboard zcu102 zcu106 ## Generates the bitstream for all supported boards board.

clean_all: clean_genesys2 clean_zcu104 clean_nexys_video clean_nexys clean_zedboard clean_zcu102 ## Removes synthesis output and bitstreams for all boards.

.PHONY: $(PULPISSIMO_FPGA_ROOT)/pulpissimo/tcl/generated/compile.tcl
$(PULPISSIMO_FPGA_ROOT)/pulpissimo/tcl/generated/compile.tcl:
	mkdir -p $(PULPISSIMO_FPGA_ROOT)/pulpissimo/tcl/generated
	$(PULPISSIMO_UTILS)/bender script vivado -t fpga -t xilinx > $@

## Generates the bistream for the genesys2 board
genesys2: $(PULPISSIMO_FPGA_ROOT)/pulpissimo/tcl/generated/compile.tcl
	$(MAKE) -C $(PULPISSIMO_FPGA_ROOT)/pulpissimo-genesys2 all
	cp $(PULPISSIMO_FPGA_ROOT)/pulpissimo-genesys2/pulpissimo-genesys2.runs/impl_1/xilinx_pulpissimo.bit $(PULPISSIMO_FPGA_ROOT)/pulpissimo_genesys2.bit
	cp $(PULPISSIMO_FPGA_ROOT)/pulpissimo-genesys2/pulpissimo-genesys2.runs/impl_1/xilinx_pulpissimo.bin $(PULPISSIMO_FPGA_ROOT)/pulpissimo_genesys2.bin
	@echo "Bitstream generation for genesys2 board finished. The bitstream Configuration Memory File was copied to ./pulpissimo_genesys2.bit and ./pulpissimo_genesys2.bin"

## Removes all bitstreams, *.log files and vivado related files (rm -rf vivado*) for the genesys2 board.
clean_genesys2:
	$(MAKE) -C $(PULPISSIMO_FPGA_ROOT)/pulpissimo-genesys2 clean
	rm -f $(PULPISSIMO_FPGA_ROOT)/pulpissimo_genesys2.bit
	rm -f $(PULPISSIMO_FPGA_ROOT)/pulpissimo_genesys2.bin

## Generates the bistream for the zcu104 board
zcu104: $(PULPISSIMO_FPGA_ROOT)/pulpissimo/tcl/generated/compile.tcl
	$(MAKE) -C $(PULPISSIMO_FPGA_ROOT)/pulpissimo-zcu104 all
	cp $(PULPISSIMO_FPGA_ROOT)/pulpissimo-zcu104/pulpissimo-zcu104.runs/impl_1/xilinx_pulpissimo.bit $(PULPISSIMO_FPGA_ROOT)/pulpissimo_zcu104.bit
	cp $(PULPISSIMO_FPGA_ROOT)/pulpissimo-zcu104/pulpissimo-zcu104.runs/impl_1/xilinx_pulpissimo.bin $(PULPISSIMO_FPGA_ROOT)/pulpissimo_zcu104.bin
	@echo "Bitstream generation for zcu104 board finished. The bitstream Configuration Memory File was copied to ./pulpissimo_zcu104.bit and ./pulpissimo_zcu104.bin"

## Removes all bitstreams, *.log files and vivado related files (rm -rf vivado*) for the zcu104 board.
clean_zcu104:
	$(MAKE) -C $(PULPISSIMO_FPGA_ROOT)/pulpissimo-zcu104 clean
	rm -f $(PULPISSIMO_FPGA_ROOT)/pulpissimo_zcu104.bit
	rm -f $(PULPISSIMO_FPGA_ROOT)/pulpissimo_zcu104.bin

## Generates the bistream for the zcu104 board
zcu106: $(PULPISSIMO_FPGA_ROOT)/pulpissimo/tcl/generated/compile.tcl
	$(MAKE) -C $(PULPISSIMO_FPGA_ROOT)/pulpissimo-zcu106 all
	cp $(PULPISSIMO_FPGA_ROOT)/pulpissimo-zcu106/pulpissimo-zcu106.runs/impl_1/xilinx_pulpissimo.bit $(PULPISSIMO_FPGA_ROOT)/pulpissimo_zcu106.bit
	cp $(PULPISSIMO_FPGA_ROOT)/pulpissimo-zcu106/pulpissimo-zcu106.runs/impl_1/xilinx_pulpissimo.bin $(PULPISSIMO_FPGA_ROOT)/pulpissimo_zcu106.bin
	@echo "Bitstream generation for zcu106 board finished. The bitstream Configuration Memory File was copied to ./pulpissimo_zcu106.bit and ./pulpissimo_zcu106.bin"

## Removes all bitstreams, *.log files and vivado related files (rm -rf vivado*) for the zcu104 board.
clean_zcu106:
	$(MAKE) -C $(PULPISSIMO_FPGA_ROOT)/pulpissimo-zcu106 clean
	rm -f $(PULPISSIMO_FPGA_ROOT)/pulpissimo_zcu106.bit
	rm -f $(PULPISSIMO_FPGA_ROOT)/pulpissimo_zcu106.bin

## Generates the bistream for the nexys_video board
nexys_video: $(PULPISSIMO_FPGA_ROOT)/pulpissimo/tcl/generated/compile.tcl
	$(MAKE) -C $(PULPISSIMO_FPGA_ROOT)/pulpissimo-nexys_video all
	cp $(PULPISSIMO_FPGA_ROOT)/pulpissimo-nexys_video/pulpissimo-nexys_video.runs/impl_1/xilinx_pulpissimo.bit $(PULPISSIMO_FPGA_ROOT)/pulpissimo_nexys_video.bit
	cp $(PULPISSIMO_FPGA_ROOT)/pulpissimo-nexys_video/pulpissimo-nexys_video.runs/impl_1/xilinx_pulpissimo.bin $(PULPISSIMO_FPGA_ROOT)/pulpissimo_nexys_video.bin
	@echo "Bitstream generation for nexys_video board finished. The bitstream Configuration Memory File was copied to ./pulpissimo_nexys_video.bit and ./pulpissimo_nexys_video.bin"

## Removes all bitstreams, *.log files and vivado related files (rm -rf vivado*) for the nexys_video board.
clean_nexys_video:
	$(MAKE) -C $(PULPISSIMO_FPGA_ROOT)/pulpissimo-nexys_video clean
	rm -f $(PULPISSIMO_FPGA_ROOT)/pulpissimo_nexys_video.bit
	rm -f $(PULPISSIMO_FPGA_ROOT)/pulpissimo_nexys_video.bin

## Generates the bistream for the nexys board. Use make nexys rev=[nexys4|nexys4DDR|nexysA7-50T|nexysA7-100T]
nexys: $(PULPISSIMO_FPGA_ROOT)/pulpissimo/tcl/generated/compile.tcl
	$(MAKE) -C $(PULPISSIMO_FPGA_ROOT)/pulpissimo-nexys all
	cp $(PULPISSIMO_FPGA_ROOT)/pulpissimo-nexys/pulpissimo-nexys.runs/impl_1/xilinx_pulpissimo.bit $(PULPISSIMO_FPGA_ROOT)/pulpissimo_nexys.bit
	cp $(PULPISSIMO_FPGA_ROOT)/pulpissimo-nexys/pulpissimo-nexys.runs/impl_1/xilinx_pulpissimo.bin $(PULPISSIMO_FPGA_ROOT)/pulpissimo_nexys.bin
	@echo "Bitstream generation for nexys board finished. The bitstream Configuration Memory File was copied to ./pulpissimo_nexys.bit and ./pulpissimo_nexys.bin"

## Removes all bitstreams, *.log files and vivado related files (rm -rf vivado*) for the nexys board.
clean_nexys:
	$(MAKE) -C $(PULPISSIMO_FPGA_ROOT)/pulpissimo-nexys clean
	rm -f $(PULPISSIMO_FPGA_ROOT)/pulpissimo_nexys.bit
	rm -f $(PULPISSIMO_FPGA_ROOT)/pulpissimo_nexys.bin

## Generates the bistream for the vcu108 board
vcu108: $(PULPISSIMO_FPGA_ROOT)/pulpissimo/tcl/generated/compile.tcl
	$(MAKE) -C $(PULPISSIMO_FPGA_ROOT)/pulpissimo-vcu108 all
	cp $(PULPISSIMO_FPGA_ROOT)/pulpissimo-vcu108/pulpissimo-vcu108.runs/impl_1/xilinx_pulpissimo.bit $(PULPISSIMO_FPGA_ROOT)/pulpissimo_vcu108.bit
	cp $(PULPISSIMO_FPGA_ROOT)/pulpissimo-vcu108/pulpissimo-vcu108.runs/impl_1/xilinx_pulpissimo.bin $(PULPISSIMO_FPGA_ROOT)/pulpissimo_vcu108.bin
	@echo "Bitstream generation for vcu108 board finished. The bitstream Configuration Memory File was copied to ./pulpissimo_vcu108.bit and ./pulpissimo_vcu108.bin"

## Removes all bitstreams, *.log files and vivado related files (rm -rf vivado*) for the vcu108 board.
clean_vcu108:
	$(MAKE) -C $(PULPISSIMO_FPGA_ROOT)/pulpissimo-vcu108 clean
	rm -f $(PULPISSIMO_FPGA_ROOT)/pulpissimo_vcu108.bit
	rm -f $(PULPISSIMO_FPGA_ROOT)/pulpissimo_vcu108.bin

## Generates the bistream for the ZedBoard
zedboard: $(PULPISSIMO_FPGA_ROOT)/pulpissimo/tcl/generated/compile.tcl
	$(MAKE) -C $(PULPISSIMO_FPGA_ROOT)/pulpissimo-zedboard all
	cp $(PULPISSIMO_FPGA_ROOT)/pulpissimo-zedboard/pulpissimo-zedboard.runs/impl_1/xilinx_pulpissimo.bit $(PULPISSIMO_FPGA_ROOT)/pulpissimo_zedboard.bit
	cp $(PULPISSIMO_FPGA_ROOT)/pulpissimo-zedboard/pulpissimo-zedboard.runs/impl_1/xilinx_pulpissimo.bin $(PULPISSIMO_FPGA_ROOT)/pulpissimo_zedboard.bin
	@echo "Bitstream generation for ZedBoard finished. The bitstream Configuration Memory File was copied to ./pulpissimo_zedboard.bit and ./pulpissimo_zedboard.bin"

## Removes all bitstreams, *.log files and vivado related files (rm -rf vivado*) for the ZedBoard.
clean_zedboard:
	$(MAKE) -C $(PULPISSIMO_FPGA_ROOT)/pulpissimo-zedboard clean
	rm -f $(PULPISSIMO_FPGA_ROOT)/pulpissimo_zedboard.bit
	rm -f $(PULPISSIMO_FPGA_ROOT)/pulpissimo_zedboard.bin

## Generates the bistream for the zcu102 board
zcu102: $(PULPISSIMO_FPGA_ROOT)/pulpissimo/tcl/generated/compile.tcl
	$(MAKE) -C $(PULPISSIMO_FPGA_ROOT)/pulpissimo-zcu102 all
	cp $(PULPISSIMO_FPGA_ROOT)/pulpissimo-zcu102/pulpissimo-zcu102.runs/impl_1/xilinx_pulpissimo.bit $(PULPISSIMO_FPGA_ROOT)/pulpissimo_zcu102.bit
	cp $(PULPISSIMO_FPGA_ROOT)/pulpissimo-zcu102/pulpissimo-zcu102.runs/impl_1/xilinx_pulpissimo.bin $(PULPISSIMO_FPGA_ROOT)/pulpissimo_zcu102.bin
	@echo "Bitstream generation for zcu102 board finished. The bitstream Configuration Memory File was copied to ./pulpissimo_zcu102.bit and ./pulpissimo_zcu102.bin"

## Removes all bitstreams, *.log files and vivado related files (rm -rf vivado*) for the zcu102 board.
clean_zcu102:
	$(MAKE) -C $(PULPISSIMO_FPGA_ROOT)/pulpissimo-zcu102 clean
	rm -f $(PULPISSIMO_FPGA_ROOT)/pulpissimo_zcu102.bit
	rm -f $(PULPISSIMO_FPGA_ROOT)/pulpissimo_zcu102.bin
