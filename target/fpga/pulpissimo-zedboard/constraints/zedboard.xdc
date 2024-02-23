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


#Create constraint for the clock input of the ZedBoard
create_clock -period 10.000 -name ref_clk_i [get_ports ref_clk_i]

#I2S and CAM interface are not used in this FPGA port. Set constraints to
#disable the clock
set_case_analysis 0 i_pulpissimo/safe_domain_i/cam_pclk_o
set_case_analysis 0 i_pulpissimo/safe_domain_i/i2s_slave_sck_o
#set_input_jitter tck 1.000

## JTAG
create_clock -period 100.000 -name tck -waveform {0.000 50.000} [get_ports pad_jtag_tck]
set_input_jitter tck 1.000
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets tck_int]


# minimize routing delay
set_input_delay -clock tck -clock_fall 5.000 [get_ports pad_jtag_tdi]
set_input_delay -clock tck -clock_fall 5.000 [get_ports pad_jtag_tms]
set_output_delay -clock tck 5.000 [get_ports pad_jtag_tdo]

set_max_delay -to [get_ports pad_jtag_tdo] 20.000
set_max_delay -from [get_ports pad_jtag_tms] 20.000
set_max_delay -from [get_ports pad_jtag_tdi] 20.000

set_max_delay -datapath_only -from [get_pins i_pulpissimo/soc_domain_i/pulp_soc_i/i_dmi_jtag/i_dmi_cdc/i_cdc_resp/i_src/data_src_q_reg*/C] -to [get_pins i_pulpissimo/soc_domain_i/pulp_soc_i/i_dmi_jtag/i_dmi_cdc/i_cdc_resp/i_dst/data_dst_q_reg*/D] 20.000
set_max_delay -datapath_only -from [get_pins i_pulpissimo/soc_domain_i/pulp_soc_i/i_dmi_jtag/i_dmi_cdc/i_cdc_resp/i_src/req_src_q_reg/C] -to [get_pins i_pulpissimo/soc_domain_i/pulp_soc_i/i_dmi_jtag/i_dmi_cdc/i_cdc_resp/i_dst/req_dst_q_reg/D] 20.000
set_max_delay -datapath_only -from [get_pins i_pulpissimo/soc_domain_i/pulp_soc_i/i_dmi_jtag/i_dmi_cdc/i_cdc_req/i_dst/ack_dst_q_reg/C] -to [get_pins i_pulpissimo/soc_domain_i/pulp_soc_i/i_dmi_jtag/i_dmi_cdc/i_cdc_req/i_src/ack_src_q_reg/D] 20.000


# reset signal
set_false_path -from [get_ports pad_reset]

# Set ASYNC_REG attribute for ff synchronizers to place them closer together and
# increase MTBF
set_property ASYNC_REG true [get_cells i_pulpissimo/soc_domain_i/pulp_soc_i/soc_peripherals_i/i_apb_adv_timer/u_tim0/u_in_stage/r_ls_clk_sync_reg*]
set_property ASYNC_REG true [get_cells i_pulpissimo/soc_domain_i/pulp_soc_i/soc_peripherals_i/i_apb_adv_timer/u_tim1/u_in_stage/r_ls_clk_sync_reg*]
set_property ASYNC_REG true [get_cells i_pulpissimo/soc_domain_i/pulp_soc_i/soc_peripherals_i/i_apb_adv_timer/u_tim2/u_in_stage/r_ls_clk_sync_reg*]
set_property ASYNC_REG true [get_cells i_pulpissimo/soc_domain_i/pulp_soc_i/soc_peripherals_i/i_apb_adv_timer/u_tim3/u_in_stage/r_ls_clk_sync_reg*]
set_property ASYNC_REG true [get_cells i_pulpissimo/soc_domain_i/pulp_soc_i/soc_peripherals_i/i_apb_timer_unit/s_ref_clk*]
set_property ASYNC_REG true [get_cells i_pulpissimo/soc_domain_i/pulp_soc_i/soc_peripherals_i/i_ref_clk_sync/i_pulp_sync/r_reg_reg*]
set_property ASYNC_REG true [get_cells i_pulpissimo/soc_domain_i/pulp_soc_i/soc_peripherals_i/u_evnt_gen/r_ls_sync_reg*]

# Create asynchronous clock group between slow-clk and SoC clock. Those clocks
# are considered asynchronously and proper synchronization regs are in place
set_clock_groups -asynchronous -group [get_clocks -of_objects [get_pins i_pulpissimo/safe_domain_i/i_slow_clk_gen/slow_clk_o]] -group [get_clocks -of_objects [get_pins i_pulpissimo/soc_domain_i/pulp_soc_i/i_clk_rst_gen/i_fpga_clk_gen/soc_clk_o]]

# Create asynchronous clock group between Per Clock  and SoC clock. Those clocks
# are considered asynchronously and proper synchronization regs are in place
set_clock_groups -asynchronous -group [get_clocks -of_objects [get_pins i_pulpissimo/soc_domain_i/pulp_soc_i/i_clk_rst_gen/clk_per_o]] -group [get_clocks -of_objects [get_pins i_pulpissimo/soc_domain_i/pulp_soc_i/i_clk_rst_gen/clk_soc_o]]

# Create asynchronous clock group between JTAG TCK and SoC clock.
set_clock_groups -asynchronous -group [get_clocks -of_objects [get_pins i_pulpissimo/pad_jtag_tck]] -group [get_clocks -of_objects [get_pins i_pulpissimo/soc_domain_i/pulp_soc_i/i_clk_rst_gen/clk_soc_o]]

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
set_property -dict {PACKAGE_PIN Y9 IOSTANDARD LVCMOS33} [get_ports ref_clk_i]

## Reset
set_property -dict {PACKAGE_PIN P16 IOSTANDARD LVCMOS18} [get_ports pad_reset]

## Buttons
set_property -dict {PACKAGE_PIN R16 IOSTANDARD LVCMOS18} [get_ports btnu_i]
set_property -dict {PACKAGE_PIN N15 IOSTANDARD LVCMOS18} [get_ports btnr_i]
set_property -dict {PACKAGE_PIN R18 IOSTANDARD LVCMOS18} [get_ports btnd_i]
set_property -dict {PACKAGE_PIN T18 IOSTANDARD LVCMOS18} [get_ports btnl_i]

## PMOD A
set_property -dict {PACKAGE_PIN Y11 IOSTANDARD LVCMOS33} [get_ports pad_jtag_tms]
set_property -dict {PACKAGE_PIN AA11 IOSTANDARD LVCMOS33} [get_ports pad_jtag_tdi]
set_property -dict {PACKAGE_PIN Y10 IOSTANDARD LVCMOS33} [get_ports pad_jtag_tdo]
set_property -dict {PACKAGE_PIN AA9 IOSTANDARD LVCMOS33} [get_ports pad_jtag_tck]
set_property -dict {PACKAGE_PIN AB11 IOSTANDARD LVCMOS33} [get_ports pad_uart_rx]
set_property -dict {PACKAGE_PIN AB10 IOSTANDARD LVCMOS33} [get_ports pad_uart_tx]
set_property -dict {PACKAGE_PIN AB9 IOSTANDARD LVCMOS33} [get_ports pad_uart_rts]
set_property -dict {PACKAGE_PIN AA8 IOSTANDARD LVCMOS33} [get_ports pad_uart_cts]

## PMOD B
set_property -dict {PACKAGE_PIN W12 IOSTANDARD LVCMOS33} [get_ports pad_i2c0_scl]
set_property -dict {PACKAGE_PIN W11 IOSTANDARD LVCMOS33} [get_ports pad_i2c0_sda]
set_property -dict {PACKAGE_PIN V10 IOSTANDARD LVCMOS33} [get_ports pad_i2c1_scl]
set_property -dict {PACKAGE_PIN W8 IOSTANDARD LVCMOS33} [get_ports pad_i2c1_sda]
set_property -dict {PACKAGE_PIN V12 IOSTANDARD LVCMOS33} [get_ports pad_pmod1_4]
set_property -dict {PACKAGE_PIN W10 IOSTANDARD LVCMOS33} [get_ports pad_pmod1_5]
set_property -dict {PACKAGE_PIN V9 IOSTANDARD LVCMOS33} [get_ports pad_pmod1_6]
set_property -dict {PACKAGE_PIN V8 IOSTANDARD LVCMOS33} [get_ports pad_pmod1_7]

## LEDs
set_property -dict {PACKAGE_PIN T22 IOSTANDARD LVCMOS33} [get_ports led0_o]
set_property -dict {PACKAGE_PIN T21 IOSTANDARD LVCMOS33} [get_ports led1_o]
set_property -dict {PACKAGE_PIN U22 IOSTANDARD LVCMOS33} [get_ports led2_o]
set_property -dict {PACKAGE_PIN U21 IOSTANDARD LVCMOS33} [get_ports led3_o]
set_property -dict {PACKAGE_PIN V22 IOSTANDARD LVCMOS33} [get_ports led4_o]
set_property -dict {PACKAGE_PIN W22 IOSTANDARD LVCMOS33} [get_ports led5_o]
set_property -dict {PACKAGE_PIN U19 IOSTANDARD LVCMOS33} [get_ports led6_o]
set_property -dict {PACKAGE_PIN U14 IOSTANDARD LVCMOS33} [get_ports led7_o]

## Switches
set_property -dict {PACKAGE_PIN F22 IOSTANDARD LVCMOS18} [get_ports switch0_i]
set_property -dict {PACKAGE_PIN G22 IOSTANDARD LVCMOS18} [get_ports switch1_i]
set_property -dict {PACKAGE_PIN H22 IOSTANDARD LVCMOS18} [get_ports switch2_i]
set_property -dict {PACKAGE_PIN F21 IOSTANDARD LVCMOS18} [get_ports switch3_i]
set_property -dict {PACKAGE_PIN H19 IOSTANDARD LVCMOS18} [get_ports switch4_i]
set_property -dict {PACKAGE_PIN H18 IOSTANDARD LVCMOS18} [get_ports switch5_i]
set_property -dict {PACKAGE_PIN H17 IOSTANDARD LVCMOS18} [get_ports switch6_i]
set_property -dict {PACKAGE_PIN M15 IOSTANDARD LVCMOS18} [get_ports switch7_i]
