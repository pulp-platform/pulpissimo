# Copyright 2022 ETH Zurich and University of Bologna
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Author: Manuel Eggimann

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(notdir $(patsubst %/,%,$(dir $(mkfile_path))))
PULPISSIMO_ROOT=$(abspath $(current_dir)/..)

ifneq (,$(wildcard /etc/iis.version))
	include $(PULPISSIMO_ROOT)/utils/iis-env.mk
endif

include target/sim/questasim/Makefile
include $(PULPISSIMO_ROOT)/utils/utils.mk


HELP_TITLE="PULPissimo Build & SIM Environment"
HELP_DESCRIPTION="Toplevel targets for building and simulating PULPissimo. Please check the make files in the subdirectories for additional targets.."
include $(PULPISSIMO_ROOT)/utils/help.mk
.DEFAULT_GOAL := help
