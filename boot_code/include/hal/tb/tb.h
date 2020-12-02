/*
 * Copyright (C) 2018 ETH Zurich, University of Bologna and GreenWaves Technologies
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

#ifndef __HAL__TB__TB_H__
#define __HAL__TB__TB_H__

#include "hal/utils.h"

#define TB_CHECKER tb_checker

typedef enum {
  TB_CHECKER_REQ_NONE = 0,
  TB_CHECKER_REQ_POWER_DOMAIN_STATE_ASSERT = 1
} tb_checker_req_e;

typedef enum {
  TB_CHECKER_POWER_DOMAIN_SOC     = 0,
  TB_CHECKER_POWER_DOMAIN_CLUSTER = 1,
  TB_CHECKER_POWER_DOMAIN_CSI2    = 2,
  TB_CHECKER_POWER_DOMAIN_MRAM    = 3,
  TB_CHECKER_POWER_DOMAIN_SWAKEUP = 4,
  TB_CHECKER_POWER_DOMAIN_IO_LS   = 5,
  TB_CHECKER_POWER_DOMAIN_IO_HS_L = 6,
  TB_CHECKER_POWER_DOMAIN_IO_HS_R = 7,
  TB_CHECKER_NB_POWER_DOMAINS     = 8
} tb_checker_power_domain_id_e;

typedef enum {
  TB_CHECKER_POWER_DOMAIN_STATE_OFF                 = 0,
  TB_CHECKER_POWER_DOMAIN_STATE_ON                  = 1,
  TB_CHECKER_POWER_DOMAIN_STATE_RETENTIVE           = 2,
  TB_CHECKER_POWER_DOMAIN_STATE_PREVIOUS            = 3
} tb_checker_power_domain_state_e;


typedef struct {
  uint32_t state;
} tb_checker_power_domain_t;


typedef struct 
{
  // Request sent by the test. TB_CHECKER_REQ_NONE must be written back by the testbench
  // when the request is done
  uint32_t request;

  // For some commands like asserts, this specifies a period during which the testbench
  // should look for the required state. 0 means the state should be there when the 
  // request is seen.
  uint32_t delay;

  // Result written by the testbench before it writes TB_CHECKER_REQ_NONE to the request
  uint32_t result;

  tb_checker_power_domain_state_e power_domains[TB_CHECKER_NB_POWER_DOMAINS];

} tb_checker_t;

static void tb_checker_connect(tb_checker_t *checker)
{
}

static void tb_checker_set_domain_state(tb_checker_t *checker, tb_checker_power_domain_id_e domain, tb_checker_power_domain_state_e state)
{
  // Store the request in the shared structure seen by the testbench
  checker->power_domains[domain] = state;
}

static void tb_checker_send_assert(tb_checker_t *checker, uint32_t delay)
{
  checker->delay = delay;
  hal_compiler_barrier();
  checker->request = TB_CHECKER_REQ_POWER_DOMAIN_STATE_ASSERT;
  hal_compiler_barrier();

  apb_soc_jtag_reg_write(3<<1);
}

static int tb_checker_wait_reply(tb_checker_t *checker)
{
  // Wait until we get the reply
  while(*(volatile uint32_t *)&checker->request != TB_CHECKER_REQ_NONE);

  apb_soc_jtag_reg_write(1<<1);
  while((apb_soc_jtag_reg_ext(apb_soc_jtag_reg_read()) >> 1) != 3);

  // And propagate the request result
  return checker->result;
}

#endif
