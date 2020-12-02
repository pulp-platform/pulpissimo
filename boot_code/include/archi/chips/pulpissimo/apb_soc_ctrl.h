
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

#ifndef __INCLUDE_ARCHI_CHIPS_PULPISSIMO_APB_SOC_CTRL_H__
#define __INCLUDE_ARCHI_CHIPS_PULPISSIMO_APB_SOC_CTRL_H__

#ifndef LANGUAGE_ASSEMBLY

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS
//

// Value of pad bootsel
#define APB_SOC_BOOTSEL_OFFSET                   0xc4



//
// REGISTERS FIELDS
//



//
// REGISTERS STRUCTS
//

#ifndef LANGUAGE_ASSEMBLY

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) apb_soc_bootsel_t;

#endif



//
// REGISTERS STRUCTS
//

#ifdef __GVSOC__

class vp_apb_soc_bootsel : public vp::reg_32
{
public:
};

#endif



//
// REGISTERS GLOBAL STRUCT
//

#ifndef LANGUAGE_ASSEMBLY

typedef struct {
  unsigned int bootsel         ; // Value of pad bootsel
} __attribute__((packed)) apb_soc_apb_soc_t;

#endif



//
// REGISTERS ACCESS FUNCTIONS
//

#ifndef LANGUAGE_ASSEMBLY

static inline uint32_t apb_soc_bootsel_get(uint32_t base) { return ARCHI_READ(base, APB_SOC_BOOTSEL_OFFSET); }
static inline void apb_soc_bootsel_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, APB_SOC_BOOTSEL_OFFSET, value); }

#endif



//
// REGISTERS FIELDS MACROS
//

#ifndef LANGUAGE_ASSEMBLY

#endif

#endif
