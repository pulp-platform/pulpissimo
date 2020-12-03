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

#ifndef __HAL_ICACHE_ICACHE_CTRL_V2_H__
#define __HAL_ICACHE_ICACHE_CTRL_V2_H__

#include "hal/pulp.h"

static inline unsigned int plp_icache_cluster_remote_base(int cid) { return ARCHI_CLUSTER_PERIPHERALS_GLOBAL_ADDR(cid) + ARCHI_ICACHE_CTRL_OFFSET; }

static inline unsigned int plp_icache_cluster_base(int cid) { return ARCHI_ICACHE_CTRL_ADDR; }

static inline unsigned int plp_icache_fc_base() { return ARCHI_ICACHE_CTRL_ADDR; }

// Enable All Icache Banks api 
static inline void enable_all_icache_banks ( )
{
  *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR) = 0xFFFFFFFF;
}

static inline void hal_icache_cluster_enable(int cid)
{
  pulp_write32(ARCHI_CLUSTER_PERIPHERALS_GLOBAL_ADDR(cid) + ARCHI_ICACHE_CTRL_OFFSET, 0xFFFFFFFF);
}

static inline void icache_enable(unsigned int base)
{
  pulp_write32(base, 0xFFFFFFFF);
}

static inline void icache_disable(unsigned int base)
{
  pulp_write32(base, 0);
}

// Disable all icache banks routine
static inline void disable_all_icache_banks ( )
{
  *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR) = 0x00000000;
}



// Reset the statistic counters in each icache banks
static inline void reset_all_icache_stat_regs()
{
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x10) = 0xFFFFFFFF;
}


// Enable all the statisctic counters in all icache banks availabe
static inline void start_all_icache_stat_regs()
{
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x14) = 0xFFFFFFFF;
}

// Disable all the statisctic counters in all icache banks availabe
static inline void stop_all_icache_stat_regs()
{
    *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x14) = 0x00000000;
}


static inline int read_hit_icache_reg( )
{
  volatile int reg_status;
  reg_status = *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x40);
  return reg_status;
}


static inline int read_trans_icache_reg( )
{
  volatile int reg_status;
  //FIXME we need to know how many banks are used
  reg_status = *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR +0x44);
  return reg_status;
}



static inline void flush_all_icache_banks_common ( unsigned int base )
{
  *(volatile int*) (base+0x4) = 1;
}





static inline void flush_all_icache_banks ( )
{
  flush_all_icache_banks_common(ARCHI_ICACHE_CTRL_ADDR);
}

static inline void selective_flush_icache_addr (unsigned int address )
{
  *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x8) = address; // write 4'b1111 in the flush reg
}


static inline int read_enable_icache_reg(  )
{
  volatile int reg_status;
  reg_status = *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR + 0x0C); 
  return reg_status;
}






static inline int read_status_icache_reg(  )
{
  volatile int reg_status;

  reg_status = *(volatile int*) (ARCHI_ICACHE_CTRL_ADDR+0x08);

  return reg_status;
}
#endif
