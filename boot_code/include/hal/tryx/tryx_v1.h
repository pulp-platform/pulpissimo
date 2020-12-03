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

#ifndef __HAL_TRYX_V1_H__
#define __HAL_TRYX_V1_H__

#include "archi/pulp.h"

#define DEBUG_TRYX          0
#define EVTMASK_RAB_WAKEUP  ( (unsigned)(1 << ARCHI_EVT_RAB_WAKEUP) )

/** Check if the TRYX register contains a slave error.

  \return  0 if there is no slave error; 1 if there is a slave error.
 */
static inline int pulp_tryx_has_slverr()
{
  return (*(const volatile unsigned int*)ARCHI_TRYX_ADDR & 0x1) == 0x1;
}

/** Set the TRYX register such that (1) the next memory access does not go from RAB further down
    the memory hierarchy, and (2) a (possible) RAB miss caused by the next memory access is
    flagged as prefetch in the RAB miss FIFO.
 */
static inline void pulp_tryx_set_prefetch()
{
  *(volatile unsigned int*)ARCHI_TRYX_ADDR = 0xFFFFFFFF;
}

/** Try to read from a memory address without blocking in case it produces a slave error.

  \param   addr  The address that shall be read.
  \param   val   The value in which the result shall be stored if the read is successful.

  \return  0 if the read was successful; 1 if the read caused a slave error.
 */
static inline int pulp_tryread_noblock(const unsigned int* const addr, unsigned int* const val)
{
  *val = *(const volatile unsigned*)addr;
  return pulp_tryx_has_slverr();
}

/** Try to write to a memory address without blocking in case it produces a slave error.

  \param   addr  The address to which data shall be written.
  \param   val   The value that shall be written.

  \return  0 if the write was successful; 1 if the write caused a slave error.
 */
static inline int pulp_trywrite_noblock(unsigned int* const addr, const unsigned int val)
{
  *addr = val;
  return pulp_tryx_has_slverr();
}

/** Go to sleep and wait for wake-up event.
 */
void pulp_tryx_slowpath();

/** Read from an address and block until the read completes.

  \param   addr  The address that shall be read.

  \return  The data stored at that address.
 */
static inline unsigned int pulp_tryread(const unsigned int* const addr)
{
  unsigned int val;

  int miss = pulp_tryread_noblock(addr, &val);
  while (miss) {
    pulp_tryx_slowpath();
    miss = pulp_tryread_noblock(addr, &val);
  }

  return val;
}

/** Try to read from a memory address without blocking in case it misses in the RAB and without
    causing a memory transaction. This function can be used to trigger the setup of a RAB slice
    in advance of a read.

  \param   addr  The address that shall be read-prefetched.

  \return  0 if the read would succeed (i.e., a slice in the RAB exists for this address); 1 if
           the read resulted in a RAB miss; negative value with an errno on errors.
 */
static inline int pulp_tryread_prefetch(const unsigned int* const addr)
{
  #if DEBUG_TRYX == 1
    printf("read-prefetch of address 0x%X\n",(unsigned)addr);
  #endif

  pulp_tryx_set_prefetch();

  // Issue a read through RAB.
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wunused-but-set-variable"
    const volatile unsigned int dummy = *(volatile unsigned int*)addr;
  #pragma GCC diagnostic pop

  if (pulp_tryx_has_slverr()) {
    #if DEBUG_TRYX == 1
      printf("miss on address 0x%X\n",(unsigned)addr);
    #endif
    return 1;
  }

  return 0;
}

/** Write to an address and block until the write completes.

  \param   addr  The address to which data shall be written.
  \param   val   The value that shall be written.
 */
static inline void pulp_trywrite(unsigned int* const addr, const unsigned int val)
{
  int miss = pulp_trywrite_noblock(addr, val);
  while (miss) {
    pulp_tryx_slowpath();
    miss = pulp_trywrite_noblock(addr, val);
  }

  return;
}

/** Try to write to a memory address without blocking in case it misses in the RAB and without
    causing a memory transaction. This function can be used to trigger the setup of a RAB slice
    in advance of a write.

  \param   addr  The address that shall be write-prefetched.

  \return  0 if the write would succeed (i.e., a slice in the RAB exists for this address); 1 if
           the write resulted in a RAB miss; negative value with an errno on errors.
 */
static inline int pulp_trywrite_prefetch(unsigned int* const addr)
{
  #if DEBUG_TRYX == 1
    printf("write-prefetch of address 0x%X\n",(unsigned)addr);
  #endif

  pulp_tryx_set_prefetch();

  // Issue a write through RAB (to be discarded).
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wunused-but-set-variable"
    *(volatile unsigned int*)addr = 0x5000BAD1;
  #pragma GCC diagnostic pop

  if (pulp_tryx_has_slverr()) {
    #if DEBUG_TRYX == 1
      printf("miss on address 0x%X\n",(unsigned)addr);
    #endif
    return 1;
  }

  return 0;
}

#endif
