/* 
 * Copyright (C) 2015 ETH Zurich and University of Bologna
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 *
 */

#ifndef __ARCHI_UDMA_V1_H__
#define __ARCHI_UDMA_V1_H__

#include "archi/pulp.h"
#include "archi/udma/udma_periph_v1.h"

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
#define UDMA_CONF_OFFSET            0x200

// Configuration area size
#define UDMA_CONF_SIZE              0x008

// This area contains the following registers

// First event mask configuration
#define UDMA_EVENTS_SETUP0_OFFSET    0x00

// Second event mask configuration
#define UDMA_EVENTS_SETUP1_OFFSET    0x04



/*
 * Register bitfields
 */

// The configuration register of the RX and TX parts for each channel can be accessed using the following bits

#define UDMA_CHANNEL_CFG_CLEAR    (1<<5)  // Stop and clear all pending transfers
#define UDMA_CHANNEL_CFG_EN       (1<<4)  // Start a transfer
#define UDMA_CHANNEL_CFG_SIZE_BIT (1)
#define UDMA_CHANNEL_CFG_SIZE_8   (0<<UDMA_CHANNEL_CFG_SIZE_BIT)  // Configure for 8-bits transfer
#define UDMA_CHANNEL_CFG_SIZE_16  (1<<UDMA_CHANNEL_CFG_SIZE_BIT)  // Configure for 16-bits transfer
#define UDMA_CHANNEL_CFG_SIZE_32  (2<<UDMA_CHANNEL_CFG_SIZE_BIT)  // Configure for 32-bits transfer
#define UDMA_CHANNEL_CFG_CONT     (1<<0)  // Configure for continuous mode






/*
 * Macros
 */


// Return the offset of a peripheral from its identifier
#define UDMA_PERIPH_OFFSET(id)              ((id)*UDMA_PERIPH_AREA_SIZE)

// Returns the identifier of a peripheral from its offset
#define UDMA_PERIPH_GET(offset)             ((offset)>>UDMA_PERIPH_AREA_SIZE_LOG2)

// Return the offset of a channel from its identifier
#define UDMA_CHANNEL_OFFSET(id)              ((id)*UDMA_CHANNEL_SIZE)

// Returns the identifier of a channel from its offset
#define UDMA_CHANNEL_GET(offset)             ((offset)>>UDMA_CHANNEL_SIZE_LOG2)







#endif
