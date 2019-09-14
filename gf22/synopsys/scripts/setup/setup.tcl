set NUM_CORES 1

set CLOCK_SLOW_RISCV      2000
set CLOCK_SLOW_ZERO_RISCY 2000

set CLOCK_FAST_RISCV 2100
set CLOCK_FAST_ZERO_RISCY 1200


set USE_CORNER     "NOMINAL"    ;# "SLOW | NOMINAL"
set USE_CORE       "RISCV"      ;# "RISCV | ZERO-RISCY"
set CORE_LATCH_RF  "TRUE"       ;# "TRUE | FALSE"
set UNGROUP_CORE   "FALSE"      ;# "TRUE | FALSE"
set RISCV_FPU      "FALSE"      ;
set MICRO_RISCY    "FALSE"      ;
set USE_ORIGINAL   "FALSE"      ; # use the original PULP RISC core.


      set RISCY RISCY

if { $USE_CORE == "ZERO-RISCY" } {

   if { $USE_CORNER == "SLOW"} {
      set CLOCK_SPEED $CLOCK_SLOW_ZERO_RISCY
   } else {
      set CLOCK_SPEED $CLOCK_FAST_ZERO_RISCY
   }

   if { $MICRO_RISCY == "TRUE"} {
      set DESIGN_NAME imperio_MICRO_${CLOCK_SPEED}
   } else {
      set DESIGN_NAME imperio_ZERO_${CLOCK_SPEED}
   }

} else {

   if { $USE_CORNER == "SLOW"} {
      set CLOCK_SPEED $CLOCK_SLOW_RISCV
   } else {
      set CLOCK_SPEED $CLOCK_FAST_RISCV
   }


   if { $RISCV_FPU == "TRUE"} {
      set DESIGN_NAME FP${RISCY}_${CLOCK_SPEED}
   } else {
      set DESIGN_NAME ${RISCY}_${CLOCK_SPEED}
   }

}
echo "DESIGN_NAME=$DESIGN_NAME"
set ASIC_PATH  ../../rtl
set RTL_PATH   ../../rtl
set IPS_PATH   ../../ips

set search_path [ join "$IPS_PATH/axi/wb2axi
                        $IPS_PATH/axi/per2axi
                        $IPS_PATH/axi/axi2per
                        $IPS_PATH/axi/axi2mem
                        $IPS_PATH/axi/axi_node
                        $IPS_PATH/apb/apb_i2c
                        $IPS_PATH/apb/apb_event_unit/include
                        $RTL_PATH/includes
                        $search_path"
                ]



if { $USE_ORIGINAL == "TRUE"} {
   set RISCV_PATH                  $IPS_PATH/riscv_orig/rtl
   set DESIGN_NAME                 "riscv_${DESIGN_NAME}"
} else {
   set RISCV_PATH                  $IPS_PATH/riscv/rtl
   set DESIGN_NAME                 "rnnext_${DESIGN_NAME}"
}

set ZERO_RISCY_PATH             $IPS_PATH/zero-riscy/rtl
set FPU_PATH                    $IPS_PATH/fpu/hdl
set AXI_PATH                    $IPS_PATH/axi
set SCM_PATH                    $IPS_PATH/scm
set APB_PATH                    $IPS_PATH/apb
set PULPINO_PATH                $RTL_PATH
set ADV_DEBUG_IF_PATH           $IPS_PATH/adv_dbg_if/rtl

# supress port can become inout port (for interfaces crossing hierarchy)
suppress_message {VER-735}

# suppress 'assert property not supported'
suppress_message {VER-708}
