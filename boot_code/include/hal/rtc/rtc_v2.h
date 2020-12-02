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

#ifndef __HAL_RTC_RTC_V2_H__
#define __HAL_RTC_RTC_V2_H__

#include "hal/pulp.h"
#include "archi/rtc/rtc_v2.h"

static inline unsigned int rtc_base()
{
  return ARCHI_APB_SOC_CTRL_ADDR + APB_SOC_RTC_FIRST_REG_OFFSET;
}

#endif