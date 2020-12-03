
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

#ifndef __INCLUDE_ARCHI_PWM_V1_PWM_V1_STRUCTS_H__
#define __INCLUDE_ARCHI_PWM_V1_PWM_V1_STRUCTS_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS STRUCTS
//

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

typedef union {
  struct {
    unsigned int start           :1 ; // ADV_TIMER0 start command bitfield.
    unsigned int stop            :1 ; // ADV_TIMER0 stop command bitfield.
    unsigned int update          :1 ; // ADV_TIMER0 update command bitfield.
    unsigned int reset           :1 ; // ADV_TIMER0 reset command bitfield.
    unsigned int arm             :1 ; // ADV_TIMER0 arm command bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t0_cmd_t;

typedef union {
  struct {
    unsigned int insel           :8 ; // ADV_TIMER0 input source configuration bitfield: - 0-31: GPIO[0] to GPIO[31] - 32-35: Channel 0 to 3 of ADV_TIMER0 - 36-39: Channel 0 to 3 of ADV_TIMER1 - 40-43: Channel 0 to 3 of ADV_TIMER2 - 44-47: Channel 0 to 3 of ADV_TIMER3
    unsigned int mode            :3 ; // ADV_TIMER0 trigger mode configuration bitfield: - 3'h0: trigger event at each clock cycle. - 3'h1: trigger event if input source is 0 - 3'h2: trigger event if input source is 1 - 3'h3: trigger event on input source rising edge - 3'h4: trigger event on input source falling edge - 3'h5: trigger event on input source falling or rising edge - 3'h6: trigger event on input source rising edge when armed - 3'h7: trigger event on input source falling edge when armed
    unsigned int clksel          :1 ; // ADV_TIMER0 clock source configuration bitfield: - 1'b0: FLL - 1'b1: reference clock at 32kHz
    unsigned int updownsel       :1 ; // ADV_TIMER0 center-aligned mode configuration bitfield: - 1'b0: The counter counts up and down alternatively. - 1'b1: The counter counts up and resets to 0 when reach threshold.
    unsigned int padding0:3 ;
    unsigned int presc           :8 ; // ADV_TIMER0 prescaler value configuration bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t0_config_t;

typedef union {
  struct {
    unsigned int th_lo           :16; // ADV_TIMER0 threshold low part configuration bitfield. It defines start counter value.
    unsigned int th_hi           :16; // ADV_TIMER0 threshold high part configuration bitfield. It defines end counter value.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t0_threshold_t;

typedef union {
  struct {
    unsigned int th              :16; // ADV_TIMER0 channel 0 threshold configuration bitfield.
    unsigned int mode            :3 ; // ADV_TIMER0 channel 0 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t0_th_channel0_t;

typedef union {
  struct {
    unsigned int th              :16; // ADV_TIMER0 channel 1 threshold configuration bitfield.
    unsigned int mode            :3 ; // ADV_TIMER0 channel 1 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t0_th_channel1_t;

typedef union {
  struct {
    unsigned int th              :16; // ADV_TIMER0 channel 2 threshold configuration bitfield.
    unsigned int mode            :3 ; // ADV_TIMER0 channel 2 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t0_th_channel2_t;

typedef union {
  struct {
    unsigned int th              :16; // ADV_TIMER0 channel 3 threshold configuration bitfield.
    unsigned int mode            :3 ; // ADV_TIMER0 channel 3 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t0_th_channel3_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t0_counter_t;

typedef union {
  struct {
    unsigned int start           :1 ; // ADV_TIMER1 start command bitfield.
    unsigned int stop            :1 ; // ADV_TIMER1 stop command bitfield.
    unsigned int update          :1 ; // ADV_TIMER1 update command bitfield.
    unsigned int reset           :1 ; // ADV_TIMER1 reset command bitfield.
    unsigned int arm             :1 ; // ADV_TIMER1 arm command bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t1_cmd_t;

typedef union {
  struct {
    unsigned int insel           :8 ; // ADV_TIMER1 input source configuration bitfield: - 0-31: GPIO[0] to GPIO[31] - 32-35: Channel 0 to 3 of ADV_TIMER0 - 36-39: Channel 0 to 3 of ADV_TIMER1 - 40-43: Channel 0 to 3 of ADV_TIMER2 - 44-47: Channel 0 to 3 of ADV_TIMER3
    unsigned int mode            :3 ; // ADV_TIMER1 trigger mode configuration bitfield: - 3'h0: trigger event at each clock cycle. - 3'h1: trigger event if input source is 0 - 3'h2: trigger event if input source is 1 - 3'h3: trigger event on input source rising edge - 3'h4: trigger event on input source falling edge - 3'h5: trigger event on input source falling or rising edge - 3'h6: trigger event on input source rising edge when armed - 3'h7: trigger event on input source falling edge when armed
    unsigned int clksel          :1 ; // ADV_TIMER1 clock source configuration bitfield: - 1'b0: FLL - 1'b1: reference clock at 32kHz
    unsigned int updownsel       :1 ; // ADV_TIMER1 center-aligned mode configuration bitfield: - 1'b0: The counter counts up and down alternatively. - 1'b1: The counter counts up and resets to 0 when reach threshold.
    unsigned int padding0:3 ;
    unsigned int presc           :8 ; // ADV_TIMER1 prescaler value configuration bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t1_config_t;

typedef union {
  struct {
    unsigned int th_lo           :16; // ADV_TIMER1 threshold low part configuration bitfield. It defines start counter value.
    unsigned int th_hi           :16; // ADV_TIMER1 threshold high part configuration bitfield. It defines end counter value.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t1_threshold_t;

typedef union {
  struct {
    unsigned int th              :16; // ADV_TIMER1 channel 0 threshold configuration bitfield.
    unsigned int mode            :3 ; // ADV_TIMER1 channel 0 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t1_th_channel0_t;

typedef union {
  struct {
    unsigned int th              :16; // ADV_TIMER1 channel 1 threshold configuration bitfield.
    unsigned int mode            :3 ; // ADV_TIMER1 channel 1 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t1_th_channel1_t;

typedef union {
  struct {
    unsigned int th              :16; // ADV_TIMER1 channel 2 threshold configuration bitfield.
    unsigned int mode            :3 ; // ADV_TIMER1 channel 2 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t1_th_channel2_t;

typedef union {
  struct {
    unsigned int th              :16; // ADV_TIMER1 channel 3 threshold configuration bitfield.
    unsigned int mode            :3 ; // ADV_TIMER1 channel 3 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t1_th_channel3_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t1_counter_t;

typedef union {
  struct {
    unsigned int start           :1 ; // ADV_TIMER2 start command bitfield.
    unsigned int stop            :1 ; // ADV_TIMER2 stop command bitfield.
    unsigned int update          :1 ; // ADV_TIMER2 update command bitfield.
    unsigned int reset           :1 ; // ADV_TIMER2 reset command bitfield.
    unsigned int arm             :1 ; // ADV_TIMER2 arm command bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t2_cmd_t;

typedef union {
  struct {
    unsigned int insel           :8 ; // ADV_TIMER2 input source configuration bitfield: - 0-31: GPIO[0] to GPIO[31] - 32-35: Channel 0 to 3 of ADV_TIMER0 - 36-39: Channel 0 to 3 of ADV_TIMER1 - 40-43: Channel 0 to 3 of ADV_TIMER2 - 44-47: Channel 0 to 3 of ADV_TIMER3
    unsigned int mode            :3 ; // ADV_TIMER2 trigger mode configuration bitfield: - 3'h0: trigger event at each clock cycle. - 3'h1: trigger event if input source is 0 - 3'h2: trigger event if input source is 1 - 3'h3: trigger event on input source rising edge - 3'h4: trigger event on input source falling edge - 3'h5: trigger event on input source falling or rising edge - 3'h6: trigger event on input source rising edge when armed - 3'h7: trigger event on input source falling edge when armed
    unsigned int clksel          :1 ; // ADV_TIMER2 clock source configuration bitfield: - 1'b0: FLL - 1'b1: reference clock at 32kHz
    unsigned int updownsel       :1 ; // ADV_TIMER2 center-aligned mode configuration bitfield: - 1'b0: The counter counts up and down alternatively. - 1'b1: The counter counts up and resets to 0 when reach threshold.
    unsigned int padding0:3 ;
    unsigned int presc           :8 ; // ADV_TIMER2 prescaler value configuration bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t2_config_t;

typedef union {
  struct {
    unsigned int th_lo           :16; // ADV_TIMER2 threshold low part configuration bitfield. It defines start counter value.
    unsigned int th_hi           :16; // ADV_TIMER2 threshold high part configuration bitfield. It defines end counter value.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t2_threshold_t;

typedef union {
  struct {
    unsigned int th              :16; // ADV_TIMER2 channel 0 threshold configuration bitfield.
    unsigned int mode            :3 ; // ADV_TIMER2 channel 0 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t2_th_channel0_t;

typedef union {
  struct {
    unsigned int th              :16; // ADV_TIMER2 channel 1 threshold configuration bitfield.
    unsigned int mode            :3 ; // ADV_TIMER2 channel 1 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t2_th_channel1_t;

typedef union {
  struct {
    unsigned int th              :16; // ADV_TIMER2 channel 2 threshold configuration bitfield.
    unsigned int mode            :3 ; // ADV_TIMER2 channel 2 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t2_th_channel2_t;

typedef union {
  struct {
    unsigned int th              :16; // ADV_TIMER2 channel 3 threshold configuration bitfield.
    unsigned int mode            :3 ; // ADV_TIMER2 channel 3 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t2_th_channel3_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t2_counter_t;

typedef union {
  struct {
    unsigned int start           :1 ; // ADV_TIMER3 start command bitfield.
    unsigned int stop            :1 ; // ADV_TIMER3 stop command bitfield.
    unsigned int update          :1 ; // ADV_TIMER3 update command bitfield.
    unsigned int reset           :1 ; // ADV_TIMER3 reset command bitfield.
    unsigned int arm             :1 ; // ADV_TIMER3 arm command bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t3_cmd_t;

typedef union {
  struct {
    unsigned int insel           :8 ; // ADV_TIMER3 input source configuration bitfield: - 0-31: GPIO[0] to GPIO[31] - 32-35: Channel 0 to 3 of ADV_TIMER0 - 36-39: Channel 0 to 3 of ADV_TIMER1 - 40-43: Channel 0 to 3 of ADV_TIMER2 - 44-47: Channel 0 to 3 of ADV_TIMER3
    unsigned int mode            :3 ; // ADV_TIMER3 trigger mode configuration bitfield: - 3'h0: trigger event at each clock cycle. - 3'h1: trigger event if input source is 0 - 3'h2: trigger event if input source is 1 - 3'h3: trigger event on input source rising edge - 3'h4: trigger event on input source falling edge - 3'h5: trigger event on input source falling or rising edge - 3'h6: trigger event on input source rising edge when armed - 3'h7: trigger event on input source falling edge when armed
    unsigned int clksel          :1 ; // ADV_TIMER3 clock source configuration bitfield: - 1'b0: FLL - 1'b1: reference clock at 32kHz
    unsigned int updownsel       :1 ; // ADV_TIMER3 center-aligned mode configuration bitfield: - 1'b0: The counter counts up and down alternatively. - 1'b1: The counter counts up and resets to 0 when reach threshold.
    unsigned int padding0:3 ;
    unsigned int presc           :8 ; // ADV_TIMER3 prescaler value configuration bitfield.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t3_config_t;

typedef union {
  struct {
    unsigned int th_lo           :16; // ADV_TIMER3 threshold low part configuration bitfield. It defines start counter value.
    unsigned int th_hi           :16; // ADV_TIMER3 threshold high part configuration bitfield. It defines end counter value.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t3_threshold_t;

typedef union {
  struct {
    unsigned int th              :16; // ADV_TIMER3 channel 0 threshold configuration bitfield.
    unsigned int mode            :3 ; // ADV_TIMER3 channel 0 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t3_th_channel0_t;

typedef union {
  struct {
    unsigned int th              :16; // ADV_TIMER3 channel 1 threshold configuration bitfield.
    unsigned int mode            :3 ; // ADV_TIMER3 channel 1 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t3_th_channel1_t;

typedef union {
  struct {
    unsigned int th              :16; // ADV_TIMER3 channel 2 threshold configuration bitfield.
    unsigned int mode            :3 ; // ADV_TIMER3 channel 2 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t3_th_channel2_t;

typedef union {
  struct {
    unsigned int th              :16; // ADV_TIMER3 channel 3 threshold configuration bitfield.
    unsigned int mode            :3 ; // ADV_TIMER3 channel 3 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t3_th_channel3_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) pwm_t3_counter_t;

typedef union {
  struct {
    unsigned int sel0            :4 ; // ADV_TIMER output event 0 source configuration bitfiled: - 4'h0: ADV_TIMER0 channel 0. - 4'h1: ADV_TIMER0 channel 1. - 4'h2: ADV_TIMER0 channel 2. - 4'h3: ADV_TIMER0 channel 3. - 4'h4: ADV_TIMER1 channel 0. - 4'h5: ADV_TIMER1 channel 1. - 4'h6: ADV_TIMER1 channel 2. - 4'h7: ADV_TIMER1 channel 3. - 4'h8: ADV_TIMER2 channel 0. - 4'h9: ADV_TIMER2 channel 1. - 4'hA: ADV_TIMER2 channel 2. - 4'hB: ADV_TIMER2 channel 3. - 4'hC: ADV_TIMER3 channel 0. - 4'hD: ADV_TIMER3 channel 1. - 4'hE: ADV_TIMER3 channel 2. - 4'hF: ADV_TIMER3 channel 3.
    unsigned int sel1            :4 ; // ADV_TIMER output event 1 source configuration bitfiled: - 4'h0: ADV_TIMER0 channel 0. - 4'h1: ADV_TIMER0 channel 1. - 4'h2: ADV_TIMER0 channel 2. - 4'h3: ADV_TIMER0 channel 3. - 4'h4: ADV_TIMER1 channel 0. - 4'h5: ADV_TIMER1 channel 1. - 4'h6: ADV_TIMER1 channel 2. - 4'h7: ADV_TIMER1 channel 3. - 4'h8: ADV_TIMER2 channel 0. - 4'h9: ADV_TIMER2 channel 1. - 4'hA: ADV_TIMER2 channel 2. - 4'hB: ADV_TIMER2 channel 3. - 4'hC: ADV_TIMER3 channel 0. - 4'hD: ADV_TIMER3 channel 1. - 4'hE: ADV_TIMER3 channel 2. - 4'hF: ADV_TIMER3 channel 3.
    unsigned int sel2            :4 ; // ADV_TIMER output event 2 source configuration bitfiled: - 4'h0: ADV_TIMER0 channel 0. - 4'h1: ADV_TIMER0 channel 1. - 4'h2: ADV_TIMER0 channel 2. - 4'h3: ADV_TIMER0 channel 3. - 4'h4: ADV_TIMER1 channel 0. - 4'h5: ADV_TIMER1 channel 1. - 4'h6: ADV_TIMER1 channel 2. - 4'h7: ADV_TIMER1 channel 3. - 4'h8: ADV_TIMER2 channel 0. - 4'h9: ADV_TIMER2 channel 1. - 4'hA: ADV_TIMER2 channel 2. - 4'hB: ADV_TIMER2 channel 3. - 4'hC: ADV_TIMER3 channel 0. - 4'hD: ADV_TIMER3 channel 1. - 4'hE: ADV_TIMER3 channel 2. - 4'hF: ADV_TIMER3 channel 3.
    unsigned int sel3            :4 ; // ADV_TIMER output event 3 source configuration bitfiled: - 4'h0: ADV_TIMER0 channel 0. - 4'h1: ADV_TIMER0 channel 1. - 4'h2: ADV_TIMER0 channel 2. - 4'h3: ADV_TIMER0 channel 3. - 4'h4: ADV_TIMER1 channel 0. - 4'h5: ADV_TIMER1 channel 1. - 4'h6: ADV_TIMER1 channel 2. - 4'h7: ADV_TIMER1 channel 3. - 4'h8: ADV_TIMER2 channel 0. - 4'h9: ADV_TIMER2 channel 1. - 4'hA: ADV_TIMER2 channel 2. - 4'hB: ADV_TIMER2 channel 3. - 4'hC: ADV_TIMER3 channel 0. - 4'hD: ADV_TIMER3 channel 1. - 4'hE: ADV_TIMER3 channel 2. - 4'hF: ADV_TIMER3 channel 3.
    unsigned int ena             :4 ; // ADV_TIMER output event enable configuration bitfield. ENA[i]=1 enables output event i generation.
  };
  unsigned int raw;
} __attribute__((packed)) pwm_event_cfg_t;

typedef union {
  struct {
    unsigned int ena             :16; // ADV_TIMER clock gating configuration bitfield.  - ENA[i]=0: clock gate ADV_TIMERi. - ENA[i]=1: enable ADV_TIMERi. 
  };
  unsigned int raw;
} __attribute__((packed)) pwm_cg_t;

#endif

#endif
