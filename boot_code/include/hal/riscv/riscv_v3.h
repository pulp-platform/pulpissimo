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

#ifndef __HAL_RISCV_RISCV_V3_H__
#define __HAL_RISCV_RISCV_V3_H__

#include "archi/pulp.h"
#include "hal/riscv/builtins_v2_emu.h"

#define CSR_PCMR_ACTIVE 0x1

static inline unsigned int hal_mepc_read() {
  int retval;
  asm volatile ("csrr %0, 0x341" : "=r" (retval));
  return retval;
}

static inline unsigned int core_id() {
  int hart_id;
  asm("csrr %0, 0xF10" : "=r" (hart_id) : );
  // in PULP the hart id is {22'b0, cluster_id, core_id}
  return hart_id & 0x01f;
}

static inline unsigned int cluster_id() {  int hart_id;
  asm("csrr %0, 0xF10" : "=r" (hart_id) : );
  // in PULP the hart id is {22'b0, cluster_id, core_id}
  return hart_id & 0x3e0;
}

static inline unsigned int hal_core_id() {
  int hart_id;
  asm("csrr %0, 0xF10" : "=r" (hart_id) : );
  // in PULP the hart id is {22'b0, cluster_id, core_id}
  return hart_id & 0x01f;
}

static inline unsigned int hal_cluster_id() {
  int hart_id;
  asm("csrr %0, 0xF10" : "=r" (hart_id) : );
  // in PULP the hart id is {22'b0, cluster_id, core_id}
  return (hart_id >> 5) & 0x3f;
}

static inline unsigned int hal_has_fc() {
#ifdef PLP_HAS_FC
  return 1;
#else
  return 0;
#endif
}

static inline unsigned int hal_is_fc() {
  if (hal_has_fc()) return hal_cluster_id() == 32;
  else return 0;
}

static inline int hal_irq_disable()
{
  int result;
  asm volatile ("csrrc %0, 0x300, %1" :  "=r" (result) : "I" (0) );
  return result;
}

static inline void hal_irq_restore(int state)
{
  int result;
  asm volatile ("csrrc %0, 0x300, %1" :  "=r" (result) : "r" (state) );
}

static inline void hal_irq_enable()
{
  int result;
  asm volatile ("csrrc %0, 0x300, %1" :  "=r" (result) : "I" (0x1<<1) );
}

/*
 * PERFORMANCE COUNTERS
 * 
 * API for accessing performance counters registers.
 * Have a look at file spr-defs.h to speficy registers through defines
 * SPR_PCER_* and SPR_PCMR_*
 */

#define PCER_NB_EVENTS CSR_PCER_NB_EVENTS
#define PCER_ALL_EVENTS_MASK CSR_PCER_ALL_EVENTS_MASK
#define PCMR_ACTIVE CSR_PCMR_ACTIVE
#define PCMR_SATURATE CSR_PCMR_SATURATE

/* Configure the active events. eventMask is an OR of events got through SPR_PCER_EVENT_MASK */
static inline void cpu_perf_conf_events(unsigned int eventMask)
{
  asm volatile ("csrw 0x7A0, %0" : "+r" (eventMask));
}

/* Return events configuration */
static inline unsigned int cpu_perf_conf_events_get()
{
  unsigned int result;
  asm volatile ("csrr %0, 0x7A0" : "=r" (result));
  return result;
}

/* Configure the mode. confMask is an OR of all SPR_PCMR_* macros */
static inline void cpu_perf_conf(unsigned int confMask)
{
  asm volatile ("csrw 0x7A1, %0" :: "r" (confMask));
}

/* Starts counting in all counters. As this is using the mode register,
 * the rest of the config can be given through conf parameter */
static inline void cpu_perf_start(unsigned int conf) {
  cpu_perf_conf(conf | CSR_PCMR_ACTIVE); // TODO
}

/* Stops counting in all counters. As this is using the mode register,
 * the rest of the config can be given through conf parameter */
static inline void cpu_perf_stop(unsigned int conf) {
  cpu_perf_conf(conf); // TODO
}

/* Set the specified counter to the specified value */
static inline void cpu_perf_set(unsigned int counterId, unsigned int value);

/* Set all counters to the specified value */
static inline void cpu_perf_setall(unsigned int value) {
  asm volatile ("csrw 0x79F, %0" :: "r" (value));
}

/* Return the value of the specified counter */
static inline unsigned int cpu_perf_get(const unsigned int counterId) {
  unsigned int value = 0;

  // This is stupid! But I really don't know how else we could do that
  switch(counterId) {
   case  0: asm volatile ("csrr %0, 0x780" : "=r" (value)); break;
   case  1: asm volatile ("csrr %0, 0x781" : "=r" (value)); break;
   case  2: asm volatile ("csrr %0, 0x782" : "=r" (value)); break;
   case  3: asm volatile ("csrr %0, 0x783" : "=r" (value)); break;
   case  4: asm volatile ("csrr %0, 0x784" : "=r" (value)); break;
   case  5: asm volatile ("csrr %0, 0x785" : "=r" (value)); break;
   case  6: asm volatile ("csrr %0, 0x786" : "=r" (value)); break;
   case  7: asm volatile ("csrr %0, 0x787" : "=r" (value)); break;
   case  8: asm volatile ("csrr %0, 0x788" : "=r" (value)); break;
   case  9: asm volatile ("csrr %0, 0x789" : "=r" (value)); break;
   case 10: asm volatile ("csrr %0, 0x78A" : "=r" (value)); break;
   case 11: asm volatile ("csrr %0, 0x78B" : "=r" (value)); break;
   case 12: asm volatile ("csrr %0, 0x78C" : "=r" (value)); break;
   case 13: asm volatile ("csrr %0, 0x78D" : "=r" (value)); break;
   case 14: asm volatile ("csrr %0, 0x78E" : "=r" (value)); break;
   case 15: asm volatile ("csrr %0, 0x78F" : "=r" (value)); break;
   case 16: asm volatile ("csrr %0, 0x790" : "=r" (value)); break;
   case 17: asm volatile ("csrr %0, 0x791" : "=r" (value)); break;
   case 18: asm volatile ("csrr %0, 0x792" : "=r" (value)); break;
   case 19: asm volatile ("csrr %0, 0x793" : "=r" (value)); break;
   case 20: asm volatile ("csrr %0, 0x794" : "=r" (value)); break;
   case 21: asm volatile ("csrr %0, 0x795" : "=r" (value)); break;
   case 22: asm volatile ("csrr %0, 0x796" : "=r" (value)); break;
   case 23: asm volatile ("csrr %0, 0x797" : "=r" (value)); break;
   case 24: asm volatile ("csrr %0, 0x798" : "=r" (value)); break;
   case 25: asm volatile ("csrr %0, 0x799" : "=r" (value)); break;
   case 26: asm volatile ("csrr %0, 0x79A" : "=r" (value)); break;
   case 27: asm volatile ("csrr %0, 0x79B" : "=r" (value)); break;
   case 28: asm volatile ("csrr %0, 0x79C" : "=r" (value)); break;
   case 29: asm volatile ("csrr %0, 0x79D" : "=r" (value)); break;
   case 30: asm volatile ("csrr %0, 0x79E" : "=r" (value)); break;
  }
  return value;
}

static inline char *cpu_perf_name(int event) {
  switch (event) 
    {
    case 0: return "CYCLES";
    case 1: return "INSTR";
    case 2: return "LD_STALL";
    case 3: return "JMP_STALL";
    case 4: return "IMISS";
    case 5: return "LD";
    case 6: return "ST";
    case 7: return "JUMP";
    case 8: return "BRANCH";
    case 9: return "TAKEN_BRANCH";
    case 10: return "RVC";
    case 11: return "LD_EXT";
    case 12: return "ST_EXT";
    case 13: return "LD_EXT_CYC";
    case 14: return "ST_EXT_CYC";
    case 15: return "TCDM_CONT";
    }
  return (char *)0;
}


#endif
