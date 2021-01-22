# Copyright 2020 ETH Zurich
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
# SPDX-License-Identifier: Apache-2.0
# Author: Robert Balas (balasr@iis.ee.ethz.ch)

CC      = riscv32-unknown-elf-gcc
OBJCOPY = objcopy

CFLAGS   = -Os -g -fno-jump-tables -march=rv32imc -UARCHI_CORE_HAS_PULPV2 -DRV_ISA_RV32
CPPFLAGS = -I$(CURDIR)/include
ASFLAGS  = $(CFLAGS) -DLANGUAGE_ASSEMBLY
LDFLAGS  = -Tlink.ld -nostdlib


BOOTCODE = boot_code

all: $(BOOTCODE) boot.rtl boot.gvsoc

$(BOOTCODE): boot_code.o crt0.o

# Makefile implicit rules used
# %.o: %.c
# COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
# OUTPUT_OPTION = -o $@
# $(COMPILE.c) $(OUTPUT_OPTION) $<

# %.o: %.S
# COMPILE.S = $(CC) $(ASFLAGS) $(CPPFLAGS) $(TARGET_MACH) -c
# $(COMPILE.S) -o $@ $<

# %: %.o
# LINK.o = $(CC) $(LDFLAGS) $(TARGET_ARCH)
# $(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@

boot.gvsoc: rom.bin

# gvsoc bootrom
rom.bin: $(BOOTCODE)
	./stim_utils.py  \
		--binary=$(BOOTCODE) \
		--stim-bin=rom.bin \
		--area=0x1a000000:0x01000000

# The rtl bootrom is just a verilog dump of the elf file
boot.rtl: boot_code.cde

boot_code.cde: $(BOOTCODE)
	$(OBJCOPY) --srec-len 1 --output-target=srec $(BOOTCODE) $(BOOTCODE).s19
	./s19toboot.py $(BOOTCODE).s19 boot_code.cde pulpissimo

.PHONY: clean
clean:
	$(RM) $(BOOTCODE) $(BOOTCODE).o crt0.o \
		boot_code.cde boot_code.sv \
		boot_code.s19 rom.bin
