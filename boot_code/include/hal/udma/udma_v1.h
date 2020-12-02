/*
 * Copyright (C) 2015 ETH Zurich and University of Bologna
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 *
 */

#ifndef __HAL_UDMA_V1_H__
#define __HAL_UDMA_V1_H__

#include <hal/pulp.h>
#include "hal/udma/udma_periph_v1.h"

static inline void plp_udma_enqueue(unsigned channelBase, unsigned int l2Addr, unsigned int size, unsigned int cfg)
{
  pulp_write32(channelBase + UDMA_CHANNEL_SADDR_OFFSET, l2Addr);
  pulp_write32(channelBase + UDMA_CHANNEL_SIZE_OFFSET, size);
  pulp_write32(channelBase + UDMA_CHANNEL_CFG_OFFSET, cfg);
}

/** Tell if a channel is busy, i.e. if it already contains at least one on-going transfer
 * 
  \param   channelOffset Offset of the channel
  \return  1 if the channel is busy, 0 otherwise
  */
static inline int plp_udma_busy(unsigned channelOffset);

static inline void udma_mapAllEvents(unsigned int inEvent0, unsigned int inEvent1, unsigned int inEvent2, unsigned int inEvent3, unsigned int inEvent4, unsigned int inEvent5, unsigned int inEvent6, unsigned int inEvent7)
{
  pulp_write32(ARCHI_UDMA_ADDR + UDMA_CONF_OFFSET + UDMA_EVENTS_SETUP0_OFFSET, (inEvent0 << 0) | (inEvent1 << 4) | (inEvent2 << 8) | (inEvent3 << 12) | (inEvent4 << 16) | (inEvent5 << 20) | (inEvent6 << 24) | (inEvent7 << 28));
}

static inline void udma_mapAllEvents1(unsigned int inEvent0, unsigned int inEvent1, unsigned int inEvent2, unsigned int inEvent3, unsigned int inEvent4, unsigned int inEvent5, unsigned int inEvent6, unsigned int inEvent7)
{
  pulp_write32(ARCHI_UDMA_ADDR + UDMA_CONF_OFFSET + UDMA_EVENTS_SETUP1_OFFSET, (inEvent0 << 0) | (inEvent1 << 4) | (inEvent2 << 8) | (inEvent3 << 12) | (inEvent4 << 16) | (inEvent5 << 20) | (inEvent6 << 24) | (inEvent7 << 28));
}

/// @cond IMPLEM

static inline int plp_udma_busy(unsigned channelOffset)
{
  return (pulp_read32(channelOffset + UDMA_CHANNEL_CFG_OFFSET) & UDMA_CHANNEL_CFG_EN);
}

static inline unsigned int hal_udma_channel_base(int id) {
  return ARCHI_SOC_PERIPHERALS_ADDR + ARCHI_UDMA_OFFSET + UDMA_PERIPH_OFFSET(id>>1) + UDMA_CHANNEL_OFFSET(id&1);
}

static inline unsigned int hal_udma_periph_base(int id) {
  return ARCHI_SOC_PERIPHERALS_ADDR + ARCHI_UDMA_OFFSET + UDMA_PERIPH_OFFSET(id);
}

/// @endcond

#endif