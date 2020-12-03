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

#ifndef __HAL_DMA_MCHAN_V5_H__
#define __HAL_DMA_MCHAN_V5_H__

#include "archi/dma/mchan_v5.h"
#include "hal/eu/eu_v1.h"

#include "hal/pulp.h"

#define MCHAN_COMMAND_QUEUE (ARCHI_MCHAN_ADDR + MCHAN_COMMAND_QUEUE_OFFSET)
#define MCHAN_STATUS_REGISTER (ARCHI_MCHAN_ADDR + MCHAN_STATUS_REGISTER_OFFSET)

static inline int mchan_transfer(unsigned int len, char type, char incr, char twd, unsigned int ext_addr, unsigned int tcdm_addr, unsigned short int count, unsigned short int stride){
  
  int id = *(volatile int*) MCHAN_COMMAND_QUEUE;
  
  *(volatile int*) MCHAN_COMMAND_QUEUE = (1<<19) | len | (type << MCHAN_LEN_WIDTH) | ( incr <<  (MCHAN_LEN_WIDTH + 1) ) | ( twd <<  (MCHAN_LEN_WIDTH + 2) );
  *(volatile int*) MCHAN_COMMAND_QUEUE = tcdm_addr;
  *(volatile int*) MCHAN_COMMAND_QUEUE = ext_addr;
  
  if (twd == 1)
    *(volatile int*) MCHAN_COMMAND_QUEUE = count | (stride << 16);
  
  return id;
  
}

static inline void mchan_barrier(int id) {
  while(((*(volatile int*)(MCHAN_STATUS_REGISTER)) >> id ) & 0x1 ) {
    eu_evt_maskWaitAndClr(1<<8);
  }
}







// FOR OPENVX

static inline unsigned int pulp_dma_base() {
  return ARCHI_MCHAN_ADDR;
}

static inline unsigned int pulp_dmaext_base() {
  return ARCHI_MCHAN_ADDR;
}

static inline void pulp_dma_cmd_push(unsigned int dmaBase, unsigned int locAddr, unsigned int extAddr, unsigned int cmd) {
  pulp_write32(dmaBase + MCHAN_COMMAND_QUEUE_OFFSET, cmd);
  pulp_write32(dmaBase + MCHAN_COMMAND_QUEUE_OFFSET, locAddr);
  pulp_write32(dmaBase + MCHAN_COMMAND_QUEUE_OFFSET, extAddr);
}

static inline void pulp_dma_memcpy_fromId(unsigned int dmaBase, unsigned int ext, unsigned int loc, int loc2ext, unsigned int size, unsigned int counter) {
  pulp_write32(dmaBase + MCHAN_COMMAND_QUEUE_OFFSET, ((!loc2ext) << MCHAN_TYPE_OFFSET) | (MCHAN_INC_MODE << MCHAN_INCR_OFFSET) | (MCHAN_LIN_MODE << MCHAN_TWD_OFFSET) | (size << MCHAN_SIZE_OFFSET));
  pulp_write32(dmaBase + MCHAN_COMMAND_QUEUE_OFFSET, loc);
  pulp_write32(dmaBase + MCHAN_COMMAND_QUEUE_OFFSET, ext);
}

static inline unsigned int pulp_dma_memcpy(unsigned int dmaBase, unsigned int ext, unsigned int loc, int loc2ext, unsigned int size) {
  unsigned int counter = pulp_read32(dmaBase + MCHAN_COMMAND_QUEUE_OFFSET);
  pulp_dma_memcpy_fromId(dmaBase, ext, loc, loc2ext, size, counter);
  return counter;
}

static inline unsigned int pulp_dma_memcpy_2d(unsigned int dmaBase, unsigned int ext, unsigned int loc, int loc2ext, unsigned int size, unsigned int stride, unsigned int length) {
  unsigned int counter = pulp_read32(dmaBase + MCHAN_COMMAND_QUEUE_OFFSET);
  pulp_write32(dmaBase + MCHAN_COMMAND_QUEUE_OFFSET, ((!loc2ext) << MCHAN_TYPE_OFFSET) | (MCHAN_INC_MODE << MCHAN_INCR_OFFSET) | (MCHAN_TWD_MODE << MCHAN_TWD_OFFSET) | (size << MCHAN_SIZE_OFFSET));
  pulp_write32(dmaBase + MCHAN_COMMAND_QUEUE_OFFSET, loc);
  pulp_write32(dmaBase + MCHAN_COMMAND_QUEUE_OFFSET, ext);
  pulp_write32(dmaBase + MCHAN_COMMAND_QUEUE_OFFSET, (stride << MCHAN_2D_STRIDE_OFFSET) | (length << MCHAN_2D_LEN_OFFSET));
  return counter;
}

static inline void pulp_dma_barrier() {
  unsigned int addr = ARCHI_MCHAN_ADDR + MCHAN_STATUS_REGISTER_OFFSET;
  while(pulp_read32(addr)) {
    eu_evt_maskWaitAndClr(1<<ARCHI_EVT_DMA);
  }
}

static inline unsigned int pulp_dma_counter(unsigned int dmaBase, unsigned int counter) {
  return pulp_read32(dmaBase + MCHAN_STATUS_REGISTER_OFFSET) & (1 << counter);
}

static inline void pulp_dma_wait_event(unsigned int dmaBase, unsigned int counter, unsigned int event) {
  unsigned int addr = dmaBase + MCHAN_STATUS_REGISTER_OFFSET;
  while(pulp_read32(addr) & (1 << counter)) {
    eu_evt_maskWaitAndClr(1<<event);
  }
}

static inline void pulp_dma_wait(unsigned int dmaBase, unsigned int counter) {
  pulp_dma_wait_event(dmaBase, counter, ARCHI_EVT_DMA);
}

static inline unsigned int pulp_dma_status(unsigned int dmaBase) {
  return pulp_read32(dmaBase + MCHAN_STATUS_REGISTER_OFFSET);
}

static inline void pulp_dmaext_wait(unsigned int dmaBase, unsigned int counter) {
  pulp_dma_wait_event(dmaBase, counter, ARCHI_EVT_DMA);
}

static inline void pulp_dma_freeCounter(unsigned int dmaBase, unsigned int counter) {
}







#define DMA_WRITE(value, offset) pulp_write32(ARCHI_MCHAN_ADDR + (offset), (value))
#define DMA_READ(offset) pulp_read32(ARCHI_MCHAN_ADDR + (offset))

static inline int plp_dma_counter_alloc() {
  return DMA_READ(PLP_DMA_QUEUE_OFFSET);
}

static inline unsigned int plp_dma_getCmd(int ext2loc, unsigned int size, int is2D) {
  return (ext2loc << PLP_DMA_TYPE_BIT) | (PLP_DMA_INC << PLP_DMA_INCR_BIT) | (is2D << PLP_DMA_2D_BIT) | (size << PLP_DMA_SIZE_BIT);
}

static inline unsigned int plp_dma_getStrides(unsigned short stride, unsigned short len) {
  return (stride << PLP_DMA_2D_STRIDE_BIT) | (len << PLP_DMA_2D_LEN_BIT);
}

static inline void plp_dma_cmd_push(unsigned int cmd, unsigned int locAddr, unsigned int extAddr) {
  DMA_WRITE(cmd, PLP_DMA_QUEUE_OFFSET);
  DMA_WRITE(locAddr, PLP_DMA_QUEUE_OFFSET);
  DMA_WRITE(extAddr, PLP_DMA_QUEUE_OFFSET);
}

static inline void plp_dma_cmd_push_2d(unsigned int cmd, unsigned int locAddr, unsigned int extAddr, unsigned strides) {
  plp_dma_cmd_push(cmd, locAddr, extAddr);
  DMA_WRITE(strides, PLP_DMA_QUEUE_OFFSET);
}

static inline int plp_dma_memcpy(unsigned int ext, unsigned int loc, unsigned short size, int ext2loc) {
  unsigned int counter = plp_dma_counter_alloc();
  unsigned int cmd = plp_dma_getCmd(ext2loc, size, PLP_DMA_1D);
  plp_dma_cmd_push(cmd, loc, ext);
  return counter;
}

static inline int plp_dma_l1ToExt(unsigned int ext, unsigned int loc, unsigned short size) {
  unsigned int counter = plp_dma_counter_alloc();
  unsigned int cmd = plp_dma_getCmd(PLP_DMA_LOC2EXT, size, PLP_DMA_1D);
  plp_dma_cmd_push(cmd, loc, ext);
  return counter;
}

static inline int plp_dma_extToL1(unsigned int loc, unsigned int ext, unsigned short size) {
  unsigned int counter = plp_dma_counter_alloc();
  unsigned int cmd = plp_dma_getCmd(PLP_DMA_EXT2LOC, size, PLP_DMA_1D);
  plp_dma_cmd_push(cmd, loc, ext);
  return counter;
}

static inline int plp_dma_memcpy_irq(unsigned int ext, unsigned int loc, unsigned short size, int ext2loc) {
  return plp_dma_memcpy(ext, loc, size, ext2loc);
}

static inline int plp_dma_memcpy_2d(unsigned int ext, unsigned int loc, unsigned short size, unsigned short stride, unsigned short length, int ext2loc) {
  unsigned int counter = plp_dma_counter_alloc();
  unsigned int cmd = plp_dma_getCmd(ext2loc, size, PLP_DMA_2D);
  plp_dma_cmd_push_2d(cmd, loc, ext, plp_dma_getStrides(stride, length));
  return counter;
}

static inline int plp_dma_l1ToExt_2d(unsigned int ext, unsigned int loc, unsigned short size, unsigned short stride, unsigned short length) {
  unsigned int counter = plp_dma_counter_alloc();
  unsigned int cmd = plp_dma_getCmd(PLP_DMA_LOC2EXT, size, PLP_DMA_2D);
  plp_dma_cmd_push_2d(cmd, loc, ext, plp_dma_getStrides(stride, length));
  return counter;
}

static inline int plp_dma_extToL1_2d(unsigned int loc, unsigned int ext, unsigned short size, unsigned short stride, unsigned short length) {
  unsigned int counter = plp_dma_counter_alloc();
  unsigned int cmd = plp_dma_getCmd(PLP_DMA_EXT2LOC, size, PLP_DMA_2D);
  plp_dma_cmd_push_2d(cmd, loc, ext, plp_dma_getStrides(stride, length));
  return counter;
}

static inline void plp_dma_barrier() {
  while(DMA_READ(PLP_DMA_STATUS_OFFSET)) {
    eu_evt_maskWaitAndClr(1<<ARCHI_EVT_DMA);
  }
  DMA_WRITE(PLP_DMA_STATUS_OFFSET, -1);
}

static inline void plp_dma_wait(unsigned int counter) {
  while(DMA_READ(PLP_DMA_STATUS_OFFSET) & (1 << counter)) {
    eu_evt_maskWaitAndClr(1<<ARCHI_EVT_DMA);
  }
}

static inline unsigned int plp_dma_status() {
  return DMA_READ(PLP_DMA_STATUS_OFFSET);
}



#endif
