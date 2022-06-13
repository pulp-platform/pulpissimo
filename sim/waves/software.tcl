# add all cores execution trace
set core [find instances -recursive -bydu cv32e40p_wrapper -nodu]
set fpuprivate [find instances -recursive -bydu fpu_private]

if {$core ne ""} {
    add wave -group "Software Debugging" -divider "CORE: ${core}"
    add wave -group "Software Debugging" $core/core_i/clk_i
    add wave -group "Software Debugging" -divider "Instructions at ID stage, sampled half a cycle later"
    add wave -group "Software Debugging" $core/tracer_i/insn_disas
    add wave -group "Software Debugging" $core/tracer_i/insn_pc
    add wave -group "Software Debugging" $core/tracer_i/insn_val
    add wave -group "Software Debugging" -divider "Program counter at ID and IF stage"
    add wave -group "Software Debugging" $core/core_i/pc_id
    add wave -group "Software Debugging" $core/core_i/pc_if
    add wave -group "Software Debugging" -divider "Register File contents"
    add wave -group "Software Debugging" $core/core_i/id_stage_i/register_file_i/mem
    if {$fpuprivate ne ""} {
        add wave -group "Software Debugging" $core/core_i/id_stage_i/register_file_i/mem_fp
    }
}

configure wave -namecolwidth  250
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 1
configure wave -timelineunits ns
