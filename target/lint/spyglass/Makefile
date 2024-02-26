# Copyright 2020 ETH Zurich and University of Bologna

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

#     http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

PROJECT_NAME ?= pulpissimo
PULPISSIMO_ROOT ?= $(shell git rev-parse --show-toplevel)
SG_SHELL_CMD ?= spyglass-2022.06 sg_shell
SG_GUI_CMD ?= spyglass-2022.06 spyglass
SPYGLASS_DIR ?= $(PULPISSIMO_ROOT)/target/lint/spyglass
SPYGLASS_WORKING_DIR = $(PULPISSIMO_ROOT)/build/spyglass

## @section Spyglass Lint

.DEFAULT_GOAL := help
include $(PULPISSIMO_ROOT)/utils/utils.mk

.PHONY: $(SPYGLASS_WORKING_DIR)/sources.f
$(SPYGLASS_WORKING_DIR)/sources.f: $(PULPISSIMO_UTILS)/bender
	mkdir -p $(SPYGLASS_WORKING_DIR)
	$(PULPISSIMO_UTILS)/bender script -t synthesis verilator > $(SPYGLASS_WORKING_DIR)/sources.f

.PHONY: lint_rtl
## Run spyglass lint with rtl_handoff methodology
lint_rtl: $(SPYGLASS_WORKING_DIR)/reports/lint_rtl.report.xml

$(SPYGLASS_WORKING_DIR)/reports/moresimple.rpt: $(SPYGLASS_WORKING_DIR)/sources.f
	echo $(SG_SHELL_CMD)
	cd $(SPYGLASS_WORKING_DIR) && $(SG_SHELL_CMD) -tcl_file_continue_on_error -tcl $(SPYGLASS_DIR)/run_lint_rtl_handoff.tcl

# generate generate junit report from spyglass report
$(SPYGLASS_WORKING_DIR)/reports/lint_rtl.report.xml: $(SPYGLASS_WORKING_DIR)/reports/moresimple.rpt
	$(SPYGLASS_DIR)/convert_report_to_junit.py --error-level error $(SPYGLASS_WORKING_DIR)/reports/moresimple.rpt > $(SPYGLASS_WORKING_DIR)/reports/lint_rtl.report.xml

.PHONY: show_results
## Open the generated lint results in Spyglass GUI
show_results:
	cd $(SPYGLASS_WORKING_DIR) && $(SG_GUI_CMD) -project $(PROJECT_NAME).prj

.PHONY: clean_spyglass clean
## Clean all
clean: clean_spyglass
## Delete the spyglass working directory
clean_spyglass:
	rm -rf $(SPYGLASS_WORKING_DIR)
