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

#ifndef __HAL_MAILBOX_V0_H__
#define __HAL_MAILBOX_V0_H__

#include "hal/pulp.h"
#include "archi/mailbox/mailbox_v0.h"

#define MAILBOX_VALID   (0)
#define MAILBOX_FAIL    (-1)

/** Read the status register of the mailbox.

  \return  The value of the status register of the mailbox.
 */
static inline unsigned int mailbox_status_read()
{
  return pulp_read32(MAILBOX_REG_STATUS);
}

/** Read one word from the mailbox.

  \return  The value read from the mailbox.
 */
static inline unsigned int mailbox_data_read()
{
  return pulp_read32(MAILBOX_REG_RDDATA);
}

/** Write one word to the mailbox.

  \param   value  The value to be written to the mailbox.
 */
static inline void mailbox_data_write(const unsigned int value)
{
  pulp_write32(MAILBOX_REG_WRDATA, value);
}

/** Read one word from the mailbox; block if the mailbox is currently empty.

  \param   ptr  The address to which the value read from the mailbox shall be written.

  \return  MAILBOX_VALID.
 */
int mailbox_read(unsigned int* const ptr);

/** Try to read one word from the mailbox. Poll at most t times.

  \param   ptr  The address to which the value read from the mailbox shall be written.
  \param   t    The maximum number of polling iterations.

  \return  MAILBOX_VALID if a value could be read successfully, MAILBOX_FAIL otherwise.
 */
int mailbox_read_timed(unsigned int* const ptr, const unsigned int t);

/** Write one word to the mailbox; block if the mailbox is currently full.

  \param   value  The value to be written to the mailbox.

  \return  MAILBOX_VALID.
 */
int mailbox_write(const unsigned int value);

#endif
