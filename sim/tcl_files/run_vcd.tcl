mkdir -p vcd
vcd file vcd/activities.vcd.gz
run 18479010ns
vcd add -r /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/*
run @18501047ns
vcd flush
