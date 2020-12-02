/*
 * Copyright (C) 2017 ETH Zurich and University of Bologna
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

#ifndef __HAL_UTILS_H__
#define __HAL_UTILS_H__

/** @name Bitmask Generation Macros
 *
 * @{
 */

/** Create a bitmask with one bit set.

  \param    n   The index of the bit to set.  The LSB has index 0.

  \return   Bitmask with the `n`-th bit set.
*/
#define BIT_MASK_ONE(n) (1UL << (n))

/** Create a bitmask with the lowest bits set.

  \param    n   The number of LSBs to set.

  \return   Bitmask with the `n` LSBs set.
*/
#define BIT_MASK_LSBS(n) (BIT_MASK_ONE(n) - 1)

/** Create a bitmask with a number of intermediary bits set.

  \param    start   The index of the lowest bit to set.  The LSB has index 0.
  \param    n       The number of bits to set.

  \return   Bitmask with `n` bits set starting at `start`.
*/
#define BIT_MASK_IMEDS(start, n) (BIT_MASK_LSBS(n) << (start))

//!@}

/** @name Bitfield Manipulation Macros
 *
 * @{
 */

/** Set the masked bits.

  \param    y       The bitfield to manipulate.
  \param    mask    The bitmask that defines which bits to set.

  \return   A bitfield where all bits that are set in `mask` are set and all other bits are taken
            from `y`.
*/
#define BIT_SET(y, mask) ((y) |= (mask))

/** Clear the masked bits.

  \param    y       The bitfield to manipulate.
  \param    mask    The bitmask that defines which bits to clear.

  \return   A bitfield where all bits that are set in `mask` are cleared and all other bits are
            taken from `y`.
*/
#define BIT_CLEAR(y, mask) ((y) &= ~(mask))

/** Flip the masked bits.

  \param    y       The bitfield to manipulate.
  \param    mask    The bitmask that defines which bits to flip.

  \return   A bitfield where all bits that are set in `mask` are flipped and all other bits are
            taken from `y`.
*/
#define BIT_FLIP(y, mask) ((y) ^= (mask))

/// @cond IMPLEM

// Prepare a bitmask for insertion or combining.
#define __BIT_MASK_PREP(x, start, n) (((x) & BIT_MASK_LSBS(n)) << (start))

/// @endcond

/** Get a part of a bitfield.

  \param    y       The bitfield to extract a part from.
  \param    start   The index of the least-significant bit of the part to extract.
  \param    n       The number of bits to extract.

  \return   The `n` bits starting at `start` from `y` in the LSBs.
*/
#define BIT_GET(y, start, n) (((y) >> (start)) & BIT_MASK_LSBS(n))

/** Insert one bitfield into another.

  \param    y       The target bitfield to insert into.
  \param    x       The bitfield to insert.
  \param    start   The index at which `x` shall be inserted into `y`.
  \param    n       The number of bits to insert from `x`.

  \return   `y` with `n` bits from `x` inserted starting at `start`.
*/
#define BIT_INSERT(y, x, start, n) \
    (y = ((y) & ~BIT_MASK_IMEDS(start, n)) | __BIT_MASK_PREP(x, start, n))

//!@}


static inline void hal_compiler_barrier() {
  __asm__ __volatile__ ("" : : : "memory");
}

#endif
