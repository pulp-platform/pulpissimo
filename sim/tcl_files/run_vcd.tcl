# start and end time in ns
set VCDSTART 54935198
#57621401
set VCDEND 54954410
#57832733
set prefix riscv

set model [lindex [split [exec cat ../../config_profiling.h | grep -v "//" | grep MODEL]] 1]
set outpufmtile [lindex [split [exec cat ../../config_profiling.h | grep OUTPUT]] 2]
set checkFMIN [lindex [split [exec cat ../../config_profiling.h | grep FMIN]] 0]
if {$checkFMIN == "#define"} {
set FMIN true
} else {
set FMIN false
}
set VCDFILE ${prefix}_${model}_${outpufmtile}_$FMIN.vcd.gz

mkdir -p vcd
vcd file vcd/$VCDFILE
run  ${VCDSTART}ns
vcd add -r /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/*
run @${VCDEND}ns
vcd flush
