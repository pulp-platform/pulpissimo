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

#ifndef __ARCHI_UDMA_UDMA_V2_H__
#define __ARCHI_UDMA_UDMA_V2_H__

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
#if defined(PULP_CHIP_FAMILY) && PULP_CHIP_FAMILY == CHIP_USOC_V1
#define UDMA_CONF_OFFSET            0xF80
#else
#define UDMA_CONF_OFFSET            0x780
#endif

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
#define UDMA_PERIPH_OFFSET(id)              ((id)<<UDMA_PERIPH_AREA_SIZE_LOG2)

// Returns the identifier of a peripheral from its offset
#define UDMA_PERIPH_GET(offset)             ((offset)>>UDMA_PERIPH_AREA_SIZE_LOG2)

// Return the offset of a channel from its identifier
#define UDMA_CHANNEL_OFFSET(id)              ((id)<<UDMA_CHANNEL_SIZE_LOG2)

// Returns the identifier of a channel from its offset
#define UDMA_CHANNEL_GET(offset)             ((offset)>>UDMA_CHANNEL_SIZE_LOG2)

// Return the id of a channel from the peripheral id
#define UDMA_CHANNEL_ID(id)                 ((id)*2)

// Return the number of events per peripheral
#define UDMA_NB_PERIPH_EVENTS_LOG2         1
#define UDMA_NB_PERIPH_EVENTS              (1<<UDMA_NB_PERIPH_EVENTS_LOG2)

// Return the periph id from the channel 
#define UDMA_PERIPH_ID(id)                 ((id)/2)

// Return the event id of a channel from the peripheral id
#define UDMA_EVENT_ID(id)                 ((id)*UDMA_NB_PERIPH_EVENTS)



// Define UDMA peripherals offset in case of multiple same periph
#ifdef ARCHI_UDMA_HAS_SPIM
#define UDMA_SPIM_OFFSET(id)          UDMA_PERIPH_OFFSET(ARCHI_UDMA_SPIM_ID(id))
#endif
#ifdef ARCHI_UDMA_HAS_UART
#define UDMA_UART_OFFSET(id)          UDMA_PERIPH_OFFSET(ARCHI_UDMA_UART_ID(id))
#endif
#ifdef ARCHI_UDMA_HAS_I2C
#define UDMA_I2C_OFFSET(id)           UDMA_PERIPH_OFFSET(ARCHI_UDMA_I2C_ID(id))
#endif
#ifdef ARCHI_UDMA_HAS_I2S
#endif
#ifdef ARCHI_UDMA_HAS_CAM
#define UDMA_CAM_OFFSET(id)           UDMA_PERIPH_OFFSET(ARCHI_UDMA_CAM_ID(id))
#endif
#ifdef ARCHI_UDMA_HAS_TRACER
#define UDMA_TRACER_OFFSET(id)        UDMA_PERIPH_OFFSET(ARCHI_UDMA_TRACER_ID(id))
#endif
#ifdef ARCHI_UDMA_HAS_TGEN
#define UDMA_TGEN_OFFSET(id)          UDMA_PERIPH_OFFSET(ARCHI_UDMA_TGEN_ID(id))
#endif
#ifdef ARCHI_UDMA_HAS_TCDM
#define UDMA_TCDM_OFFSET              UDMA_PERIPH_OFFSET(ARCHI_UDMA_TCDM_ID(id))
#endif
#ifdef ARCHI_UDMA_HAS_CPY
#define UDMA_CPY_OFFSET(id)           UDMA_PERIPH_OFFSET(ARCHI_UDMA_CPY_ID(id))
#endif
     
#define ARCHI_SOC_EVENT_UDMA_RX(periph)   ((periph)*2)
#define ARCHI_SOC_EVENT_UDMA_TX(periph)   ((periph)*2 + 1)

// Define UMDA peripheral common register base address map

#ifdef ARCHI_UDMA_HAS_SPIM
#define UDMA_SPIM_RX_ADDR(id)         (ARCHI_UDMA_ADDR + UDMA_SPIM_OFFSET(id) + UDMA_CHANNEL_RX_OFFSET)
#define UDMA_SPIM_TX_ADDR(id)         (ARCHI_UDMA_ADDR + UDMA_SPIM_OFFSET(id) + UDMA_CHANNEL_TX_OFFSET)
#define UDMA_SPIM_CUSTOM_ADDR(id)     (ARCHI_UDMA_ADDR + UDMA_SPIM_OFFSET(id) + UDMA_CHANNEL_CUSTOM_OFFSET)
#endif

#ifdef ARCHI_UDMA_HAS_I2C
#define UDMA_I2C_DATA_ADDR(id)        (ARCHI_UDMA_ADDR + UDMA_I2C_OFFSET(id) + UDMA_CHANNEL_RX_OFFSET)
#define UDMA_I2C_CMD_ADDR(id)         (ARCHI_UDMA_ADDR + UDMA_I2C_OFFSET(id) + UDMA_CHANNEL_TX_OFFSET)
#define UDMA_I2C_CUSTOM_ADDR(id)      (ARCHI_UDMA_ADDR + UDMA_I2C_OFFSET(id) + UDMA_CHANNEL_CUSTOM_OFFSET)
#endif

#ifdef ARCHI_UDMA_HAS_CAM
#define UDMA_CAM_RX_ADDR(id)          (ARCHI_UDMA_ADDR + UDMA_CAM_OFFSET(id) + UDMA_CHANNEL_RX_OFFSET)
#define UDMA_CAM_CUSTOM_ADDR(id)      (ARCHI_UDMA_ADDR + UDMA_CAM_OFFSET(id) + UDMA_CHANNEL_CUSTOM_OFFSET)
#define ARCHI_SOC_EVENT_CAM_RX(id)    ARCHI_SOC_EVENT_UDMA_RX(ARCHI_UDMA_CAM_ID(id))
#endif

#ifdef ARCHI_UDMA_HAS_TRACER
#define UDMA_TRACER_RX_ADDR(id)       (ARCHI_UDMA_ADDR + UDMA_TRACER_OFFSET(id) + UDMA_CHANNEL_RX_OFFSET)
#define UDMA_TRACER_CUSTOM_ADDR(id)   (ARCHI_UDMA_ADDR + UDMA_TRACER_OFFSET(id) + UDMA_CHANNEL_CUSTOM_OFFSET)
#define ARCHI_SOC_EVENT_TRACER_RX(id) ARCHI_SOC_EVENT_UDMA_RX(ARCHI_UDMA_TRACER_ID(id))
#endif

#ifdef ARCHI_UDMA_HAS_TGEN
#define UDMA_TGEN_RX_ADDR(id)         (ARCHI_UDMA_ADDR + UDMA_TGEN_OFFSET(id) + UDMA_CHANNEL_RX_OFFSET)
#define UDMA_TGEN_TX_ADDR(id)         (ARCHI_UDMA_ADDR + UDMA_TGEN_OFFSET(id) + UDMA_CHANNEL_TX_OFFSET)
#endif

#ifdef ARCHI_UDMA_HAS_TCDM
#define UDMA_TCDM_RX_ADDR             (ARCHI_UDMA_ADDR + UDMA_TCDM_OFFSET + UDMA_CHANNEL_RX_OFFSET)
#define UDMA_TCDM_TX_ADDR             (ARCHI_UDMA_ADDR + UDMA_TCDM_OFFSET + UDMA_CHANNEL_TX_OFFSET)
#define UDMA_TCDM_CUSTOM_ADDR         (ARCHI_UDMA_ADDR + UDMA_TCDM_OFFSET + UDMA_CHANNEL_CUSTOM_OFFSET)
#endif

#ifdef ARCHI_UDMA_HAS_CPY
#define UDMA_CPY_RX_ADDR(id)         (ARCHI_UDMA_ADDR + UDMA_CPY_OFFSET(id) + UDMA_CHANNEL_RX_OFFSET)
#define UDMA_CPY_TX_ADDR(id)         (ARCHI_UDMA_ADDR + UDMA_CPY_OFFSET(id) + UDMA_CHANNEL_TX_OFFSET)
#define UDMA_CPY_CUSTOM_ADDR(id)     (ARCHI_UDMA_ADDR + UDMA_CPY_OFFSET(id) + UDMA_CHANNEL_CUSTOM_OFFSET)
#endif

#endif
