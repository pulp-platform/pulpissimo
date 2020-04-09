#
# Copyright (C) 2015 ETH Zurich, University of Bologna
# All rights reserved.
#
# This software may be modified and distributed under the terms
# of the BSD license.  See the LICENSE file for details.
#

# fix for colors on Ubuntu
SHELL=/bin/bash

# colors
Green=\e[0;92m
Yellow=\e[0;93m
Red=\e[0;91m
NC=\e[0;0m
Blue=\e[0;94m

#CMDs
VLIB_CMD?=vlib
VMAP_CMD?=vmap
VLOG_CMD?=vlog
VCOM_CMD?=vcom

# paths
VSIM_PATH?=.
PULP_PATH?=../..
MSIM_LIBS_PATH=$(VSIM_PATH)/modelsim_libs
IPS_PATH=../ips
RTL_PATH=../rtl
TB_PATH=../tb
LIB_PATH=$(MSIM_LIBS_PATH)/$(LIB_NAME)

# commands
ifndef VERBOSE
	LIB_CREATE=@${VLIB_CMD}
	LIB_MAP=@${VMAP_CMD}
	SVLOG_CC=@${VLOG_CMD} -quiet -sv
	VLOG_CC=@${VLOG_CMD} -quiet
	VHDL_CC=@${VCOM_CMD} -quiet
	subip_echo=@echo -e "  $(NC)Building $(Yellow)$(IP)$(NC)/$(Yellow)$(1)$(NC)"
	ip_echo=@echo -e "$(Green)Built$(NC) $(Yellow)$(IP)$(NC)"
else
	LIB_CREATE=${VLIB_CMD}
	LIB_MAP=${VMAP_CMD}
	SVLOG_CC=${VLOG_CMD} -quiet -sv
	VLOG_CC=${VLOG_CMD} -quiet
	VHDL_CC=${VCOM_CMD} -quiet
	subip_echo=@echo -e "\n$(NC)Building $(Yellow)$(IP)$(NC)/$(Yellow)$(1)$(NC)"
	ip_echo=@echo -e "\n$(Green)Built$(NC) $(Yellow)$(IP)$(NC)"
endif

# rules
.PHONY: build lib clean

build: vcompile-$(IP)
	@true

lib: $(LIB_PATH)

$(LIB_PATH): $(MSIM_LIBS_PATH)
	$(LIB_CREATE) $(LIB_PATH)
	$(LIB_MAP) $(LIB_NAME) $(LIB_PATH)

$(MSIM_LIBS_PATH):
	mkdir -p $(MSIM_LIBS_PATH)

clean:
	rm -rf $(LIB_PATH)
