
/* THIS FILE HAS BEEN GENERATED, DO NOT MODIFY IT.
 */

/*
 * Copyright (C) 2018 ETH Zurich, University of Bologna
 * and GreenWaves Technologies
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

#ifndef __INCLUDE_ARCHI_UDMA_I2S_V3_UDMA_I2S_V3_GVSOC_H__
#define __INCLUDE_ARCHI_UDMA_I2S_V3_UDMA_I2S_V3_GVSOC_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS STRUCTS
//

#ifdef __GVSOC__

class vp_udma_i2s_i2s_rx_saddr : public vp::reg_32
{
public:
  inline void rx_saddr_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_RX_SADDR_RX_SADDR_BIT, UDMA_I2S_I2S_RX_SADDR_RX_SADDR_WIDTH); }
  inline uint32_t rx_saddr_get() { return this->get_field(UDMA_I2S_I2S_RX_SADDR_RX_SADDR_BIT, UDMA_I2S_I2S_RX_SADDR_RX_SADDR_WIDTH); }
};

class vp_udma_i2s_i2s_rx_size : public vp::reg_32
{
public:
  inline void rx_size_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_RX_SIZE_RX_SIZE_BIT, UDMA_I2S_I2S_RX_SIZE_RX_SIZE_WIDTH); }
  inline uint32_t rx_size_get() { return this->get_field(UDMA_I2S_I2S_RX_SIZE_RX_SIZE_BIT, UDMA_I2S_I2S_RX_SIZE_RX_SIZE_WIDTH); }
};

class vp_udma_i2s_i2s_rx_cfg : public vp::reg_32
{
public:
  inline void continous_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_RX_CFG_CONTINOUS_BIT, UDMA_I2S_I2S_RX_CFG_CONTINOUS_WIDTH); }
  inline uint32_t continous_get() { return this->get_field(UDMA_I2S_I2S_RX_CFG_CONTINOUS_BIT, UDMA_I2S_I2S_RX_CFG_CONTINOUS_WIDTH); }
  inline void datasize_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_RX_CFG_DATASIZE_BIT, UDMA_I2S_I2S_RX_CFG_DATASIZE_WIDTH); }
  inline uint32_t datasize_get() { return this->get_field(UDMA_I2S_I2S_RX_CFG_DATASIZE_BIT, UDMA_I2S_I2S_RX_CFG_DATASIZE_WIDTH); }
  inline void en_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_RX_CFG_EN_BIT, UDMA_I2S_I2S_RX_CFG_EN_WIDTH); }
  inline uint32_t en_get() { return this->get_field(UDMA_I2S_I2S_RX_CFG_EN_BIT, UDMA_I2S_I2S_RX_CFG_EN_WIDTH); }
  inline void clr_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_RX_CFG_CLR_BIT, UDMA_I2S_I2S_RX_CFG_CLR_WIDTH); }
  inline uint32_t clr_get() { return this->get_field(UDMA_I2S_I2S_RX_CFG_CLR_BIT, UDMA_I2S_I2S_RX_CFG_CLR_WIDTH); }
  inline void pending_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_RX_CFG_PENDING_BIT, UDMA_I2S_I2S_RX_CFG_PENDING_WIDTH); }
  inline uint32_t pending_get() { return this->get_field(UDMA_I2S_I2S_RX_CFG_PENDING_BIT, UDMA_I2S_I2S_RX_CFG_PENDING_WIDTH); }
};

class vp_udma_i2s_i2s_tx_saddr : public vp::reg_32
{
public:
  inline void tx_saddr_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_TX_SADDR_TX_SADDR_BIT, UDMA_I2S_I2S_TX_SADDR_TX_SADDR_WIDTH); }
  inline uint32_t tx_saddr_get() { return this->get_field(UDMA_I2S_I2S_TX_SADDR_TX_SADDR_BIT, UDMA_I2S_I2S_TX_SADDR_TX_SADDR_WIDTH); }
};

class vp_udma_i2s_i2s_tx_size : public vp::reg_32
{
public:
  inline void tx_size_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_TX_SIZE_TX_SIZE_BIT, UDMA_I2S_I2S_TX_SIZE_TX_SIZE_WIDTH); }
  inline uint32_t tx_size_get() { return this->get_field(UDMA_I2S_I2S_TX_SIZE_TX_SIZE_BIT, UDMA_I2S_I2S_TX_SIZE_TX_SIZE_WIDTH); }
};

class vp_udma_i2s_i2s_tx_cfg : public vp::reg_32
{
public:
  inline void continous_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_TX_CFG_CONTINOUS_BIT, UDMA_I2S_I2S_TX_CFG_CONTINOUS_WIDTH); }
  inline uint32_t continous_get() { return this->get_field(UDMA_I2S_I2S_TX_CFG_CONTINOUS_BIT, UDMA_I2S_I2S_TX_CFG_CONTINOUS_WIDTH); }
  inline void datasize_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_TX_CFG_DATASIZE_BIT, UDMA_I2S_I2S_TX_CFG_DATASIZE_WIDTH); }
  inline uint32_t datasize_get() { return this->get_field(UDMA_I2S_I2S_TX_CFG_DATASIZE_BIT, UDMA_I2S_I2S_TX_CFG_DATASIZE_WIDTH); }
  inline void en_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_TX_CFG_EN_BIT, UDMA_I2S_I2S_TX_CFG_EN_WIDTH); }
  inline uint32_t en_get() { return this->get_field(UDMA_I2S_I2S_TX_CFG_EN_BIT, UDMA_I2S_I2S_TX_CFG_EN_WIDTH); }
  inline void clr_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_TX_CFG_CLR_BIT, UDMA_I2S_I2S_TX_CFG_CLR_WIDTH); }
  inline uint32_t clr_get() { return this->get_field(UDMA_I2S_I2S_TX_CFG_CLR_BIT, UDMA_I2S_I2S_TX_CFG_CLR_WIDTH); }
  inline void pending_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_TX_CFG_PENDING_BIT, UDMA_I2S_I2S_TX_CFG_PENDING_WIDTH); }
  inline uint32_t pending_get() { return this->get_field(UDMA_I2S_I2S_TX_CFG_PENDING_BIT, UDMA_I2S_I2S_TX_CFG_PENDING_WIDTH); }
};

class vp_udma_i2s_i2s_clkcfg_setup : public vp::reg_32
{
public:
  inline void master_clk_div_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_DIV_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_DIV_WIDTH); }
  inline uint32_t master_clk_div_get() { return this->get_field(UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_DIV_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_DIV_WIDTH); }
  inline void slave_clk_div_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_DIV_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_DIV_WIDTH); }
  inline uint32_t slave_clk_div_get() { return this->get_field(UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_DIV_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_DIV_WIDTH); }
  inline void common_clk_div_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_CLKCFG_SETUP_COMMON_CLK_DIV_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_COMMON_CLK_DIV_WIDTH); }
  inline uint32_t common_clk_div_get() { return this->get_field(UDMA_I2S_I2S_CLKCFG_SETUP_COMMON_CLK_DIV_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_COMMON_CLK_DIV_WIDTH); }
  inline void slave_clk_en_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_EN_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_EN_WIDTH); }
  inline uint32_t slave_clk_en_get() { return this->get_field(UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_EN_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_EN_WIDTH); }
  inline void master_clk_en_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_EN_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_EN_WIDTH); }
  inline uint32_t master_clk_en_get() { return this->get_field(UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_EN_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_EN_WIDTH); }
  inline void pdm_clk_en_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_CLKCFG_SETUP_PDM_CLK_EN_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_PDM_CLK_EN_WIDTH); }
  inline uint32_t pdm_clk_en_get() { return this->get_field(UDMA_I2S_I2S_CLKCFG_SETUP_PDM_CLK_EN_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_PDM_CLK_EN_WIDTH); }
  inline void slave_ext_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_EXT_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_EXT_WIDTH); }
  inline uint32_t slave_ext_get() { return this->get_field(UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_EXT_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_EXT_WIDTH); }
  inline void slave_num_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_NUM_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_NUM_WIDTH); }
  inline uint32_t slave_num_get() { return this->get_field(UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_NUM_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_NUM_WIDTH); }
  inline void master_ext_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_EXT_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_EXT_WIDTH); }
  inline uint32_t master_ext_get() { return this->get_field(UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_EXT_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_EXT_WIDTH); }
  inline void master_num_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_NUM_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_NUM_WIDTH); }
  inline uint32_t master_num_get() { return this->get_field(UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_NUM_BIT, UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_NUM_WIDTH); }
};

class vp_udma_i2s_i2s_slv_setup : public vp::reg_32
{
public:
  inline void slave_words_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_SLV_SETUP_SLAVE_WORDS_BIT, UDMA_I2S_I2S_SLV_SETUP_SLAVE_WORDS_WIDTH); }
  inline uint32_t slave_words_get() { return this->get_field(UDMA_I2S_I2S_SLV_SETUP_SLAVE_WORDS_BIT, UDMA_I2S_I2S_SLV_SETUP_SLAVE_WORDS_WIDTH); }
  inline void slave_bits_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_SLV_SETUP_SLAVE_BITS_BIT, UDMA_I2S_I2S_SLV_SETUP_SLAVE_BITS_WIDTH); }
  inline uint32_t slave_bits_get() { return this->get_field(UDMA_I2S_I2S_SLV_SETUP_SLAVE_BITS_BIT, UDMA_I2S_I2S_SLV_SETUP_SLAVE_BITS_WIDTH); }
  inline void slave_lsb_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_SLV_SETUP_SLAVE_LSB_BIT, UDMA_I2S_I2S_SLV_SETUP_SLAVE_LSB_WIDTH); }
  inline uint32_t slave_lsb_get() { return this->get_field(UDMA_I2S_I2S_SLV_SETUP_SLAVE_LSB_BIT, UDMA_I2S_I2S_SLV_SETUP_SLAVE_LSB_WIDTH); }
  inline void slave_2ch_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_SLV_SETUP_SLAVE_2CH_BIT, UDMA_I2S_I2S_SLV_SETUP_SLAVE_2CH_WIDTH); }
  inline uint32_t slave_2ch_get() { return this->get_field(UDMA_I2S_I2S_SLV_SETUP_SLAVE_2CH_BIT, UDMA_I2S_I2S_SLV_SETUP_SLAVE_2CH_WIDTH); }
  inline void slave_en_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_SLV_SETUP_SLAVE_EN_BIT, UDMA_I2S_I2S_SLV_SETUP_SLAVE_EN_WIDTH); }
  inline uint32_t slave_en_get() { return this->get_field(UDMA_I2S_I2S_SLV_SETUP_SLAVE_EN_BIT, UDMA_I2S_I2S_SLV_SETUP_SLAVE_EN_WIDTH); }
};

class vp_udma_i2s_i2s_mst_setup : public vp::reg_32
{
public:
  inline void master_words_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_MST_SETUP_MASTER_WORDS_BIT, UDMA_I2S_I2S_MST_SETUP_MASTER_WORDS_WIDTH); }
  inline uint32_t master_words_get() { return this->get_field(UDMA_I2S_I2S_MST_SETUP_MASTER_WORDS_BIT, UDMA_I2S_I2S_MST_SETUP_MASTER_WORDS_WIDTH); }
  inline void master_bits_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_MST_SETUP_MASTER_BITS_BIT, UDMA_I2S_I2S_MST_SETUP_MASTER_BITS_WIDTH); }
  inline uint32_t master_bits_get() { return this->get_field(UDMA_I2S_I2S_MST_SETUP_MASTER_BITS_BIT, UDMA_I2S_I2S_MST_SETUP_MASTER_BITS_WIDTH); }
  inline void master_lsb_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_MST_SETUP_MASTER_LSB_BIT, UDMA_I2S_I2S_MST_SETUP_MASTER_LSB_WIDTH); }
  inline uint32_t master_lsb_get() { return this->get_field(UDMA_I2S_I2S_MST_SETUP_MASTER_LSB_BIT, UDMA_I2S_I2S_MST_SETUP_MASTER_LSB_WIDTH); }
  inline void master_2ch_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_MST_SETUP_MASTER_2CH_BIT, UDMA_I2S_I2S_MST_SETUP_MASTER_2CH_WIDTH); }
  inline uint32_t master_2ch_get() { return this->get_field(UDMA_I2S_I2S_MST_SETUP_MASTER_2CH_BIT, UDMA_I2S_I2S_MST_SETUP_MASTER_2CH_WIDTH); }
  inline void master_en_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_MST_SETUP_MASTER_EN_BIT, UDMA_I2S_I2S_MST_SETUP_MASTER_EN_WIDTH); }
  inline uint32_t master_en_get() { return this->get_field(UDMA_I2S_I2S_MST_SETUP_MASTER_EN_BIT, UDMA_I2S_I2S_MST_SETUP_MASTER_EN_WIDTH); }
};

class vp_udma_i2s_i2s_pdm_setup : public vp::reg_32
{
public:
  inline void pdm_shift_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_PDM_SETUP_PDM_SHIFT_BIT, UDMA_I2S_I2S_PDM_SETUP_PDM_SHIFT_WIDTH); }
  inline uint32_t pdm_shift_get() { return this->get_field(UDMA_I2S_I2S_PDM_SETUP_PDM_SHIFT_BIT, UDMA_I2S_I2S_PDM_SETUP_PDM_SHIFT_WIDTH); }
  inline void pdm_decimation_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_PDM_SETUP_PDM_DECIMATION_BIT, UDMA_I2S_I2S_PDM_SETUP_PDM_DECIMATION_WIDTH); }
  inline uint32_t pdm_decimation_get() { return this->get_field(UDMA_I2S_I2S_PDM_SETUP_PDM_DECIMATION_BIT, UDMA_I2S_I2S_PDM_SETUP_PDM_DECIMATION_WIDTH); }
  inline void pdm_mode_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_PDM_SETUP_PDM_MODE_BIT, UDMA_I2S_I2S_PDM_SETUP_PDM_MODE_WIDTH); }
  inline uint32_t pdm_mode_get() { return this->get_field(UDMA_I2S_I2S_PDM_SETUP_PDM_MODE_BIT, UDMA_I2S_I2S_PDM_SETUP_PDM_MODE_WIDTH); }
  inline void pdm_en_set(uint32_t value) { this->set_field(value, UDMA_I2S_I2S_PDM_SETUP_PDM_EN_BIT, UDMA_I2S_I2S_PDM_SETUP_PDM_EN_WIDTH); }
  inline uint32_t pdm_en_get() { return this->get_field(UDMA_I2S_I2S_PDM_SETUP_PDM_EN_BIT, UDMA_I2S_I2S_PDM_SETUP_PDM_EN_WIDTH); }
};

#endif

#endif
