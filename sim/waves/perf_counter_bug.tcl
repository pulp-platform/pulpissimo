onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -expand -group {Performance Counter Bug} /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/cs_registers_i/i_perf_bug_asserts/N_PERF_COUNTERS
add wave -noupdate -expand -group {Performance Counter Bug} /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/cs_registers_i/i_perf_bug_asserts/clk
add wave -noupdate -expand -group {Performance Counter Bug} /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/cs_registers_i/i_perf_bug_asserts/PCCR_in
add wave -noupdate -expand -group {Performance Counter Bug} /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/cs_registers_i/i_perf_bug_asserts/id_valid_i
add wave -noupdate -expand -group {Performance Counter Bug} /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/cs_registers_i/i_perf_bug_asserts/is_decoding_i
add wave -noupdate -expand -group {Performance Counter Bug} /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/cs_registers_i/i_perf_bug_asserts/ld_stall_i
add wave -noupdate -expand -group {Performance Counter Bug} /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/cs_registers_i/i_perf_bug_asserts/id_valid_q
add wave -noupdate -expand -group {Performance Counter Bug} /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/cs_registers_i/i_perf_bug_asserts/jr_stall_i
add wave -noupdate -expand -group {Performance Counter Bug} /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/cs_registers_i/i_perf_bug_asserts/imiss_i
add wave -noupdate -expand -group {Performance Counter Bug} /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/cs_registers_i/i_perf_bug_asserts/pc_set_i
add wave -noupdate -expand -group {Performance Counter Bug} /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/cs_registers_i/i_perf_bug_asserts/mem_load_i
add wave -noupdate -expand -group {Performance Counter Bug} /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/cs_registers_i/i_perf_bug_asserts/mem_store_i
add wave -noupdate -expand -group {Performance Counter Bug} /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/cs_registers_i/i_perf_bug_asserts/jump_i
add wave -noupdate -expand -group {Performance Counter Bug} /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/cs_registers_i/i_perf_bug_asserts/branch_i
add wave -noupdate -expand -group {Performance Counter Bug} /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/cs_registers_i/i_perf_bug_asserts/branch_taken_i
add wave -noupdate -expand -group {Performance Counter Bug} /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/cs_registers_i/i_perf_bug_asserts/is_compressed_i
add wave -noupdate -expand -group {Performance Counter Bug} /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE/cs_registers_i/i_perf_bug_asserts/pipeline_stall_i
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {0 ps} 0}
quietly wave cursor active 0
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 1
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {0 ps} {1 ns}
