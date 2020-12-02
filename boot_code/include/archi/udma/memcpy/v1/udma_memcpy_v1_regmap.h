
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

#ifndef __INCLUDE_ARCHI_UDMA_MEMCPY_V1_UDMA_MEMCPY_V1_REGMAP_H__
#define __INCLUDE_ARCHI_UDMA_MEMCPY_V1_UDMA_MEMCPY_V1_REGMAP_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS GLOBAL STRUCT
//

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

typedef struct {
  unsigned int rx_saddr        ; // uDMA RX MEMCPY buffer base address configuration register.
  unsigned int rx_size         ; // uDMA RX MEMCPY buffer size configuration register.
  unsigned int rx_cfg          ; // uDMA RX MEMCPY stream configuration register.
  unsigned int tx_saddr        ; // uDMA TX MEMCPY buffer base address configuration register.
  unsigned int tx_size         ; // uDMA TX MEMCPY buffer size configuration register.
  unsigned int tx_cfg          ; // uDMA TX MEMCPY stream configuration register.
  unsigned int dst_addr        ; // MEMCPY TX destination address configuration register.
  unsigned int src_addr        ; // MEMCPY RX source address configuration register.
  unsigned int mem_sel         ; // MEMCPY memory source/destination select configuration register.
} __attribute__((packed)) udma_memcpy_udma_memcpy_t;

#endif

#endif
