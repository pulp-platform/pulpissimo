/*
 * Copyright (C) 2018 ETH Zurich, University of Bologna
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

#ifndef __ARCHI_EU_EU_V1_H_
#define __ARCHI_EU_EU_V1_H_

#define PULP_CKG_MAX_NB_BARRIERS          18

#define PULP_NB_GP_EVENTS                 3
 // TODO this is wrong should be 1 !!!
#define PULP_FIRST_GP_EVENT               0
#define PULP_HW_BAR_EVENT                 0
 

#define PULP_DEMUX_CORE_CLKGATE_OFFSET     0x0
#define PULP_DEMUX_EV_BUFFER_CLEAR_OFFSET  0x4

#define PULP_BODYBIAS_SRAM0_OFFSET        0x0
#define PULP_BODYBIAS_SRAM1_OFFSET        0x4
#define PULP_BODYBIAS_SRAM2_OFFSET        0x8
#define PULP_BODYBIAS_SRAM3_OFFSET        0xC
#define PULP_BODYBIAS_CORE0_OFFSET        0x10
#define PULP_BODYBIAS_CORE1_OFFSET        0x14
#define PULP_BODYBIAS_CORE2_OFFSET        0x18
#define PULP_BODYBIAS_CORE3_OFFSET        0x1C

#define PULP_CLKGATE_SRAM0_OFFSET         0x100
#define PULP_CLKGATE_SRAM1_OFFSET         0x104
#define PULP_CLKGATE_SRAM2_OFFSET         0x108
#define PULP_CLKGATE_SRAM3_OFFSET         0x10C
#define PULP_CLKGATE_SCM_OFFSET           0x124
#define PULP_CLKGATE_STATUS               0x170

#define PULP_CLKGATE_TRIGG_BARRIER        0x35c
#define PULP_CLKGATE_WAIT_BARRIER         0x36c
#define PULP_CLKGATE_SET_BARRIER          0x374
#define PULP_CLKGATE_SET_BARRIER_SIZE     (0x4*PULP_CKG_MAX_NB_BARRIERS)


#define PULP_EV_MASK_LOW                  0x100
#define PULP_EV_MASK_LOW_SIZE             0x040

#define PULP_EV_BUFFER_LOW                0x180
#define PULP_EV_BUFFER_LOW_SIZE           0x040

#define PULP_CORE_CLKGATE                 0x308

#define PULP_EVNT_GEN                     0x30C

#define PULP_EVNT_GEN_GP0                 0x360
#define PULP_EVNT_GEN_GP1                 0x364
#define PULP_EVNT_GEN_GP2                 0x368


#define PULP_DEMUX_IRQ_BUFFER_CLEAR_OFFSET 0x8
#define PULP_IRQ_MASK_LOW_BASE             0X200
#define PULP_IRQ_MASK_LOW_SIZE             0X040
#define PULP_IRQ_MASK_HIGH_BASE            0X240
#define PULP_IRQ_MASK_HIGH_SIZE            0X040
#define PULP_IRQ_BUFFER_LOW_BASE           0X280
#define PULP_IRQ_BUFFER_LOW_SIZE           0X040
#define PULP_IRQ_BUFFER_HIGH_BASE          0X2C0
#define PULP_IRQ_BUFFER_HIGH_SIZE          0X040

#define PULP_READ_IRQ_ID_BASE                    0X31C
#define PULP_READ_IRQ_ID_SIZE                    0X040


#endif