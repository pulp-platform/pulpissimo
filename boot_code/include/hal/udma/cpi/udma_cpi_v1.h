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

#ifndef __HAL_UDMA_UDMA_CPI_V1_H__
#define __HAL_UDMA_UDMA_CPI_V1_H__

#include "archi/udma/cpi/udma_cpi_v1_old.h"

#define UDMA_CAM_OFFSET(id)           UDMA_PERIPH_OFFSET(ARCHI_UDMA_CAM_ID(id))

#define UDMA_CAM_RX_ADDR(id)          (ARCHI_UDMA_ADDR + UDMA_CAM_OFFSET(id) + UDMA_CHANNEL_RX_OFFSET)
#define UDMA_CAM_CUSTOM_ADDR(id)      (ARCHI_UDMA_ADDR + UDMA_CAM_OFFSET(id) + UDMA_CHANNEL_CUSTOM_OFFSET)
#define ARCHI_SOC_EVENT_CAM_RX(id)    ARCHI_SOC_EVENT_UDMA_RX(ARCHI_UDMA_CAM_ID(id))


// UDMA RX/TX Channels HAL Registers Structure
typedef struct {
    uint32_t rx_ch_saddr;
    uint32_t rx_ch_size;
    uint32_t rx_ch_cfg;
    uint32_t rx_ch_initcfg_unused;
    uint32_t tx_ch_saddr;
    uint32_t tx_ch_size;
    uint32_t tx_ch_cfg;
    uint32_t tx_ch_initcfg_unused;
} plpUdmaRxTxChHandle2_t;

// CAM HAL Registers Structure
typedef struct {
    plpUdmaRxTxChHandle2_t udma_rxtx_ch_handle;
    uint32_t cfg_glob;
    uint32_t cfg_ll;
    uint32_t cfg_ur;
    uint32_t cfg_size;
    uint32_t cfg_filter;
} plpUdmaCameraHandle_t;

// CAM HAL Register Fields Structure
typedef struct {
    uint32_t framedrop_enable:1;
    uint32_t framedrop_value:6;
    uint32_t frameslice_enable:1;
    uint32_t format:3;
    uint32_t shift:4;
    uint32_t unused:16;
    uint32_t enable:1;
} __attribute__ ((packed)) plpUdmaCamCfgGlob_t;

typedef struct {
    uint32_t frameslice_llx:16;
    uint32_t frameslice_lly:16;
} __attribute__ ((packed)) plpUdmaCamCfgLl_t;

typedef struct {
    uint32_t frameslice_urx:16;
    uint32_t frameslice_ury:16;
} __attribute__ ((packed)) plpUdmaCamCfgUr_t;

typedef struct {
    uint32_t unused:16;
    uint32_t row_length:16;
} __attribute__ ((packed)) plpUdmaCamCfgSize_t;

typedef struct {
    uint32_t b_coeff:8;
    uint32_t g_coeff:8;
    uint32_t r_coeff:8;
    uint32_t unused:8;
} __attribute__ ((packed)) plpUdmaCamCfgFilter_t;

// CAM HAL Register Union definition
typedef union {
    plpUdmaCamCfgGlob_t cfg_glob;
    plpUdmaCamCfgLl_t cfg_ll;
    plpUdmaCamCfgUr_t cfg_ur;
    plpUdmaCamCfgSize_t cfg_size;
    plpUdmaCamCfgFilter_t cfg_filter;
    uint32_t raw;
} __attribute__ ((packed)) plpUdmaCamCustom_u;

static inline void hal_cpi_ll_set(int cpi, unsigned int value){
  pulp_write32(UDMA_CAM_CUSTOM_ADDR(cpi) + CAM_LL_OFFSET, value);
}
static inline unsigned int hal_cpi_ll_read(int cpi){
  return pulp_read32(UDMA_CAM_CUSTOM_ADDR(cpi) + CAM_LL_OFFSET);
}
static inline void hal_cpi_ur_set(int cpi, unsigned int value){
  pulp_write32(UDMA_CAM_CUSTOM_ADDR(cpi) + CAM_UR_OFFSET, value);
}
static inline unsigned int hal_cpi_ur_read(int cpi){
  return  pulp_read32(UDMA_CAM_CUSTOM_ADDR(cpi) + CAM_UR_OFFSET);
}
static inline void hal_cpi_size_set(int cpi, unsigned int value){
  pulp_write32(UDMA_CAM_CUSTOM_ADDR(cpi) + CAM_SIZE_OFFSET, value);
}
static inline unsigned int hal_cpi_size_read(int cpi){
  return pulp_read32(UDMA_CAM_CUSTOM_ADDR(cpi) + CAM_SIZE_OFFSET);
}
static inline void hal_cpi_glob_set(int cpi, unsigned int value){
  pulp_write32(UDMA_CAM_CUSTOM_ADDR(cpi) + CAM_GLOB_OFFSET, value);
}
static inline unsigned int hal_cpi_glob_read(int cpi){
  return pulp_read32(UDMA_CAM_CUSTOM_ADDR(cpi) + CAM_GLOB_OFFSET);
}
static inline void hal_cpi_filter_set(int cpi, unsigned int value){
  pulp_write32(UDMA_CAM_CUSTOM_ADDR(cpi) + CAM_FILTER_OFFSET, value);
}
static inline unsigned int hal_cpi_filter_read(int cpi){
  return pulp_read32(UDMA_CAM_CUSTOM_ADDR(cpi) + CAM_FILTER_OFFSET);
}

///////////////////////////////////////////////////
// TODO Obsolete : to be removed cause deprecated
static inline void plp_cam_glob_set(int enabled, int frameDropEn, int nbFrameDrop, int frameSliceEn, int format, int shift)
{
  unsigned int value = (enabled << CAM_CFG_GLOB_EN_BIT) | (frameDropEn << CAM_CFG_GLOB_FRAMEDROP_EN_BIT) | (nbFrameDrop << CAM_CFG_GLOB_FRAMEDROP_VAL_BIT) | (format << CAM_CFG_GLOB_FORMAT_BIT) | (shift << CAM_CFG_GLOB_SHIFT_BIT);
  pulp_write32(ARCHI_UDMA_ADDR + UDMA_CAM_OFFSET(0) + UDMA_CHANNEL_CUSTOM_OFFSET + CAM_GLOB_OFFSET, value);
}

// CAM HAL Handle
#define CAM_HANDLE(id) ((plpUdmaCameraHandle_t *)(ARCHI_UDMA_ADDR + UDMA_CAM_OFFSET(id)))

// CAM HAL functions prototype
static inline void plpUdmaCamGlobSet (plpUdmaCameraHandle_t * const handle, uint32_t data);
static inline uint32_t plpUdmaCamGlobGet (plpUdmaCameraHandle_t * const handle);
static inline void plpUdmaCamLlSet (plpUdmaCameraHandle_t * const handle, uint32_t data);
static inline uint32_t plpUdmaCamLlGet (plpUdmaCameraHandle_t * const handle);
static inline void plpUdmaCamUrSet (plpUdmaCameraHandle_t * const handle, uint32_t data);
static inline uint32_t plpUdmaCamUrGet (plpUdmaCameraHandle_t * const handle);
static inline void plpUdmaCamSizeSet (plpUdmaCameraHandle_t * const handle, uint32_t data);
static inline uint32_t plpUdmaCamSizeGet (plpUdmaCameraHandle_t * const handle);
static inline void plpUdmaCamFilterSet (plpUdmaCameraHandle_t * const handle, uint32_t data);
static inline uint32_t plpUdmaCamFilterGet (plpUdmaCameraHandle_t * const handle);

// CAM HAL functions definition
static inline void plpUdmaCamGlobSet (plpUdmaCameraHandle_t * const handle, uint32_t data) {
    handle->cfg_glob = data;
}

static inline uint32_t plpUdmaCamGlobGet (plpUdmaCameraHandle_t * const handle) {
    return handle->cfg_glob;
}

static inline void plpUdmaCamLlSet (plpUdmaCameraHandle_t * const handle, uint32_t data) {
    handle->cfg_ll = data;
}

static inline uint32_t plpUdmaCamLlGet (plpUdmaCameraHandle_t * const handle) {
    return handle->cfg_ll;
}

static inline void plpUdmaCamUrSet (plpUdmaCameraHandle_t * const handle, uint32_t data) {
    handle->cfg_ur = data;
}

static inline uint32_t plpUdmaCamUrGet (plpUdmaCameraHandle_t * const handle) {
    return handle->cfg_ur;
}

static inline void plpUdmaCamSizeSet (plpUdmaCameraHandle_t * const handle, uint32_t data) {
    handle->cfg_size = data;
}

static inline uint32_t plpUdmaCamSizeGet (plpUdmaCameraHandle_t * const handle) {
    return handle->cfg_size;
}

static inline void plpUdmaCamFilterSet (plpUdmaCameraHandle_t * const handle, uint32_t data) {
    handle->cfg_filter = data;
}

static inline uint32_t plpUdmaCamFilterGet (plpUdmaCameraHandle_t * const handle) {
    return handle->cfg_filter;
}

///////////////////////////////////////////////////

#endif