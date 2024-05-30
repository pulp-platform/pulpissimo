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

# This utility makefile sets up a virtual environment in a newly create .venv
# subdirectory of this folder and install various commonly used python tools
# within it.

ifndef utils_mk
utils_mk=1

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))
export PULPISSIMO_UTILS=$(mkfile_dir)/bin

VENVDIR?=$(mkfile_path)/.venv
REQUIREMENTS_TXT?=$(wildcard requirements.txt)
include $(mkfile_dir)/venv.mk

$(PULPISSIMO_UTILS)/padrick:
ifeq (,$(widlcard bin/padrick))
	mkdir -p $(PULPISSIMO_UTILS)
	cd $(PULPISSIMO_UTILS) && curl https://api.github.com/repos/pulp-platform/padrick/releases/tags/v0.3.6 \
    | grep "browser_download_url.*Padrick-x86_64.AppImage" \
    | cut -d : -f 2,3 \
    | tr -d \" \
    | wget -qi -
	mv $(PULPISSIMO_UTILS)/Padrick-x86_64.AppImage $(PULPISSIMO_UTILS)/padrick
	chmod a+x $(PULPISSIMO_UTILS)/padrick
endif

$(PULPISSIMO_UTILS)/bender:
ifeq (,$(wildcard bin/bender))
	mkdir -p $(PULPISSIMO_UTILS)
	cd $(PULPISSIMO_UTILS) && curl --proto '=https' --tlsv1.2 -sSf https://pulp-platform.github.io/bender/init \
		| bash -s -- 0.28.0
	touch $(PULPISSIMO_UTILS)/bender
endif


export PULPISSIMO_UTILS=$(mkfile_dir)/bin
endif
