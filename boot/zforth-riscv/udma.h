/*
 * Copyright (C) 2021 ETH Zurich, University of Bologna
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

#ifndef __UDMA_H__
#define __UDMA_H__

#include <stdint.h>

/* make sure the user really thinks about these values */

#ifndef UART_BAUDRATE
#error "UART_BAUDRATE is not defined. Required for ZFORTH interpreter."
#endif

#ifndef PERIPH_FREQUENCY
#error "PERIPH_FREQUENCY is not defined. Required for driving UART correctly \
when using ZFORTH interpreter."
#endif

void uart_wait_tx_done(int periph);

int uart_open(int uart_id, int baudrate);

void uart_close(int uart_id);

int uart_write(int uart_id, void *buffer, uint32_t size);

int uart_read(int uart_id, void *buffer, uint32_t size);

int uart_read_poll(int uart_id, void *buffer, uint32_t size);

int uart_read_char(int uart_id);


#endif
