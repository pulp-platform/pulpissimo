#!/bin/bash

# only "genesys2" supported at the moment
if [ -z "${BOARD}" ]; then
    export BOARD="genesys2"
fi

echo -n "Configuring for "
echo ${BOARD}

if [ "$BOARD" = "genesys2" ]; then
    export XILINX_PART="xc7k325tffg900-2"
  export XILINX_BOARD="digilentinc.com:genesys2:part0:1.1"
  export CLK_PERIOD_NS="20"
else
    echo -n "Illegal boardname:"
    echo ${BOARD}
fi

export VIVADO_VERSION="2017.2"
if [ "$VIVADO_VERSION" = "2017.2" ]; then
  export COMPXLIB_PATH="/usr/pack/vivado-2017.2-kgf/DZ_STUFF/compxlib/modelsim-10.6b"
elif [ "$VIVADO_VERSION" = "2016.3" ]; then
  export COMPXLIB_PATH="/usr/pack/vivado-2016.3-kgf/DZ_STUFF/compxlib/modelsim-10.5c"
elif [ "$VIVADO_VERSION" = "2016.1" ]; then
  export COMPXLIB_PATH="/usr/pack/vivado-2016.1-kgf/DZ_STUFF/compxlib/modelsim-10.4c"
else # 2015.1
  export COMPXLIB_PATH="/usr/pack/vivado-2015.1-kgf/DZ_STUFF/compxlib/modelsim-10.2c"
fi

export AXI4LITE_VIP_PATH="/scratch/$USER/$BOARD/axi4lite_vip"
