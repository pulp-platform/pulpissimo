/*
 * Copyright (C) 2021 ETH Zurich and University of Bologna
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
 *
 *
 * Author: Robert Balas <balasr@iis.ee.ethz.ch>
 *
 * uDMA uart hal
 */

#ifndef __UART_RB_H__
#define __UART_RB_H__

#include <stdint.h>

/* Compatibility macros */
#define UDMA_UART_OFFSET(id) UDMA_PERIPH_OFFSET(ARCHI_UDMA_UART_ID(id))
#define UDMA_UART_RX_ADDR(id)                                                  \
	(ARCHI_UDMA_ADDR + UDMA_UART_OFFSET(id) + UDMA_CHANNEL_RX_OFFSET)
#define UDMA_UART_TX_ADDR(id)                                                  \
	(ARCHI_UDMA_ADDR + UDMA_UART_OFFSET(id) + UDMA_CHANNEL_TX_OFFSET)
#define ARCHI_SOC_EVENT_UART_RX(id)                                            \
	(ARCHI_SOC_EVENT_PERIPH_FIRST_EVT(ARCHI_UDMA_UART_ID(id)) +            \
	 ARCHI_UDMA_UART_RX_EVT)
#define ARCHI_SOC_EVENT_UART_TX(id)                                            \
	(ARCHI_SOC_EVENT_PERIPH_FIRST_EVT(ARCHI_UDMA_UART_ID(id)) +            \
	 ARCHI_UDMA_UART_TX_EVT)

/* base address of uart configuration */
#define UART_REG_BASE(channel)                                                 \
	(ARCHI_UDMA_ADDR + UDMA_UART_OFFSET(channel) +                         \
	 UDMA_CHANNEL_CUSTOM_OFFSET)

/**
 * @brief Convenience macro reads or sets register fields
 *
 * @param FIELD Register name
 * @param v value of bits
 */
#define REG_SET(FIELD, v) (((v) << FIELD##_SHIFT) & FIELD##_MASK)
#define REG_SET_FIELD(FIELD, v)                                                \
	((v & ~FIELD##_MASK) | (((v) << FIELD##_SHIFT) & FIELD##_MASK))
#define REG_GET(FIELD, v) (((v)&FIELD##_MASK) >> FIELD##_SHIFT)

/*! @name STATUS register */

/* TX busy status flag */
#define UART_STATUS_TX_BUSY_MASK  (0x1)
#define UART_STATUS_TX_BUSY_SHIFT (0)

/* RX busy status flag */
#define UART_STATUS_RX_BUSY_MASK  (0x2)
#define UART_STATUS_RX_BUSY_SHIFT (1)

/* RX parity error status flag */
#define UART_STATUS_RX_PE_MASK	(0x4)
#define UART_STATUS_RX_PE_SHIFT (2)

/*! @name SETUP register */

/* Set parity generation and check:
  - 1'b0: disable
  - 1'b1: enable */
#define UART_SETUP_PARITY_ENA_MASK  (0x1)
#define UART_SETUP_PARITY_ENA_SHIFT (0)

/* Set character length:
  - 2'b00: 5 bits
  - 2'b01: 6 bits
  - 2'b10: 7 bits
  - 2'b11: 8 bits */
#define UART_SETUP_BIT_LENGTH_MASK  (0x6)
#define UART_SETUP_BIT_LENGTH_SHIFT (1)

/* Set stop bits length:
  - 2'b0: 1 stop bit
  - 2'b1: 2 stop bits */
#define UART_SETUP_STOP_BITS_MASK  (0x8)
#define UART_SETUP_STOP_BITS_SHIFT (3)

/* Set polling mode:
  - 1'b0: disable
  - 1'b1: Enable polling data transfer. Wait until valid register signals ok,
    then read data register. Valid register automatically cleared after read.*/
#define UART_SETUP_POLLING_EN_MASK  (0x10)
#define UART_SETUP_POLLING_EN_SHIFT (4)

/* Set clean fifo mode:
  - 1'b0: disable
  - 1'b1: clean the rx fifo */
#define UART_SETUP_CLEAN_FIFO_MASK  (0x20)
#define UART_SETUP_CLEAN_FIFO_SHIFT (5)

/* Set TX transceiver state:
  - 1'b0: disable
  - 1'b1: enable */
#define UART_SETUP_TX_ENA_MASK	(0x100)
#define UART_SETUP_TX_ENA_SHIFT (8)

/* Set RX transceiver state:
  - 1'b0: disable
  - 1'b1: enable */
#define UART_SETUP_RX_ENA_MASK	(0x200)
#define UART_SETUP_RX_ENA_SHIFT (9)

/* Sets the clock divider ratio for the baud rate generator. */
#define UART_SETUP_CLKDIV_MASK	(0xffff0000)
#define UART_SETUP_CLKDIV_SHIFT (16)

/*! @name ERROR register */

/* Reports overflow error:
  - 1'b0: no error
  - 1'b1: rx overflow error */
#define UART_ERROR_RX_ERR_OVERFLOW_MASK	 (0x1)
#define UART_ERROR_RX_ERR_OVERFLOW_SHIFT (0)

/* Reports parity error:
  - 1'b0: no error
  - 1'b1: rx parity error */
#define UART_ERROR_RX_ERR_PARITY_MASK  (0x2)
#define UART_ERROR_RX_ERR_PARITY_SHIFT (1)

/*! @name IRQ_EN register */

/* Rx interrupt in enable flag:
  - 1’b0: RX IRQ disable
  - 1’b1: RX IRQ enable */
#define UART_IRQ_EN_RX_MASK  (0x1)
#define UART_IRQ_EN_RX_SHIFT (0)

/* Error interrupt in enable flag:
  - 1’b0: Error IRQ disable
  - 1’b1: Error IRQ enable*/
#define UART_IRQ_EN_ERROR_MASK	(0x2)
#define UART_IRQ_EN_ERROR_SHIFT (1)

/*! @name READY register */

/* Used only in RX polling method to indicate data is ready for read:
  - 1’b0: Data is not ready to read
  - 1’b1: Data is ready to read */
#define UART_VALID_READY_MASK  (0x1)
#define UART_VALID_READY_SHIFT (0)

/* RX read data for polling or interrupt */
#define UART_DATA_MASK	(0xff)
#define UART_DATA_SHIFT (0)


/**
 * @brief Setup rx and tx uart:
 * @param channel uart channel number
 * @param parity enable uart parity bit
 * @param poll use polling mode for rx
 * @param clk_divider set clock divider value
 */

static inline void hal_uart_setup(int channel, int parity, int poll,
				  uint16_t clk_divider)
{
	uint32_t val = 0;
	val |= REG_SET(UART_SETUP_TX_ENA, 1);
	val |= REG_SET(UART_SETUP_RX_ENA, 1);
	val |= REG_SET(UART_SETUP_BIT_LENGTH, 0x3); /* 8 bits */
	val |= REG_SET(UART_SETUP_PARITY_ENA, parity);
	val |= REG_SET(UART_SETUP_CLKDIV, clk_divider);
	val |= REG_SET(UART_SETUP_POLLING_EN, poll);

	pulp_write32(UART_REG_BASE(channel) + UART_SETUP_OFFSET, val);
}

/**
 * @brief Disable uart channel.
 * @param channel uart channel number
 */

static inline void hal_uart_disable(int channel)
{
	/* TODO: other code use this 0x00500006 ??? */
	uint32_t val = pulp_read32(UART_REG_BASE(channel) + UART_SETUP_OFFSET);

	val |= REG_SET(UART_SETUP_TX_ENA, 0);
	val |= REG_SET(UART_SETUP_RX_ENA, 0);

	pulp_write32(UART_REG_BASE(channel) + UART_SETUP_OFFSET, val);
}

/**
 * @brief Check if tx dma transfer is running
 * @param channel uart channel number
 */
static inline int hal_uart_tx_busy(int channel)
{
	return REG_GET(UART_STATUS_TX_BUSY, pulp_read32(UART_REG_BASE(channel) +
							UART_STATUS_OFFSET));
}

/**
 * @brief Check if rx dma transfer is running
 *
 * @param channel uart channel number
 */
static inline int hal_uart_rx_busy(int channel)
{
	return REG_GET(UART_STATUS_RX_BUSY, pulp_read32(UART_REG_BASE(channel) +
							UART_STATUS_OFFSET));
}

/**
 * @brief Check if the data in the data register is valid. This is used in
 * interrupt and polling based flows, bypassing the dma functionality.
 *
 * @param channel uart channel number
 */
static inline int hal_uart_rx_data_valid(int channel)
{
	return REG_GET(UART_VALID_READY,
		       pulp_read32(UART_REG_BASE(channel) + UART_VALID_OFFSET));
}

/**
 * @brief Read the data in the data register. Only do this if signaled valid in
 * the valid register. Automatically clear valid register after read.
 *
 * @param channel uart channel number
 */

static inline int hal_uart_rx_data(int channel)
{
	return REG_GET(UART_DATA,
		       pulp_read32(UART_REG_BASE(channel) + UART_DATA_OFFSET));
}

/**
 * @brief Read the rx overflow register. This signals whether the rx buffer
 * overflowed.
 *
 * @param channel uart channel number
 */
static inline int hal_uart_rx_overflow(int channel)
{
	return REG_GET(UART_ERROR_RX_ERR_OVERFLOW,
		       pulp_read32(UART_REG_BASE(channel) + UART_ERROR_OFFSET));
}

/**
 * @brief Clear the internal rx buffer. This can be called when the rx buffer
 * has signaled an overflow condition to drop stale data.
 *
 * @param channel uart channel number
 */
static inline void hal_uart_clear_rx_fifo(int channel)
{
	uint32_t val = pulp_read32(UART_REG_BASE(channel) + UART_SETUP_OFFSET);
	/* toggle clean bit to clear rx fifo */
	val |= ~REG_SET(UART_SETUP_CLEAN_FIFO, 1);
	pulp_write32(UART_REG_BASE(channel) + UART_SETUP_OFFSET, val);

	val &= ~REG_SET(UART_SETUP_CLEAN_FIFO, 1);
	pulp_write32(UART_REG_BASE(channel) + UART_SETUP_OFFSET, val);
}

#endif
