/*
 * Copyright (C) 2018 ETH Zurich, University of Bologna and
 * GreenWaves Technologies
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

#ifndef __HAL_TIMER_TIMER_V2_H__
#define __HAL_TIMER_TIMER_V2_H__

#include "hal/pulp.h"
#include "archi/timer/timer_v2.h"


#ifdef ARCHI_HAS_FC

static inline unsigned int timer_base_fc(int id, int sub_id)
{
  return ARCHI_FC_TIMER_ADDR + id * ARCHI_FC_TIMER_SIZE + sub_id * 4;
}

#else

#define timer_base_fc(id,sub_id) timer_base_cl(0,id,sub_id)

#endif


#ifdef ARCHI_HAS_CLUSTER

static inline unsigned int timer_base_cl(int cid, int id, int sub_id)
{
  return ARCHI_CLUSTER_PERIPHERALS_GLOBAL_ADDR(0) + ARCHI_TIMER_OFFSET + id * ARCHI_TIMER_SIZE + sub_id * 4;
}

#endif


static inline unsigned int timer_conf_get(unsigned int addr)
{
  return timer_cfg_lo_get(addr);
}


static inline void timer_conf_set(unsigned int addr, unsigned int value)
{
  timer_cfg_lo_set(addr, value);
}


static inline unsigned int timer_count_get(unsigned int addr)
{
  return timer_cnt_lo_get(addr);
}


static inline void timer_count_set(unsigned int addr, unsigned int value)
{
  timer_cnt_lo_set(addr, value);
}


static inline unsigned int timer_cmp_get(unsigned int addr)
{
  return timer_cmp_lo_get(addr);
}


static inline void timer_cmp_set(unsigned int addr, unsigned int cmp)
{
  timer_cmp_lo_set(addr, cmp);
}


static inline void timer_reset(unsigned int addr)
{
  timer_reset_lo_set(addr, 1);
}


static inline void timer_start(unsigned int addr)
{
  timer_start_lo_set(addr, 1);
}


#endif
