# Simulation Environments
Pulpissimo supports simulation on various environments like commercial RTL
simulators or Verilator. The scripts and source files for simulation are
contained in this directory grouped in subdirectories by environment.


## Supported Simulation Environments
### `Generic` 
The default generic SV testbench is a regular non-UVM SystemVerilog testbench to
be simulated on conventional RTL simulators. There is a more complex testbench
based on the legacy PULPissimo testebnch (`tb_pulp.sv`) and a simplified version
to use as a template for your own TB (`tb_pulp_simple.sv`).

### `Verilator`
TODO

## Subdirectories
* `tb`: Contains the source-code like SystemVerilog, C (e.g. for DPI) or C++
  (for Verilator) for the testebenches. The folder might also contains
* `vip`: Contains **optional** additionalverification IP for the environments
  that are not strictly necessary for the environment's TB.
* `simulators`: Contains the invocation scripts/makefiles to start the various
  simulation environments.

## Simulation Environment Invocation
In order to streamline switching between different simulation environments and
to allow for easy simulation invocation during software development for
Pulpissimo, we define a standard interface to invoke a simulation interface
based on environment variables. 

Each simulation environment shall contain a Makefile with a target called
`run_sim` to invoke the simulation. The `run_sim` target shall use the following
**mandatory** environment variables (supplied by the user or the development
SDK) to control simulation invocation:

* `EXECUTABLE_PATH` The absolute path to the compiled ELF executable to be run
  on PULPissimo.

Besides the mandatory environment variables, the following optional envionment
variables shall be used for sim. environments supporting the relevant feature:

* `GUI` [`0` or `1`] For tools with a graphical user interface, this switch
  controls whether the user whishes to invoke the tool in GUI mode (1) or wants
  to simulate in console only mode.
  
* `BATCH` [`0` or `1`] If enabled, the `run_sim` target invocatoin shall exit
  with the simulated `main` functions return value as exit code. I.e. the value
  returned by the simulated firmware shall be returned by the the `run_sim**
  target as well. This simplifies CI testing using tests written in the form of
  C-applications. Simulation environments may expose optional custom environment
  variables to modify this behavior e.g. in order to fail test with a non-zero
  exit value based on the status of some optional verification IP.
  
Each simulation environment may expose additional environment variables for
environment-specific behavior that cannot be easily supported by all
environments. 

Further, the simulation can be launched with built-in launchers configured in
the `pulp-runtime` and `pulp-sdk` by setting up the appropriate environment
variables, indicated at the end of the build flow. `VSIM_PATH` needs to point to
the questasim build directory for PULPissimo, and `VSIM` needs to containt the
same value as `VSIM_BIN`.

**The ``run_sim`` target in the sim. environemts Makefile must be documented
using Makefile docs** (see ../../utils/utils.mk). All supported variables must
be documented including the mandatory and optional variables defined above.
