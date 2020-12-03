/*
 * Copyright (C) 2018 GreenWaves Technologies
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

#ifndef __HAL_RTC_H__
#define __HAL_RTC_H__

#include <hal/pulp.h>
#include "archi/vendors/dolphin/rtc.h"

//=============================================================
/*
 * For Configuring the RTC, we use the APB interface:
        * Write a Register:
            1)   Write the data (the value of this indirect Access Register) to APB_RTC_DATA_REG_ADDR
            2)   Write the register address in APB_RTC_CTRL_REG_ADDR[0:5]
            3)   Set the write bit APB_RTC_CTRL_REG_ADDR[16] to 1

        * Read a Register:
            1)   Write the register address in APB_RTC_CTRL_REG_ADDR[0:5]
            2)   Set the write bit APB_RTC_CTRL_REG_ADDR[16] to 0
            3)   Read the value of the register from APB_RTC_DATA_REG_ADDR
 */

static inline unsigned int rt_apb_rtc_reg_read (unsigned int addr){
    return pulp_read32(addr);
}

static inline void rt_apb_rtc_reg_write(unsigned int addr, unsigned int conf){
    pulp_write32(addr, conf);
}

#endif
