target remote | $OPENOCD/bin/openocd -c "gdb_port pipe" -f $OPENOCD_CONFIG
monitor reset halt
load
continue