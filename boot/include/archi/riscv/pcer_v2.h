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

#ifndef _ARCHI_RISCV_PCER_V1_H
#define _ARCHI_RISCV_PCER_V1_H

/*
 * Bit definitions for Performance counters mode registers
 *
 */
#define CSR_PCER_CYCLES        0  /* Count the number of cycles the core was running */
#define CSR_PCER_INSTR         1  /* Count the number of instructions executed */
#define CSR_PCER_LD_STALL      2  /* Number of load use hazards */
#define CSR_PCER_JMP_STALL     3  /* Number of jump register hazards */
#define CSR_PCER_IMISS         4  /* Cycles waiting for instruction fetches. i.e. the number of instructions wasted due to non-ideal caches */
#define CSR_PCER_LD            5  /* Number of memory loads executed. Misaligned accesses are counted twice */
#define CSR_PCER_ST            6  /* Number of memory stores executed. Misaligned accesses are counted twice */
#define CSR_PCER_JUMP          7  /* Number of jump instructions seen, i.e. j, jr, jal, jalr */
#define CSR_PCER_BRANCH        8  /* Number of branch instructions seen, i.e. bf, bnf */
#define CSR_PCER_TAKEN_BRANCH  9  /* Number of taken branch instructions seen, i.e. bf, bnf */
#define CSR_PCER_RVC          10  /* Number of compressed instructions */
#define CSR_PCER_ELW          11  /* Cycles wasted due to ELW instruction */
#define CSR_PCER_LD_EXT       12  /* Number of memory loads to EXT executed. Misaligned accesses are counted twice. Every non-TCDM access is considered external */
#define CSR_PCER_ST_EXT       13  /* Number of memory stores to EXT executed. Misaligned accesses are counted twice. Every non-TCDM access is considered external */
#define CSR_PCER_LD_EXT_CYC   14  /* Cycles used for memory loads to EXT. Every non-TCDM access is considered external */
#define CSR_PCER_ST_EXT_CYC   15  /* Cycles used for memory stores to EXT. Every non-TCDM access is considered external */
#define CSR_PCER_TCDM_CONT    16  /* Cycles wasted due to TCDM/log-interconnect contention */


#define CSR_PCER_NB_EVENTS      17
#define CSR_PCER_NB_INTERNAL_EVENTS    12
#define CSR_NB_PCCR             31

// Gives from the event ID, the HW mask that can be stored (with an OR with other events mask) to the PCER
#define CSR_PCER_EVENT_MASK(eventId)  (1<<(eventId))
#define CSR_PCER_ALL_EVENTS_MASK  0xffffffff

#define CSR_PCMR_ACTIVE           0x1 /* Activate counting */
#define CSR_PCMR_SATURATE         0x2 /* Activate saturation */

#define CSR_PCER_NAME(id) \
    ( id == 0 ? "Cycles" : \
      id == 1 ? "Instructions" : \
      id == 2 ? "LD_Stall" : \
      id == 3 ? "Jmp_Stall" : \
      id == 4 ? "IMISS" : \
      id == 5 ? "LD" : \
      id == 6 ? "ST" : \
      id == 7 ? "JUMP" : \
      id == 8 ? "BRANCH" : \
      id == 9 ? "TAKEN_BRANCH" : \
      id == 10 ? "RVC" : \
      id == 11 ? "ELW" : \
      id == 12 ? "LD_EXT" : \
      id == 13 ? "ST_EXT" : \
      id == 14 ? "LD_EXT_CYC" : \
      id == 15 ? "ST_EXT_CYC" : \
      id == 16 ? "TCDM_CONT" : \
      "NA")

#endif
