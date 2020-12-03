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

#ifndef __HAL_MCHAN_V7_H__
#define __HAL_MCHAN_V7_H__

#include <archi/dma/mchan_v7.h>
#include "hal/pulp.h"

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

#if defined(ARCHI_HAS_MCHAN_64) && ARCHI_HAS_MCHAN_64 == 1
typedef unsigned long long mchan_ext_t;
#else
typedef unsigned int mchan_ext_t;
#endif

/** @name High-level DMA memory copy functions
 * The following functions can be used to trigger DMA transfers to copy data between the cluster memory (L1) and another memory outside the cluster (another cluster L1 or L2).
 * Note that they cannot be used from L2 to L2 or from a cluster memory to the same cluster memory. The DMA supports the following features:
 *   - Transfers can be either event-based or irq-based. With event-based transfers the core can call a wait function to block execution until the transfer is done. With irq-based transfers, the completion of the transfer will trigger the DMA interrupt. This interrupt cannot be managed with this HAL, but must be managed as any other IRQ.
 *   - The DMA supports 2D transfers which allows transfering a 2D tile in one command. Additional information must then be given to specify the width of the tile and the number of bytes between 2 lines of the tile.
 *   - The event or irq sent at the end of the transfer can be either sent to the core which enqueued the transfer or broadcasted to all cluster cores.
 *   - To identify specific transfers, the DMA provides a counter allocator. All transfers enqueued with the same counter are gathered into a group, on which the core can be stalled until the whole group of transfers is finished.
 *   - All transfers are enqueued into a global FIFO which can stall the core enqueueing the transfer in case it is full. The size of the FIFO depends on the chip but is typically 16 commands.
 */
/**@{*/

/** Memory transfer with event-based completion. 
 * 
  \param   ext     Address in the external memory where to access the data. There is no restriction on memory alignment.
  \param   loc     Address in the cluster memory where to access the data. There is no restriction on memory alignment.
  \param   size    Number of bytes to be transfered. The only restriction is that this size must fit 16 bits, i.e. must be inferior to 65536.
  \param   ext2loc If 1, the transfer is loading data from external memory and storing to cluster memory. If 0, it is the contrary
  \return       The identifier of the transfer. This can be used with plp_dma_wait to wait for the completion of this transfer.
  */
static inline int plp_dma_memcpy(mchan_ext_t ext, unsigned int loc, unsigned short size, int ext2loc);

/** Cluster memory to external memory transfer with event-based completion. 
 * 
  \param   ext  Address in the external memory where to store the data. There is no restriction on memory alignment.
  \param   loc  Address in the cluster memory where to load the data. There is no restriction on memory alignment.
  \param   size Number of bytes to be transfered. The only restriction is that this size must fit 16 bits, i.e. must be inferior to 65536.
  \return       The identifier of the transfer. This can be used with plp_dma_wait to wait for the completion of this transfer.
  */
static inline int plp_dma_l1ToExt(mchan_ext_t ext, unsigned int loc, unsigned short size);

/** External memory to cluster memory transfer with event-based completion. 
 * 
  \param   loc  Address in the cluster memory where to store the data. There is no restriction on memory alignment.
  \param   ext  Address in the external memory where to load the data. There is no restriction on memory alignment.
  \param   size Number of bytes to be transfered. The only restriction is that this size must fit 16 bits, i.e. must be inferior to 65536.
  \return       The identifier of the transfer. This can be used with plp_dma_wait to wait for the completion of this transfer.
  */
static inline int plp_dma_extToL1(unsigned int loc, mchan_ext_t ext, unsigned short size);

/** Memory transfer with irq-based completion. 
 * 
  \param   ext     Address in the external memory where to access the data. There is no restriction on memory alignment.
  \param   loc     Address in the cluster memory where to access the data. There is no restriction on memory alignment.
  \param   size    Number of bytes to be transfered. The only restriction is that this size must fit 16 bits, i.e. must be inferior to 65536.
  \param   ext2loc If 1, the transfer is loading data from external memory and storing to cluster memory. If 0, it is the contrary
  \return       The identifier of the transfer. This can be used with plp_dma_wait to wait for the completion of this transfer.
  */
static inline int plp_dma_memcpy_irq(mchan_ext_t ext, unsigned int loc, unsigned short size, int ext2loc);

/** Cluster memory to external memory transfer with irq-based completion. 
 * 
  \param   ext  Address in the external memory where to store the data. There is no restriction on memory alignment.
  \param   loc  Address in the cluster memory where to load the data. There is no restriction on memory alignment.
  \param   size Number of bytes to be transfered. The only restriction is that this size must fit 16 bits, i.e. must be inferior to 65536.
  \return       The identifier of the transfer. This can be used with plp_dma_wait to wait for the completion of this transfer.
  */
static inline int plp_dma_l1ToExt_irq(mchan_ext_t ext, unsigned int loc, unsigned short size);

/** External memory to cluster memory transfer with irq-based completion. 
 * 
  \param   loc  Address in the cluster memory where to store the data. There is no restriction on memory alignment.
  \param   ext  Address in the external memory where to load the data. There is no restriction on memory alignment.
  \param   size Number of bytes to be transfered. The only restriction is that this size must fit 16 bits, i.e. must be inferior to 65536.
  \return       The identifier of the transfer. This can be used with plp_dma_wait to wait for the completion of this transfer.
  */
static inline int plp_dma_extToL1_irq(unsigned int loc, mchan_ext_t ext, unsigned short size);

/** 2-dimensional memory transfer with event-based completion. 
 * 
  \param   ext    Address in the external memory where to access the data. There is no restriction on memory alignment.
  \param   loc    Address in the cluster memory where to access the data. There is no restriction on memory alignment.
  \param   size   Number of bytes to be transfered. The only restriction is that this size must fit 16 bits, i.e. must be inferior to 65536.
  \param   stride 2D stride, which is the number of bytes which are added to the beginning of the current line to switch to the next one. Must fit 16 bits, i.e. must be inferior to 65536.
  \param   length 2D length, which is the number of transfered bytes after which the DMA will switch to the next line. Must fit 16 bits, i.e. must be inferior to 65536.
  \param   ext2loc If 1, the transfer is loading data from external memory and storing to cluster memory. If 0, it is the contrary
  \return         The identifier of the transfer. This can be used with plp_dma_wait to wait for the completion of this transfer.
  */
static inline int plp_dma_memcpy_2d(mchan_ext_t ext, unsigned int loc, unsigned short size, unsigned short stride, unsigned short length, int ext2loc);

/** Cluster memory to external memory 2-dimensional transfer with event-based completion. 
 * 
  \param   ext    Address in the external memory where to store the data. There is no restriction on memory alignment.
  \param   loc    Address in the cluster memory where to load the data. There is no restriction on memory alignment.
  \param   size   Number of bytes to be transfered. The only restriction is that this size must fit 16 bits, i.e. must be inferior to 65536.
  \param   stride 2D stride, which is the number of bytes which are added to the beginning of the current line to switch to the next one. Must fit 16 bits, i.e. must be inferior to 65536. This applies only to the external memory.
  \param   length 2D length, which is the number of transfered bytes after which the DMA will switch to the next line. Must fit 16 bits, i.e. must be inferior to 65536. This applies only to the external memory.
  \return         The identifier of the transfer. This can be used with plp_dma_wait to wait for the completion of this transfer.
  */
static inline int plp_dma_l1ToExt_2d(mchan_ext_t ext, unsigned int loc, unsigned short size, unsigned short stride, unsigned short length);

/** External memory to cluster memory 2-dimensional transfer with event-based completion. 
 * 
  \param   loc    Address in the cluster memory where to store the data. There is no restriction on memory alignment.
  \param   ext    Address in the external memory where to load the data. There is no restriction on memory alignment.
  \param   size   Number of bytes to be transfered. The only restriction is that this size must fit 16 bits, i.e. must be inferior to 65536.
  \param   stride 2D stride, which is the number of bytes which are added to the beginning of the current line to switch to the next one. Must fit 16 bits, i.e. must be inferior to 65536. This applies only to the external memory.
  \param   length 2D length, which is the number of transfered bytes after which the DMA will switch to the next line. Must fit 16 bits, i.e. must be inferior to 65536. This applies only to the external memory.
  \return         The identifier of the transfer. This can be used with plp_dma_wait to wait for the completion of this transfer
  */
static inline int plp_dma_extToL1_2d(unsigned int loc, mchan_ext_t ext, unsigned short size, unsigned short stride, unsigned short length);

/** 2-dimensional memory transfer with irq-based completion. 
 * 
  \param   ext    Address in the external memory where to access the data. There is no restriction on memory alignment.
  \param   loc    Address in the cluster memory where to access the data. There is no restriction on memory alignment.
  \param   size   Number of bytes to be transfered. The only restriction is that this size must fit 16 bits, i.e. must be inferior to 65536.
  \param   stride 2D stride, which is the number of bytes which are added to the beginning of the current line to switch to the next one. Must fit 16 bits, i.e. must be inferior to 65536. This applies only to the external memory.
  \param   length 2D length, which is the number of transfered bytes after which the DMA will switch to the next line. Must fit 16 bits, i.e. must be inferior to 65536. This applies only to the external memory.
  \param   ext2loc If 1, the transfer is loading data from external memory and storing to cluster memory. If 0, it is the contrary
  \return         The identifier of the transfer. This can be used with plp_dma_wait to wait for the completion of this transfer.
  */
static inline int plp_dma_memcpy_2d_irq(mchan_ext_t ext, unsigned int loc, unsigned short size, unsigned short stride, unsigned short length, int ext2loc);

/** Cluster memory to external memory 2-dimensional transfer with irq-based completion. 
 * 
  \param   ext    Address in the external memory where to store the data. There is no restriction on memory alignment.
  \param   loc    Address in the cluster memory where to load the data. There is no restriction on memory alignment.
  \param   size   Number of bytes to be transfered. The only restriction is that this size must fit 16 bits, i.e. must be inferior to 65536.
  \param   stride 2D stride, which is the number of bytes which are added to the beginning of the current line to switch to the next one. Must fit 16 bits, i.e. must be inferior to 65536. This applies only to the external memory.
  \param   length 2D length, which is the number of transfered bytes after which the DMA will switch to the next line. Must fit 16 bits, i.e. must be inferior to 65536. This applies only to the external memory.
  \return         The identifier of the transfer. This can be used with plp_dma_wait to wait for the completion of this transfer.
  */
static inline int plp_dma_l1ToExt_2d_irq(mchan_ext_t ext, unsigned int loc, unsigned short size, unsigned short stride, unsigned short length);

/** External memory to cluster memory 2-dimensional transfer with irq-based completion. 
 * 
  \param   loc    Address in the cluster memory where to store the data. There is no restriction on memory alignment.
  \param   ext    Address in the external memory where to load the data. There is no restriction on memory alignment.
  \param   size   Number of bytes to be transfered. The only restriction is that this size must fit 16 bits, i.e. must be inferior to 65536.
  \param   stride 2D stride, which is the number of bytes which are added to the beginning of the current line to switch to the next one. Must fit 16 bits, i.e. must be inferior to 65536. This applies only to the external memory.
  \param   length 2D length, which is the number of transfered bytes after which the DMA will switch to the next line. Must fit 16 bits, i.e. must be inferior to 65536. This applies only to the external memory.
  \return         The identifier of the transfer. This can be used with plp_dma_wait to wait for the completion of this transfer
  */
static inline int plp_dma_extToL1_2d_irq(unsigned int loc, mchan_ext_t ext, unsigned short size, unsigned short stride, unsigned short length);

//!@}

/** @name DMA wait functions
 */

/** DMA barrier.
 * This blocks the core until no transfer is on-going in the DMA. 
 */
static inline void plp_dma_barrier();

/** DMA wait.
  * This blocks the core until the specified transfer is finished. 
  *
  \param   counter  The counter ID identifying the transfer. This has either been allocated explicitly or returned from an enqueued transfer (e.g. plp_dma_extToL1_2d_irq)
 */
static inline void plp_dma_wait(unsigned int counter);

//!@}


/** @name DMA low-level functions.
  * This can be used instead of the high-level ones in order to have more control over the DMA features. 
 */

/** DMA counter allocation. 
 * This allocates a counter and activate it for all the next transfers until another one is allocated. This means during this period, all transfers will be accounted on this counter and thus waiting
 * on this counter will wait for all these transfers.
 * 
  \return         The identifier of the transfer. This can be used with plp_dma_wait to wait for the completion of this transfer.
  */
static inline int plp_dma_counter_alloc();

/** DMA counter release.
 * This makes the counter available for another transfer through the DMA counter allocator 
 * 
  \param   counter    The counter number to be released
  */
static inline void plp_dma_counter_free(int counter);

/** DMA command generation. 
 * Can be used to generate the 32 bits command to be pushed to the DMA, depending on the required mode.
 * 
  \param   ext2loc    If 1, the data is loaded from external memory, and stored to the cluster memory, otherwise it is the contrary
  \param   size       Size in bytes of the transfer. In case it is a 2D transfer, this is the total number of bytes to be transfered, whatever the stride. Must fit 16 bits, i.e. must be inferior to 65536.
  \param   is2D       If 1, the transfer is a 2-dimensional transfer (tile) otherwise it is a classic one.
  \param   trigEvt    If 1, an event is sent to 1 or all cores at the end of the transfer.
  \param   trigIrq    If 1, an interrupt is sent to 1 or all cores at the end of the transfer.
  \param   broadcast  If 1 the event or irq generated when the transfer is finished is sent to all cores, otherwise it is only sent to the core enqueueing the transfer.
  \return             The generated command.
  */
static inline unsigned int plp_dma_getCmd(int ext2loc, unsigned int size, int is2D, int trigEvt, int trigIrq, int broadcast);

/** Generate the stride command for 2D transfers. 
 * 
  \param   stride    The stride of the 2D transfer, i.e. the number of bytes between the beginning of 2 lines of the tile. Must fit 16 bits, i.e. must be inferior to 65536.
  \param   len       The length of the 2D transfer, i.e. the number of bytes transfered after which the DMA should switch to the new line. Must fit 16 bits, i.e. must be inferior to 65536.
  \return            The generated command.
  */
static inline unsigned int plp_dma_getStrides(unsigned short stride, unsigned short len);

/** Push a transfer to the DMA
 * 
  \param      locAddr    The address of the transfer for the cluster memory
  \param      extAddr    The address of the transfer for the external memory
  \param      cmd        The command that specifies the type of the transfer. This can be generated using plp_dma_getCmd.
  */
static inline void plp_dma_cmd_push(unsigned int cmd, unsigned int locAddr, mchan_ext_t extAddr);

/** Push a 2D transfer to the DMA
 * 
  \param      locAddr    The address of the transfer for the cluster memory
  \param      extAddr    The address of the transfer for the external memory
  \param      cmd        The command that specifies the type of the transfer. This can be generated using plp_dma_getStrides.
  \param      strides    The command that specifies the 2D transfer (stride and len). This can be generated using plp_dma_getStrides.
  */
static inline void plp_dma_cmd_push_2d(unsigned int cmd, unsigned int locAddr, mchan_ext_t extAddr, unsigned int stride, unsigned int length);

/** Return the counter status.
 * 
  \return             Counter status. There is one bit per counter. 1 means there are still on-going transfers for this counter, 0 means nothing is on-going.
  */  
static inline unsigned int plp_dma_status();

//!@}

/// @cond IMPLEM

#if defined(__riscv__) && !defined(RV_ISA_RV32) && !defined(__LLVM__)
#define DMA_WRITE(value, offset) __builtin_pulp_OffsetedWrite((value), (int *)ARCHI_MCHAN_EXT_ADDR, (offset))
#define DMA_READ(offset) __builtin_pulp_OffsetedRead((int *)ARCHI_MCHAN_EXT_ADDR, (offset))
#else
#define DMA_WRITE(value, offset) pulp_write32(ARCHI_MCHAN_EXT_ADDR + (offset), (value))
#define DMA_READ(offset) pulp_read32(ARCHI_MCHAN_EXT_ADDR + (offset))
#endif

static inline int plp_dma_counter_alloc() {
  return DMA_READ(MCHAN_CMD_OFFSET);
}

static inline void plp_dma_counter_free(int counter) {
  DMA_WRITE(1<<counter, MCHAN_STATUS_OFFSET);
}

static inline unsigned int plp_dma_getCmd(int ext2loc, unsigned int size, int is2D, int trigEvt, int trigIrq, int broadcast) {
#if defined(__riscv__)
  unsigned int res;
  res = __builtin_bitinsert(0,  ext2loc,      1, MCHAN_CMD_CMD_TYPE_BIT);
  res = __builtin_bitinsert(res, PLP_DMA_INC, 1, MCHAN_CMD_CMD_INC_BIT);
  res = __builtin_bitinsert(res, is2D,        1, MCHAN_CMD_CMD__2D_EXT_BIT);
  res = __builtin_bitinsert(res, size,        MCHAN_CMD_CMD_LEN_WIDTH, MCHAN_CMD_CMD_LEN_BIT);
  res = __builtin_bitinsert(res, trigEvt,     1, MCHAN_CMD_CMD_ELE_BIT);
  res = __builtin_bitinsert(res, trigIrq,     1, MCHAN_CMD_CMD_ILE_BIT);
  res = __builtin_bitinsert(res, broadcast,   1, MCHAN_CMD_CMD_BLE_BIT);
  return res;
#else
  return (ext2loc << MCHAN_CMD_CMD_TYPE_BIT) | (PLP_DMA_INC << MCHAN_CMD_CMD_INC_BIT) | (is2D << MCHAN_CMD_CMD__2D_EXT_BIT) | (size << MCHAN_CMD_CMD_LEN_BIT) | (trigEvt<<MCHAN_CMD_ELE_BIT) | (trigIrq<<MCHAN_CMD_ILE_BIT) | (broadcast<<MCHAN_CMD_CMD_BLE_BIT);
#endif
}


static inline void plp_dma_cmd_push(unsigned int cmd, unsigned int locAddr, mchan_ext_t extAddr) {
  DMA_WRITE(cmd, MCHAN_CMD_OFFSET);
  DMA_WRITE(locAddr, MCHAN_CMD_OFFSET);
#if defined(ARCHI_HAS_MCHAN_64) && ARCHI_HAS_MCHAN_64 == 1
  DMA_WRITE((int)extAddr, MCHAN_CMD_OFFSET);
  DMA_WRITE((int)(extAddr>>32), MCHAN_CMD_OFFSET);
#else
  DMA_WRITE(extAddr, MCHAN_CMD_OFFSET);
#endif
}

static inline void plp_dma_cmd_push_2d(unsigned int cmd, unsigned int locAddr, mchan_ext_t extAddr, unsigned int stride, unsigned int length) {
  plp_dma_cmd_push(cmd, locAddr, extAddr);
  DMA_WRITE(length, MCHAN_CMD_OFFSET);
  DMA_WRITE(stride, MCHAN_CMD_OFFSET);
}

static inline int plp_dma_memcpy(mchan_ext_t ext, unsigned int loc, unsigned short size, int ext2loc) {
  unsigned int counter = plp_dma_counter_alloc();
  unsigned int cmd = plp_dma_getCmd(ext2loc, size, PLP_DMA_1D, PLP_DMA_TRIG_EVT, PLP_DMA_NO_TRIG_IRQ, PLP_DMA_SHARED);
  plp_dma_cmd_push(cmd, loc, ext);
  return counter;
}

static inline int plp_dma_l1ToExt(mchan_ext_t ext, unsigned int loc, unsigned short size) {
  unsigned int counter = plp_dma_counter_alloc();
  unsigned int cmd = plp_dma_getCmd(PLP_DMA_LOC2EXT, size, PLP_DMA_1D, PLP_DMA_TRIG_EVT, PLP_DMA_NO_TRIG_IRQ, PLP_DMA_SHARED);
  plp_dma_cmd_push(cmd, loc, ext);
  return counter;
}

static inline int plp_dma_extToL1(unsigned int loc, mchan_ext_t ext, unsigned short size) {
  unsigned int counter = plp_dma_counter_alloc();
  unsigned int cmd = plp_dma_getCmd(PLP_DMA_EXT2LOC, size, PLP_DMA_1D, PLP_DMA_TRIG_EVT, PLP_DMA_NO_TRIG_IRQ, PLP_DMA_SHARED);
  plp_dma_cmd_push(cmd, loc, ext);
  return counter;
}

static inline int plp_dma_memcpy_irq(mchan_ext_t ext, unsigned int loc, unsigned short size, int ext2loc) {
  unsigned int counter = plp_dma_counter_alloc();
  unsigned int cmd = plp_dma_getCmd(ext2loc, size, PLP_DMA_1D, PLP_DMA_NO_TRIG_EVT, PLP_DMA_TRIG_IRQ, PLP_DMA_SHARED);
  plp_dma_cmd_push(cmd, loc, ext);
  return counter;
}

static inline int plp_dma_l1ToExt_irq(mchan_ext_t ext, unsigned int loc, unsigned short size) {
  unsigned int counter = plp_dma_counter_alloc();
  unsigned int cmd = plp_dma_getCmd(PLP_DMA_LOC2EXT, size, PLP_DMA_1D, PLP_DMA_NO_TRIG_EVT, PLP_DMA_TRIG_IRQ, PLP_DMA_SHARED);
  plp_dma_cmd_push(cmd, loc, ext);
  return counter;
}

static inline int plp_dma_extToL1_irq(unsigned int loc, mchan_ext_t ext, unsigned short size) {
  unsigned int counter = plp_dma_counter_alloc();
  unsigned int cmd = plp_dma_getCmd(PLP_DMA_EXT2LOC, size, PLP_DMA_1D, PLP_DMA_NO_TRIG_EVT, PLP_DMA_TRIG_IRQ, PLP_DMA_SHARED);
  plp_dma_cmd_push(cmd, loc, ext);
  return counter;
}

static inline void plp_dma_memcpy_2d_keepCounter(mchan_ext_t ext, unsigned int loc, unsigned short size, unsigned short stride, unsigned short length, int ext2loc) {
  unsigned int cmd = plp_dma_getCmd(ext2loc, size, PLP_DMA_2D, PLP_DMA_TRIG_EVT, PLP_DMA_NO_TRIG_IRQ, PLP_DMA_SHARED);
  plp_dma_cmd_push_2d(cmd, loc, ext, stride, length);
}

static inline int plp_dma_memcpy_2d(mchan_ext_t ext, unsigned int loc, unsigned short size, unsigned short stride, unsigned short length, int ext2loc) {
  unsigned int counter = plp_dma_counter_alloc();
  plp_dma_memcpy_2d_keepCounter(ext, loc, size, stride, length, ext2loc);
  return counter;
}

static inline int plp_dma_l1ToExt_2d(mchan_ext_t ext, unsigned int loc, unsigned short size, unsigned short stride, unsigned short length) {
  unsigned int counter = plp_dma_counter_alloc();
  unsigned int cmd = plp_dma_getCmd(PLP_DMA_LOC2EXT, size, PLP_DMA_2D, PLP_DMA_TRIG_EVT, PLP_DMA_NO_TRIG_IRQ, PLP_DMA_SHARED);
  plp_dma_cmd_push_2d(cmd, loc, ext, stride, length);
  return counter;
}

static inline int plp_dma_extToL1_2d(unsigned int loc, mchan_ext_t ext, unsigned short size, unsigned short stride, unsigned short length) {
  unsigned int counter = plp_dma_counter_alloc();
  unsigned int cmd = plp_dma_getCmd(PLP_DMA_EXT2LOC, size, PLP_DMA_2D, PLP_DMA_TRIG_EVT, PLP_DMA_NO_TRIG_IRQ, PLP_DMA_SHARED);
  plp_dma_cmd_push_2d(cmd, loc, ext, stride, length);
  return counter;
}

static inline int plp_dma_memcpy_2d_irq(mchan_ext_t ext, unsigned int loc, unsigned short size, unsigned short stride, unsigned short length, int ext2loc) {
  unsigned int counter = plp_dma_counter_alloc();
  unsigned int cmd = plp_dma_getCmd(ext2loc, size, PLP_DMA_2D, PLP_DMA_NO_TRIG_EVT, PLP_DMA_TRIG_IRQ, PLP_DMA_SHARED);
  plp_dma_cmd_push_2d(cmd, loc, ext, stride, length);
  return counter;
}

static inline int plp_dma_l1ToExt_2d_irq(mchan_ext_t ext, unsigned int loc, unsigned short size, unsigned short stride, unsigned short length) {
  unsigned int counter = plp_dma_counter_alloc();
  unsigned int cmd = plp_dma_getCmd(PLP_DMA_LOC2EXT, size, PLP_DMA_2D, PLP_DMA_NO_TRIG_EVT, PLP_DMA_TRIG_IRQ, PLP_DMA_SHARED);
  plp_dma_cmd_push_2d(cmd, loc, ext, stride, length);
  return counter;
}

static inline int plp_dma_extToL1_2d_irq(unsigned int loc, mchan_ext_t ext, unsigned short size, unsigned short stride, unsigned short length) {
  unsigned int counter = plp_dma_counter_alloc();
  unsigned int cmd = plp_dma_getCmd(PLP_DMA_EXT2LOC, size, PLP_DMA_2D, PLP_DMA_NO_TRIG_EVT, PLP_DMA_TRIG_IRQ, PLP_DMA_SHARED);
  plp_dma_cmd_push_2d(cmd, loc, ext, stride, length);
  return counter;
}

static inline void plp_dma_barrier() {
  while(DMA_READ(MCHAN_STATUS_OFFSET) & 0xFFFF) {
    eu_evt_maskWaitAndClr(1<<ARCHI_CL_EVT_DMA0);
  }
  DMA_WRITE(-1, MCHAN_STATUS_OFFSET);
}

static inline void plp_dma_wait(unsigned int counter) {
  while(DMA_READ(MCHAN_STATUS_OFFSET) & (1 << counter)) {
    eu_evt_maskWaitAndClr(1<<ARCHI_CL_EVT_DMA0);
  }
  plp_dma_counter_free(counter);
}

static inline unsigned int plp_dma_status() {
  return DMA_READ(MCHAN_STATUS_OFFSET);
}

/// @endcond

#endif
