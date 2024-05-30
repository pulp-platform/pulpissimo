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


#ifndef __ARCHI_PULPISSIMO_MEMORY_MAP_H__
#define __ARCHI_PULPISSIMO_MEMORY_MAP_H__



/*
 * SOC PERIPHERALS
 */

#define ARCHI_SOC_PERIPHERALS_ADDR    0x1A100000

#define ARCHI_FC_TIMER_SIZE           0x00000800

#define ARCHI_GPIO_OFFSET             0x00001000
#define ARCHI_UDMA_OFFSET             0x00002000
#define ARCHI_APB_SOC_CTRL_OFFSET     0x00004000
#define ARCHI_SOC_EU_OFFSET           0x00006000
#define ARCHI_FC_ITC_OFFSET           0x00009800
#define ARCHI_FC_TIMER_OFFSET         0x0000B000
#define ARCHI_FC_HWPE_OFFSET          0x0000C000
#define ARCHI_STDOUT_OFFSET           0x0000F000
// Chip control port
#define ARCHI_FLL_OFFSET              0x00020000
#define ARCHI_PAD_CFG_OFFSET          0x00021000


#define ARCHI_GPIO_ADDR              ( ARCHI_SOC_PERIPHERALS_ADDR + ARCHI_GPIO_OFFSET )
#define ARCHI_UDMA_ADDR              ( ARCHI_SOC_PERIPHERALS_ADDR + ARCHI_UDMA_OFFSET )
#define ARCHI_APB_SOC_CTRL_ADDR      ( ARCHI_SOC_PERIPHERALS_ADDR + ARCHI_APB_SOC_CTRL_OFFSET )
#define ARCHI_SOC_EU_ADDR            ( ARCHI_SOC_PERIPHERALS_ADDR + ARCHI_SOC_EU_OFFSET )
#define ARCHI_FC_ITC_ADDR            ( ARCHI_SOC_PERIPHERALS_ADDR + ARCHI_FC_ITC_OFFSET )
#define ARCHI_FC_TIMER_ADDR          ( ARCHI_SOC_PERIPHERALS_ADDR + ARCHI_FC_TIMER_OFFSET )
#define ARCHI_FC_HWPE_ADDR           ( ARCHI_SOC_PERIPHERALS_ADDR + ARCHI_FC_HWPE_OFFSET )
#define ARCHI_STDOUT_ADDR            ( ARCHI_SOC_PERIPHERALS_ADDR + ARCHI_STDOUT_OFFSET )
#define ARCHI_FLL_ADDR               ( ARCHI_SOC_PERIPHERALS_ADDR + ARCHI_FLL_OFFSET )
#define ARCHI_PAD_CFG_ADDR           ( ARCHI_SOC_PERIPHERALS_ADDR + ARCHI_PAD_CFG_OFFSET )



#define ARCHI_FLL_AREA_SIZE          0x00000010




/*
 * CLUSTER
 */

#define ARCHI_CLUSTER_ADDR              0x00000000
#define ARCHI_CLUSTER_SIZE              0x00400000
#define ARCHI_CLUSTER_GLOBAL_ADDR(cid)  (0x10000000 + (cid)*ARCHI_CLUSTER_SIZE)



/*
 * CLUSTER PERIPHERALS
 */

#define ARCHI_CLUSTER_PERIPHERALS_OFFSET 0x00200000

#define ARCHI_TIMER_OFFSET               0x00000400

#define ARCHI_CLUSTER_PERIPHERALS_ADDR             ( ARCHI_CLUSTER_ADDR + ARCHI_CLUSTER_PERIPHERALS_OFFSET )
#define ARCHI_CLUSTER_PERIPHERALS_GLOBAL_ADDR(cid) ( ARCHI_CLUSTER_GLOBAL_ADDR(cid) + ARCHI_CLUSTER_PERIPHERALS_OFFSET )


#endif
