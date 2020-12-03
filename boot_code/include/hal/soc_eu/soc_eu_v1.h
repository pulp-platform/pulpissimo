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

#ifndef __HAL_SOC_EU_SOC_EU_V1_H__
#define __HAL_SOC_EU_SOC_EU_V1_H__

#include "archi/pulp.h"
#include "archi/soc_eu/soc_eu_v1.h"

static inline void soc_eu_eventMask_set(unsigned int reg, unsigned int value) {
  ARCHI_WRITE(ARCHI_SOC_EU_ADDR, reg, value);
}

static inline unsigned int soc_eu_eventMask_get(unsigned int reg) {
  return ARCHI_READ(ARCHI_SOC_EU_ADDR, reg);
}

static inline void soc_eu_eventMask_reset(unsigned int first_reg) {
  for (int i=0; i<SOC_NB_EVENT_REGS; i++)
  {
    soc_eu_eventMask_set(first_reg + i*4, 0xffffffff);
  }
}

static inline void soc_eu_eventMask_setEvent(int evt, unsigned int lsbReg, unsigned int msbReg) {
  unsigned int reg;
  if (evt >= 32) {
    reg = msbReg;
    evt -= 32;
  } else {
    reg = lsbReg;
  }
  soc_eu_eventMask_set(reg, soc_eu_eventMask_get(reg) & ~(1 << evt));
}

static inline void soc_eu_eventMask_clearEvent(int evt, unsigned int lsbReg, unsigned int msbReg) {
  unsigned int reg;
  if (evt >= 32) {
    reg = msbReg;
    evt -= 32;
  } else {
    reg = lsbReg;
  }
  soc_eu_eventMask_set(reg, soc_eu_eventMask_get(reg) | (1 << evt));
}

static inline void soc_eu_fcEventMask_setEvent(int evt) {
  soc_eu_eventMask_setEvent(evt, SOC_FC_MASK_LSB, SOC_FC_MASK_MSB);
}

static inline void soc_eu_prEventMask_setEvent(int evt) {
  soc_eu_eventMask_setEvent(evt, SOC_PR_MASK_LSB, SOC_PR_MASK_MSB);
}

static inline void soc_eu_clEventMask_setEvent(int clusterId, int evt) {
  soc_eu_eventMask_setEvent(evt, SOC_CL_MASK_LSB, SOC_CL_MASK_MSB);
}

static inline void soc_eu_fcEventMask_clearEvent(int evt) {
  soc_eu_eventMask_clearEvent(evt, SOC_FC_MASK_LSB, SOC_FC_MASK_MSB);
}

static inline void soc_eu_prEventMask_clearEvent(int evt) {
  soc_eu_eventMask_clearEvent(evt, SOC_PR_MASK_LSB, SOC_PR_MASK_MSB);
}

static inline void soc_eu_clEventMask_clearEvent(int clusterId, int evt) {
  soc_eu_eventMask_clearEvent(evt, SOC_CL_MASK_LSB, SOC_CL_MASK_MSB);
}



static inline void soc_eu_genEventMask(unsigned int mask) {
  pulp_write32(ARCHI_SOC_EU_ADDR + SOC_EU_EVENT, mask);
}

#endif
