
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

#ifndef __INCLUDE_ARCHI_PWM_V1_PWM_V1_GVSOC_H__
#define __INCLUDE_ARCHI_PWM_V1_PWM_V1_GVSOC_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS STRUCTS
//

#ifdef __GVSOC__

class vp_pwm_t0_cmd : public vp::reg_32
{
public:
  inline void start_set(uint32_t value) { this->set_field(value, PWM_T0_CMD_START_BIT, PWM_T0_CMD_START_WIDTH); }
  inline uint32_t start_get() { return this->get_field(PWM_T0_CMD_START_BIT, PWM_T0_CMD_START_WIDTH); }
  inline void stop_set(uint32_t value) { this->set_field(value, PWM_T0_CMD_STOP_BIT, PWM_T0_CMD_STOP_WIDTH); }
  inline uint32_t stop_get() { return this->get_field(PWM_T0_CMD_STOP_BIT, PWM_T0_CMD_STOP_WIDTH); }
  inline void update_set(uint32_t value) { this->set_field(value, PWM_T0_CMD_UPDATE_BIT, PWM_T0_CMD_UPDATE_WIDTH); }
  inline uint32_t update_get() { return this->get_field(PWM_T0_CMD_UPDATE_BIT, PWM_T0_CMD_UPDATE_WIDTH); }
  inline void reset_set(uint32_t value) { this->set_field(value, PWM_T0_CMD_RESET_BIT, PWM_T0_CMD_RESET_WIDTH); }
  inline uint32_t reset_get() { return this->get_field(PWM_T0_CMD_RESET_BIT, PWM_T0_CMD_RESET_WIDTH); }
  inline void arm_set(uint32_t value) { this->set_field(value, PWM_T0_CMD_ARM_BIT, PWM_T0_CMD_ARM_WIDTH); }
  inline uint32_t arm_get() { return this->get_field(PWM_T0_CMD_ARM_BIT, PWM_T0_CMD_ARM_WIDTH); }
};

class vp_pwm_t0_config : public vp::reg_32
{
public:
  inline void insel_set(uint32_t value) { this->set_field(value, PWM_T0_CONFIG_INSEL_BIT, PWM_T0_CONFIG_INSEL_WIDTH); }
  inline uint32_t insel_get() { return this->get_field(PWM_T0_CONFIG_INSEL_BIT, PWM_T0_CONFIG_INSEL_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T0_CONFIG_MODE_BIT, PWM_T0_CONFIG_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T0_CONFIG_MODE_BIT, PWM_T0_CONFIG_MODE_WIDTH); }
  inline void clksel_set(uint32_t value) { this->set_field(value, PWM_T0_CONFIG_CLKSEL_BIT, PWM_T0_CONFIG_CLKSEL_WIDTH); }
  inline uint32_t clksel_get() { return this->get_field(PWM_T0_CONFIG_CLKSEL_BIT, PWM_T0_CONFIG_CLKSEL_WIDTH); }
  inline void updownsel_set(uint32_t value) { this->set_field(value, PWM_T0_CONFIG_UPDOWNSEL_BIT, PWM_T0_CONFIG_UPDOWNSEL_WIDTH); }
  inline uint32_t updownsel_get() { return this->get_field(PWM_T0_CONFIG_UPDOWNSEL_BIT, PWM_T0_CONFIG_UPDOWNSEL_WIDTH); }
  inline void presc_set(uint32_t value) { this->set_field(value, PWM_T0_CONFIG_PRESC_BIT, PWM_T0_CONFIG_PRESC_WIDTH); }
  inline uint32_t presc_get() { return this->get_field(PWM_T0_CONFIG_PRESC_BIT, PWM_T0_CONFIG_PRESC_WIDTH); }
};

class vp_pwm_t0_threshold : public vp::reg_32
{
public:
  inline void th_lo_set(uint32_t value) { this->set_field(value, PWM_T0_THRESHOLD_TH_LO_BIT, PWM_T0_THRESHOLD_TH_LO_WIDTH); }
  inline uint32_t th_lo_get() { return this->get_field(PWM_T0_THRESHOLD_TH_LO_BIT, PWM_T0_THRESHOLD_TH_LO_WIDTH); }
  inline void th_hi_set(uint32_t value) { this->set_field(value, PWM_T0_THRESHOLD_TH_HI_BIT, PWM_T0_THRESHOLD_TH_HI_WIDTH); }
  inline uint32_t th_hi_get() { return this->get_field(PWM_T0_THRESHOLD_TH_HI_BIT, PWM_T0_THRESHOLD_TH_HI_WIDTH); }
};

class vp_pwm_t0_th_channel0 : public vp::reg_32
{
public:
  inline void th_set(uint32_t value) { this->set_field(value, PWM_T0_TH_CHANNEL0_TH_BIT, PWM_T0_TH_CHANNEL0_TH_WIDTH); }
  inline uint32_t th_get() { return this->get_field(PWM_T0_TH_CHANNEL0_TH_BIT, PWM_T0_TH_CHANNEL0_TH_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T0_TH_CHANNEL0_MODE_BIT, PWM_T0_TH_CHANNEL0_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T0_TH_CHANNEL0_MODE_BIT, PWM_T0_TH_CHANNEL0_MODE_WIDTH); }
};

class vp_pwm_t0_th_channel1 : public vp::reg_32
{
public:
  inline void th_set(uint32_t value) { this->set_field(value, PWM_T0_TH_CHANNEL1_TH_BIT, PWM_T0_TH_CHANNEL1_TH_WIDTH); }
  inline uint32_t th_get() { return this->get_field(PWM_T0_TH_CHANNEL1_TH_BIT, PWM_T0_TH_CHANNEL1_TH_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T0_TH_CHANNEL1_MODE_BIT, PWM_T0_TH_CHANNEL1_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T0_TH_CHANNEL1_MODE_BIT, PWM_T0_TH_CHANNEL1_MODE_WIDTH); }
};

class vp_pwm_t0_th_channel2 : public vp::reg_32
{
public:
  inline void th_set(uint32_t value) { this->set_field(value, PWM_T0_TH_CHANNEL2_TH_BIT, PWM_T0_TH_CHANNEL2_TH_WIDTH); }
  inline uint32_t th_get() { return this->get_field(PWM_T0_TH_CHANNEL2_TH_BIT, PWM_T0_TH_CHANNEL2_TH_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T0_TH_CHANNEL2_MODE_BIT, PWM_T0_TH_CHANNEL2_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T0_TH_CHANNEL2_MODE_BIT, PWM_T0_TH_CHANNEL2_MODE_WIDTH); }
};

class vp_pwm_t0_th_channel3 : public vp::reg_32
{
public:
  inline void th_set(uint32_t value) { this->set_field(value, PWM_T0_TH_CHANNEL3_TH_BIT, PWM_T0_TH_CHANNEL3_TH_WIDTH); }
  inline uint32_t th_get() { return this->get_field(PWM_T0_TH_CHANNEL3_TH_BIT, PWM_T0_TH_CHANNEL3_TH_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T0_TH_CHANNEL3_MODE_BIT, PWM_T0_TH_CHANNEL3_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T0_TH_CHANNEL3_MODE_BIT, PWM_T0_TH_CHANNEL3_MODE_WIDTH); }
};

class vp_pwm_t0_counter : public vp::reg_32
{
public:
};

class vp_pwm_t1_cmd : public vp::reg_32
{
public:
  inline void start_set(uint32_t value) { this->set_field(value, PWM_T1_CMD_START_BIT, PWM_T1_CMD_START_WIDTH); }
  inline uint32_t start_get() { return this->get_field(PWM_T1_CMD_START_BIT, PWM_T1_CMD_START_WIDTH); }
  inline void stop_set(uint32_t value) { this->set_field(value, PWM_T1_CMD_STOP_BIT, PWM_T1_CMD_STOP_WIDTH); }
  inline uint32_t stop_get() { return this->get_field(PWM_T1_CMD_STOP_BIT, PWM_T1_CMD_STOP_WIDTH); }
  inline void update_set(uint32_t value) { this->set_field(value, PWM_T1_CMD_UPDATE_BIT, PWM_T1_CMD_UPDATE_WIDTH); }
  inline uint32_t update_get() { return this->get_field(PWM_T1_CMD_UPDATE_BIT, PWM_T1_CMD_UPDATE_WIDTH); }
  inline void reset_set(uint32_t value) { this->set_field(value, PWM_T1_CMD_RESET_BIT, PWM_T1_CMD_RESET_WIDTH); }
  inline uint32_t reset_get() { return this->get_field(PWM_T1_CMD_RESET_BIT, PWM_T1_CMD_RESET_WIDTH); }
  inline void arm_set(uint32_t value) { this->set_field(value, PWM_T1_CMD_ARM_BIT, PWM_T1_CMD_ARM_WIDTH); }
  inline uint32_t arm_get() { return this->get_field(PWM_T1_CMD_ARM_BIT, PWM_T1_CMD_ARM_WIDTH); }
};

class vp_pwm_t1_config : public vp::reg_32
{
public:
  inline void insel_set(uint32_t value) { this->set_field(value, PWM_T1_CONFIG_INSEL_BIT, PWM_T1_CONFIG_INSEL_WIDTH); }
  inline uint32_t insel_get() { return this->get_field(PWM_T1_CONFIG_INSEL_BIT, PWM_T1_CONFIG_INSEL_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T1_CONFIG_MODE_BIT, PWM_T1_CONFIG_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T1_CONFIG_MODE_BIT, PWM_T1_CONFIG_MODE_WIDTH); }
  inline void clksel_set(uint32_t value) { this->set_field(value, PWM_T1_CONFIG_CLKSEL_BIT, PWM_T1_CONFIG_CLKSEL_WIDTH); }
  inline uint32_t clksel_get() { return this->get_field(PWM_T1_CONFIG_CLKSEL_BIT, PWM_T1_CONFIG_CLKSEL_WIDTH); }
  inline void updownsel_set(uint32_t value) { this->set_field(value, PWM_T1_CONFIG_UPDOWNSEL_BIT, PWM_T1_CONFIG_UPDOWNSEL_WIDTH); }
  inline uint32_t updownsel_get() { return this->get_field(PWM_T1_CONFIG_UPDOWNSEL_BIT, PWM_T1_CONFIG_UPDOWNSEL_WIDTH); }
  inline void presc_set(uint32_t value) { this->set_field(value, PWM_T1_CONFIG_PRESC_BIT, PWM_T1_CONFIG_PRESC_WIDTH); }
  inline uint32_t presc_get() { return this->get_field(PWM_T1_CONFIG_PRESC_BIT, PWM_T1_CONFIG_PRESC_WIDTH); }
};

class vp_pwm_t1_threshold : public vp::reg_32
{
public:
  inline void th_lo_set(uint32_t value) { this->set_field(value, PWM_T1_THRESHOLD_TH_LO_BIT, PWM_T1_THRESHOLD_TH_LO_WIDTH); }
  inline uint32_t th_lo_get() { return this->get_field(PWM_T1_THRESHOLD_TH_LO_BIT, PWM_T1_THRESHOLD_TH_LO_WIDTH); }
  inline void th_hi_set(uint32_t value) { this->set_field(value, PWM_T1_THRESHOLD_TH_HI_BIT, PWM_T1_THRESHOLD_TH_HI_WIDTH); }
  inline uint32_t th_hi_get() { return this->get_field(PWM_T1_THRESHOLD_TH_HI_BIT, PWM_T1_THRESHOLD_TH_HI_WIDTH); }
};

class vp_pwm_t1_th_channel0 : public vp::reg_32
{
public:
  inline void th_set(uint32_t value) { this->set_field(value, PWM_T1_TH_CHANNEL0_TH_BIT, PWM_T1_TH_CHANNEL0_TH_WIDTH); }
  inline uint32_t th_get() { return this->get_field(PWM_T1_TH_CHANNEL0_TH_BIT, PWM_T1_TH_CHANNEL0_TH_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T1_TH_CHANNEL0_MODE_BIT, PWM_T1_TH_CHANNEL0_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T1_TH_CHANNEL0_MODE_BIT, PWM_T1_TH_CHANNEL0_MODE_WIDTH); }
};

class vp_pwm_t1_th_channel1 : public vp::reg_32
{
public:
  inline void th_set(uint32_t value) { this->set_field(value, PWM_T1_TH_CHANNEL1_TH_BIT, PWM_T1_TH_CHANNEL1_TH_WIDTH); }
  inline uint32_t th_get() { return this->get_field(PWM_T1_TH_CHANNEL1_TH_BIT, PWM_T1_TH_CHANNEL1_TH_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T1_TH_CHANNEL1_MODE_BIT, PWM_T1_TH_CHANNEL1_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T1_TH_CHANNEL1_MODE_BIT, PWM_T1_TH_CHANNEL1_MODE_WIDTH); }
};

class vp_pwm_t1_th_channel2 : public vp::reg_32
{
public:
  inline void th_set(uint32_t value) { this->set_field(value, PWM_T1_TH_CHANNEL2_TH_BIT, PWM_T1_TH_CHANNEL2_TH_WIDTH); }
  inline uint32_t th_get() { return this->get_field(PWM_T1_TH_CHANNEL2_TH_BIT, PWM_T1_TH_CHANNEL2_TH_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T1_TH_CHANNEL2_MODE_BIT, PWM_T1_TH_CHANNEL2_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T1_TH_CHANNEL2_MODE_BIT, PWM_T1_TH_CHANNEL2_MODE_WIDTH); }
};

class vp_pwm_t1_th_channel3 : public vp::reg_32
{
public:
  inline void th_set(uint32_t value) { this->set_field(value, PWM_T1_TH_CHANNEL3_TH_BIT, PWM_T1_TH_CHANNEL3_TH_WIDTH); }
  inline uint32_t th_get() { return this->get_field(PWM_T1_TH_CHANNEL3_TH_BIT, PWM_T1_TH_CHANNEL3_TH_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T1_TH_CHANNEL3_MODE_BIT, PWM_T1_TH_CHANNEL3_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T1_TH_CHANNEL3_MODE_BIT, PWM_T1_TH_CHANNEL3_MODE_WIDTH); }
};

class vp_pwm_t1_counter : public vp::reg_32
{
public:
};

class vp_pwm_t2_cmd : public vp::reg_32
{
public:
  inline void start_set(uint32_t value) { this->set_field(value, PWM_T2_CMD_START_BIT, PWM_T2_CMD_START_WIDTH); }
  inline uint32_t start_get() { return this->get_field(PWM_T2_CMD_START_BIT, PWM_T2_CMD_START_WIDTH); }
  inline void stop_set(uint32_t value) { this->set_field(value, PWM_T2_CMD_STOP_BIT, PWM_T2_CMD_STOP_WIDTH); }
  inline uint32_t stop_get() { return this->get_field(PWM_T2_CMD_STOP_BIT, PWM_T2_CMD_STOP_WIDTH); }
  inline void update_set(uint32_t value) { this->set_field(value, PWM_T2_CMD_UPDATE_BIT, PWM_T2_CMD_UPDATE_WIDTH); }
  inline uint32_t update_get() { return this->get_field(PWM_T2_CMD_UPDATE_BIT, PWM_T2_CMD_UPDATE_WIDTH); }
  inline void reset_set(uint32_t value) { this->set_field(value, PWM_T2_CMD_RESET_BIT, PWM_T2_CMD_RESET_WIDTH); }
  inline uint32_t reset_get() { return this->get_field(PWM_T2_CMD_RESET_BIT, PWM_T2_CMD_RESET_WIDTH); }
  inline void arm_set(uint32_t value) { this->set_field(value, PWM_T2_CMD_ARM_BIT, PWM_T2_CMD_ARM_WIDTH); }
  inline uint32_t arm_get() { return this->get_field(PWM_T2_CMD_ARM_BIT, PWM_T2_CMD_ARM_WIDTH); }
};

class vp_pwm_t2_config : public vp::reg_32
{
public:
  inline void insel_set(uint32_t value) { this->set_field(value, PWM_T2_CONFIG_INSEL_BIT, PWM_T2_CONFIG_INSEL_WIDTH); }
  inline uint32_t insel_get() { return this->get_field(PWM_T2_CONFIG_INSEL_BIT, PWM_T2_CONFIG_INSEL_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T2_CONFIG_MODE_BIT, PWM_T2_CONFIG_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T2_CONFIG_MODE_BIT, PWM_T2_CONFIG_MODE_WIDTH); }
  inline void clksel_set(uint32_t value) { this->set_field(value, PWM_T2_CONFIG_CLKSEL_BIT, PWM_T2_CONFIG_CLKSEL_WIDTH); }
  inline uint32_t clksel_get() { return this->get_field(PWM_T2_CONFIG_CLKSEL_BIT, PWM_T2_CONFIG_CLKSEL_WIDTH); }
  inline void updownsel_set(uint32_t value) { this->set_field(value, PWM_T2_CONFIG_UPDOWNSEL_BIT, PWM_T2_CONFIG_UPDOWNSEL_WIDTH); }
  inline uint32_t updownsel_get() { return this->get_field(PWM_T2_CONFIG_UPDOWNSEL_BIT, PWM_T2_CONFIG_UPDOWNSEL_WIDTH); }
  inline void presc_set(uint32_t value) { this->set_field(value, PWM_T2_CONFIG_PRESC_BIT, PWM_T2_CONFIG_PRESC_WIDTH); }
  inline uint32_t presc_get() { return this->get_field(PWM_T2_CONFIG_PRESC_BIT, PWM_T2_CONFIG_PRESC_WIDTH); }
};

class vp_pwm_t2_threshold : public vp::reg_32
{
public:
  inline void th_lo_set(uint32_t value) { this->set_field(value, PWM_T2_THRESHOLD_TH_LO_BIT, PWM_T2_THRESHOLD_TH_LO_WIDTH); }
  inline uint32_t th_lo_get() { return this->get_field(PWM_T2_THRESHOLD_TH_LO_BIT, PWM_T2_THRESHOLD_TH_LO_WIDTH); }
  inline void th_hi_set(uint32_t value) { this->set_field(value, PWM_T2_THRESHOLD_TH_HI_BIT, PWM_T2_THRESHOLD_TH_HI_WIDTH); }
  inline uint32_t th_hi_get() { return this->get_field(PWM_T2_THRESHOLD_TH_HI_BIT, PWM_T2_THRESHOLD_TH_HI_WIDTH); }
};

class vp_pwm_t2_th_channel0 : public vp::reg_32
{
public:
  inline void th_set(uint32_t value) { this->set_field(value, PWM_T2_TH_CHANNEL0_TH_BIT, PWM_T2_TH_CHANNEL0_TH_WIDTH); }
  inline uint32_t th_get() { return this->get_field(PWM_T2_TH_CHANNEL0_TH_BIT, PWM_T2_TH_CHANNEL0_TH_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T2_TH_CHANNEL0_MODE_BIT, PWM_T2_TH_CHANNEL0_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T2_TH_CHANNEL0_MODE_BIT, PWM_T2_TH_CHANNEL0_MODE_WIDTH); }
};

class vp_pwm_t2_th_channel1 : public vp::reg_32
{
public:
  inline void th_set(uint32_t value) { this->set_field(value, PWM_T2_TH_CHANNEL1_TH_BIT, PWM_T2_TH_CHANNEL1_TH_WIDTH); }
  inline uint32_t th_get() { return this->get_field(PWM_T2_TH_CHANNEL1_TH_BIT, PWM_T2_TH_CHANNEL1_TH_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T2_TH_CHANNEL1_MODE_BIT, PWM_T2_TH_CHANNEL1_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T2_TH_CHANNEL1_MODE_BIT, PWM_T2_TH_CHANNEL1_MODE_WIDTH); }
};

class vp_pwm_t2_th_channel2 : public vp::reg_32
{
public:
  inline void th_set(uint32_t value) { this->set_field(value, PWM_T2_TH_CHANNEL2_TH_BIT, PWM_T2_TH_CHANNEL2_TH_WIDTH); }
  inline uint32_t th_get() { return this->get_field(PWM_T2_TH_CHANNEL2_TH_BIT, PWM_T2_TH_CHANNEL2_TH_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T2_TH_CHANNEL2_MODE_BIT, PWM_T2_TH_CHANNEL2_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T2_TH_CHANNEL2_MODE_BIT, PWM_T2_TH_CHANNEL2_MODE_WIDTH); }
};

class vp_pwm_t2_th_channel3 : public vp::reg_32
{
public:
  inline void th_set(uint32_t value) { this->set_field(value, PWM_T2_TH_CHANNEL3_TH_BIT, PWM_T2_TH_CHANNEL3_TH_WIDTH); }
  inline uint32_t th_get() { return this->get_field(PWM_T2_TH_CHANNEL3_TH_BIT, PWM_T2_TH_CHANNEL3_TH_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T2_TH_CHANNEL3_MODE_BIT, PWM_T2_TH_CHANNEL3_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T2_TH_CHANNEL3_MODE_BIT, PWM_T2_TH_CHANNEL3_MODE_WIDTH); }
};

class vp_pwm_t2_counter : public vp::reg_32
{
public:
};

class vp_pwm_t3_cmd : public vp::reg_32
{
public:
  inline void start_set(uint32_t value) { this->set_field(value, PWM_T3_CMD_START_BIT, PWM_T3_CMD_START_WIDTH); }
  inline uint32_t start_get() { return this->get_field(PWM_T3_CMD_START_BIT, PWM_T3_CMD_START_WIDTH); }
  inline void stop_set(uint32_t value) { this->set_field(value, PWM_T3_CMD_STOP_BIT, PWM_T3_CMD_STOP_WIDTH); }
  inline uint32_t stop_get() { return this->get_field(PWM_T3_CMD_STOP_BIT, PWM_T3_CMD_STOP_WIDTH); }
  inline void update_set(uint32_t value) { this->set_field(value, PWM_T3_CMD_UPDATE_BIT, PWM_T3_CMD_UPDATE_WIDTH); }
  inline uint32_t update_get() { return this->get_field(PWM_T3_CMD_UPDATE_BIT, PWM_T3_CMD_UPDATE_WIDTH); }
  inline void reset_set(uint32_t value) { this->set_field(value, PWM_T3_CMD_RESET_BIT, PWM_T3_CMD_RESET_WIDTH); }
  inline uint32_t reset_get() { return this->get_field(PWM_T3_CMD_RESET_BIT, PWM_T3_CMD_RESET_WIDTH); }
  inline void arm_set(uint32_t value) { this->set_field(value, PWM_T3_CMD_ARM_BIT, PWM_T3_CMD_ARM_WIDTH); }
  inline uint32_t arm_get() { return this->get_field(PWM_T3_CMD_ARM_BIT, PWM_T3_CMD_ARM_WIDTH); }
};

class vp_pwm_t3_config : public vp::reg_32
{
public:
  inline void insel_set(uint32_t value) { this->set_field(value, PWM_T3_CONFIG_INSEL_BIT, PWM_T3_CONFIG_INSEL_WIDTH); }
  inline uint32_t insel_get() { return this->get_field(PWM_T3_CONFIG_INSEL_BIT, PWM_T3_CONFIG_INSEL_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T3_CONFIG_MODE_BIT, PWM_T3_CONFIG_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T3_CONFIG_MODE_BIT, PWM_T3_CONFIG_MODE_WIDTH); }
  inline void clksel_set(uint32_t value) { this->set_field(value, PWM_T3_CONFIG_CLKSEL_BIT, PWM_T3_CONFIG_CLKSEL_WIDTH); }
  inline uint32_t clksel_get() { return this->get_field(PWM_T3_CONFIG_CLKSEL_BIT, PWM_T3_CONFIG_CLKSEL_WIDTH); }
  inline void updownsel_set(uint32_t value) { this->set_field(value, PWM_T3_CONFIG_UPDOWNSEL_BIT, PWM_T3_CONFIG_UPDOWNSEL_WIDTH); }
  inline uint32_t updownsel_get() { return this->get_field(PWM_T3_CONFIG_UPDOWNSEL_BIT, PWM_T3_CONFIG_UPDOWNSEL_WIDTH); }
  inline void presc_set(uint32_t value) { this->set_field(value, PWM_T3_CONFIG_PRESC_BIT, PWM_T3_CONFIG_PRESC_WIDTH); }
  inline uint32_t presc_get() { return this->get_field(PWM_T3_CONFIG_PRESC_BIT, PWM_T3_CONFIG_PRESC_WIDTH); }
};

class vp_pwm_t3_threshold : public vp::reg_32
{
public:
  inline void th_lo_set(uint32_t value) { this->set_field(value, PWM_T3_THRESHOLD_TH_LO_BIT, PWM_T3_THRESHOLD_TH_LO_WIDTH); }
  inline uint32_t th_lo_get() { return this->get_field(PWM_T3_THRESHOLD_TH_LO_BIT, PWM_T3_THRESHOLD_TH_LO_WIDTH); }
  inline void th_hi_set(uint32_t value) { this->set_field(value, PWM_T3_THRESHOLD_TH_HI_BIT, PWM_T3_THRESHOLD_TH_HI_WIDTH); }
  inline uint32_t th_hi_get() { return this->get_field(PWM_T3_THRESHOLD_TH_HI_BIT, PWM_T3_THRESHOLD_TH_HI_WIDTH); }
};

class vp_pwm_t3_th_channel0 : public vp::reg_32
{
public:
  inline void th_set(uint32_t value) { this->set_field(value, PWM_T3_TH_CHANNEL0_TH_BIT, PWM_T3_TH_CHANNEL0_TH_WIDTH); }
  inline uint32_t th_get() { return this->get_field(PWM_T3_TH_CHANNEL0_TH_BIT, PWM_T3_TH_CHANNEL0_TH_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T3_TH_CHANNEL0_MODE_BIT, PWM_T3_TH_CHANNEL0_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T3_TH_CHANNEL0_MODE_BIT, PWM_T3_TH_CHANNEL0_MODE_WIDTH); }
};

class vp_pwm_t3_th_channel1 : public vp::reg_32
{
public:
  inline void th_set(uint32_t value) { this->set_field(value, PWM_T3_TH_CHANNEL1_TH_BIT, PWM_T3_TH_CHANNEL1_TH_WIDTH); }
  inline uint32_t th_get() { return this->get_field(PWM_T3_TH_CHANNEL1_TH_BIT, PWM_T3_TH_CHANNEL1_TH_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T3_TH_CHANNEL1_MODE_BIT, PWM_T3_TH_CHANNEL1_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T3_TH_CHANNEL1_MODE_BIT, PWM_T3_TH_CHANNEL1_MODE_WIDTH); }
};

class vp_pwm_t3_th_channel2 : public vp::reg_32
{
public:
  inline void th_set(uint32_t value) { this->set_field(value, PWM_T3_TH_CHANNEL2_TH_BIT, PWM_T3_TH_CHANNEL2_TH_WIDTH); }
  inline uint32_t th_get() { return this->get_field(PWM_T3_TH_CHANNEL2_TH_BIT, PWM_T3_TH_CHANNEL2_TH_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T3_TH_CHANNEL2_MODE_BIT, PWM_T3_TH_CHANNEL2_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T3_TH_CHANNEL2_MODE_BIT, PWM_T3_TH_CHANNEL2_MODE_WIDTH); }
};

class vp_pwm_t3_th_channel3 : public vp::reg_32
{
public:
  inline void th_set(uint32_t value) { this->set_field(value, PWM_T3_TH_CHANNEL3_TH_BIT, PWM_T3_TH_CHANNEL3_TH_WIDTH); }
  inline uint32_t th_get() { return this->get_field(PWM_T3_TH_CHANNEL3_TH_BIT, PWM_T3_TH_CHANNEL3_TH_WIDTH); }
  inline void mode_set(uint32_t value) { this->set_field(value, PWM_T3_TH_CHANNEL3_MODE_BIT, PWM_T3_TH_CHANNEL3_MODE_WIDTH); }
  inline uint32_t mode_get() { return this->get_field(PWM_T3_TH_CHANNEL3_MODE_BIT, PWM_T3_TH_CHANNEL3_MODE_WIDTH); }
};

class vp_pwm_t3_counter : public vp::reg_32
{
public:
};

class vp_pwm_event_cfg : public vp::reg_32
{
public:
  inline void sel0_set(uint32_t value) { this->set_field(value, PWM_EVENT_CFG_SEL0_BIT, PWM_EVENT_CFG_SEL0_WIDTH); }
  inline uint32_t sel0_get() { return this->get_field(PWM_EVENT_CFG_SEL0_BIT, PWM_EVENT_CFG_SEL0_WIDTH); }
  inline void sel1_set(uint32_t value) { this->set_field(value, PWM_EVENT_CFG_SEL1_BIT, PWM_EVENT_CFG_SEL1_WIDTH); }
  inline uint32_t sel1_get() { return this->get_field(PWM_EVENT_CFG_SEL1_BIT, PWM_EVENT_CFG_SEL1_WIDTH); }
  inline void sel2_set(uint32_t value) { this->set_field(value, PWM_EVENT_CFG_SEL2_BIT, PWM_EVENT_CFG_SEL2_WIDTH); }
  inline uint32_t sel2_get() { return this->get_field(PWM_EVENT_CFG_SEL2_BIT, PWM_EVENT_CFG_SEL2_WIDTH); }
  inline void sel3_set(uint32_t value) { this->set_field(value, PWM_EVENT_CFG_SEL3_BIT, PWM_EVENT_CFG_SEL3_WIDTH); }
  inline uint32_t sel3_get() { return this->get_field(PWM_EVENT_CFG_SEL3_BIT, PWM_EVENT_CFG_SEL3_WIDTH); }
  inline void ena_set(uint32_t value) { this->set_field(value, PWM_EVENT_CFG_ENA_BIT, PWM_EVENT_CFG_ENA_WIDTH); }
  inline uint32_t ena_get() { return this->get_field(PWM_EVENT_CFG_ENA_BIT, PWM_EVENT_CFG_ENA_WIDTH); }
};

class vp_pwm_cg : public vp::reg_32
{
public:
  inline void ena_set(uint32_t value) { this->set_field(value, PWM_CG_ENA_BIT, PWM_CG_ENA_WIDTH); }
  inline uint32_t ena_get() { return this->get_field(PWM_CG_ENA_BIT, PWM_CG_ENA_WIDTH); }
};

#endif

#endif
