/*
 * Copyright (C) 2018 ETH Zurich, University of Bologna and
 * GreenWaves Technologies
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

#ifndef __ARCHI_PWM_PWM_V1_H__
#define __ARCHI_PWM_PWM_V1_H__

#include "archi/pulp.h"

#define PWM_TIMER_TO_TIMER_OFFSET	    0x40

#define	PWM_TIMER_CMD_OFFSET	    	0x00
#define	PWM_TIMER_CONFIG_OFFSET		    0x04
#define	PWM_TIMER_THRESHOLD_OFFSET	    0x08
#define	PWM_TIMER_TH_CHANNEL_OFFSET	    0x0C
#define	PWM_TIMER_LUT_CHANNEL_OFFSET	0x1C
#define PWM_TIMER_COUNTER_OFFSET        0x2C

#define PWM_CHANNEL_TO_CHANNEL_OFFSET	0x04

/* Timer Base:	PWM_BASE_ADDR + Timer*PWM_TIMER_TO_TIMER_OFFSET
	Config:		+ PWM_TIMER_CONFIG_OFFSET
	Threhsold:	+ PWM_TIMER_THRESHOLD_OFFSET
	Channel Thresh:	+ PWM_TIMER_TH_CHANNEL_OFFSET + Channel*PWM_CHANNEL_TO_CHANNEL_OFFSET
	Channel LUT:	+ PWM_TIMER_LUT_CHANNEL_OFFSET + Channel*PWM_CHANNEL_TO_CHANNEL_OFFSET
*/
#define PWM_TIMER_BASE_ADDR(timer)                      (ARCHI_PWM_ADDR + timer*PWM_TIMER_TO_TIMER_OFFSET)
#define PWM_TIMER_CMD_ADDR(timer)                       (PWM_TIMER_BASE_ADDR(timer) + PWM_TIMER_CMD_OFFSET)
#define PWM_TIMER_CONFIG_ADDR(timer)                    (PWM_TIMER_BASE_ADDR(timer) + PWM_TIMER_CONFIG_OFFSET)
#define PWM_TIMER_THRESHOLD_ADDR(timer)                 (PWM_TIMER_BASE_ADDR(timer) + PWM_TIMER_THRESHOLD_OFFSET)
#define PWM_TIMER_TH_CHANNEL_ADDR(timer, channel)       (PWM_TIMER_BASE_ADDR(timer) + PWM_TIMER_TH_CHANNEL_OFFSET + (channel*PWM_CHANNEL_TO_CHANNEL_OFFSET))
#define PWM_TIMER_LUT_CHANNEL_ADDR(timer, channel)      (PWM_TIMER_BASE_ADDR(timer) + PWM_TIMER_LUT_CHANNEL_OFFSET + (channel*PWM_CHANNEL_TO_CHANNEL_OFFSET))
#define PWM_TIMER_COUNTER_ADDR(timer)                   (PWM_TIMER_BASE_ADDR(timer) + PWM_TIMER_COUNTER_OFFSET)

#define REG_EVENT_CFG                                   (ARCHI_PWM_ADDR + 0x100)
#define REG_PWM_TIMER_EN                                (ARCHI_PWM_ADDR + 0X104)

#define PWM_TIMER_EN(timer)                             (0x1<<timer)
#define PWM_TIMER_EN_ALL                                (0xF)
#define PWM_TIMER_DISABLE(timer)                        ((~PWM_TIMER_EN(timer))&0xF)
#define PWM_TIMER_DISABLE_ALL                           (0x0)


#define ADV_TIMER_INMODE_AO       0x0 //event at each clock cycle
#define ADV_TIMER_INMODE_IN0      0x1 //event if input signal is 0
#define ADV_TIMER_INMODE_IN1      0x2 //event if input signal is 1
#define ADV_TIMER_INMODE_RISE     0x3 //event on input signal rising edge
#define ADV_TIMER_INMODE_FALL     0x4 //event on input signal falling edge
#define ADV_TIMER_INMODE_EDGE     0x5 //event on input signal rising or falling edge
#define ADV_TIMER_INMODE_ARM_RISE 0x6 //event on input signal rising edge when armed
#define ADV_TIMER_INMODE_ARM_FALL 0x7 //event on input signal falling edge when armed

#define ADV_TIMER_SAW             0x1
#define ADV_TIMER_NOSAW           0x0

#define ADV_TIMER_USEREF          0x1
#define ADV_TIMER_USESIG          0x0

#define ALL_CHANNEL               0x1
#define THIS_CHANNEL_ONLY         0x0

// When channel counter reaches threshold:
#define ADV_TIMER_OP_SET    0       //   	000: Set
#define ADV_TIMER_OP_TOGRST 1       //   	001: Toggle then next is Clear
#define ADV_TIMER_OP_SETRST 2       //   	010: Set then Clear
#define ADV_TIMER_OP_TOG    3       //   	011: Toggle
#define ADV_TIMER_OP_RST    4       //   	100: Clear
#define ADV_TIMER_OP_TOGSET 5       //   	101: Toggle then next is Set
#define ADV_TIMER_OP_RSTSET 6       //   	110: Clear then Set

#endif
