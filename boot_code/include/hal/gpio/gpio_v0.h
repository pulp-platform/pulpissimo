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

#ifndef __HAL_GPIO_GPIO_V0_H__
#define __HAL_GPIO_GPIO_V0_H__

static inline void hal_gpio_set_dir(uint32_t mask, uint8_t is_out)
{
  uint32_t current = pulp_read32(GPIO_REG_PADDIR);
  if (is_out)
  {
    current |= mask;
  }
  else
  {
    current &= ~mask;
  }
  pulp_write32(GPIO_REG_PADDIR, current);
}

static inline void hal_gpio_padout_set(unsigned int value)
{
  pulp_write32(GPIO_REG_PADOUT, value);
}

static inline unsigned int hal_gpio_padout_get()
{
  return pulp_read32(GPIO_REG_PADOUT);
}

static inline void hal_gpio_set_value(uint32_t mask, uint8_t value)
{
  uint32_t current = hal_gpio_padout_get();
  if (value)
  {
    current |= mask;
  }
  else
  {
    current &= ~mask;
  }
  hal_gpio_padout_set(current);
}

static inline uint32_t hal_gpio_get_value()
{
  return pulp_read32(GPIO_REG_PADIN);
}

static inline void hal_gpio_set_pin_value(uint32_t pin, uint8_t value)
{
  uint32_t current = hal_gpio_padout_get();
  if (value)
  {
    current |= 1<<pin;
  }
  else
  {
    current &= ~(1<<pin);
  }
  hal_gpio_padout_set(current);
}

#endif