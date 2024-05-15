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


#Create constraint for the clock input of the zcu104 board
create_clock -period 8.000 -name ref_clk [get_ports ref_clk_p]
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
set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets pad_reset_IBUF_inst/O]

set_property CLOCK_DEDICATED_ROUTE ANY_CMT_COLUMN [get_nets i_pulpissimo/i_clock_gen/i_slow_clk_div/i_clk_mux/clk_o]
set_property CLOCK_DEDICATED_ROUTE ANY_CMT_COLUMN [get_nets i_pulpissimo/i_clock_gen/i_slow_clk_mngr/inst/clk_out1]

set_property CLOCK_DEDICATED_ROUTE ANY_CMT_COLUMN [get_nets i_pulpissimo/i_clock_gen/i_clk_manager/inst/clk_out1]
set_property CLOCK_DEDICATED_ROUTE ANY_CMT_COLUMN [get_nets i_pulpissimo/i_clock_gen/i_clk_manager/inst/clk_out2]
set_property CLOCK_DEDICATED_ROUTE TRUE [get_nets i_pulpissimo/i_clock_gen/soc_clk_o]
set_property CLOCK_DEDICATED_ROUTE TRUE [get_nets i_pulpissimo/i_clock_gen/per_clk_o]

# Set ASYNC_REG attribute for ff synchronizers to place them closer together and
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

# Create asynchronous clock group between JTAG TCK and per clock.
set_clock_groups -asynchronous -group [get_clocks -of_objects [get_pins i_pulpissimo/pad_jtag_tck]] \
                               -group [get_clocks -of_objects [get_pins i_pulpissimo/i_clock_gen/i_clk_manager/clk_out2]]

# Create asynchronous clock group between slow clock and JTAG TCK.
set_clock_groups -asynchronous -group [get_clocks -of_objects [get_pins i_pulpissimo/i_clock_gen/slow_clk_o]] \
                               -group [get_clocks -of_objects [get_pins i_pulpissimo/pad_jtag_tck]]

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
set_property -dict {PACKAGE_PIN E23 IOSTANDARD LVDS} [get_ports ref_clk_n]
set_property -dict {PACKAGE_PIN F23 IOSTANDARD LVDS} [get_ports ref_clk_p]

## Reset
set_property -dict {PACKAGE_PIN M11 IOSTANDARD LVCMOS33} [get_ports pad_reset]

## Buttons
set_property -dict {PACKAGE_PIN B4 IOSTANDARD LVCMOS33} [get_ports btn0_i]
set_property -dict {PACKAGE_PIN C4 IOSTANDARD LVCMOS33} [get_ports btn1_i]
set_property -dict {PACKAGE_PIN B3 IOSTANDARD LVCMOS33} [get_ports btn2_i]
set_property -dict {PACKAGE_PIN C3 IOSTANDARD LVCMOS33} [get_ports btn3_i]

## PMOD 0
set_property -dict {PACKAGE_PIN G8 IOSTANDARD LVCMOS33} [get_ports pad_jtag_tms]
set_property -dict {PACKAGE_PIN H8 IOSTANDARD LVCMOS33} [get_ports pad_jtag_tdi]
set_property -dict {PACKAGE_PIN G7 IOSTANDARD LVCMOS33} [get_ports pad_jtag_tdo]
set_property -dict {PACKAGE_PIN H7 IOSTANDARD LVCMOS33} [get_ports pad_jtag_tck]
set_property -dict {PACKAGE_PIN G6 IOSTANDARD LVCMOS33} [get_ports pad_pmod0_4]
set_property -dict {PACKAGE_PIN H6 IOSTANDARD LVCMOS33} [get_ports pad_pmod0_5]
set_property -dict {PACKAGE_PIN J6 IOSTANDARD LVCMOS33} [get_ports pad_pmod0_6]
set_property -dict {PACKAGE_PIN J7 IOSTANDARD LVCMOS33} [get_ports pad_pmod0_7]

## PMOD 1
set_property -dict {PACKAGE_PIN J9  IOSTANDARD LVCMOS33} [get_ports pad_pmod1_0]
set_property -dict {PACKAGE_PIN K9  IOSTANDARD LVCMOS33} [get_ports pad_pmod1_1]
set_property -dict {PACKAGE_PIN K8  IOSTANDARD LVCMOS33} [get_ports pad_pmod1_2]
set_property -dict {PACKAGE_PIN L8  IOSTANDARD LVCMOS33} [get_ports pad_pmod1_3]
set_property -dict {PACKAGE_PIN L10 IOSTANDARD LVCMOS33} [get_ports pad_pmod1_4]
set_property -dict {PACKAGE_PIN M10 IOSTANDARD LVCMOS33} [get_ports pad_pmod1_5]
set_property -dict {PACKAGE_PIN M8  IOSTANDARD LVCMOS33} [get_ports pad_pmod1_6]
set_property -dict {PACKAGE_PIN M9  IOSTANDARD LVCMOS33} [get_ports pad_pmod1_7]

## UART
set_property -dict {PACKAGE_PIN A20 IOSTANDARD LVCMOS18} [get_ports pad_uart_rx]
set_property -dict {PACKAGE_PIN C19 IOSTANDARD LVCMOS18} [get_ports pad_uart_tx]
set_property -dict {PACKAGE_PIN C18 IOSTANDARD LVCMOS18} [get_ports pad_uart_rts]
set_property -dict {PACKAGE_PIN A19 IOSTANDARD LVCMOS18} [get_ports pad_uart_cts]

## LEDs
set_property -dict {PACKAGE_PIN D5 IOSTANDARD LVCMOS33} [get_ports led0_o]
set_property -dict {PACKAGE_PIN D6 IOSTANDARD LVCMOS33} [get_ports led1_o]
set_property -dict {PACKAGE_PIN A5 IOSTANDARD LVCMOS33} [get_ports led2_o]
set_property -dict {PACKAGE_PIN B5 IOSTANDARD LVCMOS33} [get_ports led3_o]

## Switches
set_property -dict {PACKAGE_PIN E4 IOSTANDARD LVCMOS33} [get_ports switch0_i]
set_property -dict {PACKAGE_PIN D4 IOSTANDARD LVCMOS33} [get_ports switch1_i]
set_property -dict {PACKAGE_PIN F5 IOSTANDARD LVCMOS33} [get_ports switch2_i]
set_property -dict {PACKAGE_PIN F4 IOSTANDARD LVCMOS33} [get_ports switch3_i]

## I2C Bus
set_property -dict {PACKAGE_PIN N12 IOSTANDARD LVCMOS33} [get_ports pad_i2c0_scl]
set_property -dict {PACKAGE_PIN P12 IOSTANDARD LVCMOS33} [get_ports pad_i2c0_sda]

## HDMI CTL
set_property -dict {PACKAGE_PIN D1 IOSTANDARD LVCMOS33} [get_ports pad_hdmi_scl]
set_property -dict {PACKAGE_PIN E1 IOSTANDARD LVCMOS33} [get_ports pad_hdmi_sda]
