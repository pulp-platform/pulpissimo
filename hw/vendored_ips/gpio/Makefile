.DEFAULT_GOAL := help

VENVDIR?=$(WORKDIR)/.venv
REQUIREMENTS_TXT?=$(wildcard requirements.txt)
include Makefile.venv

GPIOS ?= 32

## Regenerate the register file and HAL C-header for a different GPIO count. Usage: make reconfigure GPIOS=128
reconfigure: | venv
	@echo Reconfiguring IP to use $(GPIOS) gpios...
	@sed -i -r 's/default: "[0-9]+"/default: "${GPIOS}"/g' gpio_regs.hjson
ifeq ($(shell expr $(GPIOS) \<= 16), 1)
	@sed -i -r 's|(//)?`define ENABLE_LESS_THAN_16_GPIOS_REG_PKG_WORKAROUND|`define ENABLE_LESS_THAN_16_GPIOS_REG_PKG_WORKAROUND|g' test/tb_gpio.sv
else
	@sed -i -r 's|(//)?`define ENABLE_LESS_THAN_16_GPIOS_REG_PKG_WORKAROUND|//`define ENABLE_LESS_THAN_16_GPIOS_REG_PKG_WORKAROUND|g' test/tb_gpio.sv
endif
ifeq ($(shell expr $(GPIOS) \<= 32), 1)
	@sed -i -r 's|(//)?`define ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND|`define ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND|g' test/tb_gpio.sv
else
	@sed -i -r 's|(//)?`define ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND|//`define ENABLE_LESS_THAN_32_GPIOS_REG_PKG_WORKAROUND|g' test/tb_gpio.sv
endif
	$(VENV)/python util/reggen/regtool.py gpio_regs.hjson -r -t src -p GPIOCount=${GPIOS}
	$(VENV)/python util/reggen/regtool.py gpio_regs.hjson --cdefines -o hal/gpio_hal.h -p GPIOCount=${GPIOS};
	@echo "Done"

.PHONY: help
help: Makefile
	@printf "GPIO Reconfiguration\n"
	@printf "Use this Makefile to regenerate the register file and HAL C-header for a different number GPIOs than the default one.\n\n"
	@printf "Usage: \n"
	@printf "make reconfigure GPIOS=<desired nr of gpios>\n\n"
