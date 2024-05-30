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

#ifndef __HAL_BUILTINS_V2_EMU_H__
#define __HAL_BUILTINS_V2_EMU_H__

#ifndef ARCHI_CORE_HAS_PULPV2
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
#define __PACK2(x, y)			((v2s) {(signed short)   (x), (signed short)   (y)})
#define __PACKU2(x, y)			((v2u) {(unsigned short) (x), (unsigned short) (y)})

#define __PACK4(x, y, z, t)			((v4s) {(signed char)   (x), (signed char)   (y), (signed char)   (z), (signed char)   (t)})
#define __PACKU4(x, y, z, t)			((v4u) {(unsigned char) (x), (unsigned char) (y), (unsigned char) (z), (unsigned char) (t)})

/* Max */
#define __MAX(x, y) ((x)>(y)?(x):(y))
#define __MAX2(x, y) 			((v2s) {((signed short)(x)[0]>(signed short)(y)[0])?((signed short)(x)[0]):((signed short)(y)[0]), \
							((signed short)(x)[1]>(signed short)(y)[1])?((signed short)(x)[1]):((signed short)(y)[1])})
#define __MAX4(x, y) 			((v4s) {((signed char)(x)[0]>(signed char)(y)[0])?(signed char)(x)[0]:(signed char)(y)[0], \
							((signed char)(x)[1]>(signed char)(y)[1])?(signed char)(x)[1]:(signed char)(y)[1], \
							((signed char)(x)[2]>(signed char)(y)[2])?(signed char)(x)[2]:(signed char)(y)[2], \
							((signed char)(x)[3]>(signed char)(y)[3])?(signed char)(x)[3]:(signed char)(y)[3]})

#define __MAXU2(x, y) 			((v2u) {((unsigned short)(x)[0]>(unsigned short)(y)[0])?(unsigned short)(x)[0]:(unsigned short)(y)[0], \
							((unsigned short)(x)[1]>(unsigned short)(y)[1])?(unsigned short)(x)[1]:(unsigned short)(y)[1]})
#define __MAXU4(x, y) 			((v4u) {((unsigned char)(x)[0]>(unsigned char)(y)[0])?(unsigned char)(x)[0]:(unsigned char)(y)[0], \
							((unsigned char)(x)[1]>(unsigned char)(y)[1])?(unsigned char)(x)[1]:(unsigned char)(y)[1], \
							((unsigned char)(x)[2]>(unsigned char)(y)[2])?(unsigned char)(x)[2]:(unsigned char)(y)[2], \
							((unsigned char)(x)[3]>(unsigned char)(y)[3])?(unsigned char)(x)[3]:(unsigned char)(y)[3]})

/* Min */
#define __MIN2(x, y) 			((v2s) {((signed short)(x)[0]<(signed short)(y)[0])?((signed short)(x)[0]):((signed short)(y)[0]), \
							((signed short)(x)[1]<(signed short)(y)[1])?((signed short)(x)[1]):((signed short)(y)[1])})
#define __MIN4(x, y) 			((v4s) {((signed char)(x)[0]<(signed char)(y)[0])?(signed char)(x)[0]:(signed char)(y)[0], \
							((signed char)(x)[1]<(signed char)(y)[1])?(signed char)(x)[1]:(signed char)(y)[1], \
							((signed char)(x)[2]<(signed char)(y)[2])?(signed char)(x)[2]:(signed char)(y)[2], \
							((signed char)(x)[3]<(signed char)(y)[3])?(signed char)(x)[3]:(signed char)(y)[3]})

#define __MINU2(x, y) 			((v2u) {((unsigned short)(x)[0]<(unsigned short)(y)[0])?(unsigned short)(x)[0]:(unsigned short)(y)[0], \
							((unsigned short)(x)[1]<(unsigned short)(y)[1])?(unsigned short)(x)[1]:(unsigned short)(y)[1]})
#define __MINU4(x, y) 			((v4u) {((unsigned char)(x)[0]<(unsigned char)(y)[0])?(unsigned char)(x)[0]:(unsigned char)(y)[0], \
							((unsigned char)(x)[1]<(unsigned char)(y)[1])?(unsigned char)(x)[1]:(unsigned char)(y)[1], \
							((unsigned char)(x)[2]<(unsigned char)(y)[2])?(unsigned char)(x)[2]:(unsigned char)(y)[2], \
							((unsigned char)(x)[3]<(unsigned char)(y)[3])?(unsigned char)(x)[3]:(unsigned char)(y)[3]})

/* Clip */
#define __CLIP(x, precision)			((x)<(-(1<<(precision)))?(-(1<<(precision))):(((x)>((1<<(precision))-1))?((1<<(precision))-1):(x)))
#define __CLIP_R(x, bound)			(((x)<=-((bound)+1))?(-((bound)+1)):(((x)>=(bound))?(bound):(x)))

#define __CLIPU(x, precision)		((x)<0)?0:(((x)>((1<<(precision))-1))?((1<<(precision))-1):(x))
#define __CLIPU_R(x, bound)			(((x)<=0)?(0):(((x)>=(bound))?(bound):(x)))

/* Abs */
#define __ABS2(x) 				((v2u) {((x)[0]<0)?-(x)[0]:(x)[0], ((x)[1]<0)?-(x)[1]:(x)[1]})
#define __ABS4(x) 				((v4u) {((x)[0]<0)?-(x)[0]:(x)[0], ((x)[1]<0)?-(x)[1]:(x)[1], \
 						        ((x)[2]<0)?-(x)[2]:(x)[2], ((x)[3]<0)?-(x)[3]:(x)[3]})

/* Unary minus */
#define __NEG2(x) 				((v2s) {-(x)[0], -(x)[1]}
#define __NEG4(x) 				((v4s) {-(x)[0], -(x)[1], -(x)[2], -(x)[3]}

/* Addition */
#define __ADD2(x, y) 			((v2s) {(x)[0]+(y)[0], (x)[1]+(y)[1]}
#define __ADD4(x, y) 			((v4s) {(x)[0]+(y)[0], (x)[1]+(y)[1], (x)[2]+(y)[2], (x)[3]+(y)[3]}

/* Substraction */
#define __SUB2(x, y) 			((v2s) {(x)[0]-(y)[0], (x)[1]-(y)[1]}
#define __SUB4(x, y) 			((v4s) {(x)[0]-(y)[0], (x)[1]-(y)[1], (x)[2]-(y)[2], (x)[3]-(y)[3]}

/* Average */
#define __AVG2(x, y) 			((v2s) {((x)[0]+(y)[0])>>1, ((x)[1]+(y)[1])>>1}
#define __AVG4(x, y) 			((v4s) {((x)[0]+(y)[0])>>1, ((x)[1]+(y)[1])>>1, ((x)[2]+(y)[2])>>1, ((x)[3]+(y)[3])>>1}

/* Average unsigned */
#define __AVGU2(x, y) 			((v2u) {((unsigned short)(x)[0]+(unsigned short)(y)[0])>>1, ((unsigned short)(x)[1]+(unsigned short)(y)[1])>>1}
#define __AVGU4(x, y) 			((v4u) {((unsigned char)(x)[0]+(unsigned char)(y)[0])>>1, ((unsigned char)(x)[1]+(unsigned char)(y)[1])>>1, \
							((unsigned char)(x)[2]+(unsigned char)(y)[2])>>1, ((unsigned char)(x)[3]+(unsigned char)(y)[3])>>1}

/* Bitwise and */
#define __AND2(x, y) 			((v2s) {(x)[0]&(y)[0], (x)[1]&(y)[1]}
#define __AND4(x, y) 			((v4s) {(x)[0]&(y)[0], (x)[1]&(y)[1], (x)[2]&(y)[2], (x)[3]&(y)[3]}

/* Bitwise or */
#define __OR2(x, y) 				((v2s) {(x)[0]|(y)[0], (x)[1]|(y)[1]}
#define __OR4(x, y) 				((v4s) {(x)[0]|(y)[0], (x)[1]|(y)[1], (x)[2]|(y)[2], (x)[3]|(y)[3]}

/* Bitwise exor */
#define __EXOR2(x, y) 			((v2s) {(x)[0]^(y)[0], (x)[1]^(y)[1]}
#define __EXOR4(x, y) 			((v4s) {(x)[0]^(y)[0], (x)[1]^(y)[1], (x)[2]^(y)[2], (x)[3]^(y)[3]}

/* Logical shift right */
#define __SRL2(x, y) 			((v2u) {((unsigned short)(x)[0]>>(unsigned short)(y)[0]), ((unsigned short)(x)[1]>>(unsigned short)(y)[1])}
#define __SRL4(x, y) 			((v4u) {((unsigned char)(x)[0]>>(unsigned char)(y)[0]), ((unsigned char)(x)[1]>>(unsigned char)(y)[1]), \
                               		                ((unsigned char)(x)[2]>>(unsigned char)(y)[2]), ((unsigned char)(x)[3]>>(unsigned char)(y)[3])}

/* Arithmetic shift right */
#define __SRA2(x, y) 			((v2s) {((signed short)(x)[0]>>(signed short)(y)[0]), ((signed short)(x)[1]>>(signed short)(y)[1])}
#define __SRA4(x, y) 			((v4s) {((signed char)(x)[0]>>(signed char)(y)[0]), ((signed char)(x)[1]>>(signed char)(y)[1]), \
                               		                ((signed char)(x)[2]>>(signed char)(y)[2]), ((signed char)(x)[3]>>(signed char)(y)[3])}

/* Logical shift left */
#define __SLL2(x, y) 			((v2s) {(x)[0]<<(y)[0], (x)[1]<<(y)[1]}
#define __SLL4(x, y) 			((v4s) {(x)[0]<<(y)[0], (x)[1]<<(y)[1], (x)[2]<<(y)[2], (x)[3]<<(y)[3]}

/* Mac */
#define	__MAC(Acc, x, y)			((Acc) + ((x) * (y)))
#define	__MSU(Acc, x, y)			((Acc) - ((x) * (y)))

#define	__MACS(Acc, x, y)			((Acc) + ((short int) (x) * (short int) (y)))
#define	__MACHHS(Acc, x, y)			((Acc) + ((short int) ((x)>>16) * (short int) ((y)>>16)))
#define	__MACU(Acc, x, y)			((Acc) + ((unsigned short int) (x) * (unsigned short int) (y)))
#define	__MACHHU(Acc, x, y)			((Acc) + ((unsigned short int) ((x)>>16) * (unsigned short int) ((y)>>16)))

#define	__MACSN(Acc, x, y, n)		(((Acc) + ((short int) (x) * (short int) (y)))>>(n))
#define	__MACUN(Acc, x, y, n)		(((Acc) + ((unsigned short int) (x) * (unsigned short int) (y)))>>(n))
#define	__MACSRN(Acc, x, y, n)		((((Acc) + ((short int) (x) * (short int) (y))) + (1<<((n)-1))) >> (n))
#define	__MACURN(Acc, x, y, n)		((((Acc) + ((unsigned short int) (x) * (unsigned short int) (y))) + (1<<((n)-1))) >> (n))

#define	__MACHHSN(Acc, x, y, n)		(((Acc) + ((short int) ((x)>>16) * (short int) ((y)>>16))) >> (n))
#define	__MACHHUN(Acc, x, y, n)		(((Acc) + ((unsigned short int) ((x)>>16) * (unsigned short int) ((y)>>16))) >> (n))
#define	__MACHHSRN(Acc, x, y, n)		((((Acc) + ((short int) ((x)>>16) * (short int) ((y)>>16))) + (1<<((n)-1))) >> (n))
#define	__MACHHURN(Acc, x, y, n)		((((Acc) + ((unsigned short int) ((x)>>16) * (unsigned short int) ((y)>>16))) + (n)))

/* Multiplications */
#define __MULS(x, y)				(((short int) (x) * (short int) (y)))
#define __MULU(x, y)				(((unsigned short int) (x) * (unsigned short int) (y)))
#define __MULHHS(x, y)			(((short int) ((x)>>16) * (short int) ((y)>>16)))
#define __MULHHU(x, y)			(((unsigned short int) ((x)>>16) * (unsigned short int) ((y)>>16)))

#define __MULSN(x, y, n)			(((short int) (x) * (short int) (y))>>(n))
#define __MULSRN(x, y, n)			((((short int) (x) * (short int) (y)) + (1<<((n)-1)))>>(n))
#define __MULUN(x, y, n)			(((unsigned short int) (x) * (unsigned short int) (y))>>(n))
#define __MULURN(x, y, n)			((((unsigned short int) (x) * (unsigned short int) (y)) + (1<<((n)-1)))>>(n))

#define __MULHHSN(x, y, n)			((((short int) ((x)>>16) * (short int) ((y)>>16)))>>(n))
#define __MULHHSRN(x, y, n)			(((((short int) ((x)>>16) * (short int) ((y)>>16)))+(1<<((n)-1)))>>(n))
#define __MULHHUN(x, y, n)			((((unsigned short int) ((x)>>16) * (unsigned short int) ((y)>>16)))>>(n))
#define __MULHHURN(x, y, n)			(((((unsigned short int) ((x)>>16) * (unsigned short int) ((y)>>16)))+(1<<((n)-1)))>>(n))

/* Vectorial product and sum of products */
#define __DOTP2(x, y)			(    (short)(x)[0]*(short)(y)[0] + (short)(x)[1]*(short)(y)[1])
#define __DOTPU2(x, y)			(    (unsigned short)(x)[0]*(unsigned short)(y)[0] + (unsigned short)(x)[1]*(unsigned short)(y)[1])
#define __DOTPUS2(x, y)			(    (unsigned short)(x)[0]*(short)(y)[0] + (unsigned short)(x)[1]*(short)(y)[1])

#define __DOTPSC2(x, y)			(    (short)(x)[0]*(short)(y) + (short)(x)[1]*(short)(y))
#define __DOTPUSC2(x, y)			(    (unsigned short)(x)[0]*(unsigned short)(y) + (unsigned short)(x)[1]*(unsigned short)(y))
#define __DOTPUSSC2(x, y)			(    (unsigned short)(x)[0]*(short)(y) + (unsigned short)(x)[1]*(short)(y))

#define __SUMDOTP2(x, y, z)			((z)+(short)(x)[0]*(short)(y)[0] + (short)(x)[1]*(short)(y)[1])
#define __SUMDOTPU2(x, y, z)			((z)+(unsigned short)(x)[0]*(unsigned short)(y)[0] + (unsigned short)(x)[1]*(unsigned short)(y)[1])
#define __SUMDOTPUS2(x, y, z)		((z)+(unsigned short)(x)[0]*(short)(y)[0] + (unsigned short)(x)[1]*(short)(y)[1])

#define __SUMDOTPSC2(x, y, z)		((z)+(short)(x)[0]*(short)(y) + (short)(x)[1]*(short)(y))
#define __SUMDOTPUSC2(x, y, z)		((z)+(unsigned short)(x)[0]*(unsigned short)(y) + (unsigned short)(x)[1]*(unsigned short)(y))
#define __SUMDOTPUSSC2(x, y, z)		((z)+(unsigned short)(x)[0]*(short)(y) + (unsigned short)(x)[1]*(short)(y))

#define __DOTP4(x, y)			(    (char)(x)[0]*(char)(y)[0] + (char)(x)[1]*(char)(y)[1] + (char)(x)[2]*(char)(y)[2] + (char)(x)[3]*(char)(y)[3])
#define __DOTPU4(x, y)			(    (unsigned char)(x)[0]*(unsigned char)(y)[0] + (unsigned char)(x)[1]*(unsigned char)(y)[1] + \
                                       		(unsigned char)(x)[2]*(unsigned char)(y)[2] + (unsigned char)(x)[3]*(unsigned char)(y)[3])
#define __DOTPUS4(x, y)			(    (unsigned char)(x)[0]*(char)(y)[0] + (unsigned char)(x)[1]*(char)(y)[1] + \
                              			     (unsigned char)(x)[2]*(char)(y)[2] + (unsigned char)(x)[3]*(char)(y)[3])

#define __DOTPSC4(x, y)			(    (char)(x)[0]*(char)(y) + (char)(x)[1]*(char)(y) + (char)(x)[2]*(char)(y) + (char)(x)[3]*(char)(y))
#define __DOTPUSC4(x, y)			(    (unsigned char)(x)[0]*(unsigned char)(y) + (unsigned char)(x)[1]*(unsigned char)(y) + \
                               	              	     (unsigned char)(x)[2]*(unsigned char)(y) + (unsigned char)(x)[3]*(unsigned char)(y))
#define __DOTPUSSC4(x, y)			(    (unsigned char)(x)[0]*(char)(y) + (unsigned char)(x)[1]*(char)(y) + \
                                             	     (unsigned char)(x)[2]*(char)(y) + (unsigned char)(x)[3]*(char)(y))

#define __SUMDOTP4(x, y, z)			((z)+(char)(x)[0]*(char)(y)[0] + (char)(x)[1]*(char)(y)[1] + (char)(x)[2]*(char)(y)[2] + (char)(x)[3]*(char)(y)[3])
#define __SUMDOTPU4(x, y, z)			((z)+(unsigned char)(x)[0]*(unsigned char)(y)[0] + (unsigned char)(x)[1]*(unsigned char)(y)[1] + \
                                  		     (unsigned char)(x)[2]*(unsigned char)(y)[2] + (unsigned char)(x)[3]*(unsigned char)(y)[3])
#define __SUMDOTPUS4(x, y, z)		((z)+(unsigned char)(x)[0]*(char)(y)[0] + (unsigned char)(x)[1]*(char)(y)[1] + \
                                             	     (unsigned char)(x)[2]*(char)(y)[2] + (unsigned char)(x)[3]*(char)(y)[3])

#define __SUMDOTPSC4(x, y, z)		((z)+(char)(x)[0]*(char)(y) + (char)(x)[1]*(char)(y) + (char)(x)[2]*(char)(y) + (char)(x)[3]*(char)(y))
#define __SUMDOTPUSC4(x, y, z)		((z)+(unsigned char)(x)[0]*(unsigned char)(y) + (unsigned char)(x)[1]*(unsigned char)(y) + \
                                       		     (unsigned char)(x)[2]*(unsigned char)(y) + (unsigned char)(x)[3]*(unsigned char)(y))
#define __SUMDOTPUSSC4(x, y, z)		((z)+(unsigned char)(x)[0]*(char)(y) + (unsigned char)(x)[1]*(char)(y) + \
                                       		     (unsigned char)(x)[2]*(char)(y) + (unsigned char)(x)[3]*(char)(y))

#ifdef ARCHI_CORE_HAS_CPLX
 
/* Complex Multiplication, Q15x15 into Q15, with optional post scaling by 1 or 2 */
#define __CPLXMULS(x, y)			((v2s) {(signed short) ((((long long) (x)[0]*(long long) (y)[0]) - ((long long) (x)[1]*(long long) (y)[1]))>>15),  \
							(signed short) ((((long long) (x)[0]*(long long) (y)[1]) + ((long long) (x)[1]*(long long) (y)[0]))>>15)})
#define __CPLXMULSDIV2(x, y)			(__CPLXMULS(x, y)>>(v2s){1,1})
#define __CPLXMULSDIV4(x, y)			(__CPLXMULS(x, y)>>(v2s){2,2})

/* Complex conjugate */
#define __CPLXCONJ(x)			((v2s) {(x)[0], -(x)[1]})

/* Complex substration, result rotated by -pi/2 */
#define __SUB2ROTMJ(x, y)			((v2s) {(x)[1]-(y)[1], (y)[0]-(x)[0]})

/* Complex addition with post scaling by 1 or 2 */
#define __ADD2DIV2(x, y)			(((x)+(y))>>(v2s) {1, 1})
#define __ADD2DIV4(x, y)			(((x)+(y))>>(v2s) {2, 2})

#define __ADD4DIV2(x, y)			(((x)+(y))>>(v4s) {1, 1, 1, 1})
#define __ADD4DIV4(x, y)			(((x)+(y))>>(v4s) {2, 2, 2, 2})

/* Complex substraction with post scaling by 1 or 2 */
#define __SUB2DIV2(x, y)			(((x)-(y))>>(v2s) {1, 1})
#define __SUB2DIV4(x, y)			(((x)-(y))>>(v2s) {2, 2})

#define __SUB4DIV2(x, y)			(((x)-(y))>>(v4s) {1, 1, 1, 1})
#define __SUB4DIV4(x, y)			(((x)-(y))>>(v4s) {2, 2, 2, 2})

/* Complex subtraction with post scaling by 1 or 2 */
#define __SUB2DIV2(x, y)			(((x)-(y))>>(v2s) {1, 1})
#define __SUB2DIV4(x, y)			(((x)-(y))>>(v2s) {2, 2})

/* Viterbi Max and Viterbi Select, pair of Q15 */
#define __VITMAX(x, y) 			(_VitT1_Flag=((x)[1]<=(y)[1])?1:0, _VitT0_Flag=((x)[0]<=(y)[0])?1:0,\
					 	(v2s) {((x)[0]>(y)[0])?(x)[0]:(y)[0], ((x)[1]>(y)[1])?(x)[1]:(y)[1]})
#define __VITSEL(x, y) 			(v2s) {(_VitT0_Flag?(y)[0]:(x)[0])<<1|_VitT0_Flag, (_VitT1_Flag?(y)[1]:(x)[1])<<1|_VitT1_Flag}

#endif

/* Position of the most significant bit of x */
#define __FL1(x)				(31 - __builtin_clz((x)))

/* Number of sign bits */
#define __CLB(x)				(__builtin_clrsb((x)))

/* Bit set */
#define __BITSET(x, size, off)		((x) | (((1<<(size))-1)<<(off)))
#define __BITSET_R(x, size, off)		((x) | (((1<<(size))-1)<<(off)))
#define __BITSET_R_SAFE(x, size, off)	((x) | (((1<<((size)&0x1F))-1)<<((off)&0x1F)))

/* Bit clr */
#define __BITCLR(x, size, off)		((x) & ~(((1<<(size))-1)<<(off)))
#define __BITCLR_R(x, size, off)		((x) & ~(((1<<(size))-1)<<(off)))
#define __BITCLR_R_SAFE(x, size, off)	((x) & ~(((1<<((size)&0x1F))-1)<<((off)&0x1F)))

/* Bit Extraction */
#define __BITEXTRACT(x, size, off) 		(((((x)>>(off))&((unsigned int)(1<<(size))-1))<<(32-(size)))>>(32-(size)))
#define __BITEXTRACTU(x, size, off)		(((x)>>(off))&((unsigned int)(1<<(size))-1))

#define __BITEXTRACT_R(x, size, off) 	(((((x)>>(off))&((unsigned int)(1<<(size))-1))<<(32-(size)))>>(32-(size)))
#define __BITEXTRACTU_R(x, size, off)	(((x)>>(off))&((unsigned int)(1<<(size))-1))

#define __BITEXTRACT_R_SAFE(x, size, off) 	(((((x)>>((off)&0x1F))&((unsigned int)(1<<((((size)>32)?32:(size))))-1))<<(32-((((size)>32)?32:(size)))))>>(32-((((size)>32)?32:(size)))))
#define __BITEXTRACTU_R_SAFE(x, size, off)	(((x)>>((off)&0x1F))&((unsigned int)(1<<((((size)>32)?32:(size))))-1))

/* Bit insertion */
#define __BITINSERT(dst, src, size, off) 	(((dst) & ~(((1<<(size))-1)<<(off))) | (((src) & ((1<<(size))-1))<<(off)))
#define __BITINSERT_R(dst, src, size, off) 	(((dst) & ~(((1<<(size))-1)<<(off))) | (((src) & ((1<<(size))-1))<<(off)))
#define __BITINSERT_R_SAFE(dst, src, size, off) 	(((dst) & ~(((1<<(((size)>32)?32:(size)))-1)<<((off)&0x1F))) | (((src) & ((1<<(((size)>32)?32:(size)))-1))<<((off)&0x1F)))

/* 1 bit rotation to the right, 32 bits input */
#define __ROTR(x)				((((x)>>1)&0x7FFFFFFF) | ((x)<<31))

/* Add with normalization */
#define __ADDNORMU(x, y, scale)		((unsigned int)((x) + (y))>>(scale))
#define __ADDNORMU_REG(x, y, scale)		((unsigned int)((x) + (y))>>(scale))
#define __ADDNORM(x, y, scale)		((int)((x) + (y))>>(scale))
#define __ADDNORM_REG(x, y, scale)		((int)((x) + (y))>>(scale))

/* Add with normalization and rounding */
#define __ADDROUNDNORMU(x, y, scale)		((unsigned int)((x) + (y) + (1<<((scale)-1)))>>(scale))
#define __ADDROUNDNORMU_REG(x, y, scale)	((unsigned int)((x) + (y) + (1<<((scale)-1)))>>(scale))
#define __ADDROUNDNORM(x, y, scale)		((int)((x) + (y) + (1<<((scale)-1)))>>(scale))
#define __ADDROUNDNORM_REG(x, y, scale)	((int)((x) + (y) + (1<<((scale)-1)))>>(scale))

/* Sub with normalization */
#define __SUBNORMU(x, y, scale)		((unsigned int)((x) - (y))>>(scale))
#define __SUBNORMU_REG(x, y, scale)		((unsigned int)((x) - (y))>>(scale))
#define __SUBNORM(x, y, scale)		((int)((x) - (y))>>(scale))
#define __SUBNORM_REG(x, y, scale)		((int)((x) - (y))>>(scale))

/* Sub with normalization and rounding */
#define __SUBROUNDNORMU(x, y, scale)		((unsigned int)((x) - (y) + (1<<((scale)-1)))>>(scale))
#define __SUBROUNDNORMU_REG(x, y, scale)	((unsigned int)((x) - (y) + (1<<((scale)-1)))>>(scale))
#define __SUBROUNDNORM(x, y, scale)		((int)((x) - (y) + (1<<((scale)-1)))>>(scale))
#define __SUBROUNDNORM_REG(x, y, scale)	((int)((x) - (y) + (1<<((scale)-1)))>>(scale))

/* Normalization and rounding */
#define __ROUNDNORMU(x, scale)		((unsigned int)((x) + (1<<((scale)-1)))>>(scale))
#define __ROUNDNORMU_REG(x, scale)		((unsigned int)((x) + (1<<((scale)-1)))>>(scale))
#define __ROUNDNORM(x, scale)		((int)((x) + (1<<((scale)-1)))>>(scale))
#define __ROUNDNORM_REG(x, scale)		((int)((x) + (1<<((scale)-1)))>>(scale))
#define __COREID()					0
#define __CLUSTERID()				0
#define __NCORE()					1

#define __SPRWRITE(x, y)
#define __SPRREAD(x)					((int) 0)
#define __SPRREAD_VOL(x)				((int) 0)

#define __READ_BASE_OFF(base, off)  	         	((int) 0)
#define __WRITE_BASE_OFF(base, off, val)

#define __READ_BASE_OFF_VOL(base, off)       	((int) 0)
#define __READ_BASE_OFF_HALF_VOL(base, off)  	((int) 0)
#define __READ_BASE_OFF_BYTE_VOL(base, off) 	 	((int) 0)

#define __WRITE_BASE_OFF_VOL(x, base, off)
#define __WRITE_BASE_OFF_HALF_VOL(x, base, off)
#define __WRITE_BASE_OFF_BYTE_VOL(x, base, off)
/* Utilities, Target independant */
#define FIX2FP(Val, Precision)						((float) (Val) / (float) (1<<(Precision)))
#define FP2FIXR(Val, Precision)						((int)((Val)*((1 << (Precision))-1) + 0.5))
#define FP2FIX(Val, Precision)						((int)((Val)*((1 << (Precision))-1)))
#endif
#endif
