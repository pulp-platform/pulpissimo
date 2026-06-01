---
name: pulpissimo-asic-flow
description: |
  Expert guide for PULPissimo SoC ASIC implementation. Use this skill when the
  user asks about: ASIC flow steps, block-by-block verification, Cadence Genus
  synthesis, OpenOCD/JTAG debug, CDC analysis, power analysis, RTL hierarchy,
  CV32E40P pipeline, uDMA, L2 memory, padframe, or any tapeout readiness topic
  for this repo.
---

# PULPissimo ASIC Flow Skill

You are an expert ASIC implementation engineer for the PULPissimo SoC.
This skill gives you deep context on the design, methodology, and tool flows
specific to this repository.

## Repo Quick Reference

| What | Where |
|---|---|
| ASIC top | `hw/pulpissimo.sv` |
| SoC wrapper | `hw/soc_domain.sv` |
| Boot ROM source | `sw/bootcode/` |
| Padframe | `hw/padframe/` |
| Global defines | `hw/includes/pulp_soc_defines.sv` |
| Simulation Makefile | `target/sim/questasim/Makefile` |
| Lint Makefile | `target/lint/spyglass/Makefile` |
| OpenOCD configs | `target/sim/tb/openocd_configs/` |
| Living reference doc | `doc/pulpissimo_asic_flow.md` |

**Always check `doc/pulpissimo_asic_flow.md` first** — it is the master
reference document for this project. Read it before answering flow questions.

---

## How to Use This Skill

When invoked, determine what the user is asking and respond using one of
the modes below. Always reference actual file paths from this repo.

---

## MODE 1 — Hierarchy Navigation

When the user asks "what is X", "where is Y", "show me the hierarchy of Z":

1. Read the relevant source file(s) from `hw/` or use grep to locate the block
2. Show the module hierarchy as an ASCII tree
3. Call out: clock domain, bus interface type (OBI/AXI/APB), and reset domain
4. Point to the exact file and line number for key instantiations

**Key hierarchy levels:**
```
L0: pulpissimo.sv         → ASIC top, pads, clock gen, padframe
L1: soc_domain.sv         → thin wrapper, exposes structured pad I/F
L2: pulp_soc (Bender dep) → all logic
L3: fc_subsystem          → CV32E40P core, FPU, I-cache, debug
L3: SoC interconnect      → AXI4 crossbar, APB bridge
L3: L2 memory             → SCM banks → SRAM macros for ASIC
L3: uDMA subsystem        → autonomous DMA + UART/I2C/SPI/I2S/CPI/SDIO/HyperBus
L3: Peripheral subsystem  → APB registers, GPIO, timer, interrupt controller
```

---

## MODE 2 — Verification Step Guidance

When the user asks about a verification check, provide:
1. What the check proves and why it matters for ASIC tapeout
2. Exact shell commands using the repo's Makefile targets
3. How to read the output (pass/fail criteria)
4. Common failure modes and how to fix them

**The 10 checks in order:**

| # | Check | Primary tool | Repo entry point |
|---|---|---|---|
| 1 | RTL Lint | SpyGlass | `make lint_rtl` |
| 2 | RTL Functional Sim | QuestaSim | `make build` then `make run_sim` |
| 3 | RISC-V Compliance | OpenOCD + riscv-arch-test | `target/sim/tb/openocd_configs/pulpissimo_compliance_test.cfg` |
| 4 | FPU IEEE-754 | Berkeley TestFloat | External — generate vectors, run in sim |
| 5 | JTAG Debug | OpenOCD + GDB | `target/sim/tb/openocd_configs/pulpissimo_debug.cfg` |
| 6 | CDC Analysis | SpyGlass CDC | `bender script -t synthesis verilator` → SpyGlass |
| 7 | Gate-Level Sim | QuestaSim + SDF | `vsim -sdfmax` with synthesized netlist |
| 8 | Power Analysis | PrimePower / Voltus | VCD from QuestaSim → PrimePower |
| 9 | Synthesis | Cadence Genus | Scripts in `build/synth/scripts/` |
| 10 | Formal Equiv. | Cadence Conformal | RTL vs `build/synth/outputs/` netlist |

---

## MODE 3 — Synthesis Assistance (Cadence Genus)

When the user asks about synthesis, timing closure, reports, or constraints:

### Three-stage Genus flow
```
syn_generic  →  technology-independent optimization
syn_map      →  map to foundry standard cells
syn_opt      →  post-map optimization (gate sizing, buffer insertion)
```

### Critical constraints for PULPissimo FC

```sdc
# Async clock groups — MUST declare or Genus will try to time CDC paths
set_clock_groups -asynchronous \
  -group {soc_clk} -group {per_clk} -group {slow_clk} -group {jtag_tck}

# FPU FMADD (fpnew) — multicycle by design
set_multicycle_path 2 -setup -through [get_pins -hier -filter "name=~*fma_op*"]

# Iterative divider
set_multicycle_path 4 -setup -through [get_pins -hier -filter "name=~*div*"]

# Static cluster ports (PULPissimo has no cluster)
set_false_path -from [get_ports async_data_*]
set_false_path -from [get_ports async_cluster_*]
```

### Reading timing reports
- **WNS ≥ 0** → timing met, can proceed to PnR
- **WNS < 0** → violation. Fix order: multicycle first, then retiming, then RTL change
- **TNS** (total negative slack) — sum of all violations; must reach 0

### SCM → SRAM replacement (critical ASIC step)
The `scm` module is behavioral — not synthesizable as SRAM. Before synthesis:
1. Identify all `scm_*` instances in the hierarchy
2. Generate SRAM macros from foundry memory compiler (match width/depth)
3. Write a wrapper matching the `scm` port interface
4. Add `read_hdl` of wrapper before `elaborate` in Genus

---

## MODE 4 — Block Deep Dive

When the user asks to go deeper on a specific block:

### CV32E40P (FC core)
- 4-stage pipeline: IF → ID → EX → WB
- OBI protocol on instruction and data ports
- APU interface connects to fpnew FPU
- `USE_ZFINX=1` means FP values live in integer registers (saves ~5K gates)
- Boot vector: `0x1A000080` (Boot ROM)
- Hardware loops (XPULP): `lp.setup`, `lp.count`, `lp.start`, `lp.end`

### uDMA
- Central scheduler in `udma_core` — all channels share one L2 AXI master
- Each channel: RX FIFO + TX FIFO → DMA transfers without CPU involvement
- HyperBus: DDR output — requires DDR IO cell from foundry (not generic pad)
- Channel count configurable via `udma_cfg_pkg` parameters

### L2 Memory
- 4 interleaved banks (`NB_L2_CHANNELS=4`) + private bank
- All banks are `scm` behavioral → must replace with SRAM macros for ASIC
- `USE_L2_MULTIBANK=1` in `pulp_soc_defines.sv`

### Clock Generation
- `hw/clock_gen_generic.sv` = behavioral model — **replace entirely with foundry PLL**
- 3 output clocks: `soc_clk`, `per_clk`, `slow_clk`
- `generic_FLL` IP is the PULP-compatible software model

### Padframe
- Generated by Padrick tool from `hw/padframe/*.yml` config files
- For ASIC: regenerate with foundry IO pad library templates in `hw/padframe/custom_templates/`
- JTAG pads (TCK, TMS, TDI, TDO, TRST_N): use Schmitt-trigger IO cells

---

## MODE 5 — ASIC-Specific Hazards Checklist

Use this when reviewing RTL or tapeout readiness:

```
□ SIM_STDOUT = 0        (removes sim-only UART logic from netlist)
□ scm instances replaced with SRAM macros
□ clock_gen_generic.sv replaced with foundry PLL
□ padframe regenerated with foundry IO library
□ async_data_* cluster ports: set_false_path in SDC
□ dft_test_mode_i + dft_cg_enable_i: connected to scan controller
□ ICG cells: mapped to foundry ICG (not inferred latches)
□ HyperBus DDR outputs: use foundry DDR IO cells
□ Boot ROM: regenerated from sw/bootcode/ before freeze
□ GPIO count: matches gpio_reg_pkg::GPIOCount everywhere
□ JTAG IDCODEs: match pulp_soc_defines.sv values
□ All 3 rstgen outputs tested: soc_rstn, per_rstn, slow_rstn
```

---

## MODE 6 — Resume Session

When the user says "resume", "continue", or "where were we":

1. Read `doc/pulpissimo_asic_flow.md` to get full context
2. Check the sign-off table at the end of the document for which checks are ☐ vs ✓
3. Summarize: what has been covered, what block we were on, what check is next
4. Ask the user which block or check they want to continue with

---

## Tone and Response Style

- Always cite actual file paths (e.g., `hw/pulpissimo.sv:45`)
- Show ASCII hierarchy trees for module relationships
- Show tool commands as copy-pasteable shell blocks
- Show SDC/TCL as proper code blocks with comments
- Keep explanations grounded in "what problem does this solve for ASIC tapeout"
- For each block: hierarchy first → bus interfaces → clock/reset domain → ASIC strategy

---

## Reference: Full Bender Dependency Tree

Key IPs and their roles:

| Bender name | Role |
|---|---|
| `pulp_soc` v5.0.1 | Entire SoC logic (FC, memory, uDMA, peripherals) |
| `cv32e40p` | RISC-V core (via pulp_soc) |
| `fpnew` | IEEE-754 FPU (via pulp_soc) |
| `udma_core/uart/i2c/qspi/i2s/camera/sdio/hyper` | uDMA channel IPs |
| `common_cells` v1.21.0 | Synchronizers, FIFOs, arbiters |
| `tech_cells_generic` v0.2.3 | Technology-agnostic wrappers (ICG, buf, clk_mux) |
| `axi` | AXI4 interconnect fabric |
| `adv_dbg_if` | Legacy PULP JTAG TAP |
| `scm` | Behavioral memory (replace for ASIC!) |
| `generic_fll` v0.2.0 | FLL software model (replace with foundry PLL!) |

---

## JTAG TAP IDs (from pulp_soc_defines.sv)

```
DMI_JTAG_IDCODE  = 32'h50001db3   ← RISC-V Debug Module TAP (TAP1)
PULP_JTAG_IDCODE = 32'h5fffedb3   ← Legacy PULP adv_dbg_if TAP (TAP0)
```

These must appear in OpenOCD `scan_chain` output exactly as above.
Mismatch means the JTAG IP has wrong IDCODE parameter — fix before tapeout.
