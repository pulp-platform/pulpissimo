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

#ifndef __HAL_APB_SOC_APB_SOC_V2_H__
#define __HAL_APB_SOC_APB_SOC_V2_H__

#include "archi/pulp.h"

static inline void apb_soc_bootaddr_set(unsigned int value) {
  pulp_write32(ARCHI_APB_SOC_CTRL_ADDR + APB_SOC_BOOTADDR_OFFSET, value);
}

static inline void apb_soc_status_set(unsigned int value) {
  pulp_write32(ARCHI_APB_SOC_CTRL_ADDR + APB_SOC_CORESTATUS_OFFSET, value | (1<<APB_SOC_STATUS_EOC_BIT));
}

static inline unsigned int apb_soc_nbCores() {
  return pulp_read16(ARCHI_APB_SOC_CTRL_ADDR + APB_SOC_INFO_CORES_OFFSET);
}

static inline unsigned int apb_soc_nbClusters() {
  return pulp_read16(ARCHI_APB_SOC_CTRL_ADDR + APB_SOC_INFO_CLUSTERS_OFFSET);
}



static inline unsigned int hal_apb_soc_padfun_get(unsigned int id) {
  return pulp_read32(ARCHI_APB_SOC_CTRL_ADDR + APB_SOC_PADFUN_OFFSET(id));
}

static inline void hal_apb_soc_padfun_set(unsigned int id, unsigned int value) {
  pulp_write32(ARCHI_APB_SOC_CTRL_ADDR + APB_SOC_PADFUN_OFFSET(id), value);
}

static inline unsigned int hal_apb_soc_padcfg_get(unsigned int id) {
  return pulp_read32(ARCHI_APB_SOC_CTRL_ADDR + APB_SOC_PADCFG_OFFSET(id));
}

static inline void hal_apb_soc_padcfg_set(unsigned int id, unsigned int value) {
  pulp_write32(ARCHI_APB_SOC_CTRL_ADDR + APB_SOC_PADCFG_OFFSET(id), value);
}


static inline void hal_apb_soc_pad_set_function(unsigned int pad, unsigned int func) {
	unsigned int padfunId = APB_SOC_PADFUN_NO(pad);
	unsigned int padBit = APB_SOC_PADFUN_BIT(pad);
	unsigned int oldval = hal_apb_soc_padfun_get(padfunId) & ~(((1<<APB_SOC_PADFUN_SIZE)-1) << padBit);
	unsigned int newVal = oldval | (func << padBit);
	hal_apb_soc_padfun_set(padfunId, newVal);
}

static inline void hal_apb_soc_pad_set_config(unsigned int pad, unsigned int cfg) {
	unsigned int padcfgId = APB_SOC_PADCFG_NO(pad);
	unsigned int padBit = APB_SOC_PADCFG_BIT(pad);
	unsigned int oldval = hal_apb_soc_padcfg_get(padcfgId) & ~(((1<<APB_SOC_PADCFG_SIZE)-1) << padBit);
	unsigned int newVal = oldval | (cfg << padBit);
	hal_apb_soc_padcfg_set(padcfgId, newVal);
}




static inline unsigned int apb_soc_jtag_reg_read() {
  return pulp_read32(ARCHI_APB_SOC_CTRL_ADDR + APB_SOC_JTAG_REG);
}

static inline void apb_soc_jtag_reg_write(unsigned int value) {
  pulp_write32(ARCHI_APB_SOC_CTRL_ADDR + APB_SOC_JTAG_REG, value);
}

static inline unsigned int apb_soc_jtag_reg_ext(unsigned int value) {
  return ARCHI_REG_FIELD_GET(value, APB_SOC_JTAG_REG_EXT_BIT, APB_SOC_JTAG_REG_EXT_WIDTH);
}

static inline unsigned int apb_soc_jtag_reg_loc(unsigned int value) {
  return ARCHI_REG_FIELD_GET(value, APB_SOC_JTAG_REG_LOC_BIT, APB_SOC_JTAG_REG_LOC_WIDTH);
}

#endif
