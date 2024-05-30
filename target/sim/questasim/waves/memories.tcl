onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -group l2_memory /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/clk_i
add wave -noupdate -group l2_memory /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/rst_ni
add wave -noupdate -group l2_memory /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/init_ni
add wave -noupdate -group l2_memory /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/test_mode_i
add wave -noupdate -group l2_memory /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/pri0_address
add wave -noupdate -group l2_memory /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/pri1_address
add wave -noupdate -group l2_memory -group private_bank0 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri0_i/CLK
add wave -noupdate -group l2_memory -group private_bank0 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri0_i/INITN
add wave -noupdate -group l2_memory -group private_bank0 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri0_i/CEN
add wave -noupdate -group l2_memory -group private_bank0 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri0_i/A
add wave -noupdate -group l2_memory -group private_bank0 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri0_i/WEN
add wave -noupdate -group l2_memory -group private_bank0 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri0_i/D
add wave -noupdate -group l2_memory -group private_bank0 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri0_i/BEN
add wave -noupdate -group l2_memory -group private_bank0 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri0_i/Q
add wave -noupdate -group l2_memory -group private_bank0 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri0_i/M
add wave -noupdate -group l2_memory -group private_bank1 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri1_i/CLK
add wave -noupdate -group l2_memory -group private_bank1 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri1_i/INITN
add wave -noupdate -group l2_memory -group private_bank1 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri1_i/CEN
add wave -noupdate -group l2_memory -group private_bank1 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri1_i/A
add wave -noupdate -group l2_memory -group private_bank1 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri1_i/WEN
add wave -noupdate -group l2_memory -group private_bank1 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri1_i/D
add wave -noupdate -group l2_memory -group private_bank1 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri1_i/BEN
add wave -noupdate -group l2_memory -group private_bank1 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri1_i/Q
add wave -noupdate -group l2_memory -group private_bank1 /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/bank_sram_pri1_i/M
add wave -noupdate -group l2_memory -group bank0 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[0]/bank_i/CLK}
add wave -noupdate -group l2_memory -group bank0 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[0]/bank_i/INITN}
add wave -noupdate -group l2_memory -group bank0 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[0]/bank_i/CEN}
add wave -noupdate -group l2_memory -group bank0 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[0]/bank_i/A}
add wave -noupdate -group l2_memory -group bank0 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[0]/bank_i/WEN}
add wave -noupdate -group l2_memory -group bank0 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[0]/bank_i/D}
add wave -noupdate -group l2_memory -group bank0 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[0]/bank_i/BEN}
add wave -noupdate -group l2_memory -group bank0 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[0]/bank_i/Q}
add wave -noupdate -group l2_memory -group bank0 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[0]/bank_i/M}
add wave -noupdate -group l2_memory -group bank1 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[1]/bank_i/CLK}
add wave -noupdate -group l2_memory -group bank1 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[1]/bank_i/INITN}
add wave -noupdate -group l2_memory -group bank1 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[1]/bank_i/CEN}
add wave -noupdate -group l2_memory -group bank1 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[1]/bank_i/A}
add wave -noupdate -group l2_memory -group bank1 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[1]/bank_i/WEN}
add wave -noupdate -group l2_memory -group bank1 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[1]/bank_i/D}
add wave -noupdate -group l2_memory -group bank1 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[1]/bank_i/BEN}
add wave -noupdate -group l2_memory -group bank1 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[1]/bank_i/Q}
add wave -noupdate -group l2_memory -group bank1 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[1]/bank_i/M}
add wave -noupdate -group l2_memory -group bank2 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[2]/bank_i/CLK}
add wave -noupdate -group l2_memory -group bank2 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[2]/bank_i/INITN}
add wave -noupdate -group l2_memory -group bank2 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[2]/bank_i/CEN}
add wave -noupdate -group l2_memory -group bank2 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[2]/bank_i/A}
add wave -noupdate -group l2_memory -group bank2 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[2]/bank_i/WEN}
add wave -noupdate -group l2_memory -group bank2 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[2]/bank_i/D}
add wave -noupdate -group l2_memory -group bank2 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[2]/bank_i/BEN}
add wave -noupdate -group l2_memory -group bank2 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[2]/bank_i/Q}
add wave -noupdate -group l2_memory -group bank2 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[2]/bank_i/M}
add wave -noupdate -group l2_memory -group bank3 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[3]/bank_i/CLK}
add wave -noupdate -group l2_memory -group bank3 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[3]/bank_i/INITN}
add wave -noupdate -group l2_memory -group bank3 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[3]/bank_i/CEN}
add wave -noupdate -group l2_memory -group bank3 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[3]/bank_i/A}
add wave -noupdate -group l2_memory -group bank3 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[3]/bank_i/WEN}
add wave -noupdate -group l2_memory -group bank3 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[3]/bank_i/D}
add wave -noupdate -group l2_memory -group bank3 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[3]/bank_i/BEN}
add wave -noupdate -group l2_memory -group bank3 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[3]/bank_i/Q}
add wave -noupdate -group l2_memory -group bank3 {/tb_pulp/i_dut/soc_domain_i/pulp_soc_i/l2_ram_i/CUTS[3]/bank_i/M}
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {5873214196 ps} 0} {{Cursor 2} {52985734 ps} 1}
quietly wave cursor active 1
configure wave -namecolwidth 250
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
WaveRestoreZoom {0 ps} {6167157150 ps}
