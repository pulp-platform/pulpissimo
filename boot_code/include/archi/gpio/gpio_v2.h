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

#ifndef __ARCHI_GPIO_GPIO_V2_H__
#define __ARCHI_GPIO_GPIO_V2_H__

#include "archi/gpio/gpio_v2_new.h"

#define ARCHI_GPIO_PADDIR    0x0    // Direction		i:0..31, GPIOi => Bit[i] = 1 Output, Bit[i] = 0 Input (Default)
#define ARCHI_GPIO_PADIN     0x4    // i:0..31, Bit[i] Received bit from GPIOi
#define ARCHI_GPIO_PADOUT    0x8    // i:0..31, Bit[i] Bit to transmit through GPIOi
#define ARCHI_GPIO_INTEN     0xC    // i:0..31, Bit[i]=1 Enable Event for GPIOi
#define ARCHI_GPIO_INTTYPE0  0x10   // Interrupt Condition	i:0..15, Bit[2*i:2*i+1] = 00 Falling edge		on GPIOi
                                  // = 01 Raising edge		on GPIOi
                                  // = 11 Raising then falling edge	on GPIOi
#define ARCHI_GPIO_INTTYPE1  0x14   // Interrupt Condition	i:0..15, Bit[2*i:2*i+1] = 00 Falling edge		on GPIOi+16
                                  // = 01 Raising edge		on GPIOi+16
                                  // = 11 Raising the falling edge	on GPIOi+16
#define ARCHI_GPIO_INTSTATUS 0x18   // Interrupt Status	i:0..31, Bit[i]=1 Event received for GPIOi, bit is cleared when readen
#define GPIO_INTSTATUS_OFFSET ARCHI_GPIO_INTSTATUS
#define ARCHI_GPIO_EN        0x1C

#define ARCHI_GPIO_PADCFG0   0x20
#define ARCHI_GPIO_PADCFG1   0x24
#define ARCHI_GPIO_PADCFG2   0x28
#define ARCHI_GPIO_PADCFG3   0x2C
#define ARCHI_GPIO_PADCFG4   0x30
#define ARCHI_GPIO_PADCFG5   0x34
#define ARCHI_GPIO_PADCFG6   0x38
#define ARCHI_GPIO_PADCFG7   0x3C


#define ARCHI_GPIO_PADDIR_IN  0
#define ARCHI_GPIO_PADDIR_OUT 1

#define ARCHI_GPIO_INTTYPE_RISE          1
#define ARCHI_GPIO_INTTYPE_FALL          0
#define ARCHI_GPIO_INTTYPE_RISE_AND_FALL 2

#define ARCHI_GPIO_INTTYPE(id)           (ARCHI_GPIO_INTTYPE0 + (id)*4)
#define ARCHI_GPIO_INTTYPE_NO(gpio)      ((gpio) >> 4)
#define ARCHI_GPIO_INTTYPE_GPIO(inttype) ((inttype)*16)
#define ARCHI_GPIO_INTTYPE_SIZE          2
#define ARCHI_GPIO_INTTYPE_BIT(pad)      (((pad) & 0xF) << 1)
#define ARCHI_GPIO_INTTYPE_GET(gpio,value) (((value) >> ARCHI_GPIO_INTTYPE_BIT(gpio)) & ((1<<ARCHI_GPIO_INTTYPE_SIZE) - 1))

#define ARCHI_GPIO_PADCFG_PIN_WIDTH  8

#define ARCHI_GPIO_PADCFG_PULL_BIT   0
#define ARCHI_GPIO_PADCFG_PULL_WIDTH 1

#define ARCHI_GPIO_PADCFG_STRENGTH_BIT   1
#define ARCHI_GPIO_PADCFG_STRENGTH_WIDTH 1

#define ARCHI_GPIO_PADCFG(id)           (ARCHI_GPIO_PADCFG0 + (id)*4)
#define ARCHI_GPIO_PADCFG_REG(gpio)      ((gpio) >> 2)
#define ARCHI_GPIO_PADCFG_GROUP(gpio)    ((gpio) & ((1<<2)-1))


#ifndef LANGUAGE_ASSEMBLY

typedef struct {
  int pull:1;
  int strength:1;
  int reserved:6;
} __attribute__((packed)) gpio_padcfg_group_t;

typedef union {
  gpio_padcfg_group_t  pin[4];
  uint32_t raw;
} __attribute__((packed)) gpio_reg_padcfg_t;

#endif

#endif
