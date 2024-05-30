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

#ifndef __HAL_UDMA_UDMA_SPIM_V3_H__
#define __HAL_UDMA_UDMA_SPIM_V3_H__

#include "archi/udma/spim/udma_spim_v3.h"

#define UDMA_SPIM_OFFSET(id)          UDMA_PERIPH_OFFSET(ARCHI_UDMA_SPIM_ID(id))
#define UDMA_SPIM_CMD_ADDR(id)        (ARCHI_UDMA_ADDR + UDMA_SPIM_OFFSET(id) + 0x20)
#define UDMA_SPIM_RX_ADDR(id)         (ARCHI_UDMA_ADDR + UDMA_SPIM_OFFSET(id) + 0x00)
#define UDMA_SPIM_TX_ADDR(id)         (ARCHI_UDMA_ADDR + UDMA_SPIM_OFFSET(id) + 0x10)
#define UDMA_SPIM_CUSTOM_ADDR(id)     (ARCHI_UDMA_ADDR + UDMA_SPIM_OFFSET(id) + UDMA_CHANNEL_CUSTOM_OFFSET)

#endif
