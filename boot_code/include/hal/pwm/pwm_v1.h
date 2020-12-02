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

#ifndef __HAL_PWM_PWM_V1_H__
#define __HAL_PWM_PWM_V1_H__

#include <archi/pulp.h>
#include <archi/pwm/pwm_v1.h>

/* Timer Base:	PWM_BASE_ADDR + Timer*PWM_TIMER_TO_TIMER_OFFSET
	Config:		+ PWM_TIMER_CONFIG_OFFSET
	Threhsold:	+ PWM_TIMER_THRESHOLD_OFFSET
	Channel Thresh	+ PWM_TIMER_TH_CHANNEL_OFFSET + Channel*PWM_CHANNEL_TO_CHANNEL_OFFSET
	Channel LUT	+ PWM_TIMER_LUT_CHANNEL_OFFSET + Channel*PWM_CHANNEL_TO_CHANNEL_OFFSET
*/

typedef enum {
	PWM_TIMER0=0,
	PWM_TIMER1=1,
	PWM_TIMER2=2,
	PWM_TIMER3=3,
} numPwmTimerT;

typedef enum {
	PWM_TIMER_TH_CHANNEL0=0,
	PWM_TIMER_TH_CHANNEL1=1,
	PWM_TIMER_TH_CHANNEL2=2,
	PWM_TIMER_TH_CHANNEL3=3,
} PwmTimerThChannelT;

typedef enum {
	PWM_TIMER_LUT_CHANNEL0=0,
	PWM_TIMER_LUT_CHANNEL1=1,
	PWM_TIMER_LUT_CHANNEL2=2,
	PWM_TIMER_LUT_CHANNEL3=3,
} PwmTimerLutChannelT;

enum{
    pwm_timer_event0 = 0,
    pwm_timer_event1 ,
    pwm_timer_event2 ,
    pwm_timer_event3 ,
};

typedef enum {
    PWM_TIMER_CMD_START = 0x01, 		/* Start counting */
    PWM_TIMER_CMD_STOP  = 0x02, 		/* Stop counting */
    PWM_TIMER_CMD_UPD   = 0x04, 		/* Update timer params */
    PWM_TIMER_CMD_RST   = 0x08, 		/* Reset counter value */
} PwmCounterCmdT;

typedef struct {
    unsigned int SelectInputSource:8;	/* Select counting condition */
    unsigned int InputEnableIn:3;		/* Define enable rules:
                                           000, always count (use clock)
                                           001 count when external input is 0
                                           010 count when external input is 1
                                           011 count on rising edge of external
                                           100 count on falling edge of external
                                           101 count on falling and on rising edge of external
                                           */
    unsigned int FllOrRTC:1;		/* Clock input of counter is Fll or RTC */
    unsigned int IncThenDec:1;		/* When counter reaches threshold count down if IncThenDec else return to 0 and ocunt up again */
    unsigned int Pad:3;
    unsigned int PreScaler:8;		/* */
    unsigned int Pad2:8;
} PwmCounterConfigT;

typedef struct {
	unsigned int chThreshold:16;		/* Threshold value for the channel of a counter */
	unsigned int chAction:3;
						/* When counter reaches threshold:
							000: Set
							001: Toggle then next is Clear
							010: Set then Clear
							011: Toggle
							100: Clear
							101: Toggle then next is Set
							110: Clear then Set
						*/
    unsigned int Pad:13;
} PwmChannelThConfigT;

typedef struct {
	unsigned int Lut:16;
	unsigned int Flt:2;
	unsigned int Pad:14;
} PwmChannelLutConfigT;

typedef struct{
    unsigned int evt0_sel:4;
    unsigned int evt1_sel:4;
    unsigned int evt2_sel:4;
    unsigned int evt3_sel:4;
    unsigned int evt_en:4;
    unsigned int pad:12;
} PwmTimerEvtT;

//  TODO: maybe we do not need the functions: _get below,
//  because all the get could be replaced by reading the value of struct objects.
//  Except: maybe we need to reset the values in structs after a "RESET"!!
//          And for debugging usages.
static inline void gap_pwm_timer_cmd(numPwmTimerT timer, PwmCounterCmdT CMD){
    pulp_write32( PWM_TIMER_CMD_ADDR(timer), CMD);
}

static inline void gap_pwm_timer_config(numPwmTimerT timer, unsigned int conf){
    pulp_write32( PWM_TIMER_CONFIG_ADDR(timer), conf);
}

static inline unsigned int gap_pwm_timer_config_get(numPwmTimerT timer){
    return pulp_read32( PWM_TIMER_CONFIG_ADDR(timer));
}

static inline void gap_pwm_timer_threshold_set(numPwmTimerT timer, unsigned int value){
    pulp_write32(PWM_TIMER_THRESHOLD_ADDR(timer), value);
}

static inline unsigned int gap_pwm_timer_threshold_get(numPwmTimerT timer){
    return pulp_read32(PWM_TIMER_THRESHOLD_ADDR(timer));
}

static inline void gap_pwm_timer_th_channel_set(numPwmTimerT timer, PwmTimerThChannelT channel, unsigned int value){
    pulp_write32(PWM_TIMER_TH_CHANNEL_ADDR(timer, channel), value);
}

static inline unsigned int gap_pwm_timer_th_channel_get(numPwmTimerT timer, PwmTimerThChannelT channel){
    return pulp_read32(PWM_TIMER_TH_CHANNEL_ADDR(timer, channel));
}

static inline void gap_pwm_timer_lut_channel_set(numPwmTimerT timer, PwmTimerThChannelT channel, unsigned int value){
    pulp_write32(PWM_TIMER_LUT_CHANNEL_ADDR(timer, channel), value);
}

static inline unsigned int gap_pwm_timer_lut_channel_get(numPwmTimerT timer, PwmTimerThChannelT channel){
    return pulp_read32(PWM_TIMER_LUT_CHANNEL_ADDR(timer, channel));
}

static inline unsigned int gap_pwm_timer_read_counter(numPwmTimerT nTimer) {
	return pulp_read32( PWM_TIMER_COUNTER_ADDR(nTimer) );
}

static inline void gap_pwm_timer_evt_reg_cfg (unsigned int CMD){
    pulp_write32(REG_EVENT_CFG, CMD);
}

static inline unsigned int gap_pwm_timer_evt_reg_read() {
	return pulp_read32( REG_EVENT_CFG );
}

static inline unsigned int gap_pwm_timer_status(){
    return pulp_read32(REG_PWM_TIMER_EN);
}

static inline void gap_pwm_timer_en_reg(unsigned int timer_en_val){
    pulp_write32(REG_PWM_TIMER_EN, timer_en_val);
}
/*************************************************************************/

typedef union{
    PwmCounterConfigT       timerConf;
    unsigned int            timerTh;    /* Threshold value for the counter */
    PwmChannelThConfigT     ch_ThConfig;
    PwmChannelLutConfigT    ch_LutConfig;
    PwmTimerEvtT            timerEvt;
    unsigned int            Raw;
} gap_pwm_timer_t;


#endif
