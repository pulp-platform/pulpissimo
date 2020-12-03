/*
 * Copyright (C) 2018 ETH Zurich and University of Bologna
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

#ifndef __HAL_UDMA_UDMA_TCDM_V1_H__
#define __HAL_UDMA_UDMA_TCDM_V1_H__

#include "archi/udma/tcdm/udma_tcdm_v1.h"

#define UDMA_TCDM_OFFSET              UDMA_PERIPH_OFFSET(ARCHI_UDMA_TCDM_ID(id))

#define UDMA_TCDM_RX_ADDR             (ARCHI_UDMA_ADDR + UDMA_TCDM_OFFSET + UDMA_CHANNEL_RX_OFFSET)
#define UDMA_TCDM_TX_ADDR             (ARCHI_UDMA_ADDR + UDMA_TCDM_OFFSET + UDMA_CHANNEL_TX_OFFSET)
#define UDMA_TCDM_CUSTOM_ADDR         (ARCHI_UDMA_ADDR + UDMA_TCDM_OFFSET + UDMA_CHANNEL_CUSTOM_OFFSET)

static inline void plp_tcdm_setDst(unsigned int addr)
{
  pulp_write32(ARCHI_UDMA_ADDR + UDMA_TCDM_OFFSET + UDMA_CHANNEL_CUSTOM_OFFSET + TCDM_T_DST_SADDR, addr);
}

static inline void plp_tcdm_setSrc(unsigned int addr)
{
  pulp_write32(ARCHI_UDMA_ADDR + UDMA_TCDM_OFFSET + UDMA_CHANNEL_CUSTOM_OFFSET + TCDM_T_SRC_SADDR, addr);
}

static inline void plp_udma_enqueue_toTcdm(unsigned int l2Addr, unsigned int fcTcdmAddr, unsigned int size, unsigned int cfg)
{
  plp_tcdm_setDst(fcTcdmAddr);
  plp_udma_enqueue(UDMA_TCDM_TX_ADDR, l2Addr, size, cfg);
}

static inline void plp_udma_enqueue_fromTcdm(unsigned int l2Addr, unsigned int fcTcdmAddr, unsigned int size, unsigned int cfg)
{
  plp_tcdm_setSrc(fcTcdmAddr);
  plp_udma_enqueue(UDMA_TCDM_RX_ADDR, l2Addr, size, cfg);
}

#endif