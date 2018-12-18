
SHELL=bash

PKG_DIR ?= $(PWD)/install

export VSIM_PATH=$(PKG_DIR)
export PULP_PATH=$(PWD)

export MSIM_LIBS_PATH=$(VSIM_PATH)/modelsim_libs

export IPS_PATH=$(PULP_PATH)/fe/ips
export RTL_PATH=$(PULP_PATH)/fe/rtl
export TB_PATH=$(PULP_PATH)/rtl/tb

define declareInstallFile

$(VSIM_PATH)/$(1): sim/$(1)
	install -v -D sim/$(1) $$@

INSTALL_HEADERS += $(VSIM_PATH)/$(1)

endef

INSTALL_FILES += tcl_files/config/vsim_ips.tcl
INSTALL_FILES += modelsim.ini
INSTALL_FILES += $(shell cd sim && find boot -type f)
INSTALL_FILES += $(shell cd sim && find tcl_files -type f)
INSTALL_FILES += $(shell cd sim && find waves -type f)

$(foreach file, $(INSTALL_FILES), $(eval $(call declareInstallFile,$(file))))

BRANCH ?= master

checkout:
	git submodule update --init
	./update-ips

clean:
	rm -rf $(VSIM_PATH)
	cd sim && make clean

build:
	cd sim && make lib build opt
	cp -r rtl/tb/* $(VSIM_PATH)

install: $(INSTALL_HEADERS)

vopt:
	export VOPT_FLOW=1 && cd $(VSIM_PATH) && vsim -64 -c -do "source tcl_files/config/vsim.tcl; quit"

import_bootcode:
	cd sim/boot && objcopy --srec-len 1 --output-target=srec ${PULP_SDK_HOME}/install/bin/boot-pulpissimo boot-pulpissimo.s19
	cd sim/boot && s19toboot.py boot-pulpissimo.s19 pulpissimo


sdk:
	if [ ! -e pulp-sdk ]; then \
	  git clone https://github.com/pulp-platform/pulp-sdk.git; \
	fi; \
	cd pulp-sdk; \
	git checkout 52093849703efffc8c62ef740045a0295b5f779f; \
	. configs/pulpissimo.sh; \
	. configs/platform-rtl.sh; \
	make distclean; \
	make deps; \
	make MODULES="--g runtime --m sdk_install" all env;


all: checkout build install vopt sdk

test-checkout:
	cd pulp-sdk; \
	source init.sh; \
	source sourceme.sh; \
	plpbuild --p tests checkout

test:        
	source pulp-sdk/sourceme.sh && cd pulp-sdk && source init.sh && \
          plpbuild --p tests test --threads 16 --stdout
