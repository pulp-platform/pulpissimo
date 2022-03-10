/*
 * Copyright (C) 2019 ETH Zurich, University of Bologna
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

#include "config.h"
#include "pulp.h"
#include <stddef.h>
/* #include "libc.h" */

#include "udma.h"

void *memcpy(void *dest, const void *src, size_t n);

void uart_wait_tx_done(int periph)
{
	/* we don't care if the uart is done, we just want to know whether we
	 * can queue another transfer. Thats why don't also poll for
	 * hal_uart_tx_busy() here. */

	while (!plp_udma_canEnqueue(
		UDMA_UART_TX_ADDR(periph - ARCHI_UDMA_UART_ID(0)))) {
	}
}


static void uart_wait_rx_done(int periph)
{
	while (plp_udma_busy(
		UDMA_UART_RX_ADDR(periph - ARCHI_UDMA_UART_ID(0)))) {
	}
}


static void uart_setup(int channel, int baudrate)
{
	int div = (PERIPH_FREQUENCY + baudrate / 2) / baudrate;

	hal_uart_setup(channel - ARCHI_UDMA_UART_ID(0), 0, 1, div - 1);
}


int uart_open(int uart_id, int baudrate)
{
	int periph_id = ARCHI_UDMA_UART_ID(uart_id);
	int channel = UDMA_EVENT_ID(periph_id);

	plp_udma_cg_set(plp_udma_cg_get() | (1 << periph_id));

	soc_eu_fcEventMask_setEvent(channel);
	soc_eu_fcEventMask_setEvent(channel + 1);

	uart_setup(periph_id, baudrate);

	return 0;
}


void uart_close(int uart_id)
{
	int periph_id = ARCHI_UDMA_UART_ID(uart_id);
	/* int channel = UDMA_EVENT_ID(periph_id); */

	uart_wait_tx_done(periph_id);

	hal_uart_disable(periph_id);

	plp_udma_cg_set(plp_udma_cg_get() & ~(1 << periph_id));
}


static int which_buf = 0;
/* note that this function only works for size < 128. This is true for this
 * codebase */
int uart_write(int uart_id, void *buffer, uint32_t size)
{
	int periph_id = ARCHI_UDMA_UART_ID(uart_id);
	int channel = UDMA_EVENT_ID(periph_id) + 1;

	unsigned int base = hal_udma_channel_base(channel);

	/* two buffers: starting from 0 and 128 */
	static char copyout_buf[256] = {0};

	/* make sure we can issue a dma transfer */
	uart_wait_tx_done(periph_id);
	/* copy to tmp buffer so that when we later functions don't clobber our
	 * buffer */
	memcpy(copyout_buf + which_buf * 128, buffer, size);

	plp_udma_enqueue(base, (int)(copyout_buf + which_buf * 128), size,
			 UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_8);

	which_buf = !which_buf;

	return 0;
}


/* This is doesn't work for small size values, such as size=1. Use
 * uart_read_char() or uart_read_poll(). */

int uart_read(int uart_id, void *buffer, uint32_t size)
{
	int periph_id = ARCHI_UDMA_UART_ID(uart_id);
	int channel = UDMA_EVENT_ID(periph_id);

	unsigned int base = hal_udma_channel_base(channel);

	plp_udma_enqueue(base, (int)buffer, size,
			 UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_8);

	uart_wait_rx_done(periph_id);

	return 0;
}

int uart_read_poll(int uart_id, void *buffer, uint32_t size)
{
	char *ptr = buffer;
	for (uint32_t i = 0; i < size; i++)
		ptr[i] = uart_read_char(uart_id);
	return 0;
}

int uart_read_char(int uart_id)
{
	/* We need to clear the fifo buffer if we have an overflow,
	 * otherwise we read stale data. We rather drop it. */
	if (hal_uart_rx_overflow(uart_id))
		hal_uart_clear_rx_fifo(uart_id);

	/* TODO: channel number computation */
	while (!hal_uart_rx_data_valid(uart_id))
		;
	return hal_uart_rx_data(uart_id);
}
