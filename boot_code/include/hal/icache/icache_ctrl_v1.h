/*
 * Copyright (C) 2018 ETH Zurich and University of Bologna
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __HAL_ICACHE_ICACHE_CTRL_V1_H__
#define __HAL_ICACHE_ICACHE_CTRL_V1_H__

#include "archi/pulp.h"

// Flush the L0 buffers, each bit of conf identifies a L0 Buffer Block
static inline void flush_L0_buffers(int conf){
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x0CU) = conf;
    return;
}

// Enable All Icache Banks api 
static inline void enable_all_icache_banks(void){
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR) = 0xFFFFFFFF;
    return;
}

static inline void hal_icache_cluster_enable(int cid)
{
  pulp_write32(ARCHI_CLUSTER_PERIPHERALS_GLOBAL_ADDR(cid) + ARCHI_ICACHE_CTRL_OFFSET, 0xFFFFFFFF);
}

static inline void icache_enable(unsigned int base)
{
  pulp_write32(base, 0xFFFFFFFF);
}

// Disable all icache banks routine
static inline void disable_all_icache_banks(void){
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR) = 0x00000000;
    return;
}

// Reset the statistic counters in each icache banks
static inline void reset_all_icache_stat_regs(void){
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x10U) = 0xFFFFFFFF;
    return;
}

// Enable all the statistic counters in all icache banks available
static inline void start_all_icache_stat_regs(void){
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x14U) = 0xFFFFFFFF;
    return;
}

// Disable all the statistic counters in all icache banks available
static inline void stop_all_icache_stat_regs(void){
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x14U) = 0x00000000;
    return;
}

// Read Hit counter reg in a specified icache bank
static inline unsigned int read_hit_icache_reg(unsigned int bank){
    volatile unsigned int reg_status;
    reg_status = *(volatile unsigned int *) (ARCHI_ICACHE_CTRL_ADDR+0x18U+bank*0x04U);
    return reg_status;
}

// Read Total transaction counter reg in a specified icache bank
static inline unsigned int read_trans_icache_reg(unsigned int bank){
    volatile unsigned int reg_status;
    reg_status = *(volatile unsigned int *) (ARCHI_ICACHE_CTRL_ADDR+0x28U+bank*0x04U);
    return reg_status;
}

// Read Total transaction counter reg in a specified icache bank
static inline unsigned int read_stall_icache_reg(unsigned int bank){
  return 0x0U;
}

static inline void flush_all_icache_banks(void){
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x04U) = -1;// write 4'b1111 in the flush reg
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR) = 0x0;// disable the icache banks
    
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR) = -1;// enable the icache banks
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x04U) = 0x0;// write 4'b000 in the flush reg
    return;
}

static inline int read_enable_icache_reg(void){
    volatile int reg_status;
    reg_status = *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR);
    return reg_status;
}

static inline int read_status_icache_reg(void){
    volatile int reg_status;
    reg_status = *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x08U);
    return reg_status;
}

static inline void flush_some_icache_banks(int conf){
    volatile int current_conf = *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x08U);
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR) = conf ^ current_conf;
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR) = current_conf;
    return;
}

static inline void set_icache_banks_conf(int conf){
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR) = conf;
    return; 
}

static inline void set_icache_private(void){
    
    //Disable all icache banks
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x04U) = -1;// write 4'b1111 in the flush reg
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR) = 0x0;// disable the icache banks
    
    //Drive the icache_is_private signal
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0xF0U) = 0x1;
    
    //Enable all icache banks
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR) = -1;// enable the icache banks
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x04U) = 0x0;// write 4'b000 in the flush reg
    return;
}

static inline void set_icache_shared(void){
    
    //Disable all icache banks
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x04U) = -1;// write 4'b1111 in the flush reg
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR) = 0x0;// disable the icache banks
    
    //Drive the icache_is_private signal
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0xF0U) = 0x0;
    
    //Enable all icache banks
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR) = -1;// enable the icache banks
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x04U)    = 0x0; // write 4'b000 in the flush reg
    return;
}

static inline int read_icache_pri_sh_reg(void){
    volatile int reg_status;
    reg_status = *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0xF0U);
    return reg_status;
}

#endif
