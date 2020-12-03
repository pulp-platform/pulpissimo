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

#ifndef __HAL_DMA_MCHAN_V4H__
#define __HAL_DMA_MCHAN_V4H__

#include <archi/dma/mchan_v3.h>

#define TCDM_ADDR_REG      ( MCHAN_BASE_ADDR + TCDM_ADDR_REG_OFFSET )
#define EXT_ADDR_REG       ( MCHAN_BASE_ADDR + EXT_ADDR_REG_OFFSET )
#define CMD_QUEUE          ( MCHAN_BASE_ADDR + CMD_QUEUE_OFFSET )
#define CMD_QUEUE_BUSY_REG ( MCHAN_BASE_ADDR + CMD_QUEUE_BUSY_REG_OFFSET )

#define set_ext_addr(addr)		        \
  *(volatile int*)EXT_ADDR_REG = addr;

#define set_tcdm_addr(addr)			\
  *(volatile int*)TCDM_ADDR_REG = addr;

#define push_cmd(cmd)				\
  *(volatile int*)CMD_QUEUE = cmd;

#define dma_barrier()				\
    while(*(volatile int*)CMD_QUEUE_BUSY_REG); 

#endif
