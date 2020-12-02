
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

#ifndef __INCLUDE_ARCHI_UDMA_I2S_V3_UDMA_I2S_V3_REGMAP_H__
#define __INCLUDE_ARCHI_UDMA_I2S_V3_UDMA_I2S_V3_REGMAP_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS GLOBAL STRUCT
//

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

typedef struct {
  unsigned int i2s_rx_saddr    ; // RX Channel 0 I2S uDMA transfer address of associated buffer
  unsigned int i2s_rx_size     ; // RX Channel 0 I2S uDMA transfer size of buffer
  unsigned int i2s_rx_cfg      ; // RX Channel 0 I2S uDMA transfer configuration
  unsigned int i2s_rx_initcfg  ; // -
  unsigned int i2s_tx_saddr    ; //  TX Channel I2S uDMA transfer address of associated buffer
  unsigned int i2s_tx_size     ; //  TX Channel I2S uDMA transfer size of buffer
  unsigned int i2s_tx_cfg      ; //  TX Channel I2S uDMA transfer configuration
  unsigned int i2s_tx_initcfg  ; // -
  unsigned int i2s_clkcfg_setup; // Clock configuration for both master, slave and pdm
  unsigned int i2s_slv_setup   ; // Configuration of I2S slave
  unsigned int i2s_mst_setup   ; // Configuration of I2S master
  unsigned int i2s_pdm_setup   ; // Configuration of PDM module
} __attribute__((packed)) udma_i2s_udma_i2s_t;

#endif

#endif
