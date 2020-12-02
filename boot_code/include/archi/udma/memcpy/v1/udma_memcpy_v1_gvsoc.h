
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

#ifndef __INCLUDE_ARCHI_UDMA_MEMCPY_V1_UDMA_MEMCPY_V1_GVSOC_H__
#define __INCLUDE_ARCHI_UDMA_MEMCPY_V1_UDMA_MEMCPY_V1_GVSOC_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS STRUCTS
//

#ifdef __GVSOC__

class vp_udma_memcpy_rx_saddr : public vp::reg_32
{
public:
  inline void rx_saddr_set(uint32_t value) { this->set_field(value, UDMA_MEMCPY_RX_SADDR_RX_SADDR_BIT, UDMA_MEMCPY_RX_SADDR_RX_SADDR_WIDTH); }
  inline uint32_t rx_saddr_get() { return this->get_field(UDMA_MEMCPY_RX_SADDR_RX_SADDR_BIT, UDMA_MEMCPY_RX_SADDR_RX_SADDR_WIDTH); }
};

class vp_udma_memcpy_rx_size : public vp::reg_32
{
public:
  inline void rx_size_set(uint32_t value) { this->set_field(value, UDMA_MEMCPY_RX_SIZE_RX_SIZE_BIT, UDMA_MEMCPY_RX_SIZE_RX_SIZE_WIDTH); }
  inline uint32_t rx_size_get() { return this->get_field(UDMA_MEMCPY_RX_SIZE_RX_SIZE_BIT, UDMA_MEMCPY_RX_SIZE_RX_SIZE_WIDTH); }
};

class vp_udma_memcpy_rx_cfg : public vp::reg_32
{
public:
  inline void continous_set(uint32_t value) { this->set_field(value, UDMA_MEMCPY_RX_CFG_CONTINOUS_BIT, UDMA_MEMCPY_RX_CFG_CONTINOUS_WIDTH); }
  inline uint32_t continous_get() { return this->get_field(UDMA_MEMCPY_RX_CFG_CONTINOUS_BIT, UDMA_MEMCPY_RX_CFG_CONTINOUS_WIDTH); }
  inline void en_set(uint32_t value) { this->set_field(value, UDMA_MEMCPY_RX_CFG_EN_BIT, UDMA_MEMCPY_RX_CFG_EN_WIDTH); }
  inline uint32_t en_get() { return this->get_field(UDMA_MEMCPY_RX_CFG_EN_BIT, UDMA_MEMCPY_RX_CFG_EN_WIDTH); }
  inline void clr_set(uint32_t value) { this->set_field(value, UDMA_MEMCPY_RX_CFG_CLR_BIT, UDMA_MEMCPY_RX_CFG_CLR_WIDTH); }
  inline uint32_t clr_get() { return this->get_field(UDMA_MEMCPY_RX_CFG_CLR_BIT, UDMA_MEMCPY_RX_CFG_CLR_WIDTH); }
  inline void pending_set(uint32_t value) { this->set_field(value, UDMA_MEMCPY_RX_CFG_PENDING_BIT, UDMA_MEMCPY_RX_CFG_PENDING_WIDTH); }
  inline uint32_t pending_get() { return this->get_field(UDMA_MEMCPY_RX_CFG_PENDING_BIT, UDMA_MEMCPY_RX_CFG_PENDING_WIDTH); }
};

class vp_udma_memcpy_tx_saddr : public vp::reg_32
{
public:
  inline void tx_saddr_set(uint32_t value) { this->set_field(value, UDMA_MEMCPY_TX_SADDR_TX_SADDR_BIT, UDMA_MEMCPY_TX_SADDR_TX_SADDR_WIDTH); }
  inline uint32_t tx_saddr_get() { return this->get_field(UDMA_MEMCPY_TX_SADDR_TX_SADDR_BIT, UDMA_MEMCPY_TX_SADDR_TX_SADDR_WIDTH); }
};

class vp_udma_memcpy_tx_size : public vp::reg_32
{
public:
  inline void tx_size_set(uint32_t value) { this->set_field(value, UDMA_MEMCPY_TX_SIZE_TX_SIZE_BIT, UDMA_MEMCPY_TX_SIZE_TX_SIZE_WIDTH); }
  inline uint32_t tx_size_get() { return this->get_field(UDMA_MEMCPY_TX_SIZE_TX_SIZE_BIT, UDMA_MEMCPY_TX_SIZE_TX_SIZE_WIDTH); }
};

class vp_udma_memcpy_tx_cfg : public vp::reg_32
{
public:
  inline void continous_set(uint32_t value) { this->set_field(value, UDMA_MEMCPY_TX_CFG_CONTINOUS_BIT, UDMA_MEMCPY_TX_CFG_CONTINOUS_WIDTH); }
  inline uint32_t continous_get() { return this->get_field(UDMA_MEMCPY_TX_CFG_CONTINOUS_BIT, UDMA_MEMCPY_TX_CFG_CONTINOUS_WIDTH); }
  inline void en_set(uint32_t value) { this->set_field(value, UDMA_MEMCPY_TX_CFG_EN_BIT, UDMA_MEMCPY_TX_CFG_EN_WIDTH); }
  inline uint32_t en_get() { return this->get_field(UDMA_MEMCPY_TX_CFG_EN_BIT, UDMA_MEMCPY_TX_CFG_EN_WIDTH); }
  inline void clr_set(uint32_t value) { this->set_field(value, UDMA_MEMCPY_TX_CFG_CLR_BIT, UDMA_MEMCPY_TX_CFG_CLR_WIDTH); }
  inline uint32_t clr_get() { return this->get_field(UDMA_MEMCPY_TX_CFG_CLR_BIT, UDMA_MEMCPY_TX_CFG_CLR_WIDTH); }
  inline void pending_set(uint32_t value) { this->set_field(value, UDMA_MEMCPY_TX_CFG_PENDING_BIT, UDMA_MEMCPY_TX_CFG_PENDING_WIDTH); }
  inline uint32_t pending_get() { return this->get_field(UDMA_MEMCPY_TX_CFG_PENDING_BIT, UDMA_MEMCPY_TX_CFG_PENDING_WIDTH); }
};

class vp_udma_memcpy_dst_addr : public vp::reg_32
{
public:
  inline void dst_addr_set(uint32_t value) { this->set_field(value, UDMA_MEMCPY_DST_ADDR_DST_ADDR_BIT, UDMA_MEMCPY_DST_ADDR_DST_ADDR_WIDTH); }
  inline uint32_t dst_addr_get() { return this->get_field(UDMA_MEMCPY_DST_ADDR_DST_ADDR_BIT, UDMA_MEMCPY_DST_ADDR_DST_ADDR_WIDTH); }
};

class vp_udma_memcpy_src_addr : public vp::reg_32
{
public:
  inline void src_addr_set(uint32_t value) { this->set_field(value, UDMA_MEMCPY_SRC_ADDR_SRC_ADDR_BIT, UDMA_MEMCPY_SRC_ADDR_SRC_ADDR_WIDTH); }
  inline uint32_t src_addr_get() { return this->get_field(UDMA_MEMCPY_SRC_ADDR_SRC_ADDR_BIT, UDMA_MEMCPY_SRC_ADDR_SRC_ADDR_WIDTH); }
};

class vp_udma_memcpy_mem_sel : public vp::reg_32
{
public:
  inline void mem_sel_set(uint32_t value) { this->set_field(value, UDMA_MEMCPY_MEM_SEL_MEM_SEL_BIT, UDMA_MEMCPY_MEM_SEL_MEM_SEL_WIDTH); }
  inline uint32_t mem_sel_get() { return this->get_field(UDMA_MEMCPY_MEM_SEL_MEM_SEL_BIT, UDMA_MEMCPY_MEM_SEL_MEM_SEL_WIDTH); }
};

#endif

#endif
