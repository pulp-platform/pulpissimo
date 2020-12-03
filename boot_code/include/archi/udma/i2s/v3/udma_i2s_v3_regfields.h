
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

#ifndef __INCLUDE_ARCHI_UDMA_I2S_V3_UDMA_I2S_V3_REGFIELDS_H__
#define __INCLUDE_ARCHI_UDMA_I2S_V3_UDMA_I2S_V3_REGFIELDS_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS FIELDS
//

// Configure pointer to memory buffer: - Read: value of the pointer until transfer is over. Else returns 0 - Write: set Address Pointer to memory buffer start address (access: R/W)
#define UDMA_I2S_I2S_RX_SADDR_RX_SADDR_BIT                           0
#define UDMA_I2S_I2S_RX_SADDR_RX_SADDR_WIDTH                         16
#define UDMA_I2S_I2S_RX_SADDR_RX_SADDR_MASK                          0xffff

// Buffer size in byte. (128kBytes maximum) - Read: buffer size left - Write: set buffer size (access: R/W)
#define UDMA_I2S_I2S_RX_SIZE_RX_SIZE_BIT                             0
#define UDMA_I2S_I2S_RX_SIZE_RX_SIZE_WIDTH                           17
#define UDMA_I2S_I2S_RX_SIZE_RX_SIZE_MASK                            0x1ffff

// Channel continuous mode: -1'b0: disable -1'b1: enable At the end of the buffer the uDMA reloads the address and size and starts a new transfer. (access: R/W)
#define UDMA_I2S_I2S_RX_CFG_CONTINOUS_BIT                            0
#define UDMA_I2S_I2S_RX_CFG_CONTINOUS_WIDTH                          1
#define UDMA_I2S_I2S_RX_CFG_CONTINOUS_MASK                           0x1

// Channel transfer size used to increment uDMA buffer address pointer: - 2'b00: +1 (8 bits) - 2'b01: +2 (16 bits) - 2'b10: +4 (32 bits) - 2'b11: +0 (access: R/W)
#define UDMA_I2S_I2S_RX_CFG_DATASIZE_BIT                             1
#define UDMA_I2S_I2S_RX_CFG_DATASIZE_WIDTH                           2
#define UDMA_I2S_I2S_RX_CFG_DATASIZE_MASK                            0x6

// Channel enable and start transfer: -1'b0: disable -1'b1: enable This signal is used also to queue a transfer if one is already ongoing. (access: R/W)
#define UDMA_I2S_I2S_RX_CFG_EN_BIT                                   4
#define UDMA_I2S_I2S_RX_CFG_EN_WIDTH                                 1
#define UDMA_I2S_I2S_RX_CFG_EN_MASK                                  0x10

// Channel clear and stop transfer: -1'b0: disable -1'b1: enable (access: W)
#define UDMA_I2S_I2S_RX_CFG_CLR_BIT                                  5
#define UDMA_I2S_I2S_RX_CFG_CLR_WIDTH                                1
#define UDMA_I2S_I2S_RX_CFG_CLR_MASK                                 0x20

// Transfer pending in queue status flag: -1'b0: free -1'b1: pending (access: R)
#define UDMA_I2S_I2S_RX_CFG_PENDING_BIT                              5
#define UDMA_I2S_I2S_RX_CFG_PENDING_WIDTH                            1
#define UDMA_I2S_I2S_RX_CFG_PENDING_MASK                             0x20

// Configure pointer to memory buffer: - Read: value of the pointer until transfer is over. Else returns 0 - Write: set Address Pointer to memory buffer start address (access: R/W)
#define UDMA_I2S_I2S_TX_SADDR_TX_SADDR_BIT                           0
#define UDMA_I2S_I2S_TX_SADDR_TX_SADDR_WIDTH                         16
#define UDMA_I2S_I2S_TX_SADDR_TX_SADDR_MASK                          0xffff

// Buffer size in byte. (128kBytes maximum) - Read: buffer size left - Write: set buffer size (access: R/W)
#define UDMA_I2S_I2S_TX_SIZE_TX_SIZE_BIT                             0
#define UDMA_I2S_I2S_TX_SIZE_TX_SIZE_WIDTH                           17
#define UDMA_I2S_I2S_TX_SIZE_TX_SIZE_MASK                            0x1ffff

// Channel continuous mode: -1'b0: disable -1'b1: enable At the end of the buffer the uDMA reloads the address and size and starts a new transfer. (access: R/W)
#define UDMA_I2S_I2S_TX_CFG_CONTINOUS_BIT                            0
#define UDMA_I2S_I2S_TX_CFG_CONTINOUS_WIDTH                          1
#define UDMA_I2S_I2S_TX_CFG_CONTINOUS_MASK                           0x1

// Channel transfer size used to increment uDMA buffer address pointer: - 2'b00: +1 (8 bits) - 2'b01: +2 (16 bits) - 2'b10: +4 (32 bits) - 2'b11: +0 (access: R/W)
#define UDMA_I2S_I2S_TX_CFG_DATASIZE_BIT                             1
#define UDMA_I2S_I2S_TX_CFG_DATASIZE_WIDTH                           2
#define UDMA_I2S_I2S_TX_CFG_DATASIZE_MASK                            0x6

// Channel enable and start transfer: -1'b0: disable -1'b1: enable This signal is used also to queue a transfer if one is already ongoing. (access: R/W)
#define UDMA_I2S_I2S_TX_CFG_EN_BIT                                   4
#define UDMA_I2S_I2S_TX_CFG_EN_WIDTH                                 1
#define UDMA_I2S_I2S_TX_CFG_EN_MASK                                  0x10

// Channel clear and stop transfer: -1'b0: disable -1'b1: enable (access: R/W)
#define UDMA_I2S_I2S_TX_CFG_CLR_BIT                                  5
#define UDMA_I2S_I2S_TX_CFG_CLR_WIDTH                                1
#define UDMA_I2S_I2S_TX_CFG_CLR_MASK                                 0x20

// Transfer pending in queue status flag: -1'b0: free -1'b1: pending (access: R)
#define UDMA_I2S_I2S_TX_CFG_PENDING_BIT                              5
#define UDMA_I2S_I2S_TX_CFG_PENDING_WIDTH                            1
#define UDMA_I2S_I2S_TX_CFG_PENDING_MASK                             0x20

// LSB of master clock divider (access: R/W)
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_DIV_BIT                 0
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_DIV_WIDTH               8
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_DIV_MASK                0xff

// LSB of slave clock divider (access: R/W)
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_DIV_BIT                  8
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_DIV_WIDTH                8
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_DIV_MASK                 0xff00

// MSBs of both master and slave clock divider (access: R/W)
#define UDMA_I2S_I2S_CLKCFG_SETUP_COMMON_CLK_DIV_BIT                 16
#define UDMA_I2S_I2S_CLKCFG_SETUP_COMMON_CLK_DIV_WIDTH               8
#define UDMA_I2S_I2S_CLKCFG_SETUP_COMMON_CLK_DIV_MASK                0xff0000

// Enables Slave clock (access: R/W)
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_EN_BIT                   24
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_EN_WIDTH                 1
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_EN_MASK                  0x1000000

// Enables Master clock (access: R/W)
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_EN_BIT                  25
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_EN_WIDTH                1
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_EN_MASK                 0x2000000

// When enabled slave output clock is taken from PDM module (access: R/W)
#define UDMA_I2S_I2S_CLKCFG_SETUP_PDM_CLK_EN_BIT                     26
#define UDMA_I2S_I2S_CLKCFG_SETUP_PDM_CLK_EN_WIDTH                   1
#define UDMA_I2S_I2S_CLKCFG_SETUP_PDM_CLK_EN_MASK                    0x4000000

// When set uses external clock for slave (access: R/W)
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_EXT_BIT                      28
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_EXT_WIDTH                    1
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_EXT_MASK                     0x10000000

// Selects slave clock source(either ext or generated): -1b0:selects master -1b1:selects slave (access: R/W)
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_NUM_BIT                      29
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_NUM_WIDTH                    1
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_NUM_MASK                     0x20000000

// When set uses external clock for master (access: R/W)
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_EXT_BIT                     30
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_EXT_WIDTH                   1
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_EXT_MASK                    0x40000000

// Selects master clock source(either ext or generated): -1b0:selects master -1b1:selects slave (access: R/W)
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_NUM_BIT                     31
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_NUM_WIDTH                   1
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_NUM_MASK                    0x80000000

// Sets how many words for each I2S phase (access: R/W)
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_WORDS_BIT                       0
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_WORDS_WIDTH                     3
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_WORDS_MASK                      0x7

// Sets how many bits per word (access: R/W)
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_BITS_BIT                        8
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_BITS_WIDTH                      5
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_BITS_MASK                       0x1f00

// Enables LSB shifting (access: R/W)
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_LSB_BIT                         16
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_LSB_WIDTH                       1
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_LSB_MASK                        0x10000

// Enables both channels (access: R/W)
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_2CH_BIT                         17
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_2CH_WIDTH                       1
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_2CH_MASK                        0x20000

// Enables the Slave (access: R/W)
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_EN_BIT                          31
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_EN_WIDTH                        1
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_EN_MASK                         0x80000000

// Sets how many words for each I2S phase (access: R/W)
#define UDMA_I2S_I2S_MST_SETUP_MASTER_WORDS_BIT                      0
#define UDMA_I2S_I2S_MST_SETUP_MASTER_WORDS_WIDTH                    3
#define UDMA_I2S_I2S_MST_SETUP_MASTER_WORDS_MASK                     0x7

// Sets how many bits per word (access: R/W)
#define UDMA_I2S_I2S_MST_SETUP_MASTER_BITS_BIT                       8
#define UDMA_I2S_I2S_MST_SETUP_MASTER_BITS_WIDTH                     5
#define UDMA_I2S_I2S_MST_SETUP_MASTER_BITS_MASK                      0x1f00

// Enables LSB shifting (access: R/W)
#define UDMA_I2S_I2S_MST_SETUP_MASTER_LSB_BIT                        16
#define UDMA_I2S_I2S_MST_SETUP_MASTER_LSB_WIDTH                      1
#define UDMA_I2S_I2S_MST_SETUP_MASTER_LSB_MASK                       0x10000

// Enables both channels (access: R/W)
#define UDMA_I2S_I2S_MST_SETUP_MASTER_2CH_BIT                        17
#define UDMA_I2S_I2S_MST_SETUP_MASTER_2CH_WIDTH                      1
#define UDMA_I2S_I2S_MST_SETUP_MASTER_2CH_MASK                       0x20000

// Enables the Master (access: R/W)
#define UDMA_I2S_I2S_MST_SETUP_MASTER_EN_BIT                         31
#define UDMA_I2S_I2S_MST_SETUP_MASTER_EN_WIDTH                       1
#define UDMA_I2S_I2S_MST_SETUP_MASTER_EN_MASK                        0x80000000

// Shifts the output of the filter (access: R/W)
#define UDMA_I2S_I2S_PDM_SETUP_PDM_SHIFT_BIT                         0
#define UDMA_I2S_I2S_PDM_SETUP_PDM_SHIFT_WIDTH                       3
#define UDMA_I2S_I2S_PDM_SETUP_PDM_SHIFT_MASK                        0x7

// Sets the decimation ratio of the filter (access: R/W)
#define UDMA_I2S_I2S_PDM_SETUP_PDM_DECIMATION_BIT                    3
#define UDMA_I2S_I2S_PDM_SETUP_PDM_DECIMATION_WIDTH                  10
#define UDMA_I2S_I2S_PDM_SETUP_PDM_DECIMATION_MASK                   0x1ff8

// nan (access: R/W)
#define UDMA_I2S_I2S_PDM_SETUP_PDM_MODE_BIT                          13
#define UDMA_I2S_I2S_PDM_SETUP_PDM_MODE_WIDTH                        2
#define UDMA_I2S_I2S_PDM_SETUP_PDM_MODE_MASK                         0x6000

// nan (access: R/W)
#define UDMA_I2S_I2S_PDM_SETUP_PDM_EN_BIT                            31
#define UDMA_I2S_I2S_PDM_SETUP_PDM_EN_WIDTH                          1
#define UDMA_I2S_I2S_PDM_SETUP_PDM_EN_MASK                           0x80000000

#endif
