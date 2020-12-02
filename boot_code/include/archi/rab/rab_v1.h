/*
 * Copyright (C) 2017 ETH Zurich and University of Bologna
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

#ifndef __ARCHI_RAB_V1_H__
#define __ARCHI_RAB_V1_H__

#include "archi/pulp.h"     // for ARCHI_RAB_CFG_ADDR, RAB_L1_N_SLICES_PORT_0,
                            // RAB_L1_N_SLICES_PORT_1, RAB_L2_N_ENTRIES_PER_SET, RAB_L2_N_SETS

// This struct represents the information in the L1 TLB hardware.
typedef struct {
    volatile uint32_t word[8];
} rab_cfg_t;

// L1 addresses and pointers
#define RAB_CFG_L1_ADDR     ((unsigned)(ARCHI_RAB_CFG_ADDR) + 4*8)
#define RAB_CFG_BPTR        ((rab_cfg_t*)(RAB_CFG_L1_ADDR) + (RAB_L1_N_SLICES_PORT_0))
#define RAB_CFG_EPTR        ((RAB_CFG_BPTR) + (RAB_L1_N_SLICES_PORT_1))

#define RAB_CFG_FLAG_EN         ((unsigned)(1 << 0))
#define RAB_CFG_FLAG_RDEN       ((unsigned)(1 << 1))
#define RAB_CFG_FLAG_WREN       ((unsigned)(1 << 2))
#define RAB_CFG_FLAG_COHERENT   ((unsigned)(1 << 3)) // cache-coherent with host

// These types represents the information in the L2 TLB hardware.
typedef volatile uint32_t rab_cfg_l2_varam_t;
typedef volatile uint32_t rab_cfg_l2_param_t;

// L2 addresses and pointers
#define RAB_CFG_L2_ADDR     ((unsigned)(ARCHI_RAB_CFG_ADDR) + 2*0x4000)
#define RAB_CFG_L2_VARAM_PTR(i_set, i_entry) \
    ((rab_cfg_l2_varam_t*)(RAB_CFG_L2_ADDR + i_set*RAB_L2_N_ENTRIES_PER_SET*4 + i_entry*4))
#define RAB_CFG_L2_PARAM_PTR(i_set, i_entry) \
    ((rab_cfg_l2_param_t*)(RAB_CFG_L2_ADDR + i_set*RAB_L2_N_ENTRIES_PER_SET*4 + i_entry*4 \
    + RAB_L2_N_SETS*RAB_L2_N_ENTRIES_PER_SET*4))

#define RAB_CFG_L2_SET_PFN_MASK ((unsigned)(RAB_L2_N_SETS-1))

#endif
