/*
 * Copyright (C) 2022 ETH Zurich and University of Bologna
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

#ifndef _ARCHI_RISCV_PRIV_1_12_H
#define _ARCHI_RISCV_PRIV_1_12_H

#define CSR_FFLAGS 0x001 /* URW fflags Floating-Point Accrued Exceptions. */
#define CSR_FRM 0x002 /* URW frm Floating-Point Dynamic Rounding Mode. */
#define CSR_FCSR 0x003 /* URW fcsr Floating-Point Control and Status Register (frm + fflags). */

#define CSR_CYCLE 0xC00 /* URO cycle Cycle counter for RDCYCLE instruction. */
#define CSR_TIME 0xC01 /* URO time Timer for RDTIME instruction. */
#define CSR_INSTRET 0xC02 /* URO instret Instructions-retired counter for RDINSTRET instruction. */
#define CSR_HPMCOUNTER(id) (0xC00 + id) /* URO hpmcounter Performance-monitoring counter. */

#define CSR_CYCLEH 0xC80 /* URO cycleh Upper 32 bits of cycle, RV32 only. */
#define CSR_TIMEH 0xC81 /* URO timeh Upper 32 bits of time, RV32 only. */
#define CSR_INSTRETH 0xC82 /* URO instreth Upper 32 bits of instret, RV32 only. */
#define CSR_HPMCOUNTERH(id) (0xC80 + id) /* URO hpmcounterh Upper 32 bits of hpmcounter, RV32 only. */

#define CSR_SSTATUS 0x100 /* SRW sstatus Supervisor status register. */
#define CSR_SIE 0x104 /* SRW sie Supervisor interrupt-enable register. */
#define CSR_STVEC 0x105 /* SRW stvec Supervisor trap handler base address. */
#define CSR_SCOUNTEREN 0x106 /* SRW scounteren Supervisor counter enable. */

#define CSR_SENVCFG 0x10A /* SRW senvcfg Supervisor environment configuration register. */

#define CSR_SSCRATCH 0x140 /* SRW sscratch Scratch register for supervisor trap handlers. */
#define CSR_SEPC 0x141 /* SRW sepc Supervisor exception program counter. */
#define CSR_SCAUSE 0x142 /* SRW scause Supervisor trap cause. */
#define CSR_STVAL 0x143 /* SRW stval Supervisor bad address or instruction. */
#define CSR_SIP 0x144 /* SRW sip Supervisor interrupt pending. */

#define CSR_SATP 0x180 /* SRW satp Supervisor address translation and protection. */

#define CSR_SCONTEXT 0x5A8 /* SRW scontext Supervisor-mode context register. */

#define CSR_HSTATUS 0x600 /* HRW hstatus Hypervisor status register. */
#define CSR_HEDELEG 0x602 /* HRW hedeleg Hypervisor exception delegation register. */
#define CSR_HIDELEG 0x603 /* HRW hideleg Hypervisor interrupt delegation register. */
#define CSR_HIE 0x604 /* HRW hie Hypervisor interrupt-enable register. */
#define CSR_HCOUNTEREN 0x606 /* HRW hcounteren Hypervisor counter enable. */
#define CSR_HGEIE 0x607 /* HRW hgeie Hypervisor guest external interrupt-enable register. */

#define CSR_HTVAL 0x643 /* HRW htval Hypervisor bad guest physical address. */
#define CSR_HIP 0x644 /* HRW hip Hypervisor interrupt pending. */
#define CSR_HVIP 0x645 /* HRW hvip Hypervisor virtual interrupt pending. */
#define CSR_HTINST 0x64A /* HRW htinst Hypervisor trap instruction (transformed). */
#define CSR_HGEIP 0xE12 /* HRO hgeip Hypervisor guest external interrupt pending. */

#define CSR_HENVCFG 0x60A /* HRW henvcfg Hypervisor environment configuration register. */
#define CSR_HENVCFGH 0x61A /* HRW henvcfgh Additional hypervisor env. conf. register, RV32 only. */

#define CSR_HGATP 0x680 /* HRW hgatp Hypervisor guest address translation and protection. */

#define CSR_HCONTEXT 0x6A8 /* HRW hcontext Hypervisor-mode context register. */

#define CSR_HTIMEDELTA 0x605 /* HRW htimedelta Delta for VS/VU-mode timer. */
#define CSR_HTIMEDELTAH 0x615 /* HRW htimedeltah Upper 32 bits of htimedelta, HSXLEN=32 only. */

#define CSR_VSSTATUS 0x200 /* HRW vsstatus Virtual supervisor status register. */
#define CSR_VSIE 0x204 /* HRW vsie Virtual supervisor interrupt-enable register. */
#define CSR_VSTVEC 0x205 /* HRW vstvec Virtual supervisor trap handler base address. */
#define CSR_VSSCRATCH 0x240 /* HRW vsscratch Virtual supervisor scratch register. */
#define CSR_VSEPC 0x241 /* HRW vsepc Virtual supervisor exception program counter. */
#define CSR_VSCAUSE 0x242 /* HRW vscause Virtual supervisor trap cause. */
#define CSR_VSTVAL 0x243 /* HRW vstval Virtual supervisor bad address or instruction. */
#define CSR_VSIP 0x244 /* HRW vsip Virtual supervisor interrupt pending. */
#define CSR_VSATP 0x280 /* HRW vsatp Virtual supervisor address translation and protection. */

#define CSR_MVENDORID 0xF11 /* MRO mvendorid Vendor ID. */
#define CSR_MARCHID 0xF12 /* MRO marchid Architecture ID. */
#define CSR_MIMPID 0xF13 /* MRO mimpid Implementation ID. */
#define CSR_MHARTID 0xF14 /* MRO mhartid Hardware thread ID. */
#define CSR_MCONFIGPTR 0xF15 /* MRO mconfigptr Pointer to configuration data structure. */

#define CSR_MSTATUS 0x300 /* MRW mstatus Machine status register. */
#define CSR_MISA 0x301 /* MRW misa ISA and extensions */
#define CSR_MEDELEG 0x302 /* MRW medeleg Machine exception delegation register. */
#define CSR_MIDELEG 0x303 /* MRW mideleg Machine interrupt delegation register. */
#define CSR_MIE 0x304 /* MRW mie Machine interrupt-enable register. */
#define CSR_MTVEC 0x305 /* MRW mtvec Machine trap-handler base address. */
#define CSR_MCOUNTEREN 0x306 /* MRW mcounteren Machine counter enable. */
#define CSR_MSTATUSH 0x310 /* MRW mstatush Additional machine status register, RV32 only */

#define CSR_MSCRATCH 0x340 /* MRW mscratch Scratch register for machine trap handlers. */
#define CSR_MEPC 0x341 /* MRW mepc Machine exception program counter. */
#define CSR_MCAUSE 0x342 /* MRW mcause Machine trap cause. */
#define CSR_MTVAL 0x343 /* MRW mtval Machine bad address or instruction. */
#define CSR_MIP 0x344 /* MRW mip Machine interrupt pending. */
#define CSR_MTINST 0x34A /* MRW mtinst Machine trap instruction (transformed). */
#define CSR_MTVAL2 0x34B /* MRW mtval2 Machine bad guest physical address. */

#define CSR_MENVCFG 0x30A /* MRW menvcfg Machine environment configuration register. */
#define CSR_MENVCFGH 0x31A /* MRW menvcfgh Additional machine env. conf. register, RV32 only. */
#define CSR_MSECCFG 0x747 /* MRW mseccfg Machine security configuration register. */
#define CSR_MSECCFGH 0x757 /* MRW mseccfgh Additional machine security conf. register, RV32 only. */

#define CSR_PMPCFG(id) (0x3A0+id) /* MRW pmpcfg Physical memory protection configuration. */
#define CSR_PMPADDR(id) (0x3B0+id) /* MRW pmpaddr Physical memory protection address register. */

#define CSR_MCYCLE 0xB00 /* MRW mcycle Machine cycle counter. */
#define CSR_MINSTRET 0xB02 /* MRW minstret Machine instructions-retired counter. */
#define CSR_MHPMCOUNTER(id) (0xB00 + id) /* MRW mhpmcounter Machine performance-monitoring counter. */
#define CSR_MCYCLEH 0xB80 /* MRW mcycleh Upper 32 bits of mcycle, RV32 only. */
#define CSR_MINSTRETH 0xB82 /* MRW minstreth Upper 32 bits of minstret, RV32 only. */
#define CSR_MHPMCOUNTERH(id) (0xB80 + id) /* MRW mhpmcounterh Upper 32 bits of mhpmcounter3, RV32 only. */

#define CSR_MCOUNTINHIBIT 0x320 /* MRW mcountinhibit Machine counter-inhibit register. */
#define CSR_MHPMEVENT(id) (0x320 + id) /* MRW mhpmevent Machine performance-monitoring event selector. */

#define CSR_TSELECT 0x7A0 /* MRW tselect Debug/Trace trigger register select. */
#define CSR_TDATA1 0x7A1 /* MRW tdata1 First Debug/Trace trigger data register. */
#define CSR_TDATA2 0x7A2 /* MRW tdata2 Second Debug/Trace trigger data register. */
#define CSR_TDATA3 0x7A3 /* MRW tdata3 Third Debug/Trace trigger data register. */
#define CSR_MCONTEXT 0x7A8 /* MRW mcontext Machine-mode context register. */

#define CSR_DCSR 0x7B0 /* DRW dcsr Debug control and status register. */
#define CSR_DPC 0x7B1 /* DRW dpc Debug PC. */
#define CSR_DSCRATCH0 0x7B2 /* DRW dscratch0 Debug scratch register 0. */
#define CSR_DSCRATCH1 0x7B3 /* DRW dscratch1 Debug scratch register 1. */

#endif
