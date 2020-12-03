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

#ifndef __ARCHI_UDMA_UDMA_UART_V1_H__
#define __ARCHI_UDMA_UDMA_UART_V1_H__

// UART custom registers offset definition
#define UART_STATUS_OFFSET               (0x00)
#define UART_SETUP_OFFSET                (0x04)

// UART custom registers bitfields offset, mask, value definition
// STATUS
#define UART_TX_BUSY_OFFSET   0
#define UART_TX_BUSY_WIDTH    1
#define UART_TX_BUSY_MASK   (0x1 << UART_TX_BUSY_OFFSET)
#define UART_TX_BUSY      (0x1 << UART_TX_BUSY_OFFSET)

#define UART_RX_BUSY_OFFSET   1
#define UART_RX_BUSY_WIDTH    1
#define UART_RX_BUSY_MASK   (0x1 << UART_RX_BUSY_OFFSET)
#define UART_RX_BUSY      (0x1 << UART_RX_BUSY_OFFSET)

#define UART_RX_PE_OFFSET   2
#define UART_RX_PE_WIDTH    1
#define UART_RX_PE_MASK     (0x1 << UART_RX_PE_OFFSET)
#define UART_RX_PE      (0x1 << UART_RX_PE_OFFSET)

// SETUP
#define UART_PARITY_OFFSET    0
#define UART_PARITY_WIDTH   1
#define UART_PARITY_MASK    (0x1 << UART_PARITY_OFFSET)
#define UART_PARITY_DIS     (0 << UART_PARITY_OFFSET)
#define UART_PARITY_ENA     (1 << UART_PARITY_OFFSET)

#define UART_BIT_LENGTH_OFFSET    1
#define UART_BIT_LENGTH_WIDTH   2
#define UART_BIT_LENGTH_MASK    (0x3 << UART_BIT_LENGTH_OFFSET)
#define UART_BIT_LENGTH_5   (0 << UART_BIT_LENGTH_OFFSET)
#define UART_BIT_LENGTH_6   (1 << UART_BIT_LENGTH_OFFSET)
#define UART_BIT_LENGTH_7   (2 << UART_BIT_LENGTH_OFFSET)
#define UART_BIT_LENGTH_8   (3 << UART_BIT_LENGTH_OFFSET)

#define UART_STOP_BITS_OFFSET   3
#define UART_STOP_BITS_WIDTH    1
#define UART_STOP_BITS_MASK   (0x1 << UART_STOP_BITS_OFFSET)
#define UART_STOP_BITS_1    (0 << UART_STOP_BITS_OFFSET)
#define UART_STOP_BITS_2    (1 << UART_STOP_BITS_OFFSET)

#define UART_TX_OFFSET    8
#define UART_TX_WIDTH   1
#define UART_TX_MASK    (0x1 << UART_TX_OFFSET)
#define UART_TX_DIS   (0 << UART_TX_OFFSET)
#define UART_TX_ENA   (1 << UART_TX_OFFSET)

#define UART_RX_OFFSET    9
#define UART_RX_WIDTH   1
#define UART_RX_MASK    (0x1 << UART_RX_OFFSET)
#define UART_RX_DIS   (0 << UART_RX_OFFSET)
#define UART_RX_ENA   (1 << UART_RX_OFFSET)

#define UART_CLKDIV_OFFSET    16
#define UART_CLKDIV_WIDTH   16
#define UART_CLKDIV_MASK    (0xffff << UART_CLKDIV_OFFSET)
#define UART_CLKDIV(val)    (val << UART_CLKDIV_OFFSET)

#define ARCHI_UDMA_UART_RX_EVT           0
#define ARCHI_UDMA_UART_TX_EVT           1

#endif