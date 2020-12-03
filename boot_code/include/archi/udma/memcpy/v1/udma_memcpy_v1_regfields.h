
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

#ifndef __INCLUDE_ARCHI_UDMA_MEMCPY_V1_UDMA_MEMCPY_V1_REGFIELDS_H__
#define __INCLUDE_ARCHI_UDMA_MEMCPY_V1_UDMA_MEMCPY_V1_REGFIELDS_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS FIELDS
//

// RX buffer base address bitfield: - Read: returns value of the buffer pointer until transfer is finished. Else returns 0. - Write: sets RX buffer base address (access: R/W)
#define UDMA_MEMCPY_RX_SADDR_RX_SADDR_BIT                            0
#define UDMA_MEMCPY_RX_SADDR_RX_SADDR_WIDTH                          16
#define UDMA_MEMCPY_RX_SADDR_RX_SADDR_MASK                           0xffff

// RX buffer size bitfield in bytes. (128kBytes maximum) - Read: returns remaining buffer size to transfer. - Write: sets buffer size. (access: R/W)
#define UDMA_MEMCPY_RX_SIZE_RX_SIZE_BIT                              0
#define UDMA_MEMCPY_RX_SIZE_RX_SIZE_WIDTH                            17
#define UDMA_MEMCPY_RX_SIZE_RX_SIZE_MASK                             0x1ffff

// RX channel continuous mode bitfield: -1'b0: disabled -1'b1: enabled At the end of the buffer transfer, the uDMA reloads the address / buffer size and starts a new transfer. (access: R/W)
#define UDMA_MEMCPY_RX_CFG_CONTINOUS_BIT                             0
#define UDMA_MEMCPY_RX_CFG_CONTINOUS_WIDTH                           1
#define UDMA_MEMCPY_RX_CFG_CONTINOUS_MASK                            0x1

// RX channel enable and start transfer bitfield: -1'b0: disable -1'b1: start - enable and start the transfer This signal is used also to queue a transfer if one is already ongoing. (access: R/W)
#define UDMA_MEMCPY_RX_CFG_EN_BIT                                    4
#define UDMA_MEMCPY_RX_CFG_EN_WIDTH                                  1
#define UDMA_MEMCPY_RX_CFG_EN_MASK                                   0x10

// RX channel clear and stop transfer: -1'b0: disable -1'b1: stop and clear - stop and clear the on-going transfer (access: W)
#define UDMA_MEMCPY_RX_CFG_CLR_BIT                                   5
#define UDMA_MEMCPY_RX_CFG_CLR_WIDTH                                 1
#define UDMA_MEMCPY_RX_CFG_CLR_MASK                                  0x20

// RX transfer pending in queue status flag: -1'b0: no pending - no pending transfer in the queue -1'b1: pending - pending transfer in the queue (access: R)
#define UDMA_MEMCPY_RX_CFG_PENDING_BIT                               5
#define UDMA_MEMCPY_RX_CFG_PENDING_WIDTH                             1
#define UDMA_MEMCPY_RX_CFG_PENDING_MASK                              0x20

// TX buffer base address bitfield: - Read: returns value of the buffer pointer until transfer is finished. Else returns 0. - Write: sets buffer base address (access: R/W)
#define UDMA_MEMCPY_TX_SADDR_TX_SADDR_BIT                            0
#define UDMA_MEMCPY_TX_SADDR_TX_SADDR_WIDTH                          16
#define UDMA_MEMCPY_TX_SADDR_TX_SADDR_MASK                           0xffff

// TX buffer size bitfield in bytes. (128kBytes maximum) - Read: returns remaining buffer size to transfer. - Write: sets buffer size. (access: R/W)
#define UDMA_MEMCPY_TX_SIZE_TX_SIZE_BIT                              0
#define UDMA_MEMCPY_TX_SIZE_TX_SIZE_WIDTH                            17
#define UDMA_MEMCPY_TX_SIZE_TX_SIZE_MASK                             0x1ffff

// TX channel continuous mode bitfield: -1'b0: disabled -1'b1: enabled At the end of the buffer transfer, the uDMA reloads the address / buffer size and starts a new transfer. (access: R/W)
#define UDMA_MEMCPY_TX_CFG_CONTINOUS_BIT                             0
#define UDMA_MEMCPY_TX_CFG_CONTINOUS_WIDTH                           1
#define UDMA_MEMCPY_TX_CFG_CONTINOUS_MASK                            0x1

// TX channel enable and start transfer bitfield: -1'b0: disabled -1'b1: start - enable and start the transfer This signal is used also to queue a transfer if one is already ongoing. (access: R/W)
#define UDMA_MEMCPY_TX_CFG_EN_BIT                                    4
#define UDMA_MEMCPY_TX_CFG_EN_WIDTH                                  1
#define UDMA_MEMCPY_TX_CFG_EN_MASK                                   0x10

// TX channel clear and stop transfer bitfield: -1'b0: disabled -1'b1: stop and clear - stop and clear the on-going transfer (access: W)
#define UDMA_MEMCPY_TX_CFG_CLR_BIT                                   5
#define UDMA_MEMCPY_TX_CFG_CLR_WIDTH                                 1
#define UDMA_MEMCPY_TX_CFG_CLR_MASK                                  0x20

// TX transfer pending in queue status flag: -1'b0: no pending - no pending transfer in the queue -1'b1: pending - pending transfer in the queue (access: R)
#define UDMA_MEMCPY_TX_CFG_PENDING_BIT                               5
#define UDMA_MEMCPY_TX_CFG_PENDING_WIDTH                             1
#define UDMA_MEMCPY_TX_CFG_PENDING_MASK                              0x20

// TX destination start address configuration bitfield. MEMCPY TX transfer copy data from L2 TX_CFG.TX_SADDR address to FC_TCDM or L2 memories DST_ADDR address. (access: R/W)
#define UDMA_MEMCPY_DST_ADDR_DST_ADDR_BIT                            0
#define UDMA_MEMCPY_DST_ADDR_DST_ADDR_WIDTH                          17
#define UDMA_MEMCPY_DST_ADDR_DST_ADDR_MASK                           0x1ffff

// RX source start address configuration bitfield. MEMCPY RX transfer copy data from FC_TCDM or L2 memories SRC_ADDR address to L2 RX_CFG.RX_SADDR address. (access: R/W)
#define UDMA_MEMCPY_SRC_ADDR_SRC_ADDR_BIT                            0
#define UDMA_MEMCPY_SRC_ADDR_SRC_ADDR_WIDTH                          17
#define UDMA_MEMCPY_SRC_ADDR_SRC_ADDR_MASK                           0x1ffff

// Memory selection configuration bitfield: - 1'b0: L2 from/to FC_TCDM - 1'b1: L2 from/to L2 (access: R/W)
#define UDMA_MEMCPY_MEM_SEL_MEM_SEL_BIT                              0
#define UDMA_MEMCPY_MEM_SEL_MEM_SEL_WIDTH                            1
#define UDMA_MEMCPY_MEM_SEL_MEM_SEL_MASK                             0x1

#endif
