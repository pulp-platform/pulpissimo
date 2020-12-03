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

#ifndef __HAL_UDMA_UDMA_PERIPH_I2S_V1_H__
#define __HAL_UDMA_UDMA_PERIPH_I2S_V1_H__

#include "archi/udma/i2s/udma_i2s_v1.h"
#include "archi/utils.h"

static inline void hal_i2s_ext_clk_set(int i2s, unsigned int value);

static inline unsigned int hal_i2s_ext_clk_get(int i2s);

static inline void hal_i2s_cfg_clkgen_set(int i2s, int clk, unsigned int value);

static inline unsigned int hal_i2s_cfg_clkgen_get(int i2s, int clk);

static inline void hal_i2s_chmode_set(int i2s, unsigned int value);

static inline unsigned int hal_i2s_chmode_get(int i2s);

static inline void hal_i2s_filt_ch_set(int i2s, int ch, unsigned int value);

static inline unsigned int hal_i2s_filt_ch_get(int i2s, int ch);




/// @cond IMPLEM

static inline void hal_i2s_ext_clk_set(int i2s, unsigned int value)
{
  pulp_write32(UDMA_I2S_CUSTOM_ADDR(i2s) + I2S_EXT_OFFSET, value);
}

static inline unsigned int hal_i2s_ext_clk_get(int i2s)
{
  return pulp_read32(UDMA_I2S_CUSTOM_ADDR(i2s) + I2S_EXT_OFFSET);
}

static inline void hal_i2s_cfg_clkgen_set(int i2s, int clk, unsigned int value)
{
  pulp_write32(UDMA_I2S_CUSTOM_ADDR(i2s) + I2S_CFG_CLKGEN_OFFSET(clk), value);
}

static inline unsigned int hal_i2s_cfg_clkgen_get(int i2s, int clk)
{
  return pulp_read32(UDMA_I2S_CUSTOM_ADDR(i2s) + I2S_CFG_CLKGEN_OFFSET(clk));
}

static inline void hal_i2s_chmode_set(int i2s, unsigned int value)
{
  pulp_write32(UDMA_I2S_CUSTOM_ADDR(i2s) + I2S_CHMODE_OFFSET, value);
}

static inline unsigned int hal_i2s_chmode_get(int i2s)
{
  return pulp_read32(UDMA_I2S_CUSTOM_ADDR(i2s) + I2S_CHMODE_OFFSET);
}

static inline void hal_i2s_filt_ch_set(int i2s, int ch, unsigned int value)
{
  pulp_write32(UDMA_I2S_CUSTOM_ADDR(i2s) + I2S_FILT_CH_OFFSET(ch), value);
}

static inline unsigned int hal_i2s_filt_ch_get(int i2s, int ch)
{
  return pulp_read32(UDMA_I2S_CUSTOM_ADDR(i2s) + I2S_FILT_CH_OFFSET(ch));
}



static inline unsigned int hal_i2s_clkgen_en_update(unsigned int reg_value, unsigned int field_value)
{
  return ARCHI_BINSERT(reg_value, field_value, I2S_CFG_CLKGEN_CLK_EN_WIDTH, I2S_CFG_CLKGEN_CLK_EN_OFFSET);
}



/// @endcond

#endif
