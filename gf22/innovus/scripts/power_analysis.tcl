set startTime 54935198000
#57621401000
set endTime   54954410000
#57632733000
set vcdFile /scratch/andrire/RNNASIP/sourcecode/Basic_Kernels/build/pulpissimo/vcd/riscv_MODEL5_8_true.vcd.gz
set targetFrequency 380
set vcdFrequency 50.5

set scalingFactor [expr $vcdFrequency/$targetFrequency]

#in ps
set_power -reset
set_powerup_analysis -reset
set_dynamic_power_simulation -reset
#report_power -rail_analysis_format VS -outfile ./reports/power//${DESIGNNAME}_core.rpt
set_power_output_dir -reset
set_power_output_dir ./reports/power/
read_activity_file -reset
read_activity_file -scale_duration $scalingFactor -format VCD -scope /tb_pulp/i_dut/soc_domain_i/pulp_soc_i/fc_subsystem_i/FC_CORE/lFC_CORE -start $startTime -end $endTime -block {} $vcdFile
set_power -reset
set_powerup_analysis -reset
set_dynamic_power_simulation -reset

report_power -outfile ${DESIGNNAME}.rpt -sort total -hierarchy all
echo "Power simulation configuration" > tmp
echo [concat "hostname: " [exec hostname]] >> tmp
echo "Netlist" >> tmp
ls -lah out/$DESIGNNAME.v >> tmp
echo "startTime = \t $startTime" >> tmp
echo "endTime = \t $endTime" >> tmp
echo "vcdFile = " >> tmp
ls -lah $vcdFile >> tmp
echo "targetFrequency = \t $targetFrequency" >> tmp
echo "vcdFrequency = \t $vcdFrequency" >> tmp
echo "scalingFactor = \t $scalingFactor" >> tmp
exec cat ./reports/power/${DESIGNNAME}.rpt >>  tmp
mv tmp ./reports/power/${DESIGNNAME}.rpt

cat ./reports/power/${DESIGNNAME}.rpt | grep _i | grep -v "/"
cat ./reports/power/${DESIGNNAME}.rpt | grep "Total Internal Power" | tail -n1
cat ./reports/power/${DESIGNNAME}.rpt | grep "Total Switching Power" | tail -n1
cat ./reports/power/${DESIGNNAME}.rpt | grep "Total Leakage Power" | tail -n1
cat ./reports/power/${DESIGNNAME}.rpt | grep "Total Power" | tail -n1