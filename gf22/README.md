# Setup

Initialize Cockpit:
```
icdesign gf22 -update all
```

Make synthesis:
```
synopsys-2018.06 dc_shell -64bit | tee view_command.log
> source scripts/synth_onlycore.tcl
```

Backend run:
```
cds_innovus-18.11.000 innovus
> source scripts/run_single_core.tcl
```
