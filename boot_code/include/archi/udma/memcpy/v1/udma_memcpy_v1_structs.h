
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

#ifndef __INCLUDE_ARCHI_UDMA_MEMCPY_V1_UDMA_MEMCPY_V1_STRUCTS_H__
#define __INCLUDE_ARCHI_UDMA_MEMCPY_V1_UDMA_MEMCPY_V1_STRUCTS_H__

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
    unsigned int rx_saddr        :16; // RX buffer base address bitfield: - Read: returns value of the buffer pointer until transfer is finished. Else returns 0. - Write: sets RX buffer base address
  };
  unsigned int raw;
} __attribute__((packed)) udma_memcpy_rx_saddr_t;

typedef union {
  struct {
    unsigned int rx_size         :17; // RX buffer size bitfield in bytes. (128kBytes maximum) - Read: returns remaining buffer size to transfer. - Write: sets buffer size.
  };
  unsigned int raw;
} __attribute__((packed)) udma_memcpy_rx_size_t;

typedef union {
  struct {
    unsigned int continous       :1 ; // RX channel continuous mode bitfield: -1'b0: disabled -1'b1: enabled At the end of the buffer transfer, the uDMA reloads the address / buffer size and starts a new transfer.
    unsigned int padding0:3 ;
    unsigned int en              :1 ; // RX channel enable and start transfer bitfield: -1'b0: disable -1'b1: start - enable and start the transfer This signal is used also to queue a transfer if one is already ongoing.
    unsigned int clr             :1 ; // RX channel clear and stop transfer: -1'b0: disable -1'b1: stop and clear - stop and clear the on-going transfer
    unsigned int pending         :1 ; // RX transfer pending in queue status flag: -1'b0: no pending - no pending transfer in the queue -1'b1: pending - pending transfer in the queue
  };
  unsigned int raw;
} __attribute__((packed)) udma_memcpy_rx_cfg_t;

typedef union {
  struct {
    unsigned int tx_saddr        :16; // TX buffer base address bitfield: - Read: returns value of the buffer pointer until transfer is finished. Else returns 0. - Write: sets buffer base address
  };
  unsigned int raw;
} __attribute__((packed)) udma_memcpy_tx_saddr_t;

typedef union {
  struct {
    unsigned int tx_size         :17; // TX buffer size bitfield in bytes. (128kBytes maximum) - Read: returns remaining buffer size to transfer. - Write: sets buffer size.
  };
  unsigned int raw;
} __attribute__((packed)) udma_memcpy_tx_size_t;

typedef union {
  struct {
    unsigned int continous       :1 ; // TX channel continuous mode bitfield: -1'b0: disabled -1'b1: enabled At the end of the buffer transfer, the uDMA reloads the address / buffer size and starts a new transfer.
    unsigned int padding0:3 ;
    unsigned int en              :1 ; // TX channel enable and start transfer bitfield: -1'b0: disabled -1'b1: start - enable and start the transfer This signal is used also to queue a transfer if one is already ongoing.
    unsigned int clr             :1 ; // TX channel clear and stop transfer bitfield: -1'b0: disabled -1'b1: stop and clear - stop and clear the on-going transfer
    unsigned int pending         :1 ; // TX transfer pending in queue status flag: -1'b0: no pending - no pending transfer in the queue -1'b1: pending - pending transfer in the queue
  };
  unsigned int raw;
} __attribute__((packed)) udma_memcpy_tx_cfg_t;

typedef union {
  struct {
    unsigned int dst_addr        :17; // TX destination start address configuration bitfield. MEMCPY TX transfer copy data from L2 TX_CFG.TX_SADDR address to FC_TCDM or L2 memories DST_ADDR address.
  };
  unsigned int raw;
} __attribute__((packed)) udma_memcpy_dst_addr_t;

typedef union {
  struct {
    unsigned int src_addr        :17; // RX source start address configuration bitfield. MEMCPY RX transfer copy data from FC_TCDM or L2 memories SRC_ADDR address to L2 RX_CFG.RX_SADDR address.
  };
  unsigned int raw;
} __attribute__((packed)) udma_memcpy_src_addr_t;

typedef union {
  struct {
    unsigned int mem_sel         :1 ; // Memory selection configuration bitfield: - 1'b0: L2 from/to FC_TCDM - 1'b1: L2 from/to L2
  };
  unsigned int raw;
} __attribute__((packed)) udma_memcpy_mem_sel_t;

#endif

#endif
