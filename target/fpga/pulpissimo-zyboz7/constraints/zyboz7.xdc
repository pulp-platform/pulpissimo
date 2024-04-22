#######################################
#  _______ _           _              #
# |__   __(_)         (_)             #
#    | |   _ _ __ ___  _ _ __   __ _  #
#    | |  | | '_ ` _ \| | '_ \ / _` | #
#    | |  | | | | | | | | | | | (_| | #
#    |_|  |_|_| |_| |_|_|_| |_|\__, | #
#                               __/ | #
#                              |___/  #
#######################################


#Create constraint for the clock input of the ZyboZ7
create_clock -period 8.000 -name ref_clk_i [get_ports ref_clk_i]
set_property CLOCK_DEDICATED_ROUTE ANY_CMT_COLUMN [get_nets ref_clk]

## JTAG
create_clock -period 100.000 -name tck -waveform {0.000 50.000} [get_ports pad_jtag_tck]
set_input_jitter tck 1.000
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets i_pulpissimo/i_padframe/i_pulpissimo_pads/i_all_pads/i_all_pads_pads/i_pad_jtag_tck/O]


# minimize routing delay
set_input_delay -clock tck -clock_fall 5.000 [get_ports pad_jtag_tdi]
set_input_delay -clock tck -clock_fall 5.000 [get_ports pad_jtag_tms]
set_output_delay -clock tck 5.000 [get_ports pad_jtag_tdo]

set_max_delay -to [get_ports pad_jtag_tdo] 20.000
set_max_delay -from [get_ports pad_jtag_tms] 20.000
set_max_delay -from [get_ports pad_jtag_tdi] 20.000

set_max_delay -datapath_only -from [get_pins i_pulpissimo/i_soc_domain/i_pulp_soc/i_dmi_jtag/i_dmi_cdc/i_cdc_resp/i_src/data_src_q_reg*/C] -to [get_pins i_pulpissimo/i_soc_domain/i_pulp_soc/i_dmi_jtag/i_dmi_cdc/i_cdc_resp/i_dst/data_dst_q_reg*/D] 20.000
set_max_delay -datapath_only -from [get_pins i_pulpissimo/i_soc_domain/i_pulp_soc/i_dmi_jtag/i_dmi_cdc/i_cdc_resp/i_src/req_src_q_reg/C] -to [get_pins i_pulpissimo/i_soc_domain/i_pulp_soc/i_dmi_jtag/i_dmi_cdc/i_cdc_resp/i_dst/req_dst_q_reg/D] 20.000
set_max_delay -datapath_only -from [get_pins i_pulpissimo/i_soc_domain/i_pulp_soc/i_dmi_jtag/i_dmi_cdc/i_cdc_req/i_dst/ack_dst_q_reg/C] -to [get_pins i_pulpissimo/i_soc_domain/i_pulp_soc/i_dmi_jtag/i_dmi_cdc/i_cdc_req/i_src/ack_src_q_reg/D] 20.000


# reset signal
set_false_path -from [get_ports pad_reset]
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets pad_reset_n_IBUF]

set_property CLOCK_DEDICATED_ROUTE ANY_CMT_COLUMN [get_nets i_pulpissimo/i_clock_gen/i_slow_clk_div/i_clk_mux/clk_o]
set_property CLOCK_DEDICATED_ROUTE ANY_CMT_COLUMN [get_nets i_pulpissimo/i_clock_gen/i_slow_clk_mngr/inst/clk_out1]

# increase MTBF
set_property ASYNC_REG true [get_cells i_pulpissimo/i_soc_domain/i_pulp_soc/soc_peripherals_i/i_apb_adv_timer/u_tim0/u_in_stage/r_ls_clk_sync_reg*]
set_property ASYNC_REG true [get_cells i_pulpissimo/i_soc_domain/i_pulp_soc/soc_peripherals_i/i_apb_adv_timer/u_tim1/u_in_stage/r_ls_clk_sync_reg*]
set_property ASYNC_REG true [get_cells i_pulpissimo/i_soc_domain/i_pulp_soc/soc_peripherals_i/i_apb_adv_timer/u_tim2/u_in_stage/r_ls_clk_sync_reg*]
set_property ASYNC_REG true [get_cells i_pulpissimo/i_soc_domain/i_pulp_soc/soc_peripherals_i/i_apb_adv_timer/u_tim3/u_in_stage/r_ls_clk_sync_reg*]
set_property ASYNC_REG true [get_cells i_pulpissimo/i_soc_domain/i_pulp_soc/soc_peripherals_i/i_apb_timer_unit/s_ref_clk*]
set_property ASYNC_REG true [get_cells i_pulpissimo/i_soc_domain/i_pulp_soc/soc_peripherals_i/i_ref_clk_sync/i_pulp_sync/r_reg_reg*]
set_property ASYNC_REG true [get_cells i_pulpissimo/i_soc_domain/i_pulp_soc/soc_peripherals_i/u_evnt_gen/r_ls_sync_reg*]

# Create asynchronous clock group between slow-clk and SoC clock. Those clocks
# are considered asynchronously and proper synchronization regs are in place
set_clock_groups -asynchronous -group [get_clocks -of_objects [get_pins i_pulpissimo/i_clock_gen/slow_clk_o]] \
                               -group [get_clocks -of_objects [get_pins i_pulpissimo/i_clock_gen/i_clk_manager/clk_out1]]

# Create asynchronous clock group between Per Clock  and SoC clock. Those clocks
# are considered asynchronously and proper synchronization regs are in place
set_clock_groups -asynchronous -group [get_clocks -of_objects [get_pins i_pulpissimo/i_clock_gen/i_clk_manager/clk_out1]] \
                               -group [get_clocks -of_objects [get_pins i_pulpissimo/i_clock_gen/i_clk_manager/clk_out2]]

# Create asynchronous clock group between JTAG TCK and SoC clock.
set_clock_groups -asynchronous -group [get_clocks -of_objects [get_pins i_pulpissimo/pad_jtag_tck]] \
                               -group [get_clocks -of_objects [get_pins i_pulpissimo/i_clock_gen/i_clk_manager/clk_out1]]

#############################################################
#  _____ ____         _____      _   _   _                  #
# |_   _/ __ \       / ____|    | | | | (_)                 #
#   | || |  | |_____| (___   ___| |_| |_ _ _ __   __ _ ___  #
#   | || |  | |______\___ \ / _ \ __| __| | '_ \ / _` / __| #
#  _| || |__| |      ____) |  __/ |_| |_| | | | | (_| \__ \ #
# |_____\____/      |_____/ \___|\__|\__|_|_| |_|\__, |___/ #
#                                                 __/ |     #
#                                                |___/      #
#############################################################

## Sys clock
set_property -dict {PACKAGE_PIN K17 IOSTANDARD LVCMOS33} [get_ports ref_clk_i]

## Reset
set_property -dict {PACKAGE_PIN K18 IOSTANDARD LVCMOS33} [get_ports pad_reset]

## Buttons
set_property -dict {PACKAGE_PIN P16 IOSTANDARD LVCMOS33} [get_ports btn1_i]
set_property -dict {PACKAGE_PIN K19 IOSTANDARD LVCMOS33} [get_ports btn2_i]
set_property -dict {PACKAGE_PIN Y16 IOSTANDARD LVCMOS33} [get_ports btn3_i]

## PMOD JE
set_property -dict {PACKAGE_PIN V12 IOSTANDARD LVCMOS33} [get_ports pad_jtag_tms]
set_property -dict {PACKAGE_PIN W16 IOSTANDARD LVCMOS33} [get_ports pad_jtag_tdi]
set_property -dict {PACKAGE_PIN J15 IOSTANDARD LVCMOS33} [get_ports pad_jtag_tdo]
set_property -dict {PACKAGE_PIN H15 IOSTANDARD LVCMOS33} [get_ports pad_jtag_tck]
set_property -dict {PACKAGE_PIN V13 IOSTANDARD LVCMOS33} [get_ports pad_uart_rx]
set_property -dict {PACKAGE_PIN U17 IOSTANDARD LVCMOS33} [get_ports pad_uart_tx]
set_property -dict {PACKAGE_PIN T17 IOSTANDARD LVCMOS33} [get_ports pad_uart_rts]
set_property -dict {PACKAGE_PIN Y17 IOSTANDARD LVCMOS33} [get_ports pad_uart_cts]

## PMOD JB
set_property -dict {PACKAGE_PIN V8 IOSTANDARD LVCMOS33} [get_ports pad_pmodb_1]
set_property -dict {PACKAGE_PIN W8 IOSTANDARD LVCMOS33} [get_ports pad_pmodb_2]
set_property -dict {PACKAGE_PIN U7 IOSTANDARD LVCMOS33} [get_ports pad_pmodb_3]
set_property -dict {PACKAGE_PIN V7 IOSTANDARD LVCMOS33} [get_ports pad_pmodb_4]
set_property -dict {PACKAGE_PIN Y7 IOSTANDARD LVCMOS33} [get_ports pad_pmodb_7]
set_property -dict {PACKAGE_PIN Y6 IOSTANDARD LVCMOS33} [get_ports pad_pmodb_8]
set_property -dict {PACKAGE_PIN V6 IOSTANDARD LVCMOS33} [get_ports pad_pmodb_9]
set_property -dict {PACKAGE_PIN W6 IOSTANDARD LVCMOS33} [get_ports pad_pmodb_10]

## LEDs
set_property -dict {PACKAGE_PIN M14 IOSTANDARD LVCMOS33} [get_ports led0_o]
set_property -dict {PACKAGE_PIN M15 IOSTANDARD LVCMOS33} [get_ports led1_o]
set_property -dict {PACKAGE_PIN G14 IOSTANDARD LVCMOS33} [get_ports led2_o]
set_property -dict {PACKAGE_PIN D18 IOSTANDARD LVCMOS33} [get_ports led3_o]

## PMOD JC
set_property -dict {PACKAGE_PIN V15 IOSTANDARD LVCMOS33} [get_ports pad_pmodc_1]
set_property -dict {PACKAGE_PIN W15 IOSTANDARD LVCMOS33} [get_ports pad_pmodc_2]
set_property -dict {PACKAGE_PIN T11 IOSTANDARD LVCMOS33} [get_ports pad_pmodc_3]
set_property -dict {PACKAGE_PIN T10 IOSTANDARD LVCMOS33} [get_ports pad_pmodc_4]
set_property -dict {PACKAGE_PIN W14 IOSTANDARD LVCMOS33} [get_ports pad_pmodc_7]
set_property -dict {PACKAGE_PIN Y14 IOSTANDARD LVCMOS33} [get_ports pad_pmodc_8]
set_property -dict {PACKAGE_PIN T12 IOSTANDARD LVCMOS33} [get_ports pad_pmodc_9]
set_property -dict {PACKAGE_PIN U12 IOSTANDARD LVCMOS33} [get_ports pad_pmodc_10]

## PMOD JD
set_property -dict {PACKAGE_PIN T14 IOSTANDARD LVCMOS33} [get_ports pad_pmodd_1]
set_property -dict {PACKAGE_PIN T15 IOSTANDARD LVCMOS33} [get_ports test_clk_o]
set_property -dict {PACKAGE_PIN P14 IOSTANDARD LVCMOS33} [get_ports obs1_o]
set_property -dict {PACKAGE_PIN R14 IOSTANDARD LVCMOS33} [get_ports obs2_o]

## Switches
set_property -dict {PACKAGE_PIN G15 IOSTANDARD LVCMOS33} [get_ports switch0_i]
set_property -dict {PACKAGE_PIN P15 IOSTANDARD LVCMOS33} [get_ports switch1_i]
set_property -dict {PACKAGE_PIN W13 IOSTANDARD LVCMOS33} [get_ports switch2_i]
set_property -dict {PACKAGE_PIN T16 IOSTANDARD LVCMOS33} [get_ports switch3_i]
