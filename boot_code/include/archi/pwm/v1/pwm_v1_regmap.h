
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

#ifndef __INCLUDE_ARCHI_PWM_V1_PWM_V1_REGMAP_H__
#define __INCLUDE_ARCHI_PWM_V1_PWM_V1_REGMAP_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS GLOBAL STRUCT
//

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

typedef struct {
  unsigned int t0_cmd          ; // ADV_TIMER0 command register.
  unsigned int t0_config       ; // ADV_TIMER0 configuration register.
  unsigned int t0_threshold    ; // ADV_TIMER0 threshold configuration register.
  unsigned int t0_th_channel0  ; // ADV_TIMER0 channel 0 threshold configuration register.
  unsigned int t0_th_channel1  ; // ADV_TIMER0 channel 1 threshold configuration register.
  unsigned int t0_th_channel2  ; // ADV_TIMER0 channel 2 threshold configuration register.
  unsigned int t0_th_channel3  ; // ADV_TIMER0 channel 3 threshold configuration register.
  unsigned int t0_counter      ; // ADV_TIMER0 counter register.
  unsigned int t1_cmd          ; // ADV_TIMER1 command register.
  unsigned int t1_config       ; // ADV_TIMER1 configuration register.
  unsigned int t1_threshold    ; // ADV_TIMER1 threshold configuration register.
  unsigned int t1_th_channel0  ; // ADV_TIMER1 channel 0 threshold configuration register.
  unsigned int t1_th_channel1  ; // ADV_TIMER1 channel 1 threshold configuration register.
  unsigned int t1_th_channel2  ; // ADV_TIMER1 channel 2 threshold configuration register.
  unsigned int t1_th_channel3  ; // ADV_TIMER1 channel 3 threshold configuration register.
  unsigned int t1_counter      ; // ADV_TIMER1 counter register.
  unsigned int t2_cmd          ; // ADV_TIMER2 command register.
  unsigned int t2_config       ; // ADV_TIMER2 configuration register.
  unsigned int t2_threshold    ; // ADV_TIMER2 threshold configuration register.
  unsigned int t2_th_channel0  ; // ADV_TIMER2 channel 0 threshold configuration register.
  unsigned int t2_th_channel1  ; // ADV_TIMER2 channel 1 threshold configuration register.
  unsigned int t2_th_channel2  ; // ADV_TIMER2 channel 2 threshold configuration register.
  unsigned int t2_th_channel3  ; // ADV_TIMER2 channel 3 threshold configuration register.
  unsigned int t2_counter      ; // ADV_TIMER2 counter register.
  unsigned int t3_cmd          ; // ADV_TIMER3 command register.
  unsigned int t3_config       ; // ADV_TIMER3 configuration register.
  unsigned int t3_threshold    ; // ADV_TIMER3 threshold configuration register.
  unsigned int t3_th_channel0  ; // ADV_TIMER3 channel 0 threshold configuration register.
  unsigned int t3_th_channel1  ; // ADV_TIMER3 channel 1 threshold configuration register.
  unsigned int t3_th_channel2  ; // ADV_TIMER3 channel 2 threshold configuration register.
  unsigned int t3_th_channel3  ; // ADV_TIMER3 channel 3 threshold configuration register.
  unsigned int t3_counter      ; // ADV_TIMER3 counter register.
  unsigned int event_cfg       ; // ADV_TIMERS events configuration register.
  unsigned int cg              ; // ADV_TIMERS channels clock gating configuration register.
} __attribute__((packed)) pwm_pwm_t;

#endif

#endif
