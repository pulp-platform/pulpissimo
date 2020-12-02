/*
 * Copyright (C) 2018 ETH Zurich and University of Bologna
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

#ifndef __HAL_MAESTRO_PMU_V3_H__
#define __HAL_MAESTRO_PMU_V3_H__

#include "hal/pulp.h"
#include "archi/maestro/maestro_v3.h"


#define PMU_PICL_PACK(chipsel,addr) (((chipsel) << 5) | (addr))
#define PMU_DLC_PACK(state,picl) (((state) << 16) | ((picl) << 1) | 0x1); //write 0x2 at picl_reg



#define PMU_WRITE(offset, value) IP_WRITE(ARCHI_PMU_ADDR, offset, value)
#define PMU_READ(offset) IP_READ(ARCHI_PMU_ADDR, offset)



static inline void maestro_picl_write(unsigned int island, unsigned int addr, unsigned int value)
{
  unsigned int picl_reg = PMU_PICL_PACK(island, addr);
  unsigned int dlc_reg = PMU_DLC_PACK(value, picl_reg);
  PMU_WRITE(MAESTRO_DLC_PCTRL_OFFSET, dlc_reg);
}


static inline __attribute__((always_inline)) void maestro_trigger_sequence(unsigned int seq)
{
  // Compute the right register ID / bit shift as each WIU IFR register is 8 bits wide
  int reg_id = MAESTRO_WIU_IFR_0_OFFSET + (seq >> 3);
  int seq_id = seq & 0x7;

  maestro_picl_write(MAESTRO_WIU_OFFSET, reg_id, 1<<seq_id);
}


static inline void maestro_icu_set_state(int island, unsigned int state)
{
  maestro_picl_write(island, MAESTRO_ICU_CTRL_OFFSET, state);
}



#define ARCHI_PMU_SAFE_ID     2
#define ARCHI_PMU_MRAMIO_ID   3
#define ARCHI_PMU_MRAMCORE_ID 4
#define ARCHI_PMU_IO_LS_ID    5
#define ARCHI_PMU_SWAFE_ID    6
#define ARCHI_PMU_SOC_ID      7
#define ARCHI_PMU_CLU_ID      8
#define ARCHI_PMU_IO_HS_ID    9
#define ARCHI_PMU_CSI2_ID     10



// TODO deprecated, should be removed asap

/* APB Interface */
#define ARCHI_PCTRL_OFFSET                   0x0
#define ARCHI_PRDATA_OFFSET                  0x4
#define ARCHI_DLC_SR_OFFSET                  0x8
#define ARCHI_DLC_IMR_OFFSET                 0xC
#define ARCHI_DLC_IFR_OFFSET                 0x10
#define ARCHI_DLC_IOIFR_OFFSET               0x14
#define ARCHI_DLC_IDIFR_OFFSET               0x18
#define ARCHI_DLC_IMCIFR_OFFSET              0x1C

#define ARCHI_PMU_CS_DLC      0x00
#define ARCHI_PMU_CS_WIU      0x01
#define ARCHI_PMU_CS_ICU0     0x02
#define ARCHI_PMU_CS_ICU1     0x03
#define ARCHI_PMU_CS_ICU2     0x04
#define ARCHI_PMU_CS_ICU3     0x05

#define ARCHI_PMU_WIU_ISPMR_0 0x00
#define ARCHI_PMU_WIU_ISPMR_1 0x01
#define ARCHI_PMU_WIU_IFR_0   0x02
#define ARCHI_PMU_WIU_IFR_1   0x03
#define ARCHI_PMU_WIU_ICR_0   0x04
#define ARCHI_PMU_WIU_ICR_1   0x05
#define ARCHI_PMU_WIU_ICR_2   0x06
#define ARCHI_PMU_WIU_ICR_3   0x07
#define ARCHI_PMU_WIU_ICR_4   0x08
#define ARCHI_PMU_WIU_ICR_5   0x09
#define ARCHI_PMU_WIU_ICR_6   0x0A
#define ARCHI_PMU_WIU_ICR_7   0x0B
#define ARCHI_PMU_WIU_ICR_8   0x0C
#define ARCHI_PMU_WIU_ICR_9   0x0D
#define ARCHI_PMU_WIU_ICR_10  0x0E
#define ARCHI_PMU_WIU_ICR_11  0x0F
#define ARCHI_PMU_WIU_ICR_12  0x10
#define ARCHI_PMU_WIU_ICR_13  0x11
#define ARCHI_PMU_WIU_ICR_14  0x12
#define ARCHI_PMU_WIU_ICR_15  0x13

#define ARCHI_PMU_STATE_SOC_NV_CLU_OFF 0x01
#define ARCHI_PMU_STATE_SOC_LV_CLU_OFF 0x02
#define ARCHI_PMU_STATE_SOC_NV_CLU_NV  0x04
#define ARCHI_PMU_STATE_SOC_LV_CLU_LV  0x08
#define ARCHI_PMU_STATE_DEEP_SLEEP     0x10
#define ARCHI_PMU_STATE_RETENTIVE      0x20


#endif