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

#ifndef __HAL_CLUSTER_CTRL_CLUSTER_CTRL_V2_H__
#define __HAL_CLUSTER_CTRL_CLUSTER_CTRL_V2_H__

#include "archi/cluster_ctrl/cluster_ctrl_v2.h"

static inline void eoc_fetch_enable_base(unsigned int base, unsigned int mask) {
  pulp_write32(base + ARCHI_CLUSTER_CTRL_OFFSET + EOC_FETCH_OFFSET, mask);
}

static inline void eoc_fetch_enable_remote(int cid, unsigned int mask) {
  pulp_write32(ARCHI_CLUSTER_PERIPHERALS_GLOBAL_ADDR(cid) + ARCHI_CLUSTER_CTRL_OFFSET + EOC_FETCH_OFFSET, mask);
}

static inline void eoc_fetch_enable(unsigned int mask) {
  eoc_fetch_enable_base(ARCHI_CLUSTER_ADDR, mask);
}

static inline void hal_cluster_ctrl_eoc_set(int value) {
  pulp_write32(ARCHI_CLUSTER_CTRL_ADDR, value);
}

static inline void plp_ctrl_fetchen_base(unsigned int base, unsigned int mask) {
  pulp_write32(base + ARCHI_CLUSTER_CTRL_OFFSET + EOC_FETCH_OFFSET, mask);
}

static inline void plp_ctrl_fetchen(unsigned int mask) {
  plp_ctrl_fetchen_base(ARCHI_CLUSTER_ADDR, mask);
}

static inline void plp_ctrl_bootaddr_set(unsigned int bootAddr) {
  pulp_write32(ARCHI_CLUSTER_CTRL_ADDR + 0x40, bootAddr);
}

static inline void plp_ctrl_bootaddr_set_remote(int cid, unsigned int bootAddr) {
  pulp_write32(ARCHI_CLUSTER_PERIPHERALS_GLOBAL_ADDR(cid) + ARCHI_CLUSTER_CTRL_OFFSET + 0x40, bootAddr);
}

static inline void plp_ctrl_core_bootaddr_set(int core, unsigned int bootAddr) {
  pulp_write32(ARCHI_CLUSTER_CTRL_ADDR + 0x40 + core*4, bootAddr);
}

static inline void plp_ctrl_core_bootaddr_set_remote(int cid, int core, unsigned int bootAddr) {
  pulp_write32(ARCHI_CLUSTER_PERIPHERALS_GLOBAL_ADDR(cid) + ARCHI_CLUSTER_CTRL_OFFSET + 0x40 + core*4, bootAddr);
}

static inline unsigned int plp_ctrl_bootaddr_get() {
  return pulp_read32(ARCHI_CLUSTER_CTRL_ADDR + 0x40);
}

#endif