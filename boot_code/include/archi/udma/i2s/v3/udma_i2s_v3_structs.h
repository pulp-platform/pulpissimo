
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

#ifndef __INCLUDE_ARCHI_UDMA_I2S_V3_UDMA_I2S_V3_STRUCTS_H__
#define __INCLUDE_ARCHI_UDMA_I2S_V3_UDMA_I2S_V3_STRUCTS_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS STRUCTS
//

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

typedef union {
  struct {
    unsigned int rx_saddr        :16; // Configure pointer to memory buffer: - Read: value of the pointer until transfer is over. Else returns 0 - Write: set Address Pointer to memory buffer start address
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_i2s_rx_saddr_t;

typedef union {
  struct {
    unsigned int rx_size         :17; // Buffer size in byte. (128kBytes maximum) - Read: buffer size left - Write: set buffer size
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_i2s_rx_size_t;

typedef union {
  struct {
    unsigned int continous       :1 ; // Channel continuous mode: -1'b0: disable -1'b1: enable At the end of the buffer the uDMA reloads the address and size and starts a new transfer.
    unsigned int datasize        :2 ; // Channel transfer size used to increment uDMA buffer address pointer: - 2'b00: +1 (8 bits) - 2'b01: +2 (16 bits) - 2'b10: +4 (32 bits) - 2'b11: +0
    unsigned int padding0:1 ;
    unsigned int en              :1 ; // Channel enable and start transfer: -1'b0: disable -1'b1: enable This signal is used also to queue a transfer if one is already ongoing.
    unsigned int clr             :1 ; // Channel clear and stop transfer: -1'b0: disable -1'b1: enable
    unsigned int pending         :1 ; // Transfer pending in queue status flag: -1'b0: free -1'b1: pending
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_i2s_rx_cfg_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_i2s_rx_initcfg_t;

typedef union {
  struct {
    unsigned int tx_saddr        :16; // Configure pointer to memory buffer: - Read: value of the pointer until transfer is over. Else returns 0 - Write: set Address Pointer to memory buffer start address
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_i2s_tx_saddr_t;

typedef union {
  struct {
    unsigned int tx_size         :17; // Buffer size in byte. (128kBytes maximum) - Read: buffer size left - Write: set buffer size
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_i2s_tx_size_t;

typedef union {
  struct {
    unsigned int continous       :1 ; // Channel continuous mode: -1'b0: disable -1'b1: enable At the end of the buffer the uDMA reloads the address and size and starts a new transfer.
    unsigned int datasize        :2 ; // Channel transfer size used to increment uDMA buffer address pointer: - 2'b00: +1 (8 bits) - 2'b01: +2 (16 bits) - 2'b10: +4 (32 bits) - 2'b11: +0
    unsigned int padding0:1 ;
    unsigned int en              :1 ; // Channel enable and start transfer: -1'b0: disable -1'b1: enable This signal is used also to queue a transfer if one is already ongoing.
    unsigned int clr             :1 ; // Channel clear and stop transfer: -1'b0: disable -1'b1: enable
    unsigned int pending         :1 ; // Transfer pending in queue status flag: -1'b0: free -1'b1: pending
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_i2s_tx_cfg_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_i2s_tx_initcfg_t;

typedef union {
  struct {
    unsigned int master_clk_div  :8 ; // LSB of master clock divider
    unsigned int slave_clk_div   :8 ; // LSB of slave clock divider
    unsigned int common_clk_div  :8 ; // MSBs of both master and slave clock divider
    unsigned int slave_clk_en    :1 ; // Enables Slave clock
    unsigned int master_clk_en   :1 ; // Enables Master clock
    unsigned int pdm_clk_en      :1 ; // When enabled slave output clock is taken from PDM module
    unsigned int padding0:1 ;
    unsigned int slave_ext       :1 ; // When set uses external clock for slave
    unsigned int slave_num       :1 ; // Selects slave clock source(either ext or generated): -1b0:selects master -1b1:selects slave
    unsigned int master_ext      :1 ; // When set uses external clock for master
    unsigned int master_num      :1 ; // Selects master clock source(either ext or generated): -1b0:selects master -1b1:selects slave
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_i2s_clkcfg_setup_t;

typedef union {
  struct {
    unsigned int slave_words     :3 ; // Sets how many words for each I2S phase
    unsigned int padding0:5 ;
    unsigned int slave_bits      :5 ; // Sets how many bits per word
    unsigned int padding1:3 ;
    unsigned int slave_lsb       :1 ; // Enables LSB shifting
    unsigned int slave_2ch       :1 ; // Enables both channels
    unsigned int padding2:13;
    unsigned int slave_en        :1 ; // Enables the Slave
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_i2s_slv_setup_t;

typedef union {
  struct {
    unsigned int master_words    :3 ; // Sets how many words for each I2S phase
    unsigned int padding0:5 ;
    unsigned int master_bits     :5 ; // Sets how many bits per word
    unsigned int padding1:3 ;
    unsigned int master_lsb      :1 ; // Enables LSB shifting
    unsigned int master_2ch      :1 ; // Enables both channels
    unsigned int padding2:13;
    unsigned int master_en       :1 ; // Enables the Master
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_i2s_mst_setup_t;

typedef union {
  struct {
    unsigned int pdm_shift       :3 ; // Shifts the output of the filter
    unsigned int pdm_decimation  :10; // Sets the decimation ratio of the filter
    unsigned int pdm_mode        :2 ; // nan
    unsigned int padding0:16;
    unsigned int pdm_en          :1 ; // nan
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_i2s_pdm_setup_t;

#endif

#endif
