export BOARD=zedboard
export XILINX_PART=xc7z020clg484-1
export XILINX_BOARD=em.avnet.com:zed:part0:1.4
export FC_CLK_PERIOD_NS=62.5
export PER_CLK_PERIOD_NS=100
export SLOW_CLK_PERIOD_NS=30517
#Must also change the localparam 'L2_BANK_SIZE' in pulp_soc.sv accordingly
export INTERLEAVED_BANK_SIZE=28672
#Must also change the localparam 'L2_BANK_SIZE_PRI' in pulp_soc.sv accordingly
export PRIVATE_BANK_SIZE=8192
$(info Setting environment variables for $(BOARD) board)
