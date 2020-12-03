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


#ifndef __ARCHI_UTILS_H__
#define __ARCHI_UTILS_H__


#define __ARCHI_DEF_REG_STR(x) #x
#define _ARCHI_DEF_REG_MASK(x) __ARCHI_DEF_REG_STR(x ## _MASK ARCHI_REG_MASK(x ## _BIT, x ## _BITS))
#define ARCHI_DEF_REG_MASK(x) _ARCHI_DEF_REF_MASK(x)

#define _ARCHI_DEF_REG_VALUE(x, vname, val) __ARCHI_DEF_REG_STR(x ## _ ## vname  (val << (x ## _BIT)))
#define ARCHI_DEF_REG_VALUE(x, vname, val) _ARCHI_DEF_REG_VALUE(x, vname, val)


// Generate register mask given offset and size of bitfield
#define ARCHI_REG_MASK(offset,size) (((1<<(size))-1) << (offset))

// Generate register value given current (full) register value, register field value, offset and size of bitfield
#define ARCHI_REG_FIELD_SET(fullValue,value,offset,size) (((fullValue) & ~ARCHI_REG_MASK(offset, size)) | ((value) << (offset)))

// Get register field value given current (full) register value, offset and size of bitfield
#define ARCHI_REG_FIELD_GET(fullValue,offset,size) (((fullValue) & ARCHI_REG_MASK(offset, size)) >> (offset))


#ifndef LANGUAGE_ASSEMBLY

#define archi_write8(add, val_)  (*(volatile unsigned char *)(long)(add) = val_)
#define archi_write16(add, val_) (*(volatile unsigned short *)(long)(add) = val_)
#define archi_write32(add, val_) (*(volatile unsigned int *)(long)(add) = val_)
#define archi_write(add, val_)   (*(volatile unsigned int *)(long)(add) = val_)

#define archi_read8(add)         (*(volatile unsigned char *)(long)(add))
#define archi_read16(add)        (*(volatile unsigned short *)(long)(add))
#define archi_read32(add)        (*(volatile unsigned int *)(long)(add))
#define archi_read(add)          (*(volatile unsigned int *)(long)(add))


#if defined(__riscv__) && !defined(__LLVM__) && !defined(RV_ISA_RV32)
#define ARCHI_WRITE_VOL(base, offset, value) __builtin_pulp_write_base_off_v((value), (base), (offset))
#define ARCHI_WRITE(base, offset, value)     __builtin_pulp_OffsetedWrite((value), (int *)(base), (offset))
#define ARCHI_READ(base, offset)             __builtin_pulp_OffsetedRead((int *)(base), (offset))
#else
#define ARCHI_WRITE_VOL(base, offset, value) archi_write32((base) + (offset), (value))
#define ARCHI_WRITE(base, offset, value)     archi_write32((base) + (offset), (value))
#define ARCHI_READ(base, offset)             archi_read32((base) + (offset))
#endif


#include "archi/riscv/builtins_v2.h"
#include "archi/riscv/builtins_v2_emu.h"

#define ARCHI_BINSERT(dst,src,size,off)  __BITINSERT(dst,src,size,off)
#define ARCHI_BINSERT_R(dst,src,size,off)  __BITINSERT_R(dst,src,size,off)
#define ARCHI_BEXTRACTU(src,size,off)    __BITEXTRACTU(src,size,off)
#define ARCHI_BEXTRACT(src,size,off)     __BITEXTRACT(src,size,off)

#endif

#endif