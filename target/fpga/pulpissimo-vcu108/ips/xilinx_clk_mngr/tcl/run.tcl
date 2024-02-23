source ../../tcl/common.tcl

# detect target clock
if [info exists ::env(FC_CLK_PERIOD_NS)] {
    set FC_CLK_PERIOD_NS $::env(FC_CLK_PERIOD_NS)
} else {
    set FC_CLK_PERIOD_NS 10.000
}
if [info exists ::env(PER_CLK_PERIOD_NS)] {
    set PER_CLK_PERIOD_NS $::env(PER_CLK_PERIOD_NS)
} else {
    set PER_CLK_PERIOD_NS 20.000
}


set FC_CLK_FREQ_MHZ [expr 1000 / $FC_CLK_PERIOD_NS]
set PER_CLK_FREQ_MHZ [expr 1000 / $PER_CLK_PERIOD_NS]

set ipName xilinx_clk_mngr

create_project $ipName . -part $partNumber
set_property board_part $XILINX_BOARD [current_project]

create_ip -name clk_wiz -vendor xilinx.com -library ip -module_name $ipName

set_property -dict [eval list CONFIG.PRIM_IN_FREQ {125.000} \
                        CONFIG.NUM_OUT_CLKS {2} \
                        CONFIG.CLKOUT2_USED {true} \
                        CONFIG.RESET_TYPE {ACTIVE_LOW} \
                        CONFIG.RESET_PORT {resetn} \
                        CONFIG.CLKOUT1_REQUESTED_OUT_FREQ {$FC_CLK_FREQ_MHZ} \
                        CONFIG.CLKOUT2_REQUESTED_OUT_FREQ {$PER_CLK_FREQ_MHZ} \
                        CONFIG.CLKIN1_JITTER_PS {50.0} \
                       ] [get_ips $ipName]

create_ip_run [get_ips $ipName]
launch_run -jobs 8 ${ipName}_synth_1
wait_on_run ${ipName}_synth_1
