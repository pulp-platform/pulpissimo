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

#ifndef __ARCHI_HWCE_HWCE_V5_H__
#define __ARCHI_HWCE_HWCE_V5_H__

#define HWCE_TRIGGER         0x00
#define HWCE_ACQUIRE         0x04
#define HWCE_FINISHED        0x08
#define HWCE_STATUS          0x0C
#define HWCE_RUNNING_JOB     0x10
#define HWCE_SOFT_CLEAR      0x14
#define HWCE_OFFLOADER_ID    0x18
#define HWCE_SW_EVT          0x1C

#define HWCE_GEN_CONFIG0     0x20
#define HWCE_GEN_CONFIG1     0x24
#define HWCE_GEN_CONFIG2     0x28

#define HWCE_Y_TRANS_SIZE          0x40
#define HWCE_Y_LINE_STRIDE_LENGTH  0x44
#define HWCE_Y_FEAT_STRIDE_LENGTH  0x48
#define HWCE_Y_OUT_3_BASE_ADDR     0x4C
#define HWCE_Y_OUT_2_BASE_ADDR     0x50
#define HWCE_Y_OUT_1_BASE_ADDR     0x54
#define HWCE_Y_OUT_0_BASE_ADDR     0x58
#define HWCE_Y_IN_3_BASE_ADDR      0x5C
#define HWCE_Y_IN_2_BASE_ADDR      0x60
#define HWCE_Y_IN_1_BASE_ADDR      0x64
#define HWCE_Y_IN_0_BASE_ADDR      0x68
#define HWCE_X_TRANS_SIZE          0x6C
#define HWCE_X_LINE_STRIDE_LENGTH  0x70
#define HWCE_X_FEAT_STRIDE_LENGTH  0x74
#define HWCE_X_IN_BASE_ADDR        0x78
#define HWCE_W_BASE_ADDR           0x7C
#define HWCE_JOB_CONFIG0           0x80
#define HWCE_JOB_CONFIG1           0x84
#define HWCE_JOB_CONFIG2           0x88
#define HWCE_TH_BASE_ADDR          0x8C
#define HWCE_LBUFXTRANSSIZE_ADDR   0x90

#define HWCE_NB_IO_REGS    19

#define HWCE_ACQUIRE_CONTEXT_COPY -3
#define HWCE_ACQUIRE_LOCKED       -2
#define HWCE_ACQUIRE_QUEUE_FULL   -1
#define HWCE_ACQUIRE_READY        0

#define HWCE_GEN_CONFIG0_WSTRIDE(x) ((x) >> 16)
#define HWCE_GEN_CONFIG0_NCP(x)     (((x) >> 13) & 0x1)
#define HWCE_GEN_CONFIG0_CONV(x)    (((x) >> 11) & 0x3)
#define HWCE_GEN_CONFIG0_VECT(x)    (((x) >> 9) & 0x3)
#define HWCE_GEN_CONFIG0_UNS(x)     (((x) >> 8) & 1)
#define HWCE_GEN_CONFIG0_NY(x)      (((x) >> 7) & 1)
#define HWCE_GEN_CONFIG0_NF(x)      (((x) >> 6) & 1)
#define HWCE_GEN_CONFIG0_QF(x)      ((x) & 0x3f)

#define HWCE_GEN_CONFIG0_CONV_5x5 0
#define HWCE_GEN_CONFIG0_CONV_3x3 1
#define HWCE_GEN_CONFIG0_CONV_4x7 2

#define HWCE_GEN_CONFIG0_VECT_1 0
#define HWCE_GEN_CONFIG0_VECT_2 1
#define HWCE_GEN_CONFIG0_VECT_4 2

#define HWCE_GEN_CONFIG1_PIXSHIFTR(x)  (((x) >> 16) & 0x1F)
#define HWCE_GEN_CONFIG1_PIXMODE(x)    (((x) >> 8) & 0x3)
#define HWCE_GEN_CONFIG1_PIXSHIFTL(x)  (((x) >> 0) & 0x1F)

#define HWCE_JOB_CONFIG0_NOYCONST(x) ((x) >> 16)
#define HWCE_JOB_CONFIG0_LBUFLEN(x)  ((x) & 0x3ff)

#define HWCE_JOB_CONFIG1_LO(x)                (((x) >> 24) & 0x1)
#define HWCE_JOB_CONFIG1_WIF(x)               (((x) >> 16) & 0x3F)
#define HWCE_JOB_CONFIG1_WOF(x)               (((x) >> 8) & 0x1F)
#define HWCE_JOB_CONFIG1_VECT_DISABLE_MASK(x) (((x) >> 0) & 0xF)

#define HWCE_JOB_STRIDE(x) ((x) >> 16)
#define HWCE_JOB_LENGTH(x) ((x) & 0xffff)

/* utility constants - used by hwce_rt and other libs */

// linebuffer width in 16-bit half-words
#define HWCE_LBSIZE 32

// loop order modes
#define HWCE_LOOP_ORDER_OF_IF 0
#define HWCE_LOOP_ORDER_IF_OF 1

// quantization modes
#define HWCE_QMODE_16BIT 0
#define HWCE_QMODE_8BIT  4
#define HWCE_QMODE_4BIT  3
#define HWCE_QMODE_2BIT  2
#define HWCE_QMODE_1BIT  1

// y_in modes
#define HWCE_Y_IN_MODE_ON  1
#define HWCE_Y_IN_MODE_OFF 0

// disable vectors
#define HWCE_VECT_DISABLE(y0, y1, y2, y3) ( y0 << 3 | y1 << 2 | y2 << 1 | y3 )

// conv mode
#define HWCE_CONVMODE_5x5 HWCE_GEN_CONFIG0_CONV_5x5
#define HWCE_CONVMODE_3x3 HWCE_GEN_CONFIG0_CONV_3x3
#define HWCE_CONVMODE_4x7 HWCE_GEN_CONFIG0_CONV_4x7

// vect mode
#define HWCE_VECTMODE_1 HWCE_GEN_CONFIG0_VECT_1
#define HWCE_VECTMODE_2 HWCE_GEN_CONFIG0_VECT_2
#define HWCE_VECTMODE_4 HWCE_GEN_CONFIG0_VECT_4

// sign mode
#define HWCE_SIGNMODE_SIGNED   1
#define HWCE_SIGNMODE_UNSIGNED 0

// weight order
#define HWCE_WEIGHTORDER_AUTOCORR 1
#define HWCE_WEIGHTORDER_CONV     0

// job copy mechanism
#define HWCE_JOBCOPY_ON  1
#define HWCE_JOBCOPY_OFF 0

#endif
