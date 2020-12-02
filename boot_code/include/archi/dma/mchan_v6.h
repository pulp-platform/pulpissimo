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

#ifndef ARCHI_DMA_MCHAN_V6_H
#define ARCHI_DMA_MCHAN_V6_H

// Register map

#define MCHAN_CMD_OFFSET                         0x0
#define MCHAN_STATUS_OFFSET                      0x4

#define PLP_DMA_QUEUE_OFFSET   0x0
#define PLP_DMA_STATUS_OFFSET  0x4

#define MCHAN_CMD_CMD_LEN_BIT                                        0
#define MCHAN_CMD_CMD_LEN_WIDTH                                      16

// Command bitfield

#define PLP_DMA_SIZE_BIT    0
#define PLP_DMA_SIZE_WIDTH  16
#define PLP_DMA_TYPE_BIT   (PLP_DMA_SIZE_WIDTH)
#define PLP_DMA_INCR_BIT   (PLP_DMA_SIZE_WIDTH + 1)
#define PLP_DMA_2D_BIT     (PLP_DMA_SIZE_WIDTH + 2)
#define PLP_DMA_ELE_BIT    (PLP_DMA_SIZE_WIDTH + 3)
#define PLP_DMA_ILE_BIT    (PLP_DMA_SIZE_WIDTH + 4)
#define PLP_DMA_BLE_BIT    (PLP_DMA_SIZE_WIDTH + 5)

#define PLP_DMA_LOC2EXT 0
#define PLP_DMA_EXT2LOC 1

#define PLP_DMA_1D 0
#define PLP_DMA_2D 1

#define PLP_DMA_NO_TRIG_EVT 0
#define PLP_DMA_TRIG_EVT    1

#define PLP_DMA_NO_TRIG_IRQ 0
#define PLP_DMA_TRIG_IRQ    1

#define PLP_DMA_PRIV        0
#define PLP_DMA_SHARED      1

#define PLP_DMA_FIX         0
#define PLP_DMA_INC         1

// Stride bitfield

#define PLP_DMA_2D_STRIDE_BIT    16
#define PLP_DMA_2D_STRIDE_WIDTH  15

#define PLP_DMA_2D_LEN_BIT       0
#define PLP_DMA_2D_LEN_WIDTH     15

// Macros
#define PLP_DMA_SIZE_GET(x)    (((x) >> PLP_DMA_SIZE_BIT) & ((1<<PLP_DMA_SIZE_WIDTH)-1))
#define PLP_DMA_TYPE_GET(x)    (((x) >> PLP_DMA_TYPE_BIT) & 1)
#define PLP_DMA_INCR_GET(x)    (((x) >> PLP_DMA_INCR_BIT) & 1)
#define PLP_DMA_2D_GET(x)      (((x) >> PLP_DMA_2D_BIT)   & 1)
#define PLP_DMA_ELE_GET(x)     (((x) >> PLP_DMA_ELE_BIT)  & 1)
#define PLP_DMA_ILE_GET(x)     (((x) >> PLP_DMA_ILE_BIT)  & 1)
#define PLP_DMA_BLE_GET(x)     (((x) >> PLP_DMA_BLE_BIT)  & 1)

#define PLP_DMA_2D_STRIDE_GET(x)   (((x) >> PLP_DMA_2D_STRIDE_BIT) & ((1<<PLP_DMA_2D_STRIDE_WIDTH)-1))
#define PLP_DMA_2D_LEN_GET(x) (((x) >> PLP_DMA_2D_LEN_BIT) & ((1<<PLP_DMA_2D_LEN_WIDTH)-1))

#endif
