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

#ifndef __HAL_LNT_CSI2_V1_H__
#define __HAL_LNT_CSI2_V1_H__

#include <hal/pulp.h>
#include <stdint.h>
#include "archi/vendors/lnt/csi2_v1.h"

#if CSI2_VERSION != 1
#error This file must be included only with quiddikey version 1
#endif

// CSI2 HAL Registers Structure
struct halCsi2_struct_t {
	uint32_t unused[96];		// offset to start reg access @ 0x60<<2
    uint32_t cfg;				// default value 0x0
    uint32_t err_msb1;				// default value 0x0
    uint32_t err_msb;				// default value 0x0
    uint32_t err_lsb;				// default value 0x0
    uint32_t hs_rx_timeout_msb2;				// default value 0xff
    uint32_t hs_rx_timeout_msb1;				// default value 0xff
    uint32_t hs_rx_timeout_lsb;				// default value 0xff
    uint32_t vccfg;				// default value 0x1
    uint32_t polarity;				// default value 0x0
    uint32_t cci_addr;				// default value 0x0
    uint32_t cci_wr_data;				// default value 0x0
    uint32_t cci_rd_data;				// default value 0x0
    uint32_t cci_read_write;				// default value 0x0
    uint32_t cci_status;				// default value 0x0
    uint32_t cci_device_addr;				// default value 0x3c
    uint32_t ulps_status;				// default value 0x0
};
typedef volatile struct halCsi2_struct_t halCsi2Handle_t;

// DPHY HAL Registers Structure
struct halDphy_struct_t {
    uint32_t lane_enable;				// default value 0x1
    uint32_t unused[31];
    //TODO add missing new registers visible in v1.6
    uint32_t reset_dig_logic;				// default value 0x1f
    uint32_t unused1[41];
    uint32_t lane_ck_cont_mode;				// default value 0x0f  
    uint32_t unused2[13];
    uint32_t lane_ck_hs_countdown;				// default value 0x1b
    uint32_t unused3[1];
    uint32_t lane_ck_rx_calib_enable;				// default value 0x7f
    uint32_t unused4[29];
    uint32_t lane_0_hs_countdown;				// default value 0x1b
    uint32_t unused5[1];
    uint32_t lane_0_rx_calib_enable;				// default value 0x7f
    uint32_t unused6[29];
    uint32_t lane_1_hs_countdown;				// default value 0x1b
    uint32_t unused7[1];
    uint32_t lane_1_rx_calib_enable;				// default value 0x7f
};
typedef volatile struct halDphy_struct_t halDphyHandle_t;

// TODO CSI2 HAL Register Fields Structure
// typedef struct {
//     uint32_t zeroize       : 1;
//     uint32_t unused2       : 16;
// } __attribute__ ((packed)) halQuiddikeyCfg_t;

// TODO CSI2 HAL Register Union definition
// typedef union {
//     halQuiddikeyCfg_t             config;
//     halQuiddikeyStatus_t          status;
//     uint32_t raw;
// } __attribute__ ((packed)) halQuiddikey_u;




// CSI2 HAL Handle
// located in "archi/chip/x/memory_map.h"

// DPHY HAL Handle
// located in "archi/chip/x/memory_map.h"


//     CSI2   HAL      functions                  prototype
static inline uint32_t halCsi2BaseAddrGet         (halCsi2Handle_t * handle);
static inline void     halCsi2CfgSet              (halCsi2Handle_t * handle,  uint32_t data);
static inline uint32_t halCsi2CfgGet              (halCsi2Handle_t * handle);
static inline uint32_t halCsi2ErrMsb1Get          (halCsi2Handle_t * handle);
static inline uint32_t halCsi2ErrMsbGet           (halCsi2Handle_t * handle);
static inline uint32_t halCsi2ErrLsbGet           (halCsi2Handle_t * handle);
static inline void     halCsi2HsRxTimeoutMsb2Set  (halCsi2Handle_t * handle,  uint32_t data);
static inline uint32_t halCsi2HsRxTimeoutMsb2Get  (halCsi2Handle_t * handle);
static inline void     halCsi2HsRxTimeoutMsb1Set  (halCsi2Handle_t * handle,  uint32_t data);
static inline uint32_t halCsi2HsRxTimeoutMsb1Get  (halCsi2Handle_t * handle);
static inline void     halCsi2HsRxTimeoutLsbSet   (halCsi2Handle_t * handle,  uint32_t data);
static inline uint32_t halCsi2HsRxTimeoutLsbGet   (halCsi2Handle_t * handle);
static inline void     halCsi2VcCfgSet            (halCsi2Handle_t * handle,  uint32_t data);
static inline uint32_t halCsi2VcCfgGet            (halCsi2Handle_t * handle);
static inline void     halCsi2PolaritySet         (halCsi2Handle_t * handle,  uint32_t data);
static inline uint32_t halCsi2PolarityGet         (halCsi2Handle_t * handle);
static inline void     halCsi2CciAddressSet       (halCsi2Handle_t * handle,  uint32_t data);
static inline uint32_t halCsi2CciAddressGet       (halCsi2Handle_t * handle);
static inline void     halCsi2CciWriteDataSet     (halCsi2Handle_t * handle,  uint32_t data);
static inline uint32_t halCsi2CciWriteDataGet     (halCsi2Handle_t * handle);
static inline uint32_t halCsi2CciReadDataGet      (halCsi2Handle_t * handle);
static inline void     halCsi2CciReadWriteSet     (halCsi2Handle_t * handle,  uint32_t data);
static inline uint32_t halCsi2CciReadWriteGet     (halCsi2Handle_t * handle);
static inline uint32_t halCsi2CciStatusGet        (halCsi2Handle_t * handle);
static inline void     halCsi2CciDeviceAddressSet (halCsi2Handle_t * handle,  uint32_t data);
static inline uint32_t halCsi2CciDeviceAddressGet (halCsi2Handle_t * handle);
static inline uint32_t halCsi2UlpsStatusGet       (halCsi2Handle_t * handle);

//     DPHY   HAL      functions            prototype
static inline uint32_t halDphyBaseAddrGet           (halDphyHandle_t * handle);
static inline void     halDphyLaneEnableSet         (halDphyHandle_t * handle,  uint32_t data);
static inline uint32_t halDphyLaneEnableGet         (halDphyHandle_t * handle);
static inline void     halDphyResetDigLogicSet      (halDphyHandle_t * handle,  uint32_t data);
static inline uint32_t halDphyResetDigLogicGet      (halDphyHandle_t * handle);
static inline void     halDphyLaneClkHsCountdownSet (halDphyHandle_t * handle,  uint32_t data);
static inline uint32_t halDphyLaneClkHsCountdownGet (halDphyHandle_t * handle);
static inline void     halDphyLaneClkContModeSet    (halDphyHandle_t * handle,  uint32_t data);
static inline uint32_t halDphyLaneClkContModeGet    (halDphyHandle_t * handle);
static inline void     halDphyLaneClkRxCalibSet     (halDphyHandle_t * handle,  uint32_t data);
static inline uint32_t halDphyLaneClkRxCalibGet     (halDphyHandle_t * handle);
static inline void     halDphyLane0HsCountdownSet   (halDphyHandle_t * handle,  uint32_t data);
static inline uint32_t halDphyLane0HsCountdownGet   (halDphyHandle_t * handle);
static inline void     halDphyLane0RxCalibSet       (halDphyHandle_t * handle,  uint32_t data);
static inline uint32_t halDphyLane0RxCalibGet       (halDphyHandle_t * handle);
static inline void     halDphyLane1HsCountdownSet   (halDphyHandle_t * handle,  uint32_t data);
static inline uint32_t halDphyLane1HsCountdownGet   (halDphyHandle_t * handle);
static inline void     halDphyLane1RxCalibSet       (halDphyHandle_t * handle,  uint32_t data);
static inline uint32_t halDphyLane1RxCalibGet       (halDphyHandle_t * handle);

// TODO

// CSI2 HAL functions definition
static inline uint32_t halCsi2BaseAddrGet 			 (halCsi2Handle_t * handle) {
	return (uint32_t) (handle);
}

static inline void halCsi2CfgSet (halCsi2Handle_t * handle, uint32_t data) {
    handle->cfg = data;
}

static inline uint32_t halCsi2CfgGet (halCsi2Handle_t * handle) {
    return handle->cfg;
}

static inline uint32_t halCsi2ErrMsb1Get          (halCsi2Handle_t * handle) {
	return handle->err_msb1;
}

static inline uint32_t halCsi2ErrMsbGet           (halCsi2Handle_t * handle) {
	return handle->err_msb;
}

static inline uint32_t halCsi2ErrLsbGet           (halCsi2Handle_t * handle) {
	return handle->err_lsb;
}

static inline void     halCsi2HsRxTimeoutMsb2Set  (halCsi2Handle_t * handle,  uint32_t data) {
	handle->hs_rx_timeout_msb2 = data;
}

static inline uint32_t halCsi2HsRxTimeoutMsb2Get  (halCsi2Handle_t * handle) {
	return handle->hs_rx_timeout_msb2;
}

static inline void     halCsi2HsRxTimeoutMsb1Set  (halCsi2Handle_t * handle,  uint32_t data) {
	handle->hs_rx_timeout_msb1 = data;
}

static inline uint32_t halCsi2HsRxTimeoutMsb1Get  (halCsi2Handle_t * handle) {
	return handle->hs_rx_timeout_msb1;
}

static inline void     halCsi2HsRxTimeoutLsbSet   (halCsi2Handle_t * handle,  uint32_t data) {
	handle->hs_rx_timeout_lsb = data;
}

static inline uint32_t halCsi2HsRxTimeoutLsbGet   (halCsi2Handle_t * handle) {
	return handle->hs_rx_timeout_lsb;
}

static inline void     halCsi2VcCfgSet            (halCsi2Handle_t * handle,  uint32_t data) {
	handle->vccfg = data;
}

static inline uint32_t halCsi2VcCfgGet            (halCsi2Handle_t * handle) {
	return handle->vccfg;
}

static inline void     halCsi2PolaritySet         (halCsi2Handle_t * handle,  uint32_t data) {
	handle->polarity = data;
}

static inline uint32_t halCsi2PolarityGet         (halCsi2Handle_t * handle) {
	return handle->polarity;
}

static inline void     halCsi2CciAddressSet       (halCsi2Handle_t * handle,  uint32_t data) {
	handle->cci_addr = data;
}

static inline uint32_t halCsi2CciAddressGet       (halCsi2Handle_t * handle) {
	return handle->cci_addr;
}

static inline void     halCsi2CciWriteDataSet     (halCsi2Handle_t * handle,  uint32_t data) {
	handle->cci_wr_data = data;
}

static inline uint32_t halCsi2CciWriteDataGet     (halCsi2Handle_t * handle) {
	return handle->cci_wr_data;
}

static inline uint32_t halCsi2CciReadDataGet      (halCsi2Handle_t * handle) {
	return handle->cci_rd_data;
}

static inline void     halCsi2CciReadWriteSet     (halCsi2Handle_t * handle,  uint32_t data) {
	handle->cci_read_write = data;
}

static inline uint32_t halCsi2CciReadWriteGet     (halCsi2Handle_t * handle) {
	return handle->cci_read_write;
}

static inline uint32_t halCsi2CciStatusGet        (halCsi2Handle_t * handle) {
	return handle->cci_status;
}

static inline void     halCsi2CciDeviceAddressSet (halCsi2Handle_t * handle,  uint32_t data) {
	handle->cci_device_addr = data;
}

static inline uint32_t halCsi2CciDeviceAddressGet (halCsi2Handle_t * handle) {
	return handle->cci_device_addr;
}

static inline uint32_t halCsi2UlpsStatusGet       (halCsi2Handle_t * handle) {
	return handle->ulps_status;
}




// DPHY HAL functions definition
static inline uint32_t halDphyBaseAddrGet            (halDphyHandle_t * handle) {
    return (uint32_t) (handle);
}

static inline void     halDphyLaneEnableSet                (halDphyHandle_t * handle,  uint32_t data) {
    handle->lane_enable = data;
}

static inline uint32_t halDphyLaneEnableGet                (halDphyHandle_t * handle) {
    return handle->lane_enable;
}

static inline void     halDphyResetDigLogicSet (halDphyHandle_t * handle,  uint32_t data) {
	handle->reset_dig_logic = data;
}

static inline uint32_t halDphyResetDigLogicGet (halDphyHandle_t * handle) {
	return handle->reset_dig_logic;
}

static inline void     halDphyLaneClkHsCountdownSet (halDphyHandle_t * handle,  uint32_t data) {
	handle->lane_ck_hs_countdown = data;
}

static inline uint32_t halDphyLaneClkHsCountdownGet (halDphyHandle_t * handle) {
	return handle->lane_ck_hs_countdown;
}

static inline void     halDphyLaneClkContModeSet (halDphyHandle_t * handle,  uint32_t data) {
	handle->lane_ck_cont_mode = data;
}

static inline uint32_t halDphyLaneClkContModeGet (halDphyHandle_t * handle) {
	return handle->lane_ck_cont_mode;
}

static inline void     halDphyLaneClkRxCalibSet (halDphyHandle_t * handle,  uint32_t data) {
	handle->lane_ck_rx_calib_enable = data;
}

static inline uint32_t halDphyLaneClkRxCalibGet (halDphyHandle_t * handle) {
	return handle->lane_ck_rx_calib_enable;
}

static inline void     halDphyLane0HsCountdownSet (halDphyHandle_t * handle,  uint32_t data) {
	handle->lane_0_hs_countdown = data;
}

static inline uint32_t halDphyLane0HsCountdownGet (halDphyHandle_t * handle) {
	return handle->lane_0_hs_countdown;
}

static inline void     halDphyLane0RxCalibSet (halDphyHandle_t * handle,  uint32_t data) {
	handle->lane_0_rx_calib_enable = data;
}

static inline uint32_t halDphyLane0RxCalibGet (halDphyHandle_t * handle) {
	return handle->lane_0_rx_calib_enable;
}

static inline void     halDphyLane1HsCountdownSet (halDphyHandle_t * handle,  uint32_t data) {
	handle->lane_1_hs_countdown = data;
}

static inline uint32_t halDphyLane1HsCountdownGet (halDphyHandle_t * handle) {
	return handle->lane_1_hs_countdown;
}

static inline void     halDphyLane1RxCalibSet (halDphyHandle_t * handle,  uint32_t data) {
	handle->lane_1_rx_calib_enable = data;
}

static inline uint32_t halDphyLane1RxCalibGet (halDphyHandle_t * handle) {
	return handle->lane_1_rx_calib_enable;
}


#endif