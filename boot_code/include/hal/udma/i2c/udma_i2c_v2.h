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

#ifndef __HAL_UDMA_UDMA_I2C_V2_H__
#define __HAL_UDMA_UDMA_I2C_V2_H__

#include "archi/udma/i2c/udma_i2c_v2.h"

#define UDMA_I2C_OFFSET(id)           UDMA_PERIPH_OFFSET(ARCHI_UDMA_I2C_ID(id))

#define UDMA_I2C_DATA_ADDR(id)        (ARCHI_UDMA_ADDR + UDMA_I2C_OFFSET(id) + UDMA_CHANNEL_RX_OFFSET)
#define UDMA_I2C_CMD_ADDR(id)         (ARCHI_UDMA_ADDR + UDMA_I2C_OFFSET(id) + UDMA_CHANNEL_TX_OFFSET)
#define UDMA_I2C_CUSTOM_ADDR(id)      (ARCHI_UDMA_ADDR + UDMA_I2C_OFFSET(id) + UDMA_CHANNEL_CUSTOM_OFFSET)
#define ARCHI_SOC_EVENT_I2C_DATA(id)    (ARCHI_SOC_EVENT_PERIPH_FIRST_EVT(ARCHI_UDMA_I2C_ID(id)) + 0)
#define ARCHI_SOC_EVENT_I2C_CMD(id)    (ARCHI_SOC_EVENT_PERIPH_FIRST_EVT(ARCHI_UDMA_I2C_ID(id)) + 1)

#endif