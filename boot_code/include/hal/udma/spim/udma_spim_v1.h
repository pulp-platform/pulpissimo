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

#ifndef __HAL_UDMA_UDMA_SPIM_V1_H__
#define __HAL_UDMA_UDMA_SPIM_V1_H__

#include "archi/udma/spim/udma_spim_v1.h"


static inline void plp_spi_disable(unsigned channelBase)
{
  pulp_write32(channelBase + UDMA_CHANNEL_CFG_OFFSET, 0);
}

static inline void hal_udma_spim_enqueue(unsigned int periphBase, unsigned channelBase, unsigned int spi_status, unsigned int l2Addr, unsigned int size, unsigned int cfg, unsigned int spi_len)
{
  pulp_write32(periphBase + UDMA_CHANNEL_CUSTOM_OFFSET + SPIM_SPILEN_OFFSET, spi_len << 16);
  pulp_write32(channelBase + UDMA_CHANNEL_SADDR_OFFSET, l2Addr);
  pulp_write32(channelBase + UDMA_CHANNEL_SIZE_OFFSET, size);
  pulp_write32(channelBase + UDMA_CHANNEL_CFG_OFFSET, cfg);
  pulp_write32(periphBase + UDMA_CHANNEL_CUSTOM_OFFSET + SPIM_STATUS_OFFSET, spi_status);
}

static inline uint32_t hal_udma_spim_status_compute(
  unsigned int cskeep, unsigned int cs, unsigned int reset, unsigned int command
)
{
  return (cskeep << ARCHI_SPIM_WSTATUS_CSKEEP_BIT) |
    (cs << ARCHI_SPIM_WSTATUS_CS_BIT) |
    (reset << ARCHI_SPIM_WSTATUS_RESET_BIT) |
    (command << ARCHI_SPIM_WSTATUS_CMD_BIT);
}

static inline uint32_t hal_udma_spim_status_get(uint32_t periph_base)
{
  return pulp_read32(periph_base + UDMA_CHANNEL_CUSTOM_OFFSET + SPIM_STATUS_OFFSET);
}

static inline void hal_udma_spim_status_set(uint32_t periph_base, uint32_t value)
{
  pulp_write32(periph_base + UDMA_CHANNEL_CUSTOM_OFFSET + SPIM_STATUS_OFFSET, value);
}

static inline uint32_t hal_udma_spim_clkdiv_compute(
  int datasize_tx, int datasize_rx, int cpha, int cpol, int clkdiv
)
{
  return (datasize_tx << ARCHI_SPIM_CLKDIV_DATASIZE_TX_BIT) |
    (datasize_rx << ARCHI_SPIM_CLKDIV_DATASIZE_RX_BIT) |
    (cpha << ARCHI_SPIM_CLKDIV_CPHA_BIT) |
    (cpol << ARCHI_SPIM_CLKDIV_CPOL_BIT) |
    (clkdiv << ARCHI_SPIM_CLKDIV_CLKDIV_BIT);
}

static inline uint32_t hal_udma_spim_clkdiv_get(uint32_t periph_base)
{
  return pulp_read32(periph_base + UDMA_CHANNEL_CUSTOM_OFFSET + SPIM_CLKDIV_OFFSET);
}

static inline void hal_udma_spim_clkdiv_set(uint32_t periph_base, uint32_t value)
{
  pulp_write32(periph_base + UDMA_CHANNEL_CUSTOM_OFFSET + SPIM_CLKDIV_OFFSET, value);
}

#endif