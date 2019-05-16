if ![info exists PULP_FPGA_SIM] {
    set RTL ../rtl
    set IPS ../ips
    set FPGA_IPS ../ips
    set FPGA_RTL ../rtl
}

puts "../fpga/tcl/rtl_src_files.tcl"
set dircorr [pwd]
puts $dircorr


# pulpissimo
set SRC_PULPISSIMO " \
    $RTL/pulpissimo/jtag_tap_top.sv \
    $RTL/pulpissimo/pad_control.sv \
    $RTL/pulpissimo/pad_frame.sv \
    $RTL/pulpissimo/safe_domain.sv \
    $RTL/pulpissimo/soc_domain.sv \
    $RTL/pulpissimo/rtc_date.sv \
    $RTL/pulpissimo/rtc_clock.sv \
    $RTL/pulpissimo/pulpissimo.sv \
"

set SRC_PULPISSIMO_FPGA " \
    $RTL/../fpga/src/pulpissimo_xilinx.sv \
    $RTL/../fpga/src/count_clk.sv \
    $RTL/../fpga/src/xilinx_pll.sv \
    $RTL/../fpga/src/pad_functional_xilinx.sv \
    $RTL/../fpga/src/xilinx_bram_mem.sv \
"

set INC_PULPISSIMO " \
    $RTL/pulpissimo/../includes \
"
