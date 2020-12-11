# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

## [6.0.0] - 2020-12-11

### Changed
- Bump `pulp_soc` to `v2.0.0` which adds completely new interconnect with integrated AXI crossbar for simplified IP
  integration
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
