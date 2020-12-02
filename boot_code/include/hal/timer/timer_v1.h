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

#ifndef	__HAL_TIMER_TIMER_V1_H__
#define __HAL_TIMER_TIMER_V1_H__

#include "archi/pulp.h"

#define START_TIME_ADDR    (ARCHI_TIMER_ADDR + 0x0)
#define STOP_TIME_ADDR     (ARCHI_TIMER_ADDR + 0x04)
#define RESET_TIME_ADDR    (ARCHI_TIMER_ADDR + 0x08)
#define GET_TIME_LO_ADDR   (ARCHI_TIMER_ADDR + 0x0C)
#define GET_TIME_HI_ADDR   (ARCHI_TIMER_ADDR + 0x10)

#define START_TIME_T0_ADDR (ARCHI_TIMER_ADDR + 0x40)
#define STOP_TIME_T0_ADDR  (ARCHI_TIMER_ADDR + 0x44)
#define RESET_TIME_T0_ADDR (ARCHI_TIMER_ADDR + 0x48)
#define GET_TIME_T0_ADDR   (ARCHI_TIMER_ADDR + 0x4C)
#define START_TIME_T1_ADDR (ARCHI_TIMER_ADDR + 0x80)
#define STOP_TIME_T1_ADDR  (ARCHI_TIMER_ADDR + 0x84)
#define RESET_TIME_T1_ADDR (ARCHI_TIMER_ADDR + 0x88)
#define GET_TIME_T1_ADDR   (ARCHI_TIMER_ADDR + 0x8C)
#define START_TIME_T2_ADDR (ARCHI_TIMER_ADDR + 0xC0)
#define STOP_TIME_T2_ADDR  (ARCHI_TIMER_ADDR + 0xC4)
#define RESET_TIME_T2_ADDR (ARCHI_TIMER_ADDR + 0xC8)
#define GET_TIME_T2_ADDR   (ARCHI_TIMER_ADDR + 0xCC)
#define START_TIME_T3_ADDR (ARCHI_TIMER_ADDR + 0x100)
#define STOP_TIME_T3_ADDR  (ARCHI_TIMER_ADDR + 0x104)
#define RESET_TIME_T3_ADDR (ARCHI_TIMER_ADDR + 0x108)
#define GET_TIME_T3_ADDR   (ARCHI_TIMER_ADDR + 0x10C)

#define GET_TIMER_ADDR(t)  (ARCHI_TIMER_ADDR + ((t)+1)*0x40)

static inline void start_core_timer(int timernum) {
  *(volatile int*)(GET_TIMER_ADDR(timernum) + 0x0) = 1;
}

static inline void stop_core_timer(int timernum) {
  *(volatile int*)(GET_TIMER_ADDR(timernum) + 0x4) = 1;
}

static inline void reset_core_timer(int timernum) {
  *(volatile int*)(GET_TIMER_ADDR(timernum) + 0x8) = 1;
}

static inline int  get_core_time(int timernum) {
  return *(volatile int*)(GET_TIMER_ADDR(timernum) + 0xc);
}

static inline void set_core_time(int timernum,int timerval) {
  *(volatile int*)(GET_TIMER_ADDR(timernum) + 0xc) = timerval;
}

static inline void plp_timer_fire(int timer)
{
	start_core_timer(timer);
	reset_core_timer(timer);
}

static inline void plp_timer_compare_set(int timer, int cmpVal)
{
	set_core_time(timer, cmpVal);
}

static inline void plp_timer_compare_unset(int timer)
{
	set_core_time(timer, 0);
}

static inline void plp_timer_update(int timer, int cmpVal)
{
	set_core_time(timer, cmpVal);
}

static inline void plp_timer_cancel(int timer)
{
	stop_core_timer(timer);
}

static inline unsigned int plp_timer_cycles(int timer)
{
	return get_core_time(timer);
}

#endif
