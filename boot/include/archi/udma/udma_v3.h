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

#ifndef __ARCHI_UDMA_UDMA_V3_H__
#define __ARCHI_UDMA_UDMA_V3_H__

/*
 * Global register map
 */

// The UDMA register map is made of several channels, each channel area size is defined just below

// Periph area size in log2
#define UDMA_PERIPH_AREA_SIZE_LOG2  7

// Periph area size
#define UDMA_PERIPH_AREA_SIZE       (1<<UDMA_PERIPH_AREA_SIZE_LOG2)

// Channel area size in log2
#define UDMA_CHANNEL_SIZE_LOG2      4

// Channel area size
#define UDMA_CHANNEL_SIZE           (1<<UDMA_CHANNEL_SIZE_LOG2)

#define UDMA_FIRST_CHANNEL_OFFSET   0x80



// Each channel area is itself made of 3 areas
// The offsets are given relative to the offset of the channel

// Offset for RX part
#define UDMA_CHANNEL_RX_OFFSET      0x00

// Offset for TX part
#define UDMA_CHANNEL_TX_OFFSET      0x10

// Offset for peripheral specific part
#define UDMA_CHANNEL_CUSTOM_OFFSET  0x20


// For each channel, the RX and TX part have the following registers
// The offsets are given relative to the offset of the RX or TX part

// Start address register
#define UDMA_CHANNEL_SADDR_OFFSET        0x0

// Size register
#define UDMA_CHANNEL_SIZE_OFFSET         0x4

// Configuration register
#define UDMA_CHANNEL_CFG_OFFSET          0x8

// Int configuration register
#define UDMA_CHANNEL_INTCFG_OFFSET       0xC




// The UDMA also has a global configuration are defined here

// Configuration area offset
#define UDMA_CONF_OFFSET            0x0

// Configuration area size
#define UDMA_CONF_SIZE              0x040

// This area contains the following registers

// Clock-gating control register
#define UDMA_CONF_CG_OFFSET         0x00

// Input event control register
#define UDMA_CONF_EVTIN_OFFSET      0x04







/*
 * Register bitfields
 */

// The configuration register of the RX and TX parts for each channel can be accessed using the following bits

#define UDMA_CHANNEL_CFG_SHADOW_BIT   (5)
#define UDMA_CHANNEL_CFG_CLEAR_BIT    (5)
#define UDMA_CHANNEL_CFG_EN_BIT       (4)
#define UDMA_CHANNEL_CFG_SIZE_BIT     (1)
#define UDMA_CHANNEL_CFG_CONT_BIT     (0)
#define UDMA_CHANNEL_CFG_SHADOW   (1<<UDMA_CHANNEL_CFG_SHADOW_BIT)  // Indicates if a shadow transfer is there
#define UDMA_CHANNEL_CFG_CLEAR    (1<<UDMA_CHANNEL_CFG_CLEAR_BIT)  // Stop and clear all pending transfers
#define UDMA_CHANNEL_CFG_EN       (1<<UDMA_CHANNEL_CFG_EN_BIT)  // Start a transfer
#define UDMA_CHANNEL_CFG_SIZE_8   (0<<UDMA_CHANNEL_CFG_SIZE_BIT)  // Configure for 8-bits transfer
#define UDMA_CHANNEL_CFG_SIZE_16  (1<<UDMA_CHANNEL_CFG_SIZE_BIT)  // Configure for 16-bits transfer
#define UDMA_CHANNEL_CFG_SIZE_32  (2<<UDMA_CHANNEL_CFG_SIZE_BIT)  // Configure for 32-bits transfer
#define UDMA_CHANNEL_CFG_CONT     (1<<UDMA_CHANNEL_CFG_CONT_BIT)  // Configure for continuous mode






/*
 * Macros
 */


// Returns the configuration of an input event. Several values can be ORed together to form the full configuration
#define UDMA_CONF_EVTIN_EVT(udmaId,globalId) ((globalId)<<(udmaId*8))

// Return the offset of a peripheral from its identifier
#define UDMA_PERIPH_OFFSET(id)              (((id)<<UDMA_PERIPH_AREA_SIZE_LOG2)+UDMA_FIRST_CHANNEL_OFFSET)

// Returns the identifier of a peripheral from its offset
#define UDMA_PERIPH_GET(offset)             ((offset)>>UDMA_PERIPH_AREA_SIZE_LOG2)

// Return the offset of a channel from its identifier
#define UDMA_CHANNEL_OFFSET(id)              ((id)<<UDMA_CHANNEL_SIZE_LOG2)

// Returns the identifier of a channel from its offset
#define UDMA_CHANNEL_GET(offset)             ((offset)>>UDMA_CHANNEL_SIZE_LOG2)

// Return the id of a channel from the peripheral id
#define UDMA_CHANNEL_ID(id)                 ((id)*2)

// Return the number of events per peripheral
#define UDMA_NB_PERIPH_EVENTS_LOG2         2
#define UDMA_NB_PERIPH_EVENTS              (1<<UDMA_NB_PERIPH_EVENTS_LOG2)

// Return the periph id from the channel 
#define UDMA_PERIPH_ID(id)                 ((id)/2)

// Return the event id of a channel from the peripheral id
#define UDMA_EVENT_ID(id)                 ((id)*UDMA_NB_PERIPH_EVENTS)



#define ARCHI_SOC_EVENT_UDMA_RX(periph)   ((periph)*2)
#define ARCHI_SOC_EVENT_UDMA_TX(periph)   ((periph)*2 + 1)



// Define UMDA peripheral common register base address map

#ifdef ARCHI_UDMA_HAS_SPIM

#define ARCHI_UDMA_SPIM_RX_OFFSET     0x00
#define ARCHI_UDMA_SPIM_TX_OFFSET     0x10
#define ARCHI_UDMA_SPIM_CMD_OFFSET    0x20

#define ARCHI_UDMA_SPIM_RX_EVT  0
#define ARCHI_UDMA_SPIM_TX_EVT  1
#define ARCHI_UDMA_SPIM_CMD_EVT 2
#define ARCHI_UDMA_SPIM_EOT_EVT 3

#endif



#endif
