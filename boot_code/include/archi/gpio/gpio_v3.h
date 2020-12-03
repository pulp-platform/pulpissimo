
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

#ifndef __INCLUDE_ARCHI_GPIO_GPIO_V3_H__
#define __INCLUDE_ARCHI_GPIO_GPIO_V3_H__

#ifndef LANGUAGE_ASSEMBLY

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS
//

// GPIO pad direction configuration register.
#define GPIO_PADDIR_OFFSET                       0x0

// GPIO enable register.
#define GPIO_GPIOEN_OFFSET                       0x4

// GPIO pad input value register.
#define GPIO_PADIN_OFFSET                        0x8

// GPIO pad output value register.
#define GPIO_PADOUT_OFFSET                       0xc

// GPIO pad output set register.
#define GPIO_PADOUTSET_OFFSET                    0x10

// GPIO pad output clear register.
#define GPIO_PADOUTCLR_OFFSET                    0x14

// GPIO pad interrupt enable configuration register.
#define GPIO_INTEN_OFFSET                        0x18

// GPIO pad interrupt type gpio 0 to 15 register.
#define GPIO_INTTYPE0_OFFSET                     0x1c

// GPIO pad interrupt type gpio 16 to 31 register.
#define GPIO_INTTYPE1_OFFSET                     0x20

// GPIO pad interrupt status register.
#define GPIO_INTSTATUS_OFFSET                    0x24

// GPIO pad pin 0 to 7 configuration register.
#define GPIO_PADCFG0_OFFSET                      0x28

// GPIO pad pin 8 to 15 configuration register.
#define GPIO_PADCFG1_OFFSET                      0x2c

// GPIO pad pin 16 to 23 configuration register.
#define GPIO_PADCFG2_OFFSET                      0x30

// GPIO pad pin 24 to 31 configuration register.
#define GPIO_PADCFG3_OFFSET                      0x34

// GPIO pad direction configuration register.
#define GPIO_PADDIR_32_63_OFFSET                 0x38

// GPIO enable register.
#define GPIO_GPIOEN_32_63_OFFSET                 0x3c

// GPIO pad input value register.
#define GPIO_PADIN_32_63_OFFSET                  0x40

// GPIO pad output value register.
#define GPIO_PADOUT_32_63_OFFSET                 0x44

// GPIO pad output set register.
#define GPIO_PADOUTSET_32_63_OFFSET              0x48

// GPIO pad output clear register.
#define GPIO_PADOUTCLR_32_63_OFFSET              0x4c

// GPIO pad interrupt enable configuration register.
#define GPIO_INTEN_32_63_OFFSET                  0x50

// GPIO pad interrupt type gpio 32 to 47 register.
#define GPIO_INTTYPE_32_47_OFFSET                0x54

// GPIO pad interrupt type gpio 48 to 63 register.
#define GPIO_INTTYPE_48_63_OFFSET                0x58

// GPIO pad interrupt status register.
#define GPIO_INTSTATUS_32_63_OFFSET              0x5c

// GPIO pad pin 32 to 39 configuration register.
#define GPIO_PADCFG_32_39_OFFSET                 0x60

// GPIO pad pin 40 to 47 configuration register.
#define GPIO_PADCFG_40_47_OFFSET                 0x64

// GPIO pad pin 48 to 55 configuration register.
#define GPIO_PADCFG_48_55_OFFSET                 0x68

// GPIO pad pin 56 to 63 configuration register.
#define GPIO_PADCFG_56_63_OFFSET                 0x6c



//
// REGISTERS FIELDS
//

// GPIO[31:0] direction configuration bitfield: - bit[i]=1'b0: Input mode for GPIO[i] - bit[i]=1'b1: Output mode for GPIO[i] (access: R/W)
#define GPIO_PADDIR_DIR_BIT                                          0
#define GPIO_PADDIR_DIR_WIDTH                                        32
#define GPIO_PADDIR_DIR_MASK                                         0xffffffff

// GPIO[31:0] clock enable configuration bitfield: - bit[i]=1'b0: disable clock for GPIO[i] - bit[i]=1'b1: enable clock for GPIO[i] GPIOs are gathered by groups of 4. The clock gating of one group is done only if all 4 GPIOs are disabled.  Clock must be enabled for a GPIO if it's direction is configured in input mode. (access: R/W)
#define GPIO_GPIOEN_GPIOEN_BIT                                       0
#define GPIO_GPIOEN_GPIOEN_WIDTH                                     32
#define GPIO_GPIOEN_GPIOEN_MASK                                      0xffffffff

// GPIO[31:0] input data read bitfield. DATA_IN[i] corresponds to input data of GPIO[i]. (access: R)
#define GPIO_PADIN_DATA_IN_BIT                                       0
#define GPIO_PADIN_DATA_IN_WIDTH                                     32
#define GPIO_PADIN_DATA_IN_MASK                                      0xffffffff

// GPIO[31:0] output data read bitfield. DATA_OUT[i] corresponds to output data set on GPIO[i]. (access: R/W)
#define GPIO_PADOUT_DATA_OUT_BIT                                     0
#define GPIO_PADOUT_DATA_OUT_WIDTH                                   32
#define GPIO_PADOUT_DATA_OUT_MASK                                    0xffffffff

// GPIO[31:0] set bitfield: - bit[i]=1'b0: No change for GPIO[i] - bit[i]=1'b1: Sets GPIO[i] to 1 (access: W)
#define GPIO_PADOUTSET_DATA_SET_BIT                                  0
#define GPIO_PADOUTSET_DATA_SET_WIDTH                                32
#define GPIO_PADOUTSET_DATA_SET_MASK                                 0xffffffff

// GPIO[31:0] clear bitfield: - bit[i]=1'b0: No change for GPIO[i] - bit[i]=1'b1: Clears GPIO[i] (access: W)
#define GPIO_PADOUTCLR_DATA_CLEAR_BIT                                0
#define GPIO_PADOUTCLR_DATA_CLEAR_WIDTH                              32
#define GPIO_PADOUTCLR_DATA_CLEAR_MASK                               0xffffffff

// GPIO[31:0] interrupt enable configuration bitfield: - bit[i]=1'b0: disable interrupt for GPIO[i] - bit[i]=1'b1: enable interrupt for GPIO[i] (access: R/W)
#define GPIO_INTEN_INTEN_BIT                                         0
#define GPIO_INTEN_INTEN_WIDTH                                       32
#define GPIO_INTEN_INTEN_MASK                                        0xffffffff

// GPIO[15:0] interrupt type configuration bitfield: - bit[2*i+1:2*i]=2'b00: interrupt on falling edge for GPIO[i] - bit[2*i+1:2*i]=2'b01: interrupt on rising edge for GPIO[i] - bit[2*i+1:2*i]=2'b10: interrupt on rising and falling edge for GPIO[i] - bit[2*i+1:2*i]=2'b11: RFU (access: R/W)
#define GPIO_INTTYPE0_INTTYPE0_BIT                                   0
#define GPIO_INTTYPE0_INTTYPE0_WIDTH                                 32
#define GPIO_INTTYPE0_INTTYPE0_MASK                                  0xffffffff

// GPIO[31:16] interrupt type configuration bitfield: - bit[2*i+1:2*i]=2'b00: interrupt on falling edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b01: interrupt on rising edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b10: interrupt on rising and falling edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b11: RFU (access: R/W)
#define GPIO_INTTYPE1_INTTYPE1_BIT                                   0
#define GPIO_INTTYPE1_INTTYPE1_WIDTH                                 32
#define GPIO_INTTYPE1_INTTYPE1_MASK                                  0xffffffff

// GPIO[31:0] Interrupt status flags bitfield. INTSTATUS[i]=1 when interrupt received on GPIO[i]. INTSTATUS is cleared when it is red. GPIO interrupt line is also cleared when INTSTATUS register is red. (access: R)
#define GPIO_INTSTATUS_INTSTATUS_BIT                                 0
#define GPIO_INTSTATUS_INTSTATUS_WIDTH                               32
#define GPIO_INTSTATUS_INTSTATUS_MASK                                0xffffffff

// GPIO[0] pull activation configuration bitfield: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_PADCFG0_GPIO0_CFG_BIT                                   0
#define GPIO_PADCFG0_GPIO0_CFG_WIDTH                                 4
#define GPIO_PADCFG0_GPIO0_CFG_MASK                                  0xf

// GPIO[0] drive strength configuration bitfield: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_PADCFG0_GPIO1_CFG_BIT                                   4
#define GPIO_PADCFG0_GPIO1_CFG_WIDTH                                 4
#define GPIO_PADCFG0_GPIO1_CFG_MASK                                  0xf0

// GPIO[1] pull activation configuration bitfield: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_PADCFG0_GPIO2_CFG_BIT                                   8
#define GPIO_PADCFG0_GPIO2_CFG_WIDTH                                 4
#define GPIO_PADCFG0_GPIO2_CFG_MASK                                  0xf00

// GPIO[1] drive strength configuration bitfield: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_PADCFG0_GPIO3_CFG_BIT                                   12
#define GPIO_PADCFG0_GPIO3_CFG_WIDTH                                 4
#define GPIO_PADCFG0_GPIO3_CFG_MASK                                  0xf000

// GPIO[2] pull activation configuration bitfield: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_PADCFG0_GPIO4_CFG_BIT                                   16
#define GPIO_PADCFG0_GPIO4_CFG_WIDTH                                 4
#define GPIO_PADCFG0_GPIO4_CFG_MASK                                  0xf0000

// GPIO[2] drive strength configuration bitfield: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_PADCFG0_GPIO5_CFG_BIT                                   20
#define GPIO_PADCFG0_GPIO5_CFG_WIDTH                                 4
#define GPIO_PADCFG0_GPIO5_CFG_MASK                                  0xf00000

// GPIO[3] pull activation configuration bitfield: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_PADCFG0_GPIO6_CFG_BIT                                   24
#define GPIO_PADCFG0_GPIO6_CFG_WIDTH                                 4
#define GPIO_PADCFG0_GPIO6_CFG_MASK                                  0xf000000

// GPIO[3] drive strength configuration bitfield: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_PADCFG0_GPIO7_CFG_BIT                                   28
#define GPIO_PADCFG0_GPIO7_CFG_WIDTH                                 4
#define GPIO_PADCFG0_GPIO7_CFG_MASK                                  0xf0000000

// GPIO[4] pull activation configuration bitfield: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_PADCFG1_GPIO4_PE_BIT                                    0
#define GPIO_PADCFG1_GPIO4_PE_WIDTH                                  1
#define GPIO_PADCFG1_GPIO4_PE_MASK                                   0x1

// GPIO[4] drive strength configuration bitfield: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_PADCFG1_GPIO4_DS_BIT                                    1
#define GPIO_PADCFG1_GPIO4_DS_WIDTH                                  1
#define GPIO_PADCFG1_GPIO4_DS_MASK                                   0x2

// GPIO[63:32] direction configuration bitfield: - bit[i]=1'b0: Input mode for GPIO[i] - bit[i]=1'b1: Output mode for GPIO[i] (access: R/W)
#define GPIO_PADDIR_32_63_DIR_BIT                                    0
#define GPIO_PADDIR_32_63_DIR_WIDTH                                  32
#define GPIO_PADDIR_32_63_DIR_MASK                                   0xffffffff

// GPIO[63:32] clock enable configuration bitfield: - bit[i]=1'b0: disable clock for GPIO[i] - bit[i]=1'b1: enable clock for GPIO[i] GPIOs are gathered by groups of 4. The clock gating of one group is done only if all 4 GPIOs are disabled.  Clock must be enabled for a GPIO if it's direction is configured in input mode. (access: R/W)
#define GPIO_GPIOEN_32_63_GPIOEN_BIT                                 0
#define GPIO_GPIOEN_32_63_GPIOEN_WIDTH                               32
#define GPIO_GPIOEN_32_63_GPIOEN_MASK                                0xffffffff

// GPIO[63:32] input data read bitfield. DATA_IN[i] corresponds to input data of GPIO[i]. (access: R)
#define GPIO_PADIN_32_63_DATA_IN_BIT                                 0
#define GPIO_PADIN_32_63_DATA_IN_WIDTH                               32
#define GPIO_PADIN_32_63_DATA_IN_MASK                                0xffffffff

// GPIO[63:32] output data read bitfield. DATA_OUT[i] corresponds to output data set on GPIO[i]. (access: R/W)
#define GPIO_PADOUT_32_63_DATA_OUT_BIT                               0
#define GPIO_PADOUT_32_63_DATA_OUT_WIDTH                             32
#define GPIO_PADOUT_32_63_DATA_OUT_MASK                              0xffffffff

// GPIO[63:32] set bitfield: - bit[i]=1'b0: No change for GPIO[i] - bit[i]=1'b1: Sets GPIO[i] to 1 (access: W)
#define GPIO_PADOUTSET_32_63_DATA_SET_BIT                            0
#define GPIO_PADOUTSET_32_63_DATA_SET_WIDTH                          32
#define GPIO_PADOUTSET_32_63_DATA_SET_MASK                           0xffffffff

// GPIO[63:32] clear bitfield: - bit[i]=1'b0: No change for GPIO[i] - bit[i]=1'b1: Clears GPIO[i] (access: W)
#define GPIO_PADOUTCLR_32_63_DATA_CLEAR_BIT                          0
#define GPIO_PADOUTCLR_32_63_DATA_CLEAR_WIDTH                        32
#define GPIO_PADOUTCLR_32_63_DATA_CLEAR_MASK                         0xffffffff

// GPIO[63:32] interrupt enable configuration bitfield: - bit[i]=1'b0: disable interrupt for GPIO[i] - bit[i]=1'b1: enable interrupt for GPIO[i] (access: R/W)
#define GPIO_INTEN_32_63_INTEN_BIT                                   0
#define GPIO_INTEN_32_63_INTEN_WIDTH                                 32
#define GPIO_INTEN_32_63_INTEN_MASK                                  0xffffffff

// GPIO[47:32] interrupt type configuration bitfield: - bit[2*i+1:2*i]=2'b00: interrupt on falling edge for GPIO[i] - bit[2*i+1:2*i]=2'b01: interrupt on rising edge for GPIO[i] - bit[2*i+1:2*i]=2'b10: interrupt on rising and falling edge for GPIO[i] - bit[2*i+1:2*i]=2'b11: RFU (access: R/W)
#define GPIO_INTTYPE_32_47_INTTYPE0_BIT                              0
#define GPIO_INTTYPE_32_47_INTTYPE0_WIDTH                            32
#define GPIO_INTTYPE_32_47_INTTYPE0_MASK                             0xffffffff

// GPIO[63:48] interrupt type configuration bitfield: - bit[2*i+1:2*i]=2'b00: interrupt on falling edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b01: interrupt on rising edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b10: interrupt on rising and falling edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b11: RFU (access: R/W)
#define GPIO_INTTYPE_48_63_INTTYPE1_BIT                              0
#define GPIO_INTTYPE_48_63_INTTYPE1_WIDTH                            32
#define GPIO_INTTYPE_48_63_INTTYPE1_MASK                             0xffffffff

// GPIO[63:32] Interrupt status flags bitfield. INTSTATUS[i]=1 when interrupt received on GPIO[i]. INTSTATUS is cleared when it is red. GPIO interrupt line is also cleared when INTSTATUS register is red. (access: R)
#define GPIO_INTSTATUS_32_63_INTSTATUS_BIT                           0
#define GPIO_INTSTATUS_32_63_INTSTATUS_WIDTH                         32
#define GPIO_INTSTATUS_32_63_INTSTATUS_MASK                          0xffffffff



//
// REGISTERS STRUCTS
//

#ifndef LANGUAGE_ASSEMBLY

typedef union {
  struct {
    unsigned int dir             :32; // GPIO[31:0] direction configuration bitfield: - bit[i]=1'b0: Input mode for GPIO[i] - bit[i]=1'b1: Output mode for GPIO[i]
  };
  unsigned int raw;
} __attribute__((packed)) gpio_paddir_t;

typedef union {
  struct {
    unsigned int gpioen          :32; // GPIO[31:0] clock enable configuration bitfield: - bit[i]=1'b0: disable clock for GPIO[i] - bit[i]=1'b1: enable clock for GPIO[i] GPIOs are gathered by groups of 4. The clock gating of one group is done only if all 4 GPIOs are disabled.  Clock must be enabled for a GPIO if it's direction is configured in input mode.
  };
  unsigned int raw;
} __attribute__((packed)) gpio_gpioen_t;

typedef union {
  struct {
    unsigned int data_in         :32; // GPIO[31:0] input data read bitfield. DATA_IN[i] corresponds to input data of GPIO[i].
  };
  unsigned int raw;
} __attribute__((packed)) gpio_padin_t;

typedef union {
  struct {
    unsigned int data_out        :32; // GPIO[31:0] output data read bitfield. DATA_OUT[i] corresponds to output data set on GPIO[i].
  };
  unsigned int raw;
} __attribute__((packed)) gpio_padout_t;

typedef union {
  struct {
    unsigned int data_set        :32; // GPIO[31:0] set bitfield: - bit[i]=1'b0: No change for GPIO[i] - bit[i]=1'b1: Sets GPIO[i] to 1
  };
  unsigned int raw;
} __attribute__((packed)) gpio_padoutset_t;

typedef union {
  struct {
    unsigned int data_clear      :32; // GPIO[31:0] clear bitfield: - bit[i]=1'b0: No change for GPIO[i] - bit[i]=1'b1: Clears GPIO[i]
  };
  unsigned int raw;
} __attribute__((packed)) gpio_padoutclr_t;

typedef union {
  struct {
    unsigned int inten           :32; // GPIO[31:0] interrupt enable configuration bitfield: - bit[i]=1'b0: disable interrupt for GPIO[i] - bit[i]=1'b1: enable interrupt for GPIO[i]
  };
  unsigned int raw;
} __attribute__((packed)) gpio_inten_t;

typedef union {
  struct {
    unsigned int inttype0        :32; // GPIO[15:0] interrupt type configuration bitfield: - bit[2*i+1:2*i]=2'b00: interrupt on falling edge for GPIO[i] - bit[2*i+1:2*i]=2'b01: interrupt on rising edge for GPIO[i] - bit[2*i+1:2*i]=2'b10: interrupt on rising and falling edge for GPIO[i] - bit[2*i+1:2*i]=2'b11: RFU
  };
  unsigned int raw;
} __attribute__((packed)) gpio_inttype0_t;

typedef union {
  struct {
    unsigned int inttype1        :32; // GPIO[31:16] interrupt type configuration bitfield: - bit[2*i+1:2*i]=2'b00: interrupt on falling edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b01: interrupt on rising edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b10: interrupt on rising and falling edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b11: RFU
  };
  unsigned int raw;
} __attribute__((packed)) gpio_inttype1_t;

typedef union {
  struct {
    unsigned int intstatus       :32; // GPIO[31:0] Interrupt status flags bitfield. INTSTATUS[i]=1 when interrupt received on GPIO[i]. INTSTATUS is cleared when it is red. GPIO interrupt line is also cleared when INTSTATUS register is red.
  };
  unsigned int raw;
} __attribute__((packed)) gpio_intstatus_t;

typedef union {
  struct {
    unsigned int gpio0_cfg       :4 ; // GPIO[0] pull activation configuration bitfield: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int gpio1_cfg       :4 ; // GPIO[0] drive strength configuration bitfield: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int gpio2_cfg       :4 ; // GPIO[1] pull activation configuration bitfield: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int gpio3_cfg       :4 ; // GPIO[1] drive strength configuration bitfield: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int gpio4_cfg       :4 ; // GPIO[2] pull activation configuration bitfield: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int gpio5_cfg       :4 ; // GPIO[2] drive strength configuration bitfield: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int gpio6_cfg       :4 ; // GPIO[3] pull activation configuration bitfield: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int gpio7_cfg       :4 ; // GPIO[3] drive strength configuration bitfield: - 1'b0: low drive strength - 1'b1: high drive strength
  };
  unsigned int raw;
} __attribute__((packed)) gpio_padcfg0_t;

typedef union {
  struct {
    unsigned int gpio4_pe        :1 ; // GPIO[4] pull activation configuration bitfield: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int gpio4_ds        :1 ; // GPIO[4] drive strength configuration bitfield: - 1'b0: low drive strength - 1'b1: high drive strength
  };
  unsigned int raw;
} __attribute__((packed)) gpio_padcfg1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) gpio_padcfg2_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) gpio_padcfg3_t;

typedef union {
  struct {
    unsigned int dir             :32; // GPIO[63:32] direction configuration bitfield: - bit[i]=1'b0: Input mode for GPIO[i] - bit[i]=1'b1: Output mode for GPIO[i]
  };
  unsigned int raw;
} __attribute__((packed)) gpio_paddir_32_63_t;

typedef union {
  struct {
    unsigned int gpioen          :32; // GPIO[63:32] clock enable configuration bitfield: - bit[i]=1'b0: disable clock for GPIO[i] - bit[i]=1'b1: enable clock for GPIO[i] GPIOs are gathered by groups of 4. The clock gating of one group is done only if all 4 GPIOs are disabled.  Clock must be enabled for a GPIO if it's direction is configured in input mode.
  };
  unsigned int raw;
} __attribute__((packed)) gpio_gpioen_32_63_t;

typedef union {
  struct {
    unsigned int data_in         :32; // GPIO[63:32] input data read bitfield. DATA_IN[i] corresponds to input data of GPIO[i].
  };
  unsigned int raw;
} __attribute__((packed)) gpio_padin_32_63_t;

typedef union {
  struct {
    unsigned int data_out        :32; // GPIO[63:32] output data read bitfield. DATA_OUT[i] corresponds to output data set on GPIO[i].
  };
  unsigned int raw;
} __attribute__((packed)) gpio_padout_32_63_t;

typedef union {
  struct {
    unsigned int data_set        :32; // GPIO[63:32] set bitfield: - bit[i]=1'b0: No change for GPIO[i] - bit[i]=1'b1: Sets GPIO[i] to 1
  };
  unsigned int raw;
} __attribute__((packed)) gpio_padoutset_32_63_t;

typedef union {
  struct {
    unsigned int data_clear      :32; // GPIO[63:32] clear bitfield: - bit[i]=1'b0: No change for GPIO[i] - bit[i]=1'b1: Clears GPIO[i]
  };
  unsigned int raw;
} __attribute__((packed)) gpio_padoutclr_32_63_t;

typedef union {
  struct {
    unsigned int inten           :32; // GPIO[63:32] interrupt enable configuration bitfield: - bit[i]=1'b0: disable interrupt for GPIO[i] - bit[i]=1'b1: enable interrupt for GPIO[i]
  };
  unsigned int raw;
} __attribute__((packed)) gpio_inten_32_63_t;

typedef union {
  struct {
    unsigned int inttype0        :32; // GPIO[47:32] interrupt type configuration bitfield: - bit[2*i+1:2*i]=2'b00: interrupt on falling edge for GPIO[i] - bit[2*i+1:2*i]=2'b01: interrupt on rising edge for GPIO[i] - bit[2*i+1:2*i]=2'b10: interrupt on rising and falling edge for GPIO[i] - bit[2*i+1:2*i]=2'b11: RFU
  };
  unsigned int raw;
} __attribute__((packed)) gpio_inttype_32_47_t;

typedef union {
  struct {
    unsigned int inttype1        :32; // GPIO[63:48] interrupt type configuration bitfield: - bit[2*i+1:2*i]=2'b00: interrupt on falling edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b01: interrupt on rising edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b10: interrupt on rising and falling edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b11: RFU
  };
  unsigned int raw;
} __attribute__((packed)) gpio_inttype_48_63_t;

typedef union {
  struct {
    unsigned int intstatus       :32; // GPIO[63:32] Interrupt status flags bitfield. INTSTATUS[i]=1 when interrupt received on GPIO[i]. INTSTATUS is cleared when it is red. GPIO interrupt line is also cleared when INTSTATUS register is red.
  };
  unsigned int raw;
} __attribute__((packed)) gpio_intstatus_32_63_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) gpio_padcfg_32_39_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) gpio_padcfg_40_47_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) gpio_padcfg_48_55_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) gpio_padcfg_56_63_t;

#endif



//
// REGISTERS STRUCTS
//

#ifdef __GVSOC__

class vp_gpio_paddir : public vp::reg_32
{
public:
  inline void dir_set(uint32_t value) { this->set_field(value, GPIO_PADDIR_DIR_BIT, GPIO_PADDIR_DIR_WIDTH); }
  inline uint32_t dir_get() { return this->get_field(GPIO_PADDIR_DIR_BIT, GPIO_PADDIR_DIR_WIDTH); }
};

class vp_gpio_gpioen : public vp::reg_32
{
public:
  inline void gpioen_set(uint32_t value) { this->set_field(value, GPIO_GPIOEN_GPIOEN_BIT, GPIO_GPIOEN_GPIOEN_WIDTH); }
  inline uint32_t gpioen_get() { return this->get_field(GPIO_GPIOEN_GPIOEN_BIT, GPIO_GPIOEN_GPIOEN_WIDTH); }
};

class vp_gpio_padin : public vp::reg_32
{
public:
  inline void data_in_set(uint32_t value) { this->set_field(value, GPIO_PADIN_DATA_IN_BIT, GPIO_PADIN_DATA_IN_WIDTH); }
  inline uint32_t data_in_get() { return this->get_field(GPIO_PADIN_DATA_IN_BIT, GPIO_PADIN_DATA_IN_WIDTH); }
};

class vp_gpio_padout : public vp::reg_32
{
public:
  inline void data_out_set(uint32_t value) { this->set_field(value, GPIO_PADOUT_DATA_OUT_BIT, GPIO_PADOUT_DATA_OUT_WIDTH); }
  inline uint32_t data_out_get() { return this->get_field(GPIO_PADOUT_DATA_OUT_BIT, GPIO_PADOUT_DATA_OUT_WIDTH); }
};

class vp_gpio_padoutset : public vp::reg_32
{
public:
  inline void data_set_set(uint32_t value) { this->set_field(value, GPIO_PADOUTSET_DATA_SET_BIT, GPIO_PADOUTSET_DATA_SET_WIDTH); }
  inline uint32_t data_set_get() { return this->get_field(GPIO_PADOUTSET_DATA_SET_BIT, GPIO_PADOUTSET_DATA_SET_WIDTH); }
};

class vp_gpio_padoutclr : public vp::reg_32
{
public:
  inline void data_clear_set(uint32_t value) { this->set_field(value, GPIO_PADOUTCLR_DATA_CLEAR_BIT, GPIO_PADOUTCLR_DATA_CLEAR_WIDTH); }
  inline uint32_t data_clear_get() { return this->get_field(GPIO_PADOUTCLR_DATA_CLEAR_BIT, GPIO_PADOUTCLR_DATA_CLEAR_WIDTH); }
};

class vp_gpio_inten : public vp::reg_32
{
public:
  inline void inten_set(uint32_t value) { this->set_field(value, GPIO_INTEN_INTEN_BIT, GPIO_INTEN_INTEN_WIDTH); }
  inline uint32_t inten_get() { return this->get_field(GPIO_INTEN_INTEN_BIT, GPIO_INTEN_INTEN_WIDTH); }
};

class vp_gpio_inttype0 : public vp::reg_32
{
public:
  inline void inttype0_set(uint32_t value) { this->set_field(value, GPIO_INTTYPE0_INTTYPE0_BIT, GPIO_INTTYPE0_INTTYPE0_WIDTH); }
  inline uint32_t inttype0_get() { return this->get_field(GPIO_INTTYPE0_INTTYPE0_BIT, GPIO_INTTYPE0_INTTYPE0_WIDTH); }
};

class vp_gpio_inttype1 : public vp::reg_32
{
public:
  inline void inttype1_set(uint32_t value) { this->set_field(value, GPIO_INTTYPE1_INTTYPE1_BIT, GPIO_INTTYPE1_INTTYPE1_WIDTH); }
  inline uint32_t inttype1_get() { return this->get_field(GPIO_INTTYPE1_INTTYPE1_BIT, GPIO_INTTYPE1_INTTYPE1_WIDTH); }
};

class vp_gpio_intstatus : public vp::reg_32
{
public:
  inline void intstatus_set(uint32_t value) { this->set_field(value, GPIO_INTSTATUS_INTSTATUS_BIT, GPIO_INTSTATUS_INTSTATUS_WIDTH); }
  inline uint32_t intstatus_get() { return this->get_field(GPIO_INTSTATUS_INTSTATUS_BIT, GPIO_INTSTATUS_INTSTATUS_WIDTH); }
};

class vp_gpio_padcfg0 : public vp::reg_32
{
public:
  inline void gpio0_cfg_set(uint32_t value) { this->set_field(value, GPIO_PADCFG0_GPIO0_CFG_BIT, GPIO_PADCFG0_GPIO0_CFG_WIDTH); }
  inline uint32_t gpio0_cfg_get() { return this->get_field(GPIO_PADCFG0_GPIO0_CFG_BIT, GPIO_PADCFG0_GPIO0_CFG_WIDTH); }
  inline void gpio1_cfg_set(uint32_t value) { this->set_field(value, GPIO_PADCFG0_GPIO1_CFG_BIT, GPIO_PADCFG0_GPIO1_CFG_WIDTH); }
  inline uint32_t gpio1_cfg_get() { return this->get_field(GPIO_PADCFG0_GPIO1_CFG_BIT, GPIO_PADCFG0_GPIO1_CFG_WIDTH); }
  inline void gpio2_cfg_set(uint32_t value) { this->set_field(value, GPIO_PADCFG0_GPIO2_CFG_BIT, GPIO_PADCFG0_GPIO2_CFG_WIDTH); }
  inline uint32_t gpio2_cfg_get() { return this->get_field(GPIO_PADCFG0_GPIO2_CFG_BIT, GPIO_PADCFG0_GPIO2_CFG_WIDTH); }
  inline void gpio3_cfg_set(uint32_t value) { this->set_field(value, GPIO_PADCFG0_GPIO3_CFG_BIT, GPIO_PADCFG0_GPIO3_CFG_WIDTH); }
  inline uint32_t gpio3_cfg_get() { return this->get_field(GPIO_PADCFG0_GPIO3_CFG_BIT, GPIO_PADCFG0_GPIO3_CFG_WIDTH); }
  inline void gpio4_cfg_set(uint32_t value) { this->set_field(value, GPIO_PADCFG0_GPIO4_CFG_BIT, GPIO_PADCFG0_GPIO4_CFG_WIDTH); }
  inline uint32_t gpio4_cfg_get() { return this->get_field(GPIO_PADCFG0_GPIO4_CFG_BIT, GPIO_PADCFG0_GPIO4_CFG_WIDTH); }
  inline void gpio5_cfg_set(uint32_t value) { this->set_field(value, GPIO_PADCFG0_GPIO5_CFG_BIT, GPIO_PADCFG0_GPIO5_CFG_WIDTH); }
  inline uint32_t gpio5_cfg_get() { return this->get_field(GPIO_PADCFG0_GPIO5_CFG_BIT, GPIO_PADCFG0_GPIO5_CFG_WIDTH); }
  inline void gpio6_cfg_set(uint32_t value) { this->set_field(value, GPIO_PADCFG0_GPIO6_CFG_BIT, GPIO_PADCFG0_GPIO6_CFG_WIDTH); }
  inline uint32_t gpio6_cfg_get() { return this->get_field(GPIO_PADCFG0_GPIO6_CFG_BIT, GPIO_PADCFG0_GPIO6_CFG_WIDTH); }
  inline void gpio7_cfg_set(uint32_t value) { this->set_field(value, GPIO_PADCFG0_GPIO7_CFG_BIT, GPIO_PADCFG0_GPIO7_CFG_WIDTH); }
  inline uint32_t gpio7_cfg_get() { return this->get_field(GPIO_PADCFG0_GPIO7_CFG_BIT, GPIO_PADCFG0_GPIO7_CFG_WIDTH); }
};

class vp_gpio_padcfg1 : public vp::reg_32
{
public:
  inline void gpio4_pe_set(uint32_t value) { this->set_field(value, GPIO_PADCFG1_GPIO4_PE_BIT, GPIO_PADCFG1_GPIO4_PE_WIDTH); }
  inline uint32_t gpio4_pe_get() { return this->get_field(GPIO_PADCFG1_GPIO4_PE_BIT, GPIO_PADCFG1_GPIO4_PE_WIDTH); }
  inline void gpio4_ds_set(uint32_t value) { this->set_field(value, GPIO_PADCFG1_GPIO4_DS_BIT, GPIO_PADCFG1_GPIO4_DS_WIDTH); }
  inline uint32_t gpio4_ds_get() { return this->get_field(GPIO_PADCFG1_GPIO4_DS_BIT, GPIO_PADCFG1_GPIO4_DS_WIDTH); }
};

class vp_gpio_padcfg2 : public vp::reg_32
{
public:
};

class vp_gpio_padcfg3 : public vp::reg_32
{
public:
};

class vp_gpio_paddir_32_63 : public vp::reg_32
{
public:
  inline void dir_set(uint32_t value) { this->set_field(value, GPIO_PADDIR_32_63_DIR_BIT, GPIO_PADDIR_32_63_DIR_WIDTH); }
  inline uint32_t dir_get() { return this->get_field(GPIO_PADDIR_32_63_DIR_BIT, GPIO_PADDIR_32_63_DIR_WIDTH); }
};

class vp_gpio_gpioen_32_63 : public vp::reg_32
{
public:
  inline void gpioen_set(uint32_t value) { this->set_field(value, GPIO_GPIOEN_32_63_GPIOEN_BIT, GPIO_GPIOEN_32_63_GPIOEN_WIDTH); }
  inline uint32_t gpioen_get() { return this->get_field(GPIO_GPIOEN_32_63_GPIOEN_BIT, GPIO_GPIOEN_32_63_GPIOEN_WIDTH); }
};

class vp_gpio_padin_32_63 : public vp::reg_32
{
public:
  inline void data_in_set(uint32_t value) { this->set_field(value, GPIO_PADIN_32_63_DATA_IN_BIT, GPIO_PADIN_32_63_DATA_IN_WIDTH); }
  inline uint32_t data_in_get() { return this->get_field(GPIO_PADIN_32_63_DATA_IN_BIT, GPIO_PADIN_32_63_DATA_IN_WIDTH); }
};

class vp_gpio_padout_32_63 : public vp::reg_32
{
public:
  inline void data_out_set(uint32_t value) { this->set_field(value, GPIO_PADOUT_32_63_DATA_OUT_BIT, GPIO_PADOUT_32_63_DATA_OUT_WIDTH); }
  inline uint32_t data_out_get() { return this->get_field(GPIO_PADOUT_32_63_DATA_OUT_BIT, GPIO_PADOUT_32_63_DATA_OUT_WIDTH); }
};

class vp_gpio_padoutset_32_63 : public vp::reg_32
{
public:
  inline void data_set_set(uint32_t value) { this->set_field(value, GPIO_PADOUTSET_32_63_DATA_SET_BIT, GPIO_PADOUTSET_32_63_DATA_SET_WIDTH); }
  inline uint32_t data_set_get() { return this->get_field(GPIO_PADOUTSET_32_63_DATA_SET_BIT, GPIO_PADOUTSET_32_63_DATA_SET_WIDTH); }
};

class vp_gpio_padoutclr_32_63 : public vp::reg_32
{
public:
  inline void data_clear_set(uint32_t value) { this->set_field(value, GPIO_PADOUTCLR_32_63_DATA_CLEAR_BIT, GPIO_PADOUTCLR_32_63_DATA_CLEAR_WIDTH); }
  inline uint32_t data_clear_get() { return this->get_field(GPIO_PADOUTCLR_32_63_DATA_CLEAR_BIT, GPIO_PADOUTCLR_32_63_DATA_CLEAR_WIDTH); }
};

class vp_gpio_inten_32_63 : public vp::reg_32
{
public:
  inline void inten_set(uint32_t value) { this->set_field(value, GPIO_INTEN_32_63_INTEN_BIT, GPIO_INTEN_32_63_INTEN_WIDTH); }
  inline uint32_t inten_get() { return this->get_field(GPIO_INTEN_32_63_INTEN_BIT, GPIO_INTEN_32_63_INTEN_WIDTH); }
};

class vp_gpio_inttype_32_47 : public vp::reg_32
{
public:
  inline void inttype0_set(uint32_t value) { this->set_field(value, GPIO_INTTYPE_32_47_INTTYPE0_BIT, GPIO_INTTYPE_32_47_INTTYPE0_WIDTH); }
  inline uint32_t inttype0_get() { return this->get_field(GPIO_INTTYPE_32_47_INTTYPE0_BIT, GPIO_INTTYPE_32_47_INTTYPE0_WIDTH); }
};

class vp_gpio_inttype_48_63 : public vp::reg_32
{
public:
  inline void inttype1_set(uint32_t value) { this->set_field(value, GPIO_INTTYPE_48_63_INTTYPE1_BIT, GPIO_INTTYPE_48_63_INTTYPE1_WIDTH); }
  inline uint32_t inttype1_get() { return this->get_field(GPIO_INTTYPE_48_63_INTTYPE1_BIT, GPIO_INTTYPE_48_63_INTTYPE1_WIDTH); }
};

class vp_gpio_intstatus_32_63 : public vp::reg_32
{
public:
  inline void intstatus_set(uint32_t value) { this->set_field(value, GPIO_INTSTATUS_32_63_INTSTATUS_BIT, GPIO_INTSTATUS_32_63_INTSTATUS_WIDTH); }
  inline uint32_t intstatus_get() { return this->get_field(GPIO_INTSTATUS_32_63_INTSTATUS_BIT, GPIO_INTSTATUS_32_63_INTSTATUS_WIDTH); }
};

class vp_gpio_padcfg_32_39 : public vp::reg_32
{
public:
};

class vp_gpio_padcfg_40_47 : public vp::reg_32
{
public:
};

class vp_gpio_padcfg_48_55 : public vp::reg_32
{
public:
};

class vp_gpio_padcfg_56_63 : public vp::reg_32
{
public:
};

#endif



//
// REGISTERS GLOBAL STRUCT
//

#ifndef LANGUAGE_ASSEMBLY

typedef struct {
  unsigned int paddir          ; // GPIO pad direction configuration register.
  unsigned int gpioen          ; // GPIO enable register.
  unsigned int padin           ; // GPIO pad input value register.
  unsigned int padout          ; // GPIO pad output value register.
  unsigned int padoutset       ; // GPIO pad output set register.
  unsigned int padoutclr       ; // GPIO pad output clear register.
  unsigned int inten           ; // GPIO pad interrupt enable configuration register.
  unsigned int inttype0        ; // GPIO pad interrupt type gpio 0 to 15 register.
  unsigned int inttype1        ; // GPIO pad interrupt type gpio 16 to 31 register.
  unsigned int intstatus       ; // GPIO pad interrupt status register.
  unsigned int padcfg0         ; // GPIO pad pin 0 to 7 configuration register.
  unsigned int padcfg1         ; // GPIO pad pin 8 to 15 configuration register.
  unsigned int padcfg2         ; // GPIO pad pin 16 to 23 configuration register.
  unsigned int padcfg3         ; // GPIO pad pin 24 to 31 configuration register.
  unsigned int paddir_32_63    ; // GPIO pad direction configuration register.
  unsigned int gpioen_32_63    ; // GPIO enable register.
  unsigned int padin_32_63     ; // GPIO pad input value register.
  unsigned int padout_32_63    ; // GPIO pad output value register.
  unsigned int padoutset_32_63 ; // GPIO pad output set register.
  unsigned int padoutclr_32_63 ; // GPIO pad output clear register.
  unsigned int inten_32_63     ; // GPIO pad interrupt enable configuration register.
  unsigned int inttype_32_47   ; // GPIO pad interrupt type gpio 32 to 47 register.
  unsigned int inttype_48_63   ; // GPIO pad interrupt type gpio 48 to 63 register.
  unsigned int intstatus_32_63 ; // GPIO pad interrupt status register.
  unsigned int padcfg_32_39    ; // GPIO pad pin 32 to 39 configuration register.
  unsigned int padcfg_40_47    ; // GPIO pad pin 40 to 47 configuration register.
  unsigned int padcfg_48_55    ; // GPIO pad pin 48 to 55 configuration register.
  unsigned int padcfg_56_63    ; // GPIO pad pin 56 to 63 configuration register.
} __attribute__((packed)) gpio_gpio_t;

#endif



//
// REGISTERS ACCESS FUNCTIONS
//

#ifndef LANGUAGE_ASSEMBLY

static inline uint32_t gpio_paddir_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADDIR_OFFSET); }
static inline void gpio_paddir_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADDIR_OFFSET, value); }

static inline uint32_t gpio_gpioen_get(uint32_t base) { return ARCHI_READ(base, GPIO_GPIOEN_OFFSET); }
static inline void gpio_gpioen_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_GPIOEN_OFFSET, value); }

static inline uint32_t gpio_padin_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADIN_OFFSET); }
static inline void gpio_padin_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADIN_OFFSET, value); }

static inline uint32_t gpio_padout_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADOUT_OFFSET); }
static inline void gpio_padout_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADOUT_OFFSET, value); }

static inline uint32_t gpio_padoutset_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADOUTSET_OFFSET); }
static inline void gpio_padoutset_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADOUTSET_OFFSET, value); }

static inline uint32_t gpio_padoutclr_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADOUTCLR_OFFSET); }
static inline void gpio_padoutclr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADOUTCLR_OFFSET, value); }

static inline uint32_t gpio_inten_get(uint32_t base) { return ARCHI_READ(base, GPIO_INTEN_OFFSET); }
static inline void gpio_inten_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_INTEN_OFFSET, value); }

static inline uint32_t gpio_inttype0_get(uint32_t base) { return ARCHI_READ(base, GPIO_INTTYPE0_OFFSET); }
static inline void gpio_inttype0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_INTTYPE0_OFFSET, value); }

static inline uint32_t gpio_inttype1_get(uint32_t base) { return ARCHI_READ(base, GPIO_INTTYPE1_OFFSET); }
static inline void gpio_inttype1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_INTTYPE1_OFFSET, value); }

static inline uint32_t gpio_intstatus_get(uint32_t base) { return ARCHI_READ(base, GPIO_INTSTATUS_OFFSET); }
static inline void gpio_intstatus_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_INTSTATUS_OFFSET, value); }

static inline uint32_t gpio_padcfg0_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADCFG0_OFFSET); }
static inline void gpio_padcfg0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADCFG0_OFFSET, value); }

static inline uint32_t gpio_padcfg1_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADCFG1_OFFSET); }
static inline void gpio_padcfg1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADCFG1_OFFSET, value); }

static inline uint32_t gpio_padcfg2_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADCFG2_OFFSET); }
static inline void gpio_padcfg2_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADCFG2_OFFSET, value); }

static inline uint32_t gpio_padcfg3_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADCFG3_OFFSET); }
static inline void gpio_padcfg3_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADCFG3_OFFSET, value); }

static inline uint32_t gpio_paddir_32_63_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADDIR_32_63_OFFSET); }
static inline void gpio_paddir_32_63_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADDIR_32_63_OFFSET, value); }

static inline uint32_t gpio_gpioen_32_63_get(uint32_t base) { return ARCHI_READ(base, GPIO_GPIOEN_32_63_OFFSET); }
static inline void gpio_gpioen_32_63_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_GPIOEN_32_63_OFFSET, value); }

static inline uint32_t gpio_padin_32_63_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADIN_32_63_OFFSET); }
static inline void gpio_padin_32_63_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADIN_32_63_OFFSET, value); }

static inline uint32_t gpio_padout_32_63_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADOUT_32_63_OFFSET); }
static inline void gpio_padout_32_63_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADOUT_32_63_OFFSET, value); }

static inline uint32_t gpio_padoutset_32_63_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADOUTSET_32_63_OFFSET); }
static inline void gpio_padoutset_32_63_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADOUTSET_32_63_OFFSET, value); }

static inline uint32_t gpio_padoutclr_32_63_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADOUTCLR_32_63_OFFSET); }
static inline void gpio_padoutclr_32_63_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADOUTCLR_32_63_OFFSET, value); }

static inline uint32_t gpio_inten_32_63_get(uint32_t base) { return ARCHI_READ(base, GPIO_INTEN_32_63_OFFSET); }
static inline void gpio_inten_32_63_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_INTEN_32_63_OFFSET, value); }

static inline uint32_t gpio_inttype_32_47_get(uint32_t base) { return ARCHI_READ(base, GPIO_INTTYPE_32_47_OFFSET); }
static inline void gpio_inttype_32_47_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_INTTYPE_32_47_OFFSET, value); }

static inline uint32_t gpio_inttype_48_63_get(uint32_t base) { return ARCHI_READ(base, GPIO_INTTYPE_48_63_OFFSET); }
static inline void gpio_inttype_48_63_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_INTTYPE_48_63_OFFSET, value); }

static inline uint32_t gpio_intstatus_32_63_get(uint32_t base) { return ARCHI_READ(base, GPIO_INTSTATUS_32_63_OFFSET); }
static inline void gpio_intstatus_32_63_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_INTSTATUS_32_63_OFFSET, value); }

static inline uint32_t gpio_padcfg_32_39_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADCFG_32_39_OFFSET); }
static inline void gpio_padcfg_32_39_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADCFG_32_39_OFFSET, value); }

static inline uint32_t gpio_padcfg_40_47_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADCFG_40_47_OFFSET); }
static inline void gpio_padcfg_40_47_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADCFG_40_47_OFFSET, value); }

static inline uint32_t gpio_padcfg_48_55_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADCFG_48_55_OFFSET); }
static inline void gpio_padcfg_48_55_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADCFG_48_55_OFFSET, value); }

static inline uint32_t gpio_padcfg_56_63_get(uint32_t base) { return ARCHI_READ(base, GPIO_PADCFG_56_63_OFFSET); }
static inline void gpio_padcfg_56_63_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_PADCFG_56_63_OFFSET, value); }

#endif



//
// REGISTERS FIELDS MACROS
//

#ifndef LANGUAGE_ASSEMBLY

#define GPIO_PADDIR_DIR_GET(value)                         (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_PADDIR_DIR_GETS(value)                        (ARCHI_BEXTRACT((value),32,0))
#define GPIO_PADDIR_DIR_SET(value,field)                   (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_PADDIR_DIR(val)                               ((val) << 0)

#define GPIO_GPIOEN_GPIOEN_GET(value)                      (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_GPIOEN_GPIOEN_GETS(value)                     (ARCHI_BEXTRACT((value),32,0))
#define GPIO_GPIOEN_GPIOEN_SET(value,field)                (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_GPIOEN_GPIOEN(val)                            ((val) << 0)

#define GPIO_PADIN_DATA_IN_GET(value)                      (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_PADIN_DATA_IN_GETS(value)                     (ARCHI_BEXTRACT((value),32,0))
#define GPIO_PADIN_DATA_IN_SET(value,field)                (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_PADIN_DATA_IN(val)                            ((val) << 0)

#define GPIO_PADOUT_DATA_OUT_GET(value)                    (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_PADOUT_DATA_OUT_GETS(value)                   (ARCHI_BEXTRACT((value),32,0))
#define GPIO_PADOUT_DATA_OUT_SET(value,field)              (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_PADOUT_DATA_OUT(val)                          ((val) << 0)

#define GPIO_PADOUTSET_DATA_SET_GET(value)                 (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_PADOUTSET_DATA_SET_GETS(value)                (ARCHI_BEXTRACT((value),32,0))
#define GPIO_PADOUTSET_DATA_SET_SET(value,field)           (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_PADOUTSET_DATA_SET(val)                       ((val) << 0)

#define GPIO_PADOUTCLR_DATA_CLEAR_GET(value)               (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_PADOUTCLR_DATA_CLEAR_GETS(value)              (ARCHI_BEXTRACT((value),32,0))
#define GPIO_PADOUTCLR_DATA_CLEAR_SET(value,field)         (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_PADOUTCLR_DATA_CLEAR(val)                     ((val) << 0)

#define GPIO_INTEN_INTEN_GET(value)                        (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_INTEN_INTEN_GETS(value)                       (ARCHI_BEXTRACT((value),32,0))
#define GPIO_INTEN_INTEN_SET(value,field)                  (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_INTEN_INTEN(val)                              ((val) << 0)

#define GPIO_INTTYPE0_INTTYPE0_GET(value)                  (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_INTTYPE0_INTTYPE0_GETS(value)                 (ARCHI_BEXTRACT((value),32,0))
#define GPIO_INTTYPE0_INTTYPE0_SET(value,field)            (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_INTTYPE0_INTTYPE0(val)                        ((val) << 0)

#define GPIO_INTTYPE1_INTTYPE1_GET(value)                  (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_INTTYPE1_INTTYPE1_GETS(value)                 (ARCHI_BEXTRACT((value),32,0))
#define GPIO_INTTYPE1_INTTYPE1_SET(value,field)            (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_INTTYPE1_INTTYPE1(val)                        ((val) << 0)

#define GPIO_INTSTATUS_INTSTATUS_GET(value)                (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_INTSTATUS_INTSTATUS_GETS(value)               (ARCHI_BEXTRACT((value),32,0))
#define GPIO_INTSTATUS_INTSTATUS_SET(value,field)          (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_INTSTATUS_INTSTATUS(val)                      ((val) << 0)

#define GPIO_PADCFG0_GPIO0_CFG_GET(value)                  (ARCHI_BEXTRACTU((value),4,0))
#define GPIO_PADCFG0_GPIO0_CFG_GETS(value)                 (ARCHI_BEXTRACT((value),4,0))
#define GPIO_PADCFG0_GPIO0_CFG_SET(value,field)            (ARCHI_BINSERT((value),(field),4,0))
#define GPIO_PADCFG0_GPIO0_CFG(val)                        ((val) << 0)

#define GPIO_PADCFG0_GPIO1_CFG_GET(value)                  (ARCHI_BEXTRACTU((value),4,4))
#define GPIO_PADCFG0_GPIO1_CFG_GETS(value)                 (ARCHI_BEXTRACT((value),4,4))
#define GPIO_PADCFG0_GPIO1_CFG_SET(value,field)            (ARCHI_BINSERT((value),(field),4,4))
#define GPIO_PADCFG0_GPIO1_CFG(val)                        ((val) << 4)

#define GPIO_PADCFG0_GPIO2_CFG_GET(value)                  (ARCHI_BEXTRACTU((value),4,8))
#define GPIO_PADCFG0_GPIO2_CFG_GETS(value)                 (ARCHI_BEXTRACT((value),4,8))
#define GPIO_PADCFG0_GPIO2_CFG_SET(value,field)            (ARCHI_BINSERT((value),(field),4,8))
#define GPIO_PADCFG0_GPIO2_CFG(val)                        ((val) << 8)

#define GPIO_PADCFG0_GPIO3_CFG_GET(value)                  (ARCHI_BEXTRACTU((value),4,12))
#define GPIO_PADCFG0_GPIO3_CFG_GETS(value)                 (ARCHI_BEXTRACT((value),4,12))
#define GPIO_PADCFG0_GPIO3_CFG_SET(value,field)            (ARCHI_BINSERT((value),(field),4,12))
#define GPIO_PADCFG0_GPIO3_CFG(val)                        ((val) << 12)

#define GPIO_PADCFG0_GPIO4_CFG_GET(value)                  (ARCHI_BEXTRACTU((value),4,16))
#define GPIO_PADCFG0_GPIO4_CFG_GETS(value)                 (ARCHI_BEXTRACT((value),4,16))
#define GPIO_PADCFG0_GPIO4_CFG_SET(value,field)            (ARCHI_BINSERT((value),(field),4,16))
#define GPIO_PADCFG0_GPIO4_CFG(val)                        ((val) << 16)

#define GPIO_PADCFG0_GPIO5_CFG_GET(value)                  (ARCHI_BEXTRACTU((value),4,20))
#define GPIO_PADCFG0_GPIO5_CFG_GETS(value)                 (ARCHI_BEXTRACT((value),4,20))
#define GPIO_PADCFG0_GPIO5_CFG_SET(value,field)            (ARCHI_BINSERT((value),(field),4,20))
#define GPIO_PADCFG0_GPIO5_CFG(val)                        ((val) << 20)

#define GPIO_PADCFG0_GPIO6_CFG_GET(value)                  (ARCHI_BEXTRACTU((value),4,24))
#define GPIO_PADCFG0_GPIO6_CFG_GETS(value)                 (ARCHI_BEXTRACT((value),4,24))
#define GPIO_PADCFG0_GPIO6_CFG_SET(value,field)            (ARCHI_BINSERT((value),(field),4,24))
#define GPIO_PADCFG0_GPIO6_CFG(val)                        ((val) << 24)

#define GPIO_PADCFG0_GPIO7_CFG_GET(value)                  (ARCHI_BEXTRACTU((value),4,28))
#define GPIO_PADCFG0_GPIO7_CFG_GETS(value)                 (ARCHI_BEXTRACT((value),4,28))
#define GPIO_PADCFG0_GPIO7_CFG_SET(value,field)            (ARCHI_BINSERT((value),(field),4,28))
#define GPIO_PADCFG0_GPIO7_CFG(val)                        ((val) << 28)

#define GPIO_PADCFG1_GPIO4_PE_GET(value)                   (ARCHI_BEXTRACTU((value),1,0))
#define GPIO_PADCFG1_GPIO4_PE_GETS(value)                  (ARCHI_BEXTRACT((value),1,0))
#define GPIO_PADCFG1_GPIO4_PE_SET(value,field)             (ARCHI_BINSERT((value),(field),1,0))
#define GPIO_PADCFG1_GPIO4_PE(val)                         ((val) << 0)

#define GPIO_PADCFG1_GPIO4_DS_GET(value)                   (ARCHI_BEXTRACTU((value),1,1))
#define GPIO_PADCFG1_GPIO4_DS_GETS(value)                  (ARCHI_BEXTRACT((value),1,1))
#define GPIO_PADCFG1_GPIO4_DS_SET(value,field)             (ARCHI_BINSERT((value),(field),1,1))
#define GPIO_PADCFG1_GPIO4_DS(val)                         ((val) << 1)

#define GPIO_PADDIR_32_63_DIR_GET(value)                   (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_PADDIR_32_63_DIR_GETS(value)                  (ARCHI_BEXTRACT((value),32,0))
#define GPIO_PADDIR_32_63_DIR_SET(value,field)             (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_PADDIR_32_63_DIR(val)                         ((val) << 0)

#define GPIO_GPIOEN_32_63_GPIOEN_GET(value)                (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_GPIOEN_32_63_GPIOEN_GETS(value)               (ARCHI_BEXTRACT((value),32,0))
#define GPIO_GPIOEN_32_63_GPIOEN_SET(value,field)          (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_GPIOEN_32_63_GPIOEN(val)                      ((val) << 0)

#define GPIO_PADIN_32_63_DATA_IN_GET(value)                (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_PADIN_32_63_DATA_IN_GETS(value)               (ARCHI_BEXTRACT((value),32,0))
#define GPIO_PADIN_32_63_DATA_IN_SET(value,field)          (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_PADIN_32_63_DATA_IN(val)                      ((val) << 0)

#define GPIO_PADOUT_32_63_DATA_OUT_GET(value)              (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_PADOUT_32_63_DATA_OUT_GETS(value)             (ARCHI_BEXTRACT((value),32,0))
#define GPIO_PADOUT_32_63_DATA_OUT_SET(value,field)        (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_PADOUT_32_63_DATA_OUT(val)                    ((val) << 0)

#define GPIO_PADOUTSET_32_63_DATA_SET_GET(value)           (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_PADOUTSET_32_63_DATA_SET_GETS(value)          (ARCHI_BEXTRACT((value),32,0))
#define GPIO_PADOUTSET_32_63_DATA_SET_SET(value,field)     (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_PADOUTSET_32_63_DATA_SET(val)                 ((val) << 0)

#define GPIO_PADOUTCLR_32_63_DATA_CLEAR_GET(value)         (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_PADOUTCLR_32_63_DATA_CLEAR_GETS(value)        (ARCHI_BEXTRACT((value),32,0))
#define GPIO_PADOUTCLR_32_63_DATA_CLEAR_SET(value,field)   (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_PADOUTCLR_32_63_DATA_CLEAR(val)               ((val) << 0)

#define GPIO_INTEN_32_63_INTEN_GET(value)                  (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_INTEN_32_63_INTEN_GETS(value)                 (ARCHI_BEXTRACT((value),32,0))
#define GPIO_INTEN_32_63_INTEN_SET(value,field)            (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_INTEN_32_63_INTEN(val)                        ((val) << 0)

#define GPIO_INTTYPE_32_47_INTTYPE0_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_INTTYPE_32_47_INTTYPE0_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define GPIO_INTTYPE_32_47_INTTYPE0_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_INTTYPE_32_47_INTTYPE0(val)                   ((val) << 0)

#define GPIO_INTTYPE_48_63_INTTYPE1_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_INTTYPE_48_63_INTTYPE1_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define GPIO_INTTYPE_48_63_INTTYPE1_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_INTTYPE_48_63_INTTYPE1(val)                   ((val) << 0)

#define GPIO_INTSTATUS_32_63_INTSTATUS_GET(value)          (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_INTSTATUS_32_63_INTSTATUS_GETS(value)         (ARCHI_BEXTRACT((value),32,0))
#define GPIO_INTSTATUS_32_63_INTSTATUS_SET(value,field)    (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_INTSTATUS_32_63_INTSTATUS(val)                ((val) << 0)

#endif

#endif
