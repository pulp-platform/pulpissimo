export PULP_CURRENT_CONFIG=pulpissimo@config_file=chips/pulpissimo/pulpissimo.json
echo "Note: Hardcoded RISCV TOOLCHAIN PATH (working within IIS network)"
export PULP_RISCV_GCC_TOOLCHAIN=/usr/scratch/larain5/haugoug/public/pulp_riscv_gcc_renzo.2
source sdk-setup.sh
source configs/rtl.sh 
