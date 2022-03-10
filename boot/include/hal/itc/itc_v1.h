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

#ifndef __HAL_ITC_ITC_V1_H__
#define __HAL_ITC_ITC_V1_H__

#include "hal/pulp.h" 
#include "hal/pulp_io.h" 
#include "archi/itc/itc_v1.h"


static inline void hal_itc_enable_value_set(unsigned int mask) {
  pulp_write32(ARCHI_FC_ITC_ADDR + ITC_MASK_OFFSET, mask);
}

static inline unsigned int hal_itc_enable_value_get() {
  return pulp_read32(ARCHI_FC_ITC_ADDR + ITC_MASK_OFFSET);
}

static inline void hal_itc_enable_set(unsigned int mask) {
  pulp_write32(ARCHI_FC_ITC_ADDR + ITC_MASK_SET_OFFSET, mask);
}

static inline void hal_itc_enable_clr(unsigned int mask) {
  pulp_write32(ARCHI_FC_ITC_ADDR + ITC_MASK_CLR_OFFSET, mask);
}


static inline void hal_itc_ack_value_set(unsigned int mask) {
  pulp_write32(ARCHI_FC_ITC_ADDR + ITC_ACK_OFFSET, mask);
}

static inline unsigned int hal_itc_ack_value_get() {
  return pulp_read32(ARCHI_FC_ITC_ADDR + ITC_ACK_OFFSET);
}

static inline void hal_itc_ack_set(unsigned int mask) {
  pulp_write32(ARCHI_FC_ITC_ADDR + ITC_ACK_SET_OFFSET, mask);
}

static inline void hal_itc_ack_clr(unsigned int mask) {
  pulp_write32(ARCHI_FC_ITC_ADDR + ITC_ACK_CLR_OFFSET, mask);
}



static inline void hal_itc_status_value_set(unsigned int mask) {
  pulp_write32(ARCHI_FC_ITC_ADDR + ITC_STATUS_OFFSET, mask);
}

static inline void hal_itc_status_value_set_remote(unsigned int mask) {
  pulp_write32(ARCHI_FC_ITC_ADDR + ITC_STATUS_OFFSET, mask);
}

static inline unsigned int hal_itc_status_value_get() {
  return pulp_read32(ARCHI_FC_ITC_ADDR + ITC_STATUS_OFFSET);
}

static inline void hal_itc_status_set(unsigned int mask) {
  pulp_write32(ARCHI_FC_ITC_ADDR + ITC_STATUS_SET_OFFSET, mask);
}

static inline void hal_itc_status_clr(unsigned int mask) {
  pulp_write32(ARCHI_FC_ITC_ADDR + ITC_STATUS_CLR_OFFSET, mask);
}


static inline unsigned int hal_itc_fifo_pop() {
  return pulp_read32(ARCHI_FC_ITC_ADDR + ITC_FIFO_OFFSET);
}


static inline void hal_itc_wait_for_interrupt() {
  asm volatile ("wfi");
}


static inline void hal_itc_wait_for_event_noirq(unsigned int mask) {

  int end = 0;
  do {

    unsigned int state = hal_irq_disable();
    if ((hal_itc_status_value_get() & mask) == 0) {
      hal_itc_enable_set(mask);
      asm volatile ("wfi");
      hal_itc_enable_clr(mask);
    } else {
      hal_itc_status_clr(mask);
      end = 1;
    }
    hal_irq_restore(state);
  } while (!end);
}


static inline void hal_itc_wait_for_event(unsigned int mask) {
  hal_itc_wait_for_event_noirq(mask);
}



#endif
