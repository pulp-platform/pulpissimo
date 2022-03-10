
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

#ifndef __INCLUDE_ARCHI_UDMA_HYPER_UDMA_HYPER_V2_H__
#define __INCLUDE_ARCHI_UDMA_HYPER_UDMA_HYPER_V2_H__

#ifndef LANGUAGE_ASSEMBLY

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS
//

// uDMA RX HYPERBUS buffer base address configuration register.
#define HYPER_RX_SADDR_OFFSET                    0x0

// uDMA RX HYPERBUS buffer size configuration register.
#define HYPER_RX_SIZE_OFFSET                     0x4

// uDMA RX HYPERBUS stream configuration register.
#define HYPER_RX_CFG_OFFSET                      0x8

// uDMA TX HYPERBUS buffer base address configuration register.
#define HYPER_TX_SADDR_OFFSET                    0x10

// uDMA TX HYPERBUS buffer size configuration register.
#define HYPER_TX_SIZE_OFFSET                     0x14

// uDMA TX HYPERBUS stream configuration register.
#define HYPER_TX_CFG_OFFSET                      0x18

// Memory access address register.
#define HYPER_EXT_ADDR_OFFSET                    0x20

// HYPERBUS and Octo SPI Memory Timing configuration register.
#define HYPER_TIMING_CFG_OFFSET                  0x24

// Device start address register.
#define HYPER_MBA0_OFFSET                        0x28

// Device start address register.
#define HYPER_MBA1_OFFSET                        0x2c

// Device type register(RAM or FLASH).
#define HYPER_DEVICE_OFFSET                      0x30

// OSPI command
#define HYPER_OSPI_CMD_OFFSET                    0x34

// OSPI address
#define HYPER_OSPI_ADDR_OFFSET                   0x38

// OSPI configuration
#define HYPER_OSPI_CFG_OFFSET                    0x3c

// OSPI chip select configuration
#define HYPER_OSPI_CSN_OFFSET                    0x40

// -
#define HYPER__RESERVED0_OFFSET                  0x44

// -
#define HYPER__RESERVED1_OFFSET                  0x48

// OSPI interrupt enable register
#define HYPER_IRQ_EN_OFFSET                      0x4c

// Clock divide.
#define HYPER_CLK_DIV_OFFSET                     0x50

// Transfer status for error.
#define HYPER_STATUS_OFFSET                      0x54



//
// REGISTERS FIELDS
//

// RX buffer base address bitfield: - Read: returns value of the buffer pointer until transfer is finished. Else returns 0. - Write: sets RX buffer base address (access: R/W)
#define HYPER_RX_SADDR_RX_SADDR_BIT                                  0
#define HYPER_RX_SADDR_RX_SADDR_WIDTH                                16
#define HYPER_RX_SADDR_RX_SADDR_MASK                                 0xffff

// RX buffer size bitfield in bytes. (128kBytes maximum) - Read: returns remaining buffer size to transfer. - Write: sets buffer size. (access: R/W)
#define HYPER_RX_SIZE_RX_SIZE_BIT                                    0
#define HYPER_RX_SIZE_RX_SIZE_WIDTH                                  17
#define HYPER_RX_SIZE_RX_SIZE_MASK                                   0x1ffff

// RX channel continuous mode bitfield: -1'b0: disabled -1'b1: enabled At the end of the buffer transfer, the uDMA reloads the address / buffer size and starts a new transfer. (access: R/W)
#define HYPER_RX_CFG_CONTINOUS_BIT                                   0
#define HYPER_RX_CFG_CONTINOUS_WIDTH                                 1
#define HYPER_RX_CFG_CONTINOUS_MASK                                  0x1

// RX channel enable and start transfer bitfield: -1'b0: disable -1'b1: enable and start the transfer This signal is used also to queue a transfer if one is already ongoing. (access: R/W)
#define HYPER_RX_CFG_EN_BIT                                          4
#define HYPER_RX_CFG_EN_WIDTH                                        1
#define HYPER_RX_CFG_EN_MASK                                         0x10

// RX transfer pending in queue status flag: -1'b0: no pending transfer in the queue -1'b1: pending transfer in the queue (access: R)
#define HYPER_RX_CFG_PENDING_BIT                                     5
#define HYPER_RX_CFG_PENDING_WIDTH                                   1
#define HYPER_RX_CFG_PENDING_MASK                                    0x20

// RX channel clear and stop transfer: -1'b0: disable -1'b1: stop and clear the on-going transfer (access: W)
#define HYPER_RX_CFG_CLR_BIT                                         6
#define HYPER_RX_CFG_CLR_WIDTH                                       1
#define HYPER_RX_CFG_CLR_MASK                                        0x40

// TX buffer base address bitfield: - Read: returns value of the buffer pointer until transfer is finished. Else returns 0. - Write: sets buffer base address (access: R/W)
#define HYPER_TX_SADDR_TX_SADDR_BIT                                  0
#define HYPER_TX_SADDR_TX_SADDR_WIDTH                                16
#define HYPER_TX_SADDR_TX_SADDR_MASK                                 0xffff

// TX buffer size bitfield in bytes. (128kBytes maximum) - Read: returns remaining buffer size to transfer. - Write: sets buffer size. (access: R/W)
#define HYPER_TX_SIZE_TX_SIZE_BIT                                    0
#define HYPER_TX_SIZE_TX_SIZE_WIDTH                                  17
#define HYPER_TX_SIZE_TX_SIZE_MASK                                   0x1ffff

// TX channel continuous mode bitfield: -1'b0: disabled -1'b1: enabled At the end of the buffer transfer, the uDMA reloads the address / buffer size and starts a new transfer. (access: R/W)
#define HYPER_TX_CFG_CONTINOUS_BIT                                   0
#define HYPER_TX_CFG_CONTINOUS_WIDTH                                 1
#define HYPER_TX_CFG_CONTINOUS_MASK                                  0x1

// TX channel enable and start transfer bitfield: -1'b0: disabled -1'b1: enable and start the transfer This signal is used also to queue a transfer if one is already ongoing. (access: R/W)
#define HYPER_TX_CFG_EN_BIT                                          4
#define HYPER_TX_CFG_EN_WIDTH                                        1
#define HYPER_TX_CFG_EN_MASK                                         0x10

// TX transfer pending in queue status flag: -1'b0: no pending transfer in the queue -1'b1: pending transfer in the queue (access: R)
#define HYPER_TX_CFG_PENDING_BIT                                     5
#define HYPER_TX_CFG_PENDING_WIDTH                                   1
#define HYPER_TX_CFG_PENDING_MASK                                    0x20

// TX channel clear and stop transfer bitfield: -1'b0: disabled -1'b1: stop and clear the on-going transfer (access: W)
#define HYPER_TX_CFG_CLR_BIT                                         6
#define HYPER_TX_CFG_CLR_WIDTH                                       1
#define HYPER_TX_CFG_CLR_MASK                                        0x40

// Memory access address bitfield. (access: R/W)
#define HYPER_EXT_ADDR_SADDR_BIT                                     0
#define HYPER_EXT_ADDR_SADDR_WIDTH                                   31
#define HYPER_EXT_ADDR_SADDR_MASK                                    0x7fffffff

// Register access flag bitfield. (access: R/W)
#define HYPER_EXT_ADDR_REG_ACCESS_BIT                                31
#define HYPER_EXT_ADDR_REG_ACCESS_WIDTH                              1
#define HYPER_EXT_ADDR_REG_ACCESS_MASK                               0x80000000

// Latency Cycle value for both HyperRAM and HyperFLASH for chip select 0. When using HyperRAM memory, this bit should be set to the same value as the read latency in configuration register of HyperRAM memory the read latency in configuration register of HyperRAM memory. For SPI, is the dummy cycle after ADDRESS stage : - 4'b0000: 16 CK - 4'b0001: 1 CK - 4'b0001: 2 CK ... - 4'b1111: 15 CK (access: R/W)
#define HYPER_TIMING_CFG_LATENCY0_BIT                                0
#define HYPER_TIMING_CFG_LATENCY0_WIDTH                              5
#define HYPER_TIMING_CFG_LATENCY0_MASK                               0x1f

// Latency Cycle value for both HyperRAM and HyperFLASH for chip select 1. When using HyperRAM memory, this bit should be set to the same value as the read latency in configuration register of HyperRAM memory the read latency in configuration register of HyperRAM memory. For SPI, is the dummy cycle after ADDRESS stage : - 5'b00000: 0 CK - 5'b00001: 1 CK - 5'b000001: 2 CK ... - 5'b11111: 31 CK (access: R/W)
#define HYPER_TIMING_CFG_LATENCY1_BIT                                5
#define HYPER_TIMING_CFG_LATENCY1_WIDTH                              5
#define HYPER_TIMING_CFG_LATENCY1_MASK                               0x3e0

// Some HyperBus devices may require a minimum time between the end of a prior transaction and the start of a new access. This time is referred to as Read-Write-Recovery time (tRWR). The master interface must start driving CS# Low only at a time when the CA1 transfer will complete after tRWR is satisfied. - 5'b00000: 0 CK - 5'b00001: 1 CK - 5'b000001: 2 CK ... - 5'b11111: 31 CK (access: R/W)
#define HYPER_TIMING_CFG_RW_RECOVERY_BIT                             10
#define HYPER_TIMING_CFG_RW_RECOVERY_WIDTH                           4
#define HYPER_TIMING_CFG_RW_RECOVERY_MASK                            0x3c00

// Delay of RWDS for center aligned read: - 3'b000: 0 logic delay - 3'b001: 1 logic delay - 3'b010: 2 logic delay  - 3'b111: 7 logic delay (access: R/W)
#define HYPER_TIMING_CFG_RWDS_DELAY_BIT                              14
#define HYPER_TIMING_CFG_RWDS_DELAY_WIDTH                            3
#define HYPER_TIMING_CFG_RWDS_DELAY_MASK                             0x1c000

// Auto check for RWDS high or low for additional latency : - 1'b0: additional latency no autocheck - 1'b1: additional latency autocheck (access: R/W)
#define HYPER_TIMING_CFG_ADDITIONAL_LATENCY_AUTOCHECK_EN_BIT         17
#define HYPER_TIMING_CFG_ADDITIONAL_LATENCY_AUTOCHECK_EN_WIDTH       1
#define HYPER_TIMING_CFG_ADDITIONAL_LATENCY_AUTOCHECK_EN_MASK        0x20000

// Maximum chip select low time for self-refresh HYPERRAM to valid the data transfer : - 14'h0000: 1 CK - 14'h0001: 2 CK - 14'h0011: 3 CK -  - 14'h3FFF: 16383 CK (access: R/W)
#define HYPER_TIMING_CFG_CS_MAX_BIT                                  18
#define HYPER_TIMING_CFG_CS_MAX_WIDTH                                16
#define HYPER_TIMING_CFG_CS_MAX_MASK                                 0x3fffc0000

// Memory Base Address 0 for both RAM and FLASH bitfield. The base address of addressable region to each memory is set up. Since register can be set in 16M bytes boundary, lower 24 bit is fixed to 0. MBA0 can be greater than MBA1, the chip select which decided by the relationship among MBA0, MBA1, and EXT_ADDR.  - MBA0 < MBA1, if (MBA1 <= EXT_ADDR) CS1 = 0;  else CS0 = 0; - MBA0 > MBA1, if (MBA0 <= EXT_ADDR) CS0 = 0;  else CS1 = 0; (access: R/W)
#define HYPER_MBA0_MBA0_BIT                                          24
#define HYPER_MBA0_MBA0_WIDTH                                        7
#define HYPER_MBA0_MBA0_MASK                                         0x7f000000

// Memory Base Address  for both RAM and FLASH bitfield. The base address of addressable region to each memory is set up. Since register can be set in 16M bytes boundary, lower 24 bit is fixed to 0. MBA0 can be greater than MBA1, the chip select which decided by the relationship among MBA0, MBA1, and EXT_ADDR.  - MBA0 < MBA1, if (MBA1 <= EXT_ADDR) CSn1 = 0;  else CSn0 = 0; - MBA0 > MBA1, if (MBA0 <= EXT_ADDR) CSn0 = 0;  else CSn1 = 0; (access: R/W)
#define HYPER_MBA1_MBA1_BIT                                          24
#define HYPER_MBA1_MBA1_WIDTH                                        7
#define HYPER_MBA1_MBA1_MASK                                         0x7f000000

// Device type : - 1'b00: Octo/ Single SPI - 1'b01: HYPERBUS (access: R/W)
#define HYPER_DEVICE_TYPE_BIT                                        0
#define HYPER_DEVICE_TYPE_WIDTH                                      1
#define HYPER_DEVICE_TYPE_MASK                                       0x1

// When in HYPERBUS mode :  - 1'b0: HYPERRAM -  1'b1: HYPERLASH (access: R/W)
#define HYPER_DEVICE_DT0_BIT                                         1
#define HYPER_DEVICE_DT0_WIDTH                                       1
#define HYPER_DEVICE_DT0_MASK                                        0x2

// When in HYPERBUS mode :  - 1'b0: HYPERRAM -  1'b1: HYPERLASH (access: R/W)
#define HYPER_DEVICE_DT1_BIT                                         2
#define HYPER_DEVICE_DT1_WIDTH                                       1
#define HYPER_DEVICE_DT1_MASK                                        0x4

// Octo SPI command size :  - 2b0: 0 byte -  2'b1: 1 byte -  2'b2: 2 byte (access: R/W)
#define HYPER_OSPI_CFG_CMD_SIZE_BIT                                  0
#define HYPER_OSPI_CFG_CMD_SIZE_WIDTH                                2
#define HYPER_OSPI_CFG_CMD_SIZE_MASK                                 0x3

// Octo SPI address size :  - 3'b000: 0 byte (Jump ADDRESS stage) -  3'b001: 1 byte -  3'b010: 2 byte -  3'b011: 3 byte -  3'b100: 4 byte (access: R/W)
#define HYPER_OSPI_CFG_ADDR_SIZE_BIT                                 4
#define HYPER_OSPI_CFG_ADDR_SIZE_WIDTH                               3
#define HYPER_OSPI_CFG_ADDR_SIZE_MASK                                0x70

// Octo SPI line number for Single SPI or Octo SPI:  - 1'b0: 8 line for Octo SPI -  1'b1: 1 line for Single SPI (SI : dq[0] SO: dq[1]) (access: R/W)
#define HYPER_OSPI_CFG_LINE_BIT                                      8
#define HYPER_OSPI_CFG_LINE_WIDTH                                    1
#define HYPER_OSPI_CFG_LINE_MASK                                     0x100

// Octo SPI command ddr mode or single mode :  - 1'b0: DTR mode -  1'b1: STR mode (access: R/W)
#define HYPER_OSPI_CFG_CMD_DTR_STR_BIT                               12
#define HYPER_OSPI_CFG_CMD_DTR_STR_WIDTH                             1
#define HYPER_OSPI_CFG_CMD_DTR_STR_MASK                              0x1000

// Octo SPI address ddr mode or single mode :  - 1'b0: DTR mode -  1'b1: STR mode (access: R/W)
#define HYPER_OSPI_CFG_ADDR_DTR_STR_BIT                              13
#define HYPER_OSPI_CFG_ADDR_DTR_STR_WIDTH                            1
#define HYPER_OSPI_CFG_ADDR_DTR_STR_MASK                             0x2000

// Octo SPI data ddr mode or single mode :  - 1'b0: DTR mode -  1'b1: STR mode (access: R/W)
#define HYPER_OSPI_CFG_DATA_DTR_STR_BIT                              14
#define HYPER_OSPI_CFG_DATA_DTR_STR_WIDTH                            1
#define HYPER_OSPI_CFG_DATA_DTR_STR_MASK                             0x4000

// Octo SPI data ddr mode data MSB:  - 1'b0: LSB -  1'b1: MSB (access: R/W)
#define HYPER_OSPI_CFG_DATA_DTR_MSB_BIT                              15
#define HYPER_OSPI_CFG_DATA_DTR_MSB_WIDTH                            1
#define HYPER_OSPI_CFG_DATA_DTR_MSB_MASK                             0x8000

// Octo SPI chip select index :  - 1'b0: CSN0 -  1'b1: CSN1 (access: R/W)
#define HYPER_OSPI_CSN_INDEX_BIT                                     0
#define HYPER_OSPI_CSN_INDEX_WIDTH                                   1
#define HYPER_OSPI_CSN_INDEX_MASK                                    0x1

// Octo SPI chip select controlled by user  :  - 1'b0: IP control CSN -  1'b1: USER control CSN (access: R/W)
#define HYPER_OSPI_CSN_USER_CTRL_CSN_BIT                             4
#define HYPER_OSPI_CSN_USER_CTRL_CSN_WIDTH                           1
#define HYPER_OSPI_CSN_USER_CTRL_CSN_MASK                            0x10

// Octo SPI chip select user control value :  - 1'b0: CSN low -  1'b1: CSN high (access: R/W)
#define HYPER_OSPI_CSN_CSN_VAL_BIT                                   5
#define HYPER_OSPI_CSN_CSN_VAL_WIDTH                                 1
#define HYPER_OSPI_CSN_CSN_VAL_MASK                                  0x20

// Octo SPI interrupt enable control :  - 1'b0: interrupt disable -  1'b1: Interrupt enable  (access: R/W)
#define HYPER_IRQ_EN_EN_BIT                                          0
#define HYPER_IRQ_EN_EN_WIDTH                                        1
#define HYPER_IRQ_EN_EN_MASK                                         0x1

// Clock divide data, form 0  255, frequency divide table is : -8h0  IO_FREQUENCY / 1 -8h1  IO_FREQUENCY / 2 -8h2  IO_FREQUENCY / 4   (access: R/W)
#define HYPER_CLK_DIV_DATA_BIT                                       0
#define HYPER_CLK_DIV_DATA_WIDTH                                     8
#define HYPER_CLK_DIV_DATA_MASK                                      0xff

// Clock divide valid, user can not control. Every time there is clock divide write access, set 1 by default, then when clock divide is finished, set 0.  (access: W)
#define HYPER_CLK_DIV_VALID_BIT                                      8
#define HYPER_CLK_DIV_VALID_WIDTH                                    1
#define HYPER_CLK_DIV_VALID_MASK                                     0x100

// TX transfer error because of tcsm, write 1 to clear: - 1'b0: no error - 1'b1: error (access: R/W)
#define HYPER_STATUS_TX_ERROR_BIT                                    0
#define HYPER_STATUS_TX_ERROR_WIDTH                                  1
#define HYPER_STATUS_TX_ERROR_MASK                                   0x1

// RX transfer error because of tcsm, write 1 to clear: - 1'b0: no error - 1'b1: error (access: R/W)
#define HYPER_STATUS_RX_ERROR_BIT                                    1
#define HYPER_STATUS_RX_ERROR_WIDTH                                  1
#define HYPER_STATUS_RX_ERROR_MASK                                   0x2

// RX TX transfer end flag, can be polling by user, write 1 to clear: - 1'b0: not end - 1'b1: end (access: R/W)
#define HYPER_STATUS_RX_TX_END_BIT                                   2
#define HYPER_STATUS_RX_TX_END_WIDTH                                 1
#define HYPER_STATUS_RX_TX_END_MASK                                  0x4



//
// REGISTERS STRUCTS
//

#ifndef LANGUAGE_ASSEMBLY

typedef union {
  struct {
    unsigned int rx_saddr        :16; // RX buffer base address bitfield: - Read: returns value of the buffer pointer until transfer is finished. Else returns 0. - Write: sets RX buffer base address
  };
  unsigned int raw;
} __attribute__((packed)) hyper_rx_saddr_t;

typedef union {
  struct {
    unsigned int rx_size         :17; // RX buffer size bitfield in bytes. (128kBytes maximum) - Read: returns remaining buffer size to transfer. - Write: sets buffer size.
  };
  unsigned int raw;
} __attribute__((packed)) hyper_rx_size_t;

typedef union {
  struct {
    unsigned int continous       :1 ; // RX channel continuous mode bitfield: -1'b0: disabled -1'b1: enabled At the end of the buffer transfer, the uDMA reloads the address / buffer size and starts a new transfer.
    unsigned int padding0:3 ;
    unsigned int en              :1 ; // RX channel enable and start transfer bitfield: -1'b0: disable -1'b1: enable and start the transfer This signal is used also to queue a transfer if one is already ongoing.
    unsigned int pending         :1 ; // RX transfer pending in queue status flag: -1'b0: no pending transfer in the queue -1'b1: pending transfer in the queue
    unsigned int clr             :1 ; // RX channel clear and stop transfer: -1'b0: disable -1'b1: stop and clear the on-going transfer
  };
  unsigned int raw;
} __attribute__((packed)) hyper_rx_cfg_t;

typedef union {
  struct {
    unsigned int tx_saddr        :16; // TX buffer base address bitfield: - Read: returns value of the buffer pointer until transfer is finished. Else returns 0. - Write: sets buffer base address
  };
  unsigned int raw;
} __attribute__((packed)) hyper_tx_saddr_t;

typedef union {
  struct {
    unsigned int tx_size         :17; // TX buffer size bitfield in bytes. (128kBytes maximum) - Read: returns remaining buffer size to transfer. - Write: sets buffer size.
  };
  unsigned int raw;
} __attribute__((packed)) hyper_tx_size_t;

typedef union {
  struct {
    unsigned int continous       :1 ; // TX channel continuous mode bitfield: -1'b0: disabled -1'b1: enabled At the end of the buffer transfer, the uDMA reloads the address / buffer size and starts a new transfer.
    unsigned int padding0:3 ;
    unsigned int en              :1 ; // TX channel enable and start transfer bitfield: -1'b0: disabled -1'b1: enable and start the transfer This signal is used also to queue a transfer if one is already ongoing.
    unsigned int pending         :1 ; // TX transfer pending in queue status flag: -1'b0: no pending transfer in the queue -1'b1: pending transfer in the queue
    unsigned int clr             :1 ; // TX channel clear and stop transfer bitfield: -1'b0: disabled -1'b1: stop and clear the on-going transfer
  };
  unsigned int raw;
} __attribute__((packed)) hyper_tx_cfg_t;

typedef union {
  struct {
    unsigned int saddr           :31; // Memory access address bitfield.
    unsigned int reg_access      :1 ; // Register access flag bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) hyper_ext_addr_t;

typedef union {
  struct {
    unsigned int latency0        :5 ; // Latency Cycle value for both HyperRAM and HyperFLASH for chip select 0. When using HyperRAM memory, this bit should be set to the same value as the read latency in configuration register of HyperRAM memory the read latency in configuration register of HyperRAM memory. For SPI, is the dummy cycle after ADDRESS stage : - 4'b0000: 16 CK - 4'b0001: 1 CK - 4'b0001: 2 CK ... - 4'b1111: 15 CK
    unsigned int latency1        :5 ; // Latency Cycle value for both HyperRAM and HyperFLASH for chip select 1. When using HyperRAM memory, this bit should be set to the same value as the read latency in configuration register of HyperRAM memory the read latency in configuration register of HyperRAM memory. For SPI, is the dummy cycle after ADDRESS stage : - 5'b00000: 0 CK - 5'b00001: 1 CK - 5'b000001: 2 CK ... - 5'b11111: 31 CK
    unsigned int rw_recovery     :4 ; // Some HyperBus devices may require a minimum time between the end of a prior transaction and the start of a new access. This time is referred to as Read-Write-Recovery time (tRWR). The master interface must start driving CS# Low only at a time when the CA1 transfer will complete after tRWR is satisfied. - 5'b00000: 0 CK - 5'b00001: 1 CK - 5'b000001: 2 CK ... - 5'b11111: 31 CK
    unsigned int rwds_delay      :3 ; // Delay of RWDS for center aligned read: - 3'b000: 0 logic delay - 3'b001: 1 logic delay - 3'b010: 2 logic delay  - 3'b111: 7 logic delay
    unsigned int additional_latency_autocheck_en:1 ; // Auto check for RWDS high or low for additional latency : - 1'b0: additional latency no autocheck - 1'b1: additional latency autocheck
    unsigned int cs_max          :16; // Maximum chip select low time for self-refresh HYPERRAM to valid the data transfer : - 14'h0000: 1 CK - 14'h0001: 2 CK - 14'h0011: 3 CK -  - 14'h3FFF: 16383 CK
  };
  unsigned int raw;
} __attribute__((packed)) hyper_timing_cfg_t;

typedef union {
  struct {
    unsigned int padding0:24;
    unsigned int mba0            :7 ; // Memory Base Address 0 for both RAM and FLASH bitfield. The base address of addressable region to each memory is set up. Since register can be set in 16M bytes boundary, lower 24 bit is fixed to 0. MBA0 can be greater than MBA1, the chip select which decided by the relationship among MBA0, MBA1, and EXT_ADDR.  - MBA0 < MBA1, if (MBA1 <= EXT_ADDR) CS1 = 0;  else CS0 = 0; - MBA0 > MBA1, if (MBA0 <= EXT_ADDR) CS0 = 0;  else CS1 = 0;
  };
  unsigned int raw;
} __attribute__((packed)) hyper_mba0_t;

typedef union {
  struct {
    unsigned int padding0:24;
    unsigned int mba1            :7 ; // Memory Base Address  for both RAM and FLASH bitfield. The base address of addressable region to each memory is set up. Since register can be set in 16M bytes boundary, lower 24 bit is fixed to 0. MBA0 can be greater than MBA1, the chip select which decided by the relationship among MBA0, MBA1, and EXT_ADDR.  - MBA0 < MBA1, if (MBA1 <= EXT_ADDR) CSn1 = 0;  else CSn0 = 0; - MBA0 > MBA1, if (MBA0 <= EXT_ADDR) CSn0 = 0;  else CSn1 = 0;
  };
  unsigned int raw;
} __attribute__((packed)) hyper_mba1_t;

typedef union {
  struct {
    unsigned int type            :1 ; // Device type : - 1'b00: Octo/ Single SPI - 1'b01: HYPERBUS
    unsigned int dt0             :1 ; // When in HYPERBUS mode :  - 1'b0: HYPERRAM -  1'b1: HYPERLASH
    unsigned int dt1             :1 ; // When in HYPERBUS mode :  - 1'b0: HYPERRAM -  1'b1: HYPERLASH
  };
  unsigned int raw;
} __attribute__((packed)) hyper_device_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hyper_ospi_cmd_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hyper_ospi_addr_t;

typedef union {
  struct {
    unsigned int cmd_size        :2 ; // Octo SPI command size :  - 2b0: 0 byte -  2'b1: 1 byte -  2'b2: 2 byte
    unsigned int padding0:2 ;
    unsigned int addr_size       :3 ; // Octo SPI address size :  - 3'b000: 0 byte (Jump ADDRESS stage) -  3'b001: 1 byte -  3'b010: 2 byte -  3'b011: 3 byte -  3'b100: 4 byte
    unsigned int padding1:1 ;
    unsigned int line            :1 ; // Octo SPI line number for Single SPI or Octo SPI:  - 1'b0: 8 line for Octo SPI -  1'b1: 1 line for Single SPI (SI : dq[0] SO: dq[1])
    unsigned int padding2:3 ;
    unsigned int cmd_dtr_str     :1 ; // Octo SPI command ddr mode or single mode :  - 1'b0: DTR mode -  1'b1: STR mode
    unsigned int addr_dtr_str    :1 ; // Octo SPI address ddr mode or single mode :  - 1'b0: DTR mode -  1'b1: STR mode
    unsigned int data_dtr_str    :1 ; // Octo SPI data ddr mode or single mode :  - 1'b0: DTR mode -  1'b1: STR mode
    unsigned int data_dtr_msb    :1 ; // Octo SPI data ddr mode data MSB:  - 1'b0: LSB -  1'b1: MSB
  };
  unsigned int raw;
} __attribute__((packed)) hyper_ospi_cfg_t;

typedef union {
  struct {
    unsigned int index           :1 ; // Octo SPI chip select index :  - 1'b0: CSN0 -  1'b1: CSN1
    unsigned int padding0:3 ;
    unsigned int user_ctrl_csn   :1 ; // Octo SPI chip select controlled by user  :  - 1'b0: IP control CSN -  1'b1: USER control CSN
    unsigned int csn_val         :1 ; // Octo SPI chip select user control value :  - 1'b0: CSN low -  1'b1: CSN high
  };
  unsigned int raw;
} __attribute__((packed)) hyper_ospi_csn_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hyper__reserved0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hyper__reserved1_t;

typedef union {
  struct {
    unsigned int en              :1 ; // Octo SPI interrupt enable control :  - 1'b0: interrupt disable -  1'b1: Interrupt enable 
  };
  unsigned int raw;
} __attribute__((packed)) hyper_irq_en_t;

typedef union {
  struct {
    unsigned int data            :8 ; // Clock divide data, form 0  255, frequency divide table is : -8h0  IO_FREQUENCY / 1 -8h1  IO_FREQUENCY / 2 -8h2  IO_FREQUENCY / 4  
    unsigned int valid           :1 ; // Clock divide valid, user can not control. Every time there is clock divide write access, set 1 by default, then when clock divide is finished, set 0. 
  };
  unsigned int raw;
} __attribute__((packed)) hyper_clk_div_t;

typedef union {
  struct {
    unsigned int tx_error        :1 ; // TX transfer error because of tcsm, write 1 to clear: - 1'b0: no error - 1'b1: error
    unsigned int rx_error        :1 ; // RX transfer error because of tcsm, write 1 to clear: - 1'b0: no error - 1'b1: error
    unsigned int rx_tx_end       :1 ; // RX TX transfer end flag, can be polling by user, write 1 to clear: - 1'b0: not end - 1'b1: end
  };
  unsigned int raw;
} __attribute__((packed)) hyper_status_t;

#endif



//
// REGISTERS STRUCTS
//

#ifdef __GVSOC__

class vp_hyper_rx_saddr : public vp::reg_32
{
public:
  inline void rx_saddr_set(uint32_t value) { this->set_field(value, HYPER_RX_SADDR_RX_SADDR_BIT, HYPER_RX_SADDR_RX_SADDR_WIDTH); }
  inline uint32_t rx_saddr_get() { return this->get_field(HYPER_RX_SADDR_RX_SADDR_BIT, HYPER_RX_SADDR_RX_SADDR_WIDTH); }
};

class vp_hyper_rx_size : public vp::reg_32
{
public:
  inline void rx_size_set(uint32_t value) { this->set_field(value, HYPER_RX_SIZE_RX_SIZE_BIT, HYPER_RX_SIZE_RX_SIZE_WIDTH); }
  inline uint32_t rx_size_get() { return this->get_field(HYPER_RX_SIZE_RX_SIZE_BIT, HYPER_RX_SIZE_RX_SIZE_WIDTH); }
};

class vp_hyper_rx_cfg : public vp::reg_32
{
public:
  inline void continous_set(uint32_t value) { this->set_field(value, HYPER_RX_CFG_CONTINOUS_BIT, HYPER_RX_CFG_CONTINOUS_WIDTH); }
  inline uint32_t continous_get() { return this->get_field(HYPER_RX_CFG_CONTINOUS_BIT, HYPER_RX_CFG_CONTINOUS_WIDTH); }
  inline void en_set(uint32_t value) { this->set_field(value, HYPER_RX_CFG_EN_BIT, HYPER_RX_CFG_EN_WIDTH); }
  inline uint32_t en_get() { return this->get_field(HYPER_RX_CFG_EN_BIT, HYPER_RX_CFG_EN_WIDTH); }
  inline void pending_set(uint32_t value) { this->set_field(value, HYPER_RX_CFG_PENDING_BIT, HYPER_RX_CFG_PENDING_WIDTH); }
  inline uint32_t pending_get() { return this->get_field(HYPER_RX_CFG_PENDING_BIT, HYPER_RX_CFG_PENDING_WIDTH); }
  inline void clr_set(uint32_t value) { this->set_field(value, HYPER_RX_CFG_CLR_BIT, HYPER_RX_CFG_CLR_WIDTH); }
  inline uint32_t clr_get() { return this->get_field(HYPER_RX_CFG_CLR_BIT, HYPER_RX_CFG_CLR_WIDTH); }
};

class vp_hyper_tx_saddr : public vp::reg_32
{
public:
  inline void tx_saddr_set(uint32_t value) { this->set_field(value, HYPER_TX_SADDR_TX_SADDR_BIT, HYPER_TX_SADDR_TX_SADDR_WIDTH); }
  inline uint32_t tx_saddr_get() { return this->get_field(HYPER_TX_SADDR_TX_SADDR_BIT, HYPER_TX_SADDR_TX_SADDR_WIDTH); }
};

class vp_hyper_tx_size : public vp::reg_32
{
public:
  inline void tx_size_set(uint32_t value) { this->set_field(value, HYPER_TX_SIZE_TX_SIZE_BIT, HYPER_TX_SIZE_TX_SIZE_WIDTH); }
  inline uint32_t tx_size_get() { return this->get_field(HYPER_TX_SIZE_TX_SIZE_BIT, HYPER_TX_SIZE_TX_SIZE_WIDTH); }
};

class vp_hyper_tx_cfg : public vp::reg_32
{
public:
  inline void continous_set(uint32_t value) { this->set_field(value, HYPER_TX_CFG_CONTINOUS_BIT, HYPER_TX_CFG_CONTINOUS_WIDTH); }
  inline uint32_t continous_get() { return this->get_field(HYPER_TX_CFG_CONTINOUS_BIT, HYPER_TX_CFG_CONTINOUS_WIDTH); }
  inline void en_set(uint32_t value) { this->set_field(value, HYPER_TX_CFG_EN_BIT, HYPER_TX_CFG_EN_WIDTH); }
  inline uint32_t en_get() { return this->get_field(HYPER_TX_CFG_EN_BIT, HYPER_TX_CFG_EN_WIDTH); }
  inline void pending_set(uint32_t value) { this->set_field(value, HYPER_TX_CFG_PENDING_BIT, HYPER_TX_CFG_PENDING_WIDTH); }
  inline uint32_t pending_get() { return this->get_field(HYPER_TX_CFG_PENDING_BIT, HYPER_TX_CFG_PENDING_WIDTH); }
  inline void clr_set(uint32_t value) { this->set_field(value, HYPER_TX_CFG_CLR_BIT, HYPER_TX_CFG_CLR_WIDTH); }
  inline uint32_t clr_get() { return this->get_field(HYPER_TX_CFG_CLR_BIT, HYPER_TX_CFG_CLR_WIDTH); }
};

class vp_hyper_ext_addr : public vp::reg_32
{
public:
  inline void saddr_set(uint32_t value) { this->set_field(value, HYPER_EXT_ADDR_SADDR_BIT, HYPER_EXT_ADDR_SADDR_WIDTH); }
  inline uint32_t saddr_get() { return this->get_field(HYPER_EXT_ADDR_SADDR_BIT, HYPER_EXT_ADDR_SADDR_WIDTH); }
  inline void reg_access_set(uint32_t value) { this->set_field(value, HYPER_EXT_ADDR_REG_ACCESS_BIT, HYPER_EXT_ADDR_REG_ACCESS_WIDTH); }
  inline uint32_t reg_access_get() { return this->get_field(HYPER_EXT_ADDR_REG_ACCESS_BIT, HYPER_EXT_ADDR_REG_ACCESS_WIDTH); }
};

class vp_hyper_timing_cfg : public vp::reg_32
{
public:
  inline void latency0_set(uint32_t value) { this->set_field(value, HYPER_TIMING_CFG_LATENCY0_BIT, HYPER_TIMING_CFG_LATENCY0_WIDTH); }
  inline uint32_t latency0_get() { return this->get_field(HYPER_TIMING_CFG_LATENCY0_BIT, HYPER_TIMING_CFG_LATENCY0_WIDTH); }
  inline void latency1_set(uint32_t value) { this->set_field(value, HYPER_TIMING_CFG_LATENCY1_BIT, HYPER_TIMING_CFG_LATENCY1_WIDTH); }
  inline uint32_t latency1_get() { return this->get_field(HYPER_TIMING_CFG_LATENCY1_BIT, HYPER_TIMING_CFG_LATENCY1_WIDTH); }
  inline void rw_recovery_set(uint32_t value) { this->set_field(value, HYPER_TIMING_CFG_RW_RECOVERY_BIT, HYPER_TIMING_CFG_RW_RECOVERY_WIDTH); }
  inline uint32_t rw_recovery_get() { return this->get_field(HYPER_TIMING_CFG_RW_RECOVERY_BIT, HYPER_TIMING_CFG_RW_RECOVERY_WIDTH); }
  inline void rwds_delay_set(uint32_t value) { this->set_field(value, HYPER_TIMING_CFG_RWDS_DELAY_BIT, HYPER_TIMING_CFG_RWDS_DELAY_WIDTH); }
  inline uint32_t rwds_delay_get() { return this->get_field(HYPER_TIMING_CFG_RWDS_DELAY_BIT, HYPER_TIMING_CFG_RWDS_DELAY_WIDTH); }
  inline void additional_latency_autocheck_en_set(uint32_t value) { this->set_field(value, HYPER_TIMING_CFG_ADDITIONAL_LATENCY_AUTOCHECK_EN_BIT, HYPER_TIMING_CFG_ADDITIONAL_LATENCY_AUTOCHECK_EN_WIDTH); }
  inline uint32_t additional_latency_autocheck_en_get() { return this->get_field(HYPER_TIMING_CFG_ADDITIONAL_LATENCY_AUTOCHECK_EN_BIT, HYPER_TIMING_CFG_ADDITIONAL_LATENCY_AUTOCHECK_EN_WIDTH); }
  inline void cs_max_set(uint32_t value) { this->set_field(value, HYPER_TIMING_CFG_CS_MAX_BIT, HYPER_TIMING_CFG_CS_MAX_WIDTH); }
  inline uint32_t cs_max_get() { return this->get_field(HYPER_TIMING_CFG_CS_MAX_BIT, HYPER_TIMING_CFG_CS_MAX_WIDTH); }
};

class vp_hyper_mba0 : public vp::reg_32
{
public:
  inline void mba0_set(uint32_t value) { this->set_field(value, HYPER_MBA0_MBA0_BIT, HYPER_MBA0_MBA0_WIDTH); }
  inline uint32_t mba0_get() { return this->get_field(HYPER_MBA0_MBA0_BIT, HYPER_MBA0_MBA0_WIDTH); }
};

class vp_hyper_mba1 : public vp::reg_32
{
public:
  inline void mba1_set(uint32_t value) { this->set_field(value, HYPER_MBA1_MBA1_BIT, HYPER_MBA1_MBA1_WIDTH); }
  inline uint32_t mba1_get() { return this->get_field(HYPER_MBA1_MBA1_BIT, HYPER_MBA1_MBA1_WIDTH); }
};

class vp_hyper_device : public vp::reg_32
{
public:
  inline void type_set(uint32_t value) { this->set_field(value, HYPER_DEVICE_TYPE_BIT, HYPER_DEVICE_TYPE_WIDTH); }
  inline uint32_t type_get() { return this->get_field(HYPER_DEVICE_TYPE_BIT, HYPER_DEVICE_TYPE_WIDTH); }
  inline void dt0_set(uint32_t value) { this->set_field(value, HYPER_DEVICE_DT0_BIT, HYPER_DEVICE_DT0_WIDTH); }
  inline uint32_t dt0_get() { return this->get_field(HYPER_DEVICE_DT0_BIT, HYPER_DEVICE_DT0_WIDTH); }
  inline void dt1_set(uint32_t value) { this->set_field(value, HYPER_DEVICE_DT1_BIT, HYPER_DEVICE_DT1_WIDTH); }
  inline uint32_t dt1_get() { return this->get_field(HYPER_DEVICE_DT1_BIT, HYPER_DEVICE_DT1_WIDTH); }
};

class vp_hyper_ospi_cmd : public vp::reg_16
{
public:
};

class vp_hyper_ospi_addr : public vp::reg_32
{
public:
};

class vp_hyper_ospi_cfg : public vp::reg_32
{
public:
  inline void cmd_size_set(uint32_t value) { this->set_field(value, HYPER_OSPI_CFG_CMD_SIZE_BIT, HYPER_OSPI_CFG_CMD_SIZE_WIDTH); }
  inline uint32_t cmd_size_get() { return this->get_field(HYPER_OSPI_CFG_CMD_SIZE_BIT, HYPER_OSPI_CFG_CMD_SIZE_WIDTH); }
  inline void addr_size_set(uint32_t value) { this->set_field(value, HYPER_OSPI_CFG_ADDR_SIZE_BIT, HYPER_OSPI_CFG_ADDR_SIZE_WIDTH); }
  inline uint32_t addr_size_get() { return this->get_field(HYPER_OSPI_CFG_ADDR_SIZE_BIT, HYPER_OSPI_CFG_ADDR_SIZE_WIDTH); }
  inline void line_set(uint32_t value) { this->set_field(value, HYPER_OSPI_CFG_LINE_BIT, HYPER_OSPI_CFG_LINE_WIDTH); }
  inline uint32_t line_get() { return this->get_field(HYPER_OSPI_CFG_LINE_BIT, HYPER_OSPI_CFG_LINE_WIDTH); }
  inline void cmd_dtr_str_set(uint32_t value) { this->set_field(value, HYPER_OSPI_CFG_CMD_DTR_STR_BIT, HYPER_OSPI_CFG_CMD_DTR_STR_WIDTH); }
  inline uint32_t cmd_dtr_str_get() { return this->get_field(HYPER_OSPI_CFG_CMD_DTR_STR_BIT, HYPER_OSPI_CFG_CMD_DTR_STR_WIDTH); }
  inline void addr_dtr_str_set(uint32_t value) { this->set_field(value, HYPER_OSPI_CFG_ADDR_DTR_STR_BIT, HYPER_OSPI_CFG_ADDR_DTR_STR_WIDTH); }
  inline uint32_t addr_dtr_str_get() { return this->get_field(HYPER_OSPI_CFG_ADDR_DTR_STR_BIT, HYPER_OSPI_CFG_ADDR_DTR_STR_WIDTH); }
  inline void data_dtr_str_set(uint32_t value) { this->set_field(value, HYPER_OSPI_CFG_DATA_DTR_STR_BIT, HYPER_OSPI_CFG_DATA_DTR_STR_WIDTH); }
  inline uint32_t data_dtr_str_get() { return this->get_field(HYPER_OSPI_CFG_DATA_DTR_STR_BIT, HYPER_OSPI_CFG_DATA_DTR_STR_WIDTH); }
  inline void data_dtr_msb_set(uint32_t value) { this->set_field(value, HYPER_OSPI_CFG_DATA_DTR_MSB_BIT, HYPER_OSPI_CFG_DATA_DTR_MSB_WIDTH); }
  inline uint32_t data_dtr_msb_get() { return this->get_field(HYPER_OSPI_CFG_DATA_DTR_MSB_BIT, HYPER_OSPI_CFG_DATA_DTR_MSB_WIDTH); }
};

class vp_hyper_ospi_csn : public vp::reg_32
{
public:
  inline void index_set(uint32_t value) { this->set_field(value, HYPER_OSPI_CSN_INDEX_BIT, HYPER_OSPI_CSN_INDEX_WIDTH); }
  inline uint32_t index_get() { return this->get_field(HYPER_OSPI_CSN_INDEX_BIT, HYPER_OSPI_CSN_INDEX_WIDTH); }
  inline void user_ctrl_csn_set(uint32_t value) { this->set_field(value, HYPER_OSPI_CSN_USER_CTRL_CSN_BIT, HYPER_OSPI_CSN_USER_CTRL_CSN_WIDTH); }
  inline uint32_t user_ctrl_csn_get() { return this->get_field(HYPER_OSPI_CSN_USER_CTRL_CSN_BIT, HYPER_OSPI_CSN_USER_CTRL_CSN_WIDTH); }
  inline void csn_val_set(uint32_t value) { this->set_field(value, HYPER_OSPI_CSN_CSN_VAL_BIT, HYPER_OSPI_CSN_CSN_VAL_WIDTH); }
  inline uint32_t csn_val_get() { return this->get_field(HYPER_OSPI_CSN_CSN_VAL_BIT, HYPER_OSPI_CSN_CSN_VAL_WIDTH); }
};

class vp_hyper__reserved0 : public vp::reg_32
{
public:
};

class vp_hyper__reserved1 : public vp::reg_32
{
public:
};

class vp_hyper_irq_en : public vp::reg_32
{
public:
  inline void en_set(uint32_t value) { this->set_field(value, HYPER_IRQ_EN_EN_BIT, HYPER_IRQ_EN_EN_WIDTH); }
  inline uint32_t en_get() { return this->get_field(HYPER_IRQ_EN_EN_BIT, HYPER_IRQ_EN_EN_WIDTH); }
};

class vp_hyper_clk_div : public vp::reg_32
{
public:
  inline void data_set(uint32_t value) { this->set_field(value, HYPER_CLK_DIV_DATA_BIT, HYPER_CLK_DIV_DATA_WIDTH); }
  inline uint32_t data_get() { return this->get_field(HYPER_CLK_DIV_DATA_BIT, HYPER_CLK_DIV_DATA_WIDTH); }
  inline void valid_set(uint32_t value) { this->set_field(value, HYPER_CLK_DIV_VALID_BIT, HYPER_CLK_DIV_VALID_WIDTH); }
  inline uint32_t valid_get() { return this->get_field(HYPER_CLK_DIV_VALID_BIT, HYPER_CLK_DIV_VALID_WIDTH); }
};

class vp_hyper_status : public vp::reg_32
{
public:
  inline void tx_error_set(uint32_t value) { this->set_field(value, HYPER_STATUS_TX_ERROR_BIT, HYPER_STATUS_TX_ERROR_WIDTH); }
  inline uint32_t tx_error_get() { return this->get_field(HYPER_STATUS_TX_ERROR_BIT, HYPER_STATUS_TX_ERROR_WIDTH); }
  inline void rx_error_set(uint32_t value) { this->set_field(value, HYPER_STATUS_RX_ERROR_BIT, HYPER_STATUS_RX_ERROR_WIDTH); }
  inline uint32_t rx_error_get() { return this->get_field(HYPER_STATUS_RX_ERROR_BIT, HYPER_STATUS_RX_ERROR_WIDTH); }
  inline void rx_tx_end_set(uint32_t value) { this->set_field(value, HYPER_STATUS_RX_TX_END_BIT, HYPER_STATUS_RX_TX_END_WIDTH); }
  inline uint32_t rx_tx_end_get() { return this->get_field(HYPER_STATUS_RX_TX_END_BIT, HYPER_STATUS_RX_TX_END_WIDTH); }
};

#endif



//
// REGISTERS GLOBAL STRUCT
//

#ifndef LANGUAGE_ASSEMBLY

typedef struct {
  unsigned int rx_saddr        ; // uDMA RX HYPERBUS buffer base address configuration register.
  unsigned int rx_size         ; // uDMA RX HYPERBUS buffer size configuration register.
  unsigned int rx_cfg          ; // uDMA RX HYPERBUS stream configuration register.
  unsigned int tx_saddr        ; // uDMA TX HYPERBUS buffer base address configuration register.
  unsigned int tx_size         ; // uDMA TX HYPERBUS buffer size configuration register.
  unsigned int tx_cfg          ; // uDMA TX HYPERBUS stream configuration register.
  unsigned int ext_addr        ; // Memory access address register.
  unsigned int timing_cfg      ; // HYPERBUS and Octo SPI Memory Timing configuration register.
  unsigned int mba0            ; // Device start address register.
  unsigned int mba1            ; // Device start address register.
  unsigned int device          ; // Device type register(RAM or FLASH).
  unsigned int ospi_cmd        ; // OSPI command
  unsigned int ospi_addr       ; // OSPI address
  unsigned int ospi_cfg        ; // OSPI configuration
  unsigned int ospi_csn        ; // OSPI chip select configuration
  unsigned int _reserved0      ; // -
  unsigned int _reserved1      ; // -
  unsigned int irq_en          ; // OSPI interrupt enable register
  unsigned int clk_div         ; // Clock divide.
  unsigned int status          ; // Transfer status for error.
} __attribute__((packed)) hyper_hyper_t;

#endif



//
// REGISTERS ACCESS FUNCTIONS
//

#ifndef LANGUAGE_ASSEMBLY

static inline uint32_t hyper_rx_saddr_get(uint32_t base) { return ARCHI_READ(base, HYPER_RX_SADDR_OFFSET); }
static inline void hyper_rx_saddr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_RX_SADDR_OFFSET, value); }

static inline uint32_t hyper_rx_size_get(uint32_t base) { return ARCHI_READ(base, HYPER_RX_SIZE_OFFSET); }
static inline void hyper_rx_size_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_RX_SIZE_OFFSET, value); }

static inline uint32_t hyper_rx_cfg_get(uint32_t base) { return ARCHI_READ(base, HYPER_RX_CFG_OFFSET); }
static inline void hyper_rx_cfg_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_RX_CFG_OFFSET, value); }

static inline uint32_t hyper_tx_saddr_get(uint32_t base) { return ARCHI_READ(base, HYPER_TX_SADDR_OFFSET); }
static inline void hyper_tx_saddr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_TX_SADDR_OFFSET, value); }

static inline uint32_t hyper_tx_size_get(uint32_t base) { return ARCHI_READ(base, HYPER_TX_SIZE_OFFSET); }
static inline void hyper_tx_size_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_TX_SIZE_OFFSET, value); }

static inline uint32_t hyper_tx_cfg_get(uint32_t base) { return ARCHI_READ(base, HYPER_TX_CFG_OFFSET); }
static inline void hyper_tx_cfg_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_TX_CFG_OFFSET, value); }

static inline uint32_t hyper_ext_addr_get(uint32_t base) { return ARCHI_READ(base, HYPER_EXT_ADDR_OFFSET); }
static inline void hyper_ext_addr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_EXT_ADDR_OFFSET, value); }

static inline uint32_t hyper_timing_cfg_get(uint32_t base) { return ARCHI_READ(base, HYPER_TIMING_CFG_OFFSET); }
static inline void hyper_timing_cfg_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_TIMING_CFG_OFFSET, value); }

static inline uint32_t hyper_mba0_get(uint32_t base) { return ARCHI_READ(base, HYPER_MBA0_OFFSET); }
static inline void hyper_mba0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_MBA0_OFFSET, value); }

static inline uint32_t hyper_mba1_get(uint32_t base) { return ARCHI_READ(base, HYPER_MBA1_OFFSET); }
static inline void hyper_mba1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_MBA1_OFFSET, value); }

static inline uint32_t hyper_device_get(uint32_t base) { return ARCHI_READ(base, HYPER_DEVICE_OFFSET); }
static inline void hyper_device_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_DEVICE_OFFSET, value); }

static inline uint32_t hyper_ospi_cmd_get(uint32_t base) { return ARCHI_READ(base, HYPER_OSPI_CMD_OFFSET); }
static inline void hyper_ospi_cmd_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_OSPI_CMD_OFFSET, value); }

static inline uint32_t hyper_ospi_addr_get(uint32_t base) { return ARCHI_READ(base, HYPER_OSPI_ADDR_OFFSET); }
static inline void hyper_ospi_addr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_OSPI_ADDR_OFFSET, value); }

static inline uint32_t hyper_ospi_cfg_get(uint32_t base) { return ARCHI_READ(base, HYPER_OSPI_CFG_OFFSET); }
static inline void hyper_ospi_cfg_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_OSPI_CFG_OFFSET, value); }

static inline uint32_t hyper_ospi_csn_get(uint32_t base) { return ARCHI_READ(base, HYPER_OSPI_CSN_OFFSET); }
static inline void hyper_ospi_csn_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_OSPI_CSN_OFFSET, value); }

static inline uint32_t hyper__reserved0_get(uint32_t base) { return ARCHI_READ(base, HYPER__RESERVED0_OFFSET); }
static inline void hyper__reserved0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER__RESERVED0_OFFSET, value); }

static inline uint32_t hyper__reserved1_get(uint32_t base) { return ARCHI_READ(base, HYPER__RESERVED1_OFFSET); }
static inline void hyper__reserved1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER__RESERVED1_OFFSET, value); }

static inline uint32_t hyper_irq_en_get(uint32_t base) { return ARCHI_READ(base, HYPER_IRQ_EN_OFFSET); }
static inline void hyper_irq_en_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_IRQ_EN_OFFSET, value); }

static inline uint32_t hyper_clk_div_get(uint32_t base) { return ARCHI_READ(base, HYPER_CLK_DIV_OFFSET); }
static inline void hyper_clk_div_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_CLK_DIV_OFFSET, value); }

static inline uint32_t hyper_status_get(uint32_t base) { return ARCHI_READ(base, HYPER_STATUS_OFFSET); }
static inline void hyper_status_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HYPER_STATUS_OFFSET, value); }

#endif



//
// REGISTERS FIELDS MACROS
//

#ifndef LANGUAGE_ASSEMBLY

#define HYPER_RX_SADDR_RX_SADDR_GET(value)                 (ARCHI_BEXTRACTU((value),16,0))
#define HYPER_RX_SADDR_RX_SADDR_GETS(value)                (ARCHI_BEXTRACT((value),16,0))
#define HYPER_RX_SADDR_RX_SADDR_SET(value,field)           (ARCHI_BINSERT((value),(field),16,0))
#define HYPER_RX_SADDR_RX_SADDR(val)                       ((val) << 0)

#define HYPER_RX_SIZE_RX_SIZE_GET(value)                   (ARCHI_BEXTRACTU((value),17,0))
#define HYPER_RX_SIZE_RX_SIZE_GETS(value)                  (ARCHI_BEXTRACT((value),17,0))
#define HYPER_RX_SIZE_RX_SIZE_SET(value,field)             (ARCHI_BINSERT((value),(field),17,0))
#define HYPER_RX_SIZE_RX_SIZE(val)                         ((val) << 0)

#define HYPER_RX_CFG_CONTINOUS_GET(value)                  (ARCHI_BEXTRACTU((value),1,0))
#define HYPER_RX_CFG_CONTINOUS_GETS(value)                 (ARCHI_BEXTRACT((value),1,0))
#define HYPER_RX_CFG_CONTINOUS_SET(value,field)            (ARCHI_BINSERT((value),(field),1,0))
#define HYPER_RX_CFG_CONTINOUS(val)                        ((val) << 0)

#define HYPER_RX_CFG_EN_GET(value)                         (ARCHI_BEXTRACTU((value),1,4))
#define HYPER_RX_CFG_EN_GETS(value)                        (ARCHI_BEXTRACT((value),1,4))
#define HYPER_RX_CFG_EN_SET(value,field)                   (ARCHI_BINSERT((value),(field),1,4))
#define HYPER_RX_CFG_EN(val)                               ((val) << 4)

#define HYPER_RX_CFG_PENDING_GET(value)                    (ARCHI_BEXTRACTU((value),1,5))
#define HYPER_RX_CFG_PENDING_GETS(value)                   (ARCHI_BEXTRACT((value),1,5))
#define HYPER_RX_CFG_PENDING_SET(value,field)              (ARCHI_BINSERT((value),(field),1,5))
#define HYPER_RX_CFG_PENDING(val)                          ((val) << 5)

#define HYPER_RX_CFG_CLR_GET(value)                        (ARCHI_BEXTRACTU((value),1,6))
#define HYPER_RX_CFG_CLR_GETS(value)                       (ARCHI_BEXTRACT((value),1,6))
#define HYPER_RX_CFG_CLR_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,6))
#define HYPER_RX_CFG_CLR(val)                              ((val) << 6)

#define HYPER_TX_SADDR_TX_SADDR_GET(value)                 (ARCHI_BEXTRACTU((value),16,0))
#define HYPER_TX_SADDR_TX_SADDR_GETS(value)                (ARCHI_BEXTRACT((value),16,0))
#define HYPER_TX_SADDR_TX_SADDR_SET(value,field)           (ARCHI_BINSERT((value),(field),16,0))
#define HYPER_TX_SADDR_TX_SADDR(val)                       ((val) << 0)

#define HYPER_TX_SIZE_TX_SIZE_GET(value)                   (ARCHI_BEXTRACTU((value),17,0))
#define HYPER_TX_SIZE_TX_SIZE_GETS(value)                  (ARCHI_BEXTRACT((value),17,0))
#define HYPER_TX_SIZE_TX_SIZE_SET(value,field)             (ARCHI_BINSERT((value),(field),17,0))
#define HYPER_TX_SIZE_TX_SIZE(val)                         ((val) << 0)

#define HYPER_TX_CFG_CONTINOUS_GET(value)                  (ARCHI_BEXTRACTU((value),1,0))
#define HYPER_TX_CFG_CONTINOUS_GETS(value)                 (ARCHI_BEXTRACT((value),1,0))
#define HYPER_TX_CFG_CONTINOUS_SET(value,field)            (ARCHI_BINSERT((value),(field),1,0))
#define HYPER_TX_CFG_CONTINOUS(val)                        ((val) << 0)

#define HYPER_TX_CFG_EN_GET(value)                         (ARCHI_BEXTRACTU((value),1,4))
#define HYPER_TX_CFG_EN_GETS(value)                        (ARCHI_BEXTRACT((value),1,4))
#define HYPER_TX_CFG_EN_SET(value,field)                   (ARCHI_BINSERT((value),(field),1,4))
#define HYPER_TX_CFG_EN(val)                               ((val) << 4)

#define HYPER_TX_CFG_PENDING_GET(value)                    (ARCHI_BEXTRACTU((value),1,5))
#define HYPER_TX_CFG_PENDING_GETS(value)                   (ARCHI_BEXTRACT((value),1,5))
#define HYPER_TX_CFG_PENDING_SET(value,field)              (ARCHI_BINSERT((value),(field),1,5))
#define HYPER_TX_CFG_PENDING(val)                          ((val) << 5)

#define HYPER_TX_CFG_CLR_GET(value)                        (ARCHI_BEXTRACTU((value),1,6))
#define HYPER_TX_CFG_CLR_GETS(value)                       (ARCHI_BEXTRACT((value),1,6))
#define HYPER_TX_CFG_CLR_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,6))
#define HYPER_TX_CFG_CLR(val)                              ((val) << 6)

#define HYPER_EXT_ADDR_SADDR_GET(value)                    (ARCHI_BEXTRACTU((value),31,0))
#define HYPER_EXT_ADDR_SADDR_GETS(value)                   (ARCHI_BEXTRACT((value),31,0))
#define HYPER_EXT_ADDR_SADDR_SET(value,field)              (ARCHI_BINSERT((value),(field),31,0))
#define HYPER_EXT_ADDR_SADDR(val)                          ((val) << 0)

#define HYPER_EXT_ADDR_REG_ACCESS_GET(value)               (ARCHI_BEXTRACTU((value),1,31))
#define HYPER_EXT_ADDR_REG_ACCESS_GETS(value)              (ARCHI_BEXTRACT((value),1,31))
#define HYPER_EXT_ADDR_REG_ACCESS_SET(value,field)         (ARCHI_BINSERT((value),(field),1,31))
#define HYPER_EXT_ADDR_REG_ACCESS(val)                     ((val) << 31)

#define HYPER_TIMING_CFG_LATENCY0_GET(value)               (ARCHI_BEXTRACTU((value),5,0))
#define HYPER_TIMING_CFG_LATENCY0_GETS(value)              (ARCHI_BEXTRACT((value),5,0))
#define HYPER_TIMING_CFG_LATENCY0_SET(value,field)         (ARCHI_BINSERT((value),(field),5,0))
#define HYPER_TIMING_CFG_LATENCY0(val)                     ((val) << 0)

#define HYPER_TIMING_CFG_LATENCY1_GET(value)               (ARCHI_BEXTRACTU((value),5,5))
#define HYPER_TIMING_CFG_LATENCY1_GETS(value)              (ARCHI_BEXTRACT((value),5,5))
#define HYPER_TIMING_CFG_LATENCY1_SET(value,field)         (ARCHI_BINSERT((value),(field),5,5))
#define HYPER_TIMING_CFG_LATENCY1(val)                     ((val) << 5)

#define HYPER_TIMING_CFG_RW_RECOVERY_GET(value)            (ARCHI_BEXTRACTU((value),4,10))
#define HYPER_TIMING_CFG_RW_RECOVERY_GETS(value)           (ARCHI_BEXTRACT((value),4,10))
#define HYPER_TIMING_CFG_RW_RECOVERY_SET(value,field)      (ARCHI_BINSERT((value),(field),4,10))
#define HYPER_TIMING_CFG_RW_RECOVERY(val)                  ((val) << 10)

#define HYPER_TIMING_CFG_RWDS_DELAY_GET(value)             (ARCHI_BEXTRACTU((value),3,14))
#define HYPER_TIMING_CFG_RWDS_DELAY_GETS(value)            (ARCHI_BEXTRACT((value),3,14))
#define HYPER_TIMING_CFG_RWDS_DELAY_SET(value,field)       (ARCHI_BINSERT((value),(field),3,14))
#define HYPER_TIMING_CFG_RWDS_DELAY(val)                   ((val) << 14)

#define HYPER_TIMING_CFG_ADDITIONAL_LATENCY_AUTOCHECK_EN_GET(value) (ARCHI_BEXTRACTU((value),1,17))
#define HYPER_TIMING_CFG_ADDITIONAL_LATENCY_AUTOCHECK_EN_GETS(value) (ARCHI_BEXTRACT((value),1,17))
#define HYPER_TIMING_CFG_ADDITIONAL_LATENCY_AUTOCHECK_EN_SET(value,field) (ARCHI_BINSERT((value),(field),1,17))
#define HYPER_TIMING_CFG_ADDITIONAL_LATENCY_AUTOCHECK_EN(val) ((val) << 17)

#define HYPER_TIMING_CFG_CS_MAX_GET(value)                 (ARCHI_BEXTRACTU((value),16,18))
#define HYPER_TIMING_CFG_CS_MAX_GETS(value)                (ARCHI_BEXTRACT((value),16,18))
#define HYPER_TIMING_CFG_CS_MAX_SET(value,field)           (ARCHI_BINSERT((value),(field),16,18))
#define HYPER_TIMING_CFG_CS_MAX(val)                       ((val) << 18)

#define HYPER_MBA0_MBA0_GET(value)                         (ARCHI_BEXTRACTU((value),7,24))
#define HYPER_MBA0_MBA0_GETS(value)                        (ARCHI_BEXTRACT((value),7,24))
#define HYPER_MBA0_MBA0_SET(value,field)                   (ARCHI_BINSERT((value),(field),7,24))
#define HYPER_MBA0_MBA0(val)                               ((val) << 24)

#define HYPER_MBA1_MBA1_GET(value)                         (ARCHI_BEXTRACTU((value),7,24))
#define HYPER_MBA1_MBA1_GETS(value)                        (ARCHI_BEXTRACT((value),7,24))
#define HYPER_MBA1_MBA1_SET(value,field)                   (ARCHI_BINSERT((value),(field),7,24))
#define HYPER_MBA1_MBA1(val)                               ((val) << 24)

#define HYPER_DEVICE_TYPE_GET(value)                       (ARCHI_BEXTRACTU((value),1,0))
#define HYPER_DEVICE_TYPE_GETS(value)                      (ARCHI_BEXTRACT((value),1,0))
#define HYPER_DEVICE_TYPE_SET(value,field)                 (ARCHI_BINSERT((value),(field),1,0))
#define HYPER_DEVICE_TYPE(val)                             ((val) << 0)

#define HYPER_DEVICE_DT0_GET(value)                        (ARCHI_BEXTRACTU((value),1,1))
#define HYPER_DEVICE_DT0_GETS(value)                       (ARCHI_BEXTRACT((value),1,1))
#define HYPER_DEVICE_DT0_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,1))
#define HYPER_DEVICE_DT0(val)                              ((val) << 1)

#define HYPER_DEVICE_DT1_GET(value)                        (ARCHI_BEXTRACTU((value),1,2))
#define HYPER_DEVICE_DT1_GETS(value)                       (ARCHI_BEXTRACT((value),1,2))
#define HYPER_DEVICE_DT1_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,2))
#define HYPER_DEVICE_DT1(val)                              ((val) << 2)

#define HYPER_OSPI_CFG_CMD_SIZE_GET(value)                 (ARCHI_BEXTRACTU((value),2,0))
#define HYPER_OSPI_CFG_CMD_SIZE_GETS(value)                (ARCHI_BEXTRACT((value),2,0))
#define HYPER_OSPI_CFG_CMD_SIZE_SET(value,field)           (ARCHI_BINSERT((value),(field),2,0))
#define HYPER_OSPI_CFG_CMD_SIZE(val)                       ((val) << 0)

#define HYPER_OSPI_CFG_ADDR_SIZE_GET(value)                (ARCHI_BEXTRACTU((value),3,4))
#define HYPER_OSPI_CFG_ADDR_SIZE_GETS(value)               (ARCHI_BEXTRACT((value),3,4))
#define HYPER_OSPI_CFG_ADDR_SIZE_SET(value,field)          (ARCHI_BINSERT((value),(field),3,4))
#define HYPER_OSPI_CFG_ADDR_SIZE(val)                      ((val) << 4)

#define HYPER_OSPI_CFG_LINE_GET(value)                     (ARCHI_BEXTRACTU((value),1,8))
#define HYPER_OSPI_CFG_LINE_GETS(value)                    (ARCHI_BEXTRACT((value),1,8))
#define HYPER_OSPI_CFG_LINE_SET(value,field)               (ARCHI_BINSERT((value),(field),1,8))
#define HYPER_OSPI_CFG_LINE(val)                           ((val) << 8)

#define HYPER_OSPI_CFG_CMD_DTR_STR_GET(value)              (ARCHI_BEXTRACTU((value),1,12))
#define HYPER_OSPI_CFG_CMD_DTR_STR_GETS(value)             (ARCHI_BEXTRACT((value),1,12))
#define HYPER_OSPI_CFG_CMD_DTR_STR_SET(value,field)        (ARCHI_BINSERT((value),(field),1,12))
#define HYPER_OSPI_CFG_CMD_DTR_STR(val)                    ((val) << 12)

#define HYPER_OSPI_CFG_ADDR_DTR_STR_GET(value)             (ARCHI_BEXTRACTU((value),1,13))
#define HYPER_OSPI_CFG_ADDR_DTR_STR_GETS(value)            (ARCHI_BEXTRACT((value),1,13))
#define HYPER_OSPI_CFG_ADDR_DTR_STR_SET(value,field)       (ARCHI_BINSERT((value),(field),1,13))
#define HYPER_OSPI_CFG_ADDR_DTR_STR(val)                   ((val) << 13)

#define HYPER_OSPI_CFG_DATA_DTR_STR_GET(value)             (ARCHI_BEXTRACTU((value),1,14))
#define HYPER_OSPI_CFG_DATA_DTR_STR_GETS(value)            (ARCHI_BEXTRACT((value),1,14))
#define HYPER_OSPI_CFG_DATA_DTR_STR_SET(value,field)       (ARCHI_BINSERT((value),(field),1,14))
#define HYPER_OSPI_CFG_DATA_DTR_STR(val)                   ((val) << 14)

#define HYPER_OSPI_CFG_DATA_DTR_MSB_GET(value)             (ARCHI_BEXTRACTU((value),1,15))
#define HYPER_OSPI_CFG_DATA_DTR_MSB_GETS(value)            (ARCHI_BEXTRACT((value),1,15))
#define HYPER_OSPI_CFG_DATA_DTR_MSB_SET(value,field)       (ARCHI_BINSERT((value),(field),1,15))
#define HYPER_OSPI_CFG_DATA_DTR_MSB(val)                   ((val) << 15)

#define HYPER_OSPI_CSN_INDEX_GET(value)                    (ARCHI_BEXTRACTU((value),1,0))
#define HYPER_OSPI_CSN_INDEX_GETS(value)                   (ARCHI_BEXTRACT((value),1,0))
#define HYPER_OSPI_CSN_INDEX_SET(value,field)              (ARCHI_BINSERT((value),(field),1,0))
#define HYPER_OSPI_CSN_INDEX(val)                          ((val) << 0)

#define HYPER_OSPI_CSN_USER_CTRL_CSN_GET(value)            (ARCHI_BEXTRACTU((value),1,4))
#define HYPER_OSPI_CSN_USER_CTRL_CSN_GETS(value)           (ARCHI_BEXTRACT((value),1,4))
#define HYPER_OSPI_CSN_USER_CTRL_CSN_SET(value,field)      (ARCHI_BINSERT((value),(field),1,4))
#define HYPER_OSPI_CSN_USER_CTRL_CSN(val)                  ((val) << 4)

#define HYPER_OSPI_CSN_CSN_VAL_GET(value)                  (ARCHI_BEXTRACTU((value),1,5))
#define HYPER_OSPI_CSN_CSN_VAL_GETS(value)                 (ARCHI_BEXTRACT((value),1,5))
#define HYPER_OSPI_CSN_CSN_VAL_SET(value,field)            (ARCHI_BINSERT((value),(field),1,5))
#define HYPER_OSPI_CSN_CSN_VAL(val)                        ((val) << 5)

#define HYPER_IRQ_EN_EN_GET(value)                         (ARCHI_BEXTRACTU((value),1,0))
#define HYPER_IRQ_EN_EN_GETS(value)                        (ARCHI_BEXTRACT((value),1,0))
#define HYPER_IRQ_EN_EN_SET(value,field)                   (ARCHI_BINSERT((value),(field),1,0))
#define HYPER_IRQ_EN_EN(val)                               ((val) << 0)

#define HYPER_CLK_DIV_DATA_GET(value)                      (ARCHI_BEXTRACTU((value),8,0))
#define HYPER_CLK_DIV_DATA_GETS(value)                     (ARCHI_BEXTRACT((value),8,0))
#define HYPER_CLK_DIV_DATA_SET(value,field)                (ARCHI_BINSERT((value),(field),8,0))
#define HYPER_CLK_DIV_DATA(val)                            ((val) << 0)

#define HYPER_CLK_DIV_VALID_GET(value)                     (ARCHI_BEXTRACTU((value),1,8))
#define HYPER_CLK_DIV_VALID_GETS(value)                    (ARCHI_BEXTRACT((value),1,8))
#define HYPER_CLK_DIV_VALID_SET(value,field)               (ARCHI_BINSERT((value),(field),1,8))
#define HYPER_CLK_DIV_VALID(val)                           ((val) << 8)

#define HYPER_STATUS_TX_ERROR_GET(value)                   (ARCHI_BEXTRACTU((value),1,0))
#define HYPER_STATUS_TX_ERROR_GETS(value)                  (ARCHI_BEXTRACT((value),1,0))
#define HYPER_STATUS_TX_ERROR_SET(value,field)             (ARCHI_BINSERT((value),(field),1,0))
#define HYPER_STATUS_TX_ERROR(val)                         ((val) << 0)

#define HYPER_STATUS_RX_ERROR_GET(value)                   (ARCHI_BEXTRACTU((value),1,1))
#define HYPER_STATUS_RX_ERROR_GETS(value)                  (ARCHI_BEXTRACT((value),1,1))
#define HYPER_STATUS_RX_ERROR_SET(value,field)             (ARCHI_BINSERT((value),(field),1,1))
#define HYPER_STATUS_RX_ERROR(val)                         ((val) << 1)

#define HYPER_STATUS_RX_TX_END_GET(value)                  (ARCHI_BEXTRACTU((value),1,2))
#define HYPER_STATUS_RX_TX_END_GETS(value)                 (ARCHI_BEXTRACT((value),1,2))
#define HYPER_STATUS_RX_TX_END_SET(value,field)            (ARCHI_BINSERT((value),(field),1,2))
#define HYPER_STATUS_RX_TX_END(val)                        ((val) << 2)

#endif

#endif
