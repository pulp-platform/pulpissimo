# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Changed
- Default dependency management is now bender, IPApproX no longer supported.
- Reorganize folder structure
- Reorganize code structure for simpler design
- Integrate padrick generated padframe
- Update `pulp_soc` to v5.0.0, update various dependencies
- Clock generation now in top level, no longer in `pulp_soc`

### Fixed
- fixed support for ibex core from top level

## [7.0.0] - 2021-06-26

### Added
- Fast virtual boot mode to accelerate simulation of software on RTL platform
- Added support for Bender as dependency management tool
- Support for ZSH for the VSIM setup script (`setup/vsim.sh`)
- Added new HyperFlash peripheral
- Added additional bootmode signal to accomodate for new Hyperflash boot
- Support for Xilinx VCU108 FPGA board

### Changed
- HWPE MAC unit is disabled by default
- The latest version of IPApprox with semver support is now used
- Bump `pulp_soc` to `v3.0.0` and updated bootcode to add support for the newest
  PULPissimo compatible version of ibex with a new OBI to TCDM protocol adapter.
- Various smaller clean-ups and improvements of the Makefiles and simulation TCL scripts
- The FPGA ports no longer generate the memories out-of-context. 
  Thus, chaning the memory size in RTL now also affects the FPGA memory size.
- Switched to new I2C peripheral version with command stream interface

### Fixed
- Resolved incompatibility with Vivao 2020.2
- Resolved incompatibility with Genus 2019.10
  (Genus support still requires to remove some SV attributes from the source code due to some issues in Genus' parser)
  Executing `find . -type f -name '*.sv' -exec sed -i -e 's/(\* async \*)//g' {} \;` 
  in the project root after checking out the sub-ips should do the trick.
- Added better handshaking behavior of mockup FLL modules in FPGA port to avoid
  deadlocks when trying to interact with the FLL in the FPGA port.
- With `pulp_soc` `v3.0.0` a serious bug in the interleaved SRAM address line
  connection is fixed which caused part of the memory to be inaccessible.
- Remove timing constraints on unmapped signals for FPGA ports
- Reduced latency of APB and AXI transactions

### Removed
- Removed support for Xilinx Zedboard. With the latest feature additions, the
  Zedboard is no longer large enough to fit the pulpissimo design. The necessary
  scripts to synthesize pulpissimo for the Zedboard will remain in the `fpga`
  directory but the bitstream generation flow will fail due to insuffienct LUTs available.

## [6.0.0] - 2020-12-11

### Changed
- Bump `pulp_soc` to `v2.0.0` which adds completely new interconnect with
  integrated AXI crossbar for simplified IP integration
- Make number of SPI and I2C peripherals parametrizable
- Various FPGA tcl script enhancements
- Various rtl code cleanups and assertion additions

### Added
- Fixed synthesis issues. PULPissimo is now synthesizable as is.
- Revamped datasheet & added datasheet generator
- CI support for pulp-runtime to run tests, using bwruntest.py and
  tests/runtime-tests.yaml
- CI target for all supported fpga boards
- Point to simple runtime in `README.md`
- Allow passing `generate-scripts` to pass arguments to vlog
⁻ Add global address space header file for new SoC interconnect in `pulp_soc` `v2.0.0`
- Embedded bootcode into repository and added new make target for it
- FPGA support for Nexys board familly
- Add pulp-sdk build target

### Fixed
- Properly propagate NB_CORES
- Mark tb as not synthesizable
- Add proper timing constraints for CDCs in FPGA port
- Added missing implementation of manual clock gating cells for FPGA ports

## [5.0.0] - 2019-11-18

### Added
- FPGA support for Xilinx ZCU102
- FPGA support for Nexys Video
- FPGA support for Zedboard
- [ibex](https://github.com/lowRISC/ibex/) support
- Improved software debugging (disassembly in simulator window)
- Gitlab CI (fpga synthesis, software tests, debug module tests)
- Automatic handling of VIPs (installing and compiling)
- CHANGELOD.md

### Changed
- Bump `pulp_soc` to `v1.0.0`
- Move tests to subfolder `tests`
- Allow setting entry point with `-gENTRY_POINT`
- Update to sdk-release 2019.11.02

### Fixed
- I2C EEPROM can now be concurrently used with I2C DPI model
- Small quartus compatibility fixes
- Many minor tb issues

### Removed
- zero-riscy support

## [4.0.0] - 2019-08-06

### Added
- FPGA support for genesys2
- FPGA support for Xilinx ZCU104
- Support for Xcelium

### Changed
- Update `README.m` with FPGA usage instructions

### Fixed
- Bugs in debug module integration
- AXI width issues
- USE_HWPE parameter propagation
- various debug module issues

## [3.0.0] - 2019-05-17

### Added
- Debug module compliant with [RISC-V External Debug Support v0.13.1](https://github.com/riscv/riscv-debug-spec)

### Fixed
- Various jenkins CI issues
- Bootsel behavior

### Changed
- Use new `udma`

### Removed
- Support for custom debug module

## [2.0.0] - 2019-01-24

### Added
- DPI models for peripherals
- PMP support in RI5CY

### Fixed
- JTAG issues
- Bad pad mux configuration

## [1.0.0] - 2018-02-09

### Added
- Initial release
