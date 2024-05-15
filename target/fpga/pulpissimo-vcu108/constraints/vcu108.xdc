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


#Create constraint for the clock input of the vcu108 board
create_clock -period 8.000 -name ref_clk [get_ports ref_clk_p]

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
set_property -dict {PACKAGE_PIN BC8 IOSTANDARD LVDS} [get_ports ref_clk_n]
set_property -dict {PACKAGE_PIN BC9 IOSTANDARD LVDS} [get_ports ref_clk_p]

## Reset
set_property -dict {PACKAGE_PIN E36 IOSTANDARD LVCMOS12 DRIVE 8} [get_ports pad_reset]

## Buttons - GPIO_SW North, West, South, East
set_property -dict {PACKAGE_PIN E34 IOSTANDARD LVCMOS12 DRIVE 8} [get_ports btn0_i]
set_property -dict {PACKAGE_PIN M22 IOSTANDARD LVCMOS12 DRIVE 8} [get_ports btn1_i]
set_property -dict {PACKAGE_PIN D9  IOSTANDARD LVCMOS12 DRIVE 8} [get_ports btn2_i]
set_property -dict {PACKAGE_PIN A10 IOSTANDARD LVCMOS12 DRIVE 8} [get_ports btn3_i]

## PMOD 0
set_property -dict {PACKAGE_PIN BC14 IOSTANDARD LVCMOS18} [get_ports pad_jtag_tms]
set_property -dict {PACKAGE_PIN BA10 IOSTANDARD LVCMOS18} [get_ports pad_jtag_tdi]
set_property -dict {PACKAGE_PIN AW16 IOSTANDARD LVCMOS18} [get_ports pad_jtag_tdo]
set_property -dict {PACKAGE_PIN BB16 IOSTANDARD LVCMOS18} [get_ports pad_jtag_tck]
set_property -dict {PACKAGE_PIN BC13 IOSTANDARD LVCMOS18} [get_ports pad_pmod0_4]
set_property -dict {PACKAGE_PIN BF7  IOSTANDARD LVCMOS18} [get_ports pad_pmod0_5]
set_property -dict {PACKAGE_PIN AW12 IOSTANDARD LVCMOS18} [get_ports pad_pmod0_6]
set_property -dict {PACKAGE_PIN BC16 IOSTANDARD LVCMOS18} [get_ports pad_pmod0_7]

## PMOD 1
set_property -dict {PACKAGE_PIN P22 IOSTANDARD LVCMOS12 DRIVE 8} [get_ports pad_pmod1_0]
set_property -dict {PACKAGE_PIN N22 IOSTANDARD LVCMOS12 DRIVE 8} [get_ports pad_pmod1_1]
set_property -dict {PACKAGE_PIN J20 IOSTANDARD LVCMOS12 DRIVE 8} [get_ports pad_pmod1_2]
set_property -dict {PACKAGE_PIN K24 IOSTANDARD LVCMOS12 DRIVE 8} [get_ports pad_pmod1_3]
set_property -dict {PACKAGE_PIN J24 IOSTANDARD LVCMOS12 DRIVE 8} [get_ports pad_pmod1_4]
set_property -dict {PACKAGE_PIN T23 IOSTANDARD LVCMOS12 DRIVE 8} [get_ports pad_pmod1_5]
set_property -dict {PACKAGE_PIN R23 IOSTANDARD LVCMOS12 DRIVE 8} [get_ports pad_pmod1_6]
set_property -dict {PACKAGE_PIN R22 IOSTANDARD LVCMOS12 DRIVE 8} [get_ports pad_pmod1_7]

## UART
set_property -dict {PACKAGE_PIN BE24 IOSTANDARD LVCMOS18} [get_ports pad_uart_rx]
set_property -dict {PACKAGE_PIN BC24 IOSTANDARD LVCMOS18} [get_ports pad_uart_tx]
set_property -dict {PACKAGE_PIN BD22 IOSTANDARD LVCMOS18} [get_ports pad_uart_rts]
set_property -dict {PACKAGE_PIN BF24 IOSTANDARD LVCMOS18} [get_ports pad_uart_cts]

## LEDs
set_property -dict {PACKAGE_PIN AT32 IOSTANDARD LVCMOS12 DRIVE 8} [get_ports led0_o]
set_property -dict {PACKAGE_PIN AV34 IOSTANDARD LVCMOS12 DRIVE 8} [get_ports led1_o]
set_property -dict {PACKAGE_PIN AY30 IOSTANDARD LVCMOS12 DRIVE 8} [get_ports led2_o]
set_property -dict {PACKAGE_PIN BB32 IOSTANDARD LVCMOS12 DRIVE 8} [get_ports led3_o]

## Switches
set_property -dict {PACKAGE_PIN BC40 IOSTANDARD LVCMOS12 DRIVE 8} [get_ports switch0_i]
set_property -dict {PACKAGE_PIN L19  IOSTANDARD LVCMOS12 DRIVE 8} [get_ports switch1_i]
set_property -dict {PACKAGE_PIN C37  IOSTANDARD LVCMOS12 DRIVE 8} [get_ports switch2_i]
set_property -dict {PACKAGE_PIN C38  IOSTANDARD LVCMOS12 DRIVE 8} [get_ports switch3_i]

## I2C Bus - SYSMON (vcu108) vs. PL_I2C1 (zcu104)
set_property -dict {PACKAGE_PIN AP18 IOSTANDARD LVCMOS18} [get_ports pad_i2c0_scl]
set_property -dict {PACKAGE_PIN AP17 IOSTANDARD LVCMOS18} [get_ports pad_i2c0_sda]

## HDMI CTL - Unable to determine correct pins in comparison to zcu104. How can I disable this feature completely?
set_property -dict {PACKAGE_PIN AN21 IOSTANDARD LVCMOS18} [get_ports pad_hdmi_scl]
set_property -dict {PACKAGE_PIN AP21 IOSTANDARD LVCMOS18} [get_ports pad_hdmi_sda]
