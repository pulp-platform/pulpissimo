/*
 * Copyright (C) 2019 ETH Zurich, University of Bologna
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

#ifndef __HAL_RISCV_BUILTINS_V2_H__
#define __HAL_RISCV_BUILTINS_V2_H__
#ifdef ARCHI_CORE_HAS_PULPV2
/* ARITHMETIC SECTION */
typedef   signed short v2s __attribute__((vector_size (4)));
typedef unsigned short v2u __attribute__((vector_size (4)));

typedef   signed char  v4s __attribute__((vector_size (4)));
typedef unsigned char  v4u __attribute__((vector_size (4)));

#ifdef __EMUL__
typedef void * rt_pointerT;
#else
typedef unsigned int rt_pointerT;
#endif
/* Packing of scalars into vectors */
#define __PACK2(x, y)		__builtin_pulp_pack2((signed short)   (x), (signed short)   (y))
#define __PACKU2(x, y)		__builtin_pulp_pack2((unsigned short) (x), (unsigned short) (y))

#define __PACK4(x, y, z, t)		__builtin_pulp_pack4((signed char)   (x), (signed char)   (y), (signed char)   (z), (signed char)   (t))
#define __PACKU4(x, y, z, t)		__builtin_pulp_pack4((unsigned char) (x), (unsigned char) (y), (unsigned char) (z), (unsigned char) (t))

/* Max */
#define __MAX(a, b)         __builtin_pulp_maxsi((a), (b))

#define __MAX2(x, y) 		__builtin_pulp_max2((x), (y))
#define __MAX4(x, y) 		__builtin_pulp_max4((x), (y))

#define __MAXU2(x, y) 		__builtin_pulp_maxu2((x), (y))
#define __MAXU4(x, y) 		__builtin_pulp_maxu4((x), (y))

/* Min */
#define __MIN2(x, y) 		__builtin_pulp_min2((x), (y))
#define __MIN4(x, y) 		__builtin_pulp_min4((x), (y))

#define __MINU2(x, y) 		__builtin_pulp_minu2((x), (y))
#define __MINU4(x, y) 		__builtin_pulp_minu4((x), (y))

/* Clip */
#define __CLIP(x, precision) 	__builtin_pulp_clip((x), -(1<<(precision)), (1<<precision)-1)
#define __CLIP_R(x, bound) 		__builtin_pulp_clip_r((x), (bound))

#define __CLIPU(x, precision) 	__builtin_pulp_clipu((x), 0, (1<<precision)-1)
#define __CLIPU_R(x, bound) 		__builtin_pulp_clipu_r((x), (bound))

/* Abs */
#define __ABS2(x) 			__builtin_pulp_abs2((x))
#define __ABS4(x) 			__builtin_pulp_abs4((x))

/* Unary minus */
#define __NEG2(x) 			__builtin_pulp_neg2((x))
#define __NEG4(x) 			__builtin_pulp_neg4((x))

/* Addition */
#define __ADD2(x, y) 		__builtin_pulp_add2((x), (y))
#define __ADD4(x, y) 		__builtin_pulp_add4((x), (y))

/* Substraction */
#define __SUB2(x, y) 		__builtin_pulp_sub2((x), (y))
#define __SUB4(x, y) 		__builtin_pulp_sub4((x), (y))

/* Average */
#define __AVG2(x, y) 		__builtin_pulp_avg2((x), (y))
#define __AVG4(x, y) 		__builtin_pulp_avg4((x), (y))

/* Average unsigned */
#define __AVGU2(x, y) 		__builtin_pulp_avgu2((x), (y))
#define __AVGU4(x, y) 		__builtin_pulp_avgu4((x), (y))

/* Bitwise and */
#define __AND2(x, y) 		__builtin_pulp_and2((x), (y))
#define __AND4(x, y) 		__builtin_pulp_and4((x), (y))

/* Bitwise or */
#define __OR2(x, y) 			__builtin_pulp_or2((x), (y))
#define __OR4(x, y) 			__builtin_pulp_or4((x), (y))

/* Bitwise exor */
#define __EXOR2(x, y) 		__builtin_pulp_exor2(x, y)
#define __EXOR4(x, y) 		__builtin_pulp_exor4(x, y)

/* Logical shift right */
#define __SRL2(x, y) 		__builtin_pulp_srl2(x, y)
#define __SRL4(x, y) 		__builtin_pulp_srl4(x, y)

/* Arithmetic shift right */
#define __SRA2(x, y) 		__builtin_pulp_sra2(x, y)
#define __SRA4(x, y) 		__builtin_pulp_sra4(x, y)

/* Logical shift left */
#define __SLL2(x, y) 		__builtin_pulp_sll2(x, y)
#define __SLL4(x, y) 		__builtin_pulp_sll4(x, y)

/* Mac */
#define	__MAC(Acc, x, y)		__builtin_pulp_mac((x), (y), (Acc))
#define	__MSU(Acc, x, y)		__builtin_pulp_msu((x), (y), (Acc))

#define	__MACS(Acc, x, y)		__builtin_pulp_macs((x), (y), (Acc))
#define	__MACHHS(Acc, x, y)		__builtin_pulp_machhs((x), (y), (Acc))
#define	__MACU(Acc, x, y)		__builtin_pulp_macu((x), (y), (Acc))
#define	__MACHHU(Acc, x, y)		__builtin_pulp_machhu((x), (y), (Acc))

#define __MACSN(Acc, x, y, n)	__builtin_pulp_macsN((x), (y), (Acc), (n))
#define __MACUN(Acc, x, y, n)	__builtin_pulp_macuN((x), (y), (Acc), (n))
#define __MACSRN(Acc, x, y, n)	__builtin_pulp_macsRN((x), (y), (Acc), (n), (1<<((n)-1)))
#define __MACURN(Acc, x, y, n)	__builtin_pulp_macuRN((x), (y), (Acc), (n), (1<<((n)-1)))

#define __MACHHSN(Acc, x, y, n)	__builtin_pulp_machhsN((x), (y), (Acc), (n))
#define __MACHHUN(Acc, x, y, n)	__builtin_pulp_machhuN((x), (y), (Acc), (n))
#define __MACHHSRN(Acc, x, y, n)	__builtin_pulp_machhsN((x), (y), (Acc), (n), (1<<((n)-1)))
#define __MACHHURN(Acc, x, y, n)	__builtin_pulp_machhuN((x), (y), (Acc), (n), (1<<((n)-1)))

/* Multiplications */
#define __MULS(x, y)			__builtin_pulp_muls((x), (y))
#define __MULU(x, y)			__builtin_pulp_mulu((x), (y))
#define __MULHHS(x, y)		__builtin_pulp_mulhhs((x), (y))
#define __MULHHU(x, y)		__builtin_pulp_mulhhu((x), (y))

#define __MULSN(x, y, n)		__builtin_pulp_mulsN((x), (y), (n))
#define __MULSRN(x, y, n)		__builtin_pulp_mulsRN((x), (y), (n), (1<<((n)-1)))
#define __MULUN(x, y, n)		__builtin_pulp_muluN((x), (y), (n))
#define __MULURN(x, y, n)		__builtin_pulp_muluRN((x), (y), (n), (1<<((n)-1)))

#define __MULHHSN(x, y, n)		__builtin_pulp_mulhhsN((x), (y), (n))
#define __MULHHSRN(x, y, n)		__builtin_pulp_mulhhsRN((x), (y), (n), (1<<((n)-1)))
#define __MULHHUN(x, y, n)		__builtin_pulp_mulhhuN((x), (y), (n))
#define __MULHHURN(x, y, n)		__builtin_pulp_mulhhuRN((x), (y), (n), (1<<((n)-1)))

/* Vectorial product and sum of products */
#define __DOTP2(x, y)     		__builtin_pulp_dotsp2((x), (y))
#define __DOTPU2(x, y)     		__builtin_pulp_dotup2((x), (y))
#define __DOTPUS2(x, y)    		__builtin_pulp_dotusp2((x), (y))

#define __DOTPSC2(x, y)     		__builtin_pulp_dotspsc2((x), (y))
#define __DOTPUSC2(x, y)     	__builtin_pulp_dotupsc2((x), (y))
#define __DOTPUSSC2(x, y)    	__builtin_pulp_dotuspsc2((x), (y))

#define __SUMDOTP2(x, y, z)		__builtin_pulp_sdotsp2((x), (y), (z))
#define __SUMDOTPU2(x, y, z)		__builtin_pulp_sdotup2((x), (y), (z))
#define __SUMDOTPUS2(x, y, z)	__builtin_pulp_sdotusp2((x), (y), (z))

#define __SUMDOTPSC2(x, y, z)	__builtin_pulp_sdotspsc2((x), (y), (z))
#define __SUMDOTPUSC2(x, y, z)	__builtin_pulp_sdotupsc2((x), (y), (z))
#define __SUMDOTPUSSC2(x, y, z)	__builtin_pulp_sdotuspsc2((x), (y), (z))

#define __DOTP4(x, y)     		__builtin_pulp_dotsp4((x), (y))
#define __DOTPU4(x, y)     		__builtin_pulp_dotup4((x), (y))
#define __DOTPUS4(x, y)    		__builtin_pulp_dotusp4((x), (y))

#define __DOTPSC4(x, y)     		__builtin_pulp_dotspsc4((x), (y))
#define __DOTPUSC4(x, y)     	__builtin_pulp_dotupsc4((x), (y))
#define __DOTPUSSC4(x, y)    	__builtin_pulp_dotuspsc4((x), (y))

#define __SUMDOTP4(x, y, z)     	__builtin_pulp_sdotsp4((x), (y), (z))
#define __SUMDOTPU4(x, y, z)     	__builtin_pulp_sdotup4((x), (y), (z))
#define __SUMDOTPUS4(x, y, z)    	__builtin_pulp_sdotusp4((x), (y), (z))

#define __SUMDOTPSC4(x, y, z)     	__builtin_pulp_sdotspsc4((x), (y), (z))
#define __SUMDOTPUSC4(x, y, z)     	__builtin_pulp_sdotupsc4((x), (y), (z))
#define __SUMDOTPUSSC4(x, y, z)    	__builtin_pulp_sdotuspsc4((x), (y), (z))

#ifdef ARCHI_CORE_HAS_CPLX
 
/* Complex Multiplication, Q15x15 into Q15, with optional post scaling by 1 or 2 */
#define __CPLXMULS(x, y)		__builtin_pulp_cplxmuls((x), (y))
#define __CPLXMULSDIV2(x, y)		__builtin_pulp_cplxmulsdiv2((x), (y))
#define __CPLXMULSDIV4(x, y)		__builtin_pulp_cplxmulsdiv4((x), (y))

/* Complex conjugate */
#define __CPLXCONJ(x)		__builtin_pulp_cplx_conj((x))

/* Complex substration, result rotated by -pi/2 */
#define __SUB2ROTMJ(x, y)		__builtin_pulp_sub2rotmj((x), (y))

/* Complex addition with post scaling by 1 or 2 */
#define __ADD2DIV2(x, y)		__builtin_pulp_add2div2((x), (y))
#define __ADD2DIV4(x, y)		__builtin_pulp_add2div4((x), (y))

#define __ADD4DIV2(x, y)		__builtin_pulp_add4div2((x), (y))
#define __ADD4DIV4(x, y)		__builtin_pulp_add4div4((x), (y))

/* Complex subtraction with post scaling by 1 or 2 */
#define __SUB2DIV2(x, y)		__builtin_pulp_sub2div2((x), (y))
#define __SUB2DIV4(x, y)		__builtin_pulp_sub2div4((x), (y))

#define __SUB4DIV2(x, y)		__builtin_pulp_sub4div2((x), (y))
#define __SUB4DIV4(x, y)		__builtin_pulp_sub4div4((x), (y))

/* Viterbi Max and Viterbi Select, pair of Q15 */
#define __VITMAX(x, y) 		__builtin_pulp_vitmax2((x), (y))
#define __VITSEL(x, y) 		__builtin_pulp_vitsel2((x), (y))

#endif

/* Position of the most significant bit of x */
#define __FF1(x)			__builtin_pulp_ff1((x))
#define __FL1(x)			__builtin_pulp_fl1((x))

/* Number of sign bits */
#define __CLB(x)			__builtin_pulp_clb((x))

static inline unsigned int __attribute__ ((always_inline)) __ExtInsMaskFast(unsigned int Size, unsigned int Offset) { return ((((Size-1))<<5)|(Offset)); }
static inline unsigned int __attribute__ ((always_inline)) __ExtInsMaskSafe(unsigned int Size, unsigned int Offset) { return ((((Size-1)&0x1F)<<5)|(Offset&0x1F)); }

/* Bit set */
#define __BITSET(x, size, off)               __builtin_pulp_bset((x), (((1<<(size))-1)<<(off)))
#define __BITSET_R(x, size, off)             __builtin_pulp_bset_r((x), __ExtInsMaskFast((size), (off)))
#define __BITSET_R_SAFE(x, size, off)        __builtin_pulp_bset_r((x), __ExtInsMaskSafe((size), (off)))

/* Bit clr */
#define __BITCLR(x, size, off)               __builtin_pulp_bclr((x), ~(((1<<(size))-1)<<(off)))
#define __BITCLR_R(x, size, off)             __builtin_pulp_bclr_r((x), __ExtInsMaskFast((size), (off)))
#define __BITCLR_R_SAFE(x, size, off)        __builtin_pulp_bclr_r((x), __ExtInsMaskSafe((size), (off)))

/* Bit Extraction */
#define __BITEXTRACT(x, size, off)		__builtin_pulp_bextract((x), (size), (off))
#define __BITEXTRACTU(x, size, off)		__builtin_pulp_bextractu((x), (size), (off))

#define __BITEXTRACT_R(x, size, off)		__builtin_pulp_bextract_r((x), __ExtInsMaskFast((size), (off)))
#define __BITEXTRACTU_R(x, size, off)	__builtin_pulp_bextractu_r((x), __ExtInsMaskFast((size), (off)))

#define __BITEXTRACT_R_SAFE(x, size, off)	__builtin_pulp_bextract_r((x), __ExtInsMaskSafe((size), (off)))
#define __BITEXTRACTU_R_SAFE(x, size, off)	__builtin_pulp_bextractu_r((x), __ExtInsMaskSafe((size), (off)))

/* Bit insertion */
#define __BITINSERT(dst, src, size, off) 	__builtin_pulp_binsert((dst), ~(((1<<(size))-1)<<(off)), (src), (((1<<(size))-1)<<(off)), (off))
#define __BITINSERT_R(dst, src, size, off) 	__builtin_pulp_binsert_r((dst), (src), __ExtInsMaskFast((size), (off)))
#define __BITINSERT_R_SAFE(dst, src, size, off) 	__builtin_pulp_binsert_r((dst), (src), __ExtInsMaskSafe((size), (off)))

/* 1 bit rotation to the right, 32 bits input */
#define __ROTR(x)			__builtin_pulp_rotr((x))

/* Add with normalization */
#define __ADDNORMU(x, y, scale)		__builtin_pulp_adduN((x), (y), (scale))
#define __ADDNORMU_REG(x, y, scale)		__builtin_pulp_adduN_r((x), (y), (scale))
#define __ADDNORM(x, y, scale)		__builtin_pulp_addN((x), (y), (scale))
#define __ADDNORM_REG(x, y, scale)		__builtin_pulp_addN_r((x), (y), (scale))

/* Add with normalization and rounding */
#define __ADDROUNDNORMU(x, y, scale)		__builtin_pulp_adduRN((x), (y), (scale), (1<<((scale)-1)))
#define __ADDROUNDNORMU_REG(x, y, scale)	__builtin_pulp_adduRN_r((x), (y), (scale))
#define __ADDROUNDNORM(x, y, scale)		__builtin_pulp_addRN((x), (y), (scale), (1<<((scale)-1)))
#define __ADDROUNDNORM_REG(x, y, scale)	__builtin_pulp_addRN_r((x), (y), (scale))

/* Sub with normalization */
#define __SUBNORMU(x, y, scale)		__builtin_pulp_subuN((x), (y), (scale))
#define __SUBNORMU_REG(x, y, scale)		__builtin_pulp_subuN_r((x), (y), (scale))
#define __SUBNORM(x, y, scale)		__builtin_pulp_subN((x), (y), (scale))
#define __SUBNORM_REG(x, y, scale)		__builtin_pulp_subN_r((x), (y), (scale))

/* Sub with normalization and rounding */
#define __SUBROUNDNORMU(x, y, scale)		__builtin_pulp_subuRN((x), (y), (scale), (1<<((scale)-1)))
#define __SUBROUNDNORMU_REG(x, y, scale)	__builtin_pulp_subuRN_r((x), (y), (scale))
#define __SUBROUNDNORM(x, y, scale)		__builtin_pulp_subRN((x), (y), (scale), (1<<((scale)-1)))
#define __SUBROUNDNORM_REG(x, y, scale)	__builtin_pulp_subRN_r((x), (y), (scale))

/* Normalization and rounding */
#define __ROUNDNORMU(x, scale)		__builtin_pulp_adduRN((x), 0, (scale), (1<<((scale)-1)))
#define __ROUNDNORMU_REG(x, scale)		__builtin_pulp_adduRN_r((x), 0, (scale))
#define __ROUNDNORM(x, scale)		__builtin_pulp_addRN((x), 0, (scale), (1<<((scale)-1)))
#define __ROUNDNORM_REG(x, scale)		__builtin_pulp_addRN_r((x), 0, (scale))

#define __COREID()					__builtin_pulp_CoreId()
#define __CLUSTERID()				__builtin_pulp_ClusterId()
#define __NCORE()					__builtin_pulp_CoreCount()
#define __ISFC()					__builtin_pulp_IsFc()

#define __SPRWRITE(x, y)				__builtin_pulp_spr_write(x, y)
#define __SPRREAD(x)					__builtin_pulp_spr_read(x)
#define __SPRREAD_VOL(x)				__builtin_pulp_spr_read_vol(x)

#define __SPRBITSET(spr, off)			__builtin_pulp_spr_bit_set((spr), (off))
#define __SPRBITCLR(spr, off)			__builtin_pulp_spr_bit_clr((spr), (off))

#define __SPRREADTHENWRITE(spr, x)			__builtin_pulp_read_then_spr_write((spr), (x))
#define __SPRREADTHENBITSET(spr, off)		__builtin_pulp_read_then_spr_bit_set((spr), (off))
#define __SPRREADTHENBITCLR(spr, off)		__builtin_pulp_read_then_spr_bit_clr((spr), (off))



#define __READ_BASE_OFF(base, off)           	__builtin_pulp_read_base_off((base), (off))
#define __WRITE_BASE_OFF(base, off, val)     	__builtin_pulp_write_base_off((base), (off), (val))

#define __READ_BASE_OFF_VOL(base, off)       	__builtin_pulp_OffsetedRead((base), (off))
#define __READ_BASE_OFF_HALF_VOL(base, off)  	__builtin_pulp_OffsetedReadHalf((base), (off))
#define __READ_BASE_OFF_BYTE_VOL(base, off)  	__builtin_pulp_OffsetedReadByte((base), (off))

#define __WRITE_BASE_OFF_VOL(x, base, off)       	__builtin_pulp_OffsetedWrite((x), (base), (off))
#define __WRITE_BASE_OFF_HALF_VOL(x, base, off)  	__builtin_pulp_OffsetedWriteHalf((x), (base), (off))
#define __WRITE_BASE_OFF_BYTE_VOL(x, base, off)  	__builtin_pulp_OffsetedWriteByte((x), (base), (off))
/* Utilities, Target independant */
#define FIX2FP(Val, Precision)						((float) (Val) / (float) (1<<(Precision)))
#define FP2FIXR(Val, Precision)						((int)((Val)*((1 << (Precision))-1) + 0.5))
#define FP2FIX(Val, Precision)						((int)((Val)*((1 << (Precision))-1)))
#endif
#endif
