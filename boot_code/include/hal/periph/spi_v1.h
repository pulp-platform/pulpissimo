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

#ifndef __HAL_PERIPH_SPI_V1_H__
#define __HAL_PERIPH_SPI_V1_H__

#include "archi/pulp.h"
#include "hal/pulp_io.h"
#include "archi/spim/spi_v1.h"

static inline unsigned int pulp_spi_base() {
  return 0x10000000 + PULP_SPI_OFFSET;
}

static inline void pulp_spi_setup_cmd_addr(unsigned int spiBase, int cmd, int cmdlen, int addr, int addrlen) {
  int cmd_reg;
  cmd_reg = cmd << (32-cmdlen);
  pulp_write32(spiBase + PULP_SPI_REG_SPICMD, cmd_reg);
  pulp_write32(spiBase + PULP_SPI_REG_SPIADR, addr);
  pulp_write32(spiBase + PULP_SPI_REG_SPILEN, (cmdlen & 0x3F) | ((addrlen << 8) & 0x3F00));
}

static inline void pulp_spi_set_datalen(unsigned int spiBase, int datalen) {
  volatile int old_len;
  old_len = pulp_read32(spiBase + PULP_SPI_REG_SPILEN);
  old_len = ((datalen << 16) & 0xFFFF0000) | (old_len & 0xFFFF);
  pulp_write32(spiBase + PULP_SPI_REG_SPILEN, old_len);
}

static inline void pulp_spi_start_transaction(unsigned int spiBase, int trans_type, int csnum) {
  pulp_write32(spiBase + PULP_SPI_REG_STATUS, ((1 << (csnum + 8)) & 0xF00) | ((1 << trans_type) & 0xFF));
}

static inline void pulp_spi_fifo_push(unsigned int spiBase, unsigned int value) {
  pulp_write32(spiBase + PULP_SPI_REG_TXFIFO, value);
}

static inline unsigned int pulp_spi_fifo_pop(unsigned int spiBase) {
  return pulp_read32(spiBase + PULP_SPI_REG_RXFIFO);
}

static inline unsigned int pulp_spi_status(unsigned int spiBase) {
  return pulp_read32(spiBase + PULP_SPI_REG_STATUS);
}


static inline void pulp_spi_intcfg(unsigned int spiBase, unsigned int txThres, unsigned int rxThres, unsigned int txCounter, unsigned int rxCounter, int countEn, int intEn) {
  pulp_write32(spiBase + PULP_SPI_REG_INTCFG, (txThres << 0) | (rxThres << 8) | (txCounter << 16) | (rxCounter << 24) | (countEn << 30) | (intEn << 31));
}

static inline unsigned int pulp_spi_get_div(unsigned int clkdiv)
{
  // The clock div is used to drive a counter which first generates the spi rise
  // and then the spi fall, so the real div is multiplied by 2.
  // Then the counter keeps the last value so the real divider is incremented by 1
  if (clkdiv <= 1) return 0;
  else return clkdiv/2 - 1;
}

static inline void pulp_spi_clkdiv(unsigned int spiBase, unsigned int clkdiv)
{
  pulp_write32(spiBase + PULP_SPI_REG_CLKDIV, clkdiv);
}

#endif
