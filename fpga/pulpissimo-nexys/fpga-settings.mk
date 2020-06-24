define n


endef # make errors more visually appealing

export BOARD=nexys

#Nexys has different revisions. Check which one to use
ifdef rev

ifeq ($(rev), nexys4)
	export XILINX_PART=xc7a100tcsg324-1
	export XILINX_BOARD=digilentinc.com:nexys4:1.1
endif
ifeq ($(rev), nexys4DDR)
	export XILINX_PART=xc7a100tcsg324-1
	export XILINX_BOARD=digilentinc.com:nexys4_ddr:1.1
endif
ifeq ($(rev), nexysA7-50T)
	export XILINX_PART=xc7a50ticsg324-1L
	export XILINX_BOARD=digilentinc.com:nexys-a7-50t:1.0
endif
ifeq ($(rev), nexysA7-100T)
	export XILINX_PART=xc7a100tcsg324-1
	export XILINX_BOARD=digilentinc.com:nexys-a7-100t:1.0
endif
#Check if one was found
ifndef XILINX_PART
$(error $n$nCould not find board revision $(rev).$nPossible revisions: nexys4, nexys4DDR, nexysA7-50T, nexysA7-100T.$n$n)
endif

else
$(error $n$nNo Nexys board revision given. Please use 'make nexys rev=[nexys4|nexys4DDR|nexysA7-100T|nexysA7-50T]'$n$n)
endif







export FC_CLK_PERIOD_NS=100
export PER_CLK_PERIOD_NS=200
export SLOW_CLK_PERIOD_NS=30517
#Must also change the localparam 'L2_BANK_SIZE' in pulp_soc.sv accordingly
export INTERLEAVED_BANK_SIZE=28672
#Must also change the localparam 'L2_BANK_SIZE_PRI' in pulp_soc.sv accordingly
export PRIVATE_BANK_SIZE=8192
$(info Setting environment variables for $(BOARD) board)
