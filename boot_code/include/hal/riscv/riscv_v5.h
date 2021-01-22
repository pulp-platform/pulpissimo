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

#ifndef __HAL_RISCV_RISCV_V5_H__
#define __HAL_RISCV_RISCV_V5_H__

#include "archi/pulp.h"

#include "hal/riscv/types.h"
#include "archi/riscv/builtins_v2.h"
#include "archi/riscv/builtins_v2_emu.h"

#define CSR_PCMR_ACTIVE 0x1

#define SR_MTVEC  0x305






#if defined(__OPTIMIZE__) && defined(CORE_PULP_BUILTINS) && !defined(__LLVM__)

static inline unsigned int hal_spr_read_then_clr(unsigned int reg, unsigned int val)
{
  return __builtin_pulp_read_then_spr_bit_clr(reg, val);
}

static inline unsigned int hal_spr_read_then_set(unsigned int reg, unsigned int val)
{
  return __builtin_pulp_read_then_spr_bit_set(reg, val);
}

static inline void hal_spr_write(unsigned int reg, unsigned int val)
{
  __builtin_pulp_spr_write(reg, val);
}

static inline unsigned int hal_spr_read(unsigned int reg)
{
  return __builtin_pulp_spr_read(reg);
}

#else

#if defined(__LLVM__)

#else
 
#define hal_spr_read_then_clr(reg,val) \
  ({ \
    int state; \
    asm volatile ("csrrc %0, %1, %2" :  "=r" (state) : "I" (reg), "I" (val) ); \
    state; \
  })

#define hal_spr_read_then_set(reg,val) \
  ({ \
    int state; \
    asm volatile ("csrrs %0, %1, %2" :  "=r" (state) : "I" (reg), "I" (val) ); \
    state; \
  })

#define hal_spr_read_then_clr_from_reg(reg,val) \
  ({ \
    int state; \
    asm volatile ("csrrc %0, %1, %2" :  "=r" (state) : "I" (reg), "r" (val) ); \
    state; \
  })

#define hal_spr_read_then_set(reg,val) \
  ({ \
    int state; \
    asm volatile ("csrrs %0, %1, %2" :  "=r" (state) : "I" (reg), "I" (val) ); \
    state; \
  })

#define hal_spr_read_then_set_from_reg(reg,val) \
  ({ \
    int state; \
    asm volatile ("csrrs %0, %1, %2" :  "=r" (state) : "I" (reg), "r" (val) ); \
    state; \
  })

#define hal_spr_write(reg,val) \
do { \
  asm volatile ("csrw %0, %1" :  : "I" (reg), "r" (val) ); \
} while(0)

#define hal_spr_read(reg) \
({ \
  int result; \
  asm volatile ("csrr %0, %1" : "=r" (result) : "I" (reg) ); \
  result; \
})

#endif

#endif





#if defined(__LLVM__)

#define csr_read(csr)           \
({                \
  register unsigned int __v;       \
  __asm__ __volatile__ ("csrr %0, " #csr      \
            : "=r" (__v));      \
  __v;              \
})

#define hal_mepc_read() csr_read(0x341)

#else
#define hal_mepc_read() hal_spr_read(RV_CSR_MEPC)
#endif

static inline unsigned int core_id() {
  int hart_id;
#if RISCV_VERSION >= 4 && !defined(RISCV_1_7)
#if PULP_CHIP_FAMILY == CHIP_GAP
  asm("csrr %0, 0x014" : "=r" (hart_id) : );
#else
  asm("csrr %0, 0xF14" : "=r" (hart_id) : );
#endif
#else
  asm("csrr %0, 0xF10" : "=r" (hart_id) : );
#endif
  // in PULP the hart id is {22'b0, cluster_id, core_id}
  return hart_id & 0x01f;
}

static inline unsigned int cluster_id() {  int hart_id;
#if RISCV_VERSION >= 4 && !defined(RISCV_1_7)
#if PULP_CHIP_FAMILY == CHIP_GAP
  asm("csrr %0, 0x014" : "=r" (hart_id) : );
#else
  asm("csrr %0, 0xF14" : "=r" (hart_id) : );
#endif
#else
  asm("csrr %0, 0xF10" : "=r" (hart_id) : );
#endif
  // in PULP the hart id is {22'b0, cluster_id, core_id}
  return (hart_id >> 5) & 0x3f;
}

#ifndef PLP_NO_BUILTIN

static inline unsigned int hal_core_id() {
  return core_id();
  //return __builtin_pulp_CoreId();
}

static inline unsigned int hal_cluster_id() {
  return cluster_id();
  // return __builtin_pulp_ClusterId();
}

// TODO replace by compiler builtin
static inline __attribute__((always_inline)) unsigned int hal_has_fc() {
#ifdef ARCHI_HAS_FC
  return 1;
#else
  return 0;
#endif
}

static inline __attribute__((always_inline)) unsigned int hal_is_fc() {
#ifndef ARCHI_HAS_FC
  return 0;
#else
  if (hal_has_fc()) return hal_cluster_id() == ARCHI_FC_CID;
  else return 0;
#endif
}

#else

static inline __attribute__((always_inline)) unsigned int hal_core_id() {
  int hart_id;
#if RISCV_VERSION >= 4 && !defined(RISCV_1_7)
#if PULP_CHIP_FAMILY == CHIP_GAP
  asm("csrr %0, 0x014" : "=r" (hart_id) : );
#else
  asm("csrr %0, 0xF14" : "=r" (hart_id) : );
#endif
#else
  asm("csrr %0, 0xF10" : "=r" (hart_id) : );
#endif
  // in PULP the hart id is {22'b0, cluster_id, core_id}
  return hart_id & 0x01f;
}

static inline __attribute__((always_inline)) unsigned int hal_cluster_id() {
  int hart_id;
#if RISCV_VERSION >= 4 && !defined(RISCV_1_7)
#if PULP_CHIP_FAMILY == CHIP_GAP
  asm("csrr %0, 0x014" : "=r" (hart_id) : );
#else
  asm("csrr %0, 0xF14" : "=r" (hart_id) : );
#endif
#else
  asm("csrr %0, 0xF10" : "=r" (hart_id) : );
#endif
  // in PULP the hart id is {22'b0, cluster_id, core_id}
  return (hart_id >> 5) & 0x3f;
}

static inline __attribute__((always_inline)) unsigned int hal_has_fc() {
#ifdef ARCHI_HAS_FC
  return 1;
#else
  return 0;
#endif
}

static inline __attribute__((always_inline)) unsigned int hal_is_fc() {
#ifndef ARCHI_HAS_FC
  return 0;
#else
  if (hal_has_fc()) return hal_cluster_id() == ARCHI_FC_CID;
  else return 0;
#endif
}

#endif



#if defined(__LLVM__)

static inline int hal_irq_disable()
{
  return 0;
}

static inline void hal_irq_restore(int state)
{
}

static inline void hal_irq_enable()
{
}

#else

static inline int hal_irq_disable()
{
  int irq = hal_spr_read_then_clr(0x300, 0x1<<3);
  // This memory barrier is needed to prevent the compiler to cross the irq barrier
  __asm__ __volatile__ ("" : : : "memory");
  return irq;
}

static inline void hal_irq_restore(int state)
{
  // This memory barrier is needed to prevent the compiler to cross the irq barrier
  __asm__ __volatile__ ("" : : : "memory");
  hal_spr_write(0x300, state);
}

static inline void hal_irq_enable()
{
  // This memory barrier is needed to prevent the compiler to cross the irq barrier
  __asm__ __volatile__ ("" : : : "memory");
  hal_spr_read_then_set(0x300, 0x1<<3);
}

#endif

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
#ifndef PLP_NO_PERF_COUNTERS
  asm volatile ("csrw 0xCC0, %0" : "+r" (eventMask));
#endif
}

/* Return events configuration */
static inline unsigned int cpu_perf_conf_events_get()
{
#ifndef PLP_NO_PERF_COUNTERS
  unsigned int result;
  asm volatile ("csrr %0, 0xCC0" : "=r" (result));
  return result;
#else
  return 0;
#endif
}

/* Configure the mode. confMask is an OR of all SPR_PCMR_* macros */
static inline void cpu_perf_conf(unsigned int confMask)
{
#ifndef PLP_NO_PERF_COUNTERS
  asm volatile ("csrw 0xCC1, %0" :: "r" (confMask));
#endif
}

/* Starts counting in all counters. As this is using the mode register,
 * the rest of the config can be given through conf parameter */
static inline void cpu_perf_start(unsigned int conf) {
#ifndef PLP_NO_PERF_COUNTERS
  cpu_perf_conf(conf | CSR_PCMR_ACTIVE); // TODO
#endif
}

/* Stops counting in all counters. As this is using the mode register,
 * the rest of the config can be given through conf parameter */
static inline void cpu_perf_stop(unsigned int conf) {
#ifndef PLP_NO_PERF_COUNTERS
  cpu_perf_conf(conf); // TODO
#endif
}

/* Set the specified counter to the specified value */
static inline void cpu_perf_set(unsigned int counterId, unsigned int value) {
  
}

/* Set all counters to the specified value */
static inline void cpu_perf_setall(unsigned int value) {
#ifndef PLP_NO_PERF_COUNTERS
  asm volatile ("csrw 0x79F, %0" :: "r" (value));
#endif
}

/* Return the value of the specified counter */
static inline unsigned int cpu_perf_get(const unsigned int counterId) {
#ifndef PLP_NO_PERF_COUNTERS
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
#else
  return 0;
#endif
}

static inline const char *cpu_perf_name(int event) {
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



/*
 * Stack checking
 */

static inline void cpu_stack_check_enable(unsigned int base, unsigned int end)
{
  asm volatile ("csrwi 0x7D0, 0" :: );
  asm volatile ("csrw  0x7D1, %0" :: "r" (base));
  asm volatile ("csrw  0x7D2, %0" :: "r" (end));
  asm volatile ("csrwi 0x7D0, 1" :: );
}

static inline void cpu_stack_check_disable()
{
  asm volatile ("csrwi 0x7D0, 0" :: );
}



#if !defined(RV_ISA_RV32)

/* Packing of scalars into vectors */
#define __builtin_pack2(x, y)    __builtin_pulp_pack2((signed short)   (x), (signed short)   (y))
#define __builtin_packu2(x, y)   __builtin_pulp_pack2((unsigned short) (x), (unsigned short) (y))

#define __builtin_pack4(x, y, z, t)    __builtin_pulp_pack4((signed char)   (x), (signed char)   (y), (signed char)   (z), (signed char)   (t))
#define __builtin_packu4(x, y, z, t)   __builtin_pulp_pack4((unsigned char) (x), (unsigned char) (y), (unsigned char) (z), (unsigned char) (t))

#define __builtin_max2(x, y)     __builtin_pulp_max2((x), (y))
#define __builtin_max4(x, y)     __builtin_pulp_max4((x), (y))

#define __builtin_maxu2(x, y)    __builtin_pulp_maxu2((x), (y))
#define __builtin_maxu4(x, y)    __builtin_pulp_maxu4((x), (y))

/* Min */
#define __builtin_min2(x, y)     __builtin_pulp_min2((x), (y))
#define __builtin_min4(x, y)     __builtin_pulp_min4((x), (y))

#define __builtin_minu2(x, y)    __builtin_pulp_minu2((x), (y))
#define __builtin_minu4(x, y)    __builtin_pulp_minu4((x), (y))

/* Clip */
#define __builtin_clip(x, precision)   __builtin_pulp_clip((x), -(1<<(precision)), (1<<precision)-1)
#define __builtin_clipu(x, precision)  __builtin_pulp_clipu((x), 0, (1<<precision)-1)

/* Abs */
#define __builtin_abs2(x)      __builtin_pulp_abs2((x))
#define __builtin_abs4(x)      __builtin_pulp_abs4((x))

/* Mac */
#define __builtin_macs(Acc, x, y)    __builtin_pulp_macs((x), (y), (Acc))
#define __builtin_machhs(Acc, x, y)    __builtin_pulp_machhs((x), (y), (Acc))
#define __builtin_macu(Acc, x, y)    __builtin_pulp_macu((x), (y), (Acc))
#define __builtin_machhu(Acc, x, y)    __builtin_pulp_machhu((x), (y), (Acc))

#define __builtin_macsN(Acc, x, y, n)  __builtin_pulp_macsN((x), (y), (Acc), (n))
#define __builtin_macuN(Acc, x, y, n)  __builtin_pulp_macuN((x), (y), (Acc), (n))
#define __builtin_macsRN(Acc, x, y, n) __builtin_pulp_macsRN((x), (y), (Acc), (n), (1<<((n)-1)))
#define __builtin_macuRN(Acc, x, y, n) __builtin_pulp_macuRN((x), (y), (Acc), (n), (1<<((n)-1)))

#define __builtin_machhsN(Acc, x, y, n)  __builtin_pulp_machhsN((x), (y), (Acc), (n))
#define __builtin_machhuN(Acc, x, y, n)  __builtin_pulp_machhuN((x), (y), (Acc), (n))
#define __builtin_machhsRN(Acc, x, y, n) __builtin_pulp_machhsN((x), (y), (Acc), (n), (1<<((n)-1)))
#define __builtin_machhuRN(Acc, x, y, n) __builtin_pulp_machhuN((x), (y), (Acc), (n), (1<<((n)-1)))

/* Multiplications */
#define __builtin_mulsN(x, y, n)   __builtin_pulp_mulsN((x), (y), (n))
#define __builtin_mulsRN(x, y, n)    __builtin_pulp_mulsRN((x), (y), (n), (1<<((n)-1)))
#define __builtin_muluN(x, y, n)   __builtin_pulp_muluN((x), (y), (n))
#define __builtin_muluRN(x, y, n)    __builtin_pulp_muluRN((x), (y), (n), (1<<((n)-1)))

#define __builtin_mulhhsN(x, y, n)   __builtin_pulp_mulhhsN((x), (y), (n))
#define __builtin_mulhhsRN(x, y, n)    __builtin_pulp_mulhhsRN((x), (y), (n), (1<<((n)-1)))
#define __builtin_mulhhuN(x, y, n)   __builtin_pulp_mulhhuN((x), (y), (n))
#define __builtin_mulhhuRN(x, y, n)    __builtin_pulp_mulhhuRN((x), (y), (n), (1<<((n)-1)))

/* Vectorial product and sum of products */
#define __builtin_dotp2(x, y)        __builtin_pulp_dotsp2((x), (y))
#define __builtin_dotpu2(x, y)         __builtin_pulp_dotup2((x), (y))
#define __builtin_dotpus2(x, y)        __builtin_pulp_dotusp2((x), (y))

#define __builtin_sumdotp2(x, y, z)    __builtin_pulp_sdotsp2((x), (y), (z))
#define __builtin_sumdotpu2(x, y, z)   __builtin_pulp_sdotup2((x), (y), (z))
#define __builtin_sumdotpus2(x, y, z)  __builtin_pulp_sdotusp2((x), (y), (z))

#define __builtin_dotp4(x, y)        __builtin_pulp_dotsp4((x), (y))
#define __builtin_dotpu4(x, y)         __builtin_pulp_dotup4((x), (y))
#define __builtin_dotpus4(x, y)        __builtin_pulp_dotusp4((x), (y))

#define __builtin_sumdotp4(x, y, z)      __builtin_pulp_sdotsp4((x), (y), (z))
#define __builtin_sumdotpu4(x, y, z)       __builtin_pulp_sdotup4((x), (y), (z))
#define __builtin_sumdotpus4(x, y, z)      __builtin_pulp_sdotusp4((x), (y), (z))


/* Position of the most significant bit of x */
#define __builtin_fl1(x)     __builtin_pulp_fl1((x))

/* Number of sign bits */
#define __builtin_clb(x)     __builtin_pulp_clb((x))

/* Bit Extraction */
#define __builtin_bitextract(x, size, off) __builtin_pulp_bextract((x), (size), (off))
#define __builtin_bitextractu(x, size, off)  __builtin_pulp_bextractu((x), (size), (off))

/* Bit insertion */
static inline unsigned int bi_ExtInsMaskFast(unsigned int Size, unsigned int Offset) { return ((((Size-1))<<5)|(Offset)); }
#define __builtin_bitinsert(dst, src, size, off) __builtin_pulp_binsert((dst), ~(((1<<(size))-1)<<(off)), (src), (((1<<(size))-1)<<(off)), (off))
#define __builtin_bitinsert_r(dst, src, size, off)   __builtin_pulp_binsert_r((dst), (src), bi_ExtInsMaskFast((size), (off)))

/* 1 bit rotation to the right, 32 bits input */
#define __builtin_rotr(x)      __builtin_pulp_rotr((x))

/* Add with normalization and rounding */
#define __builtin_addroundnormu(x, y, scale) __builtin_pulp_adduRN((x), (y), (scale), (1<<((scale)-1)))
#define __builtin_addroundnorm(x, y, scale)  __builtin_pulp_addRN((x), (y), (scale), (1<<((scale)-1)))

/* Normalization and rounding */
#define __builtin_roundnormu(x, scale) __builtin_pulp_adduRN((x), 0, (scale), (1<<((scale)-1)))
#define __builtin_roundnorm(x, scale)  __builtin_pulp_addRN((x), 0, (scale), (1<<((scale)-1)))

#else

/* Packing of scalars into vectors */
#define __builtin_pack2(x, y)    ((v2s) {(signed short)   (x), (signed short)   (y)})
#define __builtin_packu2(x, y)   ((v2u) {(unsigned short) (x), (unsigned short) (y)})

#define __builtin_pack4(x, y, z, t)    ((v4s) {(signed char)   (x), (signed char)   (y), (signed char)   (z), (signed char)   (t)})
#define __builtin_packu4(x, y, z, t)   ((v4u) {(unsigned char) (x), (unsigned char) (y), (unsigned char) (z), (unsigned char) (t)})

/* Max */

#define __builtin_max2(x, y)     ((v2s) {((signed short)(x)[0]>(signed short)(y)[0])?((signed short)(x)[0]):((signed short)(y)[0]), \
            ((signed short)(x)[1]>(signed short)(y)[1])?((signed short)(x)[1]):((signed short)(y)[1])})
#define __builtin_max4(x, y)     ((v4s) {((signed char)(x)[0]>(signed char)(y)[0])?(signed char)(x)[0]:(signed char)(y)[0], \
            ((signed char)(x)[1]>(signed char)(y)[1])?(signed char)(x)[1]:(signed char)(y)[1], \
            ((signed char)(x)[2]>(signed char)(y)[2])?(signed char)(x)[2]:(signed char)(y)[2], \
            ((signed char)(x)[3]>(signed char)(y)[3])?(signed char)(x)[3]:(signed char)(y)[3]})

#define __builtin_maxu2(x, y)    ((v2u) {((unsigned short)(x)[0]>(unsigned short)(y)[0])?(unsigned short)(x)[0]:(unsigned short)(y)[0], \
            ((unsigned short)(x)[1]>(unsigned short)(y)[1])?(unsigned short)(x)[1]:(unsigned short)(y)[1]})
#define __builtin_maxu4(x, y)    ((v4u) {((unsigned char)(x)[0]>(unsigned char)(y)[0])?(unsigned char)(x)[0]:(unsigned char)(y)[0], \
            ((unsigned char)(x)[1]>(unsigned char)(y)[1])?(unsigned char)(x)[1]:(unsigned char)(y)[1], \
            ((unsigned char)(x)[2]>(unsigned char)(y)[2])?(unsigned char)(x)[2]:(unsigned char)(y)[2], \
            ((unsigned char)(x)[3]>(unsigned char)(y)[3])?(unsigned char)(x)[3]:(unsigned char)(y)[3]})

/* Min */
#define __builtin_min2(x, y)     ((v2s) {((signed short)(x)[0]<(signed short)(y)[0])?((signed short)(x)[0]):((signed short)(y)[0]), \
            ((signed short)(x)[1]<(signed short)(y)[1])?((signed short)(x)[1]):((signed short)(y)[1])})
#define __builtin_min4(x, y)     ((v4s) {((signed char)(x)[0]<(signed char)(y)[0])?(signed char)(x)[0]:(signed char)(y)[0], \
            ((signed char)(x)[1]<(signed char)(y)[1])?(signed char)(x)[1]:(signed char)(y)[1], \
            ((signed char)(x)[2]<(signed char)(y)[2])?(signed char)(x)[2]:(signed char)(y)[2], \
            ((signed char)(x)[3]<(signed char)(y)[3])?(signed char)(x)[3]:(signed char)(y)[3]})

#define __builtin_minu2(x, y)    ((v2u) {((unsigned short)(x)[0]<(unsigned short)(y)[0])?(unsigned short)(x)[0]:(unsigned short)(y)[0], \
            ((unsigned short)(x)[1]<(unsigned short)(y)[1])?(unsigned short)(x)[1]:(unsigned short)(y)[1]})
#define __builtin_minu4(x, y)    ((v4u) {((unsigned char)(x)[0]<(unsigned char)(y)[0])?(unsigned char)(x)[0]:(unsigned char)(y)[0], \
            ((unsigned char)(x)[1]<(unsigned char)(y)[1])?(unsigned char)(x)[1]:(unsigned char)(y)[1], \
            ((unsigned char)(x)[2]<(unsigned char)(y)[2])?(unsigned char)(x)[2]:(unsigned char)(y)[2], \
            ((unsigned char)(x)[3]<(unsigned char)(y)[3])?(unsigned char)(x)[3]:(unsigned char)(y)[3]})

/* Clip */
#define __builtin_clip(x, precision)   ((x)<(-(1<<(precision)))?(-(1<<(precision))):(((x)>((1<<(precision))-1))?((1<<(precision))-1):(x)))
#define __builtin_clipu(x, precision)  ((x)<0)?0:(((x)>((1<<(precision))-1))?((1<<(precision))-1):(x))

/* Abs */
#define __builtin_abs2(x)      ((v2s) {((x)[0]<0)?-(x)[0]:(x)[0], ((x)[1]<0)?-(x)[1]:(x)[1]})
#define __builtin_abs4(x)      ((v4s) {((x)[0]<0)?-(x)[0]:(x)[0], ((x)[1]<0)?-(x)[1]:(x)[1], \
            ((x)[2]<0)?-(x)[2]:(x)[2], ((x)[3]<0)?-(x)[3]:(x)[3]})

/* Mac */
#define __builtin_macs(Acc, x, y)    ((Acc) + ((short int) (x) * (short int) (y)))
#define __builtin_machhs(Acc, x, y)    ((Acc) + ((short int) ((x)>>16) * (short int) ((y)>>16)))
#define __builtin_macu(Acc, x, y)    ((Acc) + ((unsigned short int) (x) * (unsigned short int) (y)))
#define __builtin_machhu(Acc, x, y)    ((Acc) + ((unsigned short int) ((x)>>16) * (unsigned short int) ((y)>>16)))

#define __builtin_macsN(Acc, x, y, n)  (((Acc) + ((short int) (x) * (short int) (y)))>>(n))
#define __builtin_macuN(Acc, x, y, n)  (((Acc) + ((unsigned short int) (x) * (unsigned short int) (y)))>>(n))
#define __builtin_macsRN(Acc, x, y, n) ((((Acc) + ((short int) (x) * (short int) (y))) + (1<<((n)-1))) >> (n))
#define __builtin_macuRN(Acc, x, y, n) ((((Acc) + ((unsigned short int) (x) * (unsigned short int) (y))) + (1<<((n)-1))) >> (n))

#define __builtin_machhsN(Acc, x, y, n)  (((Acc) + ((short int) ((x)>>16) * (short int) ((y)>>16))) >> (n))
#define __builtin_machhuN(Acc, x, y, n)  (((Acc) + ((unsigned short int) ((x)>>16) * (unsigned short int) ((y)>>16))) >> (n))
#define __builtin_machhsRN(Acc, x, y, n) ((((Acc) + ((short int) ((x)>>16) * (short int) ((y)>>16))) + (1<<((n)-1))) >> (n))
#define __builtin_machhuRN(Acc, x, y, n) ((((Acc) + ((unsigned short int) ((x)>>16) * (unsigned short int) ((y)>>16))) + (n)))

/* Multiplications */
#define __builtin_mulsN(x, y, n)   (((short int) (x) * (short int) (y))>>(n))
#define __builtin_mulsRN(x, y, n)    ((((short int) (x) * (short int) (y)) + (1<<((n)-1)))>>(n))
#define __builtin_muluN(x, y, n)   (((unsigned short int) (x) * (unsigned short int) (y))>>(n))
#define __builtin_muluRN(x, y, n)    ((((unsigned short int) (x) * (unsigned short int) (y)) + (1<<((n)-1)))>>(n))

/* Vectorial product and sum of products */
#define __builtin_dotp2(x, y)    (    (x)[0]*(y)[0] + (x)[1]*(y)[1])
#define __builtin_dotpu2(x, y)   (    (x)[0]*(y)[0] + (x)[1]*(y)[1])
#define __builtin_dotpus2(x, y)    (    (x)[0]*(y)[0] + (x)[1]*(y)[1])

#define __builtin_sumdotp2(x, y, z)    ((z)+(x)[0]*(y)[0] + (x)[1]*(y)[1])
#define __builtin_sumdotpu2(x, y, z)   ((z)+(x)[0]*(y)[0] + (x)[1]*(y)[1])
#define __builtin_sumdotpus2(x, y, z)  ((z)+(x)[0]*(y)[0] + (x)[1]*(y)[1])

#define __builtin_dotp4(x, y)    (    (x)[0]*(y)[0] + (x)[1]*(y)[1] + (x)[2]*(y)[2] + (x)[3]*(y)[3])
#define __builtin_dotpu4(x, y)   (    (x)[0]*(y)[0] + (x)[1]*(y)[1] + (x)[2]*(y)[2] + (x)[3]*(y)[3])
#define __builtin_dotpus4(x, y)    (    (x)[0]*(y)[0] + (x)[1]*(y)[1] + (x)[2]*(y)[2] + (x)[3]*(y)[3])

#define __builtin_sumdotp4(x, y, z)    ((z)+(x)[0]*(y)[0] + (x)[1]*(y)[1] + (x)[2]*(y)[2] + (x)[3]*(y)[3])
#define __builtin_sumdotpu4(x, y, z)   ((z)+(x)[0]*(y)[0] + (x)[1]*(y)[1] + (x)[2]*(y)[2] + (x)[3]*(y)[3])
#define __builtin_sumdotpus4(x, y, z)  ((z)+(x)[0]*(y)[0] + (x)[1]*(y)[1] + (x)[2]*(y)[2] + (x)[3]*(y)[3])


/* Position of the most significant bit of x */
#define __FL1(x)     (31 - __builtin_clz((x)))

/* Number of sign bits */
static inline unsigned int __builtin_clb(unsigned int x) {
  int result = 0;
  while (x) {
    if (x & 1) result++;
    x >>= 1;
  }
  return result;
}

/* Bit Extraction */
#define __builtin_bitextract(x, size, off)   (((((x)>>(off))&((unsigned int)(1<<(size))-1))<<(32-(size)))>>(32-(size)))
#define __builtin_bitextractu(x, size, off)  (((x)>>(off))&((unsigned int)(1<<(size))-1))

/* Bit insertion */
#define __builtin_bitinsert(dst, src, size, off) (((dst) & ~(((1<<(size))-1)<<(off))) | (((src) & ((1<<(size))-1))<<(off)))
#define __builtin_bitinsert_r(dst, src, size, off)   (((dst) & ~(((1<<(size))-1)<<(off))) | (((src) & ((1<<(size))-1))<<(off)))

/* 1 bit rotation to the right, 32 bits input */
#define __builtin_rotr(x)      ((((x)>>1)&0x7FFFFFFF) | ((x)<<31))

/* Add with normalization and rounding */
#define __builtin_addroundnormu(x, y, scale) ((unsigned int)((x) + (y) + (1<<((scale)-1)))>>(scale))
#define __builtin_addroundnorm(x, y, scale)  ((int)((x) + (y) + (1<<((scale)-1)))>>(scale))

/* Normalization and rounding */
#define __builtin_roundnormu(x, scale) ((unsigned int)((x) + (1<<((scale)-1)))>>(scale))
#define __builtin_roundnorm(x, scale)  ((int)((x) + (1<<((scale)-1)))>>(scale))

#endif

#endif
