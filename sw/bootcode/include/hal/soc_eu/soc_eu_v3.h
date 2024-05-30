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

#ifndef __HAL_SOC_EU_SOC_EU_V3_H__
#define __HAL_SOC_EU_SOC_EU_V3_H__

#include "archi/pulp.h"
#include "archi/soc_eu/soc_eu_v3.h"

static inline unsigned int hal_soc_eu_addr(void)
{
  return ARCHI_SOC_EU_ADDR;
}


static inline void soc_eu_eventMask_set(unsigned int reg, unsigned int value) {
  pulp_write32(ARCHI_SOC_EU_ADDR + reg, value);
}

static inline unsigned int soc_eu_eventMask_get(unsigned int reg) {
  return pulp_read32(ARCHI_SOC_EU_ADDR + reg);
}

static inline void soc_eu_eventMask_reset(unsigned int first_reg) {
  for (int i=0; i<SOC_NB_EVENT_REGS; i++)
  {
    soc_eu_eventMask_set(first_reg + i*4, 0xffffffff);
  }
}

static inline void soc_eu_eventMask_setEvent(int evt, unsigned int first_reg) {
  unsigned int reg = first_reg + (evt / 32 * 4);
  evt = evt % 32;
  soc_eu_eventMask_set(reg, soc_eu_eventMask_get(reg) & ~(1 << evt));
}

static inline void soc_eu_eventMask_clearEvent(int evt, unsigned int first_reg) {
  unsigned int reg = first_reg + (evt / 32 * 4);
  evt = evt % 32;
  soc_eu_eventMask_set(reg, soc_eu_eventMask_get(reg) | (1 << evt));
}

static inline void soc_eu_fcEventMask_setEvent(int evt) {
  soc_eu_eventMask_setEvent(evt, SOC_FC_FIRST_MASK);
}

static inline void soc_eu_prEventMask_setEvent(int evt) {
  soc_eu_eventMask_setEvent(evt, SOC_PR_FIRST_MASK);
}

static inline void soc_eu_clEventMask_setEvent(int clusterId, int evt) {
  soc_eu_eventMask_setEvent(evt, SOC_CL_FIRST_MASK);
}

static inline void soc_eu_fcEventMask_clearEvent(int evt) {
  soc_eu_eventMask_clearEvent(evt, SOC_FC_FIRST_MASK);
}

static inline void soc_eu_prEventMask_clearEvent(int evt) {
  soc_eu_eventMask_clearEvent(evt, SOC_PR_FIRST_MASK);
}

static inline void soc_eu_clEventMask_clearEvent(int clusterId, int evt) {
  soc_eu_eventMask_clearEvent(evt, SOC_CL_FIRST_MASK);
}

static inline void soc_eu_genEventMask(unsigned int mask) {
  pulp_write32(ARCHI_SOC_EU_ADDR + SOC_EU_EVENT, mask);
}



/** \brief Select event to be propagated to timer unit event input.
 *
 * \param timer_id Choice timer Low (1) or High (0).
 * \param mask Value on 8 bit to select the event id to be forwarded to the selected timer.
 */
static inline void soc_eu_selEventTimer(unsigned int timer_id, unsigned int mask) {
  pulp_write32 (ARCHI_SOC_EU_ADDR + SOC_TIMER_SEL_HI + timer_id * 4
            ,  (pulp_read32(ARCHI_SOC_EU_ADDR + SOC_TIMER_SEL_HI + timer_id * 4) & ~(SOC_TIMER_SEL_EVT_MASK << SOC_TIMER_SEL_EVT_SHIFT)) 
              | (mask & SOC_TIMER_SEL_EVT_MASK));
}

/** \brief Activation of the event forward to timer feature.
 *
 * \param timer_id Choice timer Low (1) or High (0).
 * \param val Value to enable/disable event forwarding to selected timer.
 */
static inline void soc_eu_setEnableEventTimer(unsigned int timer_id, unsigned int val) {
  pulp_write32 (ARCHI_SOC_EU_ADDR + SOC_TIMER_SEL_HI + timer_id * 4
            ,  (pulp_read32(ARCHI_SOC_EU_ADDR + SOC_TIMER_SEL_HI + timer_id * 4) & ~(1 << SOC_TIMER_SEL_ENABLE_SHIFT)) 
              | val);
}
#endif
