# add fc
set rvcores [find instances -recursive -bydu cv32e40p_core -nodu]
set fpuprivate [find instances -recursive -bydu fpnew_top]
set rvpmp [find instances -recursive -bydu cv32e40p_pmp]
set clint [find instances -recursive -bydu cv32e40p_int_controller]

foreach core $rvcores {
    add wave -group "$core"                                                    $core/*
    add wave -group "$core"  -group "IF Stage" -group "Prefetch"               $core/if_stage_i/prefetch_buffer_i/*
    add wave -group "$core"  -group "IF Stage"                                 $core/if_stage_i/*
    add wave -group "$core"  -group "ID Stage"                                 $core/id_stage_i/*
    add wave -group "$core"  -group "RF"                                       $core/id_stage_i/register_file_i/mem
    add wave -group "$core"  -group "RF_FP"                                    $core/id_stage_i/register_file_i/mem_fp
    add wave -group "$core"  -group "Decoder"                                  $core/id_stage_i/decoder_i/*
    add wave -group "$core"  -group "Controller"                               $core/id_stage_i/controller_i/*
    if {$clint ne ""} {
        add wave -group "$core"  -group "Int Ctrl"                             $core/id_stage_i/int_controller_i/*
    }
    add wave -group "$core"  -group "HWLOOP Regs"                              $core/id_stage_i/gen_hwloop_regs/hwloop_regs_i/*
    add wave -group "$core"  -group "EX Stage" -group "ALU"                    $core/ex_stage_i/alu_i/*
    add wave -group "$core"  -group "EX Stage" -group "ALU_DIV"                $core/ex_stage_i/alu_i/alu_div_i/*
    add wave -group "$core"  -group "EX Stage" -group "MUL"                    $core/ex_stage_i/mult_i/*
    if {$fpuprivate ne ""} {
        add wave -group "$core"  -group "EX Stage" -group "APU_DISP"           $core/ex_stage_i/gen_apu/apu_disp_i/*
    }
    add wave -group "$core"  -group "EX Stage"                                 $core/ex_stage_i/*
    add wave -group "$core"  -group "LSU"                                      $core/load_store_unit_i/*
    if {$rvpmp ne ""} {
        add wave -group "$core"  -group "PMP"                                  $core/pmp_unit_i/*
    }
    add wave -group "$core"  -group "CSR"                                      $core/cs_registers_i/*
}

configure wave -namecolwidth  250
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 1
configure wave -timelineunits ns
