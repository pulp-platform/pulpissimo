#!/bin/bash
frequencies="4000 400 2000 600 1500 800 1400 900 1300 1000 1200 1100"

for freq in $frequencies; do
echo "Run with period=$freq"
sed -i "s/set.* CLOCK_FAST_RISCV.*/set CLOCK_FAST_RISCV ${freq}/g" ./scripts/setup/setup.tcl
synopsys-2018.06 dc_shell -64bit -x "source scripts/synth_onlycore.tcl; exit"
done
