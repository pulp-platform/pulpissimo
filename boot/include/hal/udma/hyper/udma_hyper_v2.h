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

#ifndef __HAL_UDMA_UDMA_PERIPH_HYPER_V1_H__
#define __HAL_UDMA_UDMA_PERIPH_HYPER_V1_H__

#include <archi/pulp.h>

#define ARCHI_UDMA_HYPER_RX_EVT           0
#define ARCHI_UDMA_HYPER_TX_EVT           1

#define UDMA_HYPER_ADDR(id)         (ARCHI_UDMA_ADDR + UDMA_HYPER_OFFSET(id))

#define UDMA_HYPER_OFFSET(id)         UDMA_PERIPH_OFFSET(ARCHI_UDMA_HYPER_ID(id))
#define UDMA_HYPER_RX_ADDR(id)         (ARCHI_UDMA_ADDR + UDMA_HYPER_OFFSET(id) + UDMA_CHANNEL_RX_OFFSET)
#define UDMA_HYPER_TX_ADDR(id)         (ARCHI_UDMA_ADDR + UDMA_HYPER_OFFSET(id) + UDMA_CHANNEL_TX_OFFSET)
#define UDMA_HYPER_CUSTOM_ADDR(id)     (ARCHI_UDMA_ADDR + UDMA_HYPER_OFFSET(id) + UDMA_CHANNEL_CUSTOM_OFFSET)
#define ARCHI_SOC_EVENT_HYPER_RX(id)    (ARCHI_SOC_EVENT_PERIPH_FIRST_EVT(ARCHI_UDMA_HYPER_ID(id)) + ARCHI_UDMA_HYPER_RX_EVT)
#define ARCHI_SOC_EVENT_HYPER_TX(id)    (ARCHI_SOC_EVENT_PERIPH_FIRST_EVT(ARCHI_UDMA_HYPER_ID(id)) + ARCHI_UDMA_HYPER_TX_EVT)

#include "archi/udma/hyper/udma_hyper_v2.h"

#define REG_MBR0      0
#define REG_MBR1      0x01000000

static inline void hal_hyper_udma_ext_addr_set(unsigned int value)
{
  pulp_write32(UDMA_HYPER_ADDR(0) + HYPER_EXT_ADDR_OFFSET, value);
}

static inline unsigned int hal_hyper_udma_ext_addr_get()
{
  return (unsigned int)pulp_read32(UDMA_HYPER_ADDR(0) + HYPER_EXT_ADDR_OFFSET);
}

static inline void hal_hyper_udma_addr_set(unsigned int addr)
{
  hal_hyper_udma_ext_addr_set(addr);
}

static inline void hal_hyper_enqueue(unsigned channelBase, unsigned int l2Addr, unsigned int ext_addr, unsigned int size, unsigned int cfg)
{
  hal_hyper_udma_ext_addr_set(ext_addr);
  plp_udma_enqueue(channelBase, l2Addr, size, cfg);
}

static inline void hal_hyper_ram_ext_addr_set(unsigned int value)
{
  return hal_hyper_udma_addr_set(REG_MBR0 | value);
}

static inline void hal_hyper_flash_ext_addr_set(unsigned int value)
{
  return hal_hyper_udma_addr_set(REG_MBR1 | value);
}

/*
 * Hyper IP boot initialization
 */
/*
  PLP_BOOT_CODE __attribute__((constructor)) void plp_hyper_ip_init()
  {
  plp_trace(RT_TRACE_INIT, "Hyper IP driver initialization\n");

  plp_trace(RT_TRACE_INIT, "Hyper driver initialization done\n");
  }
*/

#if 0
static inline void hal_hyper_ext_addr_set(unsigned int value)
{
    pulp_write32(ARCHI_UDMA_ADDR + HYPER_EXT_ADDR_OFFSET, value);
}

static inline void hal_hyper_ram_ext_addr_set(unsigned int value) {return hal_hyper_ext_addr_set(REG_MBR0 | value);}

static inline void hal_hyper_flash_ext_addr_set(unsigned int value) {return hal_hyper_ext_addr_set(REG_MBR1 | value);}

static inline void hal_hyper_enqueue(unsigned channelBase, unsigned int l2Addr, unsigned int ext_addr, unsigned int size, unsigned int cfg) {
  hal_hyper_ext_addr_set(ext_addr);
  plp_udma_enqueue(channelBase, l2Addr, size, cfg);
}

static inline void hal_hyper_ram_enqueue(unsigned channelBase, unsigned int l2Addr, unsigned int ext_addr, unsigned int size, unsigned int cfg) {
  hal_hyper_ram_ext_addr_set(ext_addr);
  plp_udma_enqueue(channelBase, l2Addr, size, cfg);
}

static inline void hal_hyper_flash_enqueue(unsigned channelBase, unsigned int l2Addr, unsigned int ext_addr, unsigned int size, unsigned int cfg) {
  hal_hyper_flash_ext_addr_set(ext_addr);
  plp_udma_enqueue(channelBase, l2Addr, size, cfg);
}
#endif

#endif
