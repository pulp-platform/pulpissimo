
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

#ifndef __INCLUDE_ARCHI_PWM_V1_PWM_V1_MACROS_H__
#define __INCLUDE_ARCHI_PWM_V1_PWM_V1_MACROS_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS FIELDS MACROS
//

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#define PWM_T0_CMD_START_GET(value)                        (ARCHI_BEXTRACTU((value),1,0))
#define PWM_T0_CMD_START_GETS(value)                       (ARCHI_BEXTRACT((value),1,0))
#define PWM_T0_CMD_START_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,0))
#define PWM_T0_CMD_START(val)                              ((val) << 0)

#define PWM_T0_CMD_STOP_GET(value)                         (ARCHI_BEXTRACTU((value),1,1))
#define PWM_T0_CMD_STOP_GETS(value)                        (ARCHI_BEXTRACT((value),1,1))
#define PWM_T0_CMD_STOP_SET(value,field)                   (ARCHI_BINSERT((value),(field),1,1))
#define PWM_T0_CMD_STOP(val)                               ((val) << 1)

#define PWM_T0_CMD_UPDATE_GET(value)                       (ARCHI_BEXTRACTU((value),1,2))
#define PWM_T0_CMD_UPDATE_GETS(value)                      (ARCHI_BEXTRACT((value),1,2))
#define PWM_T0_CMD_UPDATE_SET(value,field)                 (ARCHI_BINSERT((value),(field),1,2))
#define PWM_T0_CMD_UPDATE(val)                             ((val) << 2)

#define PWM_T0_CMD_RESET_GET(value)                        (ARCHI_BEXTRACTU((value),1,3))
#define PWM_T0_CMD_RESET_GETS(value)                       (ARCHI_BEXTRACT((value),1,3))
#define PWM_T0_CMD_RESET_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,3))
#define PWM_T0_CMD_RESET(val)                              ((val) << 3)

#define PWM_T0_CMD_ARM_GET(value)                          (ARCHI_BEXTRACTU((value),1,4))
#define PWM_T0_CMD_ARM_GETS(value)                         (ARCHI_BEXTRACT((value),1,4))
#define PWM_T0_CMD_ARM_SET(value,field)                    (ARCHI_BINSERT((value),(field),1,4))
#define PWM_T0_CMD_ARM(val)                                ((val) << 4)

#define PWM_T0_CONFIG_INSEL_GET(value)                     (ARCHI_BEXTRACTU((value),8,0))
#define PWM_T0_CONFIG_INSEL_GETS(value)                    (ARCHI_BEXTRACT((value),8,0))
#define PWM_T0_CONFIG_INSEL_SET(value,field)               (ARCHI_BINSERT((value),(field),8,0))
#define PWM_T0_CONFIG_INSEL(val)                           ((val) << 0)

#define PWM_T0_CONFIG_MODE_GET(value)                      (ARCHI_BEXTRACTU((value),3,8))
#define PWM_T0_CONFIG_MODE_GETS(value)                     (ARCHI_BEXTRACT((value),3,8))
#define PWM_T0_CONFIG_MODE_SET(value,field)                (ARCHI_BINSERT((value),(field),3,8))
#define PWM_T0_CONFIG_MODE(val)                            ((val) << 8)

#define PWM_T0_CONFIG_CLKSEL_GET(value)                    (ARCHI_BEXTRACTU((value),1,11))
#define PWM_T0_CONFIG_CLKSEL_GETS(value)                   (ARCHI_BEXTRACT((value),1,11))
#define PWM_T0_CONFIG_CLKSEL_SET(value,field)              (ARCHI_BINSERT((value),(field),1,11))
#define PWM_T0_CONFIG_CLKSEL(val)                          ((val) << 11)

#define PWM_T0_CONFIG_UPDOWNSEL_GET(value)                 (ARCHI_BEXTRACTU((value),1,12))
#define PWM_T0_CONFIG_UPDOWNSEL_GETS(value)                (ARCHI_BEXTRACT((value),1,12))
#define PWM_T0_CONFIG_UPDOWNSEL_SET(value,field)           (ARCHI_BINSERT((value),(field),1,12))
#define PWM_T0_CONFIG_UPDOWNSEL(val)                       ((val) << 12)

#define PWM_T0_CONFIG_PRESC_GET(value)                     (ARCHI_BEXTRACTU((value),8,16))
#define PWM_T0_CONFIG_PRESC_GETS(value)                    (ARCHI_BEXTRACT((value),8,16))
#define PWM_T0_CONFIG_PRESC_SET(value,field)               (ARCHI_BINSERT((value),(field),8,16))
#define PWM_T0_CONFIG_PRESC(val)                           ((val) << 16)

#define PWM_T0_THRESHOLD_TH_LO_GET(value)                  (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T0_THRESHOLD_TH_LO_GETS(value)                 (ARCHI_BEXTRACT((value),16,0))
#define PWM_T0_THRESHOLD_TH_LO_SET(value,field)            (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T0_THRESHOLD_TH_LO(val)                        ((val) << 0)

#define PWM_T0_THRESHOLD_TH_HI_GET(value)                  (ARCHI_BEXTRACTU((value),16,16))
#define PWM_T0_THRESHOLD_TH_HI_GETS(value)                 (ARCHI_BEXTRACT((value),16,16))
#define PWM_T0_THRESHOLD_TH_HI_SET(value,field)            (ARCHI_BINSERT((value),(field),16,16))
#define PWM_T0_THRESHOLD_TH_HI(val)                        ((val) << 16)

#define PWM_T0_TH_CHANNEL0_TH_GET(value)                   (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T0_TH_CHANNEL0_TH_GETS(value)                  (ARCHI_BEXTRACT((value),16,0))
#define PWM_T0_TH_CHANNEL0_TH_SET(value,field)             (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T0_TH_CHANNEL0_TH(val)                         ((val) << 0)

#define PWM_T0_TH_CHANNEL0_MODE_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define PWM_T0_TH_CHANNEL0_MODE_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define PWM_T0_TH_CHANNEL0_MODE_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define PWM_T0_TH_CHANNEL0_MODE(val)                       ((val) << 16)

#define PWM_T0_TH_CHANNEL1_TH_GET(value)                   (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T0_TH_CHANNEL1_TH_GETS(value)                  (ARCHI_BEXTRACT((value),16,0))
#define PWM_T0_TH_CHANNEL1_TH_SET(value,field)             (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T0_TH_CHANNEL1_TH(val)                         ((val) << 0)

#define PWM_T0_TH_CHANNEL1_MODE_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define PWM_T0_TH_CHANNEL1_MODE_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define PWM_T0_TH_CHANNEL1_MODE_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define PWM_T0_TH_CHANNEL1_MODE(val)                       ((val) << 16)

#define PWM_T0_TH_CHANNEL2_TH_GET(value)                   (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T0_TH_CHANNEL2_TH_GETS(value)                  (ARCHI_BEXTRACT((value),16,0))
#define PWM_T0_TH_CHANNEL2_TH_SET(value,field)             (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T0_TH_CHANNEL2_TH(val)                         ((val) << 0)

#define PWM_T0_TH_CHANNEL2_MODE_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define PWM_T0_TH_CHANNEL2_MODE_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define PWM_T0_TH_CHANNEL2_MODE_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define PWM_T0_TH_CHANNEL2_MODE(val)                       ((val) << 16)

#define PWM_T0_TH_CHANNEL3_TH_GET(value)                   (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T0_TH_CHANNEL3_TH_GETS(value)                  (ARCHI_BEXTRACT((value),16,0))
#define PWM_T0_TH_CHANNEL3_TH_SET(value,field)             (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T0_TH_CHANNEL3_TH(val)                         ((val) << 0)

#define PWM_T0_TH_CHANNEL3_MODE_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define PWM_T0_TH_CHANNEL3_MODE_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define PWM_T0_TH_CHANNEL3_MODE_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define PWM_T0_TH_CHANNEL3_MODE(val)                       ((val) << 16)

#define PWM_T1_CMD_START_GET(value)                        (ARCHI_BEXTRACTU((value),1,0))
#define PWM_T1_CMD_START_GETS(value)                       (ARCHI_BEXTRACT((value),1,0))
#define PWM_T1_CMD_START_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,0))
#define PWM_T1_CMD_START(val)                              ((val) << 0)

#define PWM_T1_CMD_STOP_GET(value)                         (ARCHI_BEXTRACTU((value),1,1))
#define PWM_T1_CMD_STOP_GETS(value)                        (ARCHI_BEXTRACT((value),1,1))
#define PWM_T1_CMD_STOP_SET(value,field)                   (ARCHI_BINSERT((value),(field),1,1))
#define PWM_T1_CMD_STOP(val)                               ((val) << 1)

#define PWM_T1_CMD_UPDATE_GET(value)                       (ARCHI_BEXTRACTU((value),1,2))
#define PWM_T1_CMD_UPDATE_GETS(value)                      (ARCHI_BEXTRACT((value),1,2))
#define PWM_T1_CMD_UPDATE_SET(value,field)                 (ARCHI_BINSERT((value),(field),1,2))
#define PWM_T1_CMD_UPDATE(val)                             ((val) << 2)

#define PWM_T1_CMD_RESET_GET(value)                        (ARCHI_BEXTRACTU((value),1,3))
#define PWM_T1_CMD_RESET_GETS(value)                       (ARCHI_BEXTRACT((value),1,3))
#define PWM_T1_CMD_RESET_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,3))
#define PWM_T1_CMD_RESET(val)                              ((val) << 3)

#define PWM_T1_CMD_ARM_GET(value)                          (ARCHI_BEXTRACTU((value),1,4))
#define PWM_T1_CMD_ARM_GETS(value)                         (ARCHI_BEXTRACT((value),1,4))
#define PWM_T1_CMD_ARM_SET(value,field)                    (ARCHI_BINSERT((value),(field),1,4))
#define PWM_T1_CMD_ARM(val)                                ((val) << 4)

#define PWM_T1_CONFIG_INSEL_GET(value)                     (ARCHI_BEXTRACTU((value),8,0))
#define PWM_T1_CONFIG_INSEL_GETS(value)                    (ARCHI_BEXTRACT((value),8,0))
#define PWM_T1_CONFIG_INSEL_SET(value,field)               (ARCHI_BINSERT((value),(field),8,0))
#define PWM_T1_CONFIG_INSEL(val)                           ((val) << 0)

#define PWM_T1_CONFIG_MODE_GET(value)                      (ARCHI_BEXTRACTU((value),3,8))
#define PWM_T1_CONFIG_MODE_GETS(value)                     (ARCHI_BEXTRACT((value),3,8))
#define PWM_T1_CONFIG_MODE_SET(value,field)                (ARCHI_BINSERT((value),(field),3,8))
#define PWM_T1_CONFIG_MODE(val)                            ((val) << 8)

#define PWM_T1_CONFIG_CLKSEL_GET(value)                    (ARCHI_BEXTRACTU((value),1,11))
#define PWM_T1_CONFIG_CLKSEL_GETS(value)                   (ARCHI_BEXTRACT((value),1,11))
#define PWM_T1_CONFIG_CLKSEL_SET(value,field)              (ARCHI_BINSERT((value),(field),1,11))
#define PWM_T1_CONFIG_CLKSEL(val)                          ((val) << 11)

#define PWM_T1_CONFIG_UPDOWNSEL_GET(value)                 (ARCHI_BEXTRACTU((value),1,12))
#define PWM_T1_CONFIG_UPDOWNSEL_GETS(value)                (ARCHI_BEXTRACT((value),1,12))
#define PWM_T1_CONFIG_UPDOWNSEL_SET(value,field)           (ARCHI_BINSERT((value),(field),1,12))
#define PWM_T1_CONFIG_UPDOWNSEL(val)                       ((val) << 12)

#define PWM_T1_CONFIG_PRESC_GET(value)                     (ARCHI_BEXTRACTU((value),8,16))
#define PWM_T1_CONFIG_PRESC_GETS(value)                    (ARCHI_BEXTRACT((value),8,16))
#define PWM_T1_CONFIG_PRESC_SET(value,field)               (ARCHI_BINSERT((value),(field),8,16))
#define PWM_T1_CONFIG_PRESC(val)                           ((val) << 16)

#define PWM_T1_THRESHOLD_TH_LO_GET(value)                  (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T1_THRESHOLD_TH_LO_GETS(value)                 (ARCHI_BEXTRACT((value),16,0))
#define PWM_T1_THRESHOLD_TH_LO_SET(value,field)            (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T1_THRESHOLD_TH_LO(val)                        ((val) << 0)

#define PWM_T1_THRESHOLD_TH_HI_GET(value)                  (ARCHI_BEXTRACTU((value),16,16))
#define PWM_T1_THRESHOLD_TH_HI_GETS(value)                 (ARCHI_BEXTRACT((value),16,16))
#define PWM_T1_THRESHOLD_TH_HI_SET(value,field)            (ARCHI_BINSERT((value),(field),16,16))
#define PWM_T1_THRESHOLD_TH_HI(val)                        ((val) << 16)

#define PWM_T1_TH_CHANNEL0_TH_GET(value)                   (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T1_TH_CHANNEL0_TH_GETS(value)                  (ARCHI_BEXTRACT((value),16,0))
#define PWM_T1_TH_CHANNEL0_TH_SET(value,field)             (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T1_TH_CHANNEL0_TH(val)                         ((val) << 0)

#define PWM_T1_TH_CHANNEL0_MODE_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define PWM_T1_TH_CHANNEL0_MODE_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define PWM_T1_TH_CHANNEL0_MODE_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define PWM_T1_TH_CHANNEL0_MODE(val)                       ((val) << 16)

#define PWM_T1_TH_CHANNEL1_TH_GET(value)                   (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T1_TH_CHANNEL1_TH_GETS(value)                  (ARCHI_BEXTRACT((value),16,0))
#define PWM_T1_TH_CHANNEL1_TH_SET(value,field)             (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T1_TH_CHANNEL1_TH(val)                         ((val) << 0)

#define PWM_T1_TH_CHANNEL1_MODE_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define PWM_T1_TH_CHANNEL1_MODE_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define PWM_T1_TH_CHANNEL1_MODE_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define PWM_T1_TH_CHANNEL1_MODE(val)                       ((val) << 16)

#define PWM_T1_TH_CHANNEL2_TH_GET(value)                   (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T1_TH_CHANNEL2_TH_GETS(value)                  (ARCHI_BEXTRACT((value),16,0))
#define PWM_T1_TH_CHANNEL2_TH_SET(value,field)             (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T1_TH_CHANNEL2_TH(val)                         ((val) << 0)

#define PWM_T1_TH_CHANNEL2_MODE_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define PWM_T1_TH_CHANNEL2_MODE_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define PWM_T1_TH_CHANNEL2_MODE_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define PWM_T1_TH_CHANNEL2_MODE(val)                       ((val) << 16)

#define PWM_T1_TH_CHANNEL3_TH_GET(value)                   (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T1_TH_CHANNEL3_TH_GETS(value)                  (ARCHI_BEXTRACT((value),16,0))
#define PWM_T1_TH_CHANNEL3_TH_SET(value,field)             (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T1_TH_CHANNEL3_TH(val)                         ((val) << 0)

#define PWM_T1_TH_CHANNEL3_MODE_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define PWM_T1_TH_CHANNEL3_MODE_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define PWM_T1_TH_CHANNEL3_MODE_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define PWM_T1_TH_CHANNEL3_MODE(val)                       ((val) << 16)

#define PWM_T2_CMD_START_GET(value)                        (ARCHI_BEXTRACTU((value),1,0))
#define PWM_T2_CMD_START_GETS(value)                       (ARCHI_BEXTRACT((value),1,0))
#define PWM_T2_CMD_START_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,0))
#define PWM_T2_CMD_START(val)                              ((val) << 0)

#define PWM_T2_CMD_STOP_GET(value)                         (ARCHI_BEXTRACTU((value),1,1))
#define PWM_T2_CMD_STOP_GETS(value)                        (ARCHI_BEXTRACT((value),1,1))
#define PWM_T2_CMD_STOP_SET(value,field)                   (ARCHI_BINSERT((value),(field),1,1))
#define PWM_T2_CMD_STOP(val)                               ((val) << 1)

#define PWM_T2_CMD_UPDATE_GET(value)                       (ARCHI_BEXTRACTU((value),1,2))
#define PWM_T2_CMD_UPDATE_GETS(value)                      (ARCHI_BEXTRACT((value),1,2))
#define PWM_T2_CMD_UPDATE_SET(value,field)                 (ARCHI_BINSERT((value),(field),1,2))
#define PWM_T2_CMD_UPDATE(val)                             ((val) << 2)

#define PWM_T2_CMD_RESET_GET(value)                        (ARCHI_BEXTRACTU((value),1,3))
#define PWM_T2_CMD_RESET_GETS(value)                       (ARCHI_BEXTRACT((value),1,3))
#define PWM_T2_CMD_RESET_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,3))
#define PWM_T2_CMD_RESET(val)                              ((val) << 3)

#define PWM_T2_CMD_ARM_GET(value)                          (ARCHI_BEXTRACTU((value),1,4))
#define PWM_T2_CMD_ARM_GETS(value)                         (ARCHI_BEXTRACT((value),1,4))
#define PWM_T2_CMD_ARM_SET(value,field)                    (ARCHI_BINSERT((value),(field),1,4))
#define PWM_T2_CMD_ARM(val)                                ((val) << 4)

#define PWM_T2_CONFIG_INSEL_GET(value)                     (ARCHI_BEXTRACTU((value),8,0))
#define PWM_T2_CONFIG_INSEL_GETS(value)                    (ARCHI_BEXTRACT((value),8,0))
#define PWM_T2_CONFIG_INSEL_SET(value,field)               (ARCHI_BINSERT((value),(field),8,0))
#define PWM_T2_CONFIG_INSEL(val)                           ((val) << 0)

#define PWM_T2_CONFIG_MODE_GET(value)                      (ARCHI_BEXTRACTU((value),3,8))
#define PWM_T2_CONFIG_MODE_GETS(value)                     (ARCHI_BEXTRACT((value),3,8))
#define PWM_T2_CONFIG_MODE_SET(value,field)                (ARCHI_BINSERT((value),(field),3,8))
#define PWM_T2_CONFIG_MODE(val)                            ((val) << 8)

#define PWM_T2_CONFIG_CLKSEL_GET(value)                    (ARCHI_BEXTRACTU((value),1,11))
#define PWM_T2_CONFIG_CLKSEL_GETS(value)                   (ARCHI_BEXTRACT((value),1,11))
#define PWM_T2_CONFIG_CLKSEL_SET(value,field)              (ARCHI_BINSERT((value),(field),1,11))
#define PWM_T2_CONFIG_CLKSEL(val)                          ((val) << 11)

#define PWM_T2_CONFIG_UPDOWNSEL_GET(value)                 (ARCHI_BEXTRACTU((value),1,12))
#define PWM_T2_CONFIG_UPDOWNSEL_GETS(value)                (ARCHI_BEXTRACT((value),1,12))
#define PWM_T2_CONFIG_UPDOWNSEL_SET(value,field)           (ARCHI_BINSERT((value),(field),1,12))
#define PWM_T2_CONFIG_UPDOWNSEL(val)                       ((val) << 12)

#define PWM_T2_CONFIG_PRESC_GET(value)                     (ARCHI_BEXTRACTU((value),8,16))
#define PWM_T2_CONFIG_PRESC_GETS(value)                    (ARCHI_BEXTRACT((value),8,16))
#define PWM_T2_CONFIG_PRESC_SET(value,field)               (ARCHI_BINSERT((value),(field),8,16))
#define PWM_T2_CONFIG_PRESC(val)                           ((val) << 16)

#define PWM_T2_THRESHOLD_TH_LO_GET(value)                  (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T2_THRESHOLD_TH_LO_GETS(value)                 (ARCHI_BEXTRACT((value),16,0))
#define PWM_T2_THRESHOLD_TH_LO_SET(value,field)            (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T2_THRESHOLD_TH_LO(val)                        ((val) << 0)

#define PWM_T2_THRESHOLD_TH_HI_GET(value)                  (ARCHI_BEXTRACTU((value),16,16))
#define PWM_T2_THRESHOLD_TH_HI_GETS(value)                 (ARCHI_BEXTRACT((value),16,16))
#define PWM_T2_THRESHOLD_TH_HI_SET(value,field)            (ARCHI_BINSERT((value),(field),16,16))
#define PWM_T2_THRESHOLD_TH_HI(val)                        ((val) << 16)

#define PWM_T2_TH_CHANNEL0_TH_GET(value)                   (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T2_TH_CHANNEL0_TH_GETS(value)                  (ARCHI_BEXTRACT((value),16,0))
#define PWM_T2_TH_CHANNEL0_TH_SET(value,field)             (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T2_TH_CHANNEL0_TH(val)                         ((val) << 0)

#define PWM_T2_TH_CHANNEL0_MODE_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define PWM_T2_TH_CHANNEL0_MODE_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define PWM_T2_TH_CHANNEL0_MODE_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define PWM_T2_TH_CHANNEL0_MODE(val)                       ((val) << 16)

#define PWM_T2_TH_CHANNEL1_TH_GET(value)                   (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T2_TH_CHANNEL1_TH_GETS(value)                  (ARCHI_BEXTRACT((value),16,0))
#define PWM_T2_TH_CHANNEL1_TH_SET(value,field)             (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T2_TH_CHANNEL1_TH(val)                         ((val) << 0)

#define PWM_T2_TH_CHANNEL1_MODE_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define PWM_T2_TH_CHANNEL1_MODE_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define PWM_T2_TH_CHANNEL1_MODE_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define PWM_T2_TH_CHANNEL1_MODE(val)                       ((val) << 16)

#define PWM_T2_TH_CHANNEL2_TH_GET(value)                   (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T2_TH_CHANNEL2_TH_GETS(value)                  (ARCHI_BEXTRACT((value),16,0))
#define PWM_T2_TH_CHANNEL2_TH_SET(value,field)             (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T2_TH_CHANNEL2_TH(val)                         ((val) << 0)

#define PWM_T2_TH_CHANNEL2_MODE_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define PWM_T2_TH_CHANNEL2_MODE_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define PWM_T2_TH_CHANNEL2_MODE_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define PWM_T2_TH_CHANNEL2_MODE(val)                       ((val) << 16)

#define PWM_T2_TH_CHANNEL3_TH_GET(value)                   (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T2_TH_CHANNEL3_TH_GETS(value)                  (ARCHI_BEXTRACT((value),16,0))
#define PWM_T2_TH_CHANNEL3_TH_SET(value,field)             (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T2_TH_CHANNEL3_TH(val)                         ((val) << 0)

#define PWM_T2_TH_CHANNEL3_MODE_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define PWM_T2_TH_CHANNEL3_MODE_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define PWM_T2_TH_CHANNEL3_MODE_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define PWM_T2_TH_CHANNEL3_MODE(val)                       ((val) << 16)

#define PWM_T3_CMD_START_GET(value)                        (ARCHI_BEXTRACTU((value),1,0))
#define PWM_T3_CMD_START_GETS(value)                       (ARCHI_BEXTRACT((value),1,0))
#define PWM_T3_CMD_START_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,0))
#define PWM_T3_CMD_START(val)                              ((val) << 0)

#define PWM_T3_CMD_STOP_GET(value)                         (ARCHI_BEXTRACTU((value),1,1))
#define PWM_T3_CMD_STOP_GETS(value)                        (ARCHI_BEXTRACT((value),1,1))
#define PWM_T3_CMD_STOP_SET(value,field)                   (ARCHI_BINSERT((value),(field),1,1))
#define PWM_T3_CMD_STOP(val)                               ((val) << 1)

#define PWM_T3_CMD_UPDATE_GET(value)                       (ARCHI_BEXTRACTU((value),1,2))
#define PWM_T3_CMD_UPDATE_GETS(value)                      (ARCHI_BEXTRACT((value),1,2))
#define PWM_T3_CMD_UPDATE_SET(value,field)                 (ARCHI_BINSERT((value),(field),1,2))
#define PWM_T3_CMD_UPDATE(val)                             ((val) << 2)

#define PWM_T3_CMD_RESET_GET(value)                        (ARCHI_BEXTRACTU((value),1,3))
#define PWM_T3_CMD_RESET_GETS(value)                       (ARCHI_BEXTRACT((value),1,3))
#define PWM_T3_CMD_RESET_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,3))
#define PWM_T3_CMD_RESET(val)                              ((val) << 3)

#define PWM_T3_CMD_ARM_GET(value)                          (ARCHI_BEXTRACTU((value),1,4))
#define PWM_T3_CMD_ARM_GETS(value)                         (ARCHI_BEXTRACT((value),1,4))
#define PWM_T3_CMD_ARM_SET(value,field)                    (ARCHI_BINSERT((value),(field),1,4))
#define PWM_T3_CMD_ARM(val)                                ((val) << 4)

#define PWM_T3_CONFIG_INSEL_GET(value)                     (ARCHI_BEXTRACTU((value),8,0))
#define PWM_T3_CONFIG_INSEL_GETS(value)                    (ARCHI_BEXTRACT((value),8,0))
#define PWM_T3_CONFIG_INSEL_SET(value,field)               (ARCHI_BINSERT((value),(field),8,0))
#define PWM_T3_CONFIG_INSEL(val)                           ((val) << 0)

#define PWM_T3_CONFIG_MODE_GET(value)                      (ARCHI_BEXTRACTU((value),3,8))
#define PWM_T3_CONFIG_MODE_GETS(value)                     (ARCHI_BEXTRACT((value),3,8))
#define PWM_T3_CONFIG_MODE_SET(value,field)                (ARCHI_BINSERT((value),(field),3,8))
#define PWM_T3_CONFIG_MODE(val)                            ((val) << 8)

#define PWM_T3_CONFIG_CLKSEL_GET(value)                    (ARCHI_BEXTRACTU((value),1,11))
#define PWM_T3_CONFIG_CLKSEL_GETS(value)                   (ARCHI_BEXTRACT((value),1,11))
#define PWM_T3_CONFIG_CLKSEL_SET(value,field)              (ARCHI_BINSERT((value),(field),1,11))
#define PWM_T3_CONFIG_CLKSEL(val)                          ((val) << 11)

#define PWM_T3_CONFIG_UPDOWNSEL_GET(value)                 (ARCHI_BEXTRACTU((value),1,12))
#define PWM_T3_CONFIG_UPDOWNSEL_GETS(value)                (ARCHI_BEXTRACT((value),1,12))
#define PWM_T3_CONFIG_UPDOWNSEL_SET(value,field)           (ARCHI_BINSERT((value),(field),1,12))
#define PWM_T3_CONFIG_UPDOWNSEL(val)                       ((val) << 12)

#define PWM_T3_CONFIG_PRESC_GET(value)                     (ARCHI_BEXTRACTU((value),8,16))
#define PWM_T3_CONFIG_PRESC_GETS(value)                    (ARCHI_BEXTRACT((value),8,16))
#define PWM_T3_CONFIG_PRESC_SET(value,field)               (ARCHI_BINSERT((value),(field),8,16))
#define PWM_T3_CONFIG_PRESC(val)                           ((val) << 16)

#define PWM_T3_THRESHOLD_TH_LO_GET(value)                  (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T3_THRESHOLD_TH_LO_GETS(value)                 (ARCHI_BEXTRACT((value),16,0))
#define PWM_T3_THRESHOLD_TH_LO_SET(value,field)            (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T3_THRESHOLD_TH_LO(val)                        ((val) << 0)

#define PWM_T3_THRESHOLD_TH_HI_GET(value)                  (ARCHI_BEXTRACTU((value),16,16))
#define PWM_T3_THRESHOLD_TH_HI_GETS(value)                 (ARCHI_BEXTRACT((value),16,16))
#define PWM_T3_THRESHOLD_TH_HI_SET(value,field)            (ARCHI_BINSERT((value),(field),16,16))
#define PWM_T3_THRESHOLD_TH_HI(val)                        ((val) << 16)

#define PWM_T3_TH_CHANNEL0_TH_GET(value)                   (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T3_TH_CHANNEL0_TH_GETS(value)                  (ARCHI_BEXTRACT((value),16,0))
#define PWM_T3_TH_CHANNEL0_TH_SET(value,field)             (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T3_TH_CHANNEL0_TH(val)                         ((val) << 0)

#define PWM_T3_TH_CHANNEL0_MODE_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define PWM_T3_TH_CHANNEL0_MODE_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define PWM_T3_TH_CHANNEL0_MODE_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define PWM_T3_TH_CHANNEL0_MODE(val)                       ((val) << 16)

#define PWM_T3_TH_CHANNEL1_TH_GET(value)                   (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T3_TH_CHANNEL1_TH_GETS(value)                  (ARCHI_BEXTRACT((value),16,0))
#define PWM_T3_TH_CHANNEL1_TH_SET(value,field)             (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T3_TH_CHANNEL1_TH(val)                         ((val) << 0)

#define PWM_T3_TH_CHANNEL1_MODE_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define PWM_T3_TH_CHANNEL1_MODE_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define PWM_T3_TH_CHANNEL1_MODE_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define PWM_T3_TH_CHANNEL1_MODE(val)                       ((val) << 16)

#define PWM_T3_TH_CHANNEL2_TH_GET(value)                   (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T3_TH_CHANNEL2_TH_GETS(value)                  (ARCHI_BEXTRACT((value),16,0))
#define PWM_T3_TH_CHANNEL2_TH_SET(value,field)             (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T3_TH_CHANNEL2_TH(val)                         ((val) << 0)

#define PWM_T3_TH_CHANNEL2_MODE_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define PWM_T3_TH_CHANNEL2_MODE_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define PWM_T3_TH_CHANNEL2_MODE_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define PWM_T3_TH_CHANNEL2_MODE(val)                       ((val) << 16)

#define PWM_T3_TH_CHANNEL3_TH_GET(value)                   (ARCHI_BEXTRACTU((value),16,0))
#define PWM_T3_TH_CHANNEL3_TH_GETS(value)                  (ARCHI_BEXTRACT((value),16,0))
#define PWM_T3_TH_CHANNEL3_TH_SET(value,field)             (ARCHI_BINSERT((value),(field),16,0))
#define PWM_T3_TH_CHANNEL3_TH(val)                         ((val) << 0)

#define PWM_T3_TH_CHANNEL3_MODE_GET(value)                 (ARCHI_BEXTRACTU((value),3,16))
#define PWM_T3_TH_CHANNEL3_MODE_GETS(value)                (ARCHI_BEXTRACT((value),3,16))
#define PWM_T3_TH_CHANNEL3_MODE_SET(value,field)           (ARCHI_BINSERT((value),(field),3,16))
#define PWM_T3_TH_CHANNEL3_MODE(val)                       ((val) << 16)

#define PWM_EVENT_CFG_SEL0_GET(value)                      (ARCHI_BEXTRACTU((value),4,0))
#define PWM_EVENT_CFG_SEL0_GETS(value)                     (ARCHI_BEXTRACT((value),4,0))
#define PWM_EVENT_CFG_SEL0_SET(value,field)                (ARCHI_BINSERT((value),(field),4,0))
#define PWM_EVENT_CFG_SEL0(val)                            ((val) << 0)

#define PWM_EVENT_CFG_SEL1_GET(value)                      (ARCHI_BEXTRACTU((value),4,4))
#define PWM_EVENT_CFG_SEL1_GETS(value)                     (ARCHI_BEXTRACT((value),4,4))
#define PWM_EVENT_CFG_SEL1_SET(value,field)                (ARCHI_BINSERT((value),(field),4,4))
#define PWM_EVENT_CFG_SEL1(val)                            ((val) << 4)

#define PWM_EVENT_CFG_SEL2_GET(value)                      (ARCHI_BEXTRACTU((value),4,8))
#define PWM_EVENT_CFG_SEL2_GETS(value)                     (ARCHI_BEXTRACT((value),4,8))
#define PWM_EVENT_CFG_SEL2_SET(value,field)                (ARCHI_BINSERT((value),(field),4,8))
#define PWM_EVENT_CFG_SEL2(val)                            ((val) << 8)

#define PWM_EVENT_CFG_SEL3_GET(value)                      (ARCHI_BEXTRACTU((value),4,12))
#define PWM_EVENT_CFG_SEL3_GETS(value)                     (ARCHI_BEXTRACT((value),4,12))
#define PWM_EVENT_CFG_SEL3_SET(value,field)                (ARCHI_BINSERT((value),(field),4,12))
#define PWM_EVENT_CFG_SEL3(val)                            ((val) << 12)

#define PWM_EVENT_CFG_ENA_GET(value)                       (ARCHI_BEXTRACTU((value),4,16))
#define PWM_EVENT_CFG_ENA_GETS(value)                      (ARCHI_BEXTRACT((value),4,16))
#define PWM_EVENT_CFG_ENA_SET(value,field)                 (ARCHI_BINSERT((value),(field),4,16))
#define PWM_EVENT_CFG_ENA(val)                             ((val) << 16)

#define PWM_CG_ENA_GET(value)                              (ARCHI_BEXTRACTU((value),16,0))
#define PWM_CG_ENA_GETS(value)                             (ARCHI_BEXTRACT((value),16,0))
#define PWM_CG_ENA_SET(value,field)                        (ARCHI_BINSERT((value),(field),16,0))
#define PWM_CG_ENA(val)                                    ((val) << 0)

#endif

#endif
