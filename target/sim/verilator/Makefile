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
VERILATOR ?= verilator

VERILATOR_BUILD_DIR = $(PULPISSIMO_ROOT)/build/verilator

VERILATOR_ARGS  = --binary -j 0 -Wno-fatal

# disable all warnings in PULPissimo (at least for now)
VERILATOR_ARGS += -Wno-style \
                  -Wno-timescalemod \
                  -Wno-redefmacro \
                  -Wno-implicit \
                  -Wno-ascrange \
                  -Wno-widthexpand \
                  -Wno-widthconcat \
                  -Wno-misindent \
                  -Wno-pinmissing \
                  -Wno-widthtrunc \
                  -Wno-unsigned \
                  -Wno-cmpconst \
                  -Wno-userfatal \
                  -Wno-caseincomplete \
                  -Wno-combdly \
                  -Wno-latch \
                  -Wno-unoptflat \
				  -Wno-blkandnblk

# activate tracing
VERILATOR_ARGS += --timing --autoflush --trace-fst --trace-structs --trace-params

# workaround for Bender not liking it if I add directly DPI C sources to the Bender.yml
VERILATOR_DPI = \
	$(PULPISSIMO_ROOT)/target/sim/tb/tb_lib/remote_bitbang/sim_jtag.c \
	$(PULPISSIMO_ROOT)/target/sim/tb/tb_lib/remote_bitbang/remote_bitbang.c

$(VERILATOR_BUILD_DIR):
	mkdir -p $@

$(VERILATOR_BUILD_DIR)/pulpissimo.f: Bender.lock Bender.yml $(VERILATOR_BUILD_DIR)
	$(BENDER) script verilator -t tech_cells_generic_include_deprecated -t rtl -t verilator -t rtl_sim -t verilator_dpi -DSYNTHESIS -DVERILATOR > $@
	echo $(VERILATOR_DPI) >> $@

.PHONY: clean-verilator-bender
clean-verilator-bender:
	rm -rf $(VERILATOR_BUILD_DIR)/pulpissimo.f

.PHONY: verilator-bender
verilator-bender: $(VERILATOR_BUILD_DIR)/pulpissimo.f

## Simulate RTL using Verilator
$(VERILATOR_BUILD_DIR)/obj_dir/Vtb_pulp: $(VERILATOR_BUILD_DIR)/pulpissimo.f
	cd $(VERILATOR_BUILD_DIR); $(VERILATOR) $(VERILATOR_ARGS) -CFLAGS "-O2" --top tb_pulp -f  $(VERILATOR_BUILD_DIR)/pulpissimo.f

.PHONY: verilate
verilate: clean-verilator-bender verilator-bender $(VERILATOR_BUILD_DIR)/obj_dir/Vtb_pulp
ifneq ($(VERILATOR_PATH), $(PULPISSIMO_ROOT)/build/verilator)
	@echo ""
	@echo "To run a simulation directly with the PULP runtime or SDK \`make run\` commands execute the following:"
	@echo ""
	@echo "	export VERILATOR_PATH=$(PULPISSIMO_ROOT)/build/verilator"
endif

clean-verilate:
	rm -rf $(VERILATOR_BUILD_DIR)/obj_dir

.PHONY: verilator
