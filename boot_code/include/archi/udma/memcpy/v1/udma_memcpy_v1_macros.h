
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

#ifndef __INCLUDE_ARCHI_UDMA_MEMCPY_V1_UDMA_MEMCPY_V1_MACROS_H__
#define __INCLUDE_ARCHI_UDMA_MEMCPY_V1_UDMA_MEMCPY_V1_MACROS_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS FIELDS MACROS
//

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#define UDMA_MEMCPY_RX_SADDR_RX_SADDR_GET(value)           (ARCHI_BEXTRACTU((value),16,0))
#define UDMA_MEMCPY_RX_SADDR_RX_SADDR_GETS(value)          (ARCHI_BEXTRACT((value),16,0))
#define UDMA_MEMCPY_RX_SADDR_RX_SADDR_SET(value,field)     (ARCHI_BINSERT((value),(field),16,0))
#define UDMA_MEMCPY_RX_SADDR_RX_SADDR(val)                 ((val) << 0)

#define UDMA_MEMCPY_RX_SIZE_RX_SIZE_GET(value)             (ARCHI_BEXTRACTU((value),17,0))
#define UDMA_MEMCPY_RX_SIZE_RX_SIZE_GETS(value)            (ARCHI_BEXTRACT((value),17,0))
#define UDMA_MEMCPY_RX_SIZE_RX_SIZE_SET(value,field)       (ARCHI_BINSERT((value),(field),17,0))
#define UDMA_MEMCPY_RX_SIZE_RX_SIZE(val)                   ((val) << 0)

#define UDMA_MEMCPY_RX_CFG_CONTINOUS_GET(value)            (ARCHI_BEXTRACTU((value),1,0))
#define UDMA_MEMCPY_RX_CFG_CONTINOUS_GETS(value)           (ARCHI_BEXTRACT((value),1,0))
#define UDMA_MEMCPY_RX_CFG_CONTINOUS_SET(value,field)      (ARCHI_BINSERT((value),(field),1,0))
#define UDMA_MEMCPY_RX_CFG_CONTINOUS(val)                  ((val) << 0)

#define UDMA_MEMCPY_RX_CFG_EN_GET(value)                   (ARCHI_BEXTRACTU((value),1,4))
#define UDMA_MEMCPY_RX_CFG_EN_GETS(value)                  (ARCHI_BEXTRACT((value),1,4))
#define UDMA_MEMCPY_RX_CFG_EN_SET(value,field)             (ARCHI_BINSERT((value),(field),1,4))
#define UDMA_MEMCPY_RX_CFG_EN(val)                         ((val) << 4)

#define UDMA_MEMCPY_RX_CFG_CLR_GET(value)                  (ARCHI_BEXTRACTU((value),1,5))
#define UDMA_MEMCPY_RX_CFG_CLR_GETS(value)                 (ARCHI_BEXTRACT((value),1,5))
#define UDMA_MEMCPY_RX_CFG_CLR_SET(value,field)            (ARCHI_BINSERT((value),(field),1,5))
#define UDMA_MEMCPY_RX_CFG_CLR(val)                        ((val) << 5)

#define UDMA_MEMCPY_RX_CFG_PENDING_GET(value)              (ARCHI_BEXTRACTU((value),1,5))
#define UDMA_MEMCPY_RX_CFG_PENDING_GETS(value)             (ARCHI_BEXTRACT((value),1,5))
#define UDMA_MEMCPY_RX_CFG_PENDING_SET(value,field)        (ARCHI_BINSERT((value),(field),1,5))
#define UDMA_MEMCPY_RX_CFG_PENDING(val)                    ((val) << 5)

#define UDMA_MEMCPY_TX_SADDR_TX_SADDR_GET(value)           (ARCHI_BEXTRACTU((value),16,0))
#define UDMA_MEMCPY_TX_SADDR_TX_SADDR_GETS(value)          (ARCHI_BEXTRACT((value),16,0))
#define UDMA_MEMCPY_TX_SADDR_TX_SADDR_SET(value,field)     (ARCHI_BINSERT((value),(field),16,0))
#define UDMA_MEMCPY_TX_SADDR_TX_SADDR(val)                 ((val) << 0)

#define UDMA_MEMCPY_TX_SIZE_TX_SIZE_GET(value)             (ARCHI_BEXTRACTU((value),17,0))
#define UDMA_MEMCPY_TX_SIZE_TX_SIZE_GETS(value)            (ARCHI_BEXTRACT((value),17,0))
#define UDMA_MEMCPY_TX_SIZE_TX_SIZE_SET(value,field)       (ARCHI_BINSERT((value),(field),17,0))
#define UDMA_MEMCPY_TX_SIZE_TX_SIZE(val)                   ((val) << 0)

#define UDMA_MEMCPY_TX_CFG_CONTINOUS_GET(value)            (ARCHI_BEXTRACTU((value),1,0))
#define UDMA_MEMCPY_TX_CFG_CONTINOUS_GETS(value)           (ARCHI_BEXTRACT((value),1,0))
#define UDMA_MEMCPY_TX_CFG_CONTINOUS_SET(value,field)      (ARCHI_BINSERT((value),(field),1,0))
#define UDMA_MEMCPY_TX_CFG_CONTINOUS(val)                  ((val) << 0)

#define UDMA_MEMCPY_TX_CFG_EN_GET(value)                   (ARCHI_BEXTRACTU((value),1,4))
#define UDMA_MEMCPY_TX_CFG_EN_GETS(value)                  (ARCHI_BEXTRACT((value),1,4))
#define UDMA_MEMCPY_TX_CFG_EN_SET(value,field)             (ARCHI_BINSERT((value),(field),1,4))
#define UDMA_MEMCPY_TX_CFG_EN(val)                         ((val) << 4)

#define UDMA_MEMCPY_TX_CFG_CLR_GET(value)                  (ARCHI_BEXTRACTU((value),1,5))
#define UDMA_MEMCPY_TX_CFG_CLR_GETS(value)                 (ARCHI_BEXTRACT((value),1,5))
#define UDMA_MEMCPY_TX_CFG_CLR_SET(value,field)            (ARCHI_BINSERT((value),(field),1,5))
#define UDMA_MEMCPY_TX_CFG_CLR(val)                        ((val) << 5)

#define UDMA_MEMCPY_TX_CFG_PENDING_GET(value)              (ARCHI_BEXTRACTU((value),1,5))
#define UDMA_MEMCPY_TX_CFG_PENDING_GETS(value)             (ARCHI_BEXTRACT((value),1,5))
#define UDMA_MEMCPY_TX_CFG_PENDING_SET(value,field)        (ARCHI_BINSERT((value),(field),1,5))
#define UDMA_MEMCPY_TX_CFG_PENDING(val)                    ((val) << 5)

#define UDMA_MEMCPY_DST_ADDR_DST_ADDR_GET(value)           (ARCHI_BEXTRACTU((value),17,0))
#define UDMA_MEMCPY_DST_ADDR_DST_ADDR_GETS(value)          (ARCHI_BEXTRACT((value),17,0))
#define UDMA_MEMCPY_DST_ADDR_DST_ADDR_SET(value,field)     (ARCHI_BINSERT((value),(field),17,0))
#define UDMA_MEMCPY_DST_ADDR_DST_ADDR(val)                 ((val) << 0)

#define UDMA_MEMCPY_SRC_ADDR_SRC_ADDR_GET(value)           (ARCHI_BEXTRACTU((value),17,0))
#define UDMA_MEMCPY_SRC_ADDR_SRC_ADDR_GETS(value)          (ARCHI_BEXTRACT((value),17,0))
#define UDMA_MEMCPY_SRC_ADDR_SRC_ADDR_SET(value,field)     (ARCHI_BINSERT((value),(field),17,0))
#define UDMA_MEMCPY_SRC_ADDR_SRC_ADDR(val)                 ((val) << 0)

#define UDMA_MEMCPY_MEM_SEL_MEM_SEL_GET(value)             (ARCHI_BEXTRACTU((value),1,0))
#define UDMA_MEMCPY_MEM_SEL_MEM_SEL_GETS(value)            (ARCHI_BEXTRACT((value),1,0))
#define UDMA_MEMCPY_MEM_SEL_MEM_SEL_SET(value,field)       (ARCHI_BINSERT((value),(field),1,0))
#define UDMA_MEMCPY_MEM_SEL_MEM_SEL(val)                   ((val) << 0)

#endif

#endif
