
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

#ifndef __INCLUDE_ARCHI_UDMA_MEMCPY_V1_UDMA_MEMCPY_V1_REGS_H__
#define __INCLUDE_ARCHI_UDMA_MEMCPY_V1_UDMA_MEMCPY_V1_REGS_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS
//

// uDMA RX MEMCPY buffer base address configuration register.
#define UDMA_MEMCPY_RX_SADDR_OFFSET              0x0

// uDMA RX MEMCPY buffer size configuration register.
#define UDMA_MEMCPY_RX_SIZE_OFFSET               0x4

// uDMA RX MEMCPY stream configuration register.
#define UDMA_MEMCPY_RX_CFG_OFFSET                0x8

// uDMA TX MEMCPY buffer base address configuration register.
#define UDMA_MEMCPY_TX_SADDR_OFFSET              0x10

// uDMA TX MEMCPY buffer size configuration register.
#define UDMA_MEMCPY_TX_SIZE_OFFSET               0x14

// uDMA TX MEMCPY stream configuration register.
#define UDMA_MEMCPY_TX_CFG_OFFSET                0x18

// MEMCPY TX destination address configuration register.
#define UDMA_MEMCPY_DST_ADDR_OFFSET              0x20

// MEMCPY RX source address configuration register.
#define UDMA_MEMCPY_SRC_ADDR_OFFSET              0x24

// MEMCPY memory source/destination select configuration register.
#define UDMA_MEMCPY_MEM_SEL_OFFSET               0x28

#endif
