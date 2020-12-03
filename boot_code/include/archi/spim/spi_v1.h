/*
 * Copyright (C) 2018 ETH Zurich, University of Bologna
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

#ifndef __ARCHI_SPIM_SPI_V1_H__
#define __ARCHI_SPIM_SPI_V1_H__

#define PULP_SPI_OFFSET       0xA102000

#define PULP_SPI_FIFO_SIZE 8

#define PULP_SPI_QPI    1
#define PULP_SPI_NO_QPI 0

#define PULP_SPI_CMD_RD    0
#define PULP_SPI_CMD_WR    1
#define PULP_SPI_CMD_QRD   2
#define PULP_SPI_CMD_QWR   3
#define PULP_SPI_CMD_SWRST 4

#define PULP_SPI_CSN0 0
#define PULP_SPI_CSN1 1
#define PULP_SPI_CSN2 2
#define PULP_SPI_CSN3 3

#define PULP_SPI_REG_STATUS                ( 0x00 )
#define PULP_SPI_REG_CLKDIV                ( 0x04 )
#define PULP_SPI_REG_SPICMD                ( 0x08 )
#define PULP_SPI_REG_SPIADR                ( 0x0C )
#define PULP_SPI_REG_SPILEN                ( 0x10 )
#define PULP_SPI_REG_SPIDUM                ( 0x14 )
#define PULP_SPI_REG_TXFIFO                ( 0x18 )
#define PULP_SPI_REG_RXFIFO                ( 0x20 )
#define PULP_SPI_REG_INTCFG                ( 0x24 )
#define PULP_SPI_REG_INTSTA                ( 0x28 )

#endif