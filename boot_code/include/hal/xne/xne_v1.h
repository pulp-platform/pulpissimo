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

#ifndef __HAL_XNE_XNE_V1_H__
#define __HAL_XNE_XNE_V1_H__

#include "hal/pulp.h"
#include "archi/xne/xne_v1.h"

#if XNE_VERSION != 1
  #error This file must be included only with XNE version 1.
#endif

/*
 * Control and generic configuration register layout
 * ================================================================================
 *  # reg |  offset  |  bits   |   bitmask    ||  content
 * -------+----------+---------+--------------++-----------------------------------
 *     0  |  0x0000  |  31: 0  |  0xffffffff  ||  TRIGGER
 *     1  |  0x0004  |  31: 0  |  0xffffffff  ||  ACQUIRE
 *     2  |  0x0008  |  31: 0  |  0xffffffff  ||  EVT_ENABLE
 *     3  |  0x000c  |  31: 0  |  0xffffffff  ||  STATUS
 *     4  |  0x0010  |  31: 0  |  0xffffffff  ||  RUNNING_JOB
 *     5  |  0x0014  |  31: 0  |  0xffffffff  ||  SOFT_CLEAR
 *   6-7  |          |         |              ||  Reserved
 *     8  |  0x0020  |  31: 0  |  0xffffffff  ||  BYTECODE[31:0]
 *     9  |  0x0024  |  31: 0  |  0xffffffff  ||  BYTECODE[63:32]
 *    10  |  0x0028  |  31: 0  |  0xffffffff  ||  BYTECODE[95:64]
 *    11  |  0x002c  |  31: 0  |  0xffffffff  ||  BYTECODE[127:96]
 *    12  |  0x0030  |  31: 0  |  0xffffffff  ||  BYTECODE[159:128]
 *    13  |  0x0034  |  31:16  |  0xffff0000  ||  LOOPS[15:0]
 *        |          |  15: 0  |  0x0000ffff  ||  BYTECODE[175:160]
 *    14  |  0x0038  |  31: 0  |  0xffffffff  ||  LOOPS[47:16]
 *    15  |  0x003c  |  31: 0  |  0xffffffff  ||  Reserved
 * ================================================================================
 *
 * Job-dependent registers layout
 * ================================================================================
 *  # reg |  offset  |  bits   |   bitmask    ||  content
 * -------+----------+---------+--------------++-----------------------------------
 *     0  |  0x0040  |  31: 0  |  0xffffffff  ||  X_ADDR
 *     1  |  0x0044  |  31: 0  |  0xffffffff  ||  W_ADDR
 *     2  |  0x0048  |  31: 0  |  0xffffffff  ||  Y_ADDR
 *     3  |  0x004c  |  31:24  |  0xff000000  ||  UCODE_STATIC0.w
 *        |          |  23:16  |  0x00ff0000  ||  UCODE_STATIC0.h
 *        |          |  15: 8  |  0x0000ff00  ||  UCODE_STATIC0.ow
 *        |          |   7: 0  |  0x000000ff  ||  UCODE_STATIC0.oh
 *     4  |  0x0050  |  31:24  |  0xff000000  ||  UCODE_STATIC1.fs0
 *        |          |  23:16  |  0x00ff0000  ||  UCODE_STATIC1.fs1
 *        |          |   7: 0  |  0x000000ff  ||  UCODE_STATIC1.acc
 *     5  |  0x0054  |  27:16  |  0x0fff0000  ||  UCODE_STATIC2.nif
 *        |          |  11: 0  |  0x00000fff  ||  UCODE_STATIC2.nof
 *     6  |  0x0058  |  31: 0  |  0xffffffff  ||  TAU_ADDR
 *     7  |  0x005c  |   3: 0  |  0x0000000f  ||  TAU_SHIFT
 * ================================================================================
 *
 */

/* LOW-LEVEL HAL */
#if PULP_CHIP == CHIP_QUENTIN
  #define XNE_ADDR_BASE  ARCHI_FC_HWPE_ADDR
#else
  #define XNE_ADDR_BASE  HWCE_BASE_ADDR
#endif
#define XNE_ADDR_SPACE 0x00000100

// For all the following functions we use __builtin_pulp_OffsetedWrite and __builtin_pulp_OffsetedRead
// instead of classic load/store because otherwise the compiler is not able to correctly factorize
// the XNE base in case several accesses are done, ending up with twice more code

#if defined(__riscv__) && !defined(RV_ISA_RV32)
#define XNE_WRITE(value, offset) __builtin_pulp_OffsetedWrite(value, (int *)XNE_ADDR_BASE, offset)
#define XNE_READ(offset) __builtin_pulp_OffsetedRead((int *)XNE_ADDR_BASE, offset)
#else
#define XNE_WRITE(value, offset) pulp_write32(XNE_ADDR_BASE + (offset), value)
#define XNE_READ(offset) pulp_read32(XNE_ADDR_BASE + (offset))
#endif

static inline void xne_bytecode_set(unsigned int offs, unsigned int value) {
  XNE_WRITE(value, XNE_BYTECODE+offs);
}

static inline void xne_x_addr_set(unsigned int value) {
  XNE_WRITE(value, XNE_X_ADDR);
}

static inline void xne_w_addr_set(unsigned int value) {
  XNE_WRITE(value, XNE_W_ADDR);
}

static inline void xne_y_addr_set(unsigned int value) {
  XNE_WRITE(value, XNE_Y_ADDR);
}

static inline void xne_ucode_static0_set(unsigned int value) {
  XNE_WRITE(value, XNE_UCODE_STATIC0);
}

static inline void xne_ucode_static1_set(unsigned int value) {
  XNE_WRITE(value, XNE_UCODE_STATIC1);
}

static inline void xne_ucode_static2_set(unsigned int value) {
  XNE_WRITE(value, XNE_UCODE_STATIC2);
}

static inline void xne_tau_addr_set(unsigned int value) {
  XNE_WRITE(value, XNE_TAU_ADDR);
}

static inline void xne_tau_shift_set(unsigned int value) {
  XNE_WRITE(value, XNE_TAU_SHIFT);
}

static inline unsigned int xne_ucode_static0_value(
  unsigned char h,
  unsigned char w,
  unsigned char oh,
  unsigned char ow
) {
  unsigned int res = 0;
#if defined(__riscv__) && !defined(RV_ISA_RV32)
  res = __builtin_bitinsert(0,   w,  8, 24);
  res = __builtin_bitinsert(res, h,  8, 16);
  res = __builtin_bitinsert(res, ow, 8,  8);
  res = __builtin_bitinsert(res, oh, 8,  0);
#else
  res |= ((w  & 0xff) << 24) |
         ((h  & 0xff) << 16) |
         ((ow & 0xff) << 8) |
         ((oh & 0xff));
#endif
  return res;
}

static inline unsigned int xne_ucode_static1_value(
  unsigned char fs0,
  unsigned char fs1,
  unsigned char acc
) {
  unsigned int res = 0;
#if defined(__riscv__) && !defined(RV_ISA_RV32)
  res = __builtin_bitinsert(0,   fs0,  8, 24);
  res = __builtin_bitinsert(res, fs1,  8, 16);
  res = __builtin_bitinsert(res, acc,  8, 0);
#else
  res |= ((fs0 & 0xff) << 24) |
         ((fs1 & 0xff) << 16) |
         ((acc & 0xff));
#endif
  return res;
}

static inline unsigned int xne_ucode_static2_value(
  unsigned short nif,
  unsigned short nof
) {
  unsigned int res = 0;
#if defined(__riscv__) && !defined(RV_ISA_RV32)
  res = __builtin_bitinsert(0,   nif, 16, 16);
  res = __builtin_bitinsert(res, nof, 16,  0);
#else
  res |= ((nif & 0xffff) << 16) |
         ((nof & 0xffff));
#endif
  return res;
}

static inline unsigned int xne_tau_shift_value(
  unsigned char shift
) {
  unsigned int res = 0;
#if defined(__riscv__) && !defined(RV_ISA_RV32)
  res = __builtin_bitinsert(0, shift, 4, 0);
#else
  res |= shift << 4;
#endif
  return res;
}

static inline void xne_wait_event() {
#if PULP_CHIP != CHIP_QUENTIN
  eu_evt_maskWaitAndClr(1 << PLP_EVT_ACC0);
#endif
}

static inline void xne_trigger_job() {
  XNE_WRITE(0, XNE_TRIGGER);
}

static inline int xne_acquire_job() {
  return XNE_READ(XNE_ACQUIRE);
}

static inline unsigned int xne_get_status() {
  return XNE_READ(XNE_STATUS);
}

static inline void xne_soft_clear() {
  volatile int i;
  XNE_WRITE(0, XNE_SOFT_CLEAR);
}

static inline void plp_xne_enable() {
#ifdef ARCHI_HAS_CLUSTER
  *(volatile int*) (EOC_UNIT_BASE_ADDR + (3 << 3)) |=  0xc00;
#endif
}

static inline void plp_xne_disable() {
#ifdef ARCHI_HAS_CLUSTER
  *(volatile int*) (EOC_UNIT_BASE_ADDR + (3 << 3)) &= ~0xc00;
#endif
}

#endif /* __HAL_XNE_V1_H__ */

