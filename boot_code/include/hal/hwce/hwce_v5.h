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

#ifndef __HAL_HWCE_HWCE_V5_H__
#define __HAL_HWCE_HWCE_V5_H__

#include "hal/pulp.h"
#include "archi/hwce/hwce_v5.h"

#if HWCE_VERSION != 5
#error This file must be included only with HWCE version 5
#endif

#define NB_HWCE 1

// if defined, use builtin bitinsert -- otherwise, implement in SW (slower :)
#if defined(__riscv__) && !defined(RV_ISA_RV32)
  #define __hwce_bitinsert __builtin_bitinsert
#else
  #define __hwce_bitinsert(a,b,c,d) (a | (((b << (32-c)) >> (32-c)) << d))
#endif

/* LOW-LEVEL HAL */
#define HWCE_ADDR_BASE  ARCHI_HWCE_ADDR

// For all the following functions we use __builtin_pulp_OffsetedWrite and __builtin_pulp_OffsetedRead
// instead of classic load/store because otherwise the compiler is not able to correctly factorize
// the HWCE base in case several accesses are done, ending up with twice more code

#if defined(__riscv__) && !defined(RV_ISA_RV32)
#define HWCE_WRITE(value, offset) __builtin_pulp_OffsetedWrite(value, (int *)HWCE_ADDR_BASE, offset)
#define HWCE_READ(offset) __builtin_pulp_OffsetedRead((int *)HWCE_ADDR_BASE, offset)
#else
#define HWCE_WRITE(value, offset) pulp_write32(HWCE_ADDR_BASE + (offset), value)
#define HWCE_READ(offset) pulp_read32(HWCE_ADDR_BASE + (offset))
#endif

static inline void hwce_y_trans_size_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_Y_TRANS_SIZE);
}

static inline void hwce_y_line_stride_length_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_Y_LINE_STRIDE_LENGTH);
}

static inline void hwce_y_feat_stride_length_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_Y_FEAT_STRIDE_LENGTH);
}

static inline void hwce_y_out_3_base_addr_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_Y_OUT_3_BASE_ADDR);
}

static inline void hwce_y_out_2_base_addr_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_Y_OUT_2_BASE_ADDR);
}

static inline void hwce_y_out_1_base_addr_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_Y_OUT_1_BASE_ADDR);
}

static inline void hwce_y_out_0_base_addr_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_Y_OUT_0_BASE_ADDR);
}

static inline void hwce_y_in_3_base_addr_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_Y_IN_3_BASE_ADDR);
}

static inline void hwce_y_in_2_base_addr_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_Y_IN_2_BASE_ADDR);
}

static inline void hwce_y_in_1_base_addr_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_Y_IN_1_BASE_ADDR);
}

static inline void hwce_y_in_0_base_addr_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_Y_IN_0_BASE_ADDR);
}

static inline void hwce_x_trans_size_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_X_TRANS_SIZE);
}

static inline void hwce_x_line_stride_length_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_X_LINE_STRIDE_LENGTH);
}

static inline void hwce_x_feat_stride_length_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_X_FEAT_STRIDE_LENGTH);
}

static inline void hwce_x_in_base_addr_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_X_IN_BASE_ADDR);
}

static inline void hwce_w_base_addr_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_W_BASE_ADDR);
}

static inline void hwce_gen_config0_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_GEN_CONFIG0);
}

static inline unsigned int hwce_gen_config0_get() {
  return HWCE_READ(HWCE_GEN_CONFIG0);
}
 
static inline void hwce_gen_config1_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_GEN_CONFIG1);
}
 
static inline unsigned int hwce_gen_config1_get() {
  return HWCE_READ(HWCE_GEN_CONFIG1);
}
 
static inline void hwce_gen_config2_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_GEN_CONFIG2);
}
 
static inline unsigned int hwce_gen_config2_get() {
  return HWCE_READ(HWCE_GEN_CONFIG2);
}
 
static inline void hwce_job_config0_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_JOB_CONFIG0);
}

static inline void hwce_job_config1_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_JOB_CONFIG1);
}

static inline void hwce_job_config2_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_JOB_CONFIG2);
}

static inline void hwce_th_base_addr_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_TH_BASE_ADDR);
}

static inline void hwce_lbufxtranssize_set(unsigned int value) {
  HWCE_WRITE(value, HWCE_LBUFXTRANSSIZE_ADDR);
}

static inline unsigned int hwce_stride_length_value(unsigned int stride, unsigned int length) {
  unsigned int res = 0;
  res = __hwce_bitinsert(0,   stride, 16, 16);
  res = __hwce_bitinsert(res, length, 16, 0 );
  return res;
}

static inline unsigned int hwce_gen_config0_value(unsigned int wstride, unsigned int ncp, unsigned int conv, unsigned vect, unsigned int uns, unsigned int ny, unsigned int nf, unsigned int qf, unsigned int rnd) {
  unsigned int res;
  res = __hwce_bitinsert(0, wstride, 16, 16);
  // res = __hwce_bitinsert(0, norm_bias, 1, 15);
  res = __hwce_bitinsert(res, rnd    , 1 , 14);
  res = __hwce_bitinsert(res, ncp    , 1 , 13);
  res = __hwce_bitinsert(res, conv   , 2 , 11);
  res = __hwce_bitinsert(res, vect   , 2 , 9);
  res = __hwce_bitinsert(res, 0      , 1 , 8);
  res = __hwce_bitinsert(res, ny     , 1 , 7);
  res = __hwce_bitinsert(res, nf     , 1 , 6);
  res = __hwce_bitinsert(res, qf     , 6 , 0);
  return res;
}
 
static inline unsigned int hwce_gen_config1_value(unsigned int qmodex, unsigned int qshiftx, unsigned int qmodey, unsigned int qshifty, unsigned int thstride) {
  unsigned int res = 0;
  res = __hwce_bitinsert(res, qmodex,   3, 29);
  res = __hwce_bitinsert(res, qshiftx,  5, 24);
  res = __hwce_bitinsert(res, qmodey,   3, 21);
  res = __hwce_bitinsert(res, qshifty,  5, 16);
  res = __hwce_bitinsert(res, thstride, 16, 0);
  return res;
}
 
static inline unsigned int hwce_gen_config2_value(unsigned int qmodew, unsigned int qshiftw, unsigned int wait_nfeat) {
  unsigned int res = 0;
  res = __builtin_bitinsert(res, qmodew,     3, 29);
  res = __builtin_bitinsert(res, qshiftw,    5, 24);
  res = __builtin_bitinsert(res, wait_nfeat, 8, 16);
  return res;
}
 
static inline unsigned int hwce_job_config0_value(unsigned int noyconst, unsigned int lbuflen, unsigned int lbufskiphi,  unsigned int lbufskiplo) {
  unsigned int res = 0;
  res = __hwce_bitinsert(res, noyconst,   16, 16);
  res = __hwce_bitinsert(res, lbufskiphi, 4,  12);
  res = __hwce_bitinsert(res, lbufskiplo, 4,  8);
  res = __hwce_bitinsert(res, lbuflen,    8,  0);
  return res;
}
 
static inline unsigned int hwce_job_config1_value(unsigned int lo, unsigned int wif, unsigned int wof, unsigned int vect_disable_mask, unsigned int rect, unsigned int noutfeat) {
  unsigned int res = 0;
  res = __hwce_bitinsert(res, noutfeat         , 8 , 24);
  res = __hwce_bitinsert(res, lo               , 1 , 23);
  res = __hwce_bitinsert(res, rect             , 1 , 22);
  res = __hwce_bitinsert(res, wif              , 6 , 16);
  res = __hwce_bitinsert(res, wof              , 6 , 8);
  res = __hwce_bitinsert(res, vect_disable_mask, 4 , 0);
  return res;
}
 
static inline unsigned int hwce_job_config2_value(unsigned int bynfeat, unsigned int bye, unsigned int s2, unsigned int lbufprecnt, unsigned int xlrem, unsigned int ylrem, unsigned int ylen) {
  unsigned int res;
  res = __hwce_bitinsert(0, bynfeat            , 8 , 24);
  res = __hwce_bitinsert(res, bye              , 1 , 23);
  res = __hwce_bitinsert(res, s2               , 1 , 22);
  res = __hwce_bitinsert(res, xlrem            , 2 , 20);
  res = __hwce_bitinsert(res, ylrem            , 2 , 18);
  res = __hwce_bitinsert(res, ylen             , 8 , 8);
  res = __hwce_bitinsert(res, lbufprecnt       , 8 , 0);
  return res;
}

static inline void hwce_wait_event() {
  eu_evt_maskWaitAndClr(1 << EVENT_HWCE);
}

static inline void hwce_trigger_job() {
  HWCE_WRITE(0, HWCE_TRIGGER);
}

static inline void hwce_sw_evt() {
  HWCE_WRITE(0, HWCE_SW_EVT);
}

static inline int hwce_acquire_job() {
  return HWCE_READ(HWCE_ACQUIRE);
}

static inline void hwce_soft_clear() {
  volatile int i;
  HWCE_WRITE(1, HWCE_SOFT_CLEAR);
  for(i=0; i<3; i++);
  HWCE_WRITE(0, HWCE_SOFT_CLEAR);
}

static inline void hwce_cg_enable() {
  *(volatile int*) (ARCHI_CLUSTER_CTRL_ADDR + (3 << 3)) |=  0xc00;
}

static inline void hwce_cg_disable() {
  *(volatile int*) (ARCHI_CLUSTER_CTRL_ADDR + (3 << 3)) &= ~0xc00;
}

#endif /* __HWCE_HAL_H__ */

