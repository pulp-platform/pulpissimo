set project pulpissimo
new_project ${project}
current_methodology $env(SPYGLASS_HOME)/GuideWare/latest/block/rtl_handoff

#Read Files
read_file -type sourcelist sources.f

#Read waiver files
read_file -type awl ../waiver.awl

set_option enableSV09 yes
set_option language_mode mixed
set_option allow_module_override yes
set_option designread_enable_synthesis yes
set_option designread_disable_flatten no
set_option ignoredu axi_xbar_intf
set_option top pulpissimo

# Disable HWPE Mac Engine Usage
set_option param {pulpissimo.USE_HWPE=0}

# Link Design
compile_design

# Set lint_rtl goal and run
current_goal lint/lint_rtl
run_goal

save_project

# Create reports
exec mkdir -p reports
write_report -reportdir reports project_summary
write_report -reportdir reports moresimple > reports/moresimple.rpt
save_project
exit -force



