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

#ifndef __HAL_UDMA_UDMA_I2C_V1_H__
#define __HAL_UDMA_UDMA_I2C_V1_H__

#include "archi/udma/i2c/udma_i2c_v1.h"

static inline uint32_t hal_udma_i2c_setup_compute(int en, int div)
{
  return (en << I2C_CMD_SETUP_ENABLE_BIT) | ( div << I2C_CMD_SETUP_DIV_BIT);
}

static inline void hal_udma_i2c_setup_set(uint32_t periph_base, uint32_t value)
{
  pulp_write32(periph_base + UDMA_CHANNEL_CUSTOM_OFFSET + ARCHI_I2C_SETUP_OFFSET, value);
}

static inline uint32_t hal_udma_i2c_setup_get(uint32_t periph_base)
{
  return pulp_read32(periph_base + UDMA_CHANNEL_CUSTOM_OFFSET + ARCHI_I2C_SETUP_OFFSET);
}

#endif