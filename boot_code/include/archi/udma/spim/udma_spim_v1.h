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

#ifndef __ARCHI_UDMA_UDMA_SPIM_V1_H__
#define __ARCHI_UDMA_UDMA_SPIM_V1_H__

#define SPIM_RX_SADDR_OFFSET             0x000
#define SPIM_RX_SIZE_OFFSET              0x004
#define SPIM_RX_CFG_OFFSET               0x008
#define SPIM_RX_INTCFG_OFFSET            0x00C

#define SPIM_TX_SADDR_OFFSET             0x010
#define SPIM_TX_SIZE_OFFSET              0x014
#define SPIM_TX_CFG_OFFSET               0x018
#define SPIM_TX_INTCFG_OFFSET            0x01C

#define SPIM_STATUS_OFFSET               0x000
#define SPIM_CLKDIV_OFFSET               0x004
#define SPIM_SPICMD_OFFSET               0x008
#define SPIM_SPIADR_OFFSET               0x00C
#define SPIM_SPILEN_OFFSET               0x010
#define SPIM_SPIDUM_OFFSET               0x014
#define SPIM_TXFIFO_OFFSET               0x018
#define SPIM_RXFIFO_OFFSET               0x01C


#define ARCHI_SPIM_WSTATUS_QWRITE         8
#define ARCHI_SPIM_WSTATUS_QREAD          4
#define ARCHI_SPIM_WSTATUS_WRITE          2
#define ARCHI_SPIM_WSTATUS_READ           1

#define ARCHI_SPIM_WSTATUS_CSKEEP_BIT     16
#define ARCHI_SPIM_WSTATUS_CS_BIT         8
#define ARCHI_SPIM_WSTATUS_RESET_BIT      4
#define ARCHI_SPIM_WSTATUS_CMD_BIT        0

#define ARCHI_SPIM_RSTATUS_DATA_RX_BIT    6
#define ARCHI_SPIM_RSTATUS_DATA_TX_BIT    5
#define ARCHI_SPIM_RSTATUS_DUMMY_BIT      4
#define ARCHI_SPIM_RSTATUS_MODE_BIT       3
#define ARCHI_SPIM_RSTATUS_ADDR_BIT       2
#define ARCHI_SPIM_RSTATUS_CMD_BIT        1
#define ARCHI_SPIM_RSTATUS_IDLE_BIT       0

#define ARCHI_SPIM_CLKDIV_DATASIZE_TX_BIT 18 
#define ARCHI_SPIM_CLKDIV_DATASIZE_RX_BIT 16  
#define ARCHI_SPIM_CLKDIV_CPHA_BIT        9
#define ARCHI_SPIM_CLKDIV_CPOL_BIT        8
#define ARCHI_SPIM_CLKDIV_CLKDIV_BIT      0

#define SPIM_CMD_RD                      0
#define SPIM_CMD_WR                      1
#define SPIM_CMD_QRD                     2
#define SPIM_CMD_QWR                     3

#endif