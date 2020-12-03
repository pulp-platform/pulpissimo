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

#ifndef __HAL_UDMA_UDMA_CSI2_V1_H__
#define __HAL_UDMA_UDMA_CSI2_V1_H__

#include "archi/udma/csi2/udma_csi2_v1.h"

#define UDMA_CSI2_OFFSET(id)           UDMA_PERIPH_OFFSET(ARCHI_UDMA_CSI2_ID(id))

#define UDMA_CSI2_RX_ADDR(id)          (ARCHI_UDMA_ADDR + UDMA_CSI2_OFFSET(id) + UDMA_CHANNEL_RX_OFFSET)
#define UDMA_CSI2_CUSTOM_ADDR(id)      (ARCHI_UDMA_ADDR + UDMA_CSI2_OFFSET(id) + UDMA_CHANNEL_CUSTOM_OFFSET)
// NOTE defined in archi/vega/properties.h
// #define ARCHI_SOC_EVENT_CSI2_RX(id)    ARCHI_SOC_EVENT_UDMA_RX(ARCHI_UDMA_CSI2_ID(id))

// CSI2 HAL Registers Structure
struct plpUdmaCsi2_struct_t {
    plpUdmaRxTxChHandle_t udma_rxtx_ch_handle;
    uint32_t unused;
    uint32_t cfg_clk;
};
typedef volatile struct plpUdmaCsi2_struct_t plpUdmaCsi2Handle_t;

// CSI2 HAL Handle
// located in "archi/chip/vega/memory_map.h"

// CSI2 HAL functions prototype
static inline void plpUdmaCsi2ClkCfgSet (plpUdmaCsi2Handle_t * handle, uint32_t data);
static inline uint32_t plpUdmaCsi2ClkCfgGet (plpUdmaCsi2Handle_t * handle);

// CSI2 HAL functions definition
static inline void plpUdmaCsi2ClkCfgSet (plpUdmaCsi2Handle_t * handle, uint32_t data) {
    handle->cfg_clk = data;
}

static inline uint32_t plpUdmaCsi2ClkCfgGet (plpUdmaCsi2Handle_t * handle) {
    return handle->cfg_clk;
}

#endif