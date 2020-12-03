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

#ifndef __HAL_GPIO_GPIO_V3_H__
#define __HAL_GPIO_GPIO_V3_H__

#include "archi/gpio/gpio_v3.h"

#define ARCHI_GPIO_PADDIR_IN  0
#define ARCHI_GPIO_PADDIR_OUT 1

#define ARCHI_GPIO_INTTYPE_RISE          1
#define ARCHI_GPIO_INTTYPE_FALL          0
#define ARCHI_GPIO_INTTYPE_RISE_AND_FALL 2

#define ARCHI_GPIO_INTTYPE_NO(gpio)      ((gpio) >> 4)
#define ARCHI_GPIO_INTTYPE_GPIO(inttype) ((inttype)*16)
#define ARCHI_GPIO_INTTYPE_SIZE          2
#define ARCHI_GPIO_INTTYPE_BIT(pad)      (((pad) & 0xF) << 1)
#define ARCHI_GPIO_INTTYPE_GET(gpio,value) (((value) >> ARCHI_GPIO_INTTYPE_BIT(gpio)) & ((1<<ARCHI_GPIO_INTTYPE_SIZE) - 1))

#if 0
static inline uint32_t gpio_padcfg_get(int group)
{
  return IP_READ(ARCHI_SOC_PERIPHERALS_ADDR + ARCHI_GPIO_OFFSET, ARCHI_GPIO_PADCFG(group));
}

static inline void gpio_padcfg_set(int group, uint32_t value)
{
  IP_WRITE(ARCHI_SOC_PERIPHERALS_ADDR + ARCHI_GPIO_OFFSET, ARCHI_GPIO_PADCFG(group), value);
}

static inline void gpio_padcfg_strength_pin_set(int gpio, unsigned int val)
{
  int reg_id = ARCHI_GPIO_PADCFG_REG(gpio);
  int group = ARCHI_GPIO_PADCFG_GROUP(gpio);
  gpio_reg_padcfg_t reg = { .raw=gpio_padcfg_get(reg_id) };
  reg.pin[group].strength = val;
  gpio_padcfg_set(reg_id, reg.raw);
}

static inline void gpio_padcfg_pull_pin_set(int gpio, unsigned int val)
{
  int reg_id = ARCHI_GPIO_PADCFG_REG(gpio);
  int group = ARCHI_GPIO_PADCFG_GROUP(gpio);
  gpio_reg_padcfg_t reg = { .raw=gpio_padcfg_get(reg_id) };
  reg.pin[group].pull = val;
  gpio_padcfg_set(reg_id, reg.raw);
}


static inline void hal_gpio_paddir_set(unsigned int value)
{
  pulp_write32(ARCHI_GPIO_ADDR + ARCHI_GPIO_PADDIR, value);
}

static inline unsigned int hal_gpio_paddir_get()
{
  return pulp_read32(ARCHI_GPIO_ADDR + ARCHI_GPIO_PADDIR);
}

static inline unsigned int hal_gpio_padin_get()
{
  return pulp_read32(ARCHI_GPIO_ADDR + ARCHI_GPIO_PADIN);
}

static inline void hal_gpio_padout_set(unsigned int value)
{
  pulp_write32(ARCHI_GPIO_ADDR + ARCHI_GPIO_PADOUT, value);
}

static inline unsigned int hal_gpio_padout_get()
{
  return pulp_read32(ARCHI_GPIO_ADDR + ARCHI_GPIO_PADOUT);
}

static inline void hal_gpio_inten_set(unsigned int value)
{
  pulp_write32(ARCHI_GPIO_ADDR + ARCHI_GPIO_INTEN, value);
}

static inline unsigned int hal_gpio_inten_get()
{
  return pulp_read32(ARCHI_GPIO_ADDR + ARCHI_GPIO_INTEN);
}
#endif

static inline void hal_gpio_inttype_set(unsigned int id, unsigned int value)
{
  if (id == 0)
    return gpio_inttype0_set(ARCHI_GPIO_ADDR, value);
  else
    return gpio_inttype1_set(ARCHI_GPIO_ADDR, value);
}



static inline unsigned int hal_gpio_inttype_get(unsigned int id)
{
  if (id == 0)
    return gpio_inttype0_get(ARCHI_GPIO_ADDR);
  else
    return gpio_inttype1_get(ARCHI_GPIO_ADDR);
}


#if 0
static inline unsigned int hal_gpio_intstatus_get()
{
  return pulp_read32(ARCHI_GPIO_ADDR + ARCHI_GPIO_INTSTATUS);
}
#endif



static inline unsigned int hal_gpio_en_get()
{
  return gpio_gpioen_get(ARCHI_GPIO_ADDR);
}



static inline void hal_gpio_en_set(unsigned int value)
{
  gpio_gpioen_set(ARCHI_GPIO_ADDR, value);
}


static inline void hal_gpio_set_dir(uint32_t mask, uint8_t is_out)
{
  uint32_t current = gpio_paddir_get(ARCHI_GPIO_ADDR);
  if (is_out)
  {
    current |= mask;
  }
  else
  {
    current &= ~mask;
  }
  gpio_paddir_set(ARCHI_GPIO_ADDR, current);
}

static inline void hal_gpio_set_value(uint32_t mask, uint8_t value)
{
  uint32_t current = gpio_padout_get(ARCHI_GPIO_ADDR);
  if (value)
  {
    current |= mask;
  }
  else
  {
    current &= ~mask;
  }
  gpio_padout_set(ARCHI_GPIO_ADDR, current);
}


static inline uint32_t hal_gpio_get_value()
{
  return gpio_padout_get(ARCHI_GPIO_ADDR);
}



static inline void hal_gpio_set_pin_value(uint32_t pin, uint8_t value)
{
  uint32_t current = gpio_padout_get(ARCHI_GPIO_ADDR);
  if (value)
  {
    current |= 1<<pin;
  }
  else
  {
    current &= ~(1<<pin);
  }
  gpio_padout_set(ARCHI_GPIO_ADDR, current);
}

#endif