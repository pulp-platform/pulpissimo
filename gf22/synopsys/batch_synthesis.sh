#!/bin/bash
frequencies="2100 1900 2000 2200 2300 2400"

for freq in $frequencies; do
echo "Run with period=$freq"
sed -i "s/set.* CLOCK_FAST_RISCV.*/set CLOCK_FAST_RISCV ${freq}/g" ./scripts/setup/setup.tcl
synopsys-2018.06 dc_shell -64bit -x "source scripts/synth_onlycore.tcl; exit;"
done
