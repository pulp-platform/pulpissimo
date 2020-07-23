#!/usr/bin/env bash

# var that points to this project's root
ROOT=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
[[ -d $ROOT/pulp-sdk ]] || { echo "Error: Make sure you built the sdk with \`make build-pulp-sdk\'"; }
[[ -n $PULP_RISCV_GCC_TOOLCHAIN ]] || { echo "Error: PULP_RISCV_GCC_TOOLCHAIN is not set"; }
echo "Setting up SDK"
source "$ROOT/pulp-sdk/sourceme.sh"
echo "Setting up for RTL simulation"
source "$ROOT/pulp-sdk/configs/platform-rtl.sh"
echo "Setting up VSIM"
source "$ROOT/setup/vsim.sh"
