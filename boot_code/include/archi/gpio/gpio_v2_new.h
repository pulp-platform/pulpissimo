
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

#ifndef __INCLUDE_ARCHI_GPIO_GPIO_V2_NEW_H__
#define __INCLUDE_ARCHI_GPIO_GPIO_V2_NEW_H__

#ifndef LANGUAGE_ASSEMBLY

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS
//

// GPIO pad direction configuration
#define GPIO_APBGPIO_PADDIR_OFFSET               0x0

// GPIO pad input value
#define GPIO_APBGPIO_PADIN_OFFSET                0x4

// GPIO pad output value
#define GPIO_APBGPIO_PADOUT_OFFSET               0x8

// GPIO pad interrupt enable configuration
#define GPIO_APBGPIO_INTEN_OFFSET                0xc

// GPIO pad interrupt type bit 0 configuration
#define GPIO_APBGPIO_INTTYPE0_OFFSET             0x10

// GPIO pad interrupt type bit 1 configuration
#define GPIO_APBGPIO_INTTYPE1_OFFSET             0x14

// GPIO pad interrupt status
#define GPIO_APBGPIO_INTSTATUS_OFFSET            0x18

// GPIO pad enable configuration
#define GPIO_APBGPIO_GPIOEN_OFFSET               0x1c

// GPIO pad pin 0 to 3 configuration
#define GPIO_APBGPIO_PADCFG0_OFFSET              0x20

// GPIO pad pin 4 to 7 configuration
#define GPIO_APBGPIO_PADCFG1_OFFSET              0x24

// GPIO pad pin 8 to 11 configuration
#define GPIO_APBGPIO_PADCFG2_OFFSET              0x28

// GPIO pad pin 12 to 15 configuration
#define GPIO_APBGPIO_PADCFG3_OFFSET              0x2c

// GPIO pad pin 16 to 19 configuration
#define GPIO_APBGPIO_PADCFG4_OFFSET              0x30

// GPIO pad pin 20 to 23 configuration
#define GPIO_APBGPIO_PADCFG5_OFFSET              0x34

// GPIO pad pin 24 to 27 configuration
#define GPIO_APBGPIO_PADCFG6_OFFSET              0x38

// GPIO pad pin 28 to 31 configuration
#define GPIO_APBGPIO_PADCFG7_OFFSET              0x3c



//
// REGISTERS FIELDS
//

// Configure direction of the 32 GPIOs: - bit[i]=1'b0: Input mode for GPIO[i] - bit[i]=1'b1: Output mode for GPIO[i] (access: R/W)
#define GPIO_APBGPIO_PADDIR_DIR_BIT                                  0
#define GPIO_APBGPIO_PADDIR_DIR_WIDTH                                32
#define GPIO_APBGPIO_PADDIR_DIR_MASK                                 0xffffffff

// Read value of the 32 GPIOs. (access: R)
#define GPIO_APBGPIO_PADIN_DATA_IN_BIT                               0
#define GPIO_APBGPIO_PADIN_DATA_IN_WIDTH                             32
#define GPIO_APBGPIO_PADIN_DATA_IN_MASK                              0xffffffff

// Write value to the 32 GPIOs. (access: R/W)
#define GPIO_APBGPIO_PADOUT_DATA_OUT_BIT                             0
#define GPIO_APBGPIO_PADOUT_DATA_OUT_WIDTH                           32
#define GPIO_APBGPIO_PADOUT_DATA_OUT_MASK                            0xffffffff

// Configure interrupt mode for the 32 GPIOs: - bit[i]=1'b0: disable interrupt for GPIO[i] - bit[i]=1'b1: enable interrupt for GPIO[i] (access: R/W)
#define GPIO_APBGPIO_INTEN_INTEN_BIT                                 0
#define GPIO_APBGPIO_INTEN_INTEN_WIDTH                               32
#define GPIO_APBGPIO_INTEN_INTEN_MASK                                0xffffffff

// Configure interrupt condition for the GPIO[15:0]: - bit[2*i+1:2*i]=2'b00: interrupt on falling edge for GPIO[i] - bit[2*i+1:2*i]=2'b01: interrupt on rising edge for GPIO[i] - bit[2*i+1:2*i]=2'b10: interrupt on rising and falling edge for GPIO[i] - bit[2*i+1:2*i]=2'b11: RFU (access: R/W)
#define GPIO_APBGPIO_INTTYPE0_INTTYPE0_BIT                           0
#define GPIO_APBGPIO_INTTYPE0_INTTYPE0_WIDTH                         32
#define GPIO_APBGPIO_INTTYPE0_INTTYPE0_MASK                          0xffffffff

// Configure interrupt condition for the GPIO[31:16]: - bit[2*i+1:2*i]=2'b00: interrupt on falling edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b01: interrupt on rising edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b10: interrupt on rising and falling edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b11: RFU (access: R/W)
#define GPIO_APBGPIO_INTTYPE1_INTTYPE1_BIT                           0
#define GPIO_APBGPIO_INTTYPE1_INTTYPE1_WIDTH                         32
#define GPIO_APBGPIO_INTTYPE1_INTTYPE1_MASK                          0xffffffff

// Interrupt status flags for the 32 GPIOs.  - bit[i]=1 when interrupt received on GPIO[i] Register is cleared when read. GPIO interrupt line is also cleared when this register is red. (access: R)
#define GPIO_APBGPIO_INTSTATUS_INTSTATUS_BIT                         0
#define GPIO_APBGPIO_INTSTATUS_INTSTATUS_WIDTH                       32
#define GPIO_APBGPIO_INTSTATUS_INTSTATUS_MASK                        0xffffffff

// Configure clock enable for the 32 GPIOs: - bit[i]=1'b0: disable mode for GPIO[i] - bit[i]=1'b1: enable mode for GPIO[i] GPIOs are gathered by groups of 4. The clock-gating of one group is done only if all 4 GPIOs are disabled. (access: R/W)
#define GPIO_APBGPIO_GPIOEN_GPIOEN_BIT                               0
#define GPIO_APBGPIO_GPIOEN_GPIOEN_WIDTH                             32
#define GPIO_APBGPIO_GPIOEN_GPIOEN_MASK                              0xffffffff

// Configure pull activation for GPIO[0]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_PE_BIT                    0
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_PE_WIDTH                  1
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_PE_MASK                   0x1

// Configure drive strength for GPIO[0]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_DS_BIT                    1
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_DS_WIDTH                  1
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_DS_MASK                   0x2

// Configure pull activation for GPIO[1]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_PE_BIT                    8
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_PE_WIDTH                  1
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_PE_MASK                   0x100

// Configure drive strength for GPIO[1]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_DS_BIT                    9
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_DS_WIDTH                  1
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_DS_MASK                   0x200

// Configure pull activation for GPIO[2]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_PE_BIT                    16
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_PE_WIDTH                  1
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_PE_MASK                   0x10000

// Configure drive strength for GPIO[2]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_DS_BIT                    17
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_DS_WIDTH                  1
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_DS_MASK                   0x20000

// Configure pull activation for GPIO[3]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_PE_BIT                    24
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_PE_WIDTH                  1
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_PE_MASK                   0x1000000

// Configure drive strength for GPIO[3]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_DS_BIT                    25
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_DS_WIDTH                  1
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_DS_MASK                   0x2000000

// Configure pull activation for GPIO[4]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_PE_BIT                    0
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_PE_WIDTH                  1
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_PE_MASK                   0x1

// Configure drive strength for GPIO[4]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_DS_BIT                    1
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_DS_WIDTH                  1
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_DS_MASK                   0x2

// Configure pull activation for GPIO[5]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_PE_BIT                    8
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_PE_WIDTH                  1
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_PE_MASK                   0x100

// Configure drive strength for GPIO[5]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_DS_BIT                    9
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_DS_WIDTH                  1
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_DS_MASK                   0x200

// Configure pull activation for GPIO[6]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_PE_BIT                    16
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_PE_WIDTH                  1
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_PE_MASK                   0x10000

// Configure drive strength for GPIO[6]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_DS_BIT                    17
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_DS_WIDTH                  1
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_DS_MASK                   0x20000

// Configure pull activation for GPIO[7]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_PE_BIT                    24
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_PE_WIDTH                  1
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_PE_MASK                   0x1000000

// Configure drive strength for GPIO[7]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_DS_BIT                    25
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_DS_WIDTH                  1
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_DS_MASK                   0x2000000

// Configure pull activation for GPIO[8]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_PE_BIT                    0
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_PE_WIDTH                  1
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_PE_MASK                   0x1

// Configure drive strength for GPIO[8]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_DS_BIT                    1
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_DS_WIDTH                  1
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_DS_MASK                   0x2

// Configure pull activation for GPIO[9]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_PE_BIT                    8
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_PE_WIDTH                  1
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_PE_MASK                   0x100

// Configure drive strength for GPIO[9]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_DS_BIT                    9
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_DS_WIDTH                  1
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_DS_MASK                   0x200

// Configure pull activation for GPIO[10]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_PE_BIT                   16
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_PE_MASK                  0x10000

// Configure drive strength for GPIO[10]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_DS_BIT                   17
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_DS_MASK                  0x20000

// Configure pull activation for GPIO[11]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_PE_BIT                   24
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_PE_MASK                  0x1000000

// Configure drive strength for GPIO[11]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_DS_BIT                   25
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_DS_MASK                  0x2000000

// Configure pull activation for GPIO[12]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_PE_BIT                   0
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_PE_MASK                  0x1

// Configure drive strength for GPIO[12]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_DS_BIT                   1
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_DS_MASK                  0x2

// Configure pull activation for GPIO[13]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_PE_BIT                   8
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_PE_MASK                  0x100

// Configure drive strength for GPIO[13]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_DS_BIT                   9
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_DS_MASK                  0x200

// Configure pull activation for GPIO[14]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_PE_BIT                   16
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_PE_MASK                  0x10000

// Configure drive strength for GPIO[14]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_DS_BIT                   17
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_DS_MASK                  0x20000

// Configure pull activation for GPIO[15]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_PE_BIT                   24
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_PE_MASK                  0x1000000

// Configure drive strength for GPIO[15]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_DS_BIT                   25
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_DS_MASK                  0x2000000

// Configure pull activation for GPIO[16]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_PE_BIT                   0
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_PE_MASK                  0x1

// Configure drive strength for GPIO[16]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_DS_BIT                   1
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_DS_MASK                  0x2

// Configure pull activation for GPIO[17]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_PE_BIT                   8
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_PE_MASK                  0x100

// Configure drive strength for GPIO[17]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_DS_BIT                   9
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_DS_MASK                  0x200

// Configure pull activation for GPIO[18]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_PE_BIT                   16
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_PE_MASK                  0x10000

// Configure drive strength for GPIO[18]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_DS_BIT                   17
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_DS_MASK                  0x20000

// Configure pull activation for GPIO[19]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_PE_BIT                   24
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_PE_MASK                  0x1000000

// Configure drive strength for GPIO[19]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_DS_BIT                   25
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_DS_MASK                  0x2000000

// Configure pull activation for GPIO[20]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_PE_BIT                   0
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_PE_MASK                  0x1

// Configure drive strength for GPIO[20]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_DS_BIT                   1
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_DS_MASK                  0x2

// Configure pull activation for GPIO[21]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_PE_BIT                   8
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_PE_MASK                  0x100

// Configure drive strength for GPIO[21]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_DS_BIT                   9
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_DS_MASK                  0x200

// Configure pull activation for GPIO[22]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_PE_BIT                   16
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_PE_MASK                  0x10000

// Configure drive strength for GPIO[22]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_DS_BIT                   17
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_DS_MASK                  0x20000

// Configure pull activation for GPIO[23]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_PE_BIT                   24
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_PE_MASK                  0x1000000

// Configure drive strength for GPIO[23]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_DS_BIT                   25
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_DS_MASK                  0x2000000

// Configure pull activation for GPIO[24]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_PE_BIT                   0
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_PE_MASK                  0x1

// Configure drive strength for GPIO[24]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_DS_BIT                   1
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_DS_MASK                  0x2

// Configure pull activation for GPIO[25]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_PE_BIT                   8
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_PE_MASK                  0x100

// Configure drive strength for GPIO[25]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_DS_BIT                   9
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_DS_MASK                  0x200

// Configure pull activation for GPIO[26]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_PE_BIT                   16
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_PE_MASK                  0x10000

// Configure drive strength for GPIO[26]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_DS_BIT                   17
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_DS_MASK                  0x20000

// Configure pull activation for GPIO[27]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_PE_BIT                   24
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_PE_MASK                  0x1000000

// Configure drive strength for GPIO[27]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_DS_BIT                   25
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_DS_MASK                  0x2000000

// Configure pull activation for GPIO[28]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_PE_BIT                   0
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_PE_MASK                  0x1

// Configure drive strength for GPIO[28]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_DS_BIT                   1
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_DS_MASK                  0x2

// Configure pull activation for GPIO[29]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_PE_BIT                   8
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_PE_MASK                  0x100

// Configure drive strength for GPIO[29]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_DS_BIT                   9
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_DS_MASK                  0x200

// Configure pull activation for GPIO[30]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_PE_BIT                   16
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_PE_MASK                  0x10000

// Configure drive strength for GPIO[30]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_DS_BIT                   17
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_DS_MASK                  0x20000

// Configure pull activation for GPIO[31]: - 1'b0: pull disabled - 1'b1: pull enabled (access: R/W)
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_PE_BIT                   24
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_PE_WIDTH                 1
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_PE_MASK                  0x1000000

// Configure drive strength for GPIO[31]: - 1'b0: low drive strength - 1'b1: high drive strength (access: R/W)
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_DS_BIT                   25
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_DS_WIDTH                 1
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_DS_MASK                  0x2000000



//
// REGISTERS STRUCTS
//

#ifndef LANGUAGE_ASSEMBLY

typedef union {
  struct {
    unsigned int dir             :32; // Configure direction of the 32 GPIOs: - bit[i]=1'b0: Input mode for GPIO[i] - bit[i]=1'b1: Output mode for GPIO[i]
  };
  unsigned int raw;
} __attribute__((packed)) gpio_apbgpio_paddir_t;

typedef union {
  struct {
    unsigned int data_in         :32; // Read value of the 32 GPIOs.
  };
  unsigned int raw;
} __attribute__((packed)) gpio_apbgpio_padin_t;

typedef union {
  struct {
    unsigned int data_out        :32; // Write value to the 32 GPIOs.
  };
  unsigned int raw;
} __attribute__((packed)) gpio_apbgpio_padout_t;

typedef union {
  struct {
    unsigned int inten           :32; // Configure interrupt mode for the 32 GPIOs: - bit[i]=1'b0: disable interrupt for GPIO[i] - bit[i]=1'b1: enable interrupt for GPIO[i]
  };
  unsigned int raw;
} __attribute__((packed)) gpio_apbgpio_inten_t;

typedef union {
  struct {
    unsigned int inttype0        :32; // Configure interrupt condition for the GPIO[15:0]: - bit[2*i+1:2*i]=2'b00: interrupt on falling edge for GPIO[i] - bit[2*i+1:2*i]=2'b01: interrupt on rising edge for GPIO[i] - bit[2*i+1:2*i]=2'b10: interrupt on rising and falling edge for GPIO[i] - bit[2*i+1:2*i]=2'b11: RFU
  };
  unsigned int raw;
} __attribute__((packed)) gpio_apbgpio_inttype0_t;

typedef union {
  struct {
    unsigned int inttype1        :32; // Configure interrupt condition for the GPIO[31:16]: - bit[2*i+1:2*i]=2'b00: interrupt on falling edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b01: interrupt on rising edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b10: interrupt on rising and falling edge for GPIO[16+i] - bit[2*i+1:2*i]=2'b11: RFU
  };
  unsigned int raw;
} __attribute__((packed)) gpio_apbgpio_inttype1_t;

typedef union {
  struct {
    unsigned int intstatus       :32; // Interrupt status flags for the 32 GPIOs.  - bit[i]=1 when interrupt received on GPIO[i] Register is cleared when read. GPIO interrupt line is also cleared when this register is red.
  };
  unsigned int raw;
} __attribute__((packed)) gpio_apbgpio_intstatus_t;

typedef union {
  struct {
    unsigned int gpioen          :32; // Configure clock enable for the 32 GPIOs: - bit[i]=1'b0: disable mode for GPIO[i] - bit[i]=1'b1: enable mode for GPIO[i] GPIOs are gathered by groups of 4. The clock-gating of one group is done only if all 4 GPIOs are disabled.
  };
  unsigned int raw;
} __attribute__((packed)) gpio_apbgpio_gpioen_t;

typedef union {
  struct {
    unsigned int padcfg0_gpio0_pe:1 ; // Configure pull activation for GPIO[0]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg0_gpio0_ds:1 ; // Configure drive strength for GPIO[0]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding0:6 ;
    unsigned int padcfg0_gpio1_pe:1 ; // Configure pull activation for GPIO[1]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg0_gpio1_ds:1 ; // Configure drive strength for GPIO[1]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding1:6 ;
    unsigned int padcfg0_gpio2_pe:1 ; // Configure pull activation for GPIO[2]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg0_gpio2_ds:1 ; // Configure drive strength for GPIO[2]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding2:6 ;
    unsigned int padcfg0_gpio3_pe:1 ; // Configure pull activation for GPIO[3]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg0_gpio3_ds:1 ; // Configure drive strength for GPIO[3]: - 1'b0: low drive strength - 1'b1: high drive strength
  };
  unsigned int raw;
} __attribute__((packed)) gpio_apbgpio_padcfg0_t;

typedef union {
  struct {
    unsigned int padcfg1_gpio4_pe:1 ; // Configure pull activation for GPIO[4]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg1_gpio4_ds:1 ; // Configure drive strength for GPIO[4]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding0:6 ;
    unsigned int padcfg1_gpio5_pe:1 ; // Configure pull activation for GPIO[5]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg1_gpio5_ds:1 ; // Configure drive strength for GPIO[5]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding1:6 ;
    unsigned int padcfg1_gpio6_pe:1 ; // Configure pull activation for GPIO[6]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg1_gpio6_ds:1 ; // Configure drive strength for GPIO[6]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding2:6 ;
    unsigned int padcfg1_gpio7_pe:1 ; // Configure pull activation for GPIO[7]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg1_gpio7_ds:1 ; // Configure drive strength for GPIO[7]: - 1'b0: low drive strength - 1'b1: high drive strength
  };
  unsigned int raw;
} __attribute__((packed)) gpio_apbgpio_padcfg1_t;

typedef union {
  struct {
    unsigned int padcfg2_gpio8_pe:1 ; // Configure pull activation for GPIO[8]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg2_gpio8_ds:1 ; // Configure drive strength for GPIO[8]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding0:6 ;
    unsigned int padcfg2_gpio9_pe:1 ; // Configure pull activation for GPIO[9]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg2_gpio9_ds:1 ; // Configure drive strength for GPIO[9]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding1:6 ;
    unsigned int padcfg2_gpio10_pe:1 ; // Configure pull activation for GPIO[10]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg2_gpio10_ds:1 ; // Configure drive strength for GPIO[10]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding2:6 ;
    unsigned int padcfg2_gpio11_pe:1 ; // Configure pull activation for GPIO[11]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg2_gpio11_ds:1 ; // Configure drive strength for GPIO[11]: - 1'b0: low drive strength - 1'b1: high drive strength
  };
  unsigned int raw;
} __attribute__((packed)) gpio_apbgpio_padcfg2_t;

typedef union {
  struct {
    unsigned int padcfg3_gpio12_pe:1 ; // Configure pull activation for GPIO[12]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg3_gpio12_ds:1 ; // Configure drive strength for GPIO[12]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding0:6 ;
    unsigned int padcfg3_gpio13_pe:1 ; // Configure pull activation for GPIO[13]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg3_gpio13_ds:1 ; // Configure drive strength for GPIO[13]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding1:6 ;
    unsigned int padcfg3_gpio14_pe:1 ; // Configure pull activation for GPIO[14]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg3_gpio14_ds:1 ; // Configure drive strength for GPIO[14]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding2:6 ;
    unsigned int padcfg3_gpio15_pe:1 ; // Configure pull activation for GPIO[15]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg3_gpio15_ds:1 ; // Configure drive strength for GPIO[15]: - 1'b0: low drive strength - 1'b1: high drive strength
  };
  unsigned int raw;
} __attribute__((packed)) gpio_apbgpio_padcfg3_t;

typedef union {
  struct {
    unsigned int padcfg4_gpio16_pe:1 ; // Configure pull activation for GPIO[16]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg4_gpio16_ds:1 ; // Configure drive strength for GPIO[16]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding0:6 ;
    unsigned int padcfg4_gpio17_pe:1 ; // Configure pull activation for GPIO[17]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg4_gpio17_ds:1 ; // Configure drive strength for GPIO[17]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding1:6 ;
    unsigned int padcfg4_gpio18_pe:1 ; // Configure pull activation for GPIO[18]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg4_gpio18_ds:1 ; // Configure drive strength for GPIO[18]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding2:6 ;
    unsigned int padcfg4_gpio19_pe:1 ; // Configure pull activation for GPIO[19]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg4_gpio19_ds:1 ; // Configure drive strength for GPIO[19]: - 1'b0: low drive strength - 1'b1: high drive strength
  };
  unsigned int raw;
} __attribute__((packed)) gpio_apbgpio_padcfg4_t;

typedef union {
  struct {
    unsigned int padcfg5_gpio20_pe:1 ; // Configure pull activation for GPIO[20]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg5_gpio20_ds:1 ; // Configure drive strength for GPIO[20]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding0:6 ;
    unsigned int padcfg5_gpio21_pe:1 ; // Configure pull activation for GPIO[21]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg5_gpio21_ds:1 ; // Configure drive strength for GPIO[21]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding1:6 ;
    unsigned int padcfg5_gpio22_pe:1 ; // Configure pull activation for GPIO[22]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg5_gpio22_ds:1 ; // Configure drive strength for GPIO[22]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding2:6 ;
    unsigned int padcfg5_gpio23_pe:1 ; // Configure pull activation for GPIO[23]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg5_gpio23_ds:1 ; // Configure drive strength for GPIO[23]: - 1'b0: low drive strength - 1'b1: high drive strength
  };
  unsigned int raw;
} __attribute__((packed)) gpio_apbgpio_padcfg5_t;

typedef union {
  struct {
    unsigned int padcfg6_gpio24_pe:1 ; // Configure pull activation for GPIO[24]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg6_gpio24_ds:1 ; // Configure drive strength for GPIO[24]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding0:6 ;
    unsigned int padcfg6_gpio25_pe:1 ; // Configure pull activation for GPIO[25]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg6_gpio25_ds:1 ; // Configure drive strength for GPIO[25]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding1:6 ;
    unsigned int padcfg6_gpio26_pe:1 ; // Configure pull activation for GPIO[26]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg6_gpio26_ds:1 ; // Configure drive strength for GPIO[26]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding2:6 ;
    unsigned int padcfg6_gpio27_pe:1 ; // Configure pull activation for GPIO[27]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg6_gpio27_ds:1 ; // Configure drive strength for GPIO[27]: - 1'b0: low drive strength - 1'b1: high drive strength
  };
  unsigned int raw;
} __attribute__((packed)) gpio_apbgpio_padcfg6_t;

typedef union {
  struct {
    unsigned int padcfg7_gpio28_pe:1 ; // Configure pull activation for GPIO[28]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg7_gpio28_ds:1 ; // Configure drive strength for GPIO[28]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding0:6 ;
    unsigned int padcfg7_gpio29_pe:1 ; // Configure pull activation for GPIO[29]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg7_gpio29_ds:1 ; // Configure drive strength for GPIO[29]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding1:6 ;
    unsigned int padcfg7_gpio30_pe:1 ; // Configure pull activation for GPIO[30]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg7_gpio30_ds:1 ; // Configure drive strength for GPIO[30]: - 1'b0: low drive strength - 1'b1: high drive strength
    unsigned int padding2:6 ;
    unsigned int padcfg7_gpio31_pe:1 ; // Configure pull activation for GPIO[31]: - 1'b0: pull disabled - 1'b1: pull enabled
    unsigned int padcfg7_gpio31_ds:1 ; // Configure drive strength for GPIO[31]: - 1'b0: low drive strength - 1'b1: high drive strength
  };
  unsigned int raw;
} __attribute__((packed)) gpio_apbgpio_padcfg7_t;

#endif



//
// REGISTERS STRUCTS
//

#ifdef __GVSOC__

class vp_gpio_apbgpio_paddir : public vp::reg_32
{
public:
  inline void dir_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADDIR_DIR_BIT, GPIO_APBGPIO_PADDIR_DIR_WIDTH); }
  inline uint32_t dir_get() { return this->get_field(GPIO_APBGPIO_PADDIR_DIR_BIT, GPIO_APBGPIO_PADDIR_DIR_WIDTH); }
};

class vp_gpio_apbgpio_padin : public vp::reg_32
{
public:
  inline void data_in_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADIN_DATA_IN_BIT, GPIO_APBGPIO_PADIN_DATA_IN_WIDTH); }
  inline uint32_t data_in_get() { return this->get_field(GPIO_APBGPIO_PADIN_DATA_IN_BIT, GPIO_APBGPIO_PADIN_DATA_IN_WIDTH); }
};

class vp_gpio_apbgpio_padout : public vp::reg_32
{
public:
  inline void data_out_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADOUT_DATA_OUT_BIT, GPIO_APBGPIO_PADOUT_DATA_OUT_WIDTH); }
  inline uint32_t data_out_get() { return this->get_field(GPIO_APBGPIO_PADOUT_DATA_OUT_BIT, GPIO_APBGPIO_PADOUT_DATA_OUT_WIDTH); }
};

class vp_gpio_apbgpio_inten : public vp::reg_32
{
public:
  inline void inten_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_INTEN_INTEN_BIT, GPIO_APBGPIO_INTEN_INTEN_WIDTH); }
  inline uint32_t inten_get() { return this->get_field(GPIO_APBGPIO_INTEN_INTEN_BIT, GPIO_APBGPIO_INTEN_INTEN_WIDTH); }
};

class vp_gpio_apbgpio_inttype0 : public vp::reg_32
{
public:
  inline void inttype0_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_INTTYPE0_INTTYPE0_BIT, GPIO_APBGPIO_INTTYPE0_INTTYPE0_WIDTH); }
  inline uint32_t inttype0_get() { return this->get_field(GPIO_APBGPIO_INTTYPE0_INTTYPE0_BIT, GPIO_APBGPIO_INTTYPE0_INTTYPE0_WIDTH); }
};

class vp_gpio_apbgpio_inttype1 : public vp::reg_32
{
public:
  inline void inttype1_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_INTTYPE1_INTTYPE1_BIT, GPIO_APBGPIO_INTTYPE1_INTTYPE1_WIDTH); }
  inline uint32_t inttype1_get() { return this->get_field(GPIO_APBGPIO_INTTYPE1_INTTYPE1_BIT, GPIO_APBGPIO_INTTYPE1_INTTYPE1_WIDTH); }
};

class vp_gpio_apbgpio_intstatus : public vp::reg_32
{
public:
  inline void intstatus_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_INTSTATUS_INTSTATUS_BIT, GPIO_APBGPIO_INTSTATUS_INTSTATUS_WIDTH); }
  inline uint32_t intstatus_get() { return this->get_field(GPIO_APBGPIO_INTSTATUS_INTSTATUS_BIT, GPIO_APBGPIO_INTSTATUS_INTSTATUS_WIDTH); }
};

class vp_gpio_apbgpio_gpioen : public vp::reg_32
{
public:
  inline void gpioen_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_GPIOEN_GPIOEN_BIT, GPIO_APBGPIO_GPIOEN_GPIOEN_WIDTH); }
  inline uint32_t gpioen_get() { return this->get_field(GPIO_APBGPIO_GPIOEN_GPIOEN_BIT, GPIO_APBGPIO_GPIOEN_GPIOEN_WIDTH); }
};

class vp_gpio_apbgpio_padcfg0 : public vp::reg_32
{
public:
  inline void padcfg0_gpio0_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_PE_BIT, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_PE_WIDTH); }
  inline uint32_t padcfg0_gpio0_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_PE_BIT, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_PE_WIDTH); }
  inline void padcfg0_gpio0_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_DS_BIT, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_DS_WIDTH); }
  inline uint32_t padcfg0_gpio0_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_DS_BIT, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_DS_WIDTH); }
  inline void padcfg0_gpio1_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_PE_BIT, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_PE_WIDTH); }
  inline uint32_t padcfg0_gpio1_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_PE_BIT, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_PE_WIDTH); }
  inline void padcfg0_gpio1_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_DS_BIT, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_DS_WIDTH); }
  inline uint32_t padcfg0_gpio1_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_DS_BIT, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_DS_WIDTH); }
  inline void padcfg0_gpio2_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_PE_BIT, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_PE_WIDTH); }
  inline uint32_t padcfg0_gpio2_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_PE_BIT, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_PE_WIDTH); }
  inline void padcfg0_gpio2_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_DS_BIT, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_DS_WIDTH); }
  inline uint32_t padcfg0_gpio2_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_DS_BIT, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_DS_WIDTH); }
  inline void padcfg0_gpio3_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_PE_BIT, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_PE_WIDTH); }
  inline uint32_t padcfg0_gpio3_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_PE_BIT, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_PE_WIDTH); }
  inline void padcfg0_gpio3_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_DS_BIT, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_DS_WIDTH); }
  inline uint32_t padcfg0_gpio3_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_DS_BIT, GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_DS_WIDTH); }
};

class vp_gpio_apbgpio_padcfg1 : public vp::reg_32
{
public:
  inline void padcfg1_gpio4_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_PE_BIT, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_PE_WIDTH); }
  inline uint32_t padcfg1_gpio4_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_PE_BIT, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_PE_WIDTH); }
  inline void padcfg1_gpio4_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_DS_BIT, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_DS_WIDTH); }
  inline uint32_t padcfg1_gpio4_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_DS_BIT, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_DS_WIDTH); }
  inline void padcfg1_gpio5_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_PE_BIT, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_PE_WIDTH); }
  inline uint32_t padcfg1_gpio5_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_PE_BIT, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_PE_WIDTH); }
  inline void padcfg1_gpio5_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_DS_BIT, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_DS_WIDTH); }
  inline uint32_t padcfg1_gpio5_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_DS_BIT, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_DS_WIDTH); }
  inline void padcfg1_gpio6_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_PE_BIT, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_PE_WIDTH); }
  inline uint32_t padcfg1_gpio6_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_PE_BIT, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_PE_WIDTH); }
  inline void padcfg1_gpio6_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_DS_BIT, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_DS_WIDTH); }
  inline uint32_t padcfg1_gpio6_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_DS_BIT, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_DS_WIDTH); }
  inline void padcfg1_gpio7_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_PE_BIT, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_PE_WIDTH); }
  inline uint32_t padcfg1_gpio7_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_PE_BIT, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_PE_WIDTH); }
  inline void padcfg1_gpio7_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_DS_BIT, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_DS_WIDTH); }
  inline uint32_t padcfg1_gpio7_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_DS_BIT, GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_DS_WIDTH); }
};

class vp_gpio_apbgpio_padcfg2 : public vp::reg_32
{
public:
  inline void padcfg2_gpio8_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_PE_BIT, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_PE_WIDTH); }
  inline uint32_t padcfg2_gpio8_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_PE_BIT, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_PE_WIDTH); }
  inline void padcfg2_gpio8_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_DS_BIT, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_DS_WIDTH); }
  inline uint32_t padcfg2_gpio8_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_DS_BIT, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_DS_WIDTH); }
  inline void padcfg2_gpio9_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_PE_BIT, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_PE_WIDTH); }
  inline uint32_t padcfg2_gpio9_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_PE_BIT, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_PE_WIDTH); }
  inline void padcfg2_gpio9_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_DS_BIT, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_DS_WIDTH); }
  inline uint32_t padcfg2_gpio9_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_DS_BIT, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_DS_WIDTH); }
  inline void padcfg2_gpio10_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_PE_BIT, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_PE_WIDTH); }
  inline uint32_t padcfg2_gpio10_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_PE_BIT, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_PE_WIDTH); }
  inline void padcfg2_gpio10_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_DS_BIT, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_DS_WIDTH); }
  inline uint32_t padcfg2_gpio10_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_DS_BIT, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_DS_WIDTH); }
  inline void padcfg2_gpio11_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_PE_BIT, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_PE_WIDTH); }
  inline uint32_t padcfg2_gpio11_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_PE_BIT, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_PE_WIDTH); }
  inline void padcfg2_gpio11_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_DS_BIT, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_DS_WIDTH); }
  inline uint32_t padcfg2_gpio11_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_DS_BIT, GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_DS_WIDTH); }
};

class vp_gpio_apbgpio_padcfg3 : public vp::reg_32
{
public:
  inline void padcfg3_gpio12_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_PE_BIT, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_PE_WIDTH); }
  inline uint32_t padcfg3_gpio12_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_PE_BIT, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_PE_WIDTH); }
  inline void padcfg3_gpio12_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_DS_BIT, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_DS_WIDTH); }
  inline uint32_t padcfg3_gpio12_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_DS_BIT, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_DS_WIDTH); }
  inline void padcfg3_gpio13_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_PE_BIT, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_PE_WIDTH); }
  inline uint32_t padcfg3_gpio13_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_PE_BIT, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_PE_WIDTH); }
  inline void padcfg3_gpio13_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_DS_BIT, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_DS_WIDTH); }
  inline uint32_t padcfg3_gpio13_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_DS_BIT, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_DS_WIDTH); }
  inline void padcfg3_gpio14_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_PE_BIT, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_PE_WIDTH); }
  inline uint32_t padcfg3_gpio14_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_PE_BIT, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_PE_WIDTH); }
  inline void padcfg3_gpio14_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_DS_BIT, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_DS_WIDTH); }
  inline uint32_t padcfg3_gpio14_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_DS_BIT, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_DS_WIDTH); }
  inline void padcfg3_gpio15_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_PE_BIT, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_PE_WIDTH); }
  inline uint32_t padcfg3_gpio15_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_PE_BIT, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_PE_WIDTH); }
  inline void padcfg3_gpio15_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_DS_BIT, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_DS_WIDTH); }
  inline uint32_t padcfg3_gpio15_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_DS_BIT, GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_DS_WIDTH); }
};

class vp_gpio_apbgpio_padcfg4 : public vp::reg_32
{
public:
  inline void padcfg4_gpio16_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_PE_BIT, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_PE_WIDTH); }
  inline uint32_t padcfg4_gpio16_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_PE_BIT, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_PE_WIDTH); }
  inline void padcfg4_gpio16_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_DS_BIT, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_DS_WIDTH); }
  inline uint32_t padcfg4_gpio16_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_DS_BIT, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_DS_WIDTH); }
  inline void padcfg4_gpio17_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_PE_BIT, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_PE_WIDTH); }
  inline uint32_t padcfg4_gpio17_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_PE_BIT, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_PE_WIDTH); }
  inline void padcfg4_gpio17_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_DS_BIT, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_DS_WIDTH); }
  inline uint32_t padcfg4_gpio17_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_DS_BIT, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_DS_WIDTH); }
  inline void padcfg4_gpio18_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_PE_BIT, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_PE_WIDTH); }
  inline uint32_t padcfg4_gpio18_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_PE_BIT, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_PE_WIDTH); }
  inline void padcfg4_gpio18_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_DS_BIT, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_DS_WIDTH); }
  inline uint32_t padcfg4_gpio18_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_DS_BIT, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_DS_WIDTH); }
  inline void padcfg4_gpio19_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_PE_BIT, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_PE_WIDTH); }
  inline uint32_t padcfg4_gpio19_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_PE_BIT, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_PE_WIDTH); }
  inline void padcfg4_gpio19_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_DS_BIT, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_DS_WIDTH); }
  inline uint32_t padcfg4_gpio19_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_DS_BIT, GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_DS_WIDTH); }
};

class vp_gpio_apbgpio_padcfg5 : public vp::reg_32
{
public:
  inline void padcfg5_gpio20_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_PE_BIT, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_PE_WIDTH); }
  inline uint32_t padcfg5_gpio20_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_PE_BIT, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_PE_WIDTH); }
  inline void padcfg5_gpio20_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_DS_BIT, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_DS_WIDTH); }
  inline uint32_t padcfg5_gpio20_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_DS_BIT, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_DS_WIDTH); }
  inline void padcfg5_gpio21_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_PE_BIT, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_PE_WIDTH); }
  inline uint32_t padcfg5_gpio21_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_PE_BIT, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_PE_WIDTH); }
  inline void padcfg5_gpio21_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_DS_BIT, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_DS_WIDTH); }
  inline uint32_t padcfg5_gpio21_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_DS_BIT, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_DS_WIDTH); }
  inline void padcfg5_gpio22_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_PE_BIT, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_PE_WIDTH); }
  inline uint32_t padcfg5_gpio22_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_PE_BIT, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_PE_WIDTH); }
  inline void padcfg5_gpio22_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_DS_BIT, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_DS_WIDTH); }
  inline uint32_t padcfg5_gpio22_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_DS_BIT, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_DS_WIDTH); }
  inline void padcfg5_gpio23_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_PE_BIT, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_PE_WIDTH); }
  inline uint32_t padcfg5_gpio23_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_PE_BIT, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_PE_WIDTH); }
  inline void padcfg5_gpio23_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_DS_BIT, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_DS_WIDTH); }
  inline uint32_t padcfg5_gpio23_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_DS_BIT, GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_DS_WIDTH); }
};

class vp_gpio_apbgpio_padcfg6 : public vp::reg_32
{
public:
  inline void padcfg6_gpio24_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_PE_BIT, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_PE_WIDTH); }
  inline uint32_t padcfg6_gpio24_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_PE_BIT, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_PE_WIDTH); }
  inline void padcfg6_gpio24_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_DS_BIT, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_DS_WIDTH); }
  inline uint32_t padcfg6_gpio24_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_DS_BIT, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_DS_WIDTH); }
  inline void padcfg6_gpio25_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_PE_BIT, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_PE_WIDTH); }
  inline uint32_t padcfg6_gpio25_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_PE_BIT, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_PE_WIDTH); }
  inline void padcfg6_gpio25_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_DS_BIT, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_DS_WIDTH); }
  inline uint32_t padcfg6_gpio25_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_DS_BIT, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_DS_WIDTH); }
  inline void padcfg6_gpio26_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_PE_BIT, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_PE_WIDTH); }
  inline uint32_t padcfg6_gpio26_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_PE_BIT, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_PE_WIDTH); }
  inline void padcfg6_gpio26_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_DS_BIT, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_DS_WIDTH); }
  inline uint32_t padcfg6_gpio26_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_DS_BIT, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_DS_WIDTH); }
  inline void padcfg6_gpio27_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_PE_BIT, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_PE_WIDTH); }
  inline uint32_t padcfg6_gpio27_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_PE_BIT, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_PE_WIDTH); }
  inline void padcfg6_gpio27_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_DS_BIT, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_DS_WIDTH); }
  inline uint32_t padcfg6_gpio27_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_DS_BIT, GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_DS_WIDTH); }
};

class vp_gpio_apbgpio_padcfg7 : public vp::reg_32
{
public:
  inline void padcfg7_gpio28_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_PE_BIT, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_PE_WIDTH); }
  inline uint32_t padcfg7_gpio28_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_PE_BIT, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_PE_WIDTH); }
  inline void padcfg7_gpio28_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_DS_BIT, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_DS_WIDTH); }
  inline uint32_t padcfg7_gpio28_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_DS_BIT, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_DS_WIDTH); }
  inline void padcfg7_gpio29_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_PE_BIT, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_PE_WIDTH); }
  inline uint32_t padcfg7_gpio29_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_PE_BIT, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_PE_WIDTH); }
  inline void padcfg7_gpio29_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_DS_BIT, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_DS_WIDTH); }
  inline uint32_t padcfg7_gpio29_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_DS_BIT, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_DS_WIDTH); }
  inline void padcfg7_gpio30_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_PE_BIT, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_PE_WIDTH); }
  inline uint32_t padcfg7_gpio30_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_PE_BIT, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_PE_WIDTH); }
  inline void padcfg7_gpio30_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_DS_BIT, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_DS_WIDTH); }
  inline uint32_t padcfg7_gpio30_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_DS_BIT, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_DS_WIDTH); }
  inline void padcfg7_gpio31_pe_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_PE_BIT, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_PE_WIDTH); }
  inline uint32_t padcfg7_gpio31_pe_get() { return this->get_field(GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_PE_BIT, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_PE_WIDTH); }
  inline void padcfg7_gpio31_ds_set(uint32_t value) { this->set_field(value, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_DS_BIT, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_DS_WIDTH); }
  inline uint32_t padcfg7_gpio31_ds_get() { return this->get_field(GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_DS_BIT, GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_DS_WIDTH); }
};

#endif



//
// REGISTERS GLOBAL STRUCT
//

#ifndef LANGUAGE_ASSEMBLY

typedef struct {
  unsigned int apbgpio_paddir  ; // GPIO pad direction configuration
  unsigned int apbgpio_padin   ; // GPIO pad input value
  unsigned int apbgpio_padout  ; // GPIO pad output value
  unsigned int apbgpio_inten   ; // GPIO pad interrupt enable configuration
  unsigned int apbgpio_inttype0; // GPIO pad interrupt type bit 0 configuration
  unsigned int apbgpio_inttype1; // GPIO pad interrupt type bit 1 configuration
  unsigned int apbgpio_intstatus; // GPIO pad interrupt status
  unsigned int apbgpio_gpioen  ; // GPIO pad enable configuration
  unsigned int apbgpio_padcfg0 ; // GPIO pad pin 0 to 3 configuration
  unsigned int apbgpio_padcfg1 ; // GPIO pad pin 4 to 7 configuration
  unsigned int apbgpio_padcfg2 ; // GPIO pad pin 8 to 11 configuration
  unsigned int apbgpio_padcfg3 ; // GPIO pad pin 12 to 15 configuration
  unsigned int apbgpio_padcfg4 ; // GPIO pad pin 16 to 19 configuration
  unsigned int apbgpio_padcfg5 ; // GPIO pad pin 20 to 23 configuration
  unsigned int apbgpio_padcfg6 ; // GPIO pad pin 24 to 27 configuration
  unsigned int apbgpio_padcfg7 ; // GPIO pad pin 28 to 31 configuration
} __attribute__((packed)) gpio_gpio_t;

#endif



//
// REGISTERS ACCESS FUNCTIONS
//

#ifndef LANGUAGE_ASSEMBLY

static inline uint32_t gpio_apbgpio_paddir_get(uint32_t base) { return ARCHI_READ(base, GPIO_APBGPIO_PADDIR_OFFSET); }
static inline void gpio_apbgpio_paddir_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_APBGPIO_PADDIR_OFFSET, value); }

static inline uint32_t gpio_apbgpio_padin_get(uint32_t base) { return ARCHI_READ(base, GPIO_APBGPIO_PADIN_OFFSET); }
static inline void gpio_apbgpio_padin_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_APBGPIO_PADIN_OFFSET, value); }

static inline uint32_t gpio_apbgpio_padout_get(uint32_t base) { return ARCHI_READ(base, GPIO_APBGPIO_PADOUT_OFFSET); }
static inline void gpio_apbgpio_padout_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_APBGPIO_PADOUT_OFFSET, value); }

static inline uint32_t gpio_apbgpio_inten_get(uint32_t base) { return ARCHI_READ(base, GPIO_APBGPIO_INTEN_OFFSET); }
static inline void gpio_apbgpio_inten_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_APBGPIO_INTEN_OFFSET, value); }

static inline uint32_t gpio_apbgpio_inttype0_get(uint32_t base) { return ARCHI_READ(base, GPIO_APBGPIO_INTTYPE0_OFFSET); }
static inline void gpio_apbgpio_inttype0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_APBGPIO_INTTYPE0_OFFSET, value); }

static inline uint32_t gpio_apbgpio_inttype1_get(uint32_t base) { return ARCHI_READ(base, GPIO_APBGPIO_INTTYPE1_OFFSET); }
static inline void gpio_apbgpio_inttype1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_APBGPIO_INTTYPE1_OFFSET, value); }

static inline uint32_t gpio_apbgpio_intstatus_get(uint32_t base) { return ARCHI_READ(base, GPIO_APBGPIO_INTSTATUS_OFFSET); }
static inline void gpio_apbgpio_intstatus_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_APBGPIO_INTSTATUS_OFFSET, value); }

static inline uint32_t gpio_apbgpio_gpioen_get(uint32_t base) { return ARCHI_READ(base, GPIO_APBGPIO_GPIOEN_OFFSET); }
static inline void gpio_apbgpio_gpioen_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_APBGPIO_GPIOEN_OFFSET, value); }

static inline uint32_t gpio_apbgpio_padcfg0_get(uint32_t base) { return ARCHI_READ(base, GPIO_APBGPIO_PADCFG0_OFFSET); }
static inline void gpio_apbgpio_padcfg0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_APBGPIO_PADCFG0_OFFSET, value); }

static inline uint32_t gpio_apbgpio_padcfg1_get(uint32_t base) { return ARCHI_READ(base, GPIO_APBGPIO_PADCFG1_OFFSET); }
static inline void gpio_apbgpio_padcfg1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_APBGPIO_PADCFG1_OFFSET, value); }

static inline uint32_t gpio_apbgpio_padcfg2_get(uint32_t base) { return ARCHI_READ(base, GPIO_APBGPIO_PADCFG2_OFFSET); }
static inline void gpio_apbgpio_padcfg2_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_APBGPIO_PADCFG2_OFFSET, value); }

static inline uint32_t gpio_apbgpio_padcfg3_get(uint32_t base) { return ARCHI_READ(base, GPIO_APBGPIO_PADCFG3_OFFSET); }
static inline void gpio_apbgpio_padcfg3_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_APBGPIO_PADCFG3_OFFSET, value); }

static inline uint32_t gpio_apbgpio_padcfg4_get(uint32_t base) { return ARCHI_READ(base, GPIO_APBGPIO_PADCFG4_OFFSET); }
static inline void gpio_apbgpio_padcfg4_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_APBGPIO_PADCFG4_OFFSET, value); }

static inline uint32_t gpio_apbgpio_padcfg5_get(uint32_t base) { return ARCHI_READ(base, GPIO_APBGPIO_PADCFG5_OFFSET); }
static inline void gpio_apbgpio_padcfg5_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_APBGPIO_PADCFG5_OFFSET, value); }

static inline uint32_t gpio_apbgpio_padcfg6_get(uint32_t base) { return ARCHI_READ(base, GPIO_APBGPIO_PADCFG6_OFFSET); }
static inline void gpio_apbgpio_padcfg6_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_APBGPIO_PADCFG6_OFFSET, value); }

static inline uint32_t gpio_apbgpio_padcfg7_get(uint32_t base) { return ARCHI_READ(base, GPIO_APBGPIO_PADCFG7_OFFSET); }
static inline void gpio_apbgpio_padcfg7_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, GPIO_APBGPIO_PADCFG7_OFFSET, value); }

#endif



//
// REGISTERS FIELDS MACROS
//

#ifndef LANGUAGE_ASSEMBLY

#define GPIO_APBGPIO_PADDIR_DIR_GET(value)                 (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_APBGPIO_PADDIR_DIR_GETS(value)                (ARCHI_BEXTRACT((value),32,0))
#define GPIO_APBGPIO_PADDIR_DIR_SET(value,field)           (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_APBGPIO_PADDIR_DIR(val)                       ((val) << 0)

#define GPIO_APBGPIO_PADIN_DATA_IN_GET(value)              (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_APBGPIO_PADIN_DATA_IN_GETS(value)             (ARCHI_BEXTRACT((value),32,0))
#define GPIO_APBGPIO_PADIN_DATA_IN_SET(value,field)        (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_APBGPIO_PADIN_DATA_IN(val)                    ((val) << 0)

#define GPIO_APBGPIO_PADOUT_DATA_OUT_GET(value)            (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_APBGPIO_PADOUT_DATA_OUT_GETS(value)           (ARCHI_BEXTRACT((value),32,0))
#define GPIO_APBGPIO_PADOUT_DATA_OUT_SET(value,field)      (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_APBGPIO_PADOUT_DATA_OUT(val)                  ((val) << 0)

#define GPIO_APBGPIO_INTEN_INTEN_GET(value)                (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_APBGPIO_INTEN_INTEN_GETS(value)               (ARCHI_BEXTRACT((value),32,0))
#define GPIO_APBGPIO_INTEN_INTEN_SET(value,field)          (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_APBGPIO_INTEN_INTEN(val)                      ((val) << 0)

#define GPIO_APBGPIO_INTTYPE0_INTTYPE0_GET(value)          (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_APBGPIO_INTTYPE0_INTTYPE0_GETS(value)         (ARCHI_BEXTRACT((value),32,0))
#define GPIO_APBGPIO_INTTYPE0_INTTYPE0_SET(value,field)    (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_APBGPIO_INTTYPE0_INTTYPE0(val)                ((val) << 0)

#define GPIO_APBGPIO_INTTYPE1_INTTYPE1_GET(value)          (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_APBGPIO_INTTYPE1_INTTYPE1_GETS(value)         (ARCHI_BEXTRACT((value),32,0))
#define GPIO_APBGPIO_INTTYPE1_INTTYPE1_SET(value,field)    (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_APBGPIO_INTTYPE1_INTTYPE1(val)                ((val) << 0)

#define GPIO_APBGPIO_INTSTATUS_INTSTATUS_GET(value)        (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_APBGPIO_INTSTATUS_INTSTATUS_GETS(value)       (ARCHI_BEXTRACT((value),32,0))
#define GPIO_APBGPIO_INTSTATUS_INTSTATUS_SET(value,field)  (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_APBGPIO_INTSTATUS_INTSTATUS(val)              ((val) << 0)

#define GPIO_APBGPIO_GPIOEN_GPIOEN_GET(value)              (ARCHI_BEXTRACTU((value),32,0))
#define GPIO_APBGPIO_GPIOEN_GPIOEN_GETS(value)             (ARCHI_BEXTRACT((value),32,0))
#define GPIO_APBGPIO_GPIOEN_GPIOEN_SET(value,field)        (ARCHI_BINSERT((value),(field),32,0))
#define GPIO_APBGPIO_GPIOEN_GPIOEN(val)                    ((val) << 0)

#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_PE_GET(value)   (ARCHI_BEXTRACTU((value),1,0))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_PE_GETS(value)  (ARCHI_BEXTRACT((value),1,0))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,0))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_PE(val)         ((val) << 0)

#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_DS_GET(value)   (ARCHI_BEXTRACTU((value),1,1))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_DS_GETS(value)  (ARCHI_BEXTRACT((value),1,1))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,1))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO0_DS(val)         ((val) << 1)

#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_PE_GET(value)   (ARCHI_BEXTRACTU((value),1,8))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_PE_GETS(value)  (ARCHI_BEXTRACT((value),1,8))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,8))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_PE(val)         ((val) << 8)

#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_DS_GET(value)   (ARCHI_BEXTRACTU((value),1,9))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_DS_GETS(value)  (ARCHI_BEXTRACT((value),1,9))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,9))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO1_DS(val)         ((val) << 9)

#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_PE_GET(value)   (ARCHI_BEXTRACTU((value),1,16))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_PE_GETS(value)  (ARCHI_BEXTRACT((value),1,16))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,16))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_PE(val)         ((val) << 16)

#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_DS_GET(value)   (ARCHI_BEXTRACTU((value),1,17))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_DS_GETS(value)  (ARCHI_BEXTRACT((value),1,17))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,17))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO2_DS(val)         ((val) << 17)

#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_PE_GET(value)   (ARCHI_BEXTRACTU((value),1,24))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_PE_GETS(value)  (ARCHI_BEXTRACT((value),1,24))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,24))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_PE(val)         ((val) << 24)

#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_DS_GET(value)   (ARCHI_BEXTRACTU((value),1,25))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_DS_GETS(value)  (ARCHI_BEXTRACT((value),1,25))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,25))
#define GPIO_APBGPIO_PADCFG0_PADCFG0_GPIO3_DS(val)         ((val) << 25)

#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_PE_GET(value)   (ARCHI_BEXTRACTU((value),1,0))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_PE_GETS(value)  (ARCHI_BEXTRACT((value),1,0))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,0))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_PE(val)         ((val) << 0)

#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_DS_GET(value)   (ARCHI_BEXTRACTU((value),1,1))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_DS_GETS(value)  (ARCHI_BEXTRACT((value),1,1))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,1))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO4_DS(val)         ((val) << 1)

#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_PE_GET(value)   (ARCHI_BEXTRACTU((value),1,8))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_PE_GETS(value)  (ARCHI_BEXTRACT((value),1,8))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,8))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_PE(val)         ((val) << 8)

#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_DS_GET(value)   (ARCHI_BEXTRACTU((value),1,9))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_DS_GETS(value)  (ARCHI_BEXTRACT((value),1,9))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,9))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO5_DS(val)         ((val) << 9)

#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_PE_GET(value)   (ARCHI_BEXTRACTU((value),1,16))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_PE_GETS(value)  (ARCHI_BEXTRACT((value),1,16))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,16))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_PE(val)         ((val) << 16)

#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_DS_GET(value)   (ARCHI_BEXTRACTU((value),1,17))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_DS_GETS(value)  (ARCHI_BEXTRACT((value),1,17))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,17))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO6_DS(val)         ((val) << 17)

#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_PE_GET(value)   (ARCHI_BEXTRACTU((value),1,24))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_PE_GETS(value)  (ARCHI_BEXTRACT((value),1,24))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,24))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_PE(val)         ((val) << 24)

#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_DS_GET(value)   (ARCHI_BEXTRACTU((value),1,25))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_DS_GETS(value)  (ARCHI_BEXTRACT((value),1,25))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,25))
#define GPIO_APBGPIO_PADCFG1_PADCFG1_GPIO7_DS(val)         ((val) << 25)

#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_PE_GET(value)   (ARCHI_BEXTRACTU((value),1,0))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_PE_GETS(value)  (ARCHI_BEXTRACT((value),1,0))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,0))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_PE(val)         ((val) << 0)

#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_DS_GET(value)   (ARCHI_BEXTRACTU((value),1,1))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_DS_GETS(value)  (ARCHI_BEXTRACT((value),1,1))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,1))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO8_DS(val)         ((val) << 1)

#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_PE_GET(value)   (ARCHI_BEXTRACTU((value),1,8))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_PE_GETS(value)  (ARCHI_BEXTRACT((value),1,8))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,8))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_PE(val)         ((val) << 8)

#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_DS_GET(value)   (ARCHI_BEXTRACTU((value),1,9))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_DS_GETS(value)  (ARCHI_BEXTRACT((value),1,9))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,9))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO9_DS(val)         ((val) << 9)

#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,16))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_PE_GETS(value) (ARCHI_BEXTRACT((value),1,16))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,16))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_PE(val)        ((val) << 16)

#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,17))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_DS_GETS(value) (ARCHI_BEXTRACT((value),1,17))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,17))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO10_DS(val)        ((val) << 17)

#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,24))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_PE_GETS(value) (ARCHI_BEXTRACT((value),1,24))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,24))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_PE(val)        ((val) << 24)

#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,25))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_DS_GETS(value) (ARCHI_BEXTRACT((value),1,25))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,25))
#define GPIO_APBGPIO_PADCFG2_PADCFG2_GPIO11_DS(val)        ((val) << 25)

#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,0))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_PE_GETS(value) (ARCHI_BEXTRACT((value),1,0))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,0))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_PE(val)        ((val) << 0)

#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,1))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_DS_GETS(value) (ARCHI_BEXTRACT((value),1,1))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,1))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO12_DS(val)        ((val) << 1)

#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,8))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_PE_GETS(value) (ARCHI_BEXTRACT((value),1,8))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,8))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_PE(val)        ((val) << 8)

#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,9))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_DS_GETS(value) (ARCHI_BEXTRACT((value),1,9))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,9))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO13_DS(val)        ((val) << 9)

#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,16))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_PE_GETS(value) (ARCHI_BEXTRACT((value),1,16))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,16))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_PE(val)        ((val) << 16)

#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,17))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_DS_GETS(value) (ARCHI_BEXTRACT((value),1,17))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,17))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO14_DS(val)        ((val) << 17)

#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,24))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_PE_GETS(value) (ARCHI_BEXTRACT((value),1,24))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,24))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_PE(val)        ((val) << 24)

#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,25))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_DS_GETS(value) (ARCHI_BEXTRACT((value),1,25))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,25))
#define GPIO_APBGPIO_PADCFG3_PADCFG3_GPIO15_DS(val)        ((val) << 25)

#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,0))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_PE_GETS(value) (ARCHI_BEXTRACT((value),1,0))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,0))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_PE(val)        ((val) << 0)

#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,1))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_DS_GETS(value) (ARCHI_BEXTRACT((value),1,1))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,1))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO16_DS(val)        ((val) << 1)

#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,8))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_PE_GETS(value) (ARCHI_BEXTRACT((value),1,8))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,8))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_PE(val)        ((val) << 8)

#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,9))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_DS_GETS(value) (ARCHI_BEXTRACT((value),1,9))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,9))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO17_DS(val)        ((val) << 9)

#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,16))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_PE_GETS(value) (ARCHI_BEXTRACT((value),1,16))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,16))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_PE(val)        ((val) << 16)

#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,17))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_DS_GETS(value) (ARCHI_BEXTRACT((value),1,17))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,17))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO18_DS(val)        ((val) << 17)

#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,24))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_PE_GETS(value) (ARCHI_BEXTRACT((value),1,24))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,24))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_PE(val)        ((val) << 24)

#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,25))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_DS_GETS(value) (ARCHI_BEXTRACT((value),1,25))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,25))
#define GPIO_APBGPIO_PADCFG4_PADCFG4_GPIO19_DS(val)        ((val) << 25)

#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,0))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_PE_GETS(value) (ARCHI_BEXTRACT((value),1,0))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,0))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_PE(val)        ((val) << 0)

#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,1))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_DS_GETS(value) (ARCHI_BEXTRACT((value),1,1))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,1))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO20_DS(val)        ((val) << 1)

#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,8))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_PE_GETS(value) (ARCHI_BEXTRACT((value),1,8))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,8))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_PE(val)        ((val) << 8)

#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,9))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_DS_GETS(value) (ARCHI_BEXTRACT((value),1,9))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,9))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO21_DS(val)        ((val) << 9)

#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,16))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_PE_GETS(value) (ARCHI_BEXTRACT((value),1,16))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,16))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_PE(val)        ((val) << 16)

#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,17))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_DS_GETS(value) (ARCHI_BEXTRACT((value),1,17))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,17))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO22_DS(val)        ((val) << 17)

#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,24))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_PE_GETS(value) (ARCHI_BEXTRACT((value),1,24))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,24))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_PE(val)        ((val) << 24)

#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,25))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_DS_GETS(value) (ARCHI_BEXTRACT((value),1,25))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,25))
#define GPIO_APBGPIO_PADCFG5_PADCFG5_GPIO23_DS(val)        ((val) << 25)

#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,0))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_PE_GETS(value) (ARCHI_BEXTRACT((value),1,0))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,0))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_PE(val)        ((val) << 0)

#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,1))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_DS_GETS(value) (ARCHI_BEXTRACT((value),1,1))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,1))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO24_DS(val)        ((val) << 1)

#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,8))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_PE_GETS(value) (ARCHI_BEXTRACT((value),1,8))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,8))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_PE(val)        ((val) << 8)

#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,9))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_DS_GETS(value) (ARCHI_BEXTRACT((value),1,9))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,9))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO25_DS(val)        ((val) << 9)

#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,16))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_PE_GETS(value) (ARCHI_BEXTRACT((value),1,16))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,16))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_PE(val)        ((val) << 16)

#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,17))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_DS_GETS(value) (ARCHI_BEXTRACT((value),1,17))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,17))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO26_DS(val)        ((val) << 17)

#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,24))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_PE_GETS(value) (ARCHI_BEXTRACT((value),1,24))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,24))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_PE(val)        ((val) << 24)

#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,25))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_DS_GETS(value) (ARCHI_BEXTRACT((value),1,25))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,25))
#define GPIO_APBGPIO_PADCFG6_PADCFG6_GPIO27_DS(val)        ((val) << 25)

#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,0))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_PE_GETS(value) (ARCHI_BEXTRACT((value),1,0))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,0))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_PE(val)        ((val) << 0)

#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,1))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_DS_GETS(value) (ARCHI_BEXTRACT((value),1,1))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,1))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO28_DS(val)        ((val) << 1)

#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,8))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_PE_GETS(value) (ARCHI_BEXTRACT((value),1,8))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,8))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_PE(val)        ((val) << 8)

#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,9))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_DS_GETS(value) (ARCHI_BEXTRACT((value),1,9))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,9))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO29_DS(val)        ((val) << 9)

#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,16))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_PE_GETS(value) (ARCHI_BEXTRACT((value),1,16))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,16))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_PE(val)        ((val) << 16)

#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,17))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_DS_GETS(value) (ARCHI_BEXTRACT((value),1,17))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,17))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO30_DS(val)        ((val) << 17)

#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_PE_GET(value)  (ARCHI_BEXTRACTU((value),1,24))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_PE_GETS(value) (ARCHI_BEXTRACT((value),1,24))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_PE_SET(value,field) (ARCHI_BINSERT((value),(field),1,24))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_PE(val)        ((val) << 24)

#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_DS_GET(value)  (ARCHI_BEXTRACTU((value),1,25))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_DS_GETS(value) (ARCHI_BEXTRACT((value),1,25))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_DS_SET(value,field) (ARCHI_BINSERT((value),(field),1,25))
#define GPIO_APBGPIO_PADCFG7_PADCFG7_GPIO31_DS(val)        ((val) << 25)

#endif

#endif
