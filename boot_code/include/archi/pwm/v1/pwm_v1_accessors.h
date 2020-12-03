
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

#ifndef __INCLUDE_ARCHI_PWM_V1_PWM_V1_ACCESSORS_H__
#define __INCLUDE_ARCHI_PWM_V1_PWM_V1_ACCESSORS_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS ACCESS FUNCTIONS
//

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

static inline uint32_t pwm_t0_cmd_get(uint32_t base) { return ARCHI_READ(base, PWM_T0_CMD_OFFSET); }
static inline void pwm_t0_cmd_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T0_CMD_OFFSET, value); }

static inline uint32_t pwm_t0_config_get(uint32_t base) { return ARCHI_READ(base, PWM_T0_CONFIG_OFFSET); }
static inline void pwm_t0_config_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T0_CONFIG_OFFSET, value); }

static inline uint32_t pwm_t0_threshold_get(uint32_t base) { return ARCHI_READ(base, PWM_T0_THRESHOLD_OFFSET); }
static inline void pwm_t0_threshold_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T0_THRESHOLD_OFFSET, value); }

static inline uint32_t pwm_t0_th_channel0_get(uint32_t base) { return ARCHI_READ(base, PWM_T0_TH_CHANNEL0_OFFSET); }
static inline void pwm_t0_th_channel0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T0_TH_CHANNEL0_OFFSET, value); }

static inline uint32_t pwm_t0_th_channel1_get(uint32_t base) { return ARCHI_READ(base, PWM_T0_TH_CHANNEL1_OFFSET); }
static inline void pwm_t0_th_channel1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T0_TH_CHANNEL1_OFFSET, value); }

static inline uint32_t pwm_t0_th_channel2_get(uint32_t base) { return ARCHI_READ(base, PWM_T0_TH_CHANNEL2_OFFSET); }
static inline void pwm_t0_th_channel2_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T0_TH_CHANNEL2_OFFSET, value); }

static inline uint32_t pwm_t0_th_channel3_get(uint32_t base) { return ARCHI_READ(base, PWM_T0_TH_CHANNEL3_OFFSET); }
static inline void pwm_t0_th_channel3_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T0_TH_CHANNEL3_OFFSET, value); }

static inline uint32_t pwm_t0_counter_get(uint32_t base) { return ARCHI_READ(base, PWM_T0_COUNTER_OFFSET); }
static inline void pwm_t0_counter_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T0_COUNTER_OFFSET, value); }

static inline uint32_t pwm_t1_cmd_get(uint32_t base) { return ARCHI_READ(base, PWM_T1_CMD_OFFSET); }
static inline void pwm_t1_cmd_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T1_CMD_OFFSET, value); }

static inline uint32_t pwm_t1_config_get(uint32_t base) { return ARCHI_READ(base, PWM_T1_CONFIG_OFFSET); }
static inline void pwm_t1_config_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T1_CONFIG_OFFSET, value); }

static inline uint32_t pwm_t1_threshold_get(uint32_t base) { return ARCHI_READ(base, PWM_T1_THRESHOLD_OFFSET); }
static inline void pwm_t1_threshold_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T1_THRESHOLD_OFFSET, value); }

static inline uint32_t pwm_t1_th_channel0_get(uint32_t base) { return ARCHI_READ(base, PWM_T1_TH_CHANNEL0_OFFSET); }
static inline void pwm_t1_th_channel0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T1_TH_CHANNEL0_OFFSET, value); }

static inline uint32_t pwm_t1_th_channel1_get(uint32_t base) { return ARCHI_READ(base, PWM_T1_TH_CHANNEL1_OFFSET); }
static inline void pwm_t1_th_channel1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T1_TH_CHANNEL1_OFFSET, value); }

static inline uint32_t pwm_t1_th_channel2_get(uint32_t base) { return ARCHI_READ(base, PWM_T1_TH_CHANNEL2_OFFSET); }
static inline void pwm_t1_th_channel2_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T1_TH_CHANNEL2_OFFSET, value); }

static inline uint32_t pwm_t1_th_channel3_get(uint32_t base) { return ARCHI_READ(base, PWM_T1_TH_CHANNEL3_OFFSET); }
static inline void pwm_t1_th_channel3_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T1_TH_CHANNEL3_OFFSET, value); }

static inline uint32_t pwm_t1_counter_get(uint32_t base) { return ARCHI_READ(base, PWM_T1_COUNTER_OFFSET); }
static inline void pwm_t1_counter_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T1_COUNTER_OFFSET, value); }

static inline uint32_t pwm_t2_cmd_get(uint32_t base) { return ARCHI_READ(base, PWM_T2_CMD_OFFSET); }
static inline void pwm_t2_cmd_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T2_CMD_OFFSET, value); }

static inline uint32_t pwm_t2_config_get(uint32_t base) { return ARCHI_READ(base, PWM_T2_CONFIG_OFFSET); }
static inline void pwm_t2_config_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T2_CONFIG_OFFSET, value); }

static inline uint32_t pwm_t2_threshold_get(uint32_t base) { return ARCHI_READ(base, PWM_T2_THRESHOLD_OFFSET); }
static inline void pwm_t2_threshold_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T2_THRESHOLD_OFFSET, value); }

static inline uint32_t pwm_t2_th_channel0_get(uint32_t base) { return ARCHI_READ(base, PWM_T2_TH_CHANNEL0_OFFSET); }
static inline void pwm_t2_th_channel0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T2_TH_CHANNEL0_OFFSET, value); }

static inline uint32_t pwm_t2_th_channel1_get(uint32_t base) { return ARCHI_READ(base, PWM_T2_TH_CHANNEL1_OFFSET); }
static inline void pwm_t2_th_channel1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T2_TH_CHANNEL1_OFFSET, value); }

static inline uint32_t pwm_t2_th_channel2_get(uint32_t base) { return ARCHI_READ(base, PWM_T2_TH_CHANNEL2_OFFSET); }
static inline void pwm_t2_th_channel2_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T2_TH_CHANNEL2_OFFSET, value); }

static inline uint32_t pwm_t2_th_channel3_get(uint32_t base) { return ARCHI_READ(base, PWM_T2_TH_CHANNEL3_OFFSET); }
static inline void pwm_t2_th_channel3_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T2_TH_CHANNEL3_OFFSET, value); }

static inline uint32_t pwm_t2_counter_get(uint32_t base) { return ARCHI_READ(base, PWM_T2_COUNTER_OFFSET); }
static inline void pwm_t2_counter_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T2_COUNTER_OFFSET, value); }

static inline uint32_t pwm_t3_cmd_get(uint32_t base) { return ARCHI_READ(base, PWM_T3_CMD_OFFSET); }
static inline void pwm_t3_cmd_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T3_CMD_OFFSET, value); }

static inline uint32_t pwm_t3_config_get(uint32_t base) { return ARCHI_READ(base, PWM_T3_CONFIG_OFFSET); }
static inline void pwm_t3_config_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T3_CONFIG_OFFSET, value); }

static inline uint32_t pwm_t3_threshold_get(uint32_t base) { return ARCHI_READ(base, PWM_T3_THRESHOLD_OFFSET); }
static inline void pwm_t3_threshold_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T3_THRESHOLD_OFFSET, value); }

static inline uint32_t pwm_t3_th_channel0_get(uint32_t base) { return ARCHI_READ(base, PWM_T3_TH_CHANNEL0_OFFSET); }
static inline void pwm_t3_th_channel0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T3_TH_CHANNEL0_OFFSET, value); }

static inline uint32_t pwm_t3_th_channel1_get(uint32_t base) { return ARCHI_READ(base, PWM_T3_TH_CHANNEL1_OFFSET); }
static inline void pwm_t3_th_channel1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T3_TH_CHANNEL1_OFFSET, value); }

static inline uint32_t pwm_t3_th_channel2_get(uint32_t base) { return ARCHI_READ(base, PWM_T3_TH_CHANNEL2_OFFSET); }
static inline void pwm_t3_th_channel2_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T3_TH_CHANNEL2_OFFSET, value); }

static inline uint32_t pwm_t3_th_channel3_get(uint32_t base) { return ARCHI_READ(base, PWM_T3_TH_CHANNEL3_OFFSET); }
static inline void pwm_t3_th_channel3_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T3_TH_CHANNEL3_OFFSET, value); }

static inline uint32_t pwm_t3_counter_get(uint32_t base) { return ARCHI_READ(base, PWM_T3_COUNTER_OFFSET); }
static inline void pwm_t3_counter_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_T3_COUNTER_OFFSET, value); }

static inline uint32_t pwm_event_cfg_get(uint32_t base) { return ARCHI_READ(base, PWM_EVENT_CFG_OFFSET); }
static inline void pwm_event_cfg_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_EVENT_CFG_OFFSET, value); }

static inline uint32_t pwm_cg_get(uint32_t base) { return ARCHI_READ(base, PWM_CG_OFFSET); }
static inline void pwm_cg_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, PWM_CG_OFFSET, value); }

#endif

#endif
