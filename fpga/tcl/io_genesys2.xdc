## This file is a .xdc for the Genesys2
##
##

## Clock signal
set_property -dict {PACKAGE_PIN AD11 IOSTANDARD LVDS} [get_ports clk_n]
set_property LOC AD12 [get_cells testbuf]
set_property -dict {PACKAGE_PIN AD12 IOSTANDARD LVDS} [get_ports clk_p]


##Switches
set_property -dict {PACKAGE_PIN G19 IOSTANDARD LVCMOS12} [get_ports xil_reset_n]
set_property -dict {PACKAGE_PIN G25 IOSTANDARD LVCMOS12} [get_ports xil_bootsel]


## PMOD Header JA
set_property -dict {PACKAGE_PIN U28 IOSTANDARD LVCMOS33} [get_ports xil_jtag_tck]
set_property -dict {PACKAGE_PIN U27 IOSTANDARD LVCMOS33} [get_ports xil_jtag_tdi]
set_property -dict {PACKAGE_PIN T27 IOSTANDARD LVCMOS33} [get_ports xil_jtag_tdo]
set_property -dict {PACKAGE_PIN T26 IOSTANDARD LVCMOS33} [get_ports xil_jtag_tms]
set_property -dict {PACKAGE_PIN T23 IOSTANDARD LVCMOS33} [get_ports xil_jtag_trst]
#set_property -dict { PACKAGE_PIN T22   IOSTANDARD LVCMOS33 } [get_ports { ja[5] }]; #IO_L5P_T0_D06_14 Sch=ja_p[3]
#set_property -dict { PACKAGE_PIN T21   IOSTANDARD LVCMOS33 } [get_ports { ja[6] }]; #IO_L4N_T0_D05_14 Sch=ja_n[4]
#set_property -dict { PACKAGE_PIN T20   IOSTANDARD LVCMOS33 } [get_ports { ja[7] }]; #IO_L4P_T0_D04_14 Sch=ja_p[4]



##USB-UART Interface
set_property -dict {PACKAGE_PIN Y23 IOSTANDARD LVCMOS33} [get_ports xil_uart_tx]
set_property -dict {PACKAGE_PIN Y20 IOSTANDARD LVCMOS33} [get_ports xil_uart_rx]

## IIC Bus
set_property -dict {PACKAGE_PIN AE30 IOSTANDARD LVCMOS33} [get_ports xil_i2c0_scl]
set_property -dict {PACKAGE_PIN AF30 IOSTANDARD LVCMOS33} [get_ports xil_i2c0_sda]



#led:
set_property -dict {PACKAGE_PIN T28 IOSTANDARD LVCMOS33} [get_ports xil_led0]
set_property -dict {PACKAGE_PIN V19 IOSTANDARD LVCMOS33} [get_ports xil_led1]
set_property -dict {PACKAGE_PIN U30 IOSTANDARD LVCMOS33} [get_ports xil_led2]
set_property -dict {PACKAGE_PIN U29 IOSTANDARD LVCMOS33} [get_ports xil_led3]
#reset led
set_property -dict {PACKAGE_PIN P27 IOSTANDARD LVCMOS33} [get_ports reset_led]


## clock dedicated route
set_property CLOCK_DEDICATED_ROUTE ANY_CMT_COLUMN [get_nets pulpissimo_i/soc_domain_i/pulp_soc_i/i_clk_rst_gen/i_pll_per/clk_o]
set_property CLOCK_DEDICATED_ROUTE ANY_CMT_COLUMN [get_nets pulpissimo_i/soc_domain_i/pulp_soc_i/i_clk_rst_gen/i_pll_soc/clk_o]

set_property CLOCK_DEDICATED_ROUTE ANY_CMT_COLUMN [get_nets pulpissimo_i/soc_domain_i/pulp_soc_i/i_clk_rst_gen/i_pll_per/clk_mux0123]
set_property CLOCK_DEDICATED_ROUTE ANY_CMT_COLUMN [get_nets pulpissimo_i/soc_domain_i/pulp_soc_i/i_clk_rst_gen/i_pll_soc/clk12]
set_property CLOCK_DEDICATED_ROUTE ANY_CMT_COLUMN [get_nets pulpissimo_i/soc_domain_i/pulp_soc_i/i_clk_rst_gen/i_pll_soc/clk13]
set_property CLOCK_DEDICATED_ROUTE ANY_CMT_COLUMN [get_nets pulpissimo_i/soc_domain_i/pulp_soc_i/i_clk_rst_gen/i_pll_soc/clk_mux23]

set_property CLOCK_DEDICATED_ROUTE ANY_CMT_COLUMN [get_nets pulpissimo_i/soc_domain_i/pulp_soc_i/i_clk_rst_gen/i_pll_soc/clk_mux01]
set_property CLOCK_DEDICATED_ROUTE ANY_CMT_COLUMN [get_nets pulpissimo_i/soc_domain_i/pulp_soc_i/i_clk_rst_gen/i_pll_soc/clk10]
set_property CLOCK_DEDICATED_ROUTE ANY_CMT_COLUMN [get_nets pulpissimo_i/soc_domain_i/pulp_soc_i/i_clk_rst_gen/i_pll_soc/clk11]

set_property CLOCK_DEDICATED_ROUTE ANY_CMT_COLUMN [get_nets pulpissimo_i/soc_domain_i/pulp_soc_i/i_clk_rst_gen/i_pll_per/clk_mux23]


set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets {xil_jtag_tck_IBUF}]