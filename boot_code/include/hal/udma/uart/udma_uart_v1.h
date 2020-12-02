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

#ifndef __HAL_UDMA_UDMA_UART_V1_H__
#define __HAL_UDMA_UDMA_UART_V1_H__

#include "archi/udma/uart/udma_uart_v1.h"

#define UDMA_UART_OFFSET(id)          UDMA_PERIPH_OFFSET(ARCHI_UDMA_UART_ID(id))
#define UDMA_UART_RX_ADDR(id)         (ARCHI_UDMA_ADDR + UDMA_UART_OFFSET(id) + UDMA_CHANNEL_RX_OFFSET)
#define UDMA_UART_TX_ADDR(id)         (ARCHI_UDMA_ADDR + UDMA_UART_OFFSET(id) + UDMA_CHANNEL_TX_OFFSET)
#define UDMA_UART_CUSTOM_ADDR(id)     (ARCHI_UDMA_ADDR + UDMA_UART_OFFSET(id) + UDMA_CHANNEL_CUSTOM_OFFSET)
#define ARCHI_SOC_EVENT_UART_RX(id)    (ARCHI_SOC_EVENT_PERIPH_FIRST_EVT(ARCHI_UDMA_UART_ID(id)) + ARCHI_UDMA_UART_RX_EVT)
#define ARCHI_SOC_EVENT_UART_TX(id)    (ARCHI_SOC_EVENT_PERIPH_FIRST_EVT(ARCHI_UDMA_UART_ID(id)) + ARCHI_UDMA_UART_TX_EVT)

// UDMA RX/TX Channels HAL Registers Structure
typedef struct {
    uint32_t rx_ch_saddr;
    uint32_t rx_ch_size;
    uint32_t rx_ch_cfg;
    uint32_t rx_ch_initcfg_unused;
    uint32_t tx_ch_saddr;
    uint32_t tx_ch_size;
    uint32_t tx_ch_cfg;
    uint32_t tx_ch_initcfg_unused;
} plpUdmaRxTxChHandle3_t;

// UART HAL Registers Structure
typedef struct {
    plpUdmaRxTxChHandle3_t udma_rxtx_ch_handle;
    uint32_t status;
    uint32_t setup;
} plpUdmaUartHandle_t;

// UART HAL Register Fields Structure
typedef struct {
    uint32_t tx_oe:1;
    uint32_t rx_oe:1;
    uint32_t rx_pe:1;
    uint32_t unused:29;
} __attribute__ ((packed)) plpUdmaUartStatus_t;

typedef struct {
    uint32_t parity_en:1;
    uint32_t char_length:2;
    uint32_t stop_bit_length:1;
    uint32_t unused0:4;
    uint32_t tx_en:1;
    uint32_t rx_en:1;
    uint32_t unused1:6;
    uint32_t clkdiv:16;
} __attribute__ ((packed)) plpUdmaUartSetup_t;

// UART HAL Register Union definition
typedef union {
    plpUdmaUartStatus_t  status;
    plpUdmaUartSetup_t   setup;
    uint32_t raw;
} __attribute__ ((packed)) plpUdmaUartCustom_u;

// UART HAL Handle
#define UART_HANDLE(id) ((plpUdmaUartHandle_t *)(ARCHI_UDMA_ADDR + UDMA_UART_OFFSET(id)))

// UART HAL functions prototype
static inline void plpUdmaUartSetupSet (plpUdmaUartHandle_t * const handle, uint32_t data);
static inline uint32_t plpUdmaUartSetupGet (plpUdmaUartHandle_t * const handle);
static inline uint32_t plpUdmaUartStatusGet (plpUdmaUartHandle_t * const handle);

// UART HAL functions definition
static inline void plpUdmaUartSetupSet (plpUdmaUartHandle_t * const handle, uint32_t data) {
    handle->setup = data;
}

static inline uint32_t plpUdmaUartSetupGet (plpUdmaUartHandle_t * const handle) {
    return handle->setup;
}

static inline uint32_t plpUdmaUartStatusGet (plpUdmaUartHandle_t * const handle) {
    return handle->status;
}

///////////////////////////////////////////////////
// TODO Obsolete : to be removed cause deprecated
/**
 * Setup UART. The UART defaults to 8 bit character mode with 1 stop bit.
 *
 * parity       Enable/disable parity mode
 * clk_counter  Clock counter value that is used to derive the UART clock.
 *              There is a prescaler in place that already divides the SoC
 *              clock by 16.  Since this is a counter, a value of 0 means that
 *              the SoC clock divided by 16 is used. A value of 31 would mean
 *              that we use the SoC clock divided by 16*32 = 512.
 */

static inline void plp_uart_setup(int channel, int parity, uint16_t clk_counter)
{

  // [31:16]: clock divider (from SoC clock)
  // [9]: RX enable
  // [8]: TX enable
  // [3]: stop bits  0 = 1 stop bit
  //                 1 = 2 stop bits
  // [2:1]: bits     00 = 5 bits
  //                 01 = 6 bits
  //                 10 = 7 bits
  //                 11 = 8 bits
  // [0]: parity

  unsigned int val = 0x0306 | parity; // both tx and rx enabled; 8N1 configuration; 1 stop bits

  val |= ((clk_counter) << 16);

  pulp_write32(ARCHI_UDMA_ADDR + UDMA_UART_OFFSET(channel) + UDMA_CHANNEL_CUSTOM_OFFSET + UART_SETUP_OFFSET, val);
}

static inline void plp_uart_disable(int channel) {
  pulp_write32(ARCHI_UDMA_ADDR + UDMA_UART_OFFSET(channel) + UDMA_CHANNEL_CUSTOM_OFFSET + UART_SETUP_OFFSET, 0x00500006);
}

static inline int plp_uart_tx_busy(int channel) {
  return pulp_read32(ARCHI_UDMA_ADDR + UDMA_UART_OFFSET(channel) + UDMA_CHANNEL_CUSTOM_OFFSET + UART_STATUS_OFFSET) & 1;
}

static inline int plp_uart_rx_busy(int channel) {
  return (pulp_read32(ARCHI_UDMA_ADDR + UDMA_UART_OFFSET(channel) + UDMA_CHANNEL_CUSTOM_OFFSET + UART_STATUS_OFFSET) >> 1) & 1;
}

static inline unsigned int plp_uart_reg_read(int channel, unsigned int addr)
{ //adr is an offset, expected UART_STATUS_OFFSET or UART_SETUP_OFFSET
  return pulp_read32(ARCHI_UDMA_ADDR + UDMA_UART_OFFSET(channel) + UDMA_CHANNEL_CUSTOM_OFFSET + addr);
}

static inline void plp_uart_reg_write(int channel, unsigned int addr, unsigned int cfg)
{ //adr is an offset, expected UART_STATUS_OFFSET or UART_SETUP_OFFSET
  pulp_write32(ARCHI_UDMA_ADDR + UDMA_UART_OFFSET(channel) + UDMA_CHANNEL_CUSTOM_OFFSET + addr, cfg);
}

#endif