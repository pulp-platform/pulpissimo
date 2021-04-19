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
PULP_PATH ?= $(shell git rev-parse --show-toplevel)
SG_SHELL_CMD ?= spyglass-2019.06 sg_shell
SG_GUI_CMD ?= spyglass-2019.06 spyglass

.DEFAULT_GOAL := help

.PHONY: $(PULP_PATH)/spyglass/working_dir/sources.f
$(PULP_PATH)/spyglass/working_dir/sources.f: $(PULP_PATH)/bender
	mkdir -p $(PULP_PATH)/spyglass/working_dir
	$(PULP_PATH)/bender script -t synthesis verilator > $(PULP_PATH)/spyglass/working_dir/sources.f

.PHONY: lint_rtl
## Run spyglass lint with rtl_handoff methodology
lint_rtl: $(PULP_PATH)/spyglass/working_dir/reports/lint_rtl.report.xml

$(PULP_PATH)/spyglass/working_dir/reports/moresimple.rpt: $(PULP_PATH)/spyglass/working_dir/sources.f
	echo $(SG_SHELL_CMD)
	cd $(PULP_PATH)/spyglass/working_dir && $(SG_SHELL_CMD) -tcl_file_continue_on_error -tcl $(PULP_PATH)/spyglass/run_lint_rtl_handoff.tcl

# generate generate junit report from spyglass report
$(PULP_PATH)/spyglass/working_dir/reports/lint_rtl.report.xml: $(PULP_PATH)/spyglass/working_dir/reports/moresimple.rpt
	./convert_report_to_junit.py --error-level error $(PULP_PATH)/spyglass/working_dir/reports/moresimple.rpt > $(PULP_PATH)/spyglass/working_dir/reports/lint_rtl.report.xml

.PHONY: show_results
## Open the generated lint results in Spyglass GUI
show_results:
	cd $(PULP_PATH)/spyglass/working_dir && $(SG_GUI_CMD) -project $(PROJECT_NAME).prj

## Delete the spyglass working directory
.PHONY: clean
clean:
	rm -rf $(PULP_PATH)/spyglass/working_dir

.PHONY: help
help: Makefile
	@printf "PULP Platform\n"
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

