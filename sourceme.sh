export PULP_CURRENT_CONFIG=pulpissimo@config_file=chips/pulpissimo/pulpissimo.json
echo PULP_CURRENT_CONFIG=$PULP_CURRENT_CONFIG
export VSIM_PATH=$(pwd)/sim
echo VSIM_PATH=$VSIM_PATH
cd pulp-builder/
echo "Note: Hardcoded RISCV TOOLCHAIN PATH (working within IIS network)"
export PULP_RISCV_GCC_TOOLCHAIN=/usr/scratch/larain5/haugoug/public/pulp_riscv_gcc_renzo.2
echo PULP_RISCV_GCC_TOOLCHAIN=$PULP_RISCV_GCC_TOOLCHAIN
source sdk-setup.sh
echo "setup sdk"
source configs/rtl.sh 
echo "setup rtl"
cd ../
