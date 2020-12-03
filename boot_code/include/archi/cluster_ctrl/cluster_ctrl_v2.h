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

#ifndef ARCHI_CLUSTER_CTRL_CLUSTER_CTRL_V2_H
#define ARCHI_CLUSTER_CTRL_CLUSTER_CTRL_V2_H

#define EOC_EOC_OFFSET          0x0
#define EOC_FETCH_OFFSET        0x8
#define EOC_CLUSTER_CFG_OFFSET  0x18
#define EOC_BOOTADDR_OFFSET     0x40
#define EOC_BOOTADDR_SIZE       0x40
#define EOC_BOOTADDR_COREID(offset) ((offset) >> 2)

#define ARCHI_CLUSTER_CTRL_EOC                      0x0
#define ARCHI_CLUSTER_CTRL_FETCH_EN                 0x8
#define ARCHI_CLUSTER_CTRL_EVENT                    0x10
#define ARCHI_CLUSTER_CTRL_CLUSTER_CFG              0x18
#define ARCHI_CLUSTER_CTRL_CLUSTER_CLK_GATE         0x20
#define ARCHI_CLUSTER_CTRL_DBG_STATUS               0x28
#define ARCHI_CLUSTER_CTRL_DBG_HALT_MASK            0x38
#define ARCHI_CLUSTER_CTRL_BOOTADDR(core)          (0x40 + 4*(core))
#define ARCHI_CLUSTER_CTRL_BOOTADDR_COREID(offset) (((offset) - ARCHI_CLUSTER_CTRL_BOOTADDR(0)) >> 2)


#endif
