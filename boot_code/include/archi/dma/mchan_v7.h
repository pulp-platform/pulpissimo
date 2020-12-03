
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

#ifndef __INCLUDE_ARCHI_DMA_MCHAN_V7_H__
#define __INCLUDE_ARCHI_DMA_MCHAN_V7_H__

#ifndef LANGUAGE_ASSEMBLY

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS
//

// Cluster DMA configuration register.
#define MCHAN_CMD_OFFSET                         0x0

// Cluster DMA status register.
#define MCHAN_STATUS_OFFSET                      0x4



//
// REGISTERS FIELDS
//

// Format is operation dependent. See below. (access: R/W)
#define MCHAN_CMD_CMD_BIT                                            0
#define MCHAN_CMD_CMD_WIDTH                                          32
#define MCHAN_CMD_CMD_MASK                                           0xffffffff

// Format is operation dependent. See below. (access: R/W)
#define MCHAN_STATUS_STATUS_BIT                                      0
#define MCHAN_STATUS_STATUS_WIDTH                                    32
#define MCHAN_STATUS_STATUS_MASK                                     0xffffffff

// Transfer length in bytes configuration bitfield. (access: W)
#define MCHAN_CMD_CMD_LEN_BIT                                        0
#define MCHAN_CMD_CMD_LEN_WIDTH                                      17
#define MCHAN_CMD_CMD_LEN_MASK                                       0x1ffff

// Transfer direction configuration bitfield: - 1'b0: L1 to L2 - 1'b1: L2 to L2 (access: W)
#define MCHAN_CMD_CMD_TYPE_BIT                                       17
#define MCHAN_CMD_CMD_TYPE_WIDTH                                     1
#define MCHAN_CMD_CMD_TYPE_MASK                                      0x20000

// Transfer incremental configuration bitfield: - 1'b0: non incremental - 1'b1: incremental (access: W)
#define MCHAN_CMD_CMD_INC_BIT                                        18
#define MCHAN_CMD_CMD_INC_WIDTH                                      1
#define MCHAN_CMD_CMD_INC_MASK                                       0x40000

// Transfer type configuration bitfield: - 1'b0: linear transfer in EXT interface - 1'b1: 2D transfer in EXT interface (access: W)
#define MCHAN_CMD_CMD__2D_EXT_BIT                                    19
#define MCHAN_CMD_CMD__2D_EXT_WIDTH                                  1
#define MCHAN_CMD_CMD__2D_EXT_MASK                                   0x80000

// Transfer event generation configuration bitfield: - 1'b0: disabled - 1'b1: enabled (access: W)
#define MCHAN_CMD_CMD_ELE_BIT                                        20
#define MCHAN_CMD_CMD_ELE_WIDTH                                      1
#define MCHAN_CMD_CMD_ELE_MASK                                       0x100000

// Transfer interrupt generation configuration bitfield: - 1'b0: disabled - 1'b1: enabled (access: W)
#define MCHAN_CMD_CMD_ILE_BIT                                        21
#define MCHAN_CMD_CMD_ILE_WIDTH                                      1
#define MCHAN_CMD_CMD_ILE_MASK                                       0x200000

// Transfer event or interrupt broadcast configuration bitfield: - 1'b0: event or interrupt is routed to the cluster core who initiated the transfer - 1'b1: event or interrupt are broadcasted to all cluster cores (access: W)
#define MCHAN_CMD_CMD_BLE_BIT                                        22
#define MCHAN_CMD_CMD_BLE_WIDTH                                      1
#define MCHAN_CMD_CMD_BLE_MASK                                       0x400000

// Transfer type configuration bitfield: - 1'b0: linear transfer in TCDM interface - 1'b1: 2D transfer in TCDM interface (access: W)
#define MCHAN_CMD_CMD__2D_TCDM_BIT                                   23
#define MCHAN_CMD_CMD__2D_TCDM_WIDTH                                 1
#define MCHAN_CMD_CMD__2D_TCDM_MASK                                  0x800000

// Transfer identifier value bitfield. (access: R)
#define MCHAN_CMD_GET_TID_TID_BIT                                    0
#define MCHAN_CMD_GET_TID_TID_WIDTH                                  4
#define MCHAN_CMD_GET_TID_TID_MASK                                   0xf

// Transfer L1 base address configuration bitfield. (access: W)
#define MCHAN_CMD_TCDM_ADDR_ADDR_BIT                                 0
#define MCHAN_CMD_TCDM_ADDR_ADDR_WIDTH                               32
#define MCHAN_CMD_TCDM_ADDR_ADDR_MASK                                0xffffffff

// Transfer L2 base address configuration bitfield. (access: W)
#define MCHAN_CMD_EXT_ADDR_ADDR_BIT                                  0
#define MCHAN_CMD_EXT_ADDR_ADDR_WIDTH                                32
#define MCHAN_CMD_EXT_ADDR_ADDR_MASK                                 0xffffffff

// EXT 2D transfer conut value configuration bitfield. (access: W)
#define MCHAN_CMD_2D_EXT_COUNT__2D_EXT_COUNT_BIT                     0
#define MCHAN_CMD_2D_EXT_COUNT__2D_EXT_COUNT_WIDTH                   32
#define MCHAN_CMD_2D_EXT_COUNT__2D_EXT_COUNT_MASK                    0xffffffff

// EXT 2D transfer stride value configuration bitfield. (access: W)
#define MCHAN_CMD_2D_EXT_STRIDE__2D_EXT_STRIDE_BIT                   0
#define MCHAN_CMD_2D_EXT_STRIDE__2D_EXT_STRIDE_WIDTH                 32
#define MCHAN_CMD_2D_EXT_STRIDE__2D_EXT_STRIDE_MASK                  0xffffffff

// TCDM 2D transfer conut value configuration bitfield. (access: W)
#define MCHAN_CMD_2D_TCDM_COUNT__2D_TCDM_COUNT_BIT                   0
#define MCHAN_CMD_2D_TCDM_COUNT__2D_TCDM_COUNT_WIDTH                 32
#define MCHAN_CMD_2D_TCDM_COUNT__2D_TCDM_COUNT_MASK                  0xffffffff

// TCDM 2D transfer stride value configuration bitfield. (access: W)
#define MCHAN_CMD_2D_TCDM_STRIDE__2D_TCDM_STRIDE_BIT                 0
#define MCHAN_CMD_2D_TCDM_STRIDE__2D_TCDM_STRIDE_WIDTH               32
#define MCHAN_CMD_2D_TCDM_STRIDE__2D_TCDM_STRIDE_MASK                0xffffffff

// Transfer status bitfield: TID_TR[i]=1'b1 means that transfer with TID i is active. (access: R)
#define MCHAN_STATUS_STATUS_TID_TR_BIT                               0
#define MCHAN_STATUS_STATUS_TID_TR_WIDTH                             16
#define MCHAN_STATUS_STATUS_TID_TR_MASK                              0xffff

// Transfer status bitfield: - TID_TR[i]=1'b0 means that transfer allocator with TID i-16 is free. - TID_TR[i]=1'b1 means that transfer allocator with TID i-16 is reserved. (access: R)
#define MCHAN_STATUS_STATUS_TID_ALLOC_BIT                            16
#define MCHAN_STATUS_STATUS_TID_ALLOC_WIDTH                          16
#define MCHAN_STATUS_STATUS_TID_ALLOC_MASK                           0xffff0000

// Transfer canceller configuration bitfield. Writing a 1'b1 in TID_FREE[i] will free transfer with TID i. (access: W)
#define MCHAN_STATUS_FREE_TID_TID_FREE_BIT                           0
#define MCHAN_STATUS_FREE_TID_TID_FREE_WIDTH                         16
#define MCHAN_STATUS_FREE_TID_TID_FREE_MASK                          0xffff



//
// REGISTERS STRUCTS
//

#ifndef LANGUAGE_ASSEMBLY

typedef union {
  struct {
    unsigned int cmd             :32; // Format is operation dependent. See below.
  };
  unsigned int raw;
} __attribute__((packed)) mchan_cmd_t;

typedef union {
  struct {
    unsigned int status          :32; // Format is operation dependent. See below.
  };
  unsigned int raw;
} __attribute__((packed)) mchan_status_t;

typedef union {
  struct {
    unsigned int len             :17; // Transfer length in bytes configuration bitfield.
    unsigned int type            :1 ; // Transfer direction configuration bitfield: - 1'b0: L1 to L2 - 1'b1: L2 to L2
    unsigned int inc             :1 ; // Transfer incremental configuration bitfield: - 1'b0: non incremental - 1'b1: incremental
    unsigned int _2d_ext         :1 ; // Transfer type configuration bitfield: - 1'b0: linear transfer in EXT interface - 1'b1: 2D transfer in EXT interface
    unsigned int ele             :1 ; // Transfer event generation configuration bitfield: - 1'b0: disabled - 1'b1: enabled
    unsigned int ile             :1 ; // Transfer interrupt generation configuration bitfield: - 1'b0: disabled - 1'b1: enabled
    unsigned int ble             :1 ; // Transfer event or interrupt broadcast configuration bitfield: - 1'b0: event or interrupt is routed to the cluster core who initiated the transfer - 1'b1: event or interrupt are broadcasted to all cluster cores
    unsigned int _2d_tcdm        :1 ; // Transfer type configuration bitfield: - 1'b0: linear transfer in TCDM interface - 1'b1: 2D transfer in TCDM interface
  };
  unsigned int raw;
} __attribute__((packed)) mchan_cmd_cmd_t;

typedef union {
  struct {
    unsigned int tid             :4 ; // Transfer identifier value bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) mchan_cmd_get_tid_t;

typedef union {
  struct {
    unsigned int addr            :32; // Transfer L1 base address configuration bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) mchan_cmd_tcdm_addr_t;

typedef union {
  struct {
    unsigned int addr            :32; // Transfer L2 base address configuration bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) mchan_cmd_ext_addr_t;

typedef union {
  struct {
    unsigned int _2d_ext_count   :32; // EXT 2D transfer conut value configuration bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) mchan_cmd_2d_ext_count_t;

typedef union {
  struct {
    unsigned int _2d_ext_stride  :32; // EXT 2D transfer stride value configuration bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) mchan_cmd_2d_ext_stride_t;

typedef union {
  struct {
    unsigned int _2d_tcdm_count  :32; // TCDM 2D transfer conut value configuration bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) mchan_cmd_2d_tcdm_count_t;

typedef union {
  struct {
    unsigned int _2d_tcdm_stride :32; // TCDM 2D transfer stride value configuration bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) mchan_cmd_2d_tcdm_stride_t;

typedef union {
  struct {
    unsigned int tid_tr          :16; // Transfer status bitfield: TID_TR[i]=1'b1 means that transfer with TID i is active.
    unsigned int tid_alloc       :16; // Transfer status bitfield: - TID_TR[i]=1'b0 means that transfer allocator with TID i-16 is free. - TID_TR[i]=1'b1 means that transfer allocator with TID i-16 is reserved.
  };
  unsigned int raw;
} __attribute__((packed)) mchan_status_status_t;

typedef union {
  struct {
    unsigned int tid_free        :16; // Transfer canceller configuration bitfield. Writing a 1'b1 in TID_FREE[i] will free transfer with TID i.
  };
  unsigned int raw;
} __attribute__((packed)) mchan_status_free_tid_t;

#endif



//
// REGISTERS STRUCTS
//

#ifdef __GVSOC__

class vp_mchan_cmd : public vp::reg_32
{
public:
  inline void cmd_set(uint32_t value) { this->set_field(value, MCHAN_CMD_CMD_BIT, MCHAN_CMD_CMD_WIDTH); }
  inline uint32_t cmd_get() { return this->get_field(MCHAN_CMD_CMD_BIT, MCHAN_CMD_CMD_WIDTH); }
};

class vp_mchan_status : public vp::reg_32
{
public:
  inline void status_set(uint32_t value) { this->set_field(value, MCHAN_STATUS_STATUS_BIT, MCHAN_STATUS_STATUS_WIDTH); }
  inline uint32_t status_get() { return this->get_field(MCHAN_STATUS_STATUS_BIT, MCHAN_STATUS_STATUS_WIDTH); }
};

class vp_mchan_cmd_tcdm_addr : public vp::reg_32
{
public:
  inline void addr_set(uint32_t value) { this->set_field(value, MCHAN_CMD_TCDM_ADDR_ADDR_BIT, MCHAN_CMD_TCDM_ADDR_ADDR_WIDTH); }
  inline uint32_t addr_get() { return this->get_field(MCHAN_CMD_TCDM_ADDR_ADDR_BIT, MCHAN_CMD_TCDM_ADDR_ADDR_WIDTH); }
};

class vp_mchan_cmd_ext_addr : public vp::reg_32
{
public:
  inline void addr_set(uint32_t value) { this->set_field(value, MCHAN_CMD_EXT_ADDR_ADDR_BIT, MCHAN_CMD_EXT_ADDR_ADDR_WIDTH); }
  inline uint32_t addr_get() { return this->get_field(MCHAN_CMD_EXT_ADDR_ADDR_BIT, MCHAN_CMD_EXT_ADDR_ADDR_WIDTH); }
};

class vp_mchan_cmd_2d_ext_count : public vp::reg_32
{
public:
  inline void _2d_ext_count_set(uint32_t value) { this->set_field(value, MCHAN_CMD_2D_EXT_COUNT__2D_EXT_COUNT_BIT, MCHAN_CMD_2D_EXT_COUNT__2D_EXT_COUNT_WIDTH); }
  inline uint32_t _2d_ext_count_get() { return this->get_field(MCHAN_CMD_2D_EXT_COUNT__2D_EXT_COUNT_BIT, MCHAN_CMD_2D_EXT_COUNT__2D_EXT_COUNT_WIDTH); }
};

class vp_mchan_cmd_2d_ext_stride : public vp::reg_32
{
public:
  inline void _2d_ext_stride_set(uint32_t value) { this->set_field(value, MCHAN_CMD_2D_EXT_STRIDE__2D_EXT_STRIDE_BIT, MCHAN_CMD_2D_EXT_STRIDE__2D_EXT_STRIDE_WIDTH); }
  inline uint32_t _2d_ext_stride_get() { return this->get_field(MCHAN_CMD_2D_EXT_STRIDE__2D_EXT_STRIDE_BIT, MCHAN_CMD_2D_EXT_STRIDE__2D_EXT_STRIDE_WIDTH); }
};

class vp_mchan_cmd_2d_tcdm_count : public vp::reg_32
{
public:
  inline void _2d_tcdm_count_set(uint32_t value) { this->set_field(value, MCHAN_CMD_2D_TCDM_COUNT__2D_TCDM_COUNT_BIT, MCHAN_CMD_2D_TCDM_COUNT__2D_TCDM_COUNT_WIDTH); }
  inline uint32_t _2d_tcdm_count_get() { return this->get_field(MCHAN_CMD_2D_TCDM_COUNT__2D_TCDM_COUNT_BIT, MCHAN_CMD_2D_TCDM_COUNT__2D_TCDM_COUNT_WIDTH); }
};

class vp_mchan_cmd_2d_tcdm_stride : public vp::reg_32
{
public:
  inline void _2d_tcdm_stride_set(uint32_t value) { this->set_field(value, MCHAN_CMD_2D_TCDM_STRIDE__2D_TCDM_STRIDE_BIT, MCHAN_CMD_2D_TCDM_STRIDE__2D_TCDM_STRIDE_WIDTH); }
  inline uint32_t _2d_tcdm_stride_get() { return this->get_field(MCHAN_CMD_2D_TCDM_STRIDE__2D_TCDM_STRIDE_BIT, MCHAN_CMD_2D_TCDM_STRIDE__2D_TCDM_STRIDE_WIDTH); }
};

class vp_mchan_status_status : public vp::reg_16
{
public:
  inline void tid_tr_set(uint16_t value) { this->set_field(value, MCHAN_STATUS_STATUS_TID_TR_BIT, MCHAN_STATUS_STATUS_TID_TR_WIDTH); }
  inline uint16_t tid_tr_get() { return this->get_field(MCHAN_STATUS_STATUS_TID_TR_BIT, MCHAN_STATUS_STATUS_TID_TR_WIDTH); }
  inline void tid_alloc_set(uint16_t value) { this->set_field(value, MCHAN_STATUS_STATUS_TID_ALLOC_BIT, MCHAN_STATUS_STATUS_TID_ALLOC_WIDTH); }
  inline uint16_t tid_alloc_get() { return this->get_field(MCHAN_STATUS_STATUS_TID_ALLOC_BIT, MCHAN_STATUS_STATUS_TID_ALLOC_WIDTH); }
};

class vp_mchan_status_free_tid : public vp::reg_16
{
public:
  inline void tid_free_set(uint16_t value) { this->set_field(value, MCHAN_STATUS_FREE_TID_TID_FREE_BIT, MCHAN_STATUS_FREE_TID_TID_FREE_WIDTH); }
  inline uint16_t tid_free_get() { return this->get_field(MCHAN_STATUS_FREE_TID_TID_FREE_BIT, MCHAN_STATUS_FREE_TID_TID_FREE_WIDTH); }
};

#endif



//
// REGISTERS GLOBAL STRUCT
//

#ifndef LANGUAGE_ASSEMBLY

typedef struct {
  unsigned int cmd             ; // Cluster DMA configuration register.
  unsigned int status          ; // Cluster DMA status register.
  unsigned int cmd_cmd         ; // Transfer length in bytes configuration bitfield.
  unsigned int cmd_get_tid     ; // Transfer identifier value bitfield.
  unsigned int cmd_tcdm_addr   ; // Transfer L1 base address configuration bitfield.
  unsigned int cmd_ext_addr    ; // Transfer L2 base address configuration bitfield.
  unsigned int cmd_2d_ext_count; // EXT 2D transfer conut value configuration bitfield.
  unsigned int cmd_2d_ext_stride; // EXT 2D transfer stride value configuration bitfield.
  unsigned int cmd_2d_tcdm_count; // TCDM 2D transfer conut value configuration bitfield.
  unsigned int cmd_2d_tcdm_stride; // TCDM 2D transfer stride value configuration bitfield.
  unsigned int status_status   ; // Transfer status bitfield: TID_TR[i]=1'b1 means that transfer with TID i is active.
  unsigned int status_free_tid ; // Transfer canceller configuration bitfield. Writing a 1'b1 in TID_FREE[i] will free transfer with TID i.
} __attribute__((packed)) mchan_mchan_t;

#endif



//
// REGISTERS ACCESS FUNCTIONS
//

#ifndef LANGUAGE_ASSEMBLY

static inline uint32_t mchan_cmd_get(uint32_t base) { return ARCHI_READ(base, MCHAN_CMD_OFFSET); }
static inline void mchan_cmd_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MCHAN_CMD_OFFSET, value); }

static inline uint32_t mchan_status_get(uint32_t base) { return ARCHI_READ(base, MCHAN_STATUS_OFFSET); }
static inline void mchan_status_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MCHAN_STATUS_OFFSET, value); }

#endif



//
// REGISTERS FIELDS MACROS
//

#ifndef LANGUAGE_ASSEMBLY

#define MCHAN_CMD_CMD_GET(value)                           (ARCHI_BEXTRACTU((value),32,0))
#define MCHAN_CMD_CMD_GETS(value)                          (ARCHI_BEXTRACT((value),32,0))
#define MCHAN_CMD_CMD_SET(value,field)                     (ARCHI_BINSERT((value),(field),32,0))
#define MCHAN_CMD_CMD(val)                                 ((val) << 0)

#define MCHAN_STATUS_STATUS_GET(value)                     (ARCHI_BEXTRACTU((value),32,0))
#define MCHAN_STATUS_STATUS_GETS(value)                    (ARCHI_BEXTRACT((value),32,0))
#define MCHAN_STATUS_STATUS_SET(value,field)               (ARCHI_BINSERT((value),(field),32,0))
#define MCHAN_STATUS_STATUS(val)                           ((val) << 0)

#define MCHAN_CMD_CMD_LEN_GET(value)                       (ARCHI_BEXTRACTU((value),17,0))
#define MCHAN_CMD_CMD_LEN_GETS(value)                      (ARCHI_BEXTRACT((value),17,0))
#define MCHAN_CMD_CMD_LEN_SET(value,field)                 (ARCHI_BINSERT((value),(field),17,0))
#define MCHAN_CMD_CMD_LEN(val)                             ((val) << 0)

#define MCHAN_CMD_CMD_TYPE_GET(value)                      (ARCHI_BEXTRACTU((value),1,17))
#define MCHAN_CMD_CMD_TYPE_GETS(value)                     (ARCHI_BEXTRACT((value),1,17))
#define MCHAN_CMD_CMD_TYPE_SET(value,field)                (ARCHI_BINSERT((value),(field),1,17))
#define MCHAN_CMD_CMD_TYPE(val)                            ((val) << 17)

#define MCHAN_CMD_CMD_INC_GET(value)                       (ARCHI_BEXTRACTU((value),1,18))
#define MCHAN_CMD_CMD_INC_GETS(value)                      (ARCHI_BEXTRACT((value),1,18))
#define MCHAN_CMD_CMD_INC_SET(value,field)                 (ARCHI_BINSERT((value),(field),1,18))
#define MCHAN_CMD_CMD_INC(val)                             ((val) << 18)

#define MCHAN_CMD_CMD__2D_EXT_GET(value)                   (ARCHI_BEXTRACTU((value),1,19))
#define MCHAN_CMD_CMD__2D_EXT_GETS(value)                  (ARCHI_BEXTRACT((value),1,19))
#define MCHAN_CMD_CMD__2D_EXT_SET(value,field)             (ARCHI_BINSERT((value),(field),1,19))
#define MCHAN_CMD_CMD__2D_EXT(val)                         ((val) << 19)

#define MCHAN_CMD_CMD_ELE_GET(value)                       (ARCHI_BEXTRACTU((value),1,20))
#define MCHAN_CMD_CMD_ELE_GETS(value)                      (ARCHI_BEXTRACT((value),1,20))
#define MCHAN_CMD_CMD_ELE_SET(value,field)                 (ARCHI_BINSERT((value),(field),1,20))
#define MCHAN_CMD_CMD_ELE(val)                             ((val) << 20)

#define MCHAN_CMD_CMD_ILE_GET(value)                       (ARCHI_BEXTRACTU((value),1,21))
#define MCHAN_CMD_CMD_ILE_GETS(value)                      (ARCHI_BEXTRACT((value),1,21))
#define MCHAN_CMD_CMD_ILE_SET(value,field)                 (ARCHI_BINSERT((value),(field),1,21))
#define MCHAN_CMD_CMD_ILE(val)                             ((val) << 21)

#define MCHAN_CMD_CMD_BLE_GET(value)                       (ARCHI_BEXTRACTU((value),1,22))
#define MCHAN_CMD_CMD_BLE_GETS(value)                      (ARCHI_BEXTRACT((value),1,22))
#define MCHAN_CMD_CMD_BLE_SET(value,field)                 (ARCHI_BINSERT((value),(field),1,22))
#define MCHAN_CMD_CMD_BLE(val)                             ((val) << 22)

#define MCHAN_CMD_CMD__2D_TCDM_GET(value)                  (ARCHI_BEXTRACTU((value),1,23))
#define MCHAN_CMD_CMD__2D_TCDM_GETS(value)                 (ARCHI_BEXTRACT((value),1,23))
#define MCHAN_CMD_CMD__2D_TCDM_SET(value,field)            (ARCHI_BINSERT((value),(field),1,23))
#define MCHAN_CMD_CMD__2D_TCDM(val)                        ((val) << 23)

#define MCHAN_CMD_GET_TID_TID_GET(value)                   (ARCHI_BEXTRACTU((value),4,0))
#define MCHAN_CMD_GET_TID_TID_GETS(value)                  (ARCHI_BEXTRACT((value),4,0))
#define MCHAN_CMD_GET_TID_TID_SET(value,field)             (ARCHI_BINSERT((value),(field),4,0))
#define MCHAN_CMD_GET_TID_TID(val)                         ((val) << 0)

#define MCHAN_CMD_TCDM_ADDR_ADDR_GET(value)                (ARCHI_BEXTRACTU((value),32,0))
#define MCHAN_CMD_TCDM_ADDR_ADDR_GETS(value)               (ARCHI_BEXTRACT((value),32,0))
#define MCHAN_CMD_TCDM_ADDR_ADDR_SET(value,field)          (ARCHI_BINSERT((value),(field),32,0))
#define MCHAN_CMD_TCDM_ADDR_ADDR(val)                      ((val) << 0)

#define MCHAN_CMD_EXT_ADDR_ADDR_GET(value)                 (ARCHI_BEXTRACTU((value),32,0))
#define MCHAN_CMD_EXT_ADDR_ADDR_GETS(value)                (ARCHI_BEXTRACT((value),32,0))
#define MCHAN_CMD_EXT_ADDR_ADDR_SET(value,field)           (ARCHI_BINSERT((value),(field),32,0))
#define MCHAN_CMD_EXT_ADDR_ADDR(val)                       ((val) << 0)

#define MCHAN_CMD_2D_EXT_COUNT__2D_EXT_COUNT_GET(value)    (ARCHI_BEXTRACTU((value),32,0))
#define MCHAN_CMD_2D_EXT_COUNT__2D_EXT_COUNT_GETS(value)   (ARCHI_BEXTRACT((value),32,0))
#define MCHAN_CMD_2D_EXT_COUNT__2D_EXT_COUNT_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define MCHAN_CMD_2D_EXT_COUNT__2D_EXT_COUNT(val)          ((val) << 0)

#define MCHAN_CMD_2D_EXT_STRIDE__2D_EXT_STRIDE_GET(value)  (ARCHI_BEXTRACTU((value),32,0))
#define MCHAN_CMD_2D_EXT_STRIDE__2D_EXT_STRIDE_GETS(value) (ARCHI_BEXTRACT((value),32,0))
#define MCHAN_CMD_2D_EXT_STRIDE__2D_EXT_STRIDE_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define MCHAN_CMD_2D_EXT_STRIDE__2D_EXT_STRIDE(val)        ((val) << 0)

#define MCHAN_CMD_2D_TCDM_COUNT__2D_TCDM_COUNT_GET(value)  (ARCHI_BEXTRACTU((value),32,0))
#define MCHAN_CMD_2D_TCDM_COUNT__2D_TCDM_COUNT_GETS(value) (ARCHI_BEXTRACT((value),32,0))
#define MCHAN_CMD_2D_TCDM_COUNT__2D_TCDM_COUNT_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define MCHAN_CMD_2D_TCDM_COUNT__2D_TCDM_COUNT(val)        ((val) << 0)

#define MCHAN_CMD_2D_TCDM_STRIDE__2D_TCDM_STRIDE_GET(value) (ARCHI_BEXTRACTU((value),32,0))
#define MCHAN_CMD_2D_TCDM_STRIDE__2D_TCDM_STRIDE_GETS(value) (ARCHI_BEXTRACT((value),32,0))
#define MCHAN_CMD_2D_TCDM_STRIDE__2D_TCDM_STRIDE_SET(value,field) (ARCHI_BINSERT((value),(field),32,0))
#define MCHAN_CMD_2D_TCDM_STRIDE__2D_TCDM_STRIDE(val)      ((val) << 0)

#define MCHAN_STATUS_STATUS_TID_TR_GET(value)              (ARCHI_BEXTRACTU((value),16,0))
#define MCHAN_STATUS_STATUS_TID_TR_GETS(value)             (ARCHI_BEXTRACT((value),16,0))
#define MCHAN_STATUS_STATUS_TID_TR_SET(value,field)        (ARCHI_BINSERT((value),(field),16,0))
#define MCHAN_STATUS_STATUS_TID_TR(val)                    ((val) << 0)

#define MCHAN_STATUS_STATUS_TID_ALLOC_GET(value)           (ARCHI_BEXTRACTU((value),16,16))
#define MCHAN_STATUS_STATUS_TID_ALLOC_GETS(value)          (ARCHI_BEXTRACT((value),16,16))
#define MCHAN_STATUS_STATUS_TID_ALLOC_SET(value,field)     (ARCHI_BINSERT((value),(field),16,16))
#define MCHAN_STATUS_STATUS_TID_ALLOC(val)                 ((val) << 16)

#define MCHAN_STATUS_FREE_TID_TID_FREE_GET(value)          (ARCHI_BEXTRACTU((value),16,0))
#define MCHAN_STATUS_FREE_TID_TID_FREE_GETS(value)         (ARCHI_BEXTRACT((value),16,0))
#define MCHAN_STATUS_FREE_TID_TID_FREE_SET(value,field)    (ARCHI_BINSERT((value),(field),16,0))
#define MCHAN_STATUS_FREE_TID_TID_FREE(val)                ((val) << 0)

#endif

#endif
