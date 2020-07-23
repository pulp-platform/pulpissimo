
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

# generic clean and build targets for the platform
.PHONY: clean
## Remove the RTL model files
clean:
	rm -rf $(VSIM_PATH)
	cd sim && $(MAKE) clean

## Build the RTL model for vsim
build:
	cd sim && $(MAKE) lib build opt
	cp -r rtl/tb/* $(VSIM_PATH)

## Build the RTL model for xsim
build-incisive:
	cd sim && $(MAKE) -f Makefile.incisive build-sc
	$(warning There is currently no SDK support for this simulator. You need to manually run your programs)

# sdk specific targets
install: $(INSTALL_HEADERS)

vopt:
	export VOPT_FLOW=1 && cd $(VSIM_PATH) && vsim -64 -c -do "source tcl_files/config/vsim.tcl; quit"

## Import the latest bootcode. This should not be called by the user.
import_bootcode:
	cd sim/boot && objcopy --srec-len 1 --output-target=srec ${PULP_SDK_HOME}/install/bin/boot-pulpissimo boot-pulpissimo.s19
	cd sim/boot && s19toboot.py boot-pulpissimo.s19 pulpissimo

# # JENKIN CI
# # continuous integration on jenkins
# all: checkout build install vopt sdk

# sdk:
# 	if [ ! -e pulp-builder ]; then \
# 	  git clone --recurse https://github.com/pulp-platform/pulp-builder.git; \
# 	fi; \
# 	cd pulp-builder; \
# 	git checkout 83953d5ca4c545f4186bf3683d509566c3067012; \
# 	git checkout --recurse-submodules; \
# 	. configs/pulpissimo.sh; \
# 	. configs/rtl.sh; \
# 	./scripts/clean; \
# 	./scripts/update-runtime; \
# 	./scripts/build-runtime; \
# 	./scripts/update-runner; \
# 	./scripts/build-runner;

# test-checkout:
# 	./update-tests

# test:
# 	cd pulp-builder; \
# 	. sdk-setup.sh; \
# 	. configs/pulpissimo.sh; \
# 	. configs/rtl.sh; \
# 	cd ..; \
# 	cd tests && plptest --threads 16 --stdout

check-env-art:
ifndef PULP_ARTIFACTORY_USER
	$(error PULP_ARTIFACTORY_USER is undefined.\
	You need to set this environment variable to username:password \
	to be able access the artifactory server to download the sdk)
endif

## Download the latest supported pulp sdk release
sdk-pulp: check-env-art sdk-gitlab

## Download pulp tests for local machine. Same as test-checkout
get-tests: test-checkout

## fetch sdk for local machine
get-sdk: sdk-gitlab

# GITLAB CI
# continuous integration on gitlab
sdk-gitlab: pkg/sdk/2019.11.03
pkg/sdk/2019.11.03:
	sdk-releases/get-sdk-2019.11.03-CentOS_7.py

# simplified runtime for PULP that doesn't need the sdk
pulp-runtime:
	git clone https://github.com/pulp-platform/pulp-runtime.git -b v0.0.3

.PHONY: test-checkout
## Download pulp test for local machine. You need ssh access to the gitlab server.
test-checkout:
	./update-tests

# the gitlab runner needs a special configuration to be able to access the
# dependent git repositories
.PHONY: test-checkout-gitlab
test-checkout-gitlab:
	./update-tests-gitlab

# test with sdk release
.PHONY: test-gitlab
## Run tests on gitlab using the latest supported sdk release
test-gitlab: tests
	cd tests && plptest --threads 16 --stdout

.PHONY: test-sequential-bare
## Run only sequential_bare tests
test-sequential-bare:
	cd tests/sequential_bare_tests && plptest --threads 32 --stdout

.PHONY: test-parallel-bare
## Run only parallel_bare tests
test-parallel-bare:
	cd tests/parallel_bare_tests && plptest --threads 32 --stdout

.PHONY: test-pulp
## Run only pulp_tests tests
test-pulp:
	cd tests/pulp_tests && plptest --threads 32 --stdout

.PHONY: test-ml
## Run only ml_tests tests
test-ml:
	cd tests/ml_tests && plptest --threads 32 --stdout

.PHONY: test-riscv
## Run only riscv_tests tests
test-riscv:
	cd tests/riscv_tests && plptest --threads 32 --stdout

.PHONY: test-rt
## Run only rt_tests tests
test-rt:
	cd tests/rt-tests && plptest --threads 32 --stdout

.PHONY: test-runtime-gitlab
## Run simplified runtime tests on gitlab using the latest supported sdk release
test-runtime-gitlab: pulp-runtime
	cd tests && ../pulp-runtime/scripts/bwruntests.py --proc-verbose -v \
		--report-junit -t 3600 --yaml \
		-o simplified-runtime.xml runtime-tests.yaml

# test with built sdk
.PHONY: test-gitlab2
test-gitlab2:
	cd pulp-builder; \
	source sdk-setup.sh; \
	source configs/pulpissimo.sh; \
	source configs/rtl.sh; \
	cd ../tests && plptest --threads 16 --stdout

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
