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
 *
 * Title: io_mux.c
 * Author: Manuel Eggimann  <meggimann@iis.ee.ethz.ch>
 * Date: 25.08.2021
 *
 * Description: Implementation for Siracusa's pad control IP driver
 */

#include "io_mux.h"
#include "bitfield.h"

#include "config.h"
#include "hal/pulp.h"
#include "archi/pulp.h"

void io_mux_config_set(io_mux_pad_e pad, io_mux_cfg_t const *cfg) {
  const uint32_t cfg_addr = ARCHI_PAD_CFG_ADDR + pad*IO_MUX_PAD_REG_SEPARATION + IO_MUX_PAD_CFG_REG_OFFSET;
  uint32_t reg = pulp_read32(cfg_addr);
  reg = bitfield_bit32_write(reg, PULPISSIMO_PADFRAME_ALL_PADS_CONFIG_PAD_IO00_CFG_TX_EN_BIT, cfg->tx_en != 0);
  reg = bitfield_bit32_write(reg, PULPISSIMO_PADFRAME_ALL_PADS_CONFIG_PAD_IO00_CFG_RX_EN_BIT, cfg->rx_en != 0);
  reg = bitfield_bit32_write(reg, PULPISSIMO_PADFRAME_ALL_PADS_CONFIG_PAD_IO00_CFG_PULL_EN_BIT, cfg->pull_cfg != IO_MUX_NO_PULL);
  pulp_write32(cfg_addr, reg);
}

void io_mux_config_get(io_mux_pad_e pad, io_mux_cfg_t *cfg) {
  const uint32_t cfg_addr = ARCHI_PAD_CFG_ADDR + pad*IO_MUX_PAD_REG_SEPARATION + IO_MUX_PAD_CFG_REG_OFFSET;
  const uint32_t reg = pulp_read32(cfg_addr);
  uint8_t pull_en;
  cfg->tx_en = bitfield_bit32_read(reg, PULPISSIMO_PADFRAME_ALL_PADS_CONFIG_PAD_IO00_CFG_TX_EN_BIT);
  cfg->rx_en = bitfield_bit32_read(reg, PULPISSIMO_PADFRAME_ALL_PADS_CONFIG_PAD_IO00_CFG_RX_EN_BIT);
  pull_en = bitfield_bit32_read(reg, PULPISSIMO_PADFRAME_ALL_PADS_CONFIG_PAD_IO00_CFG_PULL_EN_BIT);
  cfg->pull_cfg = pull_en? IO_MUX_PULL_EN : IO_MUX_NO_PULL;
}

void io_mux_mode_set(io_mux_pad_e pad, io_mux_mode_e mode) {
  const uint32_t cfg_addr = ARCHI_PAD_CFG_ADDR + pad*IO_MUX_PAD_REG_SEPARATION + IO_MUX_PAD_MUX_SEL_REG_OFFSET;
  uint32_t reg = pulp_read32(cfg_addr);
  reg = bitfield_field32_write(reg, PULPISSIMO_PADFRAME_ALL_PADS_CONFIG_PAD_IO00_MUX_SEL_PAD_IO00_MUX_SEL_FIELD, mode);
  pulp_write32(cfg_addr, reg);
}

io_mux_mode_e io_mux_mode_get(io_mux_pad_e pad) {
  const uint32_t cfg_addr = ARCHI_PAD_CFG_ADDR + pad*IO_MUX_PAD_REG_SEPARATION + IO_MUX_PAD_MUX_SEL_REG_OFFSET;
  const uint32_t reg = pulp_read32(cfg_addr);
  return bitfield_field32_read(reg, PULPISSIMO_PADFRAME_ALL_PADS_CONFIG_PAD_IO00_MUX_SEL_PAD_IO00_MUX_SEL_FIELD);
}
