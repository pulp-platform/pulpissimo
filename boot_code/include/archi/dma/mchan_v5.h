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

#ifndef __ARCHI_DMA_MCHAN_V5_H__
#define __ARCHI_DMA_MCHAN_V5_H__

#define MCHAN_COMMAND_QUEUE_OFFSET   0x0
#define MCHAN_STATUS_REGISTER_OFFSET 0x4

#define MCHAN_SIZE_OFFSET 0
#define MCHAN_LEN_WIDTH 16
#define MCHAN_LEN_MASK ((1<<MCHAN_LEN_WIDTH)-1)
#define MCHAN_SIZE(x) (((x) >> MCHAN_SIZE_OFFSET) & MCHAN_LEN_MASK)

#define MCHAN_TYPE_OFFSET (MCHAN_LEN_WIDTH)
#define MCHAN_TYPE(x) (((x) >> MCHAN_TYPE_OFFSET) & 1)

#define MCHAN_INCR_OFFSET (MCHAN_LEN_WIDTH + 1)
#define MCHAN_INCR(x) (((x) >> MCHAN_INCR_OFFSET) & 1)

#define MCHAN_TWD_OFFSET (MCHAN_LEN_WIDTH + 2)
#define MCHAN_TWD(x) (((x) >> MCHAN_TWD_OFFSET) & 1)

#define MCHAN_2D_STRIDE_OFFSET (16)
#define MCHAN_2D_STRIDE_WIDTH (16)
#define MCHAN_2D_STRIDE_MASK ((1<<MCHAN_2D_STRIDE_WIDTH)-1)
#define MCHAN_2D_STRIDE(x) (((x) >> MCHAN_2D_STRIDE_OFFSET) & MCHAN_2D_STRIDE_MASK)

#define MCHAN_2D_LEN_OFFSET (0)
#define MCHAN_2D_LEN_WIDTH (16)
#define MCHAN_2D_LEN_MASK ((1<<MCHAN_2D_LEN_WIDTH)-1)
#define MCHAN_2D_LEN(x) (((x) >> MCHAN_2D_LEN_OFFSET) & MCHAN_2D_LEN_MASK)

// Direction of the transfer
#define MCHAN_LOC_TO_EXT_MODE 0x0      // From inside the cluster to outside (e.g. L1 to L2)
#define MCHAN_EXT_TO_LOC_MODE 0x1      // From outside the cluster to inside the cluster (e.g. L2 to L1)
#define MCHAN_TX_MODE 0x0
#define MCHAN_RX_MODE 0x1

// Address increment
#define MCHAN_FIX_MODE 0x0     // No increment, the access address is always the same, useful for streaming devices
#define MCHAN_INC_MODE 0x1     // Classic address increment

// 1D or 2D transfer
#define MCHAN_LIN_MODE 0x0   // Classic linear (1D) mode
#define MCHAN_TWD_MODE 0x1   // 2D mode, for block transfer

#define MCHAN_NB_COUNTERS 4














// Register map

#define PLP_DMA_QUEUE_OFFSET   0x0
#define PLP_DMA_STATUS_OFFSET  0x4

// Command bitfield

#define PLP_DMA_SIZE_BIT    0
#define PLP_DMA_SIZE_WIDTH  16
#define PLP_DMA_TYPE_BIT   (PLP_DMA_SIZE_WIDTH)
#define PLP_DMA_INCR_BIT   (PLP_DMA_SIZE_WIDTH + 1)
#define PLP_DMA_2D_BIT     (PLP_DMA_SIZE_WIDTH + 2)

#define PLP_DMA_LOC2EXT 0
#define PLP_DMA_EXT2LOC 1

#define PLP_DMA_1D 0
#define PLP_DMA_2D 1

#define PLP_DMA_FIX         0
#define PLP_DMA_INC         1

// Stride bitfield

#define PLP_DMA_2D_STRIDE_BIT    16
#define PLP_DMA_2D_STRIDE_WIDTH  16

#define PLP_DMA_2D_LEN_BIT       0
#define PLP_DMA_2D_LEN_WIDTH     16

// Macros
#define PLP_DMA_SIZE_GET(x)    (((x) >> PLP_DMA_SIZE_BIT) & ((1<<PLP_DMA_SIZE_WIDTH)-1))
#define PLP_DMA_TYPE_GET(x)    (((x) >> PLP_DMA_TYPE_BIT) & 1)
#define PLP_DMA_INCR_GET(x)    (((x) >> PLP_DMA_INCR_BIT) & 1)
#define PLP_DMA_2D_GET(x)      (((x) >> PLP_DMA_2D_BIT)   & 1)

#define PLP_DMA_2D_STRIDE_GET(x)   (((x) >> PLP_DMA_2D_STRIDE_BIT) & ((1<<PLP_DMA_2D_STRIDE_WIDTH)-1))
#define PLP_DMA_2D_LEN_GET(x) (((x) >> PLP_DMA_2D_LEN_BIT) & ((1<<PLP_DMA_2D_LEN_WIDTH)-1))





#endif
