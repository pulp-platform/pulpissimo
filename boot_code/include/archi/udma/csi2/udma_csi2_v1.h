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

#ifndef __ARCHI_UDMA_UDMA_CSI2_V1_H__
#define __ARCHI_UDMA_UDMA_CSI2_V1_H__

// CSI2 custom registers offset definition

#define CSI2_CLK_CFG_OFFSET       (0x00)

// CSI2 custom registers bitfields offset, mask, value definition
#define CSI2_CLK_CFG_CCI_BIT      0
#define CSI2_CLK_CFG_CCI_BITS     8
#define CSI2_CLK_CFG_CCI_MASK     ARCHI_REG_MASK(CSI2_CLK_CFG_CCI_BIT, CSI2_CLK_CFG_CCI_BITS)
#define CSI2_CLK_CFG_CCI(val)     (val << CSI2_CLK_CFG_CCI_BIT)

#define CSI2_CLK_CFG_PIXEL_BIT      8
#define CSI2_CLK_CFG_PIXEL_BITS     8
#define CSI2_CLK_CFG_PIXEL_MASK     ARCHI_REG_MASK(CSI2_CLK_CFG_PIXEL_BIT, CSI2_CLK_CFG_PIXEL_BITS)
#define CSI2_CLK_CFG_PIXEL(val)     (val << CSI2_CLK_CFG_PIXEL_BIT)

#endif