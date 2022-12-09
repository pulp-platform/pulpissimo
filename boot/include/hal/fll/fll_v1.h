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

#ifndef __HAL_FLL_FLL_V1_H__
#define __HAL_FLL_FLL_V1_H__

#include "hal/pulp.h"
#include "archi/fll/fll_v1.h"
#include "hal/pulp_io.h"


typedef enum {
  FLL_SOC=0,
  FLL_CLUSTER=1,
} hal_fll_e;



static inline int fll_addr(int fll)
{
  return ARCHI_SOC_PERIPHERALS_ADDR + ARCHI_FLL_OFFSET + fll*ARCHI_FLL_AREA_SIZE;
}


static inline void fll_status_set(int base, int value)
{
  IP_WRITE(base, FLL_STATUS_OFFSET, value);
}

static inline int fll_status_get(int base)
{
  return IP_READ(base, FLL_STATUS_OFFSET);
}


static inline void fll_conf1_set(int base, int value)
{
  IP_WRITE(base, FLL_CONF1_OFFSET, value);
}

static inline int fll_conf1_get(int base)
{
  return IP_READ(base, FLL_CONF1_OFFSET);
}


static inline void fll_conf2_set(int base, int value)
{
  IP_WRITE(base, FLL_CONF2_OFFSET, value);
}

static inline int fll_conf2_get(int base)
{
  return IP_READ(base, FLL_CONF2_OFFSET);
}





typedef enum {
        FLL_CONFIG1=0,
        FLL_CONFIG2=1,
        FLL_INTEGRATOR=2,
} hal_fll_config_e;


#define N_FLL     2


static inline unsigned int GetFllStatus(int Fll)
{
    return (unsigned int) IP_READ((int *) ARCHI_FLL_ADDR, (int) (FLL_STATUS_OFFSET));
}

static inline unsigned int GetFllConfiguration(int Fll, hal_fll_config_e Reg) {
        int Offset = (int) (FLL_CONF1_OFFSET + Reg*4 + Fll*ARCHI_FLL_AREA_SIZE);
        return (unsigned int) IP_READ(ARCHI_FLL_ADDR, Offset);
}

static inline void SetFllConfiguration(int Fll, hal_fll_config_e Reg, unsigned int Value) {
        IP_WRITE(ARCHI_FLL_ADDR, FLL_CONF1_OFFSET + Reg*4 + Fll*ARCHI_FLL_AREA_SIZE, Value);
}

static inline unsigned int hal_fll_status_reg_get(int fll)
{
  return IP_READ(
    ARCHI_FLL_ADDR, 
    FLL_STATUS_OFFSET + fll*ARCHI_FLL_AREA_SIZE
  );
}

static inline void hal_fll_conf_reg1_set(int fll, unsigned int value)
{
  IP_WRITE(
    ARCHI_FLL_ADDR, 
    FLL_CONF1_OFFSET + fll*ARCHI_FLL_AREA_SIZE,
    value
  );
}

static inline unsigned int hal_fll_conf_reg1_get(int fll)
{
  return IP_READ(
    ARCHI_FLL_ADDR, 
    FLL_CONF1_OFFSET + fll*ARCHI_FLL_AREA_SIZE
  );
}

static inline void hal_fll_conf_reg2_set(int fll, unsigned int value)
{
  IP_WRITE(
    ARCHI_FLL_ADDR, 
    FLL_CONF2_OFFSET + fll*ARCHI_FLL_AREA_SIZE,
    value
  );
}

static inline unsigned int hal_fll_conf_reg2_get(int fll)
{
  return IP_READ(
    ARCHI_FLL_ADDR, 
    FLL_CONF2_OFFSET + fll*ARCHI_FLL_AREA_SIZE
  );
}

static inline void hal_fll_integrator_set(int fll, unsigned int value)
{
  IP_WRITE(
    ARCHI_FLL_ADDR, 
    FLL_INTEGRATOR_OFFSET + fll*ARCHI_FLL_AREA_SIZE,
    value
  );
}

static inline unsigned int hal_fll_integrator_get(int fll)
{
  return IP_READ(
    ARCHI_FLL_ADDR, 
    FLL_INTEGRATOR_OFFSET + fll*ARCHI_FLL_AREA_SIZE
  );
}


static inline void hal_fll_update_mult_div(int fll, int mult, int div)
{  
  fll_reg_conf1_t reg = { .raw = hal_fll_conf_reg1_get(fll) };
  reg.mult_factor = mult;
  reg.clock_out_divider = div;
  hal_fll_conf_reg1_set(fll, reg.raw);
}

#endif
