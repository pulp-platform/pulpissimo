
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

#ifndef __INCLUDE_ARCHI_ITC_ITC_V1_H__
#define __INCLUDE_ARCHI_ITC_ITC_V1_H__

#ifndef LANGUAGE_ASSEMBLY

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS
//

#define ITC_MASK_OFFSET                          0x0

#define ITC_MASK_SET_OFFSET                      0x4

#define ITC_MASK_CLR_OFFSET                      0x8

#define ITC_STATUS_OFFSET                        0xc

#define ITC_STATUS_SET_OFFSET                    0x10

#define ITC_STATUS_CLR_OFFSET                    0x14

#define ITC_ACK_OFFSET                           0x18

#define ITC_ACK_SET_OFFSET                       0x1c

#define ITC_ACK_CLR_OFFSET                       0x20

#define ITC_FIFO_OFFSET                          0x24



//
// REGISTERS FIELDS
//



//
// REGISTERS STRUCTS
//

#ifndef LANGUAGE_ASSEMBLY

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) itc_mask_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) itc_mask_set_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) itc_mask_clr_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) itc_status_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) itc_status_set_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) itc_status_clr_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) itc_ack_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) itc_ack_set_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) itc_ack_clr_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) itc_fifo_t;

#endif



//
// REGISTERS STRUCTS
//

#ifdef __GVSOC__

class vp_itc_mask : public vp::reg_32
{
public:
};

class vp_itc_mask_set : public vp::reg_32
{
public:
};

class vp_itc_mask_clr : public vp::reg_32
{
public:
};

class vp_itc_status : public vp::reg_32
{
public:
};

class vp_itc_status_set : public vp::reg_32
{
public:
};

class vp_itc_status_clr : public vp::reg_32
{
public:
};

class vp_itc_ack : public vp::reg_32
{
public:
};

class vp_itc_ack_set : public vp::reg_32
{
public:
};

class vp_itc_ack_clr : public vp::reg_32
{
public:
};

class vp_itc_fifo : public vp::reg_32
{
public:
};

#endif



//
// REGISTERS GLOBAL STRUCT
//

#ifndef LANGUAGE_ASSEMBLY

typedef struct {
  unsigned int mask            ;
  unsigned int mask_set        ;
  unsigned int mask_clr        ;
  unsigned int status          ;
  unsigned int status_set      ;
  unsigned int status_clr      ;
  unsigned int ack             ;
  unsigned int ack_set         ;
  unsigned int ack_clr         ;
  unsigned int fifo            ;
} __attribute__((packed)) itc_itc_t;

#endif



//
// REGISTERS ACCESS FUNCTIONS
//

#ifndef LANGUAGE_ASSEMBLY

static inline uint32_t itc_mask_get(uint32_t base) { return ARCHI_READ(base, ITC_MASK_OFFSET); }
static inline void itc_mask_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, ITC_MASK_OFFSET, value); }

static inline uint32_t itc_mask_set_get(uint32_t base) { return ARCHI_READ(base, ITC_MASK_SET_OFFSET); }
static inline void itc_mask_set_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, ITC_MASK_SET_OFFSET, value); }

static inline uint32_t itc_mask_clr_get(uint32_t base) { return ARCHI_READ(base, ITC_MASK_CLR_OFFSET); }
static inline void itc_mask_clr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, ITC_MASK_CLR_OFFSET, value); }

static inline uint32_t itc_status_get(uint32_t base) { return ARCHI_READ(base, ITC_STATUS_OFFSET); }
static inline void itc_status_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, ITC_STATUS_OFFSET, value); }

static inline uint32_t itc_status_set_get(uint32_t base) { return ARCHI_READ(base, ITC_STATUS_SET_OFFSET); }
static inline void itc_status_set_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, ITC_STATUS_SET_OFFSET, value); }

static inline uint32_t itc_status_clr_get(uint32_t base) { return ARCHI_READ(base, ITC_STATUS_CLR_OFFSET); }
static inline void itc_status_clr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, ITC_STATUS_CLR_OFFSET, value); }

static inline uint32_t itc_ack_get(uint32_t base) { return ARCHI_READ(base, ITC_ACK_OFFSET); }
static inline void itc_ack_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, ITC_ACK_OFFSET, value); }

static inline uint32_t itc_ack_set_get(uint32_t base) { return ARCHI_READ(base, ITC_ACK_SET_OFFSET); }
static inline void itc_ack_set_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, ITC_ACK_SET_OFFSET, value); }

static inline uint32_t itc_ack_clr_get(uint32_t base) { return ARCHI_READ(base, ITC_ACK_CLR_OFFSET); }
static inline void itc_ack_clr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, ITC_ACK_CLR_OFFSET, value); }

static inline uint32_t itc_fifo_get(uint32_t base) { return ARCHI_READ(base, ITC_FIFO_OFFSET); }
static inline void itc_fifo_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, ITC_FIFO_OFFSET, value); }

#endif



//
// REGISTERS FIELDS MACROS
//

#ifndef LANGUAGE_ASSEMBLY

#endif

#endif
