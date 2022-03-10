
/* THIS FILE HAS BEEN GENERATED, DO NOT MODIFY IT.
 */

/*
 * Copyright (C) 2018 ETH Zurich, University of Bologna
 * and GreenWaves Technologies
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

#ifndef __INCLUDE_ARCHI_TIMER_TIMER_V2_H__
#define __INCLUDE_ARCHI_TIMER_TIMER_V2_H__

#ifndef LANGUAGE_ASSEMBLY

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS
//

// Timer Low Configuration register.
#define TIMER_CFG_LO_OFFSET                      0x0

// Timer High Configuration register.
#define TIMER_CFG_HI_OFFSET                      0x4

// Timer Low counter value register.
#define TIMER_CNT_LO_OFFSET                      0x8

// Timer High counter value register.
#define TIMER_CNT_HI_OFFSET                      0xc

// Timer Low comparator value register.
#define TIMER_CMP_LO_OFFSET                      0x10

// Timer High comparator value register.
#define TIMER_CMP_HI_OFFSET                      0x14

// Start Timer Low counting register.
#define TIMER_START_LO_OFFSET                    0x18

// Start Timer High counting register.
#define TIMER_START_HI_OFFSET                    0x1c

// Reset Timer Low counter register.
#define TIMER_RESET_LO_OFFSET                    0x20

// Reset Timer High counter register.
#define TIMER_RESET_HI_OFFSET                    0x24



//
// REGISTERS FIELDS
//

// Timer low enable configuration bitfield: - 1'b0: disabled - 1'b1: enabled (access: R/W)
#define TIMER_CFG_LO_ENABLE_BIT                                      0
#define TIMER_CFG_LO_ENABLE_WIDTH                                    1
#define TIMER_CFG_LO_ENABLE_MASK                                     0x1

// Timer low counter reset command bitfield. Cleared after Timer Low reset execution. (access: R/W)
#define TIMER_CFG_LO_RESET_BIT                                       1
#define TIMER_CFG_LO_RESET_WIDTH                                     1
#define TIMER_CFG_LO_RESET_MASK                                      0x2

// Timer low compare match interrupt enable configuration bitfield: - 1'b0: disabled - 1'b1: enabled (access: R/W)
#define TIMER_CFG_LO_IRQEN_BIT                                       2
#define TIMER_CFG_LO_IRQEN_WIDTH                                     1
#define TIMER_CFG_LO_IRQEN_MASK                                      0x4

// Timer low input event mask configuration bitfield: - 1'b0: disabled - 1'b1: enabled (access: R/W)
#define TIMER_CFG_LO_IEM_BIT                                         3
#define TIMER_CFG_LO_IEM_WIDTH                                       1
#define TIMER_CFG_LO_IEM_MASK                                        0x8

// Timer low continuous mode configuration bitfield: - 1'b0: Continue mode - continue incrementing Timer low counter when compare match with CMP_LO occurs. - 1'b1: Cycle mode - reset Timer low counter when compare match with CMP_LO occurs. (access: R/W)
#define TIMER_CFG_LO_MODE_BIT                                        4
#define TIMER_CFG_LO_MODE_WIDTH                                      1
#define TIMER_CFG_LO_MODE_MASK                                       0x10

// Timer low one shot configuration bitfield: - 1'b0: let Timer low enabled counting when compare match with CMP_LO occurs. - 1'b1: disable Timer low when compare match with CMP_LO occurs. (access: R/W)
#define TIMER_CFG_LO_ONE_S_BIT                                       5
#define TIMER_CFG_LO_ONE_S_WIDTH                                     1
#define TIMER_CFG_LO_ONE_S_MASK                                      0x20

// Timer low prescaler enable configuration bitfield:- 1'b0: disabled - 1'b1: enabled (access: R/W)
#define TIMER_CFG_LO_PEN_BIT                                         6
#define TIMER_CFG_LO_PEN_WIDTH                                       1
#define TIMER_CFG_LO_PEN_MASK                                        0x40

// Timer low clock source configuration bitfield: - 1'b0: FLL or FLL+Prescaler - 1'b1: Reference clock at 32kHz (access: R/W)
#define TIMER_CFG_LO_CCFG_BIT                                        7
#define TIMER_CFG_LO_CCFG_WIDTH                                      1
#define TIMER_CFG_LO_CCFG_MASK                                       0x80

// Timer low prescaler value bitfield. Ftimer = Fclk / (1 + PRESC_VAL) (access: R/W)
#define TIMER_CFG_LO_PVAL_BIT                                        8
#define TIMER_CFG_LO_PVAL_WIDTH                                      8
#define TIMER_CFG_LO_PVAL_MASK                                       0xff00

// Timer low  + Timer high 64bit cascaded mode configuration bitfield. (access: R/W)
#define TIMER_CFG_LO_CASC_BIT                                        31
#define TIMER_CFG_LO_CASC_WIDTH                                      1
#define TIMER_CFG_LO_CASC_MASK                                       0x80000000

// Timer high enable configuration bitfield: - 1'b0: disabled - 1'b1: enabled (access: R/W)
#define TIMER_CFG_HI_ENABLE_BIT                                      0
#define TIMER_CFG_HI_ENABLE_WIDTH                                    1
#define TIMER_CFG_HI_ENABLE_MASK                                     0x1

// Timer high counter reset command bitfield. Cleared after Timer high reset execution. (access: W)
#define TIMER_CFG_HI_RESET_BIT                                       1
#define TIMER_CFG_HI_RESET_WIDTH                                     1
#define TIMER_CFG_HI_RESET_MASK                                      0x2

// Timer high compare match interrupt enable configuration bitfield: - 1'b0: disabled - 1'b1: enabled (access: R/W)
#define TIMER_CFG_HI_IRQEN_BIT                                       2
#define TIMER_CFG_HI_IRQEN_WIDTH                                     1
#define TIMER_CFG_HI_IRQEN_MASK                                      0x4

// Timer high input event mask configuration bitfield: - 1'b0: disabled - 1'b1: enabled (access: R/W)
#define TIMER_CFG_HI_IEM_BIT                                         3
#define TIMER_CFG_HI_IEM_WIDTH                                       1
#define TIMER_CFG_HI_IEM_MASK                                        0x8

// Timer high continuous mode configuration bitfield: - 1'b0: Continue mode - continue incrementing Timer high counter when compare match with CMP_LO occurs. - 1'b1: Cycle mode - reset Timer high counter when compare match with CMP_LO occurs. (access: R/W)
#define TIMER_CFG_HI_MODE_BIT                                        4
#define TIMER_CFG_HI_MODE_WIDTH                                      1
#define TIMER_CFG_HI_MODE_MASK                                       0x10

// Timer high one shot configuration bitfield: - 1'b0: let Timer high enabled counting when compare match with CMP_LO occurs. - 1'b1: disable Timer high when compare match with CMP_LO occurs. (access: R/W)
#define TIMER_CFG_HI_ONE_S_BIT                                       5
#define TIMER_CFG_HI_ONE_S_WIDTH                                     1
#define TIMER_CFG_HI_ONE_S_MASK                                      0x20

// Timer high prescaler enable configuration bitfield: - 1'b0: disabled - 1'b1: enabled (access: R/W)
#define TIMER_CFG_HI_PEN_BIT                                         6
#define TIMER_CFG_HI_PEN_WIDTH                                       1
#define TIMER_CFG_HI_PEN_MASK                                        0x40

// Timer high clock source configuration bitfield: - 1'b0: FLL or FLL+Prescaler - 1'b1: Reference clock at 32kHz (access: R/W)
#define TIMER_CFG_HI_CLKCFG_BIT                                      7
#define TIMER_CFG_HI_CLKCFG_WIDTH                                    1
#define TIMER_CFG_HI_CLKCFG_MASK                                     0x80

// Timer Low counter value bitfield. (access: R/W)
#define TIMER_CNT_LO_CNT_LO_BIT                                      0
#define TIMER_CNT_LO_CNT_LO_WIDTH                                    32
#define TIMER_CNT_LO_CNT_LO_MASK                                     0xffffffff

// Timer High counter value bitfield. (access: R/W)
#define TIMER_CNT_HI_CNT_HI_BIT                                      0
#define TIMER_CNT_HI_CNT_HI_WIDTH                                    32
#define TIMER_CNT_HI_CNT_HI_MASK                                     0xffffffff

// Timer Low comparator value bitfield. (access: R/W)
#define TIMER_CMP_LO_CMP_LO_BIT                                      0
#define TIMER_CMP_LO_CMP_LO_WIDTH                                    32
#define TIMER_CMP_LO_CMP_LO_MASK                                     0xffffffff

// Timer High comparator value bitfield. (access: R/W)
#define TIMER_CMP_HI_CMP_HI_BIT                                      0
#define TIMER_CMP_HI_CMP_HI_WIDTH                                    32
#define TIMER_CMP_HI_CMP_HI_MASK                                     0xffffffff

// Timer Low start command bitfield. When executed, CFG_LO.ENABLE is set. (access: W)
#define TIMER_START_LO_STRT_LO_BIT                                   0
#define TIMER_START_LO_STRT_LO_WIDTH                                 1
#define TIMER_START_LO_STRT_LO_MASK                                  0x1

// Timer High start command bitfield. When executed, CFG_HI.ENABLE is set. (access: W)
#define TIMER_START_HI_STRT_HI_BIT                                   0
#define TIMER_START_HI_STRT_HI_WIDTH                                 1
#define TIMER_START_HI_STRT_HI_MASK                                  0x1

// Timer Low counter reset command bitfield. When executed, CFG_LO.RESET is set. (access: W)
#define TIMER_RESET_LO_RST_LO_BIT                                    0
#define TIMER_RESET_LO_RST_LO_WIDTH                                  1
#define TIMER_RESET_LO_RST_LO_MASK                                   0x1

// Timer High counter reset command bitfield. When executed, CFG_HI.RESET is set. (access: W)
#define TIMER_RESET_HI_RST_HI_BIT                                    0
#define TIMER_RESET_HI_RST_HI_WIDTH                                  1
#define TIMER_RESET_HI_RST_HI_MASK                                   0x1



//
// REGISTERS STRUCTS
//

#ifndef LANGUAGE_ASSEMBLY

typedef union {
  struct {
    unsigned int enable          :1 ; // Timer low enable configuration bitfield: - 1'b0: disabled - 1'b1: enabled
    unsigned int reset           :1 ; // Timer low counter reset command bitfield. Cleared after Timer Low reset execution.
    unsigned int irqen           :1 ; // Timer low compare match interrupt enable configuration bitfield: - 1'b0: disabled - 1'b1: enabled
    unsigned int iem             :1 ; // Timer low input event mask configuration bitfield: - 1'b0: disabled - 1'b1: enabled
    unsigned int mode            :1 ; // Timer low continuous mode configuration bitfield: - 1'b0: Continue mode - continue incrementing Timer low counter when compare match with CMP_LO occurs. - 1'b1: Cycle mode - reset Timer low counter when compare match with CMP_LO occurs.
    unsigned int one_s           :1 ; // Timer low one shot configuration bitfield: - 1'b0: let Timer low enabled counting when compare match with CMP_LO occurs. - 1'b1: disable Timer low when compare match with CMP_LO occurs.
    unsigned int pen             :1 ; // Timer low prescaler enable configuration bitfield:- 1'b0: disabled - 1'b1: enabled
    unsigned int ccfg            :1 ; // Timer low clock source configuration bitfield: - 1'b0: FLL or FLL+Prescaler - 1'b1: Reference clock at 32kHz
    unsigned int pval            :8 ; // Timer low prescaler value bitfield. Ftimer = Fclk / (1 + PRESC_VAL)
    unsigned int padding0:15;
    unsigned int casc            :1 ; // Timer low  + Timer high 64bit cascaded mode configuration bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) timer_cfg_lo_t;

typedef union {
  struct {
    unsigned int enable          :1 ; // Timer high enable configuration bitfield: - 1'b0: disabled - 1'b1: enabled
    unsigned int reset           :1 ; // Timer high counter reset command bitfield. Cleared after Timer high reset execution.
    unsigned int irqen           :1 ; // Timer high compare match interrupt enable configuration bitfield: - 1'b0: disabled - 1'b1: enabled
    unsigned int iem             :1 ; // Timer high input event mask configuration bitfield: - 1'b0: disabled - 1'b1: enabled
    unsigned int mode            :1 ; // Timer high continuous mode configuration bitfield: - 1'b0: Continue mode - continue incrementing Timer high counter when compare match with CMP_LO occurs. - 1'b1: Cycle mode - reset Timer high counter when compare match with CMP_LO occurs.
    unsigned int one_s           :1 ; // Timer high one shot configuration bitfield: - 1'b0: let Timer high enabled counting when compare match with CMP_LO occurs. - 1'b1: disable Timer high when compare match with CMP_LO occurs.
    unsigned int pen             :1 ; // Timer high prescaler enable configuration bitfield: - 1'b0: disabled - 1'b1: enabled
    unsigned int clkcfg          :1 ; // Timer high clock source configuration bitfield: - 1'b0: FLL or FLL+Prescaler - 1'b1: Reference clock at 32kHz
  };
  unsigned int raw;
} __attribute__((packed)) timer_cfg_hi_t;

typedef union {
  struct {
    unsigned int cnt_lo          :32; // Timer Low counter value bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) timer_cnt_lo_t;

typedef union {
  struct {
    unsigned int cnt_hi          :32; // Timer High counter value bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) timer_cnt_hi_t;

typedef union {
  struct {
    unsigned int cmp_lo          :32; // Timer Low comparator value bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) timer_cmp_lo_t;

typedef union {
  struct {
    unsigned int cmp_hi          :32; // Timer High comparator value bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) timer_cmp_hi_t;

typedef union {
  struct {
    unsigned int strt_lo         :1 ; // Timer Low start command bitfield. When executed, CFG_LO.ENABLE is set.
  };
  unsigned int raw;
} __attribute__((packed)) timer_start_lo_t;

typedef union {
  struct {
    unsigned int strt_hi         :1 ; // Timer High start command bitfield. When executed, CFG_HI.ENABLE is set.
  };
  unsigned int raw;
} __attribute__((packed)) timer_start_hi_t;

typedef union {
  struct {
    unsigned int rst_lo          :1 ; // Timer Low counter reset command bitfield. When executed, CFG_LO.RESET is set.
  };
  unsigned int raw;
} __attribute__((packed)) timer_reset_lo_t;

typedef union {
  struct {
    unsigned int rst_hi          :1 ; // Timer High counter reset command bitfield. When executed, CFG_HI.RESET is set.
  };
  unsigned int raw;
} __attribute__((packed)) timer_reset_hi_t;

#endif



//
// REGISTERS STRUCTS
//

#ifdef __GVSOC__

class vp_timer_cfg_lo : public vp::reg_32
{
public:
  inline void enable_set(uint32_t value) { this->set_field(value, TIMER_CFG_LO_ENABLE_BIT, TIMER_CFG_LO_ENABLE_WIDTH); }
  inline uint32_t enable_get() { return this->get_field(TIMER_CFG_LO_ENABLE_BIT, TIMER_CFG_LO_ENABLE_WIDTH); }
  inline void reset_set(uint32_t value) { this->set_field(value, TIMER_CFG_LO_RESET_BIT, TIMER_CFG_LO_RESET_WIDTH); }
  inline uint32_t reset_get() { return this->get_field(TIMER_CFG_LO_RESET_BIT, TIMER_CFG_LO_RESET_WIDTH); }
  inline void irqen_set(uint32_t value) { this->set_field(value, TIMER_CFG_LO_IRQEN_BIT, TIMER_CFG_LO_IRQEN_WIDTH); }
  inline uint32_t irqen_get() { return this->get_field(TIMER_CFG_LO_IRQEN_BIT, TIMER_CFG_LO_IRQEN_WIDTH); }
  inline void iem_set(uint32_t value) { this->set_field(value, TIMER_CFG_LO_IEM_BIT, TIMER_CFG_LO_IEM_WIDTH); }
  inline uint32_t iem_get() { return this->get_field(TIMER_CFG_LO_IEM_BIT, TIMER_CFG_LO_IEM_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, TIMER_CFG_LO_MODE_BIT, TIMER_CFG_LO_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(TIMER_CFG_LO_MODE_BIT, TIMER_CFG_LO_MODE_WIDTH); }
  inline void one_s_set(uint32_t value) { this->set_field(value, TIMER_CFG_LO_ONE_S_BIT, TIMER_CFG_LO_ONE_S_WIDTH); }
  inline uint32_t one_s_get() { return this->get_field(TIMER_CFG_LO_ONE_S_BIT, TIMER_CFG_LO_ONE_S_WIDTH); }
  inline void pen_set(uint32_t value) { this->set_field(value, TIMER_CFG_LO_PEN_BIT, TIMER_CFG_LO_PEN_WIDTH); }
  inline uint32_t pen_get() { return this->get_field(TIMER_CFG_LO_PEN_BIT, TIMER_CFG_LO_PEN_WIDTH); }
  inline void ccfg_set(uint32_t value) { this->set_field(value, TIMER_CFG_LO_CCFG_BIT, TIMER_CFG_LO_CCFG_WIDTH); }
  inline uint32_t ccfg_get() { return this->get_field(TIMER_CFG_LO_CCFG_BIT, TIMER_CFG_LO_CCFG_WIDTH); }
  inline void pval_set(uint32_t value) { this->set_field(value, TIMER_CFG_LO_PVAL_BIT, TIMER_CFG_LO_PVAL_WIDTH); }
  inline uint32_t pval_get() { return this->get_field(TIMER_CFG_LO_PVAL_BIT, TIMER_CFG_LO_PVAL_WIDTH); }
  inline void casc_set(uint32_t value) { this->set_field(value, TIMER_CFG_LO_CASC_BIT, TIMER_CFG_LO_CASC_WIDTH); }
  inline uint32_t casc_get() { return this->get_field(TIMER_CFG_LO_CASC_BIT, TIMER_CFG_LO_CASC_WIDTH); }
};

class vp_timer_cfg_hi : public vp::reg_32
{
public:
  inline void enable_set(uint32_t value) { this->set_field(value, TIMER_CFG_HI_ENABLE_BIT, TIMER_CFG_HI_ENABLE_WIDTH); }
  inline uint32_t enable_get() { return this->get_field(TIMER_CFG_HI_ENABLE_BIT, TIMER_CFG_HI_ENABLE_WIDTH); }
  inline void reset_set(uint32_t value) { this->set_field(value, TIMER_CFG_HI_RESET_BIT, TIMER_CFG_HI_RESET_WIDTH); }
  inline uint32_t reset_get() { return this->get_field(TIMER_CFG_HI_RESET_BIT, TIMER_CFG_HI_RESET_WIDTH); }
  inline void irqen_set(uint32_t value) { this->set_field(value, TIMER_CFG_HI_IRQEN_BIT, TIMER_CFG_HI_IRQEN_WIDTH); }
  inline uint32_t irqen_get() { return this->get_field(TIMER_CFG_HI_IRQEN_BIT, TIMER_CFG_HI_IRQEN_WIDTH); }
  inline void iem_set(uint32_t value) { this->set_field(value, TIMER_CFG_HI_IEM_BIT, TIMER_CFG_HI_IEM_WIDTH); }
  inline uint32_t iem_get() { return this->get_field(TIMER_CFG_HI_IEM_BIT, TIMER_CFG_HI_IEM_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, TIMER_CFG_HI_MODE_BIT, TIMER_CFG_HI_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(TIMER_CFG_HI_MODE_BIT, TIMER_CFG_HI_MODE_WIDTH); }
  inline void one_s_set(uint32_t value) { this->set_field(value, TIMER_CFG_HI_ONE_S_BIT, TIMER_CFG_HI_ONE_S_WIDTH); }
  inline uint32_t one_s_get() { return this->get_field(TIMER_CFG_HI_ONE_S_BIT, TIMER_CFG_HI_ONE_S_WIDTH); }
  inline void pen_set(uint32_t value) { this->set_field(value, TIMER_CFG_HI_PEN_BIT, TIMER_CFG_HI_PEN_WIDTH); }
  inline uint32_t pen_get() { return this->get_field(TIMER_CFG_HI_PEN_BIT, TIMER_CFG_HI_PEN_WIDTH); }
  inline void clkcfg_set(uint32_t value) { this->set_field(value, TIMER_CFG_HI_CLKCFG_BIT, TIMER_CFG_HI_CLKCFG_WIDTH); }
  inline uint32_t clkcfg_get() { return this->get_field(TIMER_CFG_HI_CLKCFG_BIT, TIMER_CFG_HI_CLKCFG_WIDTH); }
};

class vp_timer_cnt_lo : public vp::reg_32
{
public:
  inline void cnt_lo_set(uint32_t value) { this->set_field(value, TIMER_CNT_LO_CNT_LO_BIT, TIMER_CNT_LO_CNT_LO_WIDTH); }
  inline uint32_t cnt_lo_get() { return this->get_field(TIMER_CNT_LO_CNT_LO_BIT, TIMER_CNT_LO_CNT_LO_WIDTH); }
};

class vp_timer_cnt_hi : public vp::reg_32
{
public:
  inline void cnt_hi_set(uint32_t value) { this->set_field(value, TIMER_CNT_HI_CNT_HI_BIT, TIMER_CNT_HI_CNT_HI_WIDTH); }
  inline uint32_t cnt_hi_get() { return this->get_field(TIMER_CNT_HI_CNT_HI_BIT, TIMER_CNT_HI_CNT_HI_WIDTH); }
};

class vp_timer_cmp_lo : public vp::reg_32
{
public:
  inline void cmp_lo_set(uint32_t value) { this->set_field(value, TIMER_CMP_LO_CMP_LO_BIT, TIMER_CMP_LO_CMP_LO_WIDTH); }
  inline uint32_t cmp_lo_get() { return this->get_field(TIMER_CMP_LO_CMP_LO_BIT, TIMER_CMP_LO_CMP_LO_WIDTH); }
};

class vp_timer_cmp_hi : public vp::reg_32
{
public:
  inline void cmp_hi_set(uint32_t value) { this->set_field(value, TIMER_CMP_HI_CMP_HI_BIT, TIMER_CMP_HI_CMP_HI_WIDTH); }
  inline uint32_t cmp_hi_get() { return this->get_field(TIMER_CMP_HI_CMP_HI_BIT, TIMER_CMP_HI_CMP_HI_WIDTH); }
};

class vp_timer_start_lo : public vp::reg_32
{
public:
  inline void strt_lo_set(uint32_t value) { this->set_field(value, TIMER_START_LO_STRT_LO_BIT, TIMER_START_LO_STRT_LO_WIDTH); }
  inline uint32_t strt_lo_get() { return this->get_field(TIMER_START_LO_STRT_LO_BIT, TIMER_START_LO_STRT_LO_WIDTH); }
};

class vp_timer_start_hi : public vp::reg_32
{
public:
  inline void strt_hi_set(uint32_t value) { this->set_field(value, TIMER_START_HI_STRT_HI_BIT, TIMER_START_HI_STRT_HI_WIDTH); }
  inline uint32_t strt_hi_get() { return this->get_field(TIMER_START_HI_STRT_HI_BIT, TIMER_START_HI_STRT_HI_WIDTH); }
};

class vp_timer_reset_lo : public vp::reg_32
{
public:
  inline void rst_lo_set(uint32_t value) { this->set_field(value, TIMER_RESET_LO_RST_LO_BIT, TIMER_RESET_LO_RST_LO_WIDTH); }
  inline uint32_t rst_lo_get() { return this->get_field(TIMER_RESET_LO_RST_LO_BIT, TIMER_RESET_LO_RST_LO_WIDTH); }
};

class vp_timer_reset_hi : public vp::reg_32
{
public:
  inline void rst_hi_set(uint32_t value) { this->set_field(value, TIMER_RESET_HI_RST_HI_BIT, TIMER_RESET_HI_RST_HI_WIDTH); }
  inline uint32_t rst_hi_get() { return this->get_field(TIMER_RESET_HI_RST_HI_BIT, TIMER_RESET_HI_RST_HI_WIDTH); }
};

#endif



//
// REGISTERS GLOBAL STRUCT
//

#ifndef LANGUAGE_ASSEMBLY

typedef struct {
  unsigned int cfg_lo          ; // Timer Low Configuration register.
  unsigned int cfg_hi          ; // Timer High Configuration register.
  unsigned int cnt_lo          ; // Timer Low counter value register.
  unsigned int cnt_hi          ; // Timer High counter value register.
  unsigned int cmp_lo          ; // Timer Low comparator value register.
  unsigned int cmp_hi          ; // Timer High comparator value register.
  unsigned int start_lo        ; // Start Timer Low counting register.
  unsigned int start_hi        ; // Start Timer High counting register.
  unsigned int reset_lo        ; // Reset Timer Low counter register.
  unsigned int reset_hi        ; // Reset Timer High counter register.
} __attribute__((packed)) timer_timer_t;

#endif



//
// REGISTERS ACCESS FUNCTIONS
//

#ifndef LANGUAGE_ASSEMBLY

static inline uint32_t timer_cfg_lo_get(uint32_t base) { return ARCHI_READ(base, TIMER_CFG_LO_OFFSET); }
static inline void timer_cfg_lo_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, TIMER_CFG_LO_OFFSET, value); }

static inline uint32_t timer_cfg_hi_get(uint32_t base) { return ARCHI_READ(base, TIMER_CFG_HI_OFFSET); }
static inline void timer_cfg_hi_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, TIMER_CFG_HI_OFFSET, value); }

static inline uint32_t timer_cnt_lo_get(uint32_t base) { return ARCHI_READ(base, TIMER_CNT_LO_OFFSET); }
static inline void timer_cnt_lo_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, TIMER_CNT_LO_OFFSET, value); }

static inline uint32_t timer_cnt_hi_get(uint32_t base) { return ARCHI_READ(base, TIMER_CNT_HI_OFFSET); }
static inline void timer_cnt_hi_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, TIMER_CNT_HI_OFFSET, value); }

static inline uint32_t timer_cmp_lo_get(uint32_t base) { return ARCHI_READ(base, TIMER_CMP_LO_OFFSET); }
static inline void timer_cmp_lo_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, TIMER_CMP_LO_OFFSET, value); }

static inline uint32_t timer_cmp_hi_get(uint32_t base) { return ARCHI_READ(base, TIMER_CMP_HI_OFFSET); }
static inline void timer_cmp_hi_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, TIMER_CMP_HI_OFFSET, value); }

static inline uint32_t timer_start_lo_get(uint32_t base) { return ARCHI_READ(base, TIMER_START_LO_OFFSET); }
static inline void timer_start_lo_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, TIMER_START_LO_OFFSET, value); }

static inline uint32_t timer_start_hi_get(uint32_t base) { return ARCHI_READ(base, TIMER_START_HI_OFFSET); }
static inline void timer_start_hi_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, TIMER_START_HI_OFFSET, value); }

static inline uint32_t timer_reset_lo_get(uint32_t base) { return ARCHI_READ(base, TIMER_RESET_LO_OFFSET); }
static inline void timer_reset_lo_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, TIMER_RESET_LO_OFFSET, value); }

static inline uint32_t timer_reset_hi_get(uint32_t base) { return ARCHI_READ(base, TIMER_RESET_HI_OFFSET); }
static inline void timer_reset_hi_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, TIMER_RESET_HI_OFFSET, value); }

#endif



//
// REGISTERS FIELDS MACROS
//

#ifndef LANGUAGE_ASSEMBLY

#define TIMER_CFG_LO_ENABLE_GET(value)                     (ARCHI_BEXTRACTU((value),1,0))
#define TIMER_CFG_LO_ENABLE_GETS(value)                    (ARCHI_BEXTRACT((value),1,0))
#define TIMER_CFG_LO_ENABLE_SET(value,field)               (ARCHI_BINSERT((value),(field),1,0))
#define TIMER_CFG_LO_ENABLE(val)                           ((val) << 0)

#define TIMER_CFG_LO_RESET_GET(value)                      (ARCHI_BEXTRACTU((value),1,1))
#define TIMER_CFG_LO_RESET_GETS(value)                     (ARCHI_BEXTRACT((value),1,1))
#define TIMER_CFG_LO_RESET_SET(value,field)                (ARCHI_BINSERT((value),(field),1,1))
#define TIMER_CFG_LO_RESET(val)                            ((val) << 1)

#define TIMER_CFG_LO_IRQEN_GET(value)                      (ARCHI_BEXTRACTU((value),1,2))
#define TIMER_CFG_LO_IRQEN_GETS(value)                     (ARCHI_BEXTRACT((value),1,2))
#define TIMER_CFG_LO_IRQEN_SET(value,field)                (ARCHI_BINSERT((value),(field),1,2))
#define TIMER_CFG_LO_IRQEN(val)                            ((val) << 2)

#define TIMER_CFG_LO_IEM_GET(value)                        (ARCHI_BEXTRACTU((value),1,3))
#define TIMER_CFG_LO_IEM_GETS(value)                       (ARCHI_BEXTRACT((value),1,3))
#define TIMER_CFG_LO_IEM_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,3))
#define TIMER_CFG_LO_IEM(val)                              ((val) << 3)

#define TIMER_CFG_LO_MODE_GET(value)                       (ARCHI_BEXTRACTU((value),1,4))
#define TIMER_CFG_LO_MODE_GETS(value)                      (ARCHI_BEXTRACT((value),1,4))
#define TIMER_CFG_LO_MODE_SET(value,field)                 (ARCHI_BINSERT((value),(field),1,4))
#define TIMER_CFG_LO_MODE(val)                             ((val) << 4)

#define TIMER_CFG_LO_ONE_S_GET(value)                      (ARCHI_BEXTRACTU((value),1,5))
#define TIMER_CFG_LO_ONE_S_GETS(value)                     (ARCHI_BEXTRACT((value),1,5))
#define TIMER_CFG_LO_ONE_S_SET(value,field)                (ARCHI_BINSERT((value),(field),1,5))
#define TIMER_CFG_LO_ONE_S(val)                            ((val) << 5)

#define TIMER_CFG_LO_PEN_GET(value)                        (ARCHI_BEXTRACTU((value),1,6))
#define TIMER_CFG_LO_PEN_GETS(value)                       (ARCHI_BEXTRACT((value),1,6))
#define TIMER_CFG_LO_PEN_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,6))
#define TIMER_CFG_LO_PEN(val)                              ((val) << 6)

#define TIMER_CFG_LO_CCFG_GET(value)                       (ARCHI_BEXTRACTU((value),1,7))
#define TIMER_CFG_LO_CCFG_GETS(value)                      (ARCHI_BEXTRACT((value),1,7))
#define TIMER_CFG_LO_CCFG_SET(value,field)                 (ARCHI_BINSERT((value),(field),1,7))
#define TIMER_CFG_LO_CCFG(val)                             ((val) << 7)

#define TIMER_CFG_LO_PVAL_GET(value)                       (ARCHI_BEXTRACTU((value),8,8))
#define TIMER_CFG_LO_PVAL_GETS(value)                      (ARCHI_BEXTRACT((value),8,8))
#define TIMER_CFG_LO_PVAL_SET(value,field)                 (ARCHI_BINSERT((value),(field),8,8))
#define TIMER_CFG_LO_PVAL(val)                             ((val) << 8)

#define TIMER_CFG_LO_CASC_GET(value)                       (ARCHI_BEXTRACTU((value),1,31))
#define TIMER_CFG_LO_CASC_GETS(value)                      (ARCHI_BEXTRACT((value),1,31))
#define TIMER_CFG_LO_CASC_SET(value,field)                 (ARCHI_BINSERT((value),(field),1,31))
#define TIMER_CFG_LO_CASC(val)                             ((val) << 31)

#define TIMER_CFG_HI_ENABLE_GET(value)                     (ARCHI_BEXTRACTU((value),1,0))
#define TIMER_CFG_HI_ENABLE_GETS(value)                    (ARCHI_BEXTRACT((value),1,0))
#define TIMER_CFG_HI_ENABLE_SET(value,field)               (ARCHI_BINSERT((value),(field),1,0))
#define TIMER_CFG_HI_ENABLE(val)                           ((val) << 0)

#define TIMER_CFG_HI_RESET_GET(value)                      (ARCHI_BEXTRACTU((value),1,1))
#define TIMER_CFG_HI_RESET_GETS(value)                     (ARCHI_BEXTRACT((value),1,1))
#define TIMER_CFG_HI_RESET_SET(value,field)                (ARCHI_BINSERT((value),(field),1,1))
#define TIMER_CFG_HI_RESET(val)                            ((val) << 1)

#define TIMER_CFG_HI_IRQEN_GET(value)                      (ARCHI_BEXTRACTU((value),1,2))
#define TIMER_CFG_HI_IRQEN_GETS(value)                     (ARCHI_BEXTRACT((value),1,2))
#define TIMER_CFG_HI_IRQEN_SET(value,field)                (ARCHI_BINSERT((value),(field),1,2))
#define TIMER_CFG_HI_IRQEN(val)                            ((val) << 2)

#define TIMER_CFG_HI_IEM_GET(value)                        (ARCHI_BEXTRACTU((value),1,3))
#define TIMER_CFG_HI_IEM_GETS(value)                       (ARCHI_BEXTRACT((value),1,3))
#define TIMER_CFG_HI_IEM_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,3))
#define TIMER_CFG_HI_IEM(val)                              ((val) << 3)

#define TIMER_CFG_HI_MODE_GET(value)                       (ARCHI_BEXTRACTU((value),1,4))
#define TIMER_CFG_HI_MODE_GETS(value)                      (ARCHI_BEXTRACT((value),1,4))
#define TIMER_CFG_HI_MODE_SET(value,field)                 (ARCHI_BINSERT((value),(field),1,4))
#define TIMER_CFG_HI_MODE(val)                             ((val) << 4)

#define TIMER_CFG_HI_ONE_S_GET(value)                      (ARCHI_BEXTRACTU((value),1,5))
#define TIMER_CFG_HI_ONE_S_GETS(value)                     (ARCHI_BEXTRACT((value),1,5))
#define TIMER_CFG_HI_ONE_S_SET(value,field)                (ARCHI_BINSERT((value),(field),1,5))
#define TIMER_CFG_HI_ONE_S(val)                            ((val) << 5)

#define TIMER_CFG_HI_PEN_GET(value)                        (ARCHI_BEXTRACTU((value),1,6))
#define TIMER_CFG_HI_PEN_GETS(value)                       (ARCHI_BEXTRACT((value),1,6))
#define TIMER_CFG_HI_PEN_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,6))
#define TIMER_CFG_HI_PEN(val)                              ((val) << 6)

#define TIMER_CFG_HI_CLKCFG_GET(value)                     (ARCHI_BEXTRACTU((value),1,7))
#define TIMER_CFG_HI_CLKCFG_GETS(value)                    (ARCHI_BEXTRACT((value),1,7))
#define TIMER_CFG_HI_CLKCFG_SET(value,field)               (ARCHI_BINSERT((value),(field),1,7))
#define TIMER_CFG_HI_CLKCFG(val)                           ((val) << 7)

#define TIMER_CNT_LO_CNT_LO_GET(value)                     (ARCHI_BEXTRACTU((value),32,0))
#define TIMER_CNT_LO_CNT_LO_GETS(value)                    (ARCHI_BEXTRACT((value),32,0))
#define TIMER_CNT_LO_CNT_LO_SET(value,field)               (ARCHI_BINSERT((value),(field),32,0))
#define TIMER_CNT_LO_CNT_LO(val)                           ((val) << 0)

#define TIMER_CNT_HI_CNT_HI_GET(value)                     (ARCHI_BEXTRACTU((value),32,0))
#define TIMER_CNT_HI_CNT_HI_GETS(value)                    (ARCHI_BEXTRACT((value),32,0))
#define TIMER_CNT_HI_CNT_HI_SET(value,field)               (ARCHI_BINSERT((value),(field),32,0))
#define TIMER_CNT_HI_CNT_HI(val)                           ((val) << 0)

#define TIMER_CMP_LO_CMP_LO_GET(value)                     (ARCHI_BEXTRACTU((value),32,0))
#define TIMER_CMP_LO_CMP_LO_GETS(value)                    (ARCHI_BEXTRACT((value),32,0))
#define TIMER_CMP_LO_CMP_LO_SET(value,field)               (ARCHI_BINSERT((value),(field),32,0))
#define TIMER_CMP_LO_CMP_LO(val)                           ((val) << 0)

#define TIMER_CMP_HI_CMP_HI_GET(value)                     (ARCHI_BEXTRACTU((value),32,0))
#define TIMER_CMP_HI_CMP_HI_GETS(value)                    (ARCHI_BEXTRACT((value),32,0))
#define TIMER_CMP_HI_CMP_HI_SET(value,field)               (ARCHI_BINSERT((value),(field),32,0))
#define TIMER_CMP_HI_CMP_HI(val)                           ((val) << 0)

#define TIMER_START_LO_STRT_LO_GET(value)                  (ARCHI_BEXTRACTU((value),1,0))
#define TIMER_START_LO_STRT_LO_GETS(value)                 (ARCHI_BEXTRACT((value),1,0))
#define TIMER_START_LO_STRT_LO_SET(value,field)            (ARCHI_BINSERT((value),(field),1,0))
#define TIMER_START_LO_STRT_LO(val)                        ((val) << 0)

#define TIMER_START_HI_STRT_HI_GET(value)                  (ARCHI_BEXTRACTU((value),1,0))
#define TIMER_START_HI_STRT_HI_GETS(value)                 (ARCHI_BEXTRACT((value),1,0))
#define TIMER_START_HI_STRT_HI_SET(value,field)            (ARCHI_BINSERT((value),(field),1,0))
#define TIMER_START_HI_STRT_HI(val)                        ((val) << 0)

#define TIMER_RESET_LO_RST_LO_GET(value)                   (ARCHI_BEXTRACTU((value),1,0))
#define TIMER_RESET_LO_RST_LO_GETS(value)                  (ARCHI_BEXTRACT((value),1,0))
#define TIMER_RESET_LO_RST_LO_SET(value,field)             (ARCHI_BINSERT((value),(field),1,0))
#define TIMER_RESET_LO_RST_LO(val)                         ((val) << 0)

#define TIMER_RESET_HI_RST_HI_GET(value)                   (ARCHI_BEXTRACTU((value),1,0))
#define TIMER_RESET_HI_RST_HI_GETS(value)                  (ARCHI_BEXTRACT((value),1,0))
#define TIMER_RESET_HI_RST_HI_SET(value,field)             (ARCHI_BINSERT((value),(field),1,0))
#define TIMER_RESET_HI_RST_HI(val)                         ((val) << 0)

#endif

#endif
