package require struct::set

proc quote {arg} {
    string map {"[" "\\[" "]" "\\]"} $arg
}

proc get_design_name {inst} {
    set res [find instance $inst]
    return $res
    #return string range $res [string first "(" $res] [string last ")" $res]
}

echo Usage:
echo {add_instance instance to add to wave window> <optional max_recursion_level (default 2)>}
proc add_instance {inst {max_level 2} {parent_group_args ""} {parent_clocks {}} {parent_resets {}}} {
    if {$max_level == 0} {
        echo "max recursion reached"
        return
    }
    set inst_name [lindex [split $inst /] end]
    echo "Adding $inst_name to wave window"
    set parent_group_args [append parent_group_args " " -group " " $inst_name]
    set all_signals [find signals -ports $inst/*]
    set clocks [lsort -dictionary [find signals -ports $inst/*clk*]]
    set resets [lsort -dictionary [find signals -ports $inst/*rst*]]
    set other_ports [lsort -dictionary [struct::set difference [find signals -ports $inst/*] [struct::set union $clocks $resets]]]
    set internal_signals [lsort -dictionary [find signals -internal $inst/*]]
    # If there are no internal signals just add the signals with wildcard. This
    # is a workaround for the issue, that Questasim's find command does not work
    # at all with SV interfaces. Wildcard adding to the wave window on the other
    # hand works as expected so we just do it that way.
    set all_sub_instances [find instance -nodu $inst/*]
    set sub_instances [lsort -dictionary [find instance -nodu $inst/i_*]]
    set sub_blocks [lsort -dictionary [find blocks -nodu $inst/*]]
    set interface_instances [lsort -dictionary [find instance -nodu $inst/s_*]]
    set interface_ports [lsort -dictionary [struct::set difference [find instance -nodu $inst/*] [struct::set union $sub_instances $interface_instances]]]
    if {[llength $all_signals] == 0 && [llength $all_sub_instances] == 0 && [llength $sub_blocks] == 0} {
        echo "Detected interface instance"
        catch {
            eval add wave [quote $parent_group_args] [quote $parent_clocks]
            eval add wave [quote $parent_group_args] [quote $parent_resets]
            eval add wave [quote $parent_group_args] [quote $inst/*]
            return
        }
    }

    catch {
        eval add wave [quote $parent_group_args] [quote  $clocks]
        eval add wave [quote $parent_group_args] [quote  $resets]
        eval add wave [quote $parent_group_args] [quote  $other_ports]
        # echo "interface ports: $interface_ports"
    }
    echo "sub_instances: $interface_ports"
    # echo "Interface Instances: $interface_instances"
    foreach sub_inst [concat $interface_ports " " $sub_instances " " $sub_blocks " " $interface_instances] {
        add_instance $sub_inst [expr {$max_level - 1}] $parent_group_args $clocks $resets
    }
    catch {
        eval add wave [quote $parent_group_args] [quote $internal_signals]
    }
    return
}
