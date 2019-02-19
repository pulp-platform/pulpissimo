# add dm
set dm [find instances -recursive -bydu dm_top -nodu]

if {$dm ne ""} {
  add wave -group "DM"                                     $dm/*
}

configure wave -namecolwidth  250
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 1
configure wave -timelineunits ns
