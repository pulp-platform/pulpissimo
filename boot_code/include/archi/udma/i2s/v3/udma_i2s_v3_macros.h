
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

#ifndef __INCLUDE_ARCHI_UDMA_I2S_V3_UDMA_I2S_V3_MACROS_H__
#define __INCLUDE_ARCHI_UDMA_I2S_V3_UDMA_I2S_V3_MACROS_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS FIELDS MACROS
//

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#define UDMA_I2S_I2S_RX_SADDR_RX_SADDR_GET(value)          (ARCHI_BEXTRACTU((value),16,0))
#define UDMA_I2S_I2S_RX_SADDR_RX_SADDR_GETS(value)         (ARCHI_BEXTRACT((value),16,0))
#define UDMA_I2S_I2S_RX_SADDR_RX_SADDR_SET(value,field)    (ARCHI_BINSERT((value),(field),16,0))
#define UDMA_I2S_I2S_RX_SADDR_RX_SADDR(val)                ((val) << 0)

#define UDMA_I2S_I2S_RX_SIZE_RX_SIZE_GET(value)            (ARCHI_BEXTRACTU((value),17,0))
#define UDMA_I2S_I2S_RX_SIZE_RX_SIZE_GETS(value)           (ARCHI_BEXTRACT((value),17,0))
#define UDMA_I2S_I2S_RX_SIZE_RX_SIZE_SET(value,field)      (ARCHI_BINSERT((value),(field),17,0))
#define UDMA_I2S_I2S_RX_SIZE_RX_SIZE(val)                  ((val) << 0)

#define UDMA_I2S_I2S_RX_CFG_CONTINOUS_GET(value)           (ARCHI_BEXTRACTU((value),1,0))
#define UDMA_I2S_I2S_RX_CFG_CONTINOUS_GETS(value)          (ARCHI_BEXTRACT((value),1,0))
#define UDMA_I2S_I2S_RX_CFG_CONTINOUS_SET(value,field)     (ARCHI_BINSERT((value),(field),1,0))
#define UDMA_I2S_I2S_RX_CFG_CONTINOUS(val)                 ((val) << 0)

#define UDMA_I2S_I2S_RX_CFG_DATASIZE_GET(value)            (ARCHI_BEXTRACTU((value),2,1))
#define UDMA_I2S_I2S_RX_CFG_DATASIZE_GETS(value)           (ARCHI_BEXTRACT((value),2,1))
#define UDMA_I2S_I2S_RX_CFG_DATASIZE_SET(value,field)      (ARCHI_BINSERT((value),(field),2,1))
#define UDMA_I2S_I2S_RX_CFG_DATASIZE(val)                  ((val) << 1)

#define UDMA_I2S_I2S_RX_CFG_EN_GET(value)                  (ARCHI_BEXTRACTU((value),1,4))
#define UDMA_I2S_I2S_RX_CFG_EN_GETS(value)                 (ARCHI_BEXTRACT((value),1,4))
#define UDMA_I2S_I2S_RX_CFG_EN_SET(value,field)            (ARCHI_BINSERT((value),(field),1,4))
#define UDMA_I2S_I2S_RX_CFG_EN(val)                        ((val) << 4)

#define UDMA_I2S_I2S_RX_CFG_CLR_GET(value)                 (ARCHI_BEXTRACTU((value),1,5))
#define UDMA_I2S_I2S_RX_CFG_CLR_GETS(value)                (ARCHI_BEXTRACT((value),1,5))
#define UDMA_I2S_I2S_RX_CFG_CLR_SET(value,field)           (ARCHI_BINSERT((value),(field),1,5))
#define UDMA_I2S_I2S_RX_CFG_CLR(val)                       ((val) << 5)

#define UDMA_I2S_I2S_RX_CFG_PENDING_GET(value)             (ARCHI_BEXTRACTU((value),1,5))
#define UDMA_I2S_I2S_RX_CFG_PENDING_GETS(value)            (ARCHI_BEXTRACT((value),1,5))
#define UDMA_I2S_I2S_RX_CFG_PENDING_SET(value,field)       (ARCHI_BINSERT((value),(field),1,5))
#define UDMA_I2S_I2S_RX_CFG_PENDING(val)                   ((val) << 5)

#define UDMA_I2S_I2S_TX_SADDR_TX_SADDR_GET(value)          (ARCHI_BEXTRACTU((value),16,0))
#define UDMA_I2S_I2S_TX_SADDR_TX_SADDR_GETS(value)         (ARCHI_BEXTRACT((value),16,0))
#define UDMA_I2S_I2S_TX_SADDR_TX_SADDR_SET(value,field)    (ARCHI_BINSERT((value),(field),16,0))
#define UDMA_I2S_I2S_TX_SADDR_TX_SADDR(val)                ((val) << 0)

#define UDMA_I2S_I2S_TX_SIZE_TX_SIZE_GET(value)            (ARCHI_BEXTRACTU((value),17,0))
#define UDMA_I2S_I2S_TX_SIZE_TX_SIZE_GETS(value)           (ARCHI_BEXTRACT((value),17,0))
#define UDMA_I2S_I2S_TX_SIZE_TX_SIZE_SET(value,field)      (ARCHI_BINSERT((value),(field),17,0))
#define UDMA_I2S_I2S_TX_SIZE_TX_SIZE(val)                  ((val) << 0)

#define UDMA_I2S_I2S_TX_CFG_CONTINOUS_GET(value)           (ARCHI_BEXTRACTU((value),1,0))
#define UDMA_I2S_I2S_TX_CFG_CONTINOUS_GETS(value)          (ARCHI_BEXTRACT((value),1,0))
#define UDMA_I2S_I2S_TX_CFG_CONTINOUS_SET(value,field)     (ARCHI_BINSERT((value),(field),1,0))
#define UDMA_I2S_I2S_TX_CFG_CONTINOUS(val)                 ((val) << 0)

#define UDMA_I2S_I2S_TX_CFG_DATASIZE_GET(value)            (ARCHI_BEXTRACTU((value),2,1))
#define UDMA_I2S_I2S_TX_CFG_DATASIZE_GETS(value)           (ARCHI_BEXTRACT((value),2,1))
#define UDMA_I2S_I2S_TX_CFG_DATASIZE_SET(value,field)      (ARCHI_BINSERT((value),(field),2,1))
#define UDMA_I2S_I2S_TX_CFG_DATASIZE(val)                  ((val) << 1)

#define UDMA_I2S_I2S_TX_CFG_EN_GET(value)                  (ARCHI_BEXTRACTU((value),1,4))
#define UDMA_I2S_I2S_TX_CFG_EN_GETS(value)                 (ARCHI_BEXTRACT((value),1,4))
#define UDMA_I2S_I2S_TX_CFG_EN_SET(value,field)            (ARCHI_BINSERT((value),(field),1,4))
#define UDMA_I2S_I2S_TX_CFG_EN(val)                        ((val) << 4)

#define UDMA_I2S_I2S_TX_CFG_CLR_GET(value)                 (ARCHI_BEXTRACTU((value),1,5))
#define UDMA_I2S_I2S_TX_CFG_CLR_GETS(value)                (ARCHI_BEXTRACT((value),1,5))
#define UDMA_I2S_I2S_TX_CFG_CLR_SET(value,field)           (ARCHI_BINSERT((value),(field),1,5))
#define UDMA_I2S_I2S_TX_CFG_CLR(val)                       ((val) << 5)

#define UDMA_I2S_I2S_TX_CFG_PENDING_GET(value)             (ARCHI_BEXTRACTU((value),1,5))
#define UDMA_I2S_I2S_TX_CFG_PENDING_GETS(value)            (ARCHI_BEXTRACT((value),1,5))
#define UDMA_I2S_I2S_TX_CFG_PENDING_SET(value,field)       (ARCHI_BINSERT((value),(field),1,5))
#define UDMA_I2S_I2S_TX_CFG_PENDING(val)                   ((val) << 5)

#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_DIV_GET(value) (ARCHI_BEXTRACTU((value),8,0))
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_DIV_GETS(value) (ARCHI_BEXTRACT((value),8,0))
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_DIV_SET(value,field) (ARCHI_BINSERT((value),(field),8,0))
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_DIV(val)      ((val) << 0)

#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_DIV_GET(value) (ARCHI_BEXTRACTU((value),8,8))
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_DIV_GETS(value) (ARCHI_BEXTRACT((value),8,8))
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_DIV_SET(value,field) (ARCHI_BINSERT((value),(field),8,8))
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_DIV(val)       ((val) << 8)

#define UDMA_I2S_I2S_CLKCFG_SETUP_COMMON_CLK_DIV_GET(value) (ARCHI_BEXTRACTU((value),8,16))
#define UDMA_I2S_I2S_CLKCFG_SETUP_COMMON_CLK_DIV_GETS(value) (ARCHI_BEXTRACT((value),8,16))
#define UDMA_I2S_I2S_CLKCFG_SETUP_COMMON_CLK_DIV_SET(value,field) (ARCHI_BINSERT((value),(field),8,16))
#define UDMA_I2S_I2S_CLKCFG_SETUP_COMMON_CLK_DIV(val)      ((val) << 16)

#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_EN_GET(value)  (ARCHI_BEXTRACTU((value),1,24))
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_EN_GETS(value) (ARCHI_BEXTRACT((value),1,24))
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_EN_SET(value,field) (ARCHI_BINSERT((value),(field),1,24))
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_CLK_EN(val)        ((val) << 24)

#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_EN_GET(value) (ARCHI_BEXTRACTU((value),1,25))
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_EN_GETS(value) (ARCHI_BEXTRACT((value),1,25))
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_EN_SET(value,field) (ARCHI_BINSERT((value),(field),1,25))
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_CLK_EN(val)       ((val) << 25)

#define UDMA_I2S_I2S_CLKCFG_SETUP_PDM_CLK_EN_GET(value)    (ARCHI_BEXTRACTU((value),1,26))
#define UDMA_I2S_I2S_CLKCFG_SETUP_PDM_CLK_EN_GETS(value)   (ARCHI_BEXTRACT((value),1,26))
#define UDMA_I2S_I2S_CLKCFG_SETUP_PDM_CLK_EN_SET(value,field) (ARCHI_BINSERT((value),(field),1,26))
#define UDMA_I2S_I2S_CLKCFG_SETUP_PDM_CLK_EN(val)          ((val) << 26)

#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_EXT_GET(value)     (ARCHI_BEXTRACTU((value),1,28))
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_EXT_GETS(value)    (ARCHI_BEXTRACT((value),1,28))
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_EXT_SET(value,field) (ARCHI_BINSERT((value),(field),1,28))
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_EXT(val)           ((val) << 28)

#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_NUM_GET(value)     (ARCHI_BEXTRACTU((value),1,29))
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_NUM_GETS(value)    (ARCHI_BEXTRACT((value),1,29))
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_NUM_SET(value,field) (ARCHI_BINSERT((value),(field),1,29))
#define UDMA_I2S_I2S_CLKCFG_SETUP_SLAVE_NUM(val)           ((val) << 29)

#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_EXT_GET(value)    (ARCHI_BEXTRACTU((value),1,30))
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_EXT_GETS(value)   (ARCHI_BEXTRACT((value),1,30))
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_EXT_SET(value,field) (ARCHI_BINSERT((value),(field),1,30))
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_EXT(val)          ((val) << 30)

#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_NUM_GET(value)    (ARCHI_BEXTRACTU((value),1,31))
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_NUM_GETS(value)   (ARCHI_BEXTRACT((value),1,31))
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_NUM_SET(value,field) (ARCHI_BINSERT((value),(field),1,31))
#define UDMA_I2S_I2S_CLKCFG_SETUP_MASTER_NUM(val)          ((val) << 31)

#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_WORDS_GET(value)      (ARCHI_BEXTRACTU((value),3,0))
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_WORDS_GETS(value)     (ARCHI_BEXTRACT((value),3,0))
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_WORDS_SET(value,field) (ARCHI_BINSERT((value),(field),3,0))
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_WORDS(val)            ((val) << 0)

#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_BITS_GET(value)       (ARCHI_BEXTRACTU((value),5,8))
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_BITS_GETS(value)      (ARCHI_BEXTRACT((value),5,8))
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_BITS_SET(value,field) (ARCHI_BINSERT((value),(field),5,8))
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_BITS(val)             ((val) << 8)

#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_LSB_GET(value)        (ARCHI_BEXTRACTU((value),1,16))
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_LSB_GETS(value)       (ARCHI_BEXTRACT((value),1,16))
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_LSB_SET(value,field)  (ARCHI_BINSERT((value),(field),1,16))
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_LSB(val)              ((val) << 16)

#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_2CH_GET(value)        (ARCHI_BEXTRACTU((value),1,17))
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_2CH_GETS(value)       (ARCHI_BEXTRACT((value),1,17))
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_2CH_SET(value,field)  (ARCHI_BINSERT((value),(field),1,17))
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_2CH(val)              ((val) << 17)

#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_EN_GET(value)         (ARCHI_BEXTRACTU((value),1,31))
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_EN_GETS(value)        (ARCHI_BEXTRACT((value),1,31))
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_EN_SET(value,field)   (ARCHI_BINSERT((value),(field),1,31))
#define UDMA_I2S_I2S_SLV_SETUP_SLAVE_EN(val)               ((val) << 31)

#define UDMA_I2S_I2S_MST_SETUP_MASTER_WORDS_GET(value)     (ARCHI_BEXTRACTU((value),3,0))
#define UDMA_I2S_I2S_MST_SETUP_MASTER_WORDS_GETS(value)    (ARCHI_BEXTRACT((value),3,0))
#define UDMA_I2S_I2S_MST_SETUP_MASTER_WORDS_SET(value,field) (ARCHI_BINSERT((value),(field),3,0))
#define UDMA_I2S_I2S_MST_SETUP_MASTER_WORDS(val)           ((val) << 0)

#define UDMA_I2S_I2S_MST_SETUP_MASTER_BITS_GET(value)      (ARCHI_BEXTRACTU((value),5,8))
#define UDMA_I2S_I2S_MST_SETUP_MASTER_BITS_GETS(value)     (ARCHI_BEXTRACT((value),5,8))
#define UDMA_I2S_I2S_MST_SETUP_MASTER_BITS_SET(value,field) (ARCHI_BINSERT((value),(field),5,8))
#define UDMA_I2S_I2S_MST_SETUP_MASTER_BITS(val)            ((val) << 8)

#define UDMA_I2S_I2S_MST_SETUP_MASTER_LSB_GET(value)       (ARCHI_BEXTRACTU((value),1,16))
#define UDMA_I2S_I2S_MST_SETUP_MASTER_LSB_GETS(value)      (ARCHI_BEXTRACT((value),1,16))
#define UDMA_I2S_I2S_MST_SETUP_MASTER_LSB_SET(value,field) (ARCHI_BINSERT((value),(field),1,16))
#define UDMA_I2S_I2S_MST_SETUP_MASTER_LSB(val)             ((val) << 16)

#define UDMA_I2S_I2S_MST_SETUP_MASTER_2CH_GET(value)       (ARCHI_BEXTRACTU((value),1,17))
#define UDMA_I2S_I2S_MST_SETUP_MASTER_2CH_GETS(value)      (ARCHI_BEXTRACT((value),1,17))
#define UDMA_I2S_I2S_MST_SETUP_MASTER_2CH_SET(value,field) (ARCHI_BINSERT((value),(field),1,17))
#define UDMA_I2S_I2S_MST_SETUP_MASTER_2CH(val)             ((val) << 17)

#define UDMA_I2S_I2S_MST_SETUP_MASTER_EN_GET(value)        (ARCHI_BEXTRACTU((value),1,31))
#define UDMA_I2S_I2S_MST_SETUP_MASTER_EN_GETS(value)       (ARCHI_BEXTRACT((value),1,31))
#define UDMA_I2S_I2S_MST_SETUP_MASTER_EN_SET(value,field)  (ARCHI_BINSERT((value),(field),1,31))
#define UDMA_I2S_I2S_MST_SETUP_MASTER_EN(val)              ((val) << 31)

#define UDMA_I2S_I2S_PDM_SETUP_PDM_SHIFT_GET(value)        (ARCHI_BEXTRACTU((value),3,0))
#define UDMA_I2S_I2S_PDM_SETUP_PDM_SHIFT_GETS(value)       (ARCHI_BEXTRACT((value),3,0))
#define UDMA_I2S_I2S_PDM_SETUP_PDM_SHIFT_SET(value,field)  (ARCHI_BINSERT((value),(field),3,0))
#define UDMA_I2S_I2S_PDM_SETUP_PDM_SHIFT(val)              ((val) << 0)

#define UDMA_I2S_I2S_PDM_SETUP_PDM_DECIMATION_GET(value)   (ARCHI_BEXTRACTU((value),10,3))
#define UDMA_I2S_I2S_PDM_SETUP_PDM_DECIMATION_GETS(value)  (ARCHI_BEXTRACT((value),10,3))
#define UDMA_I2S_I2S_PDM_SETUP_PDM_DECIMATION_SET(value,field) (ARCHI_BINSERT((value),(field),10,3))
#define UDMA_I2S_I2S_PDM_SETUP_PDM_DECIMATION(val)         ((val) << 3)

#define UDMA_I2S_I2S_PDM_SETUP_PDM_MODE_GET(value)         (ARCHI_BEXTRACTU((value),2,13))
#define UDMA_I2S_I2S_PDM_SETUP_PDM_MODE_GETS(value)        (ARCHI_BEXTRACT((value),2,13))
#define UDMA_I2S_I2S_PDM_SETUP_PDM_MODE_SET(value,field)   (ARCHI_BINSERT((value),(field),2,13))
#define UDMA_I2S_I2S_PDM_SETUP_PDM_MODE(val)               ((val) << 13)

#define UDMA_I2S_I2S_PDM_SETUP_PDM_EN_GET(value)           (ARCHI_BEXTRACTU((value),1,31))
#define UDMA_I2S_I2S_PDM_SETUP_PDM_EN_GETS(value)          (ARCHI_BEXTRACT((value),1,31))
#define UDMA_I2S_I2S_PDM_SETUP_PDM_EN_SET(value,field)     (ARCHI_BINSERT((value),(field),1,31))
#define UDMA_I2S_I2S_PDM_SETUP_PDM_EN(val)                 ((val) << 31)

#endif

#endif
