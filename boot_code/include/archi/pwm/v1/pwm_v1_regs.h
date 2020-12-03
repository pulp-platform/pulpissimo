
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

#ifndef __INCLUDE_ARCHI_PWM_V1_PWM_V1_REGS_H__
#define __INCLUDE_ARCHI_PWM_V1_PWM_V1_REGS_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS
//

// ADV_TIMER0 command register.
#define PWM_T0_CMD_OFFSET                        0x0

// ADV_TIMER0 configuration register.
#define PWM_T0_CONFIG_OFFSET                     0x4

// ADV_TIMER0 threshold configuration register.
#define PWM_T0_THRESHOLD_OFFSET                  0x8

// ADV_TIMER0 channel 0 threshold configuration register.
#define PWM_T0_TH_CHANNEL0_OFFSET                0xc

// ADV_TIMER0 channel 1 threshold configuration register.
#define PWM_T0_TH_CHANNEL1_OFFSET                0x10

// ADV_TIMER0 channel 2 threshold configuration register.
#define PWM_T0_TH_CHANNEL2_OFFSET                0x14

// ADV_TIMER0 channel 3 threshold configuration register.
#define PWM_T0_TH_CHANNEL3_OFFSET                0x18

// ADV_TIMER0 counter register.
#define PWM_T0_COUNTER_OFFSET                    0x2c

// ADV_TIMER1 command register.
#define PWM_T1_CMD_OFFSET                        0x40

// ADV_TIMER1 configuration register.
#define PWM_T1_CONFIG_OFFSET                     0x44

// ADV_TIMER1 threshold configuration register.
#define PWM_T1_THRESHOLD_OFFSET                  0x48

// ADV_TIMER1 channel 0 threshold configuration register.
#define PWM_T1_TH_CHANNEL0_OFFSET                0x4c

// ADV_TIMER1 channel 1 threshold configuration register.
#define PWM_T1_TH_CHANNEL1_OFFSET                0x50

// ADV_TIMER1 channel 2 threshold configuration register.
#define PWM_T1_TH_CHANNEL2_OFFSET                0x54

// ADV_TIMER1 channel 3 threshold configuration register.
#define PWM_T1_TH_CHANNEL3_OFFSET                0x58

// ADV_TIMER1 counter register.
#define PWM_T1_COUNTER_OFFSET                    0x6c

// ADV_TIMER2 command register.
#define PWM_T2_CMD_OFFSET                        0x80

// ADV_TIMER2 configuration register.
#define PWM_T2_CONFIG_OFFSET                     0x84

// ADV_TIMER2 threshold configuration register.
#define PWM_T2_THRESHOLD_OFFSET                  0x88

// ADV_TIMER2 channel 0 threshold configuration register.
#define PWM_T2_TH_CHANNEL0_OFFSET                0x8c

// ADV_TIMER2 channel 1 threshold configuration register.
#define PWM_T2_TH_CHANNEL1_OFFSET                0x90

// ADV_TIMER2 channel 2 threshold configuration register.
#define PWM_T2_TH_CHANNEL2_OFFSET                0x94

// ADV_TIMER2 channel 3 threshold configuration register.
#define PWM_T2_TH_CHANNEL3_OFFSET                0x98

// ADV_TIMER2 counter register.
#define PWM_T2_COUNTER_OFFSET                    0xac

// ADV_TIMER3 command register.
#define PWM_T3_CMD_OFFSET                        0xc0

// ADV_TIMER3 configuration register.
#define PWM_T3_CONFIG_OFFSET                     0xc4

// ADV_TIMER3 threshold configuration register.
#define PWM_T3_THRESHOLD_OFFSET                  0xc8

// ADV_TIMER3 channel 0 threshold configuration register.
#define PWM_T3_TH_CHANNEL0_OFFSET                0xcc

// ADV_TIMER3 channel 1 threshold configuration register.
#define PWM_T3_TH_CHANNEL1_OFFSET                0xd0

// ADV_TIMER3 channel 2 threshold configuration register.
#define PWM_T3_TH_CHANNEL2_OFFSET                0xd4

// ADV_TIMER3 channel 3 threshold configuration register.
#define PWM_T3_TH_CHANNEL3_OFFSET                0xd8

// ADV_TIMER3 counter register.
#define PWM_T3_COUNTER_OFFSET                    0xec

// ADV_TIMERS events configuration register.
#define PWM_EVENT_CFG_OFFSET                     0x100

// ADV_TIMERS channels clock gating configuration register.
#define PWM_CG_OFFSET                            0x104

#endif
