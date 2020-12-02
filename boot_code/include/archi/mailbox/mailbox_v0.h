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


#ifndef __ARCHI_MAILBOX_V0_H__
#define __ARCHI_MAILBOX_V0_H__

#if PULP_CHIP_FAMILY != CHIP_BIGPULP
#error This file must be included only for bigpulp chip
#endif

/* MAILBOX REGISTERS */
#define MAILBOX_REG_WRDATA            ( ARCHI_MAILBOX_BASE_ADDR + 0x0 )
#define MAILBOX_REG_RDDATA            ( ARCHI_MAILBOX_BASE_ADDR + 0x8 )
#define MAILBOX_REG_STATUS            ( ARCHI_MAILBOX_BASE_ADDR + 0x10)
#define MAILBOX_REG_ERROR             ( ARCHI_MAILBOX_BASE_ADDR + 0x14)
#define MAILBOX_REG_IS                ( ARCHI_MAILBOX_BASE_ADDR + 0x20)
#define MAILBOX_REG_IE                ( ARCHI_MAILBOX_BASE_ADDR + 0x24)

/* SIGNALING */
#define PULP_READY                    ( 0x01U   )
#define PULP_START                    ( 0x02U   )
#define PULP_BUSY                     ( 0x03U   )
#define PULP_DONE                     ( 0x04U   )
#define PULP_STOP                     ( 0x0FU   )

#define HOST_READY                    ( 0x1000U )
#define HOST_DONE                     ( 0x3000U )

#define MBOX_N_BITS_REQ_TYPE          ( 4U )  // number of MSBs to specify the type
#define RAB_UPDATE_N_BITS_ELEM        ( 8U )  // number of bits to specify the mask of elements to be updated
#define RAB_UPDATE_N_BITS_TYPE        ( 2U )  // number of bits to specify the update type

#define TO_RUNTIME                    ( 0x10000000U ) // bypass PULP driver
#define RAB_UPDATE                    ( 0x20000000U ) // handled by PULP driver
#define RAB_SWITCH                    ( 0x30000000U ) // handled by PULP driver

#endif
