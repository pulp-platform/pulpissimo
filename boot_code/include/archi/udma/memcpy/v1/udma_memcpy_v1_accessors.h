
/* THIS FILE HAS BEEN GENERATED, DO NOT MODIFY IT.
 */

/*
 * Copyright (C) 2018 ETH Zurich, University of Bologna
 * and GreenWaves Technologies
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

#ifndef __INCLUDE_ARCHI_UDMA_MEMCPY_V1_UDMA_MEMCPY_V1_ACCESSORS_H__
#define __INCLUDE_ARCHI_UDMA_MEMCPY_V1_UDMA_MEMCPY_V1_ACCESSORS_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS ACCESS FUNCTIONS
//

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

static inline uint32_t udma_memcpy_rx_saddr_get(uint32_t base) { return ARCHI_READ(base, UDMA_MEMCPY_RX_SADDR_OFFSET); }
static inline void udma_memcpy_rx_saddr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MEMCPY_RX_SADDR_OFFSET, value); }

static inline uint32_t udma_memcpy_rx_size_get(uint32_t base) { return ARCHI_READ(base, UDMA_MEMCPY_RX_SIZE_OFFSET); }
static inline void udma_memcpy_rx_size_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MEMCPY_RX_SIZE_OFFSET, value); }

static inline uint32_t udma_memcpy_rx_cfg_get(uint32_t base) { return ARCHI_READ(base, UDMA_MEMCPY_RX_CFG_OFFSET); }
static inline void udma_memcpy_rx_cfg_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MEMCPY_RX_CFG_OFFSET, value); }

static inline uint32_t udma_memcpy_tx_saddr_get(uint32_t base) { return ARCHI_READ(base, UDMA_MEMCPY_TX_SADDR_OFFSET); }
static inline void udma_memcpy_tx_saddr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MEMCPY_TX_SADDR_OFFSET, value); }

static inline uint32_t udma_memcpy_tx_size_get(uint32_t base) { return ARCHI_READ(base, UDMA_MEMCPY_TX_SIZE_OFFSET); }
static inline void udma_memcpy_tx_size_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MEMCPY_TX_SIZE_OFFSET, value); }

static inline uint32_t udma_memcpy_tx_cfg_get(uint32_t base) { return ARCHI_READ(base, UDMA_MEMCPY_TX_CFG_OFFSET); }
static inline void udma_memcpy_tx_cfg_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MEMCPY_TX_CFG_OFFSET, value); }

static inline uint32_t udma_memcpy_dst_addr_get(uint32_t base) { return ARCHI_READ(base, UDMA_MEMCPY_DST_ADDR_OFFSET); }
static inline void udma_memcpy_dst_addr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MEMCPY_DST_ADDR_OFFSET, value); }

static inline uint32_t udma_memcpy_src_addr_get(uint32_t base) { return ARCHI_READ(base, UDMA_MEMCPY_SRC_ADDR_OFFSET); }
static inline void udma_memcpy_src_addr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MEMCPY_SRC_ADDR_OFFSET, value); }

static inline uint32_t udma_memcpy_mem_sel_get(uint32_t base) { return ARCHI_READ(base, UDMA_MEMCPY_MEM_SEL_OFFSET); }
static inline void udma_memcpy_mem_sel_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MEMCPY_MEM_SEL_OFFSET, value); }

#endif

#endif
