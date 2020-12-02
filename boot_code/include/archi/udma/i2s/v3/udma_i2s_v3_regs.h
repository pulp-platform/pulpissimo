
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

#ifndef __INCLUDE_ARCHI_UDMA_I2S_V3_UDMA_I2S_V3_REGS_H__
#define __INCLUDE_ARCHI_UDMA_I2S_V3_UDMA_I2S_V3_REGS_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS
//

// RX Channel 0 I2S uDMA transfer address of associated buffer
#define UDMA_I2S_I2S_RX_SADDR_OFFSET             0x0

// RX Channel 0 I2S uDMA transfer size of buffer
#define UDMA_I2S_I2S_RX_SIZE_OFFSET              0x4

// RX Channel 0 I2S uDMA transfer configuration
#define UDMA_I2S_I2S_RX_CFG_OFFSET               0x8

// -
#define UDMA_I2S_I2S_RX_INITCFG_OFFSET           0xc

//  TX Channel I2S uDMA transfer address of associated buffer
#define UDMA_I2S_I2S_TX_SADDR_OFFSET             0x10

//  TX Channel I2S uDMA transfer size of buffer
#define UDMA_I2S_I2S_TX_SIZE_OFFSET              0x14

//  TX Channel I2S uDMA transfer configuration
#define UDMA_I2S_I2S_TX_CFG_OFFSET               0x18

// -
#define UDMA_I2S_I2S_TX_INITCFG_OFFSET           0x1c

// Clock configuration for both master, slave and pdm
#define UDMA_I2S_I2S_CLKCFG_SETUP_OFFSET         0x20

// Configuration of I2S slave
#define UDMA_I2S_I2S_SLV_SETUP_OFFSET            0x24

// Configuration of I2S master
#define UDMA_I2S_I2S_MST_SETUP_OFFSET            0x28

// Configuration of PDM module
#define UDMA_I2S_I2S_PDM_SETUP_OFFSET            0x2c

#endif
