/*
 * Copyright (C) 2018 GreenWaves Technologies
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

#ifndef __HAL_IID_QUIDDIKEY_V1_H__
#define __HAL_IID_QUIDDIKEY_V1_H__

#include <hal/pulp.h>
#include <stdint.h>
#include "archi/vendors/iid/quiddikey_v1.h"

#if QUIDDIKEY_VERSION != 1
#error This file must be included only with quiddikey version 1
#endif

// QUIDDIKEY HAL Registers Structure
typedef struct {
    uint32_t cfg;
    uint32_t status;
    uint32_t allow;
    uint32_t ier;
    uint32_t imr;
    uint32_t isr;
    uint32_t key_dest;
    uint32_t dir;
    uint32_t dor;
    uint32_t misc;
    uint32_t if_sr;
    uint32_t test;
    uint32_t hw_ruc0;
    uint32_t hw_ruc1;
    uint32_t hw_settings;
    uint32_t hw_info;
    uint32_t hw_id;
    uint32_t hw_ver;
} halQuiddikeyHandle_t;


// QUIDDIKEY HAL Register Fields Structure
typedef struct {
    uint32_t zeroize       : 1;
    uint32_t enroll        : 1;
    uint32_t start         : 1;
    uint32_t unused        : 2;
    uint32_t stop          : 1;
    uint32_t get_key       : 1;
    uint32_t unwrap        : 1;
    uint32_t wrap_gen_rand : 1;
    uint32_t wrap          : 1;
    uint32_t unused1       : 5;
    uint32_t gen_rand      : 1;
    uint32_t unused2       : 16;
} __attribute__ ((packed)) halQuiddikeyCfg_t;

typedef struct {
    uint32_t busy          : 1;
    uint32_t last_op_pass  : 1;
    uint32_t last_op_error : 1;
    uint32_t zeroized      : 1;
    uint32_t rejected      : 1;
    uint32_t di_req        : 1;
    uint32_t do_req        : 1;
    uint32_t unused        : 25;
} __attribute__ ((packed)) halQuiddikeyStatus_t;

typedef struct {
    uint32_t unused        : 1;
    uint32_t enroll        : 1;
    uint32_t start         : 1;
    uint32_t unused1       : 2;
    uint32_t stop          : 1;
    uint32_t get_key       : 1;
    uint32_t unwrap        : 1;
    uint32_t wrap_gen_rand : 1;
    uint32_t wrap          : 1;
    uint32_t unused2       : 5;
    uint32_t gen_rand      : 1;
    uint32_t unused3       : 16;
} __attribute__ ((packed)) halQuiddikeyAllow_t;

typedef struct {
    uint32_t ier    : 1;
    uint32_t unused : 31;
} __attribute__ ((packed)) halQuiddikeyInterruptEnable_t;

typedef struct {
    uint32_t busy     : 1;
    uint32_t ok       : 1;
    uint32_t error    : 1;
    uint32_t zeroized : 1;
    uint32_t rejected : 1;
    uint32_t di_req   : 1;
    uint32_t do_req   : 1;
    uint32_t unused   : 25;
} __attribute__ ((packed)) halQuiddikeyInterruptMask_t;

typedef struct {
    uint32_t busy     : 1;
    uint32_t ok       : 1;
    uint32_t error    : 1;
    uint32_t zeroized : 1;
    uint32_t rejected : 1;
    uint32_t di_req   : 1;
    uint32_t do_req   : 1;
    uint32_t unused   : 25;
} __attribute__ ((packed)) halQuiddikeyInterruptStatus_t;

typedef struct {
    uint32_t dor_reg : 1;
    uint32_t ko_itf  : 1;
    uint32_t unused  : 30;
} __attribute__ ((packed)) halQuiddikeyKeyDest_t;

typedef struct {
    uint32_t data:32;
} __attribute__ ((packed)) halQuiddikeyDataInput_t;

typedef struct {
    uint32_t data:32;
} __attribute__ ((packed)) halQuiddikeyDataOutput_t;

typedef struct {
    uint32_t endianness : 1;
    uint32_t unused     : 31;
} __attribute__ ((packed)) halQuiddikeyEndianness_t;

typedef struct {
    uint32_t apb_error : 1;
    uint32_t unused    : 31;
} __attribute__ ((packed)) halQuiddikeyInterfaceStatus_t;

typedef struct {
    uint32_t bist_sel     : 1;
    uint32_t unused       : 3;
    uint32_t bist_running : 1;
    uint32_t bist_active  : 1;
    uint32_t bist_ok      : 1;
    uint32_t bist_fail    : 1;
    uint32_t unused1      : 23;
    uint32_t bist_allow   : 1;
} __attribute__ ((packed)) halQuiddikeyTest_t;

typedef struct {
    uint32_t hw_ruc0:32;
} __attribute__ ((packed)) halQuiddikeyHwRUC0_t;

typedef struct {
    uint32_t hw_ruc1:32;
} __attribute__ ((packed)) halQuiddikeyHwRUC1_t;

typedef struct {
    uint32_t unused                : 1;
    uint32_t disable_enroll        : 1;
    uint32_t disable_start         : 1;
    uint32_t unused1               : 2;
    uint32_t disable_stop          : 1;
    uint32_t disable_get_key       : 1;
    uint32_t disable_unwrap        : 1;
    uint32_t disable_wrap_gen_rand : 1;
    uint32_t disable_wrap          : 1;
    uint32_t unused2               : 5;
    uint32_t disable_gen_rand      : 1;
    uint32_t unused3               : 16;
} __attribute__ ((packed)) halQuiddikeyHwSettings_t;

typedef struct {
    uint32_t unused   : 22;
    uint32_t cfg_bist : 1;
    uint32_t unused1  : 5;
    uint32_t cfg_type : 1;
    uint32_t unused3  : 3;
} __attribute__ ((packed)) halQuiddikeyInfo_t;

typedef struct {
    uint32_t id:32;
} __attribute__ ((packed)) halQuiddikeyID_t;

typedef struct {
    uint32_t rev    : 8;
    uint32_t minor  : 8;
    uint32_t major  : 8;
    uint32_t unused : 8;
} __attribute__ ((packed)) halQuiddikeyVersion_t;

// QUIDDIKEY HAL Register Union definition
typedef union {
    halQuiddikeyCfg_t             config;
    halQuiddikeyStatus_t          status;
    halQuiddikeyAllow_t           allow;
    halQuiddikeyInterruptEnable_t int_enable;
    halQuiddikeyInterruptMask_t   int_mask;
    halQuiddikeyInterruptStatus_t int_status;
    halQuiddikeyKeyDest_t         key_dest;
    halQuiddikeyDataInput_t       data_in;
    halQuiddikeyDataOutput_t      data_out;
    halQuiddikeyEndianness_t      endianness;
    halQuiddikeyInterfaceStatus_t apb_itf_status;
    halQuiddikeyTest_t            test_cfg;
    halQuiddikeyHwRUC0_t          hw_ruc0;
    halQuiddikeyHwRUC1_t          hw_ruc1;
    halQuiddikeyHwSettings_t      hw_settings;
    halQuiddikeyInfo_t            info;
    halQuiddikeyID_t              id;
    halQuiddikeyVersion_t         version;
    uint32_t raw;
} __attribute__ ((packed)) halQuiddikey_u;


// QUIDDIKEY HAL Handle
// located in "archi/chip/x/memory_map.h"


// QUIDDIKEY HAL functions prototype
static inline uint32_t halQuiddikeyBaseAddrGet 			 (halQuiddikeyHandle_t * const handle);

static inline void     halQuiddikeyCfgSet                (halQuiddikeyHandle_t * const handle,  uint32_t data);
static inline uint32_t halQuiddikeyCfgGet                (halQuiddikeyHandle_t * const handle);
static inline void     halQuiddikeyStatusSet             (halQuiddikeyHandle_t * const handle,  uint32_t data);
static inline uint32_t halQuiddikeyStatusGet             (halQuiddikeyHandle_t * const handle);
static inline uint32_t halQuiddikeyAllowGet              (halQuiddikeyHandle_t * const handle);
static inline void     halQuiddikeyInterruptEnableSet    (halQuiddikeyHandle_t * const handle,  uint32_t data);
static inline uint32_t halQuiddikeyInterruptEnableGet    (halQuiddikeyHandle_t * const handle);
static inline void     halQuiddikeyInterruptMaskSet      (halQuiddikeyHandle_t * const handle,  uint32_t data);
static inline uint32_t halQuiddikeyInterruptMaskGet      (halQuiddikeyHandle_t * const handle);
static inline void     halQuiddikeyInterruptStatusSet    (halQuiddikeyHandle_t * const handle,  uint32_t data);
static inline uint32_t halQuiddikeyInterruptStatusGet    (halQuiddikeyHandle_t * const handle);
static inline void     halQuiddikeyKeyDestSet            (halQuiddikeyHandle_t * const handle,  uint32_t data);
static inline uint32_t halQuiddikeyKeyDestGet            (halQuiddikeyHandle_t * const handle);
static inline void     halQuiddikeyDataInputSet          (halQuiddikeyHandle_t * const handle,  uint32_t data);
static inline uint32_t halQuiddikeyDataOutputGet         (halQuiddikeyHandle_t * const handle);
static inline void     halQuiddikeyEndiannessSet         (halQuiddikeyHandle_t * const handle,  uint32_t data);
static inline uint32_t halQuiddikeyEndiannessGet         (halQuiddikeyHandle_t * const handle);
static inline void     halQuiddikeyApbInterfaceStatusSet (halQuiddikeyHandle_t * const handle,  uint32_t data);
static inline uint32_t halQuiddikeyApbInterfaceStatusGet (halQuiddikeyHandle_t * const handle);
static inline void     halQuiddikeyTestSet               (halQuiddikeyHandle_t * const handle,  uint32_t data);
static inline uint32_t halQuiddikeyTestGet               (halQuiddikeyHandle_t * const handle);
static inline uint32_t halQuiddikeyHwRUC0Get             (halQuiddikeyHandle_t * const handle);
static inline uint32_t halQuiddikeyHwRUC1Get             (halQuiddikeyHandle_t * const handle);
static inline uint32_t halQuiddikeyHwSettingsGet         (halQuiddikeyHandle_t * const handle);
static inline uint32_t halQuiddikeyHwInfoGet             (halQuiddikeyHandle_t * const handle);
static inline uint32_t halQuiddikeyHwIDGet               (halQuiddikeyHandle_t * const handle);
static inline uint32_t halQuiddikeyHwVersionGet          (halQuiddikeyHandle_t * const handle);




// QUIDDIKEY HAL functions definition
static inline uint32_t halQuiddikeyBaseAddrGet 			 (halQuiddikeyHandle_t * const handle) {
	return (uint32_t) (handle);
}

static inline void halQuiddikeyCfgSet (halQuiddikeyHandle_t * const handle, uint32_t data) {
    handle->cfg = data;
}

static inline uint32_t halQuiddikeyCfgGet (halQuiddikeyHandle_t * const handle) {
    return handle->cfg;
}

static inline void halQuiddikeyStatusSet (halQuiddikeyHandle_t * const handle, uint32_t data) {
    handle->status = data;
}

static inline uint32_t halQuiddikeyStatusGet (halQuiddikeyHandle_t * const handle) {
    return handle->status;
}

static inline uint32_t halQuiddikeyAllowGet (halQuiddikeyHandle_t * const handle) {
    return handle->allow;
}

static inline void halQuiddikeyInterruptEnableSet (halQuiddikeyHandle_t * const handle, uint32_t data) {
    handle->ier = data;
}

static inline uint32_t halQuiddikeyInterruptEnableGet (halQuiddikeyHandle_t * const handle) {
    return handle->ier;
}

static inline void halQuiddikeyInterruptMaskSet (halQuiddikeyHandle_t * const handle, uint32_t data) {
    handle->imr = data;
}

static inline uint32_t halQuiddikeyInterruptMaskGet (halQuiddikeyHandle_t * const handle) {
    return handle->imr;
}

static inline void halQuiddikeyInterruptStatusSet (halQuiddikeyHandle_t * const handle, uint32_t data) {
    handle->isr = data;
}

static inline uint32_t halQuiddikeyInterruptStatusGet (halQuiddikeyHandle_t * const handle) {
    return handle->isr;
}

static inline void halQuiddikeyKeyDestSet (halQuiddikeyHandle_t * const handle, uint32_t data) {
    handle->key_dest = data;
}

static inline uint32_t halQuiddikeyKeyDestGet (halQuiddikeyHandle_t * const handle) {
    return handle->key_dest;
}

static inline void halQuiddikeyDataInputSet (halQuiddikeyHandle_t * const handle, uint32_t data) {
    handle->dir = data;
}

static inline uint32_t halQuiddikeyDataOuputGet (halQuiddikeyHandle_t * const handle) {
    return handle->dor;
}

static inline void halQuiddikeyEndiannessSet (halQuiddikeyHandle_t * const handle, uint32_t data) {
    handle->misc = data;
}

static inline uint32_t halQuiddikeyEndiannessGet (halQuiddikeyHandle_t * const handle) {
    return handle->misc;
}

static inline void halQuiddikeyApbInterfaceStatusSet (halQuiddikeyHandle_t * const handle, uint32_t data) {
    handle->if_sr = data;
}

static inline uint32_t halQuiddikeyApbInterfaceStatusGet (halQuiddikeyHandle_t * const handle) {
    return handle->if_sr;
}

static inline void halQuiddikeyTestSet (halQuiddikeyHandle_t * const handle, uint32_t data) {
    handle->test = data;
}

static inline uint32_t halQuiddikeyTestGet (halQuiddikeyHandle_t * const handle) {
    return handle->test;
}

static inline uint32_t halQuiddikeyHwRUC0Get (halQuiddikeyHandle_t * const handle) {
    return handle->hw_ruc0;
}

static inline uint32_t halQuiddikeyHwRUC1Get (halQuiddikeyHandle_t * const handle) {
    return handle->hw_ruc1;
}

static inline uint32_t halQuiddikeyHwSettingsGet (halQuiddikeyHandle_t * const handle) {
    return handle->hw_settings;
}

static inline uint32_t halQuiddikeyHwInfoGet (halQuiddikeyHandle_t * const handle) {
    return handle->hw_info;
}

static inline uint32_t halQuiddikeyHwIDGet (halQuiddikeyHandle_t * const handle) {
    return handle->hw_id;
}

static inline uint32_t halQuiddikeyHwVersionGet (halQuiddikeyHandle_t * const handle) {
    return handle->hw_ver;
}

#endif