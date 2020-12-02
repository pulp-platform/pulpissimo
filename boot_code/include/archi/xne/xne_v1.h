/* 
 * xne_v1.h
 * Francesco Conti <f.conti@unibo.it>
 *
 * Copyright (C) 2014-2017 ETH Zurich, University of Bologna
 * All rights reserved.
 */

#ifndef __ARCHI_XNE_V1_H__
#define __ARCHI_XNE_V1_H__

/*
 * Control and generic configuration register layout
 * ================================================================================
 *  # reg |  offset  |  bits   |   bitmask    ||  content
 * -------+----------+---------+--------------++-----------------------------------
 *     0  |  0x0000  |  31: 0  |  0xffffffff  ||  TRIGGER
 *     1  |  0x0004  |  31: 0  |  0xffffffff  ||  ACQUIRE
 *     2  |  0x0008  |  31: 0  |  0xffffffff  ||  EVT_ENABLE
 *     3  |  0x000c  |  31: 0  |  0xffffffff  ||  STATUS
 *     4  |  0x0010  |  31: 0  |  0xffffffff  ||  RUNNING_JOB
 *     5  |  0x0014  |  31: 0  |  0xffffffff  ||  SOFT_CLEAR
 *   6-7  |          |         |              ||  Reserved
 *     8  |  0x0020  |  31: 0  |  0xffffffff  ||  BYTECODE0 [31:0]
 *     9  |  0x0024  |  31: 0  |  0xffffffff  ||  BYTECODE1 [63:32]
 *    10  |  0x0028  |  31: 0  |  0xffffffff  ||  BYTECODE2 [95:64]
 *    11  |  0x002c  |  31: 0  |  0xffffffff  ||  BYTECODE3 [127:96]
 *    12  |  0x0030  |  31: 0  |  0xffffffff  ||  BYTECODE4 [159:128]
 *    13  |  0x0034  |  31:16  |  0xffff0000  ||  LOOPS0    [15:0]
 *        |          |  15: 0  |  0x0000ffff  ||  BYTECODE5 [175:160]
 *    14  |  0x0038  |  31: 0  |  0xffffffff  ||  LOOPS1    [47:16]
 *    15  |          |  31: 0  |  0xffffffff  ||  Reserved
 * ================================================================================
 *
 * Job-dependent registers layout
 * ================================================================================
 *  # reg |  offset  |  bits   |   bitmask    ||  content
 * -------+----------+---------+--------------++-----------------------------------
 *     0  |  0x0040  |  31: 0  |  0xffffffff  ||  X_ADDR
 *     1  |  0x0044  |  31: 0  |  0xffffffff  ||  W_ADDR
 *     2  |  0x0048  |  31: 0  |  0xffffffff  ||  Y_ADDR
 *     3  |  0x004c  |  31:24  |  0xff000000  ||  UCODE_STATIC0.w
 *        |          |  23:16  |  0x00ff0000  ||  UCODE_STATIC0.h
 *        |          |  15: 8  |  0x0000ff00  ||  UCODE_STATIC0.ow
 *        |          |   7: 0  |  0x000000ff  ||  UCODE_STATIC0.oh
 *     4  |  0x0050  |  31:24  |  0xff000000  ||  UCODE_STATIC1.fs0
 *        |          |  23:16  |  0x00ff0000  ||  UCODE_STATIC1.fs1
 *        |          |   7: 0  |  0x000000ff  ||  UCODE_STATIC1.acc
 *     5  |  0x0054  |  27:16  |  0x0fff0000  ||  UCODE_STATIC2.nif
 *        |          |  11: 0  |  0x00000fff  ||  UCODE_STATIC2.nof
 *     6  |  0x0058  |  31: 0  |  0xffffffff  ||  TAU_ADDR
 *     7  |  0x005c  |   3: 0  |  0x0000000f  ||  TAU_SHIFT
 * ================================================================================
 *
 */

#define XNE_TRIGGER          0x00
#define XNE_ACQUIRE          0x04
#define XNE_FINISHED         0x08
#define XNE_STATUS           0x0c
#define XNE_RUNNING_JOB      0x10
#define XNE_SOFT_CLEAR       0x14

#define XNE_BYTECODE         0x20
#define XNE_BYTECODE0_OFFS        0x00
#define XNE_BYTECODE1_OFFS        0x04
#define XNE_BYTECODE2_OFFS        0x08
#define XNE_BYTECODE3_OFFS        0x0c
#define XNE_BYTECODE4_OFFS        0x10
#define XNE_BYTECODE5_LOOPS0_OFFS 0x14
#define XNE_LOOPS1_OFFS           0x18

#define XNE_X_ADDR           0x40
#define XNE_W_ADDR           0x44
#define XNE_Y_ADDR           0x48
#define XNE_UCODE_STATIC0    0x4c
#define XNE_UCODE_STATIC1    0x50
#define XNE_UCODE_STATIC2    0x54
#define XNE_TAU_ADDR         0x58
#define XNE_TAU_SHIFT        0x5c

#endif
