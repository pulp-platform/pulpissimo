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


#ifndef __ARCHI_PULP_H__
#define __ARCHI_PULP_H__

#include "archi/pulp_defs.h"
#include "archi/utils.h"

#define  __A_PULP_CHIP_INC(x) #x
#define  _A_PULP_CHIP_INC(x) __A_PULP_CHIP_INC(archi/chips/x/pulp.h)
#define  A_PULP_CHIP_INC(x) _A_PULP_CHIP_INC(x)

#if defined(PULP_CHIP_FAMILY)
#include A_PULP_CHIP_INC(PULP_CHIP_FAMILY_STR)
#else
#include A_PULP_CHIP_INC(PULP_CHIP_STR)
#endif

#endif