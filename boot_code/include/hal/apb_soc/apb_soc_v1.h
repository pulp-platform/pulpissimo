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

#ifndef __HAL_APB_SOC_APB_SOC_V1_H__
#define __HAL_APB_SOC_APB_SOC_V1_H__

#include "hal/pulp_io.h"

static inline unsigned int apb_soc_nbCores() {
  return pulp_read16(ARCHI_APB_SOC_CTRL_ADDR + APB_SOC_INFO_CORES_OFFSET);
}

static inline unsigned int apb_soc_nbClusters() {
  return pulp_read16(ARCHI_APB_SOC_CTRL_ADDR + APB_SOC_INFO_CLUSTERS_OFFSET);
}

static inline void apb_soc_set_pin_function(int pinnumber, int function) {
  int old_function;
  int addr;
  old_function = pulp_read32(SOC_CTRL_PADFUN0);
  old_function = old_function & (~(1 << pinnumber));
  old_function = old_function | (function << pinnumber);
  pulp_write32(SOC_CTRL_PADFUN0, old_function);
}

static inline int  apb_soc_get_pin_function(int pinnumber) {
  int old_function;
  old_function = pulp_read32(SOC_CTRL_PADFUN0);
  old_function = (old_function >> pinnumber & 0x01);
  return old_function;
}

static inline void hal_apb_soc_padfun_set(unsigned int id, unsigned int value) {
}

#endif
