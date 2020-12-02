
/* THIS FILE HAS BEEN GENERATED, DO NOT MODIFY IT.
 */

/*
 * Copyright (C) 2018 ETH Zurich, University of Bologna
 * and GreenWaves Technologies
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

#ifndef __INCLUDE_ARCHI_UDMA_MRAM_UDMA_MRAM_V1_H__
#define __INCLUDE_ARCHI_UDMA_MRAM_UDMA_MRAM_V1_H__

#ifndef LANGUAGE_ASSEMBLY

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS
//

// uDMA RX UART buffer base address configuration register.
#define UDMA_MRAM_RX_SADDR_OFFSET                0x0

// uDMA RX UART buffer size configuration register.
#define UDMA_MRAM_RX_SIZE_OFFSET                 0x4

// uDMA RX UART stream configuration register.
#define UDMA_MRAM_RX_CFG_OFFSET                  0x8

// uDMA TX UART buffer base address configuration register.
#define UDMA_MRAM_TX_SADDR_OFFSET                0x10

// uDMA TX UART buffer size configuration register.
#define UDMA_MRAM_TX_SIZE_OFFSET                 0x14

// uDMA TX UART stream configuration register.
#define UDMA_MRAM_TX_CFG_OFFSET                  0x18

// Destination Address register for programing.
#define UDMA_MRAM_TX_DADDR_OFFSET                0x20

// Destination Address register for reading.
#define UDMA_MRAM_RX_DADDR_OFFSET                0x24

// MRAM status for pending operation
#define UDMA_MRAM_STATUS_OFFSET                  0x28

// MRAM MODE: READ - ERASE  - PROG - TRIM_CFG
#define UDMA_MRAM_MRAM_MODE_OFFSET               0x2c

// Erase Address for word or Sector Erase
#define UDMA_MRAM_ERASE_ADDR_OFFSET              0x30

// Size of Words or Sector to erase
#define UDMA_MRAM_ERASE_SIZE_OFFSET              0x34

// Set Clock div Enable and Div factor.
#define UDMA_MRAM_CLOCK_DIV_OFFSET               0x38

//  Trigger ERASE and REF_LINE INIT.
#define UDMA_MRAM_TRIGGER_OFFSET                 0x3c

// Interrupt status register.
#define UDMA_MRAM_ISR_OFFSET                     0x40

// Interrupt enable register.
#define UDMA_MRAM_IER_OFFSET                     0x44

// Interrupt clean register.
#define UDMA_MRAM_ICR_OFFSET                     0x48



//
// REGISTERS FIELDS
//

// RX buffer base address bitfield: - Read: returns value of the buffer pointer until transfer is finished. Else returns 0. - Write: sets RX buffer base address (access: R/W)
#define UDMA_MRAM_RX_SADDR_RX_SADDR_BIT                              0
#define UDMA_MRAM_RX_SADDR_RX_SADDR_WIDTH                            16
#define UDMA_MRAM_RX_SADDR_RX_SADDR_MASK                             0xffff

// RX buffer size bitfield in bytes. (128kBytes maximum) - Read: returns remaining buffer size to transfer. - Write: sets buffer size. (access: R/W)
#define UDMA_MRAM_RX_SIZE_RX_SIZE_BIT                                0
#define UDMA_MRAM_RX_SIZE_RX_SIZE_WIDTH                              17
#define UDMA_MRAM_RX_SIZE_RX_SIZE_MASK                               0x1ffff

// RX channel continuous mode bitfield: -1'b0: disabled -1'b1: enabled At the end of the buffer transfer, the uDMA reloads the address / buffer size and starts a new transfer. (access: R/W)
#define UDMA_MRAM_RX_CFG_CONTINOUS_BIT                               0
#define UDMA_MRAM_RX_CFG_CONTINOUS_WIDTH                             1
#define UDMA_MRAM_RX_CFG_CONTINOUS_MASK                              0x1

// RX channel enable and start transfer bitfield: -1'b0: disable -1'b1: enable and start the transfer This signal is used also to queue a transfer if one is already ongoing. (access: R/W)
#define UDMA_MRAM_RX_CFG_EN_BIT                                      4
#define UDMA_MRAM_RX_CFG_EN_WIDTH                                    1
#define UDMA_MRAM_RX_CFG_EN_MASK                                     0x10

// RX transfer pending in queue status flag: -1'b0: no pending transfer in the queue -1'b1: pending transfer in the queue (access: R)
#define UDMA_MRAM_RX_CFG_PENDING_BIT                                 5
#define UDMA_MRAM_RX_CFG_PENDING_WIDTH                               1
#define UDMA_MRAM_RX_CFG_PENDING_MASK                                0x20

// RX channel clear and stop transfer: -1'b0: disable -1'b1: stop and clear the on-going transfer (access: W)
#define UDMA_MRAM_RX_CFG_CLR_BIT                                     6
#define UDMA_MRAM_RX_CFG_CLR_WIDTH                                   1
#define UDMA_MRAM_RX_CFG_CLR_MASK                                    0x40

// TX buffer base address bitfield: - Read: returns value of the buffer pointer until transfer is finished. Else returns 0. - Write: sets buffer base address (access: R/W)
#define UDMA_MRAM_TX_SADDR_TX_SADDR_BIT                              0
#define UDMA_MRAM_TX_SADDR_TX_SADDR_WIDTH                            16
#define UDMA_MRAM_TX_SADDR_TX_SADDR_MASK                             0xffff

// TX buffer size bitfield in bytes. (128kBytes maximum) - Read: returns remaining buffer size to transfer. - Write: sets buffer size. (access: R/W)
#define UDMA_MRAM_TX_SIZE_TX_SIZE_BIT                                0
#define UDMA_MRAM_TX_SIZE_TX_SIZE_WIDTH                              17
#define UDMA_MRAM_TX_SIZE_TX_SIZE_MASK                               0x1ffff

// TX channel continuous mode bitfield: -1'b0: disabled -1'b1: enabled At the end of the buffer transfer, the uDMA reloads the address / buffer size and starts a new transfer. (access: R/W)
#define UDMA_MRAM_TX_CFG_CONTINOUS_BIT                               0
#define UDMA_MRAM_TX_CFG_CONTINOUS_WIDTH                             1
#define UDMA_MRAM_TX_CFG_CONTINOUS_MASK                              0x1

// TX channel enable and start transfer bitfield: -1'b0: disabled -1'b1: enable and start the transfer This signal is used also to queue a transfer if one is already ongoing. (access: R/W)
#define UDMA_MRAM_TX_CFG_EN_BIT                                      4
#define UDMA_MRAM_TX_CFG_EN_WIDTH                                    1
#define UDMA_MRAM_TX_CFG_EN_MASK                                     0x10

// TX transfer pending in queue status flag: -1'b0: no pending transfer in the queue -1'b1: pending transfer in the queue (access: R)
#define UDMA_MRAM_TX_CFG_PENDING_BIT                                 5
#define UDMA_MRAM_TX_CFG_PENDING_WIDTH                               1
#define UDMA_MRAM_TX_CFG_PENDING_MASK                                0x20

// TX channel clear and stop transfer bitfield: -1'b0: disabled -1'b1: stop and clear the on-going transfer (access: W)
#define UDMA_MRAM_TX_CFG_CLR_BIT                                     6
#define UDMA_MRAM_TX_CFG_CLR_WIDTH                                   1
#define UDMA_MRAM_TX_CFG_CLR_MASK                                    0x40

// TX destination address (access: R/W)
#define UDMA_MRAM_TX_DADDR_TX_DST_ADDR_BIT                           0
#define UDMA_MRAM_TX_DADDR_TX_DST_ADDR_WIDTH                         19
#define UDMA_MRAM_TX_DADDR_TX_DST_ADDR_MASK                          0x7ffff

// RX destination address (access: R/W)
#define UDMA_MRAM_RX_DADDR_RX_DST_ADDR_BIT                           0
#define UDMA_MRAM_RX_DADDR_RX_DST_ADDR_WIDTH                         19
#define UDMA_MRAM_RX_DADDR_RX_DST_ADDR_MASK                          0x7ffff

// Erase pending bit: - 1'b0: not pending - 1'b1: pending (access: R)
#define UDMA_MRAM_STATUS_ERASE_PENDING_BIT                           0
#define UDMA_MRAM_STATUS_ERASE_PENDING_WIDTH                         1
#define UDMA_MRAM_STATUS_ERASE_PENDING_MASK                          0x1

// Program busy bit: - 1'b0: not busy - 1'b1: busy (access: R)
#define UDMA_MRAM_STATUS_TX_BUSY_BIT                                 1
#define UDMA_MRAM_STATUS_TX_BUSY_WIDTH                               1
#define UDMA_MRAM_STATUS_TX_BUSY_MASK                                0x2

// Read busy bit: - 1'b0: not busy - 1'b1: busy (access: R)
#define UDMA_MRAM_STATUS_RX_BUSY_BIT                                 2
#define UDMA_MRAM_STATUS_RX_BUSY_WIDTH                               1
#define UDMA_MRAM_STATUS_RX_BUSY_MASK                                0x4

// Reference line pending bit: - 1'b0: not pending - 1'b1: pending (access: R)
#define UDMA_MRAM_STATUS_REF_LINE_PENDING_BIT                        3
#define UDMA_MRAM_STATUS_REF_LINE_PENDING_WIDTH                      1
#define UDMA_MRAM_STATUS_REF_LINE_PENDING_MASK                       0x8

// nan (access: R/W)
#define UDMA_MRAM_MRAM_MODE_ECC_BYPS_BIT                             0
#define UDMA_MRAM_MRAM_MODE_ECC_BYPS_WIDTH                           1
#define UDMA_MRAM_MRAM_MODE_ECC_BYPS_MASK                            0x1

// nan (access: R/W)
#define UDMA_MRAM_MRAM_MODE_DPD_BIT                                  1
#define UDMA_MRAM_MRAM_MODE_DPD_WIDTH                                1
#define UDMA_MRAM_MRAM_MODE_DPD_MASK                                 0x2

// nan (access: R/W)
#define UDMA_MRAM_MRAM_MODE_AREF_BIT                                 2
#define UDMA_MRAM_MRAM_MODE_AREF_WIDTH                               1
#define UDMA_MRAM_MRAM_MODE_AREF_MASK                                0x4

// nan (access: R/W)
#define UDMA_MRAM_MRAM_MODE_TMEN_BIT                                 3
#define UDMA_MRAM_MRAM_MODE_TMEN_WIDTH                               1
#define UDMA_MRAM_MRAM_MODE_TMEN_MASK                                0x8

// nan (access: R/W)
#define UDMA_MRAM_MRAM_MODE_NVR_BIT                                  4
#define UDMA_MRAM_MRAM_MODE_NVR_WIDTH                                1
#define UDMA_MRAM_MRAM_MODE_NVR_MASK                                 0x10

// nan (access: R/W)
#define UDMA_MRAM_MRAM_MODE_RST_B_BIT                                5
#define UDMA_MRAM_MRAM_MODE_RST_B_WIDTH                              1
#define UDMA_MRAM_MRAM_MODE_RST_B_MASK                               0x20

// nan (access: R/W)
#define UDMA_MRAM_MRAM_MODE_RET_B_BIT                                6
#define UDMA_MRAM_MRAM_MODE_RET_B_WIDTH                              1
#define UDMA_MRAM_MRAM_MODE_RET_B_MASK                               0x40

// nan (access: R/W)
#define UDMA_MRAM_MRAM_MODE_POR_B_BIT                                7
#define UDMA_MRAM_MRAM_MODE_POR_B_WIDTH                              1
#define UDMA_MRAM_MRAM_MODE_POR_B_MASK                               0x80

// MRAM command: - 8’h1: TRIM_CFG - 8’h2: NORMAL_TX - 8’h4: ERASE_CHIP - 8’h8: ERASE_SECT - 8’h10: ERASE_WORD - 8’h20: PWDN - 8’h40: READ_RX - 8’h80: REF_LINE_P - 8’hC0: REF_LINE_AP (access: R/W)
#define UDMA_MRAM_MRAM_MODE_CMD_BIT                                  8
#define UDMA_MRAM_MRAM_MODE_CMD_WIDTH                                8
#define UDMA_MRAM_MRAM_MODE_CMD_MASK                                 0xff00

// Erase  address (access: R/W)
#define UDMA_MRAM_ERASE_ADDR_ADDR_BIT                                0
#define UDMA_MRAM_ERASE_ADDR_ADDR_WIDTH                              19
#define UDMA_MRAM_ERASE_ADDR_ADDR_MASK                               0x7ffff

// Clock divide data, form 0 - 255, frequency divide table is : -8’h0 - IO_FREQUENCY / 1 -8’h1 - IO_FREQUENCY / 2 -8’h2 - IO_FREQUENCY / 4 …  (access: R/W)
#define UDMA_MRAM_CLOCK_DIV_DATA_BIT                                 0
#define UDMA_MRAM_CLOCK_DIV_DATA_WIDTH                               8
#define UDMA_MRAM_CLOCK_DIV_DATA_MASK                                0xff

// Clock divider enable : - 1'b0: disabled - 1'b1: enabled (access: R/W)
#define UDMA_MRAM_CLOCK_DIV_EN_BIT                                   8
#define UDMA_MRAM_CLOCK_DIV_EN_WIDTH                                 1
#define UDMA_MRAM_CLOCK_DIV_EN_MASK                                  0x100

// Trigger enable bit: - 1'b0: disabled - 1'b1: enabled (access: W)
#define UDMA_MRAM_TRIGGER_EN_BIT                                     0
#define UDMA_MRAM_TRIGGER_EN_WIDTH                                   1
#define UDMA_MRAM_TRIGGER_EN_MASK                                    0x1

// Erase done bit: - 1'b0: not done - 1'b1: done (access: R)
#define UDMA_MRAM_ISR_ERASE_DONE_BIT                                 0
#define UDMA_MRAM_ISR_ERASE_DONE_WIDTH                               1
#define UDMA_MRAM_ISR_ERASE_DONE_MASK                                0x1

// Program done bit: - 1'b0: not done - 1'b1: done (access: R)
#define UDMA_MRAM_ISR_PROGRAM_DONE_BIT                               1
#define UDMA_MRAM_ISR_PROGRAM_DONE_WIDTH                             1
#define UDMA_MRAM_ISR_PROGRAM_DONE_MASK                              0x2

// TRIM configuration done bit: - 1'b0: not done - 1'b1: done (access: R)
#define UDMA_MRAM_ISR_TRIM_CFG_DONE_BIT                              2
#define UDMA_MRAM_ISR_TRIM_CFG_DONE_WIDTH                            1
#define UDMA_MRAM_ISR_TRIM_CFG_DONE_MASK                             0x4

// Reference line done bit: - 1'b0: not done - 1'b1: done (access: R)
#define UDMA_MRAM_ISR_REF_LINE_DONE_BIT                              3
#define UDMA_MRAM_ISR_REF_LINE_DONE_WIDTH                            1
#define UDMA_MRAM_ISR_REF_LINE_DONE_MASK                             0x8

// Erase IRQ enable bit: - 1'b0: not enable - 1'b1: enable (access: R)
#define UDMA_MRAM_IER_ERASE_EN_BIT                                   0
#define UDMA_MRAM_IER_ERASE_EN_WIDTH                                 1
#define UDMA_MRAM_IER_ERASE_EN_MASK                                  0x1

// Program IRQ enable bit: - 1'b0: not enable - 1'b1: enable (access: R)
#define UDMA_MRAM_IER_PROGRAM_EN_BIT                                 1
#define UDMA_MRAM_IER_PROGRAM_EN_WIDTH                               1
#define UDMA_MRAM_IER_PROGRAM_EN_MASK                                0x2

// TRIM configuration IRQ enable bit: - 1'b0: not enable - 1'b1: enable (access: R)
#define UDMA_MRAM_IER_TRIM_CFG_EN_BIT                                2
#define UDMA_MRAM_IER_TRIM_CFG_EN_WIDTH                              1
#define UDMA_MRAM_IER_TRIM_CFG_EN_MASK                               0x4

// Reference line IRQ enable bit: - 1'b0: not enable - 1'b1: enable (access: R)
#define UDMA_MRAM_IER_REF_LINE_EN_BIT                                3
#define UDMA_MRAM_IER_REF_LINE_EN_WIDTH                              1
#define UDMA_MRAM_IER_REF_LINE_EN_MASK                               0x8

// Erase clean IRQ bit: - 1'b0: not clean - 1'b1: clean (access: R)
#define UDMA_MRAM_ICR_ERASE_DONE_BIT                                 0
#define UDMA_MRAM_ICR_ERASE_DONE_WIDTH                               1
#define UDMA_MRAM_ICR_ERASE_DONE_MASK                                0x1

// Program clean IRQ bit: - 1'b0: not clean - 1'b1: clean (access: R)
#define UDMA_MRAM_ICR_PROGRAM_DONE_BIT                               1
#define UDMA_MRAM_ICR_PROGRAM_DONE_WIDTH                             1
#define UDMA_MRAM_ICR_PROGRAM_DONE_MASK                              0x2

// TRIM configuration clean IRQ bit: - 1'b0: not clean - 1'b1: clean (access: R)
#define UDMA_MRAM_ICR_TRIM_CFG_DONE_BIT                              2
#define UDMA_MRAM_ICR_TRIM_CFG_DONE_WIDTH                            1
#define UDMA_MRAM_ICR_TRIM_CFG_DONE_MASK                             0x4

// Reference line clean IRQ bit: - 1'b0: not clean - 1'b1: clean (access: R)
#define UDMA_MRAM_ICR_REF_LINE_DONE_BIT                              3
#define UDMA_MRAM_ICR_REF_LINE_DONE_WIDTH                            1
#define UDMA_MRAM_ICR_REF_LINE_DONE_MASK                             0x8



//
// REGISTERS STRUCTS
//

#ifndef LANGUAGE_ASSEMBLY

typedef union {
  struct {
    unsigned int rx_saddr        :16; // RX buffer base address bitfield: - Read: returns value of the buffer pointer until transfer is finished. Else returns 0. - Write: sets RX buffer base address
  };
  unsigned int raw;
} __attribute__((packed)) udma_mram_rx_saddr_t;

typedef union {
  struct {
    unsigned int rx_size         :17; // RX buffer size bitfield in bytes. (128kBytes maximum) - Read: returns remaining buffer size to transfer. - Write: sets buffer size.
  };
  unsigned int raw;
} __attribute__((packed)) udma_mram_rx_size_t;

typedef union {
  struct {
    unsigned int continous       :1 ; // RX channel continuous mode bitfield: -1'b0: disabled -1'b1: enabled At the end of the buffer transfer, the uDMA reloads the address / buffer size and starts a new transfer.
    unsigned int padding0:3 ;
    unsigned int en              :1 ; // RX channel enable and start transfer bitfield: -1'b0: disable -1'b1: enable and start the transfer This signal is used also to queue a transfer if one is already ongoing.
    unsigned int pending         :1 ; // RX transfer pending in queue status flag: -1'b0: no pending transfer in the queue -1'b1: pending transfer in the queue
    unsigned int clr             :1 ; // RX channel clear and stop transfer: -1'b0: disable -1'b1: stop and clear the on-going transfer
  };
  unsigned int raw;
} __attribute__((packed)) udma_mram_rx_cfg_t;

typedef union {
  struct {
    unsigned int tx_saddr        :16; // TX buffer base address bitfield: - Read: returns value of the buffer pointer until transfer is finished. Else returns 0. - Write: sets buffer base address
  };
  unsigned int raw;
} __attribute__((packed)) udma_mram_tx_saddr_t;

typedef union {
  struct {
    unsigned int tx_size         :17; // TX buffer size bitfield in bytes. (128kBytes maximum) - Read: returns remaining buffer size to transfer. - Write: sets buffer size.
  };
  unsigned int raw;
} __attribute__((packed)) udma_mram_tx_size_t;

typedef union {
  struct {
    unsigned int continous       :1 ; // TX channel continuous mode bitfield: -1'b0: disabled -1'b1: enabled At the end of the buffer transfer, the uDMA reloads the address / buffer size and starts a new transfer.
    unsigned int padding0:3 ;
    unsigned int en              :1 ; // TX channel enable and start transfer bitfield: -1'b0: disabled -1'b1: enable and start the transfer This signal is used also to queue a transfer if one is already ongoing.
    unsigned int pending         :1 ; // TX transfer pending in queue status flag: -1'b0: no pending transfer in the queue -1'b1: pending transfer in the queue
    unsigned int clr             :1 ; // TX channel clear and stop transfer bitfield: -1'b0: disabled -1'b1: stop and clear the on-going transfer
  };
  unsigned int raw;
} __attribute__((packed)) udma_mram_tx_cfg_t;

typedef union {
  struct {
    unsigned int tx_dst_addr     :19; // TX destination address
  };
  unsigned int raw;
} __attribute__((packed)) udma_mram_tx_daddr_t;

typedef union {
  struct {
    unsigned int rx_dst_addr     :19; // RX destination address
  };
  unsigned int raw;
} __attribute__((packed)) udma_mram_rx_daddr_t;

typedef union {
  struct {
    unsigned int erase_pending   :1 ; // Erase pending bit: - 1'b0: not pending - 1'b1: pending
    unsigned int tx_busy         :1 ; // Program busy bit: - 1'b0: not busy - 1'b1: busy
    unsigned int rx_busy         :1 ; // Read busy bit: - 1'b0: not busy - 1'b1: busy
    unsigned int ref_line_pending:1 ; // Reference line pending bit: - 1'b0: not pending - 1'b1: pending
  };
  unsigned int raw;
} __attribute__((packed)) udma_mram_status_t;

typedef union {
  struct {
    unsigned int ecc_byps        :1 ; // nan
    unsigned int dpd             :1 ; // nan
    unsigned int aref            :1 ; // nan
    unsigned int tmen            :1 ; // nan
    unsigned int nvr             :1 ; // nan
    unsigned int rst_b           :1 ; // nan
    unsigned int ret_b           :1 ; // nan
    unsigned int por_b           :1 ; // nan
    unsigned int cmd             :8 ; // MRAM command: - 8’h1: TRIM_CFG - 8’h2: NORMAL_TX - 8’h4: ERASE_CHIP - 8’h8: ERASE_SECT - 8’h10: ERASE_WORD - 8’h20: PWDN - 8’h40: READ_RX - 8’h80: REF_LINE_P - 8’hC0: REF_LINE_AP
  };
  unsigned int raw;
} __attribute__((packed)) udma_mram_mram_mode_t;

typedef union {
  struct {
    unsigned int addr            :19; // Erase  address
  };
  unsigned int raw;
} __attribute__((packed)) udma_mram_erase_addr_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) udma_mram_erase_size_t;

typedef union {
  struct {
    unsigned int data            :8 ; // Clock divide data, form 0 - 255, frequency divide table is : -8’h0 - IO_FREQUENCY / 1 -8’h1 - IO_FREQUENCY / 2 -8’h2 - IO_FREQUENCY / 4 … 
    unsigned int en              :1 ; // Clock divider enable : - 1'b0: disabled - 1'b1: enabled
  };
  unsigned int raw;
} __attribute__((packed)) udma_mram_clock_div_t;

typedef union {
  struct {
    unsigned int en              :1 ; // Trigger enable bit: - 1'b0: disabled - 1'b1: enabled
  };
  unsigned int raw;
} __attribute__((packed)) udma_mram_trigger_t;

typedef union {
  struct {
    unsigned int erase_done      :1 ; // Erase done bit: - 1'b0: not done - 1'b1: done
    unsigned int program_done    :1 ; // Program done bit: - 1'b0: not done - 1'b1: done
    unsigned int trim_cfg_done   :1 ; // TRIM configuration done bit: - 1'b0: not done - 1'b1: done
    unsigned int ref_line_done   :1 ; // Reference line done bit: - 1'b0: not done - 1'b1: done
  };
  unsigned int raw;
} __attribute__((packed)) udma_mram_isr_t;

typedef union {
  struct {
    unsigned int erase_en        :1 ; // Erase IRQ enable bit: - 1'b0: not enable - 1'b1: enable
    unsigned int program_en      :1 ; // Program IRQ enable bit: - 1'b0: not enable - 1'b1: enable
    unsigned int trim_cfg_en     :1 ; // TRIM configuration IRQ enable bit: - 1'b0: not enable - 1'b1: enable
    unsigned int ref_line_en     :1 ; // Reference line IRQ enable bit: - 1'b0: not enable - 1'b1: enable
  };
  unsigned int raw;
} __attribute__((packed)) udma_mram_ier_t;

typedef union {
  struct {
    unsigned int erase_done      :1 ; // Erase clean IRQ bit: - 1'b0: not clean - 1'b1: clean
    unsigned int program_done    :1 ; // Program clean IRQ bit: - 1'b0: not clean - 1'b1: clean
    unsigned int trim_cfg_done   :1 ; // TRIM configuration clean IRQ bit: - 1'b0: not clean - 1'b1: clean
    unsigned int ref_line_done   :1 ; // Reference line clean IRQ bit: - 1'b0: not clean - 1'b1: clean
  };
  unsigned int raw;
} __attribute__((packed)) udma_mram_icr_t;

#endif



//
// REGISTERS STRUCTS
//

#ifdef __GVSOC__

class vp_udma_mram_rx_saddr : public vp::reg_32
{
public:
  inline void rx_saddr_set(uint32_t value) { this->set_field(value, UDMA_MRAM_RX_SADDR_RX_SADDR_BIT, UDMA_MRAM_RX_SADDR_RX_SADDR_WIDTH); }
  inline uint32_t rx_saddr_get() { return this->get_field(UDMA_MRAM_RX_SADDR_RX_SADDR_BIT, UDMA_MRAM_RX_SADDR_RX_SADDR_WIDTH); }
};

class vp_udma_mram_rx_size : public vp::reg_32
{
public:
  inline void rx_size_set(uint32_t value) { this->set_field(value, UDMA_MRAM_RX_SIZE_RX_SIZE_BIT, UDMA_MRAM_RX_SIZE_RX_SIZE_WIDTH); }
  inline uint32_t rx_size_get() { return this->get_field(UDMA_MRAM_RX_SIZE_RX_SIZE_BIT, UDMA_MRAM_RX_SIZE_RX_SIZE_WIDTH); }
};

class vp_udma_mram_rx_cfg : public vp::reg_32
{
public:
  inline void continous_set(uint32_t value) { this->set_field(value, UDMA_MRAM_RX_CFG_CONTINOUS_BIT, UDMA_MRAM_RX_CFG_CONTINOUS_WIDTH); }
  inline uint32_t continous_get() { return this->get_field(UDMA_MRAM_RX_CFG_CONTINOUS_BIT, UDMA_MRAM_RX_CFG_CONTINOUS_WIDTH); }
  inline void en_set(uint32_t value) { this->set_field(value, UDMA_MRAM_RX_CFG_EN_BIT, UDMA_MRAM_RX_CFG_EN_WIDTH); }
  inline uint32_t en_get() { return this->get_field(UDMA_MRAM_RX_CFG_EN_BIT, UDMA_MRAM_RX_CFG_EN_WIDTH); }
  inline void pending_set(uint32_t value) { this->set_field(value, UDMA_MRAM_RX_CFG_PENDING_BIT, UDMA_MRAM_RX_CFG_PENDING_WIDTH); }
  inline uint32_t pending_get() { return this->get_field(UDMA_MRAM_RX_CFG_PENDING_BIT, UDMA_MRAM_RX_CFG_PENDING_WIDTH); }
  inline void clr_set(uint32_t value) { this->set_field(value, UDMA_MRAM_RX_CFG_CLR_BIT, UDMA_MRAM_RX_CFG_CLR_WIDTH); }
  inline uint32_t clr_get() { return this->get_field(UDMA_MRAM_RX_CFG_CLR_BIT, UDMA_MRAM_RX_CFG_CLR_WIDTH); }
};

class vp_udma_mram_tx_saddr : public vp::reg_32
{
public:
  inline void tx_saddr_set(uint32_t value) { this->set_field(value, UDMA_MRAM_TX_SADDR_TX_SADDR_BIT, UDMA_MRAM_TX_SADDR_TX_SADDR_WIDTH); }
  inline uint32_t tx_saddr_get() { return this->get_field(UDMA_MRAM_TX_SADDR_TX_SADDR_BIT, UDMA_MRAM_TX_SADDR_TX_SADDR_WIDTH); }
};

class vp_udma_mram_tx_size : public vp::reg_32
{
public:
  inline void tx_size_set(uint32_t value) { this->set_field(value, UDMA_MRAM_TX_SIZE_TX_SIZE_BIT, UDMA_MRAM_TX_SIZE_TX_SIZE_WIDTH); }
  inline uint32_t tx_size_get() { return this->get_field(UDMA_MRAM_TX_SIZE_TX_SIZE_BIT, UDMA_MRAM_TX_SIZE_TX_SIZE_WIDTH); }
};

class vp_udma_mram_tx_cfg : public vp::reg_32
{
public:
  inline void continous_set(uint32_t value) { this->set_field(value, UDMA_MRAM_TX_CFG_CONTINOUS_BIT, UDMA_MRAM_TX_CFG_CONTINOUS_WIDTH); }
  inline uint32_t continous_get() { return this->get_field(UDMA_MRAM_TX_CFG_CONTINOUS_BIT, UDMA_MRAM_TX_CFG_CONTINOUS_WIDTH); }
  inline void en_set(uint32_t value) { this->set_field(value, UDMA_MRAM_TX_CFG_EN_BIT, UDMA_MRAM_TX_CFG_EN_WIDTH); }
  inline uint32_t en_get() { return this->get_field(UDMA_MRAM_TX_CFG_EN_BIT, UDMA_MRAM_TX_CFG_EN_WIDTH); }
  inline void pending_set(uint32_t value) { this->set_field(value, UDMA_MRAM_TX_CFG_PENDING_BIT, UDMA_MRAM_TX_CFG_PENDING_WIDTH); }
  inline uint32_t pending_get() { return this->get_field(UDMA_MRAM_TX_CFG_PENDING_BIT, UDMA_MRAM_TX_CFG_PENDING_WIDTH); }
  inline void clr_set(uint32_t value) { this->set_field(value, UDMA_MRAM_TX_CFG_CLR_BIT, UDMA_MRAM_TX_CFG_CLR_WIDTH); }
  inline uint32_t clr_get() { return this->get_field(UDMA_MRAM_TX_CFG_CLR_BIT, UDMA_MRAM_TX_CFG_CLR_WIDTH); }
};

class vp_udma_mram_tx_daddr : public vp::reg_32
{
public:
  inline void tx_dst_addr_set(uint32_t value) { this->set_field(value, UDMA_MRAM_TX_DADDR_TX_DST_ADDR_BIT, UDMA_MRAM_TX_DADDR_TX_DST_ADDR_WIDTH); }
  inline uint32_t tx_dst_addr_get() { return this->get_field(UDMA_MRAM_TX_DADDR_TX_DST_ADDR_BIT, UDMA_MRAM_TX_DADDR_TX_DST_ADDR_WIDTH); }
};

class vp_udma_mram_rx_daddr : public vp::reg_32
{
public:
  inline void rx_dst_addr_set(uint32_t value) { this->set_field(value, UDMA_MRAM_RX_DADDR_RX_DST_ADDR_BIT, UDMA_MRAM_RX_DADDR_RX_DST_ADDR_WIDTH); }
  inline uint32_t rx_dst_addr_get() { return this->get_field(UDMA_MRAM_RX_DADDR_RX_DST_ADDR_BIT, UDMA_MRAM_RX_DADDR_RX_DST_ADDR_WIDTH); }
};

class vp_udma_mram_status : public vp::reg_32
{
public:
  inline void erase_pending_set(uint32_t value) { this->set_field(value, UDMA_MRAM_STATUS_ERASE_PENDING_BIT, UDMA_MRAM_STATUS_ERASE_PENDING_WIDTH); }
  inline uint32_t erase_pending_get() { return this->get_field(UDMA_MRAM_STATUS_ERASE_PENDING_BIT, UDMA_MRAM_STATUS_ERASE_PENDING_WIDTH); }
  inline void tx_busy_set(uint32_t value) { this->set_field(value, UDMA_MRAM_STATUS_TX_BUSY_BIT, UDMA_MRAM_STATUS_TX_BUSY_WIDTH); }
  inline uint32_t tx_busy_get() { return this->get_field(UDMA_MRAM_STATUS_TX_BUSY_BIT, UDMA_MRAM_STATUS_TX_BUSY_WIDTH); }
  inline void rx_busy_set(uint32_t value) { this->set_field(value, UDMA_MRAM_STATUS_RX_BUSY_BIT, UDMA_MRAM_STATUS_RX_BUSY_WIDTH); }
  inline uint32_t rx_busy_get() { return this->get_field(UDMA_MRAM_STATUS_RX_BUSY_BIT, UDMA_MRAM_STATUS_RX_BUSY_WIDTH); }
  inline void ref_line_pending_set(uint32_t value) { this->set_field(value, UDMA_MRAM_STATUS_REF_LINE_PENDING_BIT, UDMA_MRAM_STATUS_REF_LINE_PENDING_WIDTH); }
  inline uint32_t ref_line_pending_get() { return this->get_field(UDMA_MRAM_STATUS_REF_LINE_PENDING_BIT, UDMA_MRAM_STATUS_REF_LINE_PENDING_WIDTH); }
};

class vp_udma_mram_mram_mode : public vp::reg_32
{
public:
  inline void ecc_byps_set(uint32_t value) { this->set_field(value, UDMA_MRAM_MRAM_MODE_ECC_BYPS_BIT, UDMA_MRAM_MRAM_MODE_ECC_BYPS_WIDTH); }
  inline uint32_t ecc_byps_get() { return this->get_field(UDMA_MRAM_MRAM_MODE_ECC_BYPS_BIT, UDMA_MRAM_MRAM_MODE_ECC_BYPS_WIDTH); }
  inline void dpd_set(uint32_t value) { this->set_field(value, UDMA_MRAM_MRAM_MODE_DPD_BIT, UDMA_MRAM_MRAM_MODE_DPD_WIDTH); }
  inline uint32_t dpd_get() { return this->get_field(UDMA_MRAM_MRAM_MODE_DPD_BIT, UDMA_MRAM_MRAM_MODE_DPD_WIDTH); }
  inline void aref_set(uint32_t value) { this->set_field(value, UDMA_MRAM_MRAM_MODE_AREF_BIT, UDMA_MRAM_MRAM_MODE_AREF_WIDTH); }
  inline uint32_t aref_get() { return this->get_field(UDMA_MRAM_MRAM_MODE_AREF_BIT, UDMA_MRAM_MRAM_MODE_AREF_WIDTH); }
  inline void tmen_set(uint32_t value) { this->set_field(value, UDMA_MRAM_MRAM_MODE_TMEN_BIT, UDMA_MRAM_MRAM_MODE_TMEN_WIDTH); }
  inline uint32_t tmen_get() { return this->get_field(UDMA_MRAM_MRAM_MODE_TMEN_BIT, UDMA_MRAM_MRAM_MODE_TMEN_WIDTH); }
  inline void nvr_set(uint32_t value) { this->set_field(value, UDMA_MRAM_MRAM_MODE_NVR_BIT, UDMA_MRAM_MRAM_MODE_NVR_WIDTH); }
  inline uint32_t nvr_get() { return this->get_field(UDMA_MRAM_MRAM_MODE_NVR_BIT, UDMA_MRAM_MRAM_MODE_NVR_WIDTH); }
  inline void rst_b_set(uint32_t value) { this->set_field(value, UDMA_MRAM_MRAM_MODE_RST_B_BIT, UDMA_MRAM_MRAM_MODE_RST_B_WIDTH); }
  inline uint32_t rst_b_get() { return this->get_field(UDMA_MRAM_MRAM_MODE_RST_B_BIT, UDMA_MRAM_MRAM_MODE_RST_B_WIDTH); }
  inline void ret_b_set(uint32_t value) { this->set_field(value, UDMA_MRAM_MRAM_MODE_RET_B_BIT, UDMA_MRAM_MRAM_MODE_RET_B_WIDTH); }
  inline uint32_t ret_b_get() { return this->get_field(UDMA_MRAM_MRAM_MODE_RET_B_BIT, UDMA_MRAM_MRAM_MODE_RET_B_WIDTH); }
  inline void por_b_set(uint32_t value) { this->set_field(value, UDMA_MRAM_MRAM_MODE_POR_B_BIT, UDMA_MRAM_MRAM_MODE_POR_B_WIDTH); }
  inline uint32_t por_b_get() { return this->get_field(UDMA_MRAM_MRAM_MODE_POR_B_BIT, UDMA_MRAM_MRAM_MODE_POR_B_WIDTH); }
  inline void cmd_set(uint32_t value) { this->set_field(value, UDMA_MRAM_MRAM_MODE_CMD_BIT, UDMA_MRAM_MRAM_MODE_CMD_WIDTH); }
  inline uint32_t cmd_get() { return this->get_field(UDMA_MRAM_MRAM_MODE_CMD_BIT, UDMA_MRAM_MRAM_MODE_CMD_WIDTH); }
};

class vp_udma_mram_erase_addr : public vp::reg_32
{
public:
  inline void addr_set(uint32_t value) { this->set_field(value, UDMA_MRAM_ERASE_ADDR_ADDR_BIT, UDMA_MRAM_ERASE_ADDR_ADDR_WIDTH); }
  inline uint32_t addr_get() { return this->get_field(UDMA_MRAM_ERASE_ADDR_ADDR_BIT, UDMA_MRAM_ERASE_ADDR_ADDR_WIDTH); }
};

class vp_udma_mram_erase_size : public vp::reg_32
{
public:
};

class vp_udma_mram_clock_div : public vp::reg_32
{
public:
  inline void data_set(uint32_t value) { this->set_field(value, UDMA_MRAM_CLOCK_DIV_DATA_BIT, UDMA_MRAM_CLOCK_DIV_DATA_WIDTH); }
  inline uint32_t data_get() { return this->get_field(UDMA_MRAM_CLOCK_DIV_DATA_BIT, UDMA_MRAM_CLOCK_DIV_DATA_WIDTH); }
  inline void en_set(uint32_t value) { this->set_field(value, UDMA_MRAM_CLOCK_DIV_EN_BIT, UDMA_MRAM_CLOCK_DIV_EN_WIDTH); }
  inline uint32_t en_get() { return this->get_field(UDMA_MRAM_CLOCK_DIV_EN_BIT, UDMA_MRAM_CLOCK_DIV_EN_WIDTH); }
};

class vp_udma_mram_trigger : public vp::reg_32
{
public:
  inline void en_set(uint32_t value) { this->set_field(value, UDMA_MRAM_TRIGGER_EN_BIT, UDMA_MRAM_TRIGGER_EN_WIDTH); }
  inline uint32_t en_get() { return this->get_field(UDMA_MRAM_TRIGGER_EN_BIT, UDMA_MRAM_TRIGGER_EN_WIDTH); }
};

class vp_udma_mram_isr : public vp::reg_32
{
public:
  inline void erase_done_set(uint32_t value) { this->set_field(value, UDMA_MRAM_ISR_ERASE_DONE_BIT, UDMA_MRAM_ISR_ERASE_DONE_WIDTH); }
  inline uint32_t erase_done_get() { return this->get_field(UDMA_MRAM_ISR_ERASE_DONE_BIT, UDMA_MRAM_ISR_ERASE_DONE_WIDTH); }
  inline void program_done_set(uint32_t value) { this->set_field(value, UDMA_MRAM_ISR_PROGRAM_DONE_BIT, UDMA_MRAM_ISR_PROGRAM_DONE_WIDTH); }
  inline uint32_t program_done_get() { return this->get_field(UDMA_MRAM_ISR_PROGRAM_DONE_BIT, UDMA_MRAM_ISR_PROGRAM_DONE_WIDTH); }
  inline void trim_cfg_done_set(uint32_t value) { this->set_field(value, UDMA_MRAM_ISR_TRIM_CFG_DONE_BIT, UDMA_MRAM_ISR_TRIM_CFG_DONE_WIDTH); }
  inline uint32_t trim_cfg_done_get() { return this->get_field(UDMA_MRAM_ISR_TRIM_CFG_DONE_BIT, UDMA_MRAM_ISR_TRIM_CFG_DONE_WIDTH); }
  inline void ref_line_done_set(uint32_t value) { this->set_field(value, UDMA_MRAM_ISR_REF_LINE_DONE_BIT, UDMA_MRAM_ISR_REF_LINE_DONE_WIDTH); }
  inline uint32_t ref_line_done_get() { return this->get_field(UDMA_MRAM_ISR_REF_LINE_DONE_BIT, UDMA_MRAM_ISR_REF_LINE_DONE_WIDTH); }
};

class vp_udma_mram_ier : public vp::reg_32
{
public:
  inline void erase_en_set(uint32_t value) { this->set_field(value, UDMA_MRAM_IER_ERASE_EN_BIT, UDMA_MRAM_IER_ERASE_EN_WIDTH); }
  inline uint32_t erase_en_get() { return this->get_field(UDMA_MRAM_IER_ERASE_EN_BIT, UDMA_MRAM_IER_ERASE_EN_WIDTH); }
  inline void program_en_set(uint32_t value) { this->set_field(value, UDMA_MRAM_IER_PROGRAM_EN_BIT, UDMA_MRAM_IER_PROGRAM_EN_WIDTH); }
  inline uint32_t program_en_get() { return this->get_field(UDMA_MRAM_IER_PROGRAM_EN_BIT, UDMA_MRAM_IER_PROGRAM_EN_WIDTH); }
  inline void trim_cfg_en_set(uint32_t value) { this->set_field(value, UDMA_MRAM_IER_TRIM_CFG_EN_BIT, UDMA_MRAM_IER_TRIM_CFG_EN_WIDTH); }
  inline uint32_t trim_cfg_en_get() { return this->get_field(UDMA_MRAM_IER_TRIM_CFG_EN_BIT, UDMA_MRAM_IER_TRIM_CFG_EN_WIDTH); }
  inline void ref_line_en_set(uint32_t value) { this->set_field(value, UDMA_MRAM_IER_REF_LINE_EN_BIT, UDMA_MRAM_IER_REF_LINE_EN_WIDTH); }
  inline uint32_t ref_line_en_get() { return this->get_field(UDMA_MRAM_IER_REF_LINE_EN_BIT, UDMA_MRAM_IER_REF_LINE_EN_WIDTH); }
};

class vp_udma_mram_icr : public vp::reg_32
{
public:
  inline void erase_done_set(uint32_t value) { this->set_field(value, UDMA_MRAM_ICR_ERASE_DONE_BIT, UDMA_MRAM_ICR_ERASE_DONE_WIDTH); }
  inline uint32_t erase_done_get() { return this->get_field(UDMA_MRAM_ICR_ERASE_DONE_BIT, UDMA_MRAM_ICR_ERASE_DONE_WIDTH); }
  inline void program_done_set(uint32_t value) { this->set_field(value, UDMA_MRAM_ICR_PROGRAM_DONE_BIT, UDMA_MRAM_ICR_PROGRAM_DONE_WIDTH); }
  inline uint32_t program_done_get() { return this->get_field(UDMA_MRAM_ICR_PROGRAM_DONE_BIT, UDMA_MRAM_ICR_PROGRAM_DONE_WIDTH); }
  inline void trim_cfg_done_set(uint32_t value) { this->set_field(value, UDMA_MRAM_ICR_TRIM_CFG_DONE_BIT, UDMA_MRAM_ICR_TRIM_CFG_DONE_WIDTH); }
  inline uint32_t trim_cfg_done_get() { return this->get_field(UDMA_MRAM_ICR_TRIM_CFG_DONE_BIT, UDMA_MRAM_ICR_TRIM_CFG_DONE_WIDTH); }
  inline void ref_line_done_set(uint32_t value) { this->set_field(value, UDMA_MRAM_ICR_REF_LINE_DONE_BIT, UDMA_MRAM_ICR_REF_LINE_DONE_WIDTH); }
  inline uint32_t ref_line_done_get() { return this->get_field(UDMA_MRAM_ICR_REF_LINE_DONE_BIT, UDMA_MRAM_ICR_REF_LINE_DONE_WIDTH); }
};

#endif



//
// REGISTERS GLOBAL STRUCT
//

#ifndef LANGUAGE_ASSEMBLY

typedef struct {
  unsigned int rx_saddr        ; // uDMA RX UART buffer base address configuration register.
  unsigned int rx_size         ; // uDMA RX UART buffer size configuration register.
  unsigned int rx_cfg          ; // uDMA RX UART stream configuration register.
  unsigned int tx_saddr        ; // uDMA TX UART buffer base address configuration register.
  unsigned int tx_size         ; // uDMA TX UART buffer size configuration register.
  unsigned int tx_cfg          ; // uDMA TX UART stream configuration register.
  unsigned int tx_daddr        ; // Destination Address register for programing.
  unsigned int rx_daddr        ; // Destination Address register for reading.
  unsigned int status          ; // MRAM status for pending operation
  unsigned int mram_mode       ; // MRAM MODE: READ - ERASE  - PROG - TRIM_CFG
  unsigned int erase_addr      ; // Erase Address for word or Sector Erase
  unsigned int erase_size      ; // Size of Words or Sector to erase
  unsigned int clock_div       ; // Set Clock div Enable and Div factor.
  unsigned int trigger         ; //  Trigger ERASE and REF_LINE INIT.
  unsigned int isr             ; // Interrupt status register.
  unsigned int ier             ; // Interrupt enable register.
  unsigned int icr             ; // Interrupt clean register.
} __attribute__((packed)) udma_mram_udma_mram_t;

#endif



//
// REGISTERS ACCESS FUNCTIONS
//

#ifndef LANGUAGE_ASSEMBLY

static inline uint32_t udma_mram_rx_saddr_get(uint32_t base) { return ARCHI_READ(base, UDMA_MRAM_RX_SADDR_OFFSET); }
static inline void udma_mram_rx_saddr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MRAM_RX_SADDR_OFFSET, value); }

static inline uint32_t udma_mram_rx_size_get(uint32_t base) { return ARCHI_READ(base, UDMA_MRAM_RX_SIZE_OFFSET); }
static inline void udma_mram_rx_size_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MRAM_RX_SIZE_OFFSET, value); }

static inline uint32_t udma_mram_rx_cfg_get(uint32_t base) { return ARCHI_READ(base, UDMA_MRAM_RX_CFG_OFFSET); }
static inline void udma_mram_rx_cfg_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MRAM_RX_CFG_OFFSET, value); }

static inline uint32_t udma_mram_tx_saddr_get(uint32_t base) { return ARCHI_READ(base, UDMA_MRAM_TX_SADDR_OFFSET); }
static inline void udma_mram_tx_saddr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MRAM_TX_SADDR_OFFSET, value); }

static inline uint32_t udma_mram_tx_size_get(uint32_t base) { return ARCHI_READ(base, UDMA_MRAM_TX_SIZE_OFFSET); }
static inline void udma_mram_tx_size_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MRAM_TX_SIZE_OFFSET, value); }

static inline uint32_t udma_mram_tx_cfg_get(uint32_t base) { return ARCHI_READ(base, UDMA_MRAM_TX_CFG_OFFSET); }
static inline void udma_mram_tx_cfg_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MRAM_TX_CFG_OFFSET, value); }

static inline uint32_t udma_mram_tx_daddr_get(uint32_t base) { return ARCHI_READ(base, UDMA_MRAM_TX_DADDR_OFFSET); }
static inline void udma_mram_tx_daddr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MRAM_TX_DADDR_OFFSET, value); }

static inline uint32_t udma_mram_rx_daddr_get(uint32_t base) { return ARCHI_READ(base, UDMA_MRAM_RX_DADDR_OFFSET); }
static inline void udma_mram_rx_daddr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MRAM_RX_DADDR_OFFSET, value); }

static inline uint32_t udma_mram_status_get(uint32_t base) { return ARCHI_READ(base, UDMA_MRAM_STATUS_OFFSET); }
static inline void udma_mram_status_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MRAM_STATUS_OFFSET, value); }

static inline uint32_t udma_mram_mram_mode_get(uint32_t base) { return ARCHI_READ(base, UDMA_MRAM_MRAM_MODE_OFFSET); }
static inline void udma_mram_mram_mode_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MRAM_MRAM_MODE_OFFSET, value); }

static inline uint32_t udma_mram_erase_addr_get(uint32_t base) { return ARCHI_READ(base, UDMA_MRAM_ERASE_ADDR_OFFSET); }
static inline void udma_mram_erase_addr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MRAM_ERASE_ADDR_OFFSET, value); }

static inline uint32_t udma_mram_erase_size_get(uint32_t base) { return ARCHI_READ(base, UDMA_MRAM_ERASE_SIZE_OFFSET); }
static inline void udma_mram_erase_size_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MRAM_ERASE_SIZE_OFFSET, value); }

static inline uint32_t udma_mram_clock_div_get(uint32_t base) { return ARCHI_READ(base, UDMA_MRAM_CLOCK_DIV_OFFSET); }
static inline void udma_mram_clock_div_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MRAM_CLOCK_DIV_OFFSET, value); }

static inline uint32_t udma_mram_trigger_get(uint32_t base) { return ARCHI_READ(base, UDMA_MRAM_TRIGGER_OFFSET); }
static inline void udma_mram_trigger_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MRAM_TRIGGER_OFFSET, value); }

static inline uint32_t udma_mram_isr_get(uint32_t base) { return ARCHI_READ(base, UDMA_MRAM_ISR_OFFSET); }
static inline void udma_mram_isr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MRAM_ISR_OFFSET, value); }

static inline uint32_t udma_mram_ier_get(uint32_t base) { return ARCHI_READ(base, UDMA_MRAM_IER_OFFSET); }
static inline void udma_mram_ier_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MRAM_IER_OFFSET, value); }

static inline uint32_t udma_mram_icr_get(uint32_t base) { return ARCHI_READ(base, UDMA_MRAM_ICR_OFFSET); }
static inline void udma_mram_icr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_MRAM_ICR_OFFSET, value); }

#endif



//
// REGISTERS FIELDS MACROS
//

#ifndef LANGUAGE_ASSEMBLY

#define UDMA_MRAM_RX_SADDR_RX_SADDR_GET(value)             (ARCHI_BEXTRACTU((value),16,0))
#define UDMA_MRAM_RX_SADDR_RX_SADDR_GETS(value)            (ARCHI_BEXTRACT((value),16,0))
#define UDMA_MRAM_RX_SADDR_RX_SADDR_SET(value,field)       (ARCHI_BINSERT((value),(field),16,0))
#define UDMA_MRAM_RX_SADDR_RX_SADDR(val)                   ((val) << 0)

#define UDMA_MRAM_RX_SIZE_RX_SIZE_GET(value)               (ARCHI_BEXTRACTU((value),17,0))
#define UDMA_MRAM_RX_SIZE_RX_SIZE_GETS(value)              (ARCHI_BEXTRACT((value),17,0))
#define UDMA_MRAM_RX_SIZE_RX_SIZE_SET(value,field)         (ARCHI_BINSERT((value),(field),17,0))
#define UDMA_MRAM_RX_SIZE_RX_SIZE(val)                     ((val) << 0)

#define UDMA_MRAM_RX_CFG_CONTINOUS_GET(value)              (ARCHI_BEXTRACTU((value),1,0))
#define UDMA_MRAM_RX_CFG_CONTINOUS_GETS(value)             (ARCHI_BEXTRACT((value),1,0))
#define UDMA_MRAM_RX_CFG_CONTINOUS_SET(value,field)        (ARCHI_BINSERT((value),(field),1,0))
#define UDMA_MRAM_RX_CFG_CONTINOUS(val)                    ((val) << 0)

#define UDMA_MRAM_RX_CFG_EN_GET(value)                     (ARCHI_BEXTRACTU((value),1,4))
#define UDMA_MRAM_RX_CFG_EN_GETS(value)                    (ARCHI_BEXTRACT((value),1,4))
#define UDMA_MRAM_RX_CFG_EN_SET(value,field)               (ARCHI_BINSERT((value),(field),1,4))
#define UDMA_MRAM_RX_CFG_EN(val)                           ((val) << 4)

#define UDMA_MRAM_RX_CFG_PENDING_GET(value)                (ARCHI_BEXTRACTU((value),1,5))
#define UDMA_MRAM_RX_CFG_PENDING_GETS(value)               (ARCHI_BEXTRACT((value),1,5))
#define UDMA_MRAM_RX_CFG_PENDING_SET(value,field)          (ARCHI_BINSERT((value),(field),1,5))
#define UDMA_MRAM_RX_CFG_PENDING(val)                      ((val) << 5)

#define UDMA_MRAM_RX_CFG_CLR_GET(value)                    (ARCHI_BEXTRACTU((value),1,6))
#define UDMA_MRAM_RX_CFG_CLR_GETS(value)                   (ARCHI_BEXTRACT((value),1,6))
#define UDMA_MRAM_RX_CFG_CLR_SET(value,field)              (ARCHI_BINSERT((value),(field),1,6))
#define UDMA_MRAM_RX_CFG_CLR(val)                          ((val) << 6)

#define UDMA_MRAM_TX_SADDR_TX_SADDR_GET(value)             (ARCHI_BEXTRACTU((value),16,0))
#define UDMA_MRAM_TX_SADDR_TX_SADDR_GETS(value)            (ARCHI_BEXTRACT((value),16,0))
#define UDMA_MRAM_TX_SADDR_TX_SADDR_SET(value,field)       (ARCHI_BINSERT((value),(field),16,0))
#define UDMA_MRAM_TX_SADDR_TX_SADDR(val)                   ((val) << 0)

#define UDMA_MRAM_TX_SIZE_TX_SIZE_GET(value)               (ARCHI_BEXTRACTU((value),17,0))
#define UDMA_MRAM_TX_SIZE_TX_SIZE_GETS(value)              (ARCHI_BEXTRACT((value),17,0))
#define UDMA_MRAM_TX_SIZE_TX_SIZE_SET(value,field)         (ARCHI_BINSERT((value),(field),17,0))
#define UDMA_MRAM_TX_SIZE_TX_SIZE(val)                     ((val) << 0)

#define UDMA_MRAM_TX_CFG_CONTINOUS_GET(value)              (ARCHI_BEXTRACTU((value),1,0))
#define UDMA_MRAM_TX_CFG_CONTINOUS_GETS(value)             (ARCHI_BEXTRACT((value),1,0))
#define UDMA_MRAM_TX_CFG_CONTINOUS_SET(value,field)        (ARCHI_BINSERT((value),(field),1,0))
#define UDMA_MRAM_TX_CFG_CONTINOUS(val)                    ((val) << 0)

#define UDMA_MRAM_TX_CFG_EN_GET(value)                     (ARCHI_BEXTRACTU((value),1,4))
#define UDMA_MRAM_TX_CFG_EN_GETS(value)                    (ARCHI_BEXTRACT((value),1,4))
#define UDMA_MRAM_TX_CFG_EN_SET(value,field)               (ARCHI_BINSERT((value),(field),1,4))
#define UDMA_MRAM_TX_CFG_EN(val)                           ((val) << 4)

#define UDMA_MRAM_TX_CFG_PENDING_GET(value)                (ARCHI_BEXTRACTU((value),1,5))
#define UDMA_MRAM_TX_CFG_PENDING_GETS(value)               (ARCHI_BEXTRACT((value),1,5))
#define UDMA_MRAM_TX_CFG_PENDING_SET(value,field)          (ARCHI_BINSERT((value),(field),1,5))
#define UDMA_MRAM_TX_CFG_PENDING(val)                      ((val) << 5)

#define UDMA_MRAM_TX_CFG_CLR_GET(value)                    (ARCHI_BEXTRACTU((value),1,6))
#define UDMA_MRAM_TX_CFG_CLR_GETS(value)                   (ARCHI_BEXTRACT((value),1,6))
#define UDMA_MRAM_TX_CFG_CLR_SET(value,field)              (ARCHI_BINSERT((value),(field),1,6))
#define UDMA_MRAM_TX_CFG_CLR(val)                          ((val) << 6)

#define UDMA_MRAM_TX_DADDR_TX_DST_ADDR_GET(value)          (ARCHI_BEXTRACTU((value),19,0))
#define UDMA_MRAM_TX_DADDR_TX_DST_ADDR_GETS(value)         (ARCHI_BEXTRACT((value),19,0))
#define UDMA_MRAM_TX_DADDR_TX_DST_ADDR_SET(value,field)    (ARCHI_BINSERT((value),(field),19,0))
#define UDMA_MRAM_TX_DADDR_TX_DST_ADDR(val)                ((val) << 0)

#define UDMA_MRAM_RX_DADDR_RX_DST_ADDR_GET(value)          (ARCHI_BEXTRACTU((value),19,0))
#define UDMA_MRAM_RX_DADDR_RX_DST_ADDR_GETS(value)         (ARCHI_BEXTRACT((value),19,0))
#define UDMA_MRAM_RX_DADDR_RX_DST_ADDR_SET(value,field)    (ARCHI_BINSERT((value),(field),19,0))
#define UDMA_MRAM_RX_DADDR_RX_DST_ADDR(val)                ((val) << 0)

#define UDMA_MRAM_STATUS_ERASE_PENDING_GET(value)          (ARCHI_BEXTRACTU((value),1,0))
#define UDMA_MRAM_STATUS_ERASE_PENDING_GETS(value)         (ARCHI_BEXTRACT((value),1,0))
#define UDMA_MRAM_STATUS_ERASE_PENDING_SET(value,field)    (ARCHI_BINSERT((value),(field),1,0))
#define UDMA_MRAM_STATUS_ERASE_PENDING(val)                ((val) << 0)

#define UDMA_MRAM_STATUS_TX_BUSY_GET(value)                (ARCHI_BEXTRACTU((value),1,1))
#define UDMA_MRAM_STATUS_TX_BUSY_GETS(value)               (ARCHI_BEXTRACT((value),1,1))
#define UDMA_MRAM_STATUS_TX_BUSY_SET(value,field)          (ARCHI_BINSERT((value),(field),1,1))
#define UDMA_MRAM_STATUS_TX_BUSY(val)                      ((val) << 1)

#define UDMA_MRAM_STATUS_RX_BUSY_GET(value)                (ARCHI_BEXTRACTU((value),1,2))
#define UDMA_MRAM_STATUS_RX_BUSY_GETS(value)               (ARCHI_BEXTRACT((value),1,2))
#define UDMA_MRAM_STATUS_RX_BUSY_SET(value,field)          (ARCHI_BINSERT((value),(field),1,2))
#define UDMA_MRAM_STATUS_RX_BUSY(val)                      ((val) << 2)

#define UDMA_MRAM_STATUS_REF_LINE_PENDING_GET(value)       (ARCHI_BEXTRACTU((value),1,3))
#define UDMA_MRAM_STATUS_REF_LINE_PENDING_GETS(value)      (ARCHI_BEXTRACT((value),1,3))
#define UDMA_MRAM_STATUS_REF_LINE_PENDING_SET(value,field) (ARCHI_BINSERT((value),(field),1,3))
#define UDMA_MRAM_STATUS_REF_LINE_PENDING(val)             ((val) << 3)

#define UDMA_MRAM_MRAM_MODE_ECC_BYPS_GET(value)            (ARCHI_BEXTRACTU((value),1,0))
#define UDMA_MRAM_MRAM_MODE_ECC_BYPS_GETS(value)           (ARCHI_BEXTRACT((value),1,0))
#define UDMA_MRAM_MRAM_MODE_ECC_BYPS_SET(value,field)      (ARCHI_BINSERT((value),(field),1,0))
#define UDMA_MRAM_MRAM_MODE_ECC_BYPS(val)                  ((val) << 0)

#define UDMA_MRAM_MRAM_MODE_DPD_GET(value)                 (ARCHI_BEXTRACTU((value),1,1))
#define UDMA_MRAM_MRAM_MODE_DPD_GETS(value)                (ARCHI_BEXTRACT((value),1,1))
#define UDMA_MRAM_MRAM_MODE_DPD_SET(value,field)           (ARCHI_BINSERT((value),(field),1,1))
#define UDMA_MRAM_MRAM_MODE_DPD(val)                       ((val) << 1)

#define UDMA_MRAM_MRAM_MODE_AREF_GET(value)                (ARCHI_BEXTRACTU((value),1,2))
#define UDMA_MRAM_MRAM_MODE_AREF_GETS(value)               (ARCHI_BEXTRACT((value),1,2))
#define UDMA_MRAM_MRAM_MODE_AREF_SET(value,field)          (ARCHI_BINSERT((value),(field),1,2))
#define UDMA_MRAM_MRAM_MODE_AREF(val)                      ((val) << 2)

#define UDMA_MRAM_MRAM_MODE_TMEN_GET(value)                (ARCHI_BEXTRACTU((value),1,3))
#define UDMA_MRAM_MRAM_MODE_TMEN_GETS(value)               (ARCHI_BEXTRACT((value),1,3))
#define UDMA_MRAM_MRAM_MODE_TMEN_SET(value,field)          (ARCHI_BINSERT((value),(field),1,3))
#define UDMA_MRAM_MRAM_MODE_TMEN(val)                      ((val) << 3)

#define UDMA_MRAM_MRAM_MODE_NVR_GET(value)                 (ARCHI_BEXTRACTU((value),1,4))
#define UDMA_MRAM_MRAM_MODE_NVR_GETS(value)                (ARCHI_BEXTRACT((value),1,4))
#define UDMA_MRAM_MRAM_MODE_NVR_SET(value,field)           (ARCHI_BINSERT((value),(field),1,4))
#define UDMA_MRAM_MRAM_MODE_NVR(val)                       ((val) << 4)

#define UDMA_MRAM_MRAM_MODE_RST_B_GET(value)               (ARCHI_BEXTRACTU((value),1,5))
#define UDMA_MRAM_MRAM_MODE_RST_B_GETS(value)              (ARCHI_BEXTRACT((value),1,5))
#define UDMA_MRAM_MRAM_MODE_RST_B_SET(value,field)         (ARCHI_BINSERT((value),(field),1,5))
#define UDMA_MRAM_MRAM_MODE_RST_B(val)                     ((val) << 5)

#define UDMA_MRAM_MRAM_MODE_RET_B_GET(value)               (ARCHI_BEXTRACTU((value),1,6))
#define UDMA_MRAM_MRAM_MODE_RET_B_GETS(value)              (ARCHI_BEXTRACT((value),1,6))
#define UDMA_MRAM_MRAM_MODE_RET_B_SET(value,field)         (ARCHI_BINSERT((value),(field),1,6))
#define UDMA_MRAM_MRAM_MODE_RET_B(val)                     ((val) << 6)

#define UDMA_MRAM_MRAM_MODE_POR_B_GET(value)               (ARCHI_BEXTRACTU((value),1,7))
#define UDMA_MRAM_MRAM_MODE_POR_B_GETS(value)              (ARCHI_BEXTRACT((value),1,7))
#define UDMA_MRAM_MRAM_MODE_POR_B_SET(value,field)         (ARCHI_BINSERT((value),(field),1,7))
#define UDMA_MRAM_MRAM_MODE_POR_B(val)                     ((val) << 7)

#define UDMA_MRAM_MRAM_MODE_CMD_GET(value)                 (ARCHI_BEXTRACTU((value),8,8))
#define UDMA_MRAM_MRAM_MODE_CMD_GETS(value)                (ARCHI_BEXTRACT((value),8,8))
#define UDMA_MRAM_MRAM_MODE_CMD_SET(value,field)           (ARCHI_BINSERT((value),(field),8,8))
#define UDMA_MRAM_MRAM_MODE_CMD(val)                       ((val) << 8)

#define UDMA_MRAM_ERASE_ADDR_ADDR_GET(value)               (ARCHI_BEXTRACTU((value),19,0))
#define UDMA_MRAM_ERASE_ADDR_ADDR_GETS(value)              (ARCHI_BEXTRACT((value),19,0))
#define UDMA_MRAM_ERASE_ADDR_ADDR_SET(value,field)         (ARCHI_BINSERT((value),(field),19,0))
#define UDMA_MRAM_ERASE_ADDR_ADDR(val)                     ((val) << 0)

#define UDMA_MRAM_CLOCK_DIV_DATA_GET(value)                (ARCHI_BEXTRACTU((value),8,0))
#define UDMA_MRAM_CLOCK_DIV_DATA_GETS(value)               (ARCHI_BEXTRACT((value),8,0))
#define UDMA_MRAM_CLOCK_DIV_DATA_SET(value,field)          (ARCHI_BINSERT((value),(field),8,0))
#define UDMA_MRAM_CLOCK_DIV_DATA(val)                      ((val) << 0)

#define UDMA_MRAM_CLOCK_DIV_EN_GET(value)                  (ARCHI_BEXTRACTU((value),1,8))
#define UDMA_MRAM_CLOCK_DIV_EN_GETS(value)                 (ARCHI_BEXTRACT((value),1,8))
#define UDMA_MRAM_CLOCK_DIV_EN_SET(value,field)            (ARCHI_BINSERT((value),(field),1,8))
#define UDMA_MRAM_CLOCK_DIV_EN(val)                        ((val) << 8)

#define UDMA_MRAM_TRIGGER_EN_GET(value)                    (ARCHI_BEXTRACTU((value),1,0))
#define UDMA_MRAM_TRIGGER_EN_GETS(value)                   (ARCHI_BEXTRACT((value),1,0))
#define UDMA_MRAM_TRIGGER_EN_SET(value,field)              (ARCHI_BINSERT((value),(field),1,0))
#define UDMA_MRAM_TRIGGER_EN(val)                          ((val) << 0)

#define UDMA_MRAM_ISR_ERASE_DONE_GET(value)                (ARCHI_BEXTRACTU((value),1,0))
#define UDMA_MRAM_ISR_ERASE_DONE_GETS(value)               (ARCHI_BEXTRACT((value),1,0))
#define UDMA_MRAM_ISR_ERASE_DONE_SET(value,field)          (ARCHI_BINSERT((value),(field),1,0))
#define UDMA_MRAM_ISR_ERASE_DONE(val)                      ((val) << 0)

#define UDMA_MRAM_ISR_PROGRAM_DONE_GET(value)              (ARCHI_BEXTRACTU((value),1,1))
#define UDMA_MRAM_ISR_PROGRAM_DONE_GETS(value)             (ARCHI_BEXTRACT((value),1,1))
#define UDMA_MRAM_ISR_PROGRAM_DONE_SET(value,field)        (ARCHI_BINSERT((value),(field),1,1))
#define UDMA_MRAM_ISR_PROGRAM_DONE(val)                    ((val) << 1)

#define UDMA_MRAM_ISR_TRIM_CFG_DONE_GET(value)             (ARCHI_BEXTRACTU((value),1,2))
#define UDMA_MRAM_ISR_TRIM_CFG_DONE_GETS(value)            (ARCHI_BEXTRACT((value),1,2))
#define UDMA_MRAM_ISR_TRIM_CFG_DONE_SET(value,field)       (ARCHI_BINSERT((value),(field),1,2))
#define UDMA_MRAM_ISR_TRIM_CFG_DONE(val)                   ((val) << 2)

#define UDMA_MRAM_ISR_REF_LINE_DONE_GET(value)             (ARCHI_BEXTRACTU((value),1,3))
#define UDMA_MRAM_ISR_REF_LINE_DONE_GETS(value)            (ARCHI_BEXTRACT((value),1,3))
#define UDMA_MRAM_ISR_REF_LINE_DONE_SET(value,field)       (ARCHI_BINSERT((value),(field),1,3))
#define UDMA_MRAM_ISR_REF_LINE_DONE(val)                   ((val) << 3)

#define UDMA_MRAM_IER_ERASE_EN_GET(value)                  (ARCHI_BEXTRACTU((value),1,0))
#define UDMA_MRAM_IER_ERASE_EN_GETS(value)                 (ARCHI_BEXTRACT((value),1,0))
#define UDMA_MRAM_IER_ERASE_EN_SET(value,field)            (ARCHI_BINSERT((value),(field),1,0))
#define UDMA_MRAM_IER_ERASE_EN(val)                        ((val) << 0)

#define UDMA_MRAM_IER_PROGRAM_EN_GET(value)                (ARCHI_BEXTRACTU((value),1,1))
#define UDMA_MRAM_IER_PROGRAM_EN_GETS(value)               (ARCHI_BEXTRACT((value),1,1))
#define UDMA_MRAM_IER_PROGRAM_EN_SET(value,field)          (ARCHI_BINSERT((value),(field),1,1))
#define UDMA_MRAM_IER_PROGRAM_EN(val)                      ((val) << 1)

#define UDMA_MRAM_IER_TRIM_CFG_EN_GET(value)               (ARCHI_BEXTRACTU((value),1,2))
#define UDMA_MRAM_IER_TRIM_CFG_EN_GETS(value)              (ARCHI_BEXTRACT((value),1,2))
#define UDMA_MRAM_IER_TRIM_CFG_EN_SET(value,field)         (ARCHI_BINSERT((value),(field),1,2))
#define UDMA_MRAM_IER_TRIM_CFG_EN(val)                     ((val) << 2)

#define UDMA_MRAM_IER_REF_LINE_EN_GET(value)               (ARCHI_BEXTRACTU((value),1,3))
#define UDMA_MRAM_IER_REF_LINE_EN_GETS(value)              (ARCHI_BEXTRACT((value),1,3))
#define UDMA_MRAM_IER_REF_LINE_EN_SET(value,field)         (ARCHI_BINSERT((value),(field),1,3))
#define UDMA_MRAM_IER_REF_LINE_EN(val)                     ((val) << 3)

#define UDMA_MRAM_ICR_ERASE_DONE_GET(value)                (ARCHI_BEXTRACTU((value),1,0))
#define UDMA_MRAM_ICR_ERASE_DONE_GETS(value)               (ARCHI_BEXTRACT((value),1,0))
#define UDMA_MRAM_ICR_ERASE_DONE_SET(value,field)          (ARCHI_BINSERT((value),(field),1,0))
#define UDMA_MRAM_ICR_ERASE_DONE(val)                      ((val) << 0)

#define UDMA_MRAM_ICR_PROGRAM_DONE_GET(value)              (ARCHI_BEXTRACTU((value),1,1))
#define UDMA_MRAM_ICR_PROGRAM_DONE_GETS(value)             (ARCHI_BEXTRACT((value),1,1))
#define UDMA_MRAM_ICR_PROGRAM_DONE_SET(value,field)        (ARCHI_BINSERT((value),(field),1,1))
#define UDMA_MRAM_ICR_PROGRAM_DONE(val)                    ((val) << 1)

#define UDMA_MRAM_ICR_TRIM_CFG_DONE_GET(value)             (ARCHI_BEXTRACTU((value),1,2))
#define UDMA_MRAM_ICR_TRIM_CFG_DONE_GETS(value)            (ARCHI_BEXTRACT((value),1,2))
#define UDMA_MRAM_ICR_TRIM_CFG_DONE_SET(value,field)       (ARCHI_BINSERT((value),(field),1,2))
#define UDMA_MRAM_ICR_TRIM_CFG_DONE(val)                   ((val) << 2)

#define UDMA_MRAM_ICR_REF_LINE_DONE_GET(value)             (ARCHI_BEXTRACTU((value),1,3))
#define UDMA_MRAM_ICR_REF_LINE_DONE_GETS(value)            (ARCHI_BEXTRACT((value),1,3))
#define UDMA_MRAM_ICR_REF_LINE_DONE_SET(value,field)       (ARCHI_BINSERT((value),(field),1,3))
#define UDMA_MRAM_ICR_REF_LINE_DONE(val)                   ((val) << 3)

#endif

#endif
