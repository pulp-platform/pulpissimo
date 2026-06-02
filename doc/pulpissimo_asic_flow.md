---
title: "PULPissimo SoC — ASIC Implementation & Verification Reference"
subtitle: "From RTL to Tapeout: A Block-by-Block Guide"
author: "thulasiram01@semix-iitb.com"
date: "2026-06-01"
version: "0.1 (draft)"
toc: true
toc-depth: 3
numbersections: true
geometry: margin=2.5cm
fontsize: 11pt
colorlinks: true
linkcolor: blue
---

---

> **How to export this document to PDF:**
> ```bash
> pandoc doc/pulpissimo_asic_flow.md \
>   -o doc/pulpissimo_asic_flow.pdf \
>   --pdf-engine=xelatex \
>   --toc --number-sections \
>   -V geometry:margin=2.5cm
> ```
> **How to export to Word:**
> ```bash
> pandoc doc/pulpissimo_asic_flow.md -o doc/pulpissimo_asic_flow.docx
> ```

---

# Introduction

This document is a living reference for the full ASIC implementation flow of the
**PULPissimo** SoC, a single-core RISC-V microcontroller SoC developed by ETH Zurich
and the University of Bologna. It covers the design hierarchy, block-by-block
deep-dives, the complete verification strategy, and the synthesis flow using
Cadence Genus.

The document is structured to mirror the actual implementation order. Each section
builds on the previous one and contains:

- Architecture explanation
- RTL structure (referencing actual files in this repo)
- ASIC-specific strategy
- Step-by-step tool commands
- Pass/fail criteria

**Repository:** `thulasiramvarma/pulpissimo`
**Top-level RTL:** `hw/pulpissimo.sv`
**Dependency manager:** Bender (`Bender.yml`, `Bender.lock`)

---

# SoC Hierarchy Overview

## Top-Level Structure

```
pulpissimo.sv  (ASIC top-level)
│
├── i_clock_gen          hw/clock_gen_generic.sv   ← REPLACE with foundry PLL
├── i_rstgen_soc_clk     (common_cells::rstgen)    ← reset synchronizers x3
├── i_rstgen_per_clk
├── i_rstgen_slow_clk
├── i_apb_demux          ← APB config bus demux
├── i_demux              ← bus demux
├── i_err_slv            ← error slave (unmapped addresses)
├── i_padframe           hw/padframe/              ← REPLACE with foundry IO
│   └── padframe_adapter.sv
└── i_soc_domain         hw/soc_domain.sv
    └── i_pulp_soc       (external: pulp_soc v5.0.1)
```

## Level Summary Table

| Level | Module | File | Notes |
|---|---|---|---|
| L0 | `pulpissimo` | `hw/pulpissimo.sv` | ASIC top |
| L1 | `soc_domain` | `hw/soc_domain.sv` | PULPissimo wrapper for pulp_soc |
| L1 | padframe | `hw/padframe/` | Padrick-generated, replace for ASIC |
| L1 | `clock_gen_generic` | `hw/clock_gen_generic.sv` | Replace with foundry PLL |
| L2 | `pulp_soc` | external (Bender dep) | Core logic, memory, uDMA, peripherals |
| L3 | FC subsystem | inside pulp_soc | CV32E40P core + FPU + cache + debug |
| L3 | SoC Interconnect | inside pulp_soc | AXI4 crossbar + APB bridge |
| L3 | L2 Memory | inside pulp_soc | SCM → SRAM macros for ASIC |
| L3 | uDMA subsystem | inside pulp_soc | Autonomous DMA + all peripherals |
| L3 | Peripheral subsystem | inside pulp_soc | APB registers, GPIO, timer |

## Clock Domains

```
pad_ref_clk → i_clock_gen ─┬─► soc_clk  (~200 MHz) → i_rstgen_soc_clk  → FC, AXI, L2
                            ├─► per_clk  (~100 MHz) → i_rstgen_per_clk  → APB, uDMA
                            └─► slow_clk (32.768 kHz)→ i_rstgen_slow_clk→ RTC, always-on

pad_reset_n (async)  → distributed through all rstgen instances
jtag_tck_i  (async)  → TCK domain (JTAG TAP + DTM CDC)
```

## SoC Address Map

| Base Address | Region |
|---|---|
| `0x1A00_0080` | Boot ROM (FC reset vector) |
| `0x1A10_0000` | APB Peripherals (SoC Ctrl, GPIO, uDMA cfg, Timer, EFUSE) |
| `0x1B00_0000` | Debug Unit (RISC-V DM) |
| `0x1C00_0000` | L2 Interleaved RAM (128 KB typical) |
| `0x1C08_0000` | L2 Private Bank (FC-private) |

## ASIC Platform Decisions (set before synthesis)

| Parameter | Value | Effect |
|---|---|---|
| `CORE_TYPE` | `0` | CV32E40P with XPULP |
| `USE_XPULP` | `1` | PULP custom ISA (hwloops, SIMD, post-incr ld/st) |
| `USE_FPU` | `1` | Instantiate fpnew FPU |
| `USE_ZFINX` | `1` | FPU shares integer regfile (saves ~5K gates) |
| `USE_HWPE` | `0` | No hardware processing engine |
| `SIM_STDOUT` | **`0`** | **MUST be 0 for ASIC — removes sim-only UART** |

---

# L3 Block: FC Subsystem (Fabric Controller)

## What is the FC?

The Fabric Controller (FC) is the **single RISC-V core** that boots and
orchestrates the entire PULPissimo SoC. With `CORE_TYPE=0` and `USE_XPULP=1`,
it is the **CV32E40P** (formerly RI5CY): a 4-stage in-order 32-bit RISC-V core
with optional FPU and PULP-specific hardware extensions.

## FC Subsystem Hierarchy

```
fc_subsystem  (inside pulp_soc)
│
├── cv32e40p_core ─────────────────────── RV32IMFC + XPULP
│   ├── cv32e40p_if_stage               IF: Instruction Fetch
│   │   ├── prefetch_buffer             FIFO prefetcher
│   │   ├── aligner                     16/32-bit instruction alignment
│   │   └── compressed_decoder          RVC 16→32-bit expansion
│   ├── cv32e40p_id_stage               ID: Decode + Register Read
│   │   ├── cv32e40p_decoder            RISC-V + XPULP instruction decoder
│   │   ├── cv32e40p_controller         Pipeline FSM, hazard detect, IRQ
│   │   ├── cv32e40p_register_file      Integer RF (32×32-bit)
│   │   ├── cv32e40p_int_controller     IRQ priority and masking
│   │   └── hwloop_regs                 XPULP: 2 nested hardware loops
│   ├── cv32e40p_ex_stage               EX: Execute
│   │   ├── cv32e40p_alu                ALU + iterative divider
│   │   ├── cv32e40p_mult               1-cycle 32×32 multiplier
│   │   ├── cv32e40p_apu_disp           APU dispatcher → FPU
│   │   └── XPULP units                DSP MAC, SIMD, bit manip
│   ├── cv32e40p_load_store_unit        MEM: Load/Store (OBI master)
│   └── cv32e40p_cs_registers           WB: CSRs + Performance Counters
│
├── fc_icache ─────────────────────────── Private I-Cache
│   ├── Tag RAM    (SCM → SRAM macro for ASIC)
│   └── Data RAM   (SCM → SRAM macro for ASIC)
│
├── fpnew_top (FPU) ───────────────────── IEEE-754 (USE_FPU=1)
│   ├── ADDMUL block   FADD, FMUL, FMADD
│   ├── DIVSQRT block  Iterative div/sqrt (fpu_div_sqrt_mvp)
│   ├── NONCOMP block  FMIN/FMAX, FSGNJ, FCMP, FCLASS
│   ├── CONV block     INT↔FP, FP↔FP conversions
│   └── fpnew_rounding IEEE-754 rounding modes
│
├── apb_interrupt_cntrl ───────────────── External IRQ routing to core
├── event_unit ────────────────────────── PULP event/wakeup unit
└── debug_unit (RISC-V DM) ────────────── JTAG debug
    ├── dm_top            RISC-V debug module
    ├── dmi_jtag          CDC: TCK ↔ soc_clk
    └── adv_dbg_if        Legacy PULP JTAG TAP
        └── jtag_pulp     JTAG TAP controller (TCK domain)
```

## CV32E40P Pipeline

```
        ┌────────┐   ┌────────┐   ┌────────┐   ┌────────┐
   PC ──►  IF    ├──►  ID    ├──►  EX    ├──►  WB    ──► Regfile
        │ fetch  │   │decode │   │ ALU/  │   │commit │
        │+prefetch│  │RF read│   │ MULT/ │   │       │
        └────┬───┘   └───────┘   │  LSU  │   └───────┘
             │                   └───┬───┘
             ▼                       ▼
        fc_icache               Data OBI → AXI → L2
             ↓
        AXI → L2
```

**IPC targets:** ~1.0 integer, ~0.7 FP, ~1.5 with XPULP DSP loops

## Bus Interfaces From FC

```
FC OBI Instruction port  ──► fc_icache ──► AXI master ──► SoC interconnect
FC OBI Data port         ────────────────► AXI master ──► SoC interconnect
APU (FPU) interface      ──► fpnew (same clock domain)
IRQ vector (32 lines)    ◄── event_unit + apb_interrupt_cntrl
Debug request            ◄── debug_unit (DM)
```

## Boot Sequence

```
1. pad_reset_n deasserted
2. soc_clk synchronized through rstgen
3. FC fetches from 0x1A00_0080 → Boot ROM
4. Boot ROM reads bootsel_i[1:0]:
     00 → JTAG boot (wait for debugger)
     01 → SPI flash boot via QSPIM0 → L2
     10 → HyperFlash boot
     11 → Preloaded L2 (debug mode)
5. Boot code copies application ELF to L2 0x1C00_0000
6. Jumps to L2 entry point → application runs
```

## FC ASIC Constraints (SDC)

```tcl
# Primary FC clock
create_clock -name soc_clk -period 5.0 [get_ports soc_clk_i]   ;# 200 MHz
set_clock_uncertainty -setup 0.15 [get_clocks soc_clk]
set_clock_uncertainty -hold  0.05 [get_clocks soc_clk]

# JTAG clock (async to all other clocks)
create_clock -name tck -period 100.0 [get_ports jtag_tck_i]
set_clock_groups -asynchronous -group {soc_clk per_clk slow_clk} -group {tck}

# FPU FMADD multicycle (deep path through fpnew)
set_multicycle_path 2 -setup -through [get_pins -hier -filter "name=~*fma_op*"]
set_multicycle_path 1 -hold  -through [get_pins -hier -filter "name=~*fma_op*"]

# Iterative divider
set_multicycle_path 4 -setup -through [get_pins -hier -filter "name=~*div*"]
set_multicycle_path 3 -hold  -through [get_pins -hier -filter "name=~*div*"]

# Static cluster ports (tied to '0)
set_false_path -from [get_ports async_data_*]
set_false_path -from [get_ports async_cluster_*]

# Async resets
set_false_path -from [get_ports pad_reset_n]
set_false_path -from [get_ports jtag_trst_ni]
```

---

# Verification Checklist — FC Subsystem

The following 9 checks must all pass before the FC RTL is frozen for tapeout.
They are ordered so that earlier checks catch issues cheaply before investing
in expensive downstream steps.

```
CHECK 1: RTL Lint          ← Static code analysis (no tool run needed)
CHECK 2: RTL Functional    ← Simulate real programs on the RTL
CHECK 3: RISC-V Compliance ← Official RISC-V architecture test suite
CHECK 4: FPU IEEE-754      ← Floating-point math correctness vs Berkeley TestFloat
CHECK 5: JTAG Debug        ← Halt/resume/step/memory access via OpenOCD
CHECK 6: CDC Analysis      ← Clock crossing safety (no metastability risk)
CHECK 7: Gate-Level Sim    ← Same tests on synthesized netlist
CHECK 8: Power Analysis    ← Dynamic/leakage power within budget
CHECK 9: Synthesis (Genus) ← RTL → gate-level netlist, timing closed
```

---

## CHECK 1 — RTL Lint (SpyGlass)

### What and Why

Lint is **static analysis of RTL code without simulation**. It catches coding
errors before simulation or synthesis: undriven signals, width mismatches,
inferred latches, reset-less flip-flops, combinational loops.

Fix lint before running simulation — otherwise you debug symptoms instead of causes.

### Tool: Siemens SpyGlass

Setup: `target/lint/spyglass/Makefile`

### Steps

**1.1 — Check prerequisites**
```bash
spyglass-2022.06 sg_shell -help
./utils/bender --version
```

**1.2 — Checkout all dependencies**
```bash
cd /home/user/pulpissimo
make checkout
```

**1.3 — Run lint**
```bash
make lint_rtl
# Internally: bender script -t synthesis verilator → sources.f
# Then:        sg_shell -tcl target/lint/spyglass/run_lint_rtl_handoff.tcl
```

**1.4 — Read report**
```bash
cat build/spyglass/reports/moresimple.rpt
# GUI:
make show_results
```

**1.5 — Triage**

| Severity | Action |
|---|---|
| `error` | Must fix — will cause synthesis or functional failure |
| `warning` | Review individually — many are waivable |
| `info` | Skip |

**1.6 — Waiver file for known-clean patterns**
```tcl
# build/spyglass/waivers.awl
waive -rule {W287b} -comment "Async reset in rstgen is intentional"
waive -rule {W240}  -comment "Cluster ports tied to 0 in PULPissimo"
```

### Pass Criteria

- Zero `error`-level violations
- All `warning`-level violations reviewed and either fixed or waived with justification

---

## CHECK 2 — RTL Functional Simulation (QuestaSim)

### What and Why

Compile the RTL and run **real programs** on the simulated hardware.
The testbench models the chip environment: clocks, reset, JTAG, UART capture.
This is the primary functional check — verifying that cv32e40p + L2 + uDMA
work correctly together.

### Testbench Architecture

```
target/sim/tb/tb_pulp.sv        ← full testbench (preferred)
target/sim/tb/tb_pulp_simple.sv ← minimal template

tb_pulp.sv
├── DUT: pulpissimo
├── tb_clk_gen.sv   ← reference clock stimulus
├── SimJTAG.sv      ← JTAG VPI bridge (OpenOCD ↔ simulation)
├── SimDTM.sv       ← direct test mode (fast preload, not physical)
├── UART monitor    ← captures SoC stdout
└── Memory preloader← loads ELF/SREC into L2 (fastboot mode)
```

**Boot modes:**

| Mode | Mechanism | Use case |
|---|---|---|
| `fastboot` | TB writes directly into L2 via hierarchy path | Fast iteration — NOT physically realizable |
| `jtag_legacy` | PULP JTAG TAP preloads via adv_dbg_if | Tests actual legacy JTAG path |
| `jtag_openocd` | RISC-V DM via OpenOCD + SimJTAG VPI | Tests RISC-V standard debug path |

### Steps

**2.1 — Build simulation model**
```bash
make build
# Runs: bender script vsim -t rtl -t test -t rtl_sim → compile.tcl
# Then: vsim → compiles all SV → vopt tb_pulp → optimized simulation binary
```

**2.2 — Compile a test program**
```bash
# Install RISC-V cross-compiler (CV32E40P + XPULP)
# Source: https://github.com/pulp-platform/pulp-riscv-gnu-toolchain
riscv32-unknown-elf-gcc --version   # verify

# Compile hello world
riscv32-unknown-elf-gcc \
  -march=rv32imcxpulpv3 -mabi=ilp32 -O2 \
  -T link.ld \
  -o test_hello.elf test_hello.c
```

**2.3 — Run simulation**
```bash
# Fast mode
make run_sim EXECUTABLE_PATH=$(pwd)/test_hello.elf BOOTMODE=fastboot

# With waveforms
make run_sim EXECUTABLE_PATH=$(pwd)/test_hello.elf BOOTMODE=fastboot gui=1
```

**2.4 — Test categories**

| Category | What to run |
|---|---|
| Basic execution | Hello world, return value check |
| Memory | Load/store byte/halfword/word, unaligned access |
| Interrupts | Timer IRQ fires → ISR runs → returns |
| XPULP extensions | hwloop, SIMD (pv.add.h), post-increment loads |
| FPU | float add/mul/div/sqrt, int↔float conversions |

**2.5 — Key waveform signals**
```
# Core PC tracking
tb_pulp.dut.i_soc_domain.i_pulp_soc.i_fc_subsystem.i_cv32e40p_core.if_stage.pc_if_o

# OBI instruction bus
tb_pulp.dut.i_soc_domain.i_pulp_soc.i_fc_subsystem.instr_req_o
tb_pulp.dut.i_soc_domain.i_pulp_soc.i_fc_subsystem.instr_gnt_i
```

### Pass Criteria

All test programs return exit code 0. No simulation timeouts or assertion failures.

---

## CHECK 3 — RISC-V Architecture Compliance (riscv-arch-test + OpenOCD)

### What and Why

The official RISC-V compliance test suite verifies **every instruction**
against the architecture spec — including all edge cases (division by zero,
overflow, NaN handling, CSR read-modify-write). Passing simulation does not
guarantee compliance; the compliance suite exercises corners that typical
programs never hit.

### Steps

**3.1 — Get the test suite**
```bash
git clone https://github.com/riscv-non-isa/riscv-arch-test.git
cd riscv-arch-test && pip3 install -r requirements.txt
```

**3.2 — Build compliance ELFs for PULPissimo**
```bash
# Create linker script for PULPissimo memory map
mkdir -p riscv-arch-test/riscv-target/pulpissimo
# L2 starts at 0x1C000000

make XLEN=32 RISCV_TARGET=pulpissimo RISCV_DEVICE=rv32i compile
```

**3.3 — Start simulation in JTAG mode**
```bash
make run_sim BOOTMODE=jtag_openocd EXECUTABLE_PATH=./compliance.elf &
```

**3.4 — Run OpenOCD compliance test**
```bash
export JTAG_VPI_PORT=5000
openocd -f target/sim/tb/openocd_configs/pulpissimo_compliance_test.cfg
# Config already in repo — runs: riscv test_compliance
```

**3.5 — Test groups**

| Test group | ISA feature | CV32E40P block |
|---|---|---|
| `rv32i` | All base integer instructions | Decoder + ALU |
| `rv32im` | Multiply/divide (incl. div-by-zero) | cv32e40p_mult + alu_div |
| `rv32ic` | Compressed instructions | compressed_decoder |
| `rv32if` | F extension | fpnew + APU dispatch |
| `rv32Zicsr` | CSR read/write/set/clear | cs_registers |
| `rv32Zifencei` | Instruction fence | I-cache invalidation |

**3.6 — Verify JTAG TAP IDs**

From `hw/includes/pulp_soc_defines.sv`:
```
DMI_JTAG_IDCODE  = 32'h50001db3   ← RISC-V DM TAP
PULP_JTAG_IDCODE = 32'h5fffedb3   ← Legacy PULP TAP
```
These must match what OpenOCD scans. Mismatch → wrong IDCODE in IP parameter.

### Pass Criteria

`riscv.cpu: RISC-V compliance test PASSED` for all test groups.

---

## CHECK 4 — FPU IEEE-754 Compliance (Berkeley TestFloat)

### What and Why

IEEE-754 defines **exact** results for every floating-point operation including
rounding modes, special values (±∞, NaN, ±0), and exception flags.
`fpnew` claims compliance — this check verifies that claim by comparing
outputs against Berkeley SoftFloat (the golden reference).

### Steps

**4.1 — Install TestFloat**
```bash
git clone https://github.com/ucb-bar/berkeley-testfloat-3.git
cd berkeley-testfloat-3/build/Linux-x86_64-GCC
make   # produces: testfloat_gen, testfloat_ver
```

**4.2 — Generate test vectors**
```bash
# 10,000 cases for F32 addition, round-to-nearest-even
./testfloat_gen -rnear_even f32_add > f32_add_rne.tv
# Each line: <op1_hex> <op2_hex> <expected_hex> <exception_flags>
```

**4.3 — Write FPU test program for CV32E40P**
```c
// fpu_test.c — runs on PULPissimo, checks FPU result
#include <stdint.h>
int main() {
    float a = 1.0f, b = 2.0f;
    float result = a + b;           // Executed on CV32E40P FPU
    uint32_t bits;
    __builtin_memcpy(&bits, &result, 4);
    if (bits != 0x40400000U) return 1;   // 3.0f expected
    return 0;
}
```

**4.4 — Operations to test**

| Operation | TestFloat cmd | CV32E40P instruction |
|---|---|---|
| F32 Add | `f32_add` | `fadd.s` |
| F32 Mul | `f32_mul` | `fmul.s` |
| F32 FMA | `f32_mulAdd` | `fmadd.s` |
| F32 Div | `f32_div` | `fdiv.s` |
| F32 Sqrt | `f32_sqrt` | `fsqrt.s` |
| F32→I32 | `f32_to_i32` | `fcvt.w.s` |
| I32→F32 | `i32_to_f32` | `fcvt.s.w` |
| F32 Compare | `f32_lt`, `f32_le` | `flt.s`, `fle.s` |

> **Zfinx note (USE_ZFINX=1):** FP values live in integer registers.
> Compile with `-march=rv32im_zfinx`. `fpnew` results are identical;
> only register mapping changes. Saves ~5K gates vs separate FP regfile.

### Pass Criteria

All vector comparisons match golden reference for all rounding modes
(RNE, RTZ, RDN, RUP, RMM) and all special value cases.

---

## CHECK 5 — JTAG Debug (OpenOCD + GDB)

### What and Why

Before tapeout, prove that the JTAG debug interface works:
halt/resume/single-step/breakpoints/memory read-write. Without this,
a post-silicon bug has no diagnostic window.

### Two JTAG TAPs in PULPissimo

```
TDI → [TAP0: adv_dbg_if (PULP legacy)] → [TAP1: RISC-V DM] → TDO
       IDCODE: 0x5fffedb3                 IDCODE: 0x50001db3
       5-bit IR                           5-bit IR
```

OpenOCD config already in repo:
`target/sim/tb/openocd_configs/pulpissimo_debug.cfg`

### Steps

**5.1 — Start simulation in JTAG mode**
```bash
make run_sim BOOTMODE=jtag_openocd EXECUTABLE_PATH=/dev/null gui=1 &
# TB waits for JTAG connection on port 5000
```

**5.2 — Connect OpenOCD**
```bash
export JTAG_VPI_PORT=5000
openocd -f target/sim/tb/openocd_configs/pulpissimo_debug.cfg
# Expected:
#   JTAG tap: riscv.unknown0 → 0x5fffedb3  ✓
#   JTAG tap: riscv.cpu      → 0x50001db3  ✓
#   hart 0: XLEN=32, misa=0x40101104 (rv32imfc)
```

**5.3 — Connect GDB and verify all debug operations**
```bash
riscv32-unknown-elf-gdb test_hello.elf

(gdb) target remote localhost:3333   # connect to OpenOCD
(gdb) load                           # load ELF via JTAG
(gdb) monitor reset halt             # reset and halt

# Verify 1: PC at boot vector
(gdb) info register pc
# Expected: 0x1A000080

# Verify 2: Single-step
(gdb) stepi
(gdb) stepi

# Verify 3: Breakpoint
(gdb) break main
(gdb) continue
# Expected: Breakpoint 1, main () at test_hello.c:3

# Verify 4: Register read
(gdb) info registers

# Verify 5: Memory write + readback
(gdb) set *(int*)0x1C000100 = 0xDEADBEEF
(gdb) x/1x 0x1C000100
# Expected: 0x1c000100: 0xdeadbeef
```

### Pass Criteria

All 5 GDB operations succeed without error. TAP IDs match `pulp_soc_defines.sv`.

---

## CHECK 6 — CDC Analysis (SpyGlass CDC)

### What and Why

Any signal crossing between two different clock domains without proper
synchronization can cause **metastability** on silicon (flip-flop stuck
between 0 and 1). This looks correct in simulation but causes random failures
on the chip. CDC analysis catches these statically before fabrication.

### Clock Domains

```
┌──────────────┐    CDC     ┌──────────────┐
│  soc_clk     │ ─────────► │  per_clk     │
│  ~200 MHz    │            │  ~100 MHz    │
└──────┬───────┘            └──────────────┘
       │ CDC                        │ CDC
       ▼                            ▼
┌──────────────┐            ┌──────────────┐
│  slow_clk    │            │  TCK domain  │
│  32.768 kHz  │            │  (async)     │
└──────────────┘            └──────────────┘
```

Safe synchronization structures:
- **2-flop synchronizer** — single-bit control signals
- **Gray-code counter** — FIFO pointers across domains
- **Async FIFO** — streaming data (udma_core uses these)
- **Handshake (req/ack)** — multi-bit data (dmi_jtag uses this for TCK↔soc_clk)

### Steps

**6.1 — Generate synthesis filelist**
```bash
./utils/bender script -t synthesis verilator > build/cdc/sources.f
```

**6.2 — Create CDC TCL**
```tcl
# run_cdc.tcl
read_file -type sourcelist sources.f

define_clock -name soc_clk  -period 5000   [find / -port soc_clk_i]
define_clock -name per_clk  -period 10000  [find / -port per_clk_i]
define_clock -name slow_clk -period 30517  [find / -port slow_clk_i]
define_clock -name tck      -period 100000 [find / -port jtag_tck_i]

set_clock_domain_relationship -async {soc_clk} {per_clk} {slow_clk} {tck}
current_methodology cdc_methodology
run_goal cdc
```

**6.3 — Violation triage**

| Rule | Meaning | Action |
|---|---|---|
| `CDC-2` | Single-bit crossing without synchronizer | Must fix |
| `CDC-5` | Multi-bit crossing, coherency risk | Must fix or prove safe |
| `CDC-15` | Synchronizer identified (informational) | OK |
| `CDC-17` | Quasi-static (only changes in reset) | Waive with justification |

**6.4 — Key expected crossings**

```
1. soc_clk ↔ TCK (dmi_jtag): Handshake req/ack — verify 2 sync flops on ack
2. slow_clk → soc_clk (wakeup IRQ): 2-flop synchronizer
3. soc_clk → per_clk (APB bridge): Valid if per_clk is integer divide of soc_clk
```

**6.5 — Example waiver file**
```tcl
# waivers.awl
waive -rule {CDC-2} -port {async_data_*}  -comment "Tied to 0, never toggles"
waive -rule {CDC-2} -inst {*rstgen*}       -comment "Async reset synchronizer by design"
```

### Pass Criteria

Zero unwaived `CDC-2` violations. All `CDC-5` violations either fixed or
documented with proof of safe data coherency (data stable before valid assertion).

---

## CHECK 7 — Gate-Level Simulation (Post-Synthesis)

### What and Why

After synthesis, re-run the same functional tests on the **gate-level netlist**
with real cell delays back-annotated from SDF. This catches:
- Synthesis transformation bugs (logic changed incorrectly)
- X-propagation from uninitialized memory
- SRAM macro wiring errors
- Hold violations causing unexpected behavior

### Steps

**7.1 — Prerequisite: synthesized netlist + SDF**
```
outputs/fc_subsystem_netlist.v   ← from Genus (CHECK 9)
outputs/fc_subsystem.sdf         ← timing annotation
```

**7.2 — Run gate-level simulation in QuestaSim**
```bash
vsim -t ps \
  -sdfmax /tb_pulp/dut/i_soc_domain/i_pulp_soc/i_fc_subsystem=fc_subsystem.sdf \
  tb_pulp
```

**7.3 — Common issues and fixes**

| Symptom | Cause | Fix |
|---|---|---|
| X on data bus after reset | SRAM outputs X until first read | Add SRAM initialization in TB |
| Core hangs after N cycles | X propagation from uninitialized signal | Enable QuestaSim xprop mode, trace X source |
| Wrong result at higher freq | Hold violation in netlist | Verify STA hold at fast corner (FF/1.1V/−40°C) |

**7.4 — Gate-level regression plan**

| Test | What it validates |
|---|---|
| Boot ROM execution: first 100 instructions | PC reaches 0x1A000080, executes without hang |
| L2 write/read | AXI path: FC OBI → AXI bridge → L2 SRAM macro |
| First printf (UART) | FC → AXI → uDMA UART → UART pad model |
| Timer IRQ | per_clk timer → APB IRQ ctrl → FC irq → ISR entry |

### Pass Criteria

All gate-level regression tests produce same result as RTL simulation.
No X-propagation after reset completes.

---

## CHECK 8 — Power Analysis (PrimePower / Voltus)

### What and Why

Power analysis determines:
- **Dynamic power** — switching activity (CV²F)
- **Leakage power** — always-on, dominant at ≤28nm
- **Peak current** — determines power grid sizing in PnR
- **IR drop** — voltage droop must be <5% VDD to avoid timing failures

### Steps

**8.1 — Generate switching activity (VCD)**
```bash
vsim tb_pulp -do "
  vsim -t ps tb_pulp +srec=app.s19;
  vcd file power_activity.vcd;
  vcd add -r /tb_pulp/dut/i_soc_domain/i_pulp_soc/i_fc_subsystem/*;
  run 10us;
  vcd flush; exit
"
```

**8.2 — Convert VCD to SAIF**
```bash
vcd2saif -input power_activity.vcd \
         -output power_activity.saif \
         -scope /tb_pulp/dut/i_soc_domain/i_pulp_soc/i_fc_subsystem
```

**8.3 — Run PrimePower**
```tcl
read_verilog fc_subsystem_netlist.v
current_design fc_subsystem
link_design
read_sdc fc_subsystem.sdc
read_parasitics -format spef fc_subsystem.spef   ;# post-PnR for accuracy
read_saif power_activity.saif \
  -instance_name tb_pulp/dut/i_soc_domain/i_pulp_soc/i_fc_subsystem
update_power
report_power -hierarchy > reports/fc_power.rpt
```

**8.4 — Typical targets (28nm, 200 MHz, 1.0V)**

| Metric | Target | If exceeded |
|---|---|---|
| Total FC power | < 10 mW | Review clock gating |
| Leakage / Total | < 15% | Use high-Vt cells in synthesis |
| FPU power when idle | ≈ 0 | Verify ICG fires during WFI |
| Peak current spike | < 50 mA | Widen power stripes in PnR |
| IR drop | < 50 mV (5% of 1V) | Add power grid stripes |

### Pass Criteria

Total FC power within budget. IR drop < 5% VDD. FPU clock gating verified active
during integer-only workloads.

---

## CHECK 9 — Logic Synthesis (Cadence Genus)

### What and Why

Synthesis converts RTL (SystemVerilog) into a gate-level netlist of real
foundry standard cells. The tool simultaneously maps Boolean logic to cells,
optimizes for timing (meet clock period), minimizes area, and inserts clock gating.
The output netlist is the input to Place-and-Route.

```
   RTL (.sv)              Genus              Gate Netlist (.v)
   ┌──────┐          ┌──────────────┐       ┌──────────┐
   │ cv32 │          │ 1. Read RTL  │       │ AND2_X1  │
   │ e40p │ ──────► │ 2. Elaborate │ ─────►│ DFF_X2   │
   │ fpnew│          │ 3. syn_generic│      │ MUX2_X1  │
   │ ...  │          │ 4. syn_map   │       │ AOI21_X1 │
   └──────┘          │ 5. syn_opt   │       └──────────┘
                     └──────────────┘
                           ↑
                  constraints.sdc + .lib
```

### Synthesis Inputs

| Input | What it is | Source |
|---|---|---|
| RTL filelist | All `.sv`/`.v` in compile order | `bender script -t synthesis` |
| `.lib` (standard cell) | Timing/power/area per cell per corner | Foundry PDK |
| `.lib` (memory macros) | SRAM/ROM timing models | Memory compiler |
| `.sdc` | Clock, IO, false/multicycle path constraints | You write |
| MMMC view | Multi-corner analysis setup | You write |

### Step-by-Step

**9.1 — Generate synthesis filelist**
```bash
./utils/bender script -t synthesis flist > build/synth/sources.f
# Verify: no tb_*, SimDTM.sv, SimJTAG.sv in the list
grep -E "tb_|sim" build/synth/sources.f   # should be empty
```

**9.2 — Directory structure**
```bash
mkdir -p build/synth/{scripts,reports,outputs,logs}
```

**9.3 — `setup.tcl` — Libraries and search paths**
```tcl
# build/synth/scripts/setup.tcl
set FOUNDRY  "/eda/foundry/tsmc28"
set STD_CELL "$FOUNDRY/stdcells/tcbn28hpcplusbwp_120a"
set MEM_LIB  "$FOUNDRY/memories/sram_compiler_output"

set_db init_lib_search_path "$STD_CELL/lib $MEM_LIB/lib"
set_db init_hdl_search_path "/home/user/pulpissimo/hw/includes"

set_db library [list \
  $STD_CELL/lib/tcbn28hpcplusbwp_ss_0p81v_125c.lib \
  $STD_CELL/lib/tcbn28hpcplusbwp_ff_0p99v_m40c.lib \
  $MEM_LIB/lib/sram_2048x32_ss_0p81v_125c.lib      \
  $MEM_LIB/lib/sram_2048x32_ff_0p99v_m40c.lib      \
]

set_db init_lef_library [list \
  $STD_CELL/lef/tcbn28hpcplusbwp_10lm.lef \
  $MEM_LIB/lef/sram_2048x32.lef           \
]

set_db init_cap_table "$FOUNDRY/captable/typical.captbl"
```

**9.4 — `constraints.sdc` — Timing constraints**
```tcl
# build/synth/scripts/constraints.sdc

# Clock definitions
create_clock -name soc_clk  -period 5.0   [get_ports soc_clk_i]
create_clock -name per_clk  -period 10.0  [get_ports per_clk_i]
create_clock -name slow_clk -period 30517 [get_ports slow_clk_i]
create_clock -name jtag_tck -period 100.0 [get_ports jtag_tck_i]

set_clock_uncertainty -setup 0.15 [all_clocks]
set_clock_uncertainty -hold  0.05 [all_clocks]
set_clock_transition  0.1        [all_clocks]

# Async clock groups
set_clock_groups -asynchronous \
  -group {soc_clk} -group {per_clk} -group {slow_clk} -group {jtag_tck}

# IO delays
set_input_delay  -clock soc_clk 1.5 [all_inputs]
set_output_delay -clock soc_clk 1.5 [all_outputs]

# Drive and load
set_driving_cell -lib_cell BUFFD8BWP [all_inputs]
set_load 0.03 [all_outputs]

# False paths (cluster ports, resets, DFT)
set_false_path -from [get_ports async_data_*]
set_false_path -from [get_ports async_cluster_*]
set_false_path -from [get_ports pad_reset_n]
set_false_path -from [get_ports jtag_trst_ni]
set_false_path -from [get_ports dft_test_mode_i]

# Multicycle paths
set_multicycle_path 2 -setup -through [get_pins -hier -filter "name=~*fma_op*"]
set_multicycle_path 1 -hold  -through [get_pins -hier -filter "name=~*fma_op*"]
set_multicycle_path 4 -setup -through [get_pins -hier -filter "name=~*div*"]
set_multicycle_path 3 -hold  -through [get_pins -hier -filter "name=~*div*"]
```

**9.5 — `mmmc.tcl` — Multi-corner analysis**
```tcl
# build/synth/scripts/mmmc.tcl

create_library_set -name slow_set \
  -timing [list $env(STD_CELL)/lib/tcbn28_ss_0p81v_125c.lib \
                $env(MEM_LIB)/lib/sram_ss_0p81v_125c.lib]

create_library_set -name fast_set \
  -timing [list $env(STD_CELL)/lib/tcbn28_ff_0p99v_m40c.lib \
                $env(MEM_LIB)/lib/sram_ff_0p99v_m40c.lib]

create_opcond -name slow_cond -process 1.0 -voltage 0.81 -temperature 125
create_opcond -name fast_cond -process 1.0 -voltage 0.99 -temperature -40

create_delay_corner -name slow_corner \
  -library_set slow_set -opcond_library slow_cond
create_delay_corner -name fast_corner \
  -library_set fast_set -opcond_library fast_cond

create_constraint_mode -name func_mode -sdc_files [list scripts/constraints.sdc]

create_analysis_view -name slow_view \
  -constraint_mode func_mode -delay_corner slow_corner
create_analysis_view -name fast_view \
  -constraint_mode func_mode -delay_corner fast_corner

set_analysis_view -setup {slow_view} -hold {fast_view}
```

**9.6 — `synth_flow.tcl` — Main synthesis script**
```tcl
# build/synth/scripts/synth_flow.tcl

source scripts/setup.tcl

set_db max_cpus_per_server    8
set_db syn_generic_effort     high
set_db syn_map_effort         high
set_db syn_opt_effort         high
set_db lp_insert_clock_gating true
set_db lp_clock_gating_min_flops 4

# Read RTL
read_hdl -sv -f sources.f
elaborate fc_subsystem

# Sanity check
check_design -unresolved
check_design -multidriven

# Apply constraints
source scripts/mmmc.tcl
check_timing_intent

# Three-stage synthesis
syn_generic
write_db -to_file outputs/fc_post_generic.db

syn_map
write_db -to_file outputs/fc_post_map.db

syn_opt
write_db -to_file outputs/fc_post_opt.db

# Reports
report_timing -nworst 10 -view slow_view         > reports/timing_setup.rpt
report_timing -nworst 10 -view fast_view -hold   > reports/timing_hold.rpt
report_area   -hier                              > reports/area.rpt
report_power  -hier                              > reports/power.rpt
report_gates  -power_domain                      > reports/gates.rpt
report_clock_gating                              > reports/clock_gating.rpt
report_design -summary                           > reports/summary.rpt

# Outputs for PnR
write_hdl -mapped    > outputs/fc_subsystem_netlist.v
write_sdc            > outputs/fc_subsystem.sdc
write_db -all_root_attributes -to_file outputs/fc_subsystem_final.db

exit
```

**9.7 — Run Genus**
```bash
cd /home/user/pulpissimo/build/synth

# Batch
genus -files scripts/synth_flow.tcl -log logs/genus.log

# Interactive
genus
genus> source scripts/synth_flow.tcl
```

### Reading Synthesis Reports

**Timing report — what WNS means:**
```
WNS = Worst Negative Slack

WNS = +0.3 ns  → timing MET with 300 ps margin       ✓
WNS = -0.2 ns  → timing VIOLATED by 200 ps           ✗

Fixes for negative WNS:
  1. Increase clock period (if budget allows)
  2. Add pipeline register (RTL change)
  3. use set_multicycle_path (if logically valid)
  4. set_db syn_opt_effort extreme
  5. Use higher-drive cells on critical path
```

**Area report — typical FC distribution (28nm):**
```
fc_subsystem         100%   ~87,000 µm²
  cv32e40p_core       60%
    id_stage          16%   decoder is largest block
    ex_stage          14%
    if_stage           7%
  fpnew (FPU)         28%   FPU dominates if enabled
  fc_icache (logic)   12%   excludes SRAM macros
```

**Clock gating report — target:**
```
Registers under clock gating > 80%
If < 50%: RTL lacks explicit enables → add
          set_db lp_insert_clock_gating_incremental true
```

### Common Synthesis Issues

| Issue | Cause | Fix |
|---|---|---|
| "Unresolved: scm_*" | Behavioral SCM not synthesizable | Read SRAM wrapper HDL before elaborate |
| "Latch inferred" | Incomplete case in decoder | Fix in RTL lint step first |
| FPU fails timing | FMADD too deep | `set_multicycle_path 2 -through *fma*` |
| `SIM_STDOUT` cells in netlist | Parameter still = 1 | Set `SIM_STDOUT=0` at elaborate |
| Regfile huge area | No SCM mapping | Map to foundry register file or flip-flop array |

### Post-Synthesis Sign-Off Criteria

| Metric | Pass criterion |
|---|---|
| Worst Negative Slack (setup) | ≥ 0 ns |
| Worst Negative Slack (hold) | ≥ 0 ns |
| Unresolved module references | 0 |
| Inferred latches | 0 (or documented as intentional) |
| Clock gating efficiency | ≥ 80% |
| Combinational loops | 0 |
| Black-box instances | Only known SRAM/ROM macros |

### Bonus: Formal Equivalence Check (Cadence Conformal)

After synthesis, formally prove the netlist is logically equivalent to the RTL.
This catches any incorrect transformations the synthesis tool made.

```tcl
# conformal.tcl
read_design -golden  fc_subsystem.sv -sv09 -f sources.f
read_design -revised outputs/fc_subsystem_netlist.v
set_root_module fc_subsystem
map_key_points
compare
# Result must be: "Equivalent"
```

---

# Full Verification Sign-Off Table

Before passing the FC subsystem netlist to PnR, all checks must be
signed off:

| # | Check | Tool | Pass Criterion | Status |
|---|---|---|---|---|
| 1 | RTL Lint | SpyGlass | 0 errors, all warnings waived | ☐ |
| 2 | RTL Functional Sim | QuestaSim | All tests return 0 | ☐ |
| 3 | RISC-V Compliance | OpenOCD + riscv-arch-test | 100% pass | ☐ |
| 4 | FPU IEEE-754 | TestFloat + QuestaSim | All vectors match | ☐ |
| 5 | JTAG Debug | OpenOCD + GDB | All 5 debug ops pass | ☐ |
| 6 | CDC Analysis | SpyGlass CDC | 0 unwaived CDC-2 | ☐ |
| 7 | Gate-Level Sim | QuestaSim + SDF | Boot + regression pass | ☐ |
| 8 | Power Analysis | PrimePower | Within power budget | ☐ |
| 9 | Synthesis (Genus) | Cadence Genus | WNS ≥ 0, area within budget | ☐ |
| 10 | Formal Equiv. | Cadence Conformal | RTL ≡ netlist | ☐ |

---

# Next Blocks (To Be Documented)

The following L3 blocks follow the same pattern (hierarchy → verification → synthesis).
Sections to be added as the design progresses:

- [ ] **L3: SoC Interconnect** — AXI4 crossbar topology, address decode, timing closure
- [ ] **L3: L2 Memory Subsystem** — SCM→SRAM replacement, MBIST strategy, banking
- [ ] **L3: uDMA Subsystem** — Channel architecture, FIFO sizing, HyperBus DDR
- [ ] **L3: Peripheral Subsystem** — APB register map, GPIO, timer
- [ ] **L2: Clock Generation** — PLL replacement, FLL bypass, clock mux safety
- [ ] **L2: Padframe** — Padrick regeneration with foundry IO cells, JTAG IO requirements
- [ ] **PnR Flow** — Floorplan, power plan, CTS, routing, DRC/LVS, STA signoff
- [ ] **DFT** — Scan insertion, MBIST, ATPG, boundary scan
- [ ] **Physical Verification** — Calibre DRC, LVS, PEX, IR drop

---

# Appendix A — Repository Structure Reference

```
pulpissimo/
├── Bender.yml              Dependency declarations (versions locked in Bender.lock)
├── Makefile                Top-level build targets
├── hw/
│   ├── pulpissimo.sv       ASIC top-level
│   ├── soc_domain.sv       pulp_soc wrapper
│   ├── clock_gen_generic.sv Behavioral clock gen (replace for ASIC)
│   ├── clock_gen_fpga.sv   FPGA clock gen (Xilinx MMCM)
│   ├── asic_autogen_rom.sv Boot ROM (regenerate from sw/bootcode/)
│   ├── fpga_autogen_rom.sv FPGA boot ROM
│   ├── includes/
│   │   └── pulp_soc_defines.sv  Global defines (JTAG IDs, cache config, etc.)
│   ├── padframe/           Padrick-generated padframe (RTL sim + FPGA variants)
│   └── vendored_ips/
│       └── gpio/           Vendored GPIO IP (reconfigurable pad count)
├── sw/
│   ├── bootcode/           Boot ROM C source + linker script + ROM generator
│   └── pulp-runtime/       Minimal bare-metal runtime for CV32E40P
├── target/
│   ├── sim/
│   │   ├── questasim/      QuestaSim Makefile + compile scripts
│   │   ├── tb/             Testbench source (tb_pulp.sv, SimJTAG.sv, ...)
│   │   └── vip/            Optional verification IPs (I2C, Flash, I2S models)
│   ├── lint/
│   │   └── spyglass/       SpyGlass lint Makefile + TCL
│   └── fpga/               FPGA build targets (Xilinx)
└── doc/
    ├── pulpissimo_archi.png       Architecture diagram
    └── pulpissimo_asic_flow.md    ← THIS DOCUMENT
```

---

# Appendix B — Key External Dependencies

| IP | Version | Repository | Role |
|---|---|---|---|
| `pulp_soc` | 5.0.1 | pulp-platform/pulp_soc | Core SoC logic |
| `cv32e40p` | (via pulp_soc) | openhwgroup/cv32e40p | RISC-V core |
| `fpnew` | (via pulp_soc) | pulp-platform/fpnew | FPU |
| `udma_core` | (via pulp_soc) | pulp-platform/udma_core | DMA engine |
| `common_cells` | 1.21.0 | pulp-platform/common_cells | Synchronizers, FIFOs, etc. |
| `tech_cells_generic` | 0.2.3 | pulp-platform/tech_cells_generic | Technology-agnostic cell wrappers |
| `generic_FLL` | 0.2.0 | pulp-platform/generic_FLL | Frequency locked loop model |
| `axi` | (via pulp_soc) | pulp-platform/axi | AXI4 interconnect |

---

# Appendix C — Tool Version Reference

| Tool | Version used | Purpose |
|---|---|---|
| Bender | latest | RTL dependency management + filelist generation |
| QuestaSim | (site-specific) | RTL + gate-level simulation |
| SpyGlass | 2022.06 | Lint + CDC analysis |
| Cadence Genus | (site-specific) | Logic synthesis |
| Cadence Innovus | (site-specific) | Place and route |
| Synopsys PrimeTime | (site-specific) | STA signoff |
| Synopsys PrimePower | (site-specific) | Power analysis |
| Cadence Conformal | (site-specific) | Formal equivalence checking |
| OpenOCD (RISC-V fork) | latest | JTAG debug + compliance testing |
| riscv-arch-test | latest | RISC-V compliance suite |
| Berkeley TestFloat-3 | latest | IEEE-754 FPU verification vectors |
| Pandoc | ≥ 3.0 | Export this document to PDF/Word |

---

## L3 #4 — uDMA Subsystem {#udma}

### 4.1 Role and Purpose

The uDMA (micro-DMA) is PULPissimo's autonomous peripheral DMA engine. Once the CPU programs a descriptor, the uDMA moves data between L2 memory and any peripheral **without CPU involvement**. This enables ultra-low-power operation: the CV32E40P can enter WFI sleep while audio, sensor, or communication data flows unattended.

### 4.2 Sub-Hierarchy

```
pulp_soc (Bender: pulp_soc v5.0.1)
└── udma_subsystem
    ├── udma_core              ← central scheduler + L2 AXI master + APB slave
    │   ├── udma_ctrl          ← clock-gate register (UDMA_CONF_CG), event mux
    │   ├── udma_rx_ch[N]      ← per-channel RX FIFO (32-entry, 32-bit wide)
    │   └── udma_tx_ch[N]      ← per-channel TX FIFO + descriptor buffer
    │
    ├── udma_uart   [N_UART=1] ← 8N1/8E1, baud generator, RX oversampling
    ├── udma_i2c    [N_I2C=2]  ← master-only I2C, micro-code command sequencer
    ├── udma_qspi   [N_QSPIM=1]← QSPI master, XIP-style burst, DDR mode
    ├── udma_i2s    [N_I2S=1]  ← I2S/PDM audio, 2-ch TDM, master/slave
    ├── udma_camera [N_CPI=1]  ← Camera Parallel Interface, line/frame sync
    ├── udma_sdio   [N_SDIO=1] ← SDIO/SD-card host, 4-bit data, CRC7/16
    ├── udma_hyper  [N_HYPER=1]← HyperBus / HyperRAM / HyperFlash, DDR 200 Mbps
    └── udma_filter [optional] ← in-line CIC+HBF decimator (PDM→PCM)
```

Channel counts come from `udma_cfg_pkg` (inside `pulp_soc`). Default: 1 UART, 2 I2C, 1 QSPI, 1 I2S, 1 CPI, 1 SDIO, 1 HyperBus → ~16 logical DMA channels (each with RX + TX half).

### 4.3 Bus Interfaces

| Interface | Protocol | Width | Direction | Connected to |
|-----------|----------|-------|-----------|--------------|
| L2 data bus | AXI4-Lite | 32b addr/data | Master | L2 memory crossbar |
| Config bus | APB | 32b | Slave | APB bridge from SoC interconnect |
| Pad interfaces | Per-IP struct | varies | Bidirectional | `hw/padframe/padframe_adapter.sv` |
| Events | Pulse (event bus) | 4b/channel | Output | FC event unit |

**APB address map** (base `0x1A10_2000`):

```
0x000  UDMA_CONF_CG    — per-channel clock gate (1 bit per channel)
0x004  UDMA_CONF_EVTIN — event trigger source mux
0x080+ Peripheral 0 (UART0): RX_SADDR, RX_SIZE, RX_CFG; TX_SADDR, TX_SIZE, TX_CFG; CUSTOM[6]
0x100+ Peripheral 1 (I2C0)
0x180+ Peripheral 2 (I2C1)
...   (0x80 per peripheral; 0x10 per half-channel)
```

**Per-channel descriptor registers** (`udma_v3.h`):

```c
SADDR  [31:0]  // L2 start address for transfer
SIZE   [15:0]  // bytes to transfer
CFG    [5:0]   // EN[4], CONT[0] (ping-pong), SIZE_8/16/32[2:1], CLEAR[5]
```

### 4.4 Clock Domain

```
soc_clk (~200 MHz) ── udma_core AXI master (L2 write path)
per_clk (~100 MHz) ── APB config registers, FIFO read side
ext I/O clocks     ── channel PHY (I2S BCLK, QSPI SCK, HyperBus CLK)
```

**CDC crossings** (all must be verified in Check 6):

| Crossing | From → To | Mechanism |
|----------|-----------|-----------|
| RX FIFO write pointer | ext_clk → per_clk | gray-code + 2FF (`fifo_v3`) |
| RX FIFO read pointer | per_clk → ext_clk | gray-code + 2FF |
| RX FIFO read pointer | per_clk → soc_clk | gray-code + 2FF |
| TX FIFO write pointer | soc_clk → per_clk | gray-code + 2FF |
| Channel enable | per_clk → soc_clk | pulse synchronizer |
| HyperBus RWDS | external pad → per_clk | fully async (waive in CDC) |

### 4.5 ASIC-Specific Strategy

#### SCM FIFOs → SRAM or FF-array
Channel FIFOs are 32×32 bits (128 bytes). Options:
- **Flip-flop array**: synthesizes clean, ~3× area vs SRAM, acceptable for small FIFOs
- **Foundry 1-port SRAM**: memory compiler macro, replace `fifo_v3` storage array

#### HyperBus DDR IO Cells — Critical
`udma_hyper` drives DDR data at 200 Mbps. The behavioral RTL model uses a `negedge` flip-flop:

```systemverilog
// Behavioral — does NOT synthesize correctly through standard cells
always_ff @(posedge clk) dq_out_rise <= data[7:0];
always_ff @(negedge clk) dq_out_fall <= data[15:8];
```

**For ASIC**: replace with foundry DDR output IO cell (e.g., `DDRIOBUF`). This must happen **before synthesis** or Genus will generate incorrect negedge logic using standard cells.

#### Clock Gating for Power
`UDMA_CONF_CG` gates `per_clk` to each inactive channel. Verify ICG coverage:

```tcl
# In Genus after syn_map:
report_clock_gating -hier -module udma_subsystem > udma_cg_report.rpt
# Expect: 1 ICG cell per channel at its clock root
```

Target: **≥80% switching activity reduction** when a channel is idle.

#### udma_filter Multicycle Path
CIC+HBF decimation logic runs at I2S BCLK (2–4 MHz) — fast relative to its computation window:

```sdc
set_multicycle_path 2 -setup -through [get_pins -hier -filter "name=~*udma_filter*hbf*"]
set_multicycle_path 1 -hold  -through [get_pins -hier -filter "name=~*udma_filter*hbf*"]
```

### 4.6 Verification Checklist (uDMA)

#### Check 1 — RTL Lint

```bash
cd target/lint/spyglass
make lint_rtl BENDER_TARGETS="-t rtl_sim -t asic"
make show_results
```

uDMA-specific rules to watch:
- `W528` — undriven output: HyperBus DDR outputs if DDR IO model absent
- `W013` — multiple drivers: I2S BCLK if master/slave mode simultaneously active
- `STARC05-2.1.3.1` — latches: channel enable not fully synchronous

**Pass**: 0 errors, 0 policy-violating warnings.

#### Check 2 — RTL Functional Simulation (per channel)

```bash
cd target/sim/questasim
make build

# UART loopback (TX pad → RX pad connected externally)
make run_sim EXECUTABLE_PATH=<uart_test.hex> BOOTMODE=fastboot VSIM_FLAGS="+UART_LOOPBACK=1"

# HyperBus (uses HyperRAM behavioral model in target/sim/vip/)
make run_sim EXECUTABLE_PATH=<hyper_test.hex> BOOTMODE=fastboot

# Load uDMA wave group
do waves/udma_ss.tcl
```

Pass criteria per channel: received data == transmitted data; no FIFO overflow events; interrupt fires on transfer complete.

#### Check 3 — RISC-V Compliance (uDMA-adjacent)

uDMA register access tested indirectly: FC must program `SADDR/SIZE/CFG` registers without bus faults. Run compliance bootcode and verify no data-access exceptions occur in log:

```bash
make run_sim EXECUTABLE_PATH=<compliance.hex> BOOTMODE=jtag_openocd
openocd -f target/sim/tb/openocd_configs/pulpissimo_compliance_test.cfg
# Expect: OpenOCD log shows "riscv test_compliance passed"
```

#### Check 4 — FPU IEEE-754

Not applicable to uDMA. Mark **N/A**.

#### Check 5 — JTAG Debug While DMA In-Flight

Verify CPU can be halted while uDMA transfer is active (autonomy property):

```bash
# Terminal 1: sim with long DMA transfer
make run_sim EXECUTABLE_PATH=<long_dma.hex> BOOTMODE=jtag_openocd gui=1

# Terminal 2: OpenOCD + GDB
openocd -f target/sim/tb/openocd_configs/pulpissimo_debug.cfg
riscv32-unknown-elf-gdb <long_dma.elf>
(gdb) target remote :3333
(gdb) monitor halt
(gdb) x/4w 0x1A102084    # UART0 TX_CFG — must show EN=1 while halted
(gdb) monitor resume
```

Pass: L2 memory contents advance during CPU halt; CPU resumes cleanly.

#### Check 6 — CDC Analysis (uDMA is High Priority)

```bash
cd target/lint/spyglass
make lint_rtl LINT_MODE=cdc
```

All 6 crossing types (see table in Section 4.4) must be covered by gray-code synchronizers. Waive only the HyperBus async RWDS input:

```tcl
# cdc_waiver.do
waive -rule {CDC_COHERENCY} -module {udma_hyper} \
  -comment "HyperBus RWDS is async by architecture"
```

Pass: 0 unwaived violations.

#### Check 7 — Gate-Level Simulation

```bash
# Generate SDF from Genus
genus_tcl> write_sdf $netlist_dir/pulpissimo.sdf

# GLS with SDF back-annotation
vsim -sdfmax /tb_pulp/i_dut/i_soc_domain/i_pulp_soc/i_udma_subsystem=\
  build/synth/outputs/pulpissimo.sdf \
  -L <foundry_stdcell_lib> work.tb_pulp
```

Pass: UART loopback and HyperBus read-back correct; no `X` on FIFO outputs (X = setup/hold violation on async FIFO gray-code path).

#### Check 8 — Power Analysis

```bash
# Dump VCD for uDMA only
vsim work.tb_pulp -do "
  vcd file udma_activity.vcd;
  vcd add -r /tb_pulp/i_dut/.../i_udma_subsystem/*;
  run 10ms; vcd flush; quit -f"

# Analyze in PrimePower/Voltus
primepow -read_vcd udma_activity.vcd \
         -read_netlist build/synth/outputs/pulpissimo.v \
         -read_sdc constraints/pulpissimo_asic.sdc \
         -output_dir reports/power/udma
```

Pass: Clock gating efficiency ≥80% when only 1 channel active. HyperBus DDR power within budget (~10–15 mW at 200 MHz/0.9V is expected).

#### Check 9 — Synthesis (Cadence Genus)

Append to main SDC before running Genus:

```sdc
# uDMA async pad clocks
create_clock -name i2s_bclk -period 250.0 [get_ports pad_i2s_sck_i]
create_clock -name qspi_sck -period  20.0 [get_ports {pad_spim_sck*}]

set_clock_groups -asynchronous \
  -group {soc_clk} -group {per_clk} -group {slow_clk} \
  -group {jtag_tck} -group {i2s_bclk} -group {qspi_sck}

# HBF filter multicycle
set_multicycle_path 2 -setup -through [get_pins -hier -filter "name=~*udma_filter*hbf*"]
set_multicycle_path 1 -hold  -through [get_pins -hier -filter "name=~*udma_filter*hbf*"]

# I2C SCL stretch logic
set_multicycle_path 4 -setup -through [get_pins -hier -filter "name=~*udma_i2c*scl_stretch*"]
set_multicycle_path 3 -hold  -through [get_pins -hier -filter "name=~*udma_i2c*scl_stretch*"]

# HyperBus DDR output timing
set_output_delay -max  1.0 -clock qspi_sck [get_ports {pad_hyper_dq*}]
set_output_delay -min -0.5 -clock qspi_sck [get_ports {pad_hyper_dq*}]
set_output_delay -max  1.0 -clock qspi_sck -clock_fall \
  [get_ports {pad_hyper_dq*}] -add_delay

# HyperBus RWDS — async input, no timing check
set_false_path -from [get_ports pad_hyper_rwds_i]
```

Expected area (28nm rough estimate):

| Sub-block | NAND2-equivalent gates |
|-----------|------------------------|
| udma_core (scheduler + FIFOs) | ~8K |
| udma_uart | ~2K |
| udma_i2c ×2 | ~5K |
| udma_qspi | ~6K |
| udma_i2s | ~4K |
| udma_camera | ~3K |
| udma_sdio | ~7K |
| udma_hyper | ~10K |
| **Total** | **~45K** |

Pass: WNS ≥ 0 at all MMMC corners; `report_clock_gating` shows 1 ICG per channel.

#### Check 10 — Formal Equivalence

```bash
lec -work reports/lec/udma/ <<'EOF'
read_library -both $PDK_LEC_LIB
read_design -golden -sdc constraints/pulpissimo_asic.sdc -verilog rtl_list_udma.f
read_design -revised -verilog build/synth/outputs/pulpissimo.v
set_root_module udma_subsystem -both
set_flatten_model -seq_constant
map_points -auto
verify
report_verify
EOF
```

Waive HyperBus DDR cell and any SCM→SRAM replacements as structural differences; verify data path equivalence manually for those instances.

### 4.7 Sign-off Table

```
uDMA Subsystem — ASIC Tapeout Sign-off
──────────────────────────────────────────────────────────────────────────
 #    Check                                Status   Notes
──────────────────────────────────────────────────────────────────────────
 1    RTL Lint — 0 errors                   ☐
 2    Functional sim — all 7 channels        ☐       UART/I2C/QSPI/I2S/CPI/SDIO/HyperBus
 3    RISC-V compliance — no bus faults      ☐       uDMA register access
 4    FPU IEEE-754                          N/A
 5    JTAG halt while DMA in-flight          ☐       CPU halts, uDMA continues autonomously
 6    CDC — 0 unwaived violations            ☐       6 crossing types; RWDS waived
 7    Gate-level sim — all channels pass     ☐       SDF back-annotated; no X on FIFOs
 8    Power — ICG efficiency ≥80%            ☐       Per-channel clock gating verified
 9    Synthesis — WNS ≥ 0 all corners        ☐       HyperBus DDR cell replaced pre-synth
 10   Formal equiv — RTL vs netlist          ☐       DDR/SCM replacements waived
──────────────────────────────────────────────────────────────────────────
 HyperBus DDR IO cell replaced (not behavioral)  ☐
 FIFO SCM → FF-array or SRAM macro               ☐
 UDMA_CONF_CG gates → foundry ICG cells          ☐
 udma_filter HBF multicycle path in SDC          ☐
 Pad interfaces count matches udma_cfg_pkg        ☐
──────────────────────────────────────────────────────────────────────────
```

---

*Document version 0.2 — Last updated: 2026-06-02*
*To update: edit `doc/pulpissimo_asic_flow.md` and commit to the branch.*
