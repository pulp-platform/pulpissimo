# start and end time in ns
set VCDSTART 68334898
#68698414
#21857855
#59045857
#57621401 
#riscv 54935198
#ext 57621401
set VCDEND 69007875
#69608956
#21883798
#59051161
#57832733
# 54954410
#57832733
set prefix rnnext

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
vcd file ../../vcd/$VCDFILE
run  ${VCDSTART}ns
vcd add -r /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/*
run @${VCDEND}ns
vcd flush
