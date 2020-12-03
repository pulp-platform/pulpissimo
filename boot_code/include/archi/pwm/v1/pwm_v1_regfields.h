
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

#ifndef __INCLUDE_ARCHI_PWM_V1_PWM_V1_REGFIELDS_H__
#define __INCLUDE_ARCHI_PWM_V1_PWM_V1_REGFIELDS_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS FIELDS
//

// ADV_TIMER0 start command bitfield. (access: R/W)
#define PWM_T0_CMD_START_BIT                                         0
#define PWM_T0_CMD_START_WIDTH                                       1
#define PWM_T0_CMD_START_MASK                                        0x1

// ADV_TIMER0 stop command bitfield. (access: R/W)
#define PWM_T0_CMD_STOP_BIT                                          1
#define PWM_T0_CMD_STOP_WIDTH                                        1
#define PWM_T0_CMD_STOP_MASK                                         0x2

// ADV_TIMER0 update command bitfield. (access: R/W)
#define PWM_T0_CMD_UPDATE_BIT                                        2
#define PWM_T0_CMD_UPDATE_WIDTH                                      1
#define PWM_T0_CMD_UPDATE_MASK                                       0x4

// ADV_TIMER0 reset command bitfield. (access: R/W)
#define PWM_T0_CMD_RESET_BIT                                         3
#define PWM_T0_CMD_RESET_WIDTH                                       1
#define PWM_T0_CMD_RESET_MASK                                        0x8

// ADV_TIMER0 arm command bitfield. (access: R/W)
#define PWM_T0_CMD_ARM_BIT                                           4
#define PWM_T0_CMD_ARM_WIDTH                                         1
#define PWM_T0_CMD_ARM_MASK                                          0x10

// ADV_TIMER0 input source configuration bitfield: - 0-31: GPIO[0] to GPIO[31] - 32-35: Channel 0 to 3 of ADV_TIMER0 - 36-39: Channel 0 to 3 of ADV_TIMER1 - 40-43: Channel 0 to 3 of ADV_TIMER2 - 44-47: Channel 0 to 3 of ADV_TIMER3 (access: R/W)
#define PWM_T0_CONFIG_INSEL_BIT                                      0
#define PWM_T0_CONFIG_INSEL_WIDTH                                    8
#define PWM_T0_CONFIG_INSEL_MASK                                     0xff

// ADV_TIMER0 trigger mode configuration bitfield: - 3'h0: trigger event at each clock cycle. - 3'h1: trigger event if input source is 0 - 3'h2: trigger event if input source is 1 - 3'h3: trigger event on input source rising edge - 3'h4: trigger event on input source falling edge - 3'h5: trigger event on input source falling or rising edge - 3'h6: trigger event on input source rising edge when armed - 3'h7: trigger event on input source falling edge when armed (access: R/W)
#define PWM_T0_CONFIG_MODE_BIT                                       8
#define PWM_T0_CONFIG_MODE_WIDTH                                     3
#define PWM_T0_CONFIG_MODE_MASK                                      0x700

// ADV_TIMER0 clock source configuration bitfield: - 1'b0: FLL - 1'b1: reference clock at 32kHz (access: R/W)
#define PWM_T0_CONFIG_CLKSEL_BIT                                     11
#define PWM_T0_CONFIG_CLKSEL_WIDTH                                   1
#define PWM_T0_CONFIG_CLKSEL_MASK                                    0x800

// ADV_TIMER0 center-aligned mode configuration bitfield: - 1'b0: The counter counts up and down alternatively. - 1'b1: The counter counts up and resets to 0 when reach threshold. (access: R/W)
#define PWM_T0_CONFIG_UPDOWNSEL_BIT                                  12
#define PWM_T0_CONFIG_UPDOWNSEL_WIDTH                                1
#define PWM_T0_CONFIG_UPDOWNSEL_MASK                                 0x1000

// ADV_TIMER0 prescaler value configuration bitfield. (access: R/W)
#define PWM_T0_CONFIG_PRESC_BIT                                      16
#define PWM_T0_CONFIG_PRESC_WIDTH                                    8
#define PWM_T0_CONFIG_PRESC_MASK                                     0xff0000

// ADV_TIMER0 threshold low part configuration bitfield. It defines start counter value. (access: R/W)
#define PWM_T0_THRESHOLD_TH_LO_BIT                                   0
#define PWM_T0_THRESHOLD_TH_LO_WIDTH                                 16
#define PWM_T0_THRESHOLD_TH_LO_MASK                                  0xffff

// ADV_TIMER0 threshold high part configuration bitfield. It defines end counter value. (access: R/W)
#define PWM_T0_THRESHOLD_TH_HI_BIT                                   16
#define PWM_T0_THRESHOLD_TH_HI_WIDTH                                 16
#define PWM_T0_THRESHOLD_TH_HI_MASK                                  0xffff0000

// ADV_TIMER0 channel 0 threshold configuration bitfield. (access: R/W)
#define PWM_T0_TH_CHANNEL0_TH_BIT                                    0
#define PWM_T0_TH_CHANNEL0_TH_WIDTH                                  16
#define PWM_T0_TH_CHANNEL0_TH_MASK                                   0xffff

// ADV_TIMER0 channel 0 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set. (access: R/W)
#define PWM_T0_TH_CHANNEL0_MODE_BIT                                  16
#define PWM_T0_TH_CHANNEL0_MODE_WIDTH                                3
#define PWM_T0_TH_CHANNEL0_MODE_MASK                                 0x70000

// ADV_TIMER0 channel 1 threshold configuration bitfield. (access: R/W)
#define PWM_T0_TH_CHANNEL1_TH_BIT                                    0
#define PWM_T0_TH_CHANNEL1_TH_WIDTH                                  16
#define PWM_T0_TH_CHANNEL1_TH_MASK                                   0xffff

// ADV_TIMER0 channel 1 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set. (access: R/W)
#define PWM_T0_TH_CHANNEL1_MODE_BIT                                  16
#define PWM_T0_TH_CHANNEL1_MODE_WIDTH                                3
#define PWM_T0_TH_CHANNEL1_MODE_MASK                                 0x70000

// ADV_TIMER0 channel 2 threshold configuration bitfield. (access: R/W)
#define PWM_T0_TH_CHANNEL2_TH_BIT                                    0
#define PWM_T0_TH_CHANNEL2_TH_WIDTH                                  16
#define PWM_T0_TH_CHANNEL2_TH_MASK                                   0xffff

// ADV_TIMER0 channel 2 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set. (access: R/W)
#define PWM_T0_TH_CHANNEL2_MODE_BIT                                  16
#define PWM_T0_TH_CHANNEL2_MODE_WIDTH                                3
#define PWM_T0_TH_CHANNEL2_MODE_MASK                                 0x70000

// ADV_TIMER0 channel 3 threshold configuration bitfield. (access: R/W)
#define PWM_T0_TH_CHANNEL3_TH_BIT                                    0
#define PWM_T0_TH_CHANNEL3_TH_WIDTH                                  16
#define PWM_T0_TH_CHANNEL3_TH_MASK                                   0xffff

// ADV_TIMER0 channel 3 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set. (access: R/W)
#define PWM_T0_TH_CHANNEL3_MODE_BIT                                  16
#define PWM_T0_TH_CHANNEL3_MODE_WIDTH                                3
#define PWM_T0_TH_CHANNEL3_MODE_MASK                                 0x70000

// ADV_TIMER1 start command bitfield. (access: R/W)
#define PWM_T1_CMD_START_BIT                                         0
#define PWM_T1_CMD_START_WIDTH                                       1
#define PWM_T1_CMD_START_MASK                                        0x1

// ADV_TIMER1 stop command bitfield. (access: R/W)
#define PWM_T1_CMD_STOP_BIT                                          1
#define PWM_T1_CMD_STOP_WIDTH                                        1
#define PWM_T1_CMD_STOP_MASK                                         0x2

// ADV_TIMER1 update command bitfield. (access: R/W)
#define PWM_T1_CMD_UPDATE_BIT                                        2
#define PWM_T1_CMD_UPDATE_WIDTH                                      1
#define PWM_T1_CMD_UPDATE_MASK                                       0x4

// ADV_TIMER1 reset command bitfield. (access: R/W)
#define PWM_T1_CMD_RESET_BIT                                         3
#define PWM_T1_CMD_RESET_WIDTH                                       1
#define PWM_T1_CMD_RESET_MASK                                        0x8

// ADV_TIMER1 arm command bitfield. (access: R/W)
#define PWM_T1_CMD_ARM_BIT                                           4
#define PWM_T1_CMD_ARM_WIDTH                                         1
#define PWM_T1_CMD_ARM_MASK                                          0x10

// ADV_TIMER1 input source configuration bitfield: - 0-31: GPIO[0] to GPIO[31] - 32-35: Channel 0 to 3 of ADV_TIMER0 - 36-39: Channel 0 to 3 of ADV_TIMER1 - 40-43: Channel 0 to 3 of ADV_TIMER2 - 44-47: Channel 0 to 3 of ADV_TIMER3 (access: R/W)
#define PWM_T1_CONFIG_INSEL_BIT                                      0
#define PWM_T1_CONFIG_INSEL_WIDTH                                    8
#define PWM_T1_CONFIG_INSEL_MASK                                     0xff

// ADV_TIMER1 trigger mode configuration bitfield: - 3'h0: trigger event at each clock cycle. - 3'h1: trigger event if input source is 0 - 3'h2: trigger event if input source is 1 - 3'h3: trigger event on input source rising edge - 3'h4: trigger event on input source falling edge - 3'h5: trigger event on input source falling or rising edge - 3'h6: trigger event on input source rising edge when armed - 3'h7: trigger event on input source falling edge when armed (access: R/W)
#define PWM_T1_CONFIG_MODE_BIT                                       8
#define PWM_T1_CONFIG_MODE_WIDTH                                     3
#define PWM_T1_CONFIG_MODE_MASK                                      0x700

// ADV_TIMER1 clock source configuration bitfield: - 1'b0: FLL - 1'b1: reference clock at 32kHz (access: R/W)
#define PWM_T1_CONFIG_CLKSEL_BIT                                     11
#define PWM_T1_CONFIG_CLKSEL_WIDTH                                   1
#define PWM_T1_CONFIG_CLKSEL_MASK                                    0x800

// ADV_TIMER1 center-aligned mode configuration bitfield: - 1'b0: The counter counts up and down alternatively. - 1'b1: The counter counts up and resets to 0 when reach threshold. (access: R/W)
#define PWM_T1_CONFIG_UPDOWNSEL_BIT                                  12
#define PWM_T1_CONFIG_UPDOWNSEL_WIDTH                                1
#define PWM_T1_CONFIG_UPDOWNSEL_MASK                                 0x1000

// ADV_TIMER1 prescaler value configuration bitfield. (access: R/W)
#define PWM_T1_CONFIG_PRESC_BIT                                      16
#define PWM_T1_CONFIG_PRESC_WIDTH                                    8
#define PWM_T1_CONFIG_PRESC_MASK                                     0xff0000

// ADV_TIMER1 threshold low part configuration bitfield. It defines start counter value. (access: R/W)
#define PWM_T1_THRESHOLD_TH_LO_BIT                                   0
#define PWM_T1_THRESHOLD_TH_LO_WIDTH                                 16
#define PWM_T1_THRESHOLD_TH_LO_MASK                                  0xffff

// ADV_TIMER1 threshold high part configuration bitfield. It defines end counter value. (access: R/W)
#define PWM_T1_THRESHOLD_TH_HI_BIT                                   16
#define PWM_T1_THRESHOLD_TH_HI_WIDTH                                 16
#define PWM_T1_THRESHOLD_TH_HI_MASK                                  0xffff0000

// ADV_TIMER1 channel 0 threshold configuration bitfield. (access: R/W)
#define PWM_T1_TH_CHANNEL0_TH_BIT                                    0
#define PWM_T1_TH_CHANNEL0_TH_WIDTH                                  16
#define PWM_T1_TH_CHANNEL0_TH_MASK                                   0xffff

// ADV_TIMER1 channel 0 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set. (access: R/W)
#define PWM_T1_TH_CHANNEL0_MODE_BIT                                  16
#define PWM_T1_TH_CHANNEL0_MODE_WIDTH                                3
#define PWM_T1_TH_CHANNEL0_MODE_MASK                                 0x70000

// ADV_TIMER1 channel 1 threshold configuration bitfield. (access: R/W)
#define PWM_T1_TH_CHANNEL1_TH_BIT                                    0
#define PWM_T1_TH_CHANNEL1_TH_WIDTH                                  16
#define PWM_T1_TH_CHANNEL1_TH_MASK                                   0xffff

// ADV_TIMER1 channel 1 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set. (access: R/W)
#define PWM_T1_TH_CHANNEL1_MODE_BIT                                  16
#define PWM_T1_TH_CHANNEL1_MODE_WIDTH                                3
#define PWM_T1_TH_CHANNEL1_MODE_MASK                                 0x70000

// ADV_TIMER1 channel 2 threshold configuration bitfield. (access: R/W)
#define PWM_T1_TH_CHANNEL2_TH_BIT                                    0
#define PWM_T1_TH_CHANNEL2_TH_WIDTH                                  16
#define PWM_T1_TH_CHANNEL2_TH_MASK                                   0xffff

// ADV_TIMER1 channel 2 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set. (access: R/W)
#define PWM_T1_TH_CHANNEL2_MODE_BIT                                  16
#define PWM_T1_TH_CHANNEL2_MODE_WIDTH                                3
#define PWM_T1_TH_CHANNEL2_MODE_MASK                                 0x70000

// ADV_TIMER1 channel 3 threshold configuration bitfield. (access: R/W)
#define PWM_T1_TH_CHANNEL3_TH_BIT                                    0
#define PWM_T1_TH_CHANNEL3_TH_WIDTH                                  16
#define PWM_T1_TH_CHANNEL3_TH_MASK                                   0xffff

// ADV_TIMER1 channel 3 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set. (access: R/W)
#define PWM_T1_TH_CHANNEL3_MODE_BIT                                  16
#define PWM_T1_TH_CHANNEL3_MODE_WIDTH                                3
#define PWM_T1_TH_CHANNEL3_MODE_MASK                                 0x70000

// ADV_TIMER2 start command bitfield. (access: R/W)
#define PWM_T2_CMD_START_BIT                                         0
#define PWM_T2_CMD_START_WIDTH                                       1
#define PWM_T2_CMD_START_MASK                                        0x1

// ADV_TIMER2 stop command bitfield. (access: R/W)
#define PWM_T2_CMD_STOP_BIT                                          1
#define PWM_T2_CMD_STOP_WIDTH                                        1
#define PWM_T2_CMD_STOP_MASK                                         0x2

// ADV_TIMER2 update command bitfield. (access: R/W)
#define PWM_T2_CMD_UPDATE_BIT                                        2
#define PWM_T2_CMD_UPDATE_WIDTH                                      1
#define PWM_T2_CMD_UPDATE_MASK                                       0x4

// ADV_TIMER2 reset command bitfield. (access: R/W)
#define PWM_T2_CMD_RESET_BIT                                         3
#define PWM_T2_CMD_RESET_WIDTH                                       1
#define PWM_T2_CMD_RESET_MASK                                        0x8

// ADV_TIMER2 arm command bitfield. (access: R/W)
#define PWM_T2_CMD_ARM_BIT                                           4
#define PWM_T2_CMD_ARM_WIDTH                                         1
#define PWM_T2_CMD_ARM_MASK                                          0x10

// ADV_TIMER2 input source configuration bitfield: - 0-31: GPIO[0] to GPIO[31] - 32-35: Channel 0 to 3 of ADV_TIMER0 - 36-39: Channel 0 to 3 of ADV_TIMER1 - 40-43: Channel 0 to 3 of ADV_TIMER2 - 44-47: Channel 0 to 3 of ADV_TIMER3 (access: R/W)
#define PWM_T2_CONFIG_INSEL_BIT                                      0
#define PWM_T2_CONFIG_INSEL_WIDTH                                    8
#define PWM_T2_CONFIG_INSEL_MASK                                     0xff

// ADV_TIMER2 trigger mode configuration bitfield: - 3'h0: trigger event at each clock cycle. - 3'h1: trigger event if input source is 0 - 3'h2: trigger event if input source is 1 - 3'h3: trigger event on input source rising edge - 3'h4: trigger event on input source falling edge - 3'h5: trigger event on input source falling or rising edge - 3'h6: trigger event on input source rising edge when armed - 3'h7: trigger event on input source falling edge when armed (access: R/W)
#define PWM_T2_CONFIG_MODE_BIT                                       8
#define PWM_T2_CONFIG_MODE_WIDTH                                     3
#define PWM_T2_CONFIG_MODE_MASK                                      0x700

// ADV_TIMER2 clock source configuration bitfield: - 1'b0: FLL - 1'b1: reference clock at 32kHz (access: R/W)
#define PWM_T2_CONFIG_CLKSEL_BIT                                     11
#define PWM_T2_CONFIG_CLKSEL_WIDTH                                   1
#define PWM_T2_CONFIG_CLKSEL_MASK                                    0x800

// ADV_TIMER2 center-aligned mode configuration bitfield: - 1'b0: The counter counts up and down alternatively. - 1'b1: The counter counts up and resets to 0 when reach threshold. (access: R/W)
#define PWM_T2_CONFIG_UPDOWNSEL_BIT                                  12
#define PWM_T2_CONFIG_UPDOWNSEL_WIDTH                                1
#define PWM_T2_CONFIG_UPDOWNSEL_MASK                                 0x1000

// ADV_TIMER2 prescaler value configuration bitfield. (access: R/W)
#define PWM_T2_CONFIG_PRESC_BIT                                      16
#define PWM_T2_CONFIG_PRESC_WIDTH                                    8
#define PWM_T2_CONFIG_PRESC_MASK                                     0xff0000

// ADV_TIMER2 threshold low part configuration bitfield. It defines start counter value. (access: R/W)
#define PWM_T2_THRESHOLD_TH_LO_BIT                                   0
#define PWM_T2_THRESHOLD_TH_LO_WIDTH                                 16
#define PWM_T2_THRESHOLD_TH_LO_MASK                                  0xffff

// ADV_TIMER2 threshold high part configuration bitfield. It defines end counter value. (access: R/W)
#define PWM_T2_THRESHOLD_TH_HI_BIT                                   16
#define PWM_T2_THRESHOLD_TH_HI_WIDTH                                 16
#define PWM_T2_THRESHOLD_TH_HI_MASK                                  0xffff0000

// ADV_TIMER2 channel 0 threshold configuration bitfield. (access: R/W)
#define PWM_T2_TH_CHANNEL0_TH_BIT                                    0
#define PWM_T2_TH_CHANNEL0_TH_WIDTH                                  16
#define PWM_T2_TH_CHANNEL0_TH_MASK                                   0xffff

// ADV_TIMER2 channel 0 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set. (access: R/W)
#define PWM_T2_TH_CHANNEL0_MODE_BIT                                  16
#define PWM_T2_TH_CHANNEL0_MODE_WIDTH                                3
#define PWM_T2_TH_CHANNEL0_MODE_MASK                                 0x70000

// ADV_TIMER2 channel 1 threshold configuration bitfield. (access: R/W)
#define PWM_T2_TH_CHANNEL1_TH_BIT                                    0
#define PWM_T2_TH_CHANNEL1_TH_WIDTH                                  16
#define PWM_T2_TH_CHANNEL1_TH_MASK                                   0xffff

// ADV_TIMER2 channel 1 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set. (access: R/W)
#define PWM_T2_TH_CHANNEL1_MODE_BIT                                  16
#define PWM_T2_TH_CHANNEL1_MODE_WIDTH                                3
#define PWM_T2_TH_CHANNEL1_MODE_MASK                                 0x70000

// ADV_TIMER2 channel 2 threshold configuration bitfield. (access: R/W)
#define PWM_T2_TH_CHANNEL2_TH_BIT                                    0
#define PWM_T2_TH_CHANNEL2_TH_WIDTH                                  16
#define PWM_T2_TH_CHANNEL2_TH_MASK                                   0xffff

// ADV_TIMER2 channel 2 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set. (access: R/W)
#define PWM_T2_TH_CHANNEL2_MODE_BIT                                  16
#define PWM_T2_TH_CHANNEL2_MODE_WIDTH                                3
#define PWM_T2_TH_CHANNEL2_MODE_MASK                                 0x70000

// ADV_TIMER2 channel 3 threshold configuration bitfield. (access: R/W)
#define PWM_T2_TH_CHANNEL3_TH_BIT                                    0
#define PWM_T2_TH_CHANNEL3_TH_WIDTH                                  16
#define PWM_T2_TH_CHANNEL3_TH_MASK                                   0xffff

// ADV_TIMER2 channel 3 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set. (access: R/W)
#define PWM_T2_TH_CHANNEL3_MODE_BIT                                  16
#define PWM_T2_TH_CHANNEL3_MODE_WIDTH                                3
#define PWM_T2_TH_CHANNEL3_MODE_MASK                                 0x70000

// ADV_TIMER3 start command bitfield. (access: R/W)
#define PWM_T3_CMD_START_BIT                                         0
#define PWM_T3_CMD_START_WIDTH                                       1
#define PWM_T3_CMD_START_MASK                                        0x1

// ADV_TIMER3 stop command bitfield. (access: R/W)
#define PWM_T3_CMD_STOP_BIT                                          1
#define PWM_T3_CMD_STOP_WIDTH                                        1
#define PWM_T3_CMD_STOP_MASK                                         0x2

// ADV_TIMER3 update command bitfield. (access: R/W)
#define PWM_T3_CMD_UPDATE_BIT                                        2
#define PWM_T3_CMD_UPDATE_WIDTH                                      1
#define PWM_T3_CMD_UPDATE_MASK                                       0x4

// ADV_TIMER3 reset command bitfield. (access: R/W)
#define PWM_T3_CMD_RESET_BIT                                         3
#define PWM_T3_CMD_RESET_WIDTH                                       1
#define PWM_T3_CMD_RESET_MASK                                        0x8

// ADV_TIMER3 arm command bitfield. (access: R/W)
#define PWM_T3_CMD_ARM_BIT                                           4
#define PWM_T3_CMD_ARM_WIDTH                                         1
#define PWM_T3_CMD_ARM_MASK                                          0x10

// ADV_TIMER3 input source configuration bitfield: - 0-31: GPIO[0] to GPIO[31] - 32-35: Channel 0 to 3 of ADV_TIMER0 - 36-39: Channel 0 to 3 of ADV_TIMER1 - 40-43: Channel 0 to 3 of ADV_TIMER2 - 44-47: Channel 0 to 3 of ADV_TIMER3 (access: R/W)
#define PWM_T3_CONFIG_INSEL_BIT                                      0
#define PWM_T3_CONFIG_INSEL_WIDTH                                    8
#define PWM_T3_CONFIG_INSEL_MASK                                     0xff

// ADV_TIMER3 trigger mode configuration bitfield: - 3'h0: trigger event at each clock cycle. - 3'h1: trigger event if input source is 0 - 3'h2: trigger event if input source is 1 - 3'h3: trigger event on input source rising edge - 3'h4: trigger event on input source falling edge - 3'h5: trigger event on input source falling or rising edge - 3'h6: trigger event on input source rising edge when armed - 3'h7: trigger event on input source falling edge when armed (access: R/W)
#define PWM_T3_CONFIG_MODE_BIT                                       8
#define PWM_T3_CONFIG_MODE_WIDTH                                     3
#define PWM_T3_CONFIG_MODE_MASK                                      0x700

// ADV_TIMER3 clock source configuration bitfield: - 1'b0: FLL - 1'b1: reference clock at 32kHz (access: R/W)
#define PWM_T3_CONFIG_CLKSEL_BIT                                     11
#define PWM_T3_CONFIG_CLKSEL_WIDTH                                   1
#define PWM_T3_CONFIG_CLKSEL_MASK                                    0x800

// ADV_TIMER3 center-aligned mode configuration bitfield: - 1'b0: The counter counts up and down alternatively. - 1'b1: The counter counts up and resets to 0 when reach threshold. (access: R/W)
#define PWM_T3_CONFIG_UPDOWNSEL_BIT                                  12
#define PWM_T3_CONFIG_UPDOWNSEL_WIDTH                                1
#define PWM_T3_CONFIG_UPDOWNSEL_MASK                                 0x1000

// ADV_TIMER3 prescaler value configuration bitfield. (access: R/W)
#define PWM_T3_CONFIG_PRESC_BIT                                      16
#define PWM_T3_CONFIG_PRESC_WIDTH                                    8
#define PWM_T3_CONFIG_PRESC_MASK                                     0xff0000

// ADV_TIMER3 threshold low part configuration bitfield. It defines start counter value. (access: R/W)
#define PWM_T3_THRESHOLD_TH_LO_BIT                                   0
#define PWM_T3_THRESHOLD_TH_LO_WIDTH                                 16
#define PWM_T3_THRESHOLD_TH_LO_MASK                                  0xffff

// ADV_TIMER3 threshold high part configuration bitfield. It defines end counter value. (access: R/W)
#define PWM_T3_THRESHOLD_TH_HI_BIT                                   16
#define PWM_T3_THRESHOLD_TH_HI_WIDTH                                 16
#define PWM_T3_THRESHOLD_TH_HI_MASK                                  0xffff0000

// ADV_TIMER3 channel 0 threshold configuration bitfield. (access: R/W)
#define PWM_T3_TH_CHANNEL0_TH_BIT                                    0
#define PWM_T3_TH_CHANNEL0_TH_WIDTH                                  16
#define PWM_T3_TH_CHANNEL0_TH_MASK                                   0xffff

// ADV_TIMER3 channel 0 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set. (access: R/W)
#define PWM_T3_TH_CHANNEL0_MODE_BIT                                  16
#define PWM_T3_TH_CHANNEL0_MODE_WIDTH                                3
#define PWM_T3_TH_CHANNEL0_MODE_MASK                                 0x70000

// ADV_TIMER3 channel 1 threshold configuration bitfield. (access: R/W)
#define PWM_T3_TH_CHANNEL1_TH_BIT                                    0
#define PWM_T3_TH_CHANNEL1_TH_WIDTH                                  16
#define PWM_T3_TH_CHANNEL1_TH_MASK                                   0xffff

// ADV_TIMER3 channel 1 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set. (access: R/W)
#define PWM_T3_TH_CHANNEL1_MODE_BIT                                  16
#define PWM_T3_TH_CHANNEL1_MODE_WIDTH                                3
#define PWM_T3_TH_CHANNEL1_MODE_MASK                                 0x70000

// ADV_TIMER3 channel 2 threshold configuration bitfield. (access: R/W)
#define PWM_T3_TH_CHANNEL2_TH_BIT                                    0
#define PWM_T3_TH_CHANNEL2_TH_WIDTH                                  16
#define PWM_T3_TH_CHANNEL2_TH_MASK                                   0xffff

// ADV_TIMER3 channel 2 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set. (access: R/W)
#define PWM_T3_TH_CHANNEL2_MODE_BIT                                  16
#define PWM_T3_TH_CHANNEL2_MODE_WIDTH                                3
#define PWM_T3_TH_CHANNEL2_MODE_MASK                                 0x70000

// ADV_TIMER3 channel 3 threshold configuration bitfield. (access: R/W)
#define PWM_T3_TH_CHANNEL3_TH_BIT                                    0
#define PWM_T3_TH_CHANNEL3_TH_WIDTH                                  16
#define PWM_T3_TH_CHANNEL3_TH_MASK                                   0xffff

// ADV_TIMER3 channel 3 threshold match action on channel output signal configuration bitfield: - 3'h0: set. - 3'h1: toggle then next threshold match action is clear. - 3'h2: set then next threshold match action is clear. - 3'h3: toggle. - 3'h4: clear. - 3'h5: toggle then next threshold match action is set. - 3'h6: clear then next threshold match action is set. (access: R/W)
#define PWM_T3_TH_CHANNEL3_MODE_BIT                                  16
#define PWM_T3_TH_CHANNEL3_MODE_WIDTH                                3
#define PWM_T3_TH_CHANNEL3_MODE_MASK                                 0x70000

// ADV_TIMER output event 0 source configuration bitfiled: - 4'h0: ADV_TIMER0 channel 0. - 4'h1: ADV_TIMER0 channel 1. - 4'h2: ADV_TIMER0 channel 2. - 4'h3: ADV_TIMER0 channel 3. - 4'h4: ADV_TIMER1 channel 0. - 4'h5: ADV_TIMER1 channel 1. - 4'h6: ADV_TIMER1 channel 2. - 4'h7: ADV_TIMER1 channel 3. - 4'h8: ADV_TIMER2 channel 0. - 4'h9: ADV_TIMER2 channel 1. - 4'hA: ADV_TIMER2 channel 2. - 4'hB: ADV_TIMER2 channel 3. - 4'hC: ADV_TIMER3 channel 0. - 4'hD: ADV_TIMER3 channel 1. - 4'hE: ADV_TIMER3 channel 2. - 4'hF: ADV_TIMER3 channel 3. (access: R/W)
#define PWM_EVENT_CFG_SEL0_BIT                                       0
#define PWM_EVENT_CFG_SEL0_WIDTH                                     4
#define PWM_EVENT_CFG_SEL0_MASK                                      0xf

// ADV_TIMER output event 1 source configuration bitfiled: - 4'h0: ADV_TIMER0 channel 0. - 4'h1: ADV_TIMER0 channel 1. - 4'h2: ADV_TIMER0 channel 2. - 4'h3: ADV_TIMER0 channel 3. - 4'h4: ADV_TIMER1 channel 0. - 4'h5: ADV_TIMER1 channel 1. - 4'h6: ADV_TIMER1 channel 2. - 4'h7: ADV_TIMER1 channel 3. - 4'h8: ADV_TIMER2 channel 0. - 4'h9: ADV_TIMER2 channel 1. - 4'hA: ADV_TIMER2 channel 2. - 4'hB: ADV_TIMER2 channel 3. - 4'hC: ADV_TIMER3 channel 0. - 4'hD: ADV_TIMER3 channel 1. - 4'hE: ADV_TIMER3 channel 2. - 4'hF: ADV_TIMER3 channel 3. (access: R/W)
#define PWM_EVENT_CFG_SEL1_BIT                                       4
#define PWM_EVENT_CFG_SEL1_WIDTH                                     4
#define PWM_EVENT_CFG_SEL1_MASK                                      0xf0

// ADV_TIMER output event 2 source configuration bitfiled: - 4'h0: ADV_TIMER0 channel 0. - 4'h1: ADV_TIMER0 channel 1. - 4'h2: ADV_TIMER0 channel 2. - 4'h3: ADV_TIMER0 channel 3. - 4'h4: ADV_TIMER1 channel 0. - 4'h5: ADV_TIMER1 channel 1. - 4'h6: ADV_TIMER1 channel 2. - 4'h7: ADV_TIMER1 channel 3. - 4'h8: ADV_TIMER2 channel 0. - 4'h9: ADV_TIMER2 channel 1. - 4'hA: ADV_TIMER2 channel 2. - 4'hB: ADV_TIMER2 channel 3. - 4'hC: ADV_TIMER3 channel 0. - 4'hD: ADV_TIMER3 channel 1. - 4'hE: ADV_TIMER3 channel 2. - 4'hF: ADV_TIMER3 channel 3. (access: R/W)
#define PWM_EVENT_CFG_SEL2_BIT                                       8
#define PWM_EVENT_CFG_SEL2_WIDTH                                     4
#define PWM_EVENT_CFG_SEL2_MASK                                      0xf00

// ADV_TIMER output event 3 source configuration bitfiled: - 4'h0: ADV_TIMER0 channel 0. - 4'h1: ADV_TIMER0 channel 1. - 4'h2: ADV_TIMER0 channel 2. - 4'h3: ADV_TIMER0 channel 3. - 4'h4: ADV_TIMER1 channel 0. - 4'h5: ADV_TIMER1 channel 1. - 4'h6: ADV_TIMER1 channel 2. - 4'h7: ADV_TIMER1 channel 3. - 4'h8: ADV_TIMER2 channel 0. - 4'h9: ADV_TIMER2 channel 1. - 4'hA: ADV_TIMER2 channel 2. - 4'hB: ADV_TIMER2 channel 3. - 4'hC: ADV_TIMER3 channel 0. - 4'hD: ADV_TIMER3 channel 1. - 4'hE: ADV_TIMER3 channel 2. - 4'hF: ADV_TIMER3 channel 3. (access: R/W)
#define PWM_EVENT_CFG_SEL3_BIT                                       12
#define PWM_EVENT_CFG_SEL3_WIDTH                                     4
#define PWM_EVENT_CFG_SEL3_MASK                                      0xf000

// ADV_TIMER output event enable configuration bitfield. ENA[i]=1 enables output event i generation. (access: R/W)
#define PWM_EVENT_CFG_ENA_BIT                                        16
#define PWM_EVENT_CFG_ENA_WIDTH                                      4
#define PWM_EVENT_CFG_ENA_MASK                                       0xf0000

// ADV_TIMER clock gating configuration bitfield.  - ENA[i]=0: clock gate ADV_TIMERi. - ENA[i]=1: enable ADV_TIMERi.  (access: R/W)
#define PWM_CG_ENA_BIT                                               0
#define PWM_CG_ENA_WIDTH                                             16
#define PWM_CG_ENA_MASK                                              0xffff

#endif
