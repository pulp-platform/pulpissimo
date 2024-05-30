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


#ifndef __ARCHI_SOC_EU_SOC_EU_V3_H__
#define __ARCHI_SOC_EU_SOC_EU_V3_H__


#define SOC_EU_EVENT                0x00
#define SOC_FC_FIRST_MASK           0x10
#define SOC_CL_FIRST_MASK           0x20
#define SOC_PR_FIRST_MASK           0x30
#define SOC_ERR_FIRST_MASK          0x40
#define SOC_TIMER_SEL_HI            0x08
#define SOC_TIMER_SEL_LO            0x0C

// compatibility definitions
#define SOC_FC_MASK_LSB             SOC_FC_FIRST_MASK
#define SOC_FC_MASK_MSB             (SOC_FC_FIRST_MASK + 0x4)
#define SOC_CL_MASK_LSB             SOC_CL_FIRST_MASK
#define SOC_CL_MASK_MSB             (SOC_CL_FIRST_MASK + 0x4)
#define SOC_PR_MASK_LSB             SOC_PR_FIRST_MASK
#define SOC_PR_MASK_MSB             (SOC_PR_FIRST_MASK + 0x4)

#define SOC_EU_EVENT_0              0x1
#define SOC_EU_EVENT_1              0x2
#define SOC_EU_EVENT_2              0x4
#define SOC_EU_EVENT_3              0x8
#define SOC_EU_EVENT_4              0x10
#define SOC_EU_EVENT_5              0x20
#define SOC_EU_EVENT_6              0x40
#define SOC_EU_EVENT_7              0x80

#define SOC_TIMER_SEL_ENABLE_SHIFT  31
#define SOC_TIMER_SEL_EVT_SHIFT     0
#define SOC_TIMER_SEL_EVT_WIDTH     8
#define SOC_TIMER_SEL_EVT_MASK      ((~0U) >> (32 - SOC_TIMER_SEL_EVT_WIDTH))
// #define SOC_TIMER_SEL_EVT_MASK    0xff

#define SOC_TIMER_SEL_ENABLE_DISABLED   0
#define SOC_TIMER_SEL_ENABLE_ENABLED    1

#define SOC_TIMER_SEL_ENABLE_DIS        (0   << SOC_TIMER_SEL_ENABLE_SHIFT)
#define SOC_TIMER_SEL_ENABLE_ENA        (1   << SOC_TIMER_SEL_ENABLE_SHIFT)
#define SOC_TIMER_SEL_EVT_VAL(val)      ((val) << SOC_TIMER_SEL_EVT_SHIFT)

// related to XX_FIRST_MASK registers
#define SOC_NB_EVENT_REGS       4
#define SOC_NB_EVENT_TARGETS    3

#define SOC_FC_MASK(x)          (SOC_FC_FIRST_MASK + (x)*4)
#define SOC_CL_MASK(x)          (SOC_CL_FIRST_MASK + (x)*4)
#define SOC_PR_MASK(x)          (SOC_PR_FIRST_MASK + (x)*4)

#define ARCHI_SOC_EVENT_PERIPH_EVT_BASE(periph) ((periph)*ARCHI_SOC_EVENT_UDMA_NB_CHANNEL_EVT)

#endif