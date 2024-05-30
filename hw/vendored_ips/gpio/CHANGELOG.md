# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## 0.2.2 - 2023-06-12
### Added
- Added simple CI
### Changed
- Bump bender dependencies
### Fixed
- Fix typos and errors in documentation

## 0.2.1 - 2022-12-15
### Changed
- Simplified reconfiguration flow by using vendored-in regtool.py
### Fixed
- Overlapping bitfield definition in hjson description of the CFG register. 
- Remove now obsolete Makefile dependency on bender checkout dir

## 0.2.0 - 2022-12-09
### Breaking Changes
- Changed the module interface. ``interrupt_o`` was renamed to
  ``global_interrupt_o``. Additionally, the module also exposes pin level
  interrupt signals in addition to the single, globally multiplexed gpio
  interrupt signal. Existing RTL integrating this IP need to adapt the port
  list of their instantiations.
### Changed
- Change default pad count from 56 to 32.
- Use the clock gated input stage by default for simulation targets
- Bump AXI Version
### Fixed
- Fix warning about unconnected interface port

## 0.1.2 - 2022-12-04
### Changed
- Added make dependencies to auto-setup python env for reconfiguration

### Fixed
- Fix some small issues reported by linter

## 0.1.1 - 2022-10-07
### Changed
- Bumped AXI version to v0.35.3
- Added NumRepetitions to tb_gpio to choose test duration
- Refactored TB

### Fixed
- Fix tx_en inversion bug for open-drain mode 1
- Fix bug in TB that caused open-drain misbehavior not to be catched


## 0.1.0 - 2022-04-14
Initial release
