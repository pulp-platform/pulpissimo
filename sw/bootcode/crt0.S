/*
 * Copyright (C) 2015 ETH Zurich, University of Bologna and GreenWaves Technologies
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "config.h"
#include "archi/pulp.h"

.section .text

_start:
/* initialize global pointer */
.option push
.option norelax
1:	auipc gp, %pcrel_hi(__global_pointer$)
	addi  gp, gp, %pcrel_lo(1b)
.option pop

	/* init stack pointer */
	la sp, __stack_top

/* clear the bss segment */
	la t0, __bss_start
        la t1, __bss_end
1:
	sw zero,0(t0)
	addi t0, t0, 4
	bltu t0, t1, 1b

/* TODO: load data from ROM */

/* call main */
	li a0, 0                        /* a0 = argc */
	addi a1, sp, __SIZEOF_POINTER__ /* a1 = argv */
	li a2, 0                        /* a2 = envp = NULL */
	call main
	tail exit


.global change_stack
change_stack:
	mv   sp, a2
	jr   a1


.section .vectors, "ax"
.option norvc;
.org 0x0
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler
	jal x0, default_handler

	/* reset vector */
	.org 0x80
	jal x0, _start

	.org 0x84
loop:
	j loop

default_handler:
	mret

