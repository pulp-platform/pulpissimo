
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

#ifndef __INCLUDE_ARCHI_UDMA_I2S_UDMA_I2S_V1_NEW_H__
#define __INCLUDE_ARCHI_UDMA_I2S_UDMA_I2S_V1_NEW_H__

#ifndef LANGUAGE_ASSEMBLY

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS
//

// uDMA RX I2S channel 0 buffer base address configuration register.
#define UDMA_I2S_RX_SADDR_CH0_OFFSET             0x0

// uDMA RX I2S channel 0 buffer size configuration register.
#define UDMA_I2S_RX_SIZE_CH0_OFFSET              0x4

// uDMA RX I2S channel 0 stream configuration register.
#define UDMA_I2S_RX_CFG_CH0_OFFSET               0x8

// uDMA RX I2S channel 1 buffer base address configuration register.
#define UDMA_I2S_RX_SADDR_CH1_OFFSET             0x10

// uDMA RX I2S channel 1 buffer size configuration register.
#define UDMA_I2S_RX_SIZE_CH1_OFFSET              0x14

// uDMA RX I2S channel 1 stream configuration register.
#define UDMA_I2S_RX_CFG_CH1_OFFSET               0x18

// I2S external clock configuration register.
#define UDMA_I2S_CFG_EXT_OFFSET                  0x20

// I2S clock and WS generator 0 configuration register.
#define UDMA_I2S_CFG_CLKGEN0_OFFSET              0x24

// I2S clock and WS generator 1 configuration register.
#define UDMA_I2S_CFG_CLKGEN1_OFFSET              0x28

// I2S channels mode configuration register.
#define UDMA_I2S_CHMODE_OFFSET                   0x2c

// I2S channel 0 filtering configuration register.
#define UDMA_I2S_FILT_CH0_OFFSET                 0x30

// I2S channel 1 filtering configuration register.
#define UDMA_I2S_FILT_CH1_OFFSET                 0x34



//
// REGISTERS FIELDS
//

// I2S channel 0 RX buffer base address bitfield: - Read: returns value of the buffer pointer until transfer is finished. Else returns 0. - Write: sets RX buffer base address (access: R/W)
#define UDMA_I2S_RX_SADDR_CH0_RX_SADDR_BIT                           0
#define UDMA_I2S_RX_SADDR_CH0_RX_SADDR_WIDTH                         16
#define UDMA_I2S_RX_SADDR_CH0_RX_SADDR_MASK                          0xffff

// I2S channel 0 RX buffer size bitfield in bytes. (128kBytes maximum) - Read: returns remaining buffer size to transfer. - Write: sets buffer size. (access: R/W)
#define UDMA_I2S_RX_SIZE_CH0_RX_SIZE_BIT                             0
#define UDMA_I2S_RX_SIZE_CH0_RX_SIZE_WIDTH                           17
#define UDMA_I2S_RX_SIZE_CH0_RX_SIZE_MASK                            0x1ffff

// I2S channel 0 RX channel continuous mode bitfield: -1'b0: disabled -1'b1: enabled At the end of the buffer transfer, the uDMA reloads the address / buffer size and starts a new transfer. (access: R/W)
#define UDMA_I2S_RX_CFG_CH0_CONTINOUS_BIT                            0
#define UDMA_I2S_RX_CFG_CH0_CONTINOUS_WIDTH                          1
#define UDMA_I2S_RX_CFG_CH0_CONTINOUS_MASK                           0x1

// RX channel transfer size used to increment uDMA I2S channel 0 RX buffer address pointer: - 2'b00: plus 1 - +1 (8 bits) - 2'b01: plus 2 - +2 (16 bits) - 2'b10: plus 4 - +4 (32 bits) - 2'b11: plus 0 - +0 (access: R/W)
#define UDMA_I2S_RX_CFG_CH0_DATASIZE_BIT                             1
#define UDMA_I2S_RX_CFG_CH0_DATASIZE_WIDTH                           2
#define UDMA_I2S_RX_CFG_CH0_DATASIZE_MASK                            0x6

// I2S channel 0 RX Channel enable and start transfer bitfield: -1'b0: disable -1'b1: start - enable and start the transfer This signal is used also to queue a transfer if one is already ongoing. (access: R/W)
#define UDMA_I2S_RX_CFG_CH0_EN_BIT                                   4
#define UDMA_I2S_RX_CFG_CH0_EN_WIDTH                                 1
#define UDMA_I2S_RX_CFG_CH0_EN_MASK                                  0x10

// I2S channel 0 RX Channel clear and stop transfer: -1'b0: disable -1'b1: stop and clear - stop and clear the on-going transfer (access: W)
#define UDMA_I2S_RX_CFG_CH0_CLR_BIT                                  5
#define UDMA_I2S_RX_CFG_CH0_CLR_WIDTH                                1
#define UDMA_I2S_RX_CFG_CH0_CLR_MASK                                 0x20

// I2S channel 0 RX Transfer pending in queue status flag: -1'b0: no pending - no pending transfer in the queue -1'b1:pending -  pending transfer in the queue (access: R)
#define UDMA_I2S_RX_CFG_CH0_PENDING_BIT                              5
#define UDMA_I2S_RX_CFG_CH0_PENDING_WIDTH                            1
#define UDMA_I2S_RX_CFG_CH0_PENDING_MASK                             0x20

// I2S channel 1 RX buffer base address bitfield: - Read: returns value of the buffer pointer until transfer is finished. Else returns 0. - Write: sets RX buffer base address (access: R/W)
#define UDMA_I2S_RX_SADDR_CH1_TX_SADDR_BIT                           0
#define UDMA_I2S_RX_SADDR_CH1_TX_SADDR_WIDTH                         16
#define UDMA_I2S_RX_SADDR_CH1_TX_SADDR_MASK                          0xffff

// I2S channel 1 RX buffer size bitfield in bytes. (128kBytes maximum) - Read: returns remaining buffer size to transfer. - Write: sets buffer size. (access: R/W)
#define UDMA_I2S_RX_SIZE_CH1_TX_SIZE_BIT                             0
#define UDMA_I2S_RX_SIZE_CH1_TX_SIZE_WIDTH                           17
#define UDMA_I2S_RX_SIZE_CH1_TX_SIZE_MASK                            0x1ffff

// I2S channel 1 RX channel continuous mode bitfield: -1'b0: disabled -1'b1: enabled At the end of the buffer transfer, the uDMA reloads the address / buffer size and starts a new transfer. (access: R/W)
#define UDMA_I2S_RX_CFG_CH1_CONTINOUS_BIT                            0
#define UDMA_I2S_RX_CFG_CH1_CONTINOUS_WIDTH                          1
#define UDMA_I2S_RX_CFG_CH1_CONTINOUS_MASK                           0x1

// RX channel transfer size used to increment uDMA I2S channel 1 RX buffer address pointer: - 2'b00: plus 1 - +1 (8 bits) - 2'b01: plus 2 - +2 (16 bits) - 2'b10: plus 4 - +4 (32 bits) - 2'b11: plus 0 - +0 (access: R/W)
#define UDMA_I2S_RX_CFG_CH1_DATASIZE_BIT                             1
#define UDMA_I2S_RX_CFG_CH1_DATASIZE_WIDTH                           2
#define UDMA_I2S_RX_CFG_CH1_DATASIZE_MASK                            0x6

// I2S channel 1 RX Channel enable and start transfer bitfield: -1'b0: disable -1'b1: start - enable and start the transfer This signal is used also to queue a transfer if one is already ongoing. (access: R/W)
#define UDMA_I2S_RX_CFG_CH1_EN_BIT                                   4
#define UDMA_I2S_RX_CFG_CH1_EN_WIDTH                                 1
#define UDMA_I2S_RX_CFG_CH1_EN_MASK                                  0x10

// I2S channel 1 RX Channel clear and stop transfer: -1'b0: disable -1'b1: stop and clear - stop and clear the on-going transfer (access: W)
#define UDMA_I2S_RX_CFG_CH1_CLR_BIT                                  5
#define UDMA_I2S_RX_CFG_CH1_CLR_WIDTH                                1
#define UDMA_I2S_RX_CFG_CH1_CLR_MASK                                 0x20

// I2S channel 1 RX Transfer pending in queue status flag: -1'b0: no pending - no pending transfer in the queue -1'b1: pending - pending transfer in the queue (access: R)
#define UDMA_I2S_RX_CFG_CH1_PENDING_BIT                              5
#define UDMA_I2S_RX_CFG_CH1_PENDING_WIDTH                            1
#define UDMA_I2S_RX_CFG_CH1_PENDING_MASK                             0x20

// External clock word length in bits bitfield. The value is (num bits - 1). (access: R/W)
#define UDMA_I2S_CFG_EXT_EXT_BITS_WORD_BIT                           0
#define UDMA_I2S_CFG_EXT_EXT_BITS_WORD_WIDTH                         5
#define UDMA_I2S_CFG_EXT_EXT_BITS_WORD_MASK                          0x1f

// Clock generator 0 word length in bits bitfield. The value is (num bits - 1). (access: R/W)
#define UDMA_I2S_CFG_CLKGEN0_BITS_WORD_BIT                           0
#define UDMA_I2S_CFG_CLKGEN0_BITS_WORD_WIDTH                         5
#define UDMA_I2S_CFG_CLKGEN0_BITS_WORD_MASK                          0x1f

// Clock generator 0 enable bitfield: - 1'b0: disabled - 1'b1: enabled - enabled. Clock and WS signal are generated. (access: R/W)
#define UDMA_I2S_CFG_CLKGEN0_CLK_EN_BIT                              8
#define UDMA_I2S_CFG_CLKGEN0_CLK_EN_WIDTH                            1
#define UDMA_I2S_CFG_CLKGEN0_CLK_EN_MASK                             0x100

// Clock generator 0 clock divider related to SoC clock frequency. (access: R/W)
#define UDMA_I2S_CFG_CLKGEN0_CLK_DIV_BIT                             16
#define UDMA_I2S_CFG_CLKGEN0_CLK_DIV_WIDTH                           16
#define UDMA_I2S_CFG_CLKGEN0_CLK_DIV_MASK                            0xffff0000

// Clock generator 1 word length in bits bitfield. The value is (num bits - 1). (access: R/W)
#define UDMA_I2S_CFG_CLKGEN1_BITS_WORD_BIT                           0
#define UDMA_I2S_CFG_CLKGEN1_BITS_WORD_WIDTH                         5
#define UDMA_I2S_CFG_CLKGEN1_BITS_WORD_MASK                          0x1f

// Clock generator 1 enable bitfield: - 1'b0: disabled - 1'b1: enabled - enabled. Clock and WS signal are generated. (access: R/W)
#define UDMA_I2S_CFG_CLKGEN1_CLK_EN_BIT                              8
#define UDMA_I2S_CFG_CLKGEN1_CLK_EN_WIDTH                            1
#define UDMA_I2S_CFG_CLKGEN1_CLK_EN_MASK                             0x100

// Clock generator 1 clock divider related to SoC clock frequency. (access: R/W)
#define UDMA_I2S_CFG_CLKGEN1_CLK_DIV_BIT                             16
#define UDMA_I2S_CFG_CLKGEN1_CLK_DIV_WIDTH                           16
#define UDMA_I2S_CFG_CLKGEN1_CLK_DIV_MASK                            0xffff0000

// I2S channel 0 LSB first configuration for word serialization bitfield: - 1'b0: MSB first - 1'b1: LSB first  (access: R/W)
#define UDMA_I2S_CHMODE_CH0_LSB_FIRST_BIT                            4
#define UDMA_I2S_CHMODE_CH0_LSB_FIRST_WIDTH                          1
#define UDMA_I2S_CHMODE_CH0_LSB_FIRST_MASK                           0x10

// I2S channel 0 PDM filter activation bitfield: - 1'b0: disabled - 1'b1: enabled (access: R/W)
#define UDMA_I2S_CHMODE_CH0_PDM_USEFILTER_BIT                        8
#define UDMA_I2S_CHMODE_CH0_PDM_USEFILTER_WIDTH                      1
#define UDMA_I2S_CHMODE_CH0_PDM_USEFILTER_MASK                       0x100

// I2S channel 0 PDM demodulation activation bitfield: - 1'b0: disabled - 1'b1: enabled (access: R/W)
#define UDMA_I2S_CHMODE_CH0_PDM_EN_BIT                               12
#define UDMA_I2S_CHMODE_CH0_PDM_EN_WIDTH                             1
#define UDMA_I2S_CHMODE_CH0_PDM_EN_MASK                              0x1000

// I2S channel 0 DDR mode activation bitfield: - 1'b0: disabled - 1'b1: enabled (access: R/W)
#define UDMA_I2S_CHMODE_CH0_USEDDR_BIT                               16
#define UDMA_I2S_CHMODE_CH0_USEDDR_WIDTH                             1
#define UDMA_I2S_CHMODE_CH0_USEDDR_MASK                              0x10000

// I2S channel 0 clock/WS mode configuration bitfield: - 2'b00: clock gen 0 - use clock generator 0 (clock and WS generated by clkgen) - 2'b01: clock gen 1 - use clock generator 1 (clock and WS generated by clkgen) - 2'b10: ext clock int ws - use external clock but internal generated WS by clock generator 0 - 2'b11: ext clock ext ws - use external clock and external WS (access: R/W)
#define UDMA_I2S_CHMODE_CH0_MODE_BIT                                 24
#define UDMA_I2S_CHMODE_CH0_MODE_WIDTH                               2
#define UDMA_I2S_CHMODE_CH0_MODE_MASK                                0x3000000

// I2S channel 1 LSB first configuration for word serialization bitfield: - 1'b0: MSB first - 1'b1: LSB first  (access: R/W)
#define UDMA_I2S_CHMODE_CH1_LSB_FIRST_BIT                            5
#define UDMA_I2S_CHMODE_CH1_LSB_FIRST_WIDTH                          1
#define UDMA_I2S_CHMODE_CH1_LSB_FIRST_MASK                           0x20

// I2S channel 1 PDM filter activation bitfield: - 1'b0: disabled - 1'b1: enabled (access: R/W)
#define UDMA_I2S_CHMODE_CH1_PDM_USEFILTER_BIT                        9
#define UDMA_I2S_CHMODE_CH1_PDM_USEFILTER_WIDTH                      1
#define UDMA_I2S_CHMODE_CH1_PDM_USEFILTER_MASK                       0x200

// I2S channel 1 PDM demodulation activation bitfield: - 1'b0: disabled - 1'b1: enabled (access: R/W)
#define UDMA_I2S_CHMODE_CH1_PDM_EN_BIT                               13
#define UDMA_I2S_CHMODE_CH1_PDM_EN_WIDTH                             1
#define UDMA_I2S_CHMODE_CH1_PDM_EN_MASK                              0x2000

// I2S channel 1 DDR mode activation bitfield: - 1'b0: disabled - 1'b1: enabled (access: R/W)
#define UDMA_I2S_CHMODE_CH1_USEDDR_BIT                               17
#define UDMA_I2S_CHMODE_CH1_USEDDR_WIDTH                             1
#define UDMA_I2S_CHMODE_CH1_USEDDR_MASK                              0x20000

// I2S channel 1 clock/WS mode configuration bitfield: - 2'b00: clock gen 0 - use clock generator 0 (clock and WS generated by clkgen) - 2'b01: clock gen 1 - use clock generator 1 (clock and WS generated by clkgen) - 2'b10: ext clock int ws - use external clock but internal generated WS by clock generator 0 - 2'b11: ext clock ext ws - use external clock and external WS (access: R/W)
#define UDMA_I2S_CHMODE_CH1_MODE_BIT                                 26
#define UDMA_I2S_CHMODE_CH1_MODE_WIDTH                               2
#define UDMA_I2S_CHMODE_CH1_MODE_MASK                                0xc000000

// I2S channel 0 PDM filter decimation value bitfield. (access: R/W)
#define UDMA_I2S_FILT_CH0_DECIMATION_BIT                             0
#define UDMA_I2S_FILT_CH0_DECIMATION_WIDTH                           10
#define UDMA_I2S_FILT_CH0_DECIMATION_MASK                            0x3ff

// I2S channel 0 PDM filter normalisation right shift value bitfield. (access: R/W)
#define UDMA_I2S_FILT_CH0_SHIFT_BIT                                  16
#define UDMA_I2S_FILT_CH0_SHIFT_WIDTH                                3
#define UDMA_I2S_FILT_CH0_SHIFT_MASK                                 0x70000

// I2S channel 1 PDM filter decimation value bitfield. (access: R/W)
#define UDMA_I2S_FILT_CH1_DECIMATION_BIT                             0
#define UDMA_I2S_FILT_CH1_DECIMATION_WIDTH                           10
#define UDMA_I2S_FILT_CH1_DECIMATION_MASK                            0x3ff

// I2S channel 1 PDM filter normalisation right shift value bitfield. (access: R/W)
#define UDMA_I2S_FILT_CH1_SHIFT_BIT                                  16
#define UDMA_I2S_FILT_CH1_SHIFT_WIDTH                                3
#define UDMA_I2S_FILT_CH1_SHIFT_MASK                                 0x70000



//
// REGISTERS STRUCTS
//

#ifndef LANGUAGE_ASSEMBLY

typedef union {
  struct {
    unsigned int rx_saddr        :16; // I2S channel 0 RX buffer base address bitfield: - Read: returns value of the buffer pointer until transfer is finished. Else returns 0. - Write: sets RX buffer base address
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_rx_saddr_ch0_t;

typedef union {
  struct {
    unsigned int rx_size         :17; // I2S channel 0 RX buffer size bitfield in bytes. (128kBytes maximum) - Read: returns remaining buffer size to transfer. - Write: sets buffer size.
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_rx_size_ch0_t;

typedef union {
  struct {
    unsigned int continous       :1 ; // I2S channel 0 RX channel continuous mode bitfield: -1'b0: disabled -1'b1: enabled At the end of the buffer transfer, the uDMA reloads the address / buffer size and starts a new transfer.
    unsigned int datasize        :2 ; // RX channel transfer size used to increment uDMA I2S channel 0 RX buffer address pointer: - 2'b00: plus 1 - +1 (8 bits) - 2'b01: plus 2 - +2 (16 bits) - 2'b10: plus 4 - +4 (32 bits) - 2'b11: plus 0 - +0
    unsigned int padding0:1 ;
    unsigned int en              :1 ; // I2S channel 0 RX Channel enable and start transfer bitfield: -1'b0: disable -1'b1: start - enable and start the transfer This signal is used also to queue a transfer if one is already ongoing.
    unsigned int clr             :1 ; // I2S channel 0 RX Channel clear and stop transfer: -1'b0: disable -1'b1: stop and clear - stop and clear the on-going transfer
    unsigned int pending         :1 ; // I2S channel 0 RX Transfer pending in queue status flag: -1'b0: no pending - no pending transfer in the queue -1'b1:pending -  pending transfer in the queue
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_rx_cfg_ch0_t;

typedef union {
  struct {
    unsigned int tx_saddr        :16; // I2S channel 1 RX buffer base address bitfield: - Read: returns value of the buffer pointer until transfer is finished. Else returns 0. - Write: sets RX buffer base address
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_rx_saddr_ch1_t;

typedef union {
  struct {
    unsigned int tx_size         :17; // I2S channel 1 RX buffer size bitfield in bytes. (128kBytes maximum) - Read: returns remaining buffer size to transfer. - Write: sets buffer size.
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_rx_size_ch1_t;

typedef union {
  struct {
    unsigned int continous       :1 ; // I2S channel 1 RX channel continuous mode bitfield: -1'b0: disabled -1'b1: enabled At the end of the buffer transfer, the uDMA reloads the address / buffer size and starts a new transfer.
    unsigned int datasize        :2 ; // RX channel transfer size used to increment uDMA I2S channel 1 RX buffer address pointer: - 2'b00: plus 1 - +1 (8 bits) - 2'b01: plus 2 - +2 (16 bits) - 2'b10: plus 4 - +4 (32 bits) - 2'b11: plus 0 - +0
    unsigned int padding0:1 ;
    unsigned int en              :1 ; // I2S channel 1 RX Channel enable and start transfer bitfield: -1'b0: disable -1'b1: start - enable and start the transfer This signal is used also to queue a transfer if one is already ongoing.
    unsigned int clr             :1 ; // I2S channel 1 RX Channel clear and stop transfer: -1'b0: disable -1'b1: stop and clear - stop and clear the on-going transfer
    unsigned int pending         :1 ; // I2S channel 1 RX Transfer pending in queue status flag: -1'b0: no pending - no pending transfer in the queue -1'b1: pending - pending transfer in the queue
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_rx_cfg_ch1_t;

typedef union {
  struct {
    unsigned int ext_bits_word   :5 ; // External clock word length in bits bitfield. The value is (num bits - 1).
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_cfg_ext_t;

typedef union {
  struct {
    unsigned int bits_word       :5 ; // Clock generator 0 word length in bits bitfield. The value is (num bits - 1).
    unsigned int padding0:3 ;
    unsigned int clk_en          :1 ; // Clock generator 0 enable bitfield: - 1'b0: disabled - 1'b1: enabled - enabled. Clock and WS signal are generated.
    unsigned int padding1:7 ;
    unsigned int clk_div         :16; // Clock generator 0 clock divider related to SoC clock frequency.
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_cfg_clkgen0_t;

typedef union {
  struct {
    unsigned int bits_word       :5 ; // Clock generator 1 word length in bits bitfield. The value is (num bits - 1).
    unsigned int padding0:3 ;
    unsigned int clk_en          :1 ; // Clock generator 1 enable bitfield: - 1'b0: disabled - 1'b1: enabled - enabled. Clock and WS signal are generated.
    unsigned int padding1:7 ;
    unsigned int clk_div         :16; // Clock generator 1 clock divider related to SoC clock frequency.
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_cfg_clkgen1_t;

typedef union {
  struct {
    unsigned int padding0:4 ;
    unsigned int ch0_lsb_first   :1 ; // I2S channel 0 LSB first configuration for word serialization bitfield: - 1'b0: MSB first - 1'b1: LSB first 
    unsigned int padding1:3 ;
    unsigned int ch0_pdm_usefilter:1 ; // I2S channel 0 PDM filter activation bitfield: - 1'b0: disabled - 1'b1: enabled
    unsigned int padding2:3 ;
    unsigned int ch0_pdm_en      :1 ; // I2S channel 0 PDM demodulation activation bitfield: - 1'b0: disabled - 1'b1: enabled
    unsigned int padding3:3 ;
    unsigned int ch0_useddr      :1 ; // I2S channel 0 DDR mode activation bitfield: - 1'b0: disabled - 1'b1: enabled
    unsigned int padding4:7 ;
    unsigned int ch0_mode        :2 ; // I2S channel 0 clock/WS mode configuration bitfield: - 2'b00: clock gen 0 - use clock generator 0 (clock and WS generated by clkgen) - 2'b01: clock gen 1 - use clock generator 1 (clock and WS generated by clkgen) - 2'b10: ext clock int ws - use external clock but internal generated WS by clock generator 0 - 2'b11: ext clock ext ws - use external clock and external WS
    unsigned int ch1_lsb_first   :1 ; // I2S channel 1 LSB first configuration for word serialization bitfield: - 1'b0: MSB first - 1'b1: LSB first 
    unsigned int padding5:3 ;
    unsigned int ch1_pdm_usefilter:1 ; // I2S channel 1 PDM filter activation bitfield: - 1'b0: disabled - 1'b1: enabled
    unsigned int padding6:3 ;
    unsigned int ch1_pdm_en      :1 ; // I2S channel 1 PDM demodulation activation bitfield: - 1'b0: disabled - 1'b1: enabled
    unsigned int padding7:3 ;
    unsigned int ch1_useddr      :1 ; // I2S channel 1 DDR mode activation bitfield: - 1'b0: disabled - 1'b1: enabled
    unsigned int padding8:8 ;
    unsigned int ch1_mode        :2 ; // I2S channel 1 clock/WS mode configuration bitfield: - 2'b00: clock gen 0 - use clock generator 0 (clock and WS generated by clkgen) - 2'b01: clock gen 1 - use clock generator 1 (clock and WS generated by clkgen) - 2'b10: ext clock int ws - use external clock but internal generated WS by clock generator 0 - 2'b11: ext clock ext ws - use external clock and external WS
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_chmode_t;

typedef union {
  struct {
    unsigned int decimation      :10; // I2S channel 0 PDM filter decimation value bitfield.
    unsigned int padding0:6 ;
    unsigned int shift           :3 ; // I2S channel 0 PDM filter normalisation right shift value bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_filt_ch0_t;

typedef union {
  struct {
    unsigned int decimation      :10; // I2S channel 1 PDM filter decimation value bitfield.
    unsigned int padding0:6 ;
    unsigned int shift           :3 ; // I2S channel 1 PDM filter normalisation right shift value bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) udma_i2s_filt_ch1_t;

#endif



//
// REGISTERS STRUCTS
//

#ifdef __GVSOC__

class vp_udma_i2s_rx_saddr_ch0 : public vp::reg_32
{
public:
  inline void rx_saddr_set(uint32_t value) { this->set_field(value, UDMA_I2S_RX_SADDR_CH0_RX_SADDR_BIT, UDMA_I2S_RX_SADDR_CH0_RX_SADDR_WIDTH); }
  inline uint32_t rx_saddr_get() { return this->get_field(UDMA_I2S_RX_SADDR_CH0_RX_SADDR_BIT, UDMA_I2S_RX_SADDR_CH0_RX_SADDR_WIDTH); }
};

class vp_udma_i2s_rx_size_ch0 : public vp::reg_32
{
public:
  inline void rx_size_set(uint32_t value) { this->set_field(value, UDMA_I2S_RX_SIZE_CH0_RX_SIZE_BIT, UDMA_I2S_RX_SIZE_CH0_RX_SIZE_WIDTH); }
  inline uint32_t rx_size_get() { return this->get_field(UDMA_I2S_RX_SIZE_CH0_RX_SIZE_BIT, UDMA_I2S_RX_SIZE_CH0_RX_SIZE_WIDTH); }
};

class vp_udma_i2s_rx_cfg_ch0 : public vp::reg_32
{
public:
  inline void continous_set(uint32_t value) { this->set_field(value, UDMA_I2S_RX_CFG_CH0_CONTINOUS_BIT, UDMA_I2S_RX_CFG_CH0_CONTINOUS_WIDTH); }
  inline uint32_t continous_get() { return this->get_field(UDMA_I2S_RX_CFG_CH0_CONTINOUS_BIT, UDMA_I2S_RX_CFG_CH0_CONTINOUS_WIDTH); }
  inline void datasize_set(uint32_t value) { this->set_field(value, UDMA_I2S_RX_CFG_CH0_DATASIZE_BIT, UDMA_I2S_RX_CFG_CH0_DATASIZE_WIDTH); }
  inline uint32_t datasize_get() { return this->get_field(UDMA_I2S_RX_CFG_CH0_DATASIZE_BIT, UDMA_I2S_RX_CFG_CH0_DATASIZE_WIDTH); }
  inline void en_set(uint32_t value) { this->set_field(value, UDMA_I2S_RX_CFG_CH0_EN_BIT, UDMA_I2S_RX_CFG_CH0_EN_WIDTH); }
  inline uint32_t en_get() { return this->get_field(UDMA_I2S_RX_CFG_CH0_EN_BIT, UDMA_I2S_RX_CFG_CH0_EN_WIDTH); }
  inline void clr_set(uint32_t value) { this->set_field(value, UDMA_I2S_RX_CFG_CH0_CLR_BIT, UDMA_I2S_RX_CFG_CH0_CLR_WIDTH); }
  inline uint32_t clr_get() { return this->get_field(UDMA_I2S_RX_CFG_CH0_CLR_BIT, UDMA_I2S_RX_CFG_CH0_CLR_WIDTH); }
  inline void pending_set(uint32_t value) { this->set_field(value, UDMA_I2S_RX_CFG_CH0_PENDING_BIT, UDMA_I2S_RX_CFG_CH0_PENDING_WIDTH); }
  inline uint32_t pending_get() { return this->get_field(UDMA_I2S_RX_CFG_CH0_PENDING_BIT, UDMA_I2S_RX_CFG_CH0_PENDING_WIDTH); }
};

class vp_udma_i2s_rx_saddr_ch1 : public vp::reg_32
{
public:
  inline void tx_saddr_set(uint32_t value) { this->set_field(value, UDMA_I2S_RX_SADDR_CH1_TX_SADDR_BIT, UDMA_I2S_RX_SADDR_CH1_TX_SADDR_WIDTH); }
  inline uint32_t tx_saddr_get() { return this->get_field(UDMA_I2S_RX_SADDR_CH1_TX_SADDR_BIT, UDMA_I2S_RX_SADDR_CH1_TX_SADDR_WIDTH); }
};

class vp_udma_i2s_rx_size_ch1 : public vp::reg_32
{
public:
  inline void tx_size_set(uint32_t value) { this->set_field(value, UDMA_I2S_RX_SIZE_CH1_TX_SIZE_BIT, UDMA_I2S_RX_SIZE_CH1_TX_SIZE_WIDTH); }
  inline uint32_t tx_size_get() { return this->get_field(UDMA_I2S_RX_SIZE_CH1_TX_SIZE_BIT, UDMA_I2S_RX_SIZE_CH1_TX_SIZE_WIDTH); }
};

class vp_udma_i2s_rx_cfg_ch1 : public vp::reg_32
{
public:
  inline void continous_set(uint32_t value) { this->set_field(value, UDMA_I2S_RX_CFG_CH1_CONTINOUS_BIT, UDMA_I2S_RX_CFG_CH1_CONTINOUS_WIDTH); }
  inline uint32_t continous_get() { return this->get_field(UDMA_I2S_RX_CFG_CH1_CONTINOUS_BIT, UDMA_I2S_RX_CFG_CH1_CONTINOUS_WIDTH); }
  inline void datasize_set(uint32_t value) { this->set_field(value, UDMA_I2S_RX_CFG_CH1_DATASIZE_BIT, UDMA_I2S_RX_CFG_CH1_DATASIZE_WIDTH); }
  inline uint32_t datasize_get() { return this->get_field(UDMA_I2S_RX_CFG_CH1_DATASIZE_BIT, UDMA_I2S_RX_CFG_CH1_DATASIZE_WIDTH); }
  inline void en_set(uint32_t value) { this->set_field(value, UDMA_I2S_RX_CFG_CH1_EN_BIT, UDMA_I2S_RX_CFG_CH1_EN_WIDTH); }
  inline uint32_t en_get() { return this->get_field(UDMA_I2S_RX_CFG_CH1_EN_BIT, UDMA_I2S_RX_CFG_CH1_EN_WIDTH); }
  inline void clr_set(uint32_t value) { this->set_field(value, UDMA_I2S_RX_CFG_CH1_CLR_BIT, UDMA_I2S_RX_CFG_CH1_CLR_WIDTH); }
  inline uint32_t clr_get() { return this->get_field(UDMA_I2S_RX_CFG_CH1_CLR_BIT, UDMA_I2S_RX_CFG_CH1_CLR_WIDTH); }
  inline void pending_set(uint32_t value) { this->set_field(value, UDMA_I2S_RX_CFG_CH1_PENDING_BIT, UDMA_I2S_RX_CFG_CH1_PENDING_WIDTH); }
  inline uint32_t pending_get() { return this->get_field(UDMA_I2S_RX_CFG_CH1_PENDING_BIT, UDMA_I2S_RX_CFG_CH1_PENDING_WIDTH); }
};

class vp_udma_i2s_cfg_ext : public vp::reg_32
{
public:
  inline void ext_bits_word_set(uint32_t value) { this->set_field(value, UDMA_I2S_CFG_EXT_EXT_BITS_WORD_BIT, UDMA_I2S_CFG_EXT_EXT_BITS_WORD_WIDTH); }
  inline uint32_t ext_bits_word_get() { return this->get_field(UDMA_I2S_CFG_EXT_EXT_BITS_WORD_BIT, UDMA_I2S_CFG_EXT_EXT_BITS_WORD_WIDTH); }
};

class vp_udma_i2s_cfg_clkgen0 : public vp::reg_32
{
public:
  inline void bits_word_set(uint32_t value) { this->set_field(value, UDMA_I2S_CFG_CLKGEN0_BITS_WORD_BIT, UDMA_I2S_CFG_CLKGEN0_BITS_WORD_WIDTH); }
  inline uint32_t bits_word_get() { return this->get_field(UDMA_I2S_CFG_CLKGEN0_BITS_WORD_BIT, UDMA_I2S_CFG_CLKGEN0_BITS_WORD_WIDTH); }
  inline void clk_en_set(uint32_t value) { this->set_field(value, UDMA_I2S_CFG_CLKGEN0_CLK_EN_BIT, UDMA_I2S_CFG_CLKGEN0_CLK_EN_WIDTH); }
  inline uint32_t clk_en_get() { return this->get_field(UDMA_I2S_CFG_CLKGEN0_CLK_EN_BIT, UDMA_I2S_CFG_CLKGEN0_CLK_EN_WIDTH); }
  inline void clk_div_set(uint32_t value) { this->set_field(value, UDMA_I2S_CFG_CLKGEN0_CLK_DIV_BIT, UDMA_I2S_CFG_CLKGEN0_CLK_DIV_WIDTH); }
  inline uint32_t clk_div_get() { return this->get_field(UDMA_I2S_CFG_CLKGEN0_CLK_DIV_BIT, UDMA_I2S_CFG_CLKGEN0_CLK_DIV_WIDTH); }
};

class vp_udma_i2s_cfg_clkgen1 : public vp::reg_32
{
public:
  inline void bits_word_set(uint32_t value) { this->set_field(value, UDMA_I2S_CFG_CLKGEN1_BITS_WORD_BIT, UDMA_I2S_CFG_CLKGEN1_BITS_WORD_WIDTH); }
  inline uint32_t bits_word_get() { return this->get_field(UDMA_I2S_CFG_CLKGEN1_BITS_WORD_BIT, UDMA_I2S_CFG_CLKGEN1_BITS_WORD_WIDTH); }
  inline void clk_en_set(uint32_t value) { this->set_field(value, UDMA_I2S_CFG_CLKGEN1_CLK_EN_BIT, UDMA_I2S_CFG_CLKGEN1_CLK_EN_WIDTH); }
  inline uint32_t clk_en_get() { return this->get_field(UDMA_I2S_CFG_CLKGEN1_CLK_EN_BIT, UDMA_I2S_CFG_CLKGEN1_CLK_EN_WIDTH); }
  inline void clk_div_set(uint32_t value) { this->set_field(value, UDMA_I2S_CFG_CLKGEN1_CLK_DIV_BIT, UDMA_I2S_CFG_CLKGEN1_CLK_DIV_WIDTH); }
  inline uint32_t clk_div_get() { return this->get_field(UDMA_I2S_CFG_CLKGEN1_CLK_DIV_BIT, UDMA_I2S_CFG_CLKGEN1_CLK_DIV_WIDTH); }
};

class vp_udma_i2s_chmode : public vp::reg_32
{
public:
  inline void ch0_lsb_first_set(uint32_t value) { this->set_field(value, UDMA_I2S_CHMODE_CH0_LSB_FIRST_BIT, UDMA_I2S_CHMODE_CH0_LSB_FIRST_WIDTH); }
  inline uint32_t ch0_lsb_first_get() { return this->get_field(UDMA_I2S_CHMODE_CH0_LSB_FIRST_BIT, UDMA_I2S_CHMODE_CH0_LSB_FIRST_WIDTH); }
  inline void ch0_pdm_usefilter_set(uint32_t value) { this->set_field(value, UDMA_I2S_CHMODE_CH0_PDM_USEFILTER_BIT, UDMA_I2S_CHMODE_CH0_PDM_USEFILTER_WIDTH); }
  inline uint32_t ch0_pdm_usefilter_get() { return this->get_field(UDMA_I2S_CHMODE_CH0_PDM_USEFILTER_BIT, UDMA_I2S_CHMODE_CH0_PDM_USEFILTER_WIDTH); }
  inline void ch0_pdm_en_set(uint32_t value) { this->set_field(value, UDMA_I2S_CHMODE_CH0_PDM_EN_BIT, UDMA_I2S_CHMODE_CH0_PDM_EN_WIDTH); }
  inline uint32_t ch0_pdm_en_get() { return this->get_field(UDMA_I2S_CHMODE_CH0_PDM_EN_BIT, UDMA_I2S_CHMODE_CH0_PDM_EN_WIDTH); }
  inline void ch0_useddr_set(uint32_t value) { this->set_field(value, UDMA_I2S_CHMODE_CH0_USEDDR_BIT, UDMA_I2S_CHMODE_CH0_USEDDR_WIDTH); }
  inline uint32_t ch0_useddr_get() { return this->get_field(UDMA_I2S_CHMODE_CH0_USEDDR_BIT, UDMA_I2S_CHMODE_CH0_USEDDR_WIDTH); }
  inline void ch0_mode_set(uint32_t value) { this->set_field(value, UDMA_I2S_CHMODE_CH0_MODE_BIT, UDMA_I2S_CHMODE_CH0_MODE_WIDTH); }
  inline uint32_t ch0_mode_get() { return this->get_field(UDMA_I2S_CHMODE_CH0_MODE_BIT, UDMA_I2S_CHMODE_CH0_MODE_WIDTH); }
  inline void ch1_lsb_first_set(uint32_t value) { this->set_field(value, UDMA_I2S_CHMODE_CH1_LSB_FIRST_BIT, UDMA_I2S_CHMODE_CH1_LSB_FIRST_WIDTH); }
  inline uint32_t ch1_lsb_first_get() { return this->get_field(UDMA_I2S_CHMODE_CH1_LSB_FIRST_BIT, UDMA_I2S_CHMODE_CH1_LSB_FIRST_WIDTH); }
  inline void ch1_pdm_usefilter_set(uint32_t value) { this->set_field(value, UDMA_I2S_CHMODE_CH1_PDM_USEFILTER_BIT, UDMA_I2S_CHMODE_CH1_PDM_USEFILTER_WIDTH); }
  inline uint32_t ch1_pdm_usefilter_get() { return this->get_field(UDMA_I2S_CHMODE_CH1_PDM_USEFILTER_BIT, UDMA_I2S_CHMODE_CH1_PDM_USEFILTER_WIDTH); }
  inline void ch1_pdm_en_set(uint32_t value) { this->set_field(value, UDMA_I2S_CHMODE_CH1_PDM_EN_BIT, UDMA_I2S_CHMODE_CH1_PDM_EN_WIDTH); }
  inline uint32_t ch1_pdm_en_get() { return this->get_field(UDMA_I2S_CHMODE_CH1_PDM_EN_BIT, UDMA_I2S_CHMODE_CH1_PDM_EN_WIDTH); }
  inline void ch1_useddr_set(uint32_t value) { this->set_field(value, UDMA_I2S_CHMODE_CH1_USEDDR_BIT, UDMA_I2S_CHMODE_CH1_USEDDR_WIDTH); }
  inline uint32_t ch1_useddr_get() { return this->get_field(UDMA_I2S_CHMODE_CH1_USEDDR_BIT, UDMA_I2S_CHMODE_CH1_USEDDR_WIDTH); }
  inline void ch1_mode_set(uint32_t value) { this->set_field(value, UDMA_I2S_CHMODE_CH1_MODE_BIT, UDMA_I2S_CHMODE_CH1_MODE_WIDTH); }
  inline uint32_t ch1_mode_get() { return this->get_field(UDMA_I2S_CHMODE_CH1_MODE_BIT, UDMA_I2S_CHMODE_CH1_MODE_WIDTH); }
};

class vp_udma_i2s_filt_ch0 : public vp::reg_32
{
public:
  inline void decimation_set(uint32_t value) { this->set_field(value, UDMA_I2S_FILT_CH0_DECIMATION_BIT, UDMA_I2S_FILT_CH0_DECIMATION_WIDTH); }
  inline uint32_t decimation_get() { return this->get_field(UDMA_I2S_FILT_CH0_DECIMATION_BIT, UDMA_I2S_FILT_CH0_DECIMATION_WIDTH); }
  inline void shift_set(uint32_t value) { this->set_field(value, UDMA_I2S_FILT_CH0_SHIFT_BIT, UDMA_I2S_FILT_CH0_SHIFT_WIDTH); }
  inline uint32_t shift_get() { return this->get_field(UDMA_I2S_FILT_CH0_SHIFT_BIT, UDMA_I2S_FILT_CH0_SHIFT_WIDTH); }
};

class vp_udma_i2s_filt_ch1 : public vp::reg_32
{
public:
  inline void decimation_set(uint32_t value) { this->set_field(value, UDMA_I2S_FILT_CH1_DECIMATION_BIT, UDMA_I2S_FILT_CH1_DECIMATION_WIDTH); }
  inline uint32_t decimation_get() { return this->get_field(UDMA_I2S_FILT_CH1_DECIMATION_BIT, UDMA_I2S_FILT_CH1_DECIMATION_WIDTH); }
  inline void shift_set(uint32_t value) { this->set_field(value, UDMA_I2S_FILT_CH1_SHIFT_BIT, UDMA_I2S_FILT_CH1_SHIFT_WIDTH); }
  inline uint32_t shift_get() { return this->get_field(UDMA_I2S_FILT_CH1_SHIFT_BIT, UDMA_I2S_FILT_CH1_SHIFT_WIDTH); }
};

#endif



//
// REGISTERS GLOBAL STRUCT
//

#ifndef LANGUAGE_ASSEMBLY

typedef struct {
  unsigned int rx_saddr_ch0    ; // uDMA RX I2S channel 0 buffer base address configuration register.
  unsigned int rx_size_ch0     ; // uDMA RX I2S channel 0 buffer size configuration register.
  unsigned int rx_cfg_ch0      ; // uDMA RX I2S channel 0 stream configuration register.
  unsigned int rx_saddr_ch1    ; // uDMA RX I2S channel 1 buffer base address configuration register.
  unsigned int rx_size_ch1     ; // uDMA RX I2S channel 1 buffer size configuration register.
  unsigned int rx_cfg_ch1      ; // uDMA RX I2S channel 1 stream configuration register.
  unsigned int cfg_ext         ; // I2S external clock configuration register.
  unsigned int cfg_clkgen0     ; // I2S clock and WS generator 0 configuration register.
  unsigned int cfg_clkgen1     ; // I2S clock and WS generator 1 configuration register.
  unsigned int chmode          ; // I2S channels mode configuration register.
  unsigned int filt_ch0        ; // I2S channel 0 filtering configuration register.
  unsigned int filt_ch1        ; // I2S channel 1 filtering configuration register.
} __attribute__((packed)) udma_i2s_udma_i2s_t;

#endif



//
// REGISTERS ACCESS FUNCTIONS
//

#ifndef LANGUAGE_ASSEMBLY

static inline uint32_t udma_i2s_rx_saddr_ch0_get(uint32_t base) { return ARCHI_READ(base, UDMA_I2S_RX_SADDR_CH0_OFFSET); }
static inline void udma_i2s_rx_saddr_ch0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_I2S_RX_SADDR_CH0_OFFSET, value); }

static inline uint32_t udma_i2s_rx_size_ch0_get(uint32_t base) { return ARCHI_READ(base, UDMA_I2S_RX_SIZE_CH0_OFFSET); }
static inline void udma_i2s_rx_size_ch0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_I2S_RX_SIZE_CH0_OFFSET, value); }

static inline uint32_t udma_i2s_rx_cfg_ch0_get(uint32_t base) { return ARCHI_READ(base, UDMA_I2S_RX_CFG_CH0_OFFSET); }
static inline void udma_i2s_rx_cfg_ch0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_I2S_RX_CFG_CH0_OFFSET, value); }

static inline uint32_t udma_i2s_rx_saddr_ch1_get(uint32_t base) { return ARCHI_READ(base, UDMA_I2S_RX_SADDR_CH1_OFFSET); }
static inline void udma_i2s_rx_saddr_ch1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_I2S_RX_SADDR_CH1_OFFSET, value); }

static inline uint32_t udma_i2s_rx_size_ch1_get(uint32_t base) { return ARCHI_READ(base, UDMA_I2S_RX_SIZE_CH1_OFFSET); }
static inline void udma_i2s_rx_size_ch1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_I2S_RX_SIZE_CH1_OFFSET, value); }

static inline uint32_t udma_i2s_rx_cfg_ch1_get(uint32_t base) { return ARCHI_READ(base, UDMA_I2S_RX_CFG_CH1_OFFSET); }
static inline void udma_i2s_rx_cfg_ch1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_I2S_RX_CFG_CH1_OFFSET, value); }

static inline uint32_t udma_i2s_cfg_ext_get(uint32_t base) { return ARCHI_READ(base, UDMA_I2S_CFG_EXT_OFFSET); }
static inline void udma_i2s_cfg_ext_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_I2S_CFG_EXT_OFFSET, value); }

static inline uint32_t udma_i2s_cfg_clkgen0_get(uint32_t base) { return ARCHI_READ(base, UDMA_I2S_CFG_CLKGEN0_OFFSET); }
static inline void udma_i2s_cfg_clkgen0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_I2S_CFG_CLKGEN0_OFFSET, value); }

static inline uint32_t udma_i2s_cfg_clkgen1_get(uint32_t base) { return ARCHI_READ(base, UDMA_I2S_CFG_CLKGEN1_OFFSET); }
static inline void udma_i2s_cfg_clkgen1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_I2S_CFG_CLKGEN1_OFFSET, value); }

static inline uint32_t udma_i2s_chmode_get(uint32_t base) { return ARCHI_READ(base, UDMA_I2S_CHMODE_OFFSET); }
static inline void udma_i2s_chmode_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_I2S_CHMODE_OFFSET, value); }

static inline uint32_t udma_i2s_filt_ch0_get(uint32_t base) { return ARCHI_READ(base, UDMA_I2S_FILT_CH0_OFFSET); }
static inline void udma_i2s_filt_ch0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_I2S_FILT_CH0_OFFSET, value); }

static inline uint32_t udma_i2s_filt_ch1_get(uint32_t base) { return ARCHI_READ(base, UDMA_I2S_FILT_CH1_OFFSET); }
static inline void udma_i2s_filt_ch1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, UDMA_I2S_FILT_CH1_OFFSET, value); }

#endif



//
// REGISTERS FIELDS MACROS
//

#ifndef LANGUAGE_ASSEMBLY

#define UDMA_I2S_RX_SADDR_CH0_RX_SADDR_GET(value)          (ARCHI_BEXTRACTU((value),16,0))
#define UDMA_I2S_RX_SADDR_CH0_RX_SADDR_GETS(value)         (ARCHI_BEXTRACT((value),16,0))
#define UDMA_I2S_RX_SADDR_CH0_RX_SADDR_SET(value,field)    (ARCHI_BINSERT((value),(field),16,0))
#define UDMA_I2S_RX_SADDR_CH0_RX_SADDR(val)                ((val) << 0)

#define UDMA_I2S_RX_SIZE_CH0_RX_SIZE_GET(value)            (ARCHI_BEXTRACTU((value),17,0))
#define UDMA_I2S_RX_SIZE_CH0_RX_SIZE_GETS(value)           (ARCHI_BEXTRACT((value),17,0))
#define UDMA_I2S_RX_SIZE_CH0_RX_SIZE_SET(value,field)      (ARCHI_BINSERT((value),(field),17,0))
#define UDMA_I2S_RX_SIZE_CH0_RX_SIZE(val)                  ((val) << 0)

#define UDMA_I2S_RX_CFG_CH0_CONTINOUS_GET(value)           (ARCHI_BEXTRACTU((value),1,0))
#define UDMA_I2S_RX_CFG_CH0_CONTINOUS_GETS(value)          (ARCHI_BEXTRACT((value),1,0))
#define UDMA_I2S_RX_CFG_CH0_CONTINOUS_SET(value,field)     (ARCHI_BINSERT((value),(field),1,0))
#define UDMA_I2S_RX_CFG_CH0_CONTINOUS(val)                 ((val) << 0)

#define UDMA_I2S_RX_CFG_CH0_DATASIZE_GET(value)            (ARCHI_BEXTRACTU((value),2,1))
#define UDMA_I2S_RX_CFG_CH0_DATASIZE_GETS(value)           (ARCHI_BEXTRACT((value),2,1))
#define UDMA_I2S_RX_CFG_CH0_DATASIZE_SET(value,field)      (ARCHI_BINSERT((value),(field),2,1))
#define UDMA_I2S_RX_CFG_CH0_DATASIZE(val)                  ((val) << 1)

#define UDMA_I2S_RX_CFG_CH0_EN_GET(value)                  (ARCHI_BEXTRACTU((value),1,4))
#define UDMA_I2S_RX_CFG_CH0_EN_GETS(value)                 (ARCHI_BEXTRACT((value),1,4))
#define UDMA_I2S_RX_CFG_CH0_EN_SET(value,field)            (ARCHI_BINSERT((value),(field),1,4))
#define UDMA_I2S_RX_CFG_CH0_EN(val)                        ((val) << 4)

#define UDMA_I2S_RX_CFG_CH0_CLR_GET(value)                 (ARCHI_BEXTRACTU((value),1,5))
#define UDMA_I2S_RX_CFG_CH0_CLR_GETS(value)                (ARCHI_BEXTRACT((value),1,5))
#define UDMA_I2S_RX_CFG_CH0_CLR_SET(value,field)           (ARCHI_BINSERT((value),(field),1,5))
#define UDMA_I2S_RX_CFG_CH0_CLR(val)                       ((val) << 5)

#define UDMA_I2S_RX_CFG_CH0_PENDING_GET(value)             (ARCHI_BEXTRACTU((value),1,5))
#define UDMA_I2S_RX_CFG_CH0_PENDING_GETS(value)            (ARCHI_BEXTRACT((value),1,5))
#define UDMA_I2S_RX_CFG_CH0_PENDING_SET(value,field)       (ARCHI_BINSERT((value),(field),1,5))
#define UDMA_I2S_RX_CFG_CH0_PENDING(val)                   ((val) << 5)

#define UDMA_I2S_RX_SADDR_CH1_TX_SADDR_GET(value)          (ARCHI_BEXTRACTU((value),16,0))
#define UDMA_I2S_RX_SADDR_CH1_TX_SADDR_GETS(value)         (ARCHI_BEXTRACT((value),16,0))
#define UDMA_I2S_RX_SADDR_CH1_TX_SADDR_SET(value,field)    (ARCHI_BINSERT((value),(field),16,0))
#define UDMA_I2S_RX_SADDR_CH1_TX_SADDR(val)                ((val) << 0)

#define UDMA_I2S_RX_SIZE_CH1_TX_SIZE_GET(value)            (ARCHI_BEXTRACTU((value),17,0))
#define UDMA_I2S_RX_SIZE_CH1_TX_SIZE_GETS(value)           (ARCHI_BEXTRACT((value),17,0))
#define UDMA_I2S_RX_SIZE_CH1_TX_SIZE_SET(value,field)      (ARCHI_BINSERT((value),(field),17,0))
#define UDMA_I2S_RX_SIZE_CH1_TX_SIZE(val)                  ((val) << 0)

#define UDMA_I2S_RX_CFG_CH1_CONTINOUS_GET(value)           (ARCHI_BEXTRACTU((value),1,0))
#define UDMA_I2S_RX_CFG_CH1_CONTINOUS_GETS(value)          (ARCHI_BEXTRACT((value),1,0))
#define UDMA_I2S_RX_CFG_CH1_CONTINOUS_SET(value,field)     (ARCHI_BINSERT((value),(field),1,0))
#define UDMA_I2S_RX_CFG_CH1_CONTINOUS(val)                 ((val) << 0)

#define UDMA_I2S_RX_CFG_CH1_DATASIZE_GET(value)            (ARCHI_BEXTRACTU((value),2,1))
#define UDMA_I2S_RX_CFG_CH1_DATASIZE_GETS(value)           (ARCHI_BEXTRACT((value),2,1))
#define UDMA_I2S_RX_CFG_CH1_DATASIZE_SET(value,field)      (ARCHI_BINSERT((value),(field),2,1))
#define UDMA_I2S_RX_CFG_CH1_DATASIZE(val)                  ((val) << 1)

#define UDMA_I2S_RX_CFG_CH1_EN_GET(value)                  (ARCHI_BEXTRACTU((value),1,4))
#define UDMA_I2S_RX_CFG_CH1_EN_GETS(value)                 (ARCHI_BEXTRACT((value),1,4))
#define UDMA_I2S_RX_CFG_CH1_EN_SET(value,field)            (ARCHI_BINSERT((value),(field),1,4))
#define UDMA_I2S_RX_CFG_CH1_EN(val)                        ((val) << 4)

#define UDMA_I2S_RX_CFG_CH1_CLR_GET(value)                 (ARCHI_BEXTRACTU((value),1,5))
#define UDMA_I2S_RX_CFG_CH1_CLR_GETS(value)                (ARCHI_BEXTRACT((value),1,5))
#define UDMA_I2S_RX_CFG_CH1_CLR_SET(value,field)           (ARCHI_BINSERT((value),(field),1,5))
#define UDMA_I2S_RX_CFG_CH1_CLR(val)                       ((val) << 5)

#define UDMA_I2S_RX_CFG_CH1_PENDING_GET(value)             (ARCHI_BEXTRACTU((value),1,5))
#define UDMA_I2S_RX_CFG_CH1_PENDING_GETS(value)            (ARCHI_BEXTRACT((value),1,5))
#define UDMA_I2S_RX_CFG_CH1_PENDING_SET(value,field)       (ARCHI_BINSERT((value),(field),1,5))
#define UDMA_I2S_RX_CFG_CH1_PENDING(val)                   ((val) << 5)

#define UDMA_I2S_CFG_EXT_EXT_BITS_WORD_GET(value)          (ARCHI_BEXTRACTU((value),5,0))
#define UDMA_I2S_CFG_EXT_EXT_BITS_WORD_GETS(value)         (ARCHI_BEXTRACT((value),5,0))
#define UDMA_I2S_CFG_EXT_EXT_BITS_WORD_SET(value,field)    (ARCHI_BINSERT((value),(field),5,0))
#define UDMA_I2S_CFG_EXT_EXT_BITS_WORD(val)                ((val) << 0)

#define UDMA_I2S_CFG_CLKGEN0_BITS_WORD_GET(value)          (ARCHI_BEXTRACTU((value),5,0))
#define UDMA_I2S_CFG_CLKGEN0_BITS_WORD_GETS(value)         (ARCHI_BEXTRACT((value),5,0))
#define UDMA_I2S_CFG_CLKGEN0_BITS_WORD_SET(value,field)    (ARCHI_BINSERT((value),(field),5,0))
#define UDMA_I2S_CFG_CLKGEN0_BITS_WORD(val)                ((val) << 0)

#define UDMA_I2S_CFG_CLKGEN0_CLK_EN_GET(value)             (ARCHI_BEXTRACTU((value),1,8))
#define UDMA_I2S_CFG_CLKGEN0_CLK_EN_GETS(value)            (ARCHI_BEXTRACT((value),1,8))
#define UDMA_I2S_CFG_CLKGEN0_CLK_EN_SET(value,field)       (ARCHI_BINSERT((value),(field),1,8))
#define UDMA_I2S_CFG_CLKGEN0_CLK_EN(val)                   ((val) << 8)

#define UDMA_I2S_CFG_CLKGEN0_CLK_DIV_GET(value)            (ARCHI_BEXTRACTU((value),16,16))
#define UDMA_I2S_CFG_CLKGEN0_CLK_DIV_GETS(value)           (ARCHI_BEXTRACT((value),16,16))
#define UDMA_I2S_CFG_CLKGEN0_CLK_DIV_SET(value,field)      (ARCHI_BINSERT((value),(field),16,16))
#define UDMA_I2S_CFG_CLKGEN0_CLK_DIV(val)                  ((val) << 16)

#define UDMA_I2S_CFG_CLKGEN1_BITS_WORD_GET(value)          (ARCHI_BEXTRACTU((value),5,0))
#define UDMA_I2S_CFG_CLKGEN1_BITS_WORD_GETS(value)         (ARCHI_BEXTRACT((value),5,0))
#define UDMA_I2S_CFG_CLKGEN1_BITS_WORD_SET(value,field)    (ARCHI_BINSERT((value),(field),5,0))
#define UDMA_I2S_CFG_CLKGEN1_BITS_WORD(val)                ((val) << 0)

#define UDMA_I2S_CFG_CLKGEN1_CLK_EN_GET(value)             (ARCHI_BEXTRACTU((value),1,8))
#define UDMA_I2S_CFG_CLKGEN1_CLK_EN_GETS(value)            (ARCHI_BEXTRACT((value),1,8))
#define UDMA_I2S_CFG_CLKGEN1_CLK_EN_SET(value,field)       (ARCHI_BINSERT((value),(field),1,8))
#define UDMA_I2S_CFG_CLKGEN1_CLK_EN(val)                   ((val) << 8)

#define UDMA_I2S_CFG_CLKGEN1_CLK_DIV_GET(value)            (ARCHI_BEXTRACTU((value),16,16))
#define UDMA_I2S_CFG_CLKGEN1_CLK_DIV_GETS(value)           (ARCHI_BEXTRACT((value),16,16))
#define UDMA_I2S_CFG_CLKGEN1_CLK_DIV_SET(value,field)      (ARCHI_BINSERT((value),(field),16,16))
#define UDMA_I2S_CFG_CLKGEN1_CLK_DIV(val)                  ((val) << 16)

#define UDMA_I2S_CHMODE_CH0_LSB_FIRST_GET(value)           (ARCHI_BEXTRACTU((value),1,4))
#define UDMA_I2S_CHMODE_CH0_LSB_FIRST_GETS(value)          (ARCHI_BEXTRACT((value),1,4))
#define UDMA_I2S_CHMODE_CH0_LSB_FIRST_SET(value,field)     (ARCHI_BINSERT((value),(field),1,4))
#define UDMA_I2S_CHMODE_CH0_LSB_FIRST(val)                 ((val) << 4)

#define UDMA_I2S_CHMODE_CH0_PDM_USEFILTER_GET(value)       (ARCHI_BEXTRACTU((value),1,8))
#define UDMA_I2S_CHMODE_CH0_PDM_USEFILTER_GETS(value)      (ARCHI_BEXTRACT((value),1,8))
#define UDMA_I2S_CHMODE_CH0_PDM_USEFILTER_SET(value,field) (ARCHI_BINSERT((value),(field),1,8))
#define UDMA_I2S_CHMODE_CH0_PDM_USEFILTER(val)             ((val) << 8)

#define UDMA_I2S_CHMODE_CH0_PDM_EN_GET(value)              (ARCHI_BEXTRACTU((value),1,12))
#define UDMA_I2S_CHMODE_CH0_PDM_EN_GETS(value)             (ARCHI_BEXTRACT((value),1,12))
#define UDMA_I2S_CHMODE_CH0_PDM_EN_SET(value,field)        (ARCHI_BINSERT((value),(field),1,12))
#define UDMA_I2S_CHMODE_CH0_PDM_EN(val)                    ((val) << 12)

#define UDMA_I2S_CHMODE_CH0_USEDDR_GET(value)              (ARCHI_BEXTRACTU((value),1,16))
#define UDMA_I2S_CHMODE_CH0_USEDDR_GETS(value)             (ARCHI_BEXTRACT((value),1,16))
#define UDMA_I2S_CHMODE_CH0_USEDDR_SET(value,field)        (ARCHI_BINSERT((value),(field),1,16))
#define UDMA_I2S_CHMODE_CH0_USEDDR(val)                    ((val) << 16)

#define UDMA_I2S_CHMODE_CH0_MODE_GET(value)                (ARCHI_BEXTRACTU((value),2,24))
#define UDMA_I2S_CHMODE_CH0_MODE_GETS(value)               (ARCHI_BEXTRACT((value),2,24))
#define UDMA_I2S_CHMODE_CH0_MODE_SET(value,field)          (ARCHI_BINSERT((value),(field),2,24))
#define UDMA_I2S_CHMODE_CH0_MODE(val)                      ((val) << 24)

#define UDMA_I2S_CHMODE_CH1_LSB_FIRST_GET(value)           (ARCHI_BEXTRACTU((value),1,5))
#define UDMA_I2S_CHMODE_CH1_LSB_FIRST_GETS(value)          (ARCHI_BEXTRACT((value),1,5))
#define UDMA_I2S_CHMODE_CH1_LSB_FIRST_SET(value,field)     (ARCHI_BINSERT((value),(field),1,5))
#define UDMA_I2S_CHMODE_CH1_LSB_FIRST(val)                 ((val) << 5)

#define UDMA_I2S_CHMODE_CH1_PDM_USEFILTER_GET(value)       (ARCHI_BEXTRACTU((value),1,9))
#define UDMA_I2S_CHMODE_CH1_PDM_USEFILTER_GETS(value)      (ARCHI_BEXTRACT((value),1,9))
#define UDMA_I2S_CHMODE_CH1_PDM_USEFILTER_SET(value,field) (ARCHI_BINSERT((value),(field),1,9))
#define UDMA_I2S_CHMODE_CH1_PDM_USEFILTER(val)             ((val) << 9)

#define UDMA_I2S_CHMODE_CH1_PDM_EN_GET(value)              (ARCHI_BEXTRACTU((value),1,13))
#define UDMA_I2S_CHMODE_CH1_PDM_EN_GETS(value)             (ARCHI_BEXTRACT((value),1,13))
#define UDMA_I2S_CHMODE_CH1_PDM_EN_SET(value,field)        (ARCHI_BINSERT((value),(field),1,13))
#define UDMA_I2S_CHMODE_CH1_PDM_EN(val)                    ((val) << 13)

#define UDMA_I2S_CHMODE_CH1_USEDDR_GET(value)              (ARCHI_BEXTRACTU((value),1,17))
#define UDMA_I2S_CHMODE_CH1_USEDDR_GETS(value)             (ARCHI_BEXTRACT((value),1,17))
#define UDMA_I2S_CHMODE_CH1_USEDDR_SET(value,field)        (ARCHI_BINSERT((value),(field),1,17))
#define UDMA_I2S_CHMODE_CH1_USEDDR(val)                    ((val) << 17)

#define UDMA_I2S_CHMODE_CH1_MODE_GET(value)                (ARCHI_BEXTRACTU((value),2,26))
#define UDMA_I2S_CHMODE_CH1_MODE_GETS(value)               (ARCHI_BEXTRACT((value),2,26))
#define UDMA_I2S_CHMODE_CH1_MODE_SET(value,field)          (ARCHI_BINSERT((value),(field),2,26))
#define UDMA_I2S_CHMODE_CH1_MODE(val)                      ((val) << 26)

#define UDMA_I2S_FILT_CH0_DECIMATION_GET(value)            (ARCHI_BEXTRACTU((value),10,0))
#define UDMA_I2S_FILT_CH0_DECIMATION_GETS(value)           (ARCHI_BEXTRACT((value),10,0))
#define UDMA_I2S_FILT_CH0_DECIMATION_SET(value,field)      (ARCHI_BINSERT((value),(field),10,0))
#define UDMA_I2S_FILT_CH0_DECIMATION(val)                  ((val) << 0)

#define UDMA_I2S_FILT_CH0_SHIFT_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define UDMA_I2S_FILT_CH0_SHIFT_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define UDMA_I2S_FILT_CH0_SHIFT_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define UDMA_I2S_FILT_CH0_SHIFT(val)                       ((val) << 16)

#define UDMA_I2S_FILT_CH1_DECIMATION_GET(value)            (ARCHI_BEXTRACTU((value),10,0))
#define UDMA_I2S_FILT_CH1_DECIMATION_GETS(value)           (ARCHI_BEXTRACT((value),10,0))
#define UDMA_I2S_FILT_CH1_DECIMATION_SET(value,field)      (ARCHI_BINSERT((value),(field),10,0))
#define UDMA_I2S_FILT_CH1_DECIMATION(val)                  ((val) << 0)

#define UDMA_I2S_FILT_CH1_SHIFT_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define UDMA_I2S_FILT_CH1_SHIFT_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define UDMA_I2S_FILT_CH1_SHIFT_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define UDMA_I2S_FILT_CH1_SHIFT(val)                       ((val) << 16)

#endif

#endif
