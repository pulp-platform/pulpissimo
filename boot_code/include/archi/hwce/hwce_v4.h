
/* THIS FILE HAS BEEN GENERATED, DO NOT MODIFY IT.
 */

/*
 * Copyright (C) 2018 ETH Zurich, University of Bologna
 * and GreenWaves Technologies
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

#ifndef __INCLUDE_ARCHI_HWCE_HWCE_V4_H__
#define __INCLUDE_ARCHI_HWCE_HWCE_V4_H__

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS
//

// Trigger the execution of an offloaded job
#define HWCE_TRIGGER_OFFSET                      0x0

// Acquire the lock to offload job
#define HWCE_ACQUIRE_OFFSET                      0x4

// Number of concluded jobs since last read
#define HWCE_FINISHED_JOBS_OFFSET                0x8

// Status of the HWCE
#define HWCE_STATUS_OFFSET                       0xc

// ID of the currently running job
#define HWCE_RUNNING_JOB_OFFSET                  0x10

// Reset HWCE to known idle state
#define HWCE_SOFT_CLEAR_OFFSET                   0x14

// Generic configuration register 0
#define HWCE_GEN_CONFIG0_OFFSET                  0x20

// Generic configuration register 1
#define HWCE_GEN_CONFIG1_OFFSET                  0x24

// Total number of words to be read for y<sub>in</sub> and y<sub>out</sub>
#define HWCE_Y_TRANS_SIZE_OFFSET                 0x40

// Line stride and length for y<sub>in</sub> and y<sub>out</sub>
#define HWCE_Y_LINE_STRIDE_LENGTH_OFFSET         0x44

// Feature (block) stride and length for y<sub>in</sub> and y<sub>out</sub>
#define HWCE_Y_FEAT_STRIDE_LENGTH_OFFSET         0x48

// Base address of y<sub>out</sub>[3]
#define HWCE_Y_OUT_3_BASE_ADDR_OFFSET            0x4c

// Base address of y<sub>out</sub>[2]
#define HWCE_Y_OUT_2_BASE_ADDR_OFFSET            0x50

// Base address of y<sub>out</sub>[1]
#define HWCE_Y_OUT_1_BASE_ADDR_OFFSET            0x54

// Base address of y<sub>out</sub>[0]
#define HWCE_Y_OUT_0_BASE_ADDR_OFFSET            0x58

// Base address of y<sub>in</sub>[3]
#define HWCE_Y_IN_3_BASE_ADDR_OFFSET             0x5c

// Base address of y<sub>in</sub>[2]
#define HWCE_Y_IN_2_BASE_ADDR_OFFSET             0x60

// Base address of y<sub>in</sub>[1]
#define HWCE_Y_IN_1_BASE_ADDR_OFFSET             0x64

// Base address of y<sub>in</sub>[0]
#define HWCE_Y_IN_0_BASE_ADDR_OFFSET             0x68

// Total number of words to be read for x<sub>in</sub>
#define HWCE_X_TRANS_SIZE_OFFSET                 0x6c

// Line stride and length for x<sub>in</sub>
#define HWCE_X_LINE_STRIDE_LENGTH_OFFSET         0x70

// Feature (block) stride and length for x<sub>in</sub>
#define HWCE_X_FEAT_STRIDE_LENGTH_OFFSET         0x74

// Base address of x<sub>in</sub>
#define HWCE_X_IN_BASE_ADDR_OFFSET               0x78

// Base address of W
#define HWCE_W_BASE_ADDR_OFFSET                  0x7c

// Job configuration register 0
#define HWCE_JOB_CONFIG0_OFFSET                  0x80

// Job configuration register 1
#define HWCE_JOB_CONFIG1_OFFSET                  0x84

// Total number of words to be read for y<sub>in</sub> and y<sub>out</sub>
#define HWCE_Y_TRANS_SIZE_CTX0_OFFSET            0x140

// Line stride and length for y<sub>in</sub> and y<sub>out</sub>
#define HWCE_Y_LINE_STRIDE_LENGTH_CTX0_OFFSET    0x144

// Feature (block) stride and length for y<sub>in</sub> and y<sub>out</sub>
#define HWCE_Y_FEAT_STRIDE_LENGTH_CTX0_OFFSET    0x148

// Base address of y<sub>out</sub>[3]
#define HWCE_Y_OUT_3_BASE_ADDR_CTX0_OFFSET       0x14c

// Base address of y<sub>out</sub>[2]
#define HWCE_Y_OUT_2_BASE_ADDR_CTX0_OFFSET       0x150

// Base address of y<sub>out</sub>[1]
#define HWCE_Y_OUT_1_BASE_ADDR_CTX0_OFFSET       0x154

// Base address of y<sub>out</sub>[0]
#define HWCE_Y_OUT_0_BASE_ADDR_CTX0_OFFSET       0x158

// Base address of y<sub>in</sub>[3]
#define HWCE_Y_IN_3_BASE_ADDR_CTX0_OFFSET        0x15c

// Base address of y<sub>in</sub>[2]
#define HWCE_Y_IN_2_BASE_ADDR_CTX0_OFFSET        0x160

// Base address of y<sub>in</sub>[1]
#define HWCE_Y_IN_1_BASE_ADDR_CTX0_OFFSET        0x164

// Base address of y<sub>in</sub>[0]
#define HWCE_Y_IN_0_BASE_ADDR_CTX0_OFFSET        0x168

// Total number of words to be read for x<sub>in</sub>
#define HWCE_X_TRANS_SIZE_CTX0_OFFSET            0x16c

// Line stride and length for x<sub>in</sub>
#define HWCE_X_LINE_STRIDE_LENGTH_CTX0_OFFSET    0x170

// Feature (block) stride and length for x<sub>in</sub>
#define HWCE_X_FEAT_STRIDE_LENGTH_CTX0_OFFSET    0x174

// Base address of x<sub>in</sub>
#define HWCE_X_IN_BASE_ADDR_CTX0_OFFSET          0x178

// Base address of W
#define HWCE_W_BASE_ADDR_CTX0_OFFSET             0x17c

// Job configuration register 0
#define HWCE_JOB_CONFIG0_CTX0_OFFSET             0x180

// Job configuration register 1
#define HWCE_JOB_CONFIG1_CTX0_OFFSET             0x184

// Total number of words to be read for y<sub>in</sub> and y<sub>out</sub>
#define HWCE_Y_TRANS_SIZE_CTX1_OFFSET            0x240

// Line stride and length for y<sub>in</sub> and y<sub>out</sub>
#define HWCE_Y_LINE_STRIDE_LENGTH_CTX1_OFFSET    0x244

// Feature (block) stride and length for y<sub>in</sub> and y<sub>out</sub>
#define HWCE_Y_FEAT_STRIDE_LENGTH_CTX1_OFFSET    0x248

// Base address of y<sub>out</sub>[3]
#define HWCE_Y_OUT_3_BASE_ADDR_CTX1_OFFSET       0x24c

// Base address of y<sub>out</sub>[2]
#define HWCE_Y_OUT_2_BASE_ADDR_CTX1_OFFSET       0x250

// Base address of y<sub>out</sub>[1]
#define HWCE_Y_OUT_1_BASE_ADDR_CTX1_OFFSET       0x254

// Base address of y<sub>out</sub>[0]
#define HWCE_Y_OUT_0_BASE_ADDR_CTX1_OFFSET       0x258

// Base address of y<sub>in</sub>[3]
#define HWCE_Y_IN_3_BASE_ADDR_CTX1_OFFSET        0x25c

// Base address of y<sub>in</sub>[2]
#define HWCE_Y_IN_2_BASE_ADDR_CTX1_OFFSET        0x260

// Base address of y<sub>in</sub>[1]
#define HWCE_Y_IN_1_BASE_ADDR_CTX1_OFFSET        0x264

// Base address of y<sub>in</sub>[0]
#define HWCE_Y_IN_0_BASE_ADDR_CTX1_OFFSET        0x268

// Total number of words to be read for x<sub>in</sub>
#define HWCE_X_TRANS_SIZE_CTX1_OFFSET            0x26c

// Line stride and length for x<sub>in</sub>
#define HWCE_X_LINE_STRIDE_LENGTH_CTX1_OFFSET    0x270

// Feature (block) stride and length for x<sub>in</sub>
#define HWCE_X_FEAT_STRIDE_LENGTH_CTX1_OFFSET    0x274

// Base address of x<sub>in</sub>
#define HWCE_X_IN_BASE_ADDR_CTX1_OFFSET          0x278

// Base address of W
#define HWCE_W_BASE_ADDR_CTX1_OFFSET             0x27c

// Job configuration register 0
#define HWCE_JOB_CONFIG0_CTX1_OFFSET             0x280

// Job configuration register 1
#define HWCE_JOB_CONFIG1_CTX1_OFFSET             0x284



//
// REGISTERS FIELDS
//

// Write of any value will close the current offload phase by releasing the job offload lock and inserting the currently offloaded job in the control queue. (access: W)
#define HWCE_TRIGGER_ANY_BIT                                         0
#define HWCE_TRIGGER_ANY_WIDTH                                       32
#define HWCE_TRIGGER_ANY_MASK                                        0xffffffff

// If ERR is 0 then the ID of the offloaded job. Otherwise, part of the error code (access: R)
#define HWCE_ACQUIRE_ID_ERR_BIT                                      0
#define HWCE_ACQUIRE_ID_ERR_WIDTH                                    8
#define HWCE_ACQUIRE_ID_ERR_MASK                                     0xff

// An error code if one of the following conditions apply: 1. if the context copy is going on, it will answer 0xfffffffd (-3) 2. else, if the job offload lock has been established, it will answer 0xfffffffe (-2) 3. else, if the job queue is full, it will answer 0xffffffff (-1) (access: R)
#define HWCE_ACQUIRE_ERR_BIT                                         8
#define HWCE_ACQUIRE_ERR_WIDTH                                       24
#define HWCE_ACQUIRE_ERR_MASK                                        0xffffff00

// The number of jobs that the HWCE executed and finished since the last time the same FINISHED_JOBS register was accessed. A read to FINISHED_JOBS returns: - 0x0 if no job was completed since the last access - 0x1 if a single job was completed since the last access - 0x2 if two or more jobs were completed since the last access (access: R)
#define HWCE_FINISHED_JOBS_JOBS_BIT                                  0
#define HWCE_FINISHED_JOBS_JOBS_WIDTH                                32
#define HWCE_FINISHED_JOBS_JOBS_MASK                                 0xffffffff

// Status of the HWCE - 1'b0 Not running a job - 1'b1 Running a job (access: R)
#define HWCE_STATUS_ST_BIT                                           0
#define HWCE_STATUS_ST_WIDTH                                         1
#define HWCE_STATUS_ST_MASK                                          0x1

// ID of the currently running job (access: R)
#define HWCE_RUNNING_JOB_ID_BIT                                      0
#define HWCE_RUNNING_JOB_ID_WIDTH                                    8
#define HWCE_RUNNING_JOB_ID_MASK                                     0xff

// A write of any value to this register will reset the HWCE to its idle state. (access: W)
#define HWCE_SOFT_CLEAR_ANY_BIT                                      0
#define HWCE_SOFT_CLEAR_ANY_WIDTH                                    32
#define HWCE_SOFT_CLEAR_ANY_MASK                                     0xffffffff

// Fixed-point format. Pixels will be shifted to the right by QF bits in the normalization step after the sum-of-products stage. (access: R/W)
#define HWCE_GEN_CONFIG0_QF_BIT                                      0
#define HWCE_GEN_CONFIG0_QF_WIDTH                                    6
#define HWCE_GEN_CONFIG0_QF_MASK                                     0x3f

// Operation type: - 1'b0 - Normal convolution - 1'b1 - Does not flip weights (i.e. implements a stencil instead of a mathematical convolution). (access: R/W)
#define HWCE_GEN_CONFIG0_NF_BIT                                      6
#define HWCE_GEN_CONFIG0_NF_WIDTH                                    1
#define HWCE_GEN_CONFIG0_NF_MASK                                     0x40

// No y_in mode: - 1'b0 - Normal operation - 1'b1 - Disable loading of y_in and add a constant set in the CONFIG2 register (access: R/W)
#define HWCE_GEN_CONFIG0_NY_BIT                                      7
#define HWCE_GEN_CONFIG0_NY_WIDTH                                    1
#define HWCE_GEN_CONFIG0_NY_MASK                                     0x80

// Set unsigned multiplication - 1'b0 - Consider multiplication results as signed fixed-point numbers. - 1'b1 - Consider multiplication results as unsigned fixed-point numbers. (access: R/W)
#define HWCE_GEN_CONFIG0_UNS_BIT                                     8
#define HWCE_GEN_CONFIG0_UNS_WIDTH                                   1
#define HWCE_GEN_CONFIG0_UNS_MASK                                    0x100

// Vector mode: - 2'b00 - mode is scalar (1 feat/cycle, 1x16-bit weights). - 2'b01 - mode is vectorial 2 (2 feat/cycle, 2x8-bit weights). - 2'b10 - mode is vectorial 4 (4 feat/cycle, 4x4-bit weights). (access: R/W)
#define HWCE_GEN_CONFIG0_VECT_BIT                                    9
#define HWCE_GEN_CONFIG0_VECT_WIDTH                                  2
#define HWCE_GEN_CONFIG0_VECT_MASK                                   0x600

// Convolution mode: - 2'b00 - mode is 5x5. - 2'b01 - mode is 3x3. - 2'b10 - mode is 4x7. (access: R/W)
#define HWCE_GEN_CONFIG0_CONV_BIT                                    11
#define HWCE_GEN_CONFIG0_CONV_WIDTH                                  2
#define HWCE_GEN_CONFIG0_CONV_MASK                                   0x1800

// No job copy: - 1'b0 - do job copy - 1'b1 - don't do job copy (access: R/W)
#define HWCE_GEN_CONFIG0_NCP_BIT                                     13
#define HWCE_GEN_CONFIG0_NCP_WIDTH                                   1
#define HWCE_GEN_CONFIG0_NCP_MASK                                    0x2000

// Stride between one FILTER_SIZExFILTER_SIZE filter and the next. (access: R/W)
#define HWCE_GEN_CONFIG0_WSTRIDE_BIT                                 16
#define HWCE_GEN_CONFIG0_WSTRIDE_WIDTH                               16
#define HWCE_GEN_CONFIG0_WSTRIDE_MASK                                0xffff0000

// Shift input pixels to the left by this number of positions when PIXMODE is not 16bit. (access: R/W)
#define HWCE_GEN_CONFIG1_PIXSHIFTL_BIT                               0
#define HWCE_GEN_CONFIG1_PIXSHIFTL_WIDTH                             5
#define HWCE_GEN_CONFIG1_PIXSHIFTL_MASK                              0x1f

// Input pixel size - 2'b00  16bit - 2'b01 - 8bit - 2'b10 - 4bit - 2'b11  16bit bis (access: R/W)
#define HWCE_GEN_CONFIG1_PIXMODE_BIT                                 8
#define HWCE_GEN_CONFIG1_PIXMODE_WIDTH                               2
#define HWCE_GEN_CONFIG1_PIXMODE_MASK                                0x300

// Shift output pixels to the right by this number of positions when PIXMODE is not 16bit. (access: R/W)
#define HWCE_GEN_CONFIG1_PIXSHIFTR_BIT                               16
#define HWCE_GEN_CONFIG1_PIXSHIFTR_WIDTH                             5
#define HWCE_GEN_CONFIG1_PIXSHIFTR_MASK                              0x1f0000

// Contains the total number of words (i.e. double 16bit pixels, quad 8bit pixels, etc.) to be read / written by the streaming source and sink interfaces for y<sub>in</sub> and y<sub>out</sub> streams. (access: R/W)
#define HWCE_Y_TRANS_SIZE_SIZE_BIT                                   0
#define HWCE_Y_TRANS_SIZE_SIZE_WIDTH                                 32
#define HWCE_Y_TRANS_SIZE_SIZE_MASK                                  0xffffffff

// Length of a line in number of words (access: R/W)
#define HWCE_Y_LINE_STRIDE_LENGTH_LENGTH_BIT                         0
#define HWCE_Y_LINE_STRIDE_LENGTH_LENGTH_WIDTH                       16
#define HWCE_Y_LINE_STRIDE_LENGTH_LENGTH_MASK                        0xffff

// Distance in bytes between two consecutive lines. (access: R/W)
#define HWCE_Y_LINE_STRIDE_LENGTH_STRIDE_BIT                         16
#define HWCE_Y_LINE_STRIDE_LENGTH_STRIDE_WIDTH                       16
#define HWCE_Y_LINE_STRIDE_LENGTH_STRIDE_MASK                        0xffff0000

// Length of a line in number of words (access: R/W)
#define HWCE_Y_FEAT_STRIDE_LENGTH_LENGTH_BIT                         0
#define HWCE_Y_FEAT_STRIDE_LENGTH_LENGTH_WIDTH                       16
#define HWCE_Y_FEAT_STRIDE_LENGTH_LENGTH_MASK                        0xffff

// Distance in bytes between two consecutive lines. (access: R/W)
#define HWCE_Y_FEAT_STRIDE_LENGTH_STRIDE_BIT                         16
#define HWCE_Y_FEAT_STRIDE_LENGTH_STRIDE_WIDTH                       16
#define HWCE_Y_FEAT_STRIDE_LENGTH_STRIDE_MASK                        0xffff0000

// Pointer into cluster L1 memory (4x4 bit mode) (access: R/W)
#define HWCE_Y_OUT_3_BASE_ADDR_ADDR_BIT                              0
#define HWCE_Y_OUT_3_BASE_ADDR_ADDR_WIDTH                            32
#define HWCE_Y_OUT_3_BASE_ADDR_ADDR_MASK                             0xffffffff

// Pointer into cluster L1 memory (4x4 bit mode) (access: R/W)
#define HWCE_Y_OUT_2_BASE_ADDR_ADDR_BIT                              0
#define HWCE_Y_OUT_2_BASE_ADDR_ADDR_WIDTH                            32
#define HWCE_Y_OUT_2_BASE_ADDR_ADDR_MASK                             0xffffffff

// Pointer into cluster L1 memory (4x4 bit and 2x8 bit modes) (access: R/W)
#define HWCE_Y_OUT_1_BASE_ADDR_ADDR_BIT                              0
#define HWCE_Y_OUT_1_BASE_ADDR_ADDR_WIDTH                            32
#define HWCE_Y_OUT_1_BASE_ADDR_ADDR_MASK                             0xffffffff

// Pointer into cluster L1 memory (4x4 bit, 2x8 bit and 1x16 bit modes) (access: R/W)
#define HWCE_Y_OUT_0_BASE_ADDR_ADDR_BIT                              0
#define HWCE_Y_OUT_0_BASE_ADDR_ADDR_WIDTH                            32
#define HWCE_Y_OUT_0_BASE_ADDR_ADDR_MASK                             0xffffffff

// Pointer into cluster L1 memory (4x4 bit mode) (access: R/W)
#define HWCE_Y_IN_3_BASE_ADDR_ADDR_BIT                               0
#define HWCE_Y_IN_3_BASE_ADDR_ADDR_WIDTH                             32
#define HWCE_Y_IN_3_BASE_ADDR_ADDR_MASK                              0xffffffff

// Pointer into cluster L1 memory (4x4 bit mode) (access: R/W)
#define HWCE_Y_IN_2_BASE_ADDR_ADDR_BIT                               0
#define HWCE_Y_IN_2_BASE_ADDR_ADDR_WIDTH                             32
#define HWCE_Y_IN_2_BASE_ADDR_ADDR_MASK                              0xffffffff

// Pointer into cluster L1 memory (4x4 bit and 2x8 bit modes) (access: R/W)
#define HWCE_Y_IN_1_BASE_ADDR_ADDR_BIT                               0
#define HWCE_Y_IN_1_BASE_ADDR_ADDR_WIDTH                             32
#define HWCE_Y_IN_1_BASE_ADDR_ADDR_MASK                              0xffffffff

// Pointer into cluster L1 memory (4x4 bit, 2x8 bit and 1x16 bit modes) (access: R/W)
#define HWCE_Y_IN_0_BASE_ADDR_ADDR_BIT                               0
#define HWCE_Y_IN_0_BASE_ADDR_ADDR_WIDTH                             32
#define HWCE_Y_IN_0_BASE_ADDR_ADDR_MASK                              0xffffffff

// Contains the total number of words (i.e. double 16bit pixels, quad 8bit pixels, etc.) to be read / written by the streaming source interface for the x<sub>in</sub>  stream. (access: R/W)
#define HWCE_X_TRANS_SIZE_SIZE_BIT                                   0
#define HWCE_X_TRANS_SIZE_SIZE_WIDTH                                 32
#define HWCE_X_TRANS_SIZE_SIZE_MASK                                  0xffffffff

// Length of a line in number of words (access: R/W)
#define HWCE_X_LINE_STRIDE_LENGTH_LENGTH_BIT                         0
#define HWCE_X_LINE_STRIDE_LENGTH_LENGTH_WIDTH                       16
#define HWCE_X_LINE_STRIDE_LENGTH_LENGTH_MASK                        0xffff

// Distance in bytes between two consecutive lines. (access: R/W)
#define HWCE_X_LINE_STRIDE_LENGTH_STRIDE_BIT                         16
#define HWCE_X_LINE_STRIDE_LENGTH_STRIDE_WIDTH                       16
#define HWCE_X_LINE_STRIDE_LENGTH_STRIDE_MASK                        0xffff0000

// Length of a line in number of words (access: R/W)
#define HWCE_X_FEAT_STRIDE_LENGTH_LENGTH_BIT                         0
#define HWCE_X_FEAT_STRIDE_LENGTH_LENGTH_WIDTH                       16
#define HWCE_X_FEAT_STRIDE_LENGTH_LENGTH_MASK                        0xffff

// Distance in bytes between two consecutive lines. (access: R/W)
#define HWCE_X_FEAT_STRIDE_LENGTH_STRIDE_BIT                         16
#define HWCE_X_FEAT_STRIDE_LENGTH_STRIDE_WIDTH                       16
#define HWCE_X_FEAT_STRIDE_LENGTH_STRIDE_MASK                        0xffff0000

// Pointer into cluster L1 memory (access: R/W)
#define HWCE_X_IN_BASE_ADDR_ADDR_BIT                                 0
#define HWCE_X_IN_BASE_ADDR_ADDR_WIDTH                               32
#define HWCE_X_IN_BASE_ADDR_ADDR_MASK                                0xffffffff

// Pointer into cluster L1 memory (access: R/W)
#define HWCE_W_BASE_ADDR_ADDR_BIT                                    0
#define HWCE_W_BASE_ADDR_ADDR_WIDTH                                  32
#define HWCE_W_BASE_ADDR_ADDR_MASK                                   0xffffffff

// Linebuffer virtual length. Set to the same number as X_LINE_LENGTH. Acceptable LBUFLEN values range between 2 and LINEBUF_LENGTH. (access: R/W)
#define HWCE_JOB_CONFIG0_LBUFLEN_BIT                                 0
#define HWCE_JOB_CONFIG0_LBUFLEN_WIDTH                               10
#define HWCE_JOB_CONFIG0_LBUFLEN_MASK                                0x3ff

// Constant to sum instead of y<sub>in</sub> if the NY flag is active in the CONFIG1 register. (access: R/W)
#define HWCE_JOB_CONFIG0_NOYCONST_BIT                                16
#define HWCE_JOB_CONFIG0_NOYCONST_WIDTH                              16
#define HWCE_JOB_CONFIG0_NOYCONST_MASK                               0xffff0000

// Vector mode mask. Defaults to 0x0, which means that all vectors are enabled. Can be used to disable unused vector routes when using approximate vector or 3x3 mode. The bits are reversed in order, so bit 3 indicates vector 0, bit 2 vector 1, etc. (access: R/W)
#define HWCE_JOB_CONFIG1_VECT_DISABLE_MASK_BIT                       0
#define HWCE_JOB_CONFIG1_VECT_DISABLE_MASK_WIDTH                     4
#define HWCE_JOB_CONFIG1_VECT_DISABLE_MASK_MASK                      0xf

// Output feature (OF) counter wrap parameter. If both WIF and WOF are 1'b0, the looping mechanism is disabled (access: R/W)
#define HWCE_JOB_CONFIG1_WOF_PARAM_BIT                               8
#define HWCE_JOB_CONFIG1_WOF_PARAM_WIDTH                             6
#define HWCE_JOB_CONFIG1_WOF_PARAM_MASK                              0x3f00

// Input feature (IF) counter wrap parameter. If both WIF and WOF are 1'b0, the looping mechanism is disabled (access: R/W)
#define HWCE_JOB_CONFIG1_WIF_PARAM_BIT                               16
#define HWCE_JOB_CONFIG1_WIF_PARAM_WIDTH                             6
#define HWCE_JOB_CONFIG1_WIF_PARAM_MASK                              0x3f0000

// Loop order: - 1'b0 - output features (OF) are the outer loop - 1'b1 - input features (IF) are the outer loop (access: R/W)
#define HWCE_JOB_CONFIG1_LO_BIT                                      24
#define HWCE_JOB_CONFIG1_LO_WIDTH                                    1
#define HWCE_JOB_CONFIG1_LO_MASK                                     0x1000000

// Looping mechanism: - 1'b0 - both counters work as inner loops - 1'b1 - outer loop feature address is updated only when the feature counter reaches the wrap parameter, inner loop feature address is updated when the counter is less than the wrap parameter and reset when it is reached (access: R/W)
#define HWCE_JOB_CONFIG1_LN_BIT                                      25
#define HWCE_JOB_CONFIG1_LN_WIDTH                                    1
#define HWCE_JOB_CONFIG1_LN_MASK                                     0x2000000



//
// REGISTERS STRUCTS
//

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

typedef union {
  struct {
    unsigned int any             :32; // Write of any value will close the current offload phase by releasing the job offload lock and inserting the currently offloaded job in the control queue.
  };
  unsigned int raw;
} __attribute__((packed)) hwce_trigger_t;

typedef union {
  struct {
    unsigned int id_err          :8 ; // If ERR is 0 then the ID of the offloaded job. Otherwise, part of the error code
    unsigned int err             :24; // An error code if one of the following conditions apply: 1. if the context copy is going on, it will answer 0xfffffffd (-3) 2. else, if the job offload lock has been established, it will answer 0xfffffffe (-2) 3. else, if the job queue is full, it will answer 0xffffffff (-1)
  };
  unsigned int raw;
} __attribute__((packed)) hwce_acquire_t;

typedef union {
  struct {
    unsigned int jobs            :32; // The number of jobs that the HWCE executed and finished since the last time the same FINISHED_JOBS register was accessed. A read to FINISHED_JOBS returns: - 0x0 if no job was completed since the last access - 0x1 if a single job was completed since the last access - 0x2 if two or more jobs were completed since the last access
  };
  unsigned int raw;
} __attribute__((packed)) hwce_finished_jobs_t;

typedef union {
  struct {
    unsigned int st              :1 ; // Status of the HWCE - 1'b0 Not running a job - 1'b1 Running a job
  };
  unsigned int raw;
} __attribute__((packed)) hwce_status_t;

typedef union {
  struct {
    unsigned int id              :8 ; // ID of the currently running job
  };
  unsigned int raw;
} __attribute__((packed)) hwce_running_job_t;

typedef union {
  struct {
    unsigned int any             :32; // A write of any value to this register will reset the HWCE to its idle state.
  };
  unsigned int raw;
} __attribute__((packed)) hwce_soft_clear_t;

typedef union {
  struct {
    unsigned int qf              :6 ; // Fixed-point format. Pixels will be shifted to the right by QF bits in the normalization step after the sum-of-products stage.
    unsigned int nf              :1 ; // Operation type: - 1'b0 - Normal convolution - 1'b1 - Does not flip weights (i.e. implements a stencil instead of a mathematical convolution).
    unsigned int ny              :1 ; // No y_in mode: - 1'b0 - Normal operation - 1'b1 - Disable loading of y_in and add a constant set in the CONFIG2 register
    unsigned int uns             :1 ; // Set unsigned multiplication - 1'b0 - Consider multiplication results as signed fixed-point numbers. - 1'b1 - Consider multiplication results as unsigned fixed-point numbers.
    unsigned int vect            :2 ; // Vector mode: - 2'b00 - mode is scalar (1 feat/cycle, 1x16-bit weights). - 2'b01 - mode is vectorial 2 (2 feat/cycle, 2x8-bit weights). - 2'b10 - mode is vectorial 4 (4 feat/cycle, 4x4-bit weights).
    unsigned int conv            :2 ; // Convolution mode: - 2'b00 - mode is 5x5. - 2'b01 - mode is 3x3. - 2'b10 - mode is 4x7.
    unsigned int ncp             :1 ; // No job copy: - 1'b0 - do job copy - 1'b1 - don't do job copy
    unsigned int padding0:2 ;
    unsigned int wstride         :16; // Stride between one FILTER_SIZExFILTER_SIZE filter and the next.
  };
  unsigned int raw;
} __attribute__((packed)) hwce_gen_config0_t;

typedef union {
  struct {
    unsigned int pixshiftl       :5 ; // Shift input pixels to the left by this number of positions when PIXMODE is not 16bit.
    unsigned int padding0:3 ;
    unsigned int pixmode         :2 ; // Input pixel size - 2'b00  16bit - 2'b01 - 8bit - 2'b10 - 4bit - 2'b11  16bit bis
    unsigned int padding1:6 ;
    unsigned int pixshiftr       :5 ; // Shift output pixels to the right by this number of positions when PIXMODE is not 16bit.
  };
  unsigned int raw;
} __attribute__((packed)) hwce_gen_config1_t;

typedef union {
  struct {
    unsigned int size            :32; // Contains the total number of words (i.e. double 16bit pixels, quad 8bit pixels, etc.) to be read / written by the streaming source and sink interfaces for y<sub>in</sub> and y<sub>out</sub> streams.
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_trans_size_t;

typedef union {
  struct {
    unsigned int length          :16; // Length of a line in number of words
    unsigned int stride          :16; // Distance in bytes between two consecutive lines.
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_line_stride_length_t;

typedef union {
  struct {
    unsigned int length          :16; // Length of a line in number of words
    unsigned int stride          :16; // Distance in bytes between two consecutive lines.
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_feat_stride_length_t;

typedef union {
  struct {
    unsigned int addr            :32; // Pointer into cluster L1 memory (4x4 bit mode)
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_out_3_base_addr_t;

typedef union {
  struct {
    unsigned int addr            :32; // Pointer into cluster L1 memory (4x4 bit mode)
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_out_2_base_addr_t;

typedef union {
  struct {
    unsigned int addr            :32; // Pointer into cluster L1 memory (4x4 bit and 2x8 bit modes)
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_out_1_base_addr_t;

typedef union {
  struct {
    unsigned int addr            :32; // Pointer into cluster L1 memory (4x4 bit, 2x8 bit and 1x16 bit modes)
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_out_0_base_addr_t;

typedef union {
  struct {
    unsigned int addr            :32; // Pointer into cluster L1 memory (4x4 bit mode)
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_in_3_base_addr_t;

typedef union {
  struct {
    unsigned int addr            :32; // Pointer into cluster L1 memory (4x4 bit mode)
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_in_2_base_addr_t;

typedef union {
  struct {
    unsigned int addr            :32; // Pointer into cluster L1 memory (4x4 bit and 2x8 bit modes)
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_in_1_base_addr_t;

typedef union {
  struct {
    unsigned int addr            :32; // Pointer into cluster L1 memory (4x4 bit, 2x8 bit and 1x16 bit modes)
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_in_0_base_addr_t;

typedef union {
  struct {
    unsigned int size            :32; // Contains the total number of words (i.e. double 16bit pixels, quad 8bit pixels, etc.) to be read / written by the streaming source interface for the x<sub>in</sub>  stream.
  };
  unsigned int raw;
} __attribute__((packed)) hwce_x_trans_size_t;

typedef union {
  struct {
    unsigned int length          :16; // Length of a line in number of words
    unsigned int stride          :16; // Distance in bytes between two consecutive lines.
  };
  unsigned int raw;
} __attribute__((packed)) hwce_x_line_stride_length_t;

typedef union {
  struct {
    unsigned int length          :16; // Length of a line in number of words
    unsigned int stride          :16; // Distance in bytes between two consecutive lines.
  };
  unsigned int raw;
} __attribute__((packed)) hwce_x_feat_stride_length_t;

typedef union {
  struct {
    unsigned int addr            :32; // Pointer into cluster L1 memory
  };
  unsigned int raw;
} __attribute__((packed)) hwce_x_in_base_addr_t;

typedef union {
  struct {
    unsigned int addr            :32; // Pointer into cluster L1 memory
  };
  unsigned int raw;
} __attribute__((packed)) hwce_w_base_addr_t;

typedef union {
  struct {
    unsigned int lbuflen         :10; // Linebuffer virtual length. Set to the same number as X_LINE_LENGTH. Acceptable LBUFLEN values range between 2 and LINEBUF_LENGTH.
    unsigned int padding0:6 ;
    unsigned int noyconst        :16; // Constant to sum instead of y<sub>in</sub> if the NY flag is active in the CONFIG1 register.
  };
  unsigned int raw;
} __attribute__((packed)) hwce_job_config0_t;

typedef union {
  struct {
    unsigned int vect_disable_mask:4 ; // Vector mode mask. Defaults to 0x0, which means that all vectors are enabled. Can be used to disable unused vector routes when using approximate vector or 3x3 mode. The bits are reversed in order, so bit 3 indicates vector 0, bit 2 vector 1, etc.
    unsigned int padding0:4 ;
    unsigned int wof_param       :6 ; // Output feature (OF) counter wrap parameter. If both WIF and WOF are 1'b0, the looping mechanism is disabled
    unsigned int padding1:2 ;
    unsigned int wif_param       :6 ; // Input feature (IF) counter wrap parameter. If both WIF and WOF are 1'b0, the looping mechanism is disabled
    unsigned int padding2:2 ;
    unsigned int lo              :1 ; // Loop order: - 1'b0 - output features (OF) are the outer loop - 1'b1 - input features (IF) are the outer loop
    unsigned int ln              :1 ; // Looping mechanism: - 1'b0 - both counters work as inner loops - 1'b1 - outer loop feature address is updated only when the feature counter reaches the wrap parameter, inner loop feature address is updated when the counter is less than the wrap parameter and reset when it is reached
  };
  unsigned int raw;
} __attribute__((packed)) hwce_job_config1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_trans_size_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_line_stride_length_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_feat_stride_length_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_out_3_base_addr_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_out_2_base_addr_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_out_1_base_addr_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_out_0_base_addr_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_in_3_base_addr_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_in_2_base_addr_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_in_1_base_addr_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_in_0_base_addr_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_x_trans_size_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_x_line_stride_length_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_x_feat_stride_length_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_x_in_base_addr_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_w_base_addr_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_job_config0_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_job_config1_ctx0_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_trans_size_ctx1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_line_stride_length_ctx1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_feat_stride_length_ctx1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_out_3_base_addr_ctx1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_out_2_base_addr_ctx1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_out_1_base_addr_ctx1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_out_0_base_addr_ctx1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_in_3_base_addr_ctx1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_in_2_base_addr_ctx1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_in_1_base_addr_ctx1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_y_in_0_base_addr_ctx1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_x_trans_size_ctx1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_x_line_stride_length_ctx1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_x_feat_stride_length_ctx1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_x_in_base_addr_ctx1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_w_base_addr_ctx1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_job_config0_ctx1_t;

typedef union {
  struct {
  };
  unsigned int raw;
} __attribute__((packed)) hwce_job_config1_ctx1_t;

#endif



//
// REGISTERS STRUCTS
//

#ifdef __GVSOC__

class vp_hwce_trigger : public vp::reg_32
{
public:
  inline void any_set(uint32_t value) { this->set_field(value, HWCE_TRIGGER_ANY_BIT, HWCE_TRIGGER_ANY_WIDTH); }
  inline uint32_t any_get() { return this->get_field(HWCE_TRIGGER_ANY_BIT, HWCE_TRIGGER_ANY_WIDTH); }
};

class vp_hwce_acquire : public vp::reg_32
{
public:
  inline void id_err_set(uint32_t value) { this->set_field(value, HWCE_ACQUIRE_ID_ERR_BIT, HWCE_ACQUIRE_ID_ERR_WIDTH); }
  inline uint32_t id_err_get() { return this->get_field(HWCE_ACQUIRE_ID_ERR_BIT, HWCE_ACQUIRE_ID_ERR_WIDTH); }
  inline void err_set(uint32_t value) { this->set_field(value, HWCE_ACQUIRE_ERR_BIT, HWCE_ACQUIRE_ERR_WIDTH); }
  inline uint32_t err_get() { return this->get_field(HWCE_ACQUIRE_ERR_BIT, HWCE_ACQUIRE_ERR_WIDTH); }
};

class vp_hwce_finished_jobs : public vp::reg_32
{
public:
  inline void jobs_set(uint32_t value) { this->set_field(value, HWCE_FINISHED_JOBS_JOBS_BIT, HWCE_FINISHED_JOBS_JOBS_WIDTH); }
  inline uint32_t jobs_get() { return this->get_field(HWCE_FINISHED_JOBS_JOBS_BIT, HWCE_FINISHED_JOBS_JOBS_WIDTH); }
};

class vp_hwce_status : public vp::reg_32
{
public:
  inline void st_set(uint32_t value) { this->set_field(value, HWCE_STATUS_ST_BIT, HWCE_STATUS_ST_WIDTH); }
  inline uint32_t st_get() { return this->get_field(HWCE_STATUS_ST_BIT, HWCE_STATUS_ST_WIDTH); }
};

class vp_hwce_running_job : public vp::reg_32
{
public:
  inline void id_set(uint32_t value) { this->set_field(value, HWCE_RUNNING_JOB_ID_BIT, HWCE_RUNNING_JOB_ID_WIDTH); }
  inline uint32_t id_get() { return this->get_field(HWCE_RUNNING_JOB_ID_BIT, HWCE_RUNNING_JOB_ID_WIDTH); }
};

class vp_hwce_soft_clear : public vp::reg_32
{
public:
  inline void any_set(uint32_t value) { this->set_field(value, HWCE_SOFT_CLEAR_ANY_BIT, HWCE_SOFT_CLEAR_ANY_WIDTH); }
  inline uint32_t any_get() { return this->get_field(HWCE_SOFT_CLEAR_ANY_BIT, HWCE_SOFT_CLEAR_ANY_WIDTH); }
};

class vp_hwce_gen_config0 : public vp::reg_32
{
public:
  inline void qf_set(uint32_t value) { this->set_field(value, HWCE_GEN_CONFIG0_QF_BIT, HWCE_GEN_CONFIG0_QF_WIDTH); }
  inline uint32_t qf_get() { return this->get_field(HWCE_GEN_CONFIG0_QF_BIT, HWCE_GEN_CONFIG0_QF_WIDTH); }
  inline void nf_set(uint32_t value) { this->set_field(value, HWCE_GEN_CONFIG0_NF_BIT, HWCE_GEN_CONFIG0_NF_WIDTH); }
  inline uint32_t nf_get() { return this->get_field(HWCE_GEN_CONFIG0_NF_BIT, HWCE_GEN_CONFIG0_NF_WIDTH); }
  inline void ny_set(uint32_t value) { this->set_field(value, HWCE_GEN_CONFIG0_NY_BIT, HWCE_GEN_CONFIG0_NY_WIDTH); }
  inline uint32_t ny_get() { return this->get_field(HWCE_GEN_CONFIG0_NY_BIT, HWCE_GEN_CONFIG0_NY_WIDTH); }
  inline void uns_set(uint32_t value) { this->set_field(value, HWCE_GEN_CONFIG0_UNS_BIT, HWCE_GEN_CONFIG0_UNS_WIDTH); }
  inline uint32_t uns_get() { return this->get_field(HWCE_GEN_CONFIG0_UNS_BIT, HWCE_GEN_CONFIG0_UNS_WIDTH); }
  inline void vect_set(uint32_t value) { this->set_field(value, HWCE_GEN_CONFIG0_VECT_BIT, HWCE_GEN_CONFIG0_VECT_WIDTH); }
  inline uint32_t vect_get() { return this->get_field(HWCE_GEN_CONFIG0_VECT_BIT, HWCE_GEN_CONFIG0_VECT_WIDTH); }
  inline void conv_set(uint32_t value) { this->set_field(value, HWCE_GEN_CONFIG0_CONV_BIT, HWCE_GEN_CONFIG0_CONV_WIDTH); }
  inline uint32_t conv_get() { return this->get_field(HWCE_GEN_CONFIG0_CONV_BIT, HWCE_GEN_CONFIG0_CONV_WIDTH); }
  inline void ncp_set(uint32_t value) { this->set_field(value, HWCE_GEN_CONFIG0_NCP_BIT, HWCE_GEN_CONFIG0_NCP_WIDTH); }
  inline uint32_t ncp_get() { return this->get_field(HWCE_GEN_CONFIG0_NCP_BIT, HWCE_GEN_CONFIG0_NCP_WIDTH); }
  inline void wstride_set(uint32_t value) { this->set_field(value, HWCE_GEN_CONFIG0_WSTRIDE_BIT, HWCE_GEN_CONFIG0_WSTRIDE_WIDTH); }
  inline uint32_t wstride_get() { return this->get_field(HWCE_GEN_CONFIG0_WSTRIDE_BIT, HWCE_GEN_CONFIG0_WSTRIDE_WIDTH); }
};

class vp_hwce_gen_config1 : public vp::reg_32
{
public:
  inline void pixshiftl_set(uint32_t value) { this->set_field(value, HWCE_GEN_CONFIG1_PIXSHIFTL_BIT, HWCE_GEN_CONFIG1_PIXSHIFTL_WIDTH); }
  inline uint32_t pixshiftl_get() { return this->get_field(HWCE_GEN_CONFIG1_PIXSHIFTL_BIT, HWCE_GEN_CONFIG1_PIXSHIFTL_WIDTH); }
  inline void pixmode_set(uint32_t value) { this->set_field(value, HWCE_GEN_CONFIG1_PIXMODE_BIT, HWCE_GEN_CONFIG1_PIXMODE_WIDTH); }
  inline uint32_t pixmode_get() { return this->get_field(HWCE_GEN_CONFIG1_PIXMODE_BIT, HWCE_GEN_CONFIG1_PIXMODE_WIDTH); }
  inline void pixshiftr_set(uint32_t value) { this->set_field(value, HWCE_GEN_CONFIG1_PIXSHIFTR_BIT, HWCE_GEN_CONFIG1_PIXSHIFTR_WIDTH); }
  inline uint32_t pixshiftr_get() { return this->get_field(HWCE_GEN_CONFIG1_PIXSHIFTR_BIT, HWCE_GEN_CONFIG1_PIXSHIFTR_WIDTH); }
};

class vp_hwce_y_trans_size : public vp::reg_32
{
public:
  inline void size_set(uint32_t value) { this->set_field(value, HWCE_Y_TRANS_SIZE_SIZE_BIT, HWCE_Y_TRANS_SIZE_SIZE_WIDTH); }
  inline uint32_t size_get() { return this->get_field(HWCE_Y_TRANS_SIZE_SIZE_BIT, HWCE_Y_TRANS_SIZE_SIZE_WIDTH); }
};

class vp_hwce_y_line_stride_length : public vp::reg_32
{
public:
  inline void length_set(uint32_t value) { this->set_field(value, HWCE_Y_LINE_STRIDE_LENGTH_LENGTH_BIT, HWCE_Y_LINE_STRIDE_LENGTH_LENGTH_WIDTH); }
  inline uint32_t length_get() { return this->get_field(HWCE_Y_LINE_STRIDE_LENGTH_LENGTH_BIT, HWCE_Y_LINE_STRIDE_LENGTH_LENGTH_WIDTH); }
  inline void stride_set(uint32_t value) { this->set_field(value, HWCE_Y_LINE_STRIDE_LENGTH_STRIDE_BIT, HWCE_Y_LINE_STRIDE_LENGTH_STRIDE_WIDTH); }
  inline uint32_t stride_get() { return this->get_field(HWCE_Y_LINE_STRIDE_LENGTH_STRIDE_BIT, HWCE_Y_LINE_STRIDE_LENGTH_STRIDE_WIDTH); }
};

class vp_hwce_y_feat_stride_length : public vp::reg_32
{
public:
  inline void length_set(uint32_t value) { this->set_field(value, HWCE_Y_FEAT_STRIDE_LENGTH_LENGTH_BIT, HWCE_Y_FEAT_STRIDE_LENGTH_LENGTH_WIDTH); }
  inline uint32_t length_get() { return this->get_field(HWCE_Y_FEAT_STRIDE_LENGTH_LENGTH_BIT, HWCE_Y_FEAT_STRIDE_LENGTH_LENGTH_WIDTH); }
  inline void stride_set(uint32_t value) { this->set_field(value, HWCE_Y_FEAT_STRIDE_LENGTH_STRIDE_BIT, HWCE_Y_FEAT_STRIDE_LENGTH_STRIDE_WIDTH); }
  inline uint32_t stride_get() { return this->get_field(HWCE_Y_FEAT_STRIDE_LENGTH_STRIDE_BIT, HWCE_Y_FEAT_STRIDE_LENGTH_STRIDE_WIDTH); }
};

class vp_hwce_y_out_3_base_addr : public vp::reg_32
{
public:
  inline void addr_set(uint32_t value) { this->set_field(value, HWCE_Y_OUT_3_BASE_ADDR_ADDR_BIT, HWCE_Y_OUT_3_BASE_ADDR_ADDR_WIDTH); }
  inline uint32_t addr_get() { return this->get_field(HWCE_Y_OUT_3_BASE_ADDR_ADDR_BIT, HWCE_Y_OUT_3_BASE_ADDR_ADDR_WIDTH); }
};

class vp_hwce_y_out_2_base_addr : public vp::reg_32
{
public:
  inline void addr_set(uint32_t value) { this->set_field(value, HWCE_Y_OUT_2_BASE_ADDR_ADDR_BIT, HWCE_Y_OUT_2_BASE_ADDR_ADDR_WIDTH); }
  inline uint32_t addr_get() { return this->get_field(HWCE_Y_OUT_2_BASE_ADDR_ADDR_BIT, HWCE_Y_OUT_2_BASE_ADDR_ADDR_WIDTH); }
};

class vp_hwce_y_out_1_base_addr : public vp::reg_32
{
public:
  inline void addr_set(uint32_t value) { this->set_field(value, HWCE_Y_OUT_1_BASE_ADDR_ADDR_BIT, HWCE_Y_OUT_1_BASE_ADDR_ADDR_WIDTH); }
  inline uint32_t addr_get() { return this->get_field(HWCE_Y_OUT_1_BASE_ADDR_ADDR_BIT, HWCE_Y_OUT_1_BASE_ADDR_ADDR_WIDTH); }
};

class vp_hwce_y_out_0_base_addr : public vp::reg_32
{
public:
  inline void addr_set(uint32_t value) { this->set_field(value, HWCE_Y_OUT_0_BASE_ADDR_ADDR_BIT, HWCE_Y_OUT_0_BASE_ADDR_ADDR_WIDTH); }
  inline uint32_t addr_get() { return this->get_field(HWCE_Y_OUT_0_BASE_ADDR_ADDR_BIT, HWCE_Y_OUT_0_BASE_ADDR_ADDR_WIDTH); }
};

class vp_hwce_y_in_3_base_addr : public vp::reg_32
{
public:
  inline void addr_set(uint32_t value) { this->set_field(value, HWCE_Y_IN_3_BASE_ADDR_ADDR_BIT, HWCE_Y_IN_3_BASE_ADDR_ADDR_WIDTH); }
  inline uint32_t addr_get() { return this->get_field(HWCE_Y_IN_3_BASE_ADDR_ADDR_BIT, HWCE_Y_IN_3_BASE_ADDR_ADDR_WIDTH); }
};

class vp_hwce_y_in_2_base_addr : public vp::reg_32
{
public:
  inline void addr_set(uint32_t value) { this->set_field(value, HWCE_Y_IN_2_BASE_ADDR_ADDR_BIT, HWCE_Y_IN_2_BASE_ADDR_ADDR_WIDTH); }
  inline uint32_t addr_get() { return this->get_field(HWCE_Y_IN_2_BASE_ADDR_ADDR_BIT, HWCE_Y_IN_2_BASE_ADDR_ADDR_WIDTH); }
};

class vp_hwce_y_in_1_base_addr : public vp::reg_32
{
public:
  inline void addr_set(uint32_t value) { this->set_field(value, HWCE_Y_IN_1_BASE_ADDR_ADDR_BIT, HWCE_Y_IN_1_BASE_ADDR_ADDR_WIDTH); }
  inline uint32_t addr_get() { return this->get_field(HWCE_Y_IN_1_BASE_ADDR_ADDR_BIT, HWCE_Y_IN_1_BASE_ADDR_ADDR_WIDTH); }
};

class vp_hwce_y_in_0_base_addr : public vp::reg_32
{
public:
  inline void addr_set(uint32_t value) { this->set_field(value, HWCE_Y_IN_0_BASE_ADDR_ADDR_BIT, HWCE_Y_IN_0_BASE_ADDR_ADDR_WIDTH); }
  inline uint32_t addr_get() { return this->get_field(HWCE_Y_IN_0_BASE_ADDR_ADDR_BIT, HWCE_Y_IN_0_BASE_ADDR_ADDR_WIDTH); }
};

class vp_hwce_x_trans_size : public vp::reg_32
{
public:
  inline void size_set(uint32_t value) { this->set_field(value, HWCE_X_TRANS_SIZE_SIZE_BIT, HWCE_X_TRANS_SIZE_SIZE_WIDTH); }
  inline uint32_t size_get() { return this->get_field(HWCE_X_TRANS_SIZE_SIZE_BIT, HWCE_X_TRANS_SIZE_SIZE_WIDTH); }
};

class vp_hwce_x_line_stride_length : public vp::reg_32
{
public:
  inline void length_set(uint32_t value) { this->set_field(value, HWCE_X_LINE_STRIDE_LENGTH_LENGTH_BIT, HWCE_X_LINE_STRIDE_LENGTH_LENGTH_WIDTH); }
  inline uint32_t length_get() { return this->get_field(HWCE_X_LINE_STRIDE_LENGTH_LENGTH_BIT, HWCE_X_LINE_STRIDE_LENGTH_LENGTH_WIDTH); }
  inline void stride_set(uint32_t value) { this->set_field(value, HWCE_X_LINE_STRIDE_LENGTH_STRIDE_BIT, HWCE_X_LINE_STRIDE_LENGTH_STRIDE_WIDTH); }
  inline uint32_t stride_get() { return this->get_field(HWCE_X_LINE_STRIDE_LENGTH_STRIDE_BIT, HWCE_X_LINE_STRIDE_LENGTH_STRIDE_WIDTH); }
};

class vp_hwce_x_feat_stride_length : public vp::reg_32
{
public:
  inline void length_set(uint32_t value) { this->set_field(value, HWCE_X_FEAT_STRIDE_LENGTH_LENGTH_BIT, HWCE_X_FEAT_STRIDE_LENGTH_LENGTH_WIDTH); }
  inline uint32_t length_get() { return this->get_field(HWCE_X_FEAT_STRIDE_LENGTH_LENGTH_BIT, HWCE_X_FEAT_STRIDE_LENGTH_LENGTH_WIDTH); }
  inline void stride_set(uint32_t value) { this->set_field(value, HWCE_X_FEAT_STRIDE_LENGTH_STRIDE_BIT, HWCE_X_FEAT_STRIDE_LENGTH_STRIDE_WIDTH); }
  inline uint32_t stride_get() { return this->get_field(HWCE_X_FEAT_STRIDE_LENGTH_STRIDE_BIT, HWCE_X_FEAT_STRIDE_LENGTH_STRIDE_WIDTH); }
};

class vp_hwce_x_in_base_addr : public vp::reg_32
{
public:
  inline void addr_set(uint32_t value) { this->set_field(value, HWCE_X_IN_BASE_ADDR_ADDR_BIT, HWCE_X_IN_BASE_ADDR_ADDR_WIDTH); }
  inline uint32_t addr_get() { return this->get_field(HWCE_X_IN_BASE_ADDR_ADDR_BIT, HWCE_X_IN_BASE_ADDR_ADDR_WIDTH); }
};

class vp_hwce_w_base_addr : public vp::reg_32
{
public:
  inline void addr_set(uint32_t value) { this->set_field(value, HWCE_W_BASE_ADDR_ADDR_BIT, HWCE_W_BASE_ADDR_ADDR_WIDTH); }
  inline uint32_t addr_get() { return this->get_field(HWCE_W_BASE_ADDR_ADDR_BIT, HWCE_W_BASE_ADDR_ADDR_WIDTH); }
};

class vp_hwce_job_config0 : public vp::reg_32
{
public:
  inline void lbuflen_set(uint32_t value) { this->set_field(value, HWCE_JOB_CONFIG0_LBUFLEN_BIT, HWCE_JOB_CONFIG0_LBUFLEN_WIDTH); }
  inline uint32_t lbuflen_get() { return this->get_field(HWCE_JOB_CONFIG0_LBUFLEN_BIT, HWCE_JOB_CONFIG0_LBUFLEN_WIDTH); }
  inline void noyconst_set(uint32_t value) { this->set_field(value, HWCE_JOB_CONFIG0_NOYCONST_BIT, HWCE_JOB_CONFIG0_NOYCONST_WIDTH); }
  inline uint32_t noyconst_get() { return this->get_field(HWCE_JOB_CONFIG0_NOYCONST_BIT, HWCE_JOB_CONFIG0_NOYCONST_WIDTH); }
};

class vp_hwce_job_config1 : public vp::reg_32
{
public:
  inline void vect_disable_mask_set(uint32_t value) { this->set_field(value, HWCE_JOB_CONFIG1_VECT_DISABLE_MASK_BIT, HWCE_JOB_CONFIG1_VECT_DISABLE_MASK_WIDTH); }
  inline uint32_t vect_disable_mask_get() { return this->get_field(HWCE_JOB_CONFIG1_VECT_DISABLE_MASK_BIT, HWCE_JOB_CONFIG1_VECT_DISABLE_MASK_WIDTH); }
  inline void wof_param_set(uint32_t value) { this->set_field(value, HWCE_JOB_CONFIG1_WOF_PARAM_BIT, HWCE_JOB_CONFIG1_WOF_PARAM_WIDTH); }
  inline uint32_t wof_param_get() { return this->get_field(HWCE_JOB_CONFIG1_WOF_PARAM_BIT, HWCE_JOB_CONFIG1_WOF_PARAM_WIDTH); }
  inline void wif_param_set(uint32_t value) { this->set_field(value, HWCE_JOB_CONFIG1_WIF_PARAM_BIT, HWCE_JOB_CONFIG1_WIF_PARAM_WIDTH); }
  inline uint32_t wif_param_get() { return this->get_field(HWCE_JOB_CONFIG1_WIF_PARAM_BIT, HWCE_JOB_CONFIG1_WIF_PARAM_WIDTH); }
  inline void lo_set(uint32_t value) { this->set_field(value, HWCE_JOB_CONFIG1_LO_BIT, HWCE_JOB_CONFIG1_LO_WIDTH); }
  inline uint32_t lo_get() { return this->get_field(HWCE_JOB_CONFIG1_LO_BIT, HWCE_JOB_CONFIG1_LO_WIDTH); }
  inline void ln_set(uint32_t value) { this->set_field(value, HWCE_JOB_CONFIG1_LN_BIT, HWCE_JOB_CONFIG1_LN_WIDTH); }
  inline uint32_t ln_get() { return this->get_field(HWCE_JOB_CONFIG1_LN_BIT, HWCE_JOB_CONFIG1_LN_WIDTH); }
};

class vp_hwce_y_trans_size_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_y_line_stride_length_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_y_feat_stride_length_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_y_out_3_base_addr_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_y_out_2_base_addr_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_y_out_1_base_addr_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_y_out_0_base_addr_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_y_in_3_base_addr_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_y_in_2_base_addr_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_y_in_1_base_addr_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_y_in_0_base_addr_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_x_trans_size_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_x_line_stride_length_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_x_feat_stride_length_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_x_in_base_addr_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_w_base_addr_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_job_config0_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_job_config1_ctx0 : public vp::reg_32
{
public:
};

class vp_hwce_y_trans_size_ctx1 : public vp::reg_32
{
public:
};

class vp_hwce_y_line_stride_length_ctx1 : public vp::reg_32
{
public:
};

class vp_hwce_y_feat_stride_length_ctx1 : public vp::reg_32
{
public:
};

class vp_hwce_y_out_3_base_addr_ctx1 : public vp::reg_32
{
public:
};

class vp_hwce_y_out_2_base_addr_ctx1 : public vp::reg_32
{
public:
};

class vp_hwce_y_out_1_base_addr_ctx1 : public vp::reg_32
{
public:
};

class vp_hwce_y_out_0_base_addr_ctx1 : public vp::reg_32
{
public:
};

class vp_hwce_y_in_3_base_addr_ctx1 : public vp::reg_32
{
public:
};

class vp_hwce_y_in_2_base_addr_ctx1 : public vp::reg_32
{
public:
};

class vp_hwce_y_in_1_base_addr_ctx1 : public vp::reg_32
{
public:
};

class vp_hwce_y_in_0_base_addr_ctx1 : public vp::reg_32
{
public:
};

class vp_hwce_x_trans_size_ctx1 : public vp::reg_32
{
public:
};

class vp_hwce_x_line_stride_length_ctx1 : public vp::reg_32
{
public:
};

class vp_hwce_x_feat_stride_length_ctx1 : public vp::reg_32
{
public:
};

class vp_hwce_x_in_base_addr_ctx1 : public vp::reg_32
{
public:
};

class vp_hwce_w_base_addr_ctx1 : public vp::reg_32
{
public:
};

class vp_hwce_job_config0_ctx1 : public vp::reg_32
{
public:
};

class vp_hwce_job_config1_ctx1 : public vp::reg_32
{
public:
};

#endif



//
// REGISTERS GLOBAL STRUCT
//

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

typedef struct {
  unsigned int trigger         ; // Trigger the execution of an offloaded job
  unsigned int acquire         ; // Acquire the lock to offload job
  unsigned int finished_jobs   ; // Number of concluded jobs since last read
  unsigned int status          ; // Status of the HWCE
  unsigned int running_job     ; // ID of the currently running job
  unsigned int soft_clear      ; // Reset HWCE to known idle state
  unsigned int gen_config0     ; // Generic configuration register 0
  unsigned int gen_config1     ; // Generic configuration register 1
  unsigned int y_trans_size    ; // Total number of words to be read for y<sub>in</sub> and y<sub>out</sub>
  unsigned int y_line_stride_length; // Line stride and length for y<sub>in</sub> and y<sub>out</sub>
  unsigned int y_feat_stride_length; // Feature (block) stride and length for y<sub>in</sub> and y<sub>out</sub>
  unsigned int y_out_3_base_addr; // Base address of y<sub>out</sub>[3]
  unsigned int y_out_2_base_addr; // Base address of y<sub>out</sub>[2]
  unsigned int y_out_1_base_addr; // Base address of y<sub>out</sub>[1]
  unsigned int y_out_0_base_addr; // Base address of y<sub>out</sub>[0]
  unsigned int y_in_3_base_addr; // Base address of y<sub>in</sub>[3]
  unsigned int y_in_2_base_addr; // Base address of y<sub>in</sub>[2]
  unsigned int y_in_1_base_addr; // Base address of y<sub>in</sub>[1]
  unsigned int y_in_0_base_addr; // Base address of y<sub>in</sub>[0]
  unsigned int x_trans_size    ; // Total number of words to be read for x<sub>in</sub>
  unsigned int x_line_stride_length; // Line stride and length for x<sub>in</sub>
  unsigned int x_feat_stride_length; // Feature (block) stride and length for x<sub>in</sub>
  unsigned int x_in_base_addr  ; // Base address of x<sub>in</sub>
  unsigned int w_base_addr     ; // Base address of W
  unsigned int job_config0     ; // Job configuration register 0
  unsigned int job_config1     ; // Job configuration register 1
  unsigned int y_trans_size_ctx0; // Total number of words to be read for y<sub>in</sub> and y<sub>out</sub>
  unsigned int y_line_stride_length_ctx0; // Line stride and length for y<sub>in</sub> and y<sub>out</sub>
  unsigned int y_feat_stride_length_ctx0; // Feature (block) stride and length for y<sub>in</sub> and y<sub>out</sub>
  unsigned int y_out_3_base_addr_ctx0; // Base address of y<sub>out</sub>[3]
  unsigned int y_out_2_base_addr_ctx0; // Base address of y<sub>out</sub>[2]
  unsigned int y_out_1_base_addr_ctx0; // Base address of y<sub>out</sub>[1]
  unsigned int y_out_0_base_addr_ctx0; // Base address of y<sub>out</sub>[0]
  unsigned int y_in_3_base_addr_ctx0; // Base address of y<sub>in</sub>[3]
  unsigned int y_in_2_base_addr_ctx0; // Base address of y<sub>in</sub>[2]
  unsigned int y_in_1_base_addr_ctx0; // Base address of y<sub>in</sub>[1]
  unsigned int y_in_0_base_addr_ctx0; // Base address of y<sub>in</sub>[0]
  unsigned int x_trans_size_ctx0; // Total number of words to be read for x<sub>in</sub>
  unsigned int x_line_stride_length_ctx0; // Line stride and length for x<sub>in</sub>
  unsigned int x_feat_stride_length_ctx0; // Feature (block) stride and length for x<sub>in</sub>
  unsigned int x_in_base_addr_ctx0; // Base address of x<sub>in</sub>
  unsigned int w_base_addr_ctx0; // Base address of W
  unsigned int job_config0_ctx0; // Job configuration register 0
  unsigned int job_config1_ctx0; // Job configuration register 1
  unsigned int y_trans_size_ctx1; // Total number of words to be read for y<sub>in</sub> and y<sub>out</sub>
  unsigned int y_line_stride_length_ctx1; // Line stride and length for y<sub>in</sub> and y<sub>out</sub>
  unsigned int y_feat_stride_length_ctx1; // Feature (block) stride and length for y<sub>in</sub> and y<sub>out</sub>
  unsigned int y_out_3_base_addr_ctx1; // Base address of y<sub>out</sub>[3]
  unsigned int y_out_2_base_addr_ctx1; // Base address of y<sub>out</sub>[2]
  unsigned int y_out_1_base_addr_ctx1; // Base address of y<sub>out</sub>[1]
  unsigned int y_out_0_base_addr_ctx1; // Base address of y<sub>out</sub>[0]
  unsigned int y_in_3_base_addr_ctx1; // Base address of y<sub>in</sub>[3]
  unsigned int y_in_2_base_addr_ctx1; // Base address of y<sub>in</sub>[2]
  unsigned int y_in_1_base_addr_ctx1; // Base address of y<sub>in</sub>[1]
  unsigned int y_in_0_base_addr_ctx1; // Base address of y<sub>in</sub>[0]
  unsigned int x_trans_size_ctx1; // Total number of words to be read for x<sub>in</sub>
  unsigned int x_line_stride_length_ctx1; // Line stride and length for x<sub>in</sub>
  unsigned int x_feat_stride_length_ctx1; // Feature (block) stride and length for x<sub>in</sub>
  unsigned int x_in_base_addr_ctx1; // Base address of x<sub>in</sub>
  unsigned int w_base_addr_ctx1; // Base address of W
  unsigned int job_config0_ctx1; // Job configuration register 0
  unsigned int job_config1_ctx1; // Job configuration register 1
} __attribute__((packed)) hwce_hwce_t;

#endif



//
// REGISTERS ACCESS FUNCTIONS
//

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

static inline uint32_t hwce_trigger_get(uint32_t base) { return ARCHI_READ(base, HWCE_TRIGGER_OFFSET); }
static inline void hwce_trigger_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_TRIGGER_OFFSET, value); }

static inline uint32_t hwce_acquire_get(uint32_t base) { return ARCHI_READ(base, HWCE_ACQUIRE_OFFSET); }
static inline void hwce_acquire_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_ACQUIRE_OFFSET, value); }

static inline uint32_t hwce_finished_jobs_get(uint32_t base) { return ARCHI_READ(base, HWCE_FINISHED_JOBS_OFFSET); }
static inline void hwce_finished_jobs_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_FINISHED_JOBS_OFFSET, value); }

static inline uint32_t hwce_status_get(uint32_t base) { return ARCHI_READ(base, HWCE_STATUS_OFFSET); }
static inline void hwce_status_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_STATUS_OFFSET, value); }

static inline uint32_t hwce_running_job_get(uint32_t base) { return ARCHI_READ(base, HWCE_RUNNING_JOB_OFFSET); }
static inline void hwce_running_job_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_RUNNING_JOB_OFFSET, value); }

static inline uint32_t hwce_soft_clear_get(uint32_t base) { return ARCHI_READ(base, HWCE_SOFT_CLEAR_OFFSET); }
static inline void hwce_soft_clear_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_SOFT_CLEAR_OFFSET, value); }

static inline uint32_t hwce_gen_config0_get(uint32_t base) { return ARCHI_READ(base, HWCE_GEN_CONFIG0_OFFSET); }
static inline void hwce_gen_config0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_GEN_CONFIG0_OFFSET, value); }

static inline uint32_t hwce_gen_config1_get(uint32_t base) { return ARCHI_READ(base, HWCE_GEN_CONFIG1_OFFSET); }
static inline void hwce_gen_config1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_GEN_CONFIG1_OFFSET, value); }

static inline uint32_t hwce_y_trans_size_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_TRANS_SIZE_OFFSET); }
static inline void hwce_y_trans_size_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_TRANS_SIZE_OFFSET, value); }

static inline uint32_t hwce_y_line_stride_length_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_LINE_STRIDE_LENGTH_OFFSET); }
static inline void hwce_y_line_stride_length_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_LINE_STRIDE_LENGTH_OFFSET, value); }

static inline uint32_t hwce_y_feat_stride_length_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_FEAT_STRIDE_LENGTH_OFFSET); }
static inline void hwce_y_feat_stride_length_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_FEAT_STRIDE_LENGTH_OFFSET, value); }

static inline uint32_t hwce_y_out_3_base_addr_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_OUT_3_BASE_ADDR_OFFSET); }
static inline void hwce_y_out_3_base_addr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_OUT_3_BASE_ADDR_OFFSET, value); }

static inline uint32_t hwce_y_out_2_base_addr_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_OUT_2_BASE_ADDR_OFFSET); }
static inline void hwce_y_out_2_base_addr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_OUT_2_BASE_ADDR_OFFSET, value); }

static inline uint32_t hwce_y_out_1_base_addr_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_OUT_1_BASE_ADDR_OFFSET); }
static inline void hwce_y_out_1_base_addr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_OUT_1_BASE_ADDR_OFFSET, value); }

static inline uint32_t hwce_y_out_0_base_addr_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_OUT_0_BASE_ADDR_OFFSET); }
static inline void hwce_y_out_0_base_addr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_OUT_0_BASE_ADDR_OFFSET, value); }

static inline uint32_t hwce_y_in_3_base_addr_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_IN_3_BASE_ADDR_OFFSET); }
static inline void hwce_y_in_3_base_addr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_IN_3_BASE_ADDR_OFFSET, value); }

static inline uint32_t hwce_y_in_2_base_addr_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_IN_2_BASE_ADDR_OFFSET); }
static inline void hwce_y_in_2_base_addr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_IN_2_BASE_ADDR_OFFSET, value); }

static inline uint32_t hwce_y_in_1_base_addr_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_IN_1_BASE_ADDR_OFFSET); }
static inline void hwce_y_in_1_base_addr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_IN_1_BASE_ADDR_OFFSET, value); }

static inline uint32_t hwce_y_in_0_base_addr_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_IN_0_BASE_ADDR_OFFSET); }
static inline void hwce_y_in_0_base_addr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_IN_0_BASE_ADDR_OFFSET, value); }

static inline uint32_t hwce_x_trans_size_get(uint32_t base) { return ARCHI_READ(base, HWCE_X_TRANS_SIZE_OFFSET); }
static inline void hwce_x_trans_size_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_X_TRANS_SIZE_OFFSET, value); }

static inline uint32_t hwce_x_line_stride_length_get(uint32_t base) { return ARCHI_READ(base, HWCE_X_LINE_STRIDE_LENGTH_OFFSET); }
static inline void hwce_x_line_stride_length_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_X_LINE_STRIDE_LENGTH_OFFSET, value); }

static inline uint32_t hwce_x_feat_stride_length_get(uint32_t base) { return ARCHI_READ(base, HWCE_X_FEAT_STRIDE_LENGTH_OFFSET); }
static inline void hwce_x_feat_stride_length_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_X_FEAT_STRIDE_LENGTH_OFFSET, value); }

static inline uint32_t hwce_x_in_base_addr_get(uint32_t base) { return ARCHI_READ(base, HWCE_X_IN_BASE_ADDR_OFFSET); }
static inline void hwce_x_in_base_addr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_X_IN_BASE_ADDR_OFFSET, value); }

static inline uint32_t hwce_w_base_addr_get(uint32_t base) { return ARCHI_READ(base, HWCE_W_BASE_ADDR_OFFSET); }
static inline void hwce_w_base_addr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_W_BASE_ADDR_OFFSET, value); }

static inline uint32_t hwce_job_config0_get(uint32_t base) { return ARCHI_READ(base, HWCE_JOB_CONFIG0_OFFSET); }
static inline void hwce_job_config0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_JOB_CONFIG0_OFFSET, value); }

static inline uint32_t hwce_job_config1_get(uint32_t base) { return ARCHI_READ(base, HWCE_JOB_CONFIG1_OFFSET); }
static inline void hwce_job_config1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_JOB_CONFIG1_OFFSET, value); }

static inline uint32_t hwce_y_trans_size_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_TRANS_SIZE_CTX0_OFFSET); }
static inline void hwce_y_trans_size_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_TRANS_SIZE_CTX0_OFFSET, value); }

static inline uint32_t hwce_y_line_stride_length_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_LINE_STRIDE_LENGTH_CTX0_OFFSET); }
static inline void hwce_y_line_stride_length_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_LINE_STRIDE_LENGTH_CTX0_OFFSET, value); }

static inline uint32_t hwce_y_feat_stride_length_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_FEAT_STRIDE_LENGTH_CTX0_OFFSET); }
static inline void hwce_y_feat_stride_length_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_FEAT_STRIDE_LENGTH_CTX0_OFFSET, value); }

static inline uint32_t hwce_y_out_3_base_addr_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_OUT_3_BASE_ADDR_CTX0_OFFSET); }
static inline void hwce_y_out_3_base_addr_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_OUT_3_BASE_ADDR_CTX0_OFFSET, value); }

static inline uint32_t hwce_y_out_2_base_addr_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_OUT_2_BASE_ADDR_CTX0_OFFSET); }
static inline void hwce_y_out_2_base_addr_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_OUT_2_BASE_ADDR_CTX0_OFFSET, value); }

static inline uint32_t hwce_y_out_1_base_addr_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_OUT_1_BASE_ADDR_CTX0_OFFSET); }
static inline void hwce_y_out_1_base_addr_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_OUT_1_BASE_ADDR_CTX0_OFFSET, value); }

static inline uint32_t hwce_y_out_0_base_addr_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_OUT_0_BASE_ADDR_CTX0_OFFSET); }
static inline void hwce_y_out_0_base_addr_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_OUT_0_BASE_ADDR_CTX0_OFFSET, value); }

static inline uint32_t hwce_y_in_3_base_addr_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_IN_3_BASE_ADDR_CTX0_OFFSET); }
static inline void hwce_y_in_3_base_addr_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_IN_3_BASE_ADDR_CTX0_OFFSET, value); }

static inline uint32_t hwce_y_in_2_base_addr_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_IN_2_BASE_ADDR_CTX0_OFFSET); }
static inline void hwce_y_in_2_base_addr_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_IN_2_BASE_ADDR_CTX0_OFFSET, value); }

static inline uint32_t hwce_y_in_1_base_addr_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_IN_1_BASE_ADDR_CTX0_OFFSET); }
static inline void hwce_y_in_1_base_addr_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_IN_1_BASE_ADDR_CTX0_OFFSET, value); }

static inline uint32_t hwce_y_in_0_base_addr_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_IN_0_BASE_ADDR_CTX0_OFFSET); }
static inline void hwce_y_in_0_base_addr_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_IN_0_BASE_ADDR_CTX0_OFFSET, value); }

static inline uint32_t hwce_x_trans_size_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_X_TRANS_SIZE_CTX0_OFFSET); }
static inline void hwce_x_trans_size_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_X_TRANS_SIZE_CTX0_OFFSET, value); }

static inline uint32_t hwce_x_line_stride_length_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_X_LINE_STRIDE_LENGTH_CTX0_OFFSET); }
static inline void hwce_x_line_stride_length_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_X_LINE_STRIDE_LENGTH_CTX0_OFFSET, value); }

static inline uint32_t hwce_x_feat_stride_length_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_X_FEAT_STRIDE_LENGTH_CTX0_OFFSET); }
static inline void hwce_x_feat_stride_length_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_X_FEAT_STRIDE_LENGTH_CTX0_OFFSET, value); }

static inline uint32_t hwce_x_in_base_addr_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_X_IN_BASE_ADDR_CTX0_OFFSET); }
static inline void hwce_x_in_base_addr_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_X_IN_BASE_ADDR_CTX0_OFFSET, value); }

static inline uint32_t hwce_w_base_addr_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_W_BASE_ADDR_CTX0_OFFSET); }
static inline void hwce_w_base_addr_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_W_BASE_ADDR_CTX0_OFFSET, value); }

static inline uint32_t hwce_job_config0_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_JOB_CONFIG0_CTX0_OFFSET); }
static inline void hwce_job_config0_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_JOB_CONFIG0_CTX0_OFFSET, value); }

static inline uint32_t hwce_job_config1_ctx0_get(uint32_t base) { return ARCHI_READ(base, HWCE_JOB_CONFIG1_CTX0_OFFSET); }
static inline void hwce_job_config1_ctx0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_JOB_CONFIG1_CTX0_OFFSET, value); }

static inline uint32_t hwce_y_trans_size_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_TRANS_SIZE_CTX1_OFFSET); }
static inline void hwce_y_trans_size_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_TRANS_SIZE_CTX1_OFFSET, value); }

static inline uint32_t hwce_y_line_stride_length_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_LINE_STRIDE_LENGTH_CTX1_OFFSET); }
static inline void hwce_y_line_stride_length_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_LINE_STRIDE_LENGTH_CTX1_OFFSET, value); }

static inline uint32_t hwce_y_feat_stride_length_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_FEAT_STRIDE_LENGTH_CTX1_OFFSET); }
static inline void hwce_y_feat_stride_length_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_FEAT_STRIDE_LENGTH_CTX1_OFFSET, value); }

static inline uint32_t hwce_y_out_3_base_addr_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_OUT_3_BASE_ADDR_CTX1_OFFSET); }
static inline void hwce_y_out_3_base_addr_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_OUT_3_BASE_ADDR_CTX1_OFFSET, value); }

static inline uint32_t hwce_y_out_2_base_addr_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_OUT_2_BASE_ADDR_CTX1_OFFSET); }
static inline void hwce_y_out_2_base_addr_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_OUT_2_BASE_ADDR_CTX1_OFFSET, value); }

static inline uint32_t hwce_y_out_1_base_addr_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_OUT_1_BASE_ADDR_CTX1_OFFSET); }
static inline void hwce_y_out_1_base_addr_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_OUT_1_BASE_ADDR_CTX1_OFFSET, value); }

static inline uint32_t hwce_y_out_0_base_addr_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_OUT_0_BASE_ADDR_CTX1_OFFSET); }
static inline void hwce_y_out_0_base_addr_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_OUT_0_BASE_ADDR_CTX1_OFFSET, value); }

static inline uint32_t hwce_y_in_3_base_addr_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_IN_3_BASE_ADDR_CTX1_OFFSET); }
static inline void hwce_y_in_3_base_addr_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_IN_3_BASE_ADDR_CTX1_OFFSET, value); }

static inline uint32_t hwce_y_in_2_base_addr_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_IN_2_BASE_ADDR_CTX1_OFFSET); }
static inline void hwce_y_in_2_base_addr_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_IN_2_BASE_ADDR_CTX1_OFFSET, value); }

static inline uint32_t hwce_y_in_1_base_addr_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_IN_1_BASE_ADDR_CTX1_OFFSET); }
static inline void hwce_y_in_1_base_addr_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_IN_1_BASE_ADDR_CTX1_OFFSET, value); }

static inline uint32_t hwce_y_in_0_base_addr_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_Y_IN_0_BASE_ADDR_CTX1_OFFSET); }
static inline void hwce_y_in_0_base_addr_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_Y_IN_0_BASE_ADDR_CTX1_OFFSET, value); }

static inline uint32_t hwce_x_trans_size_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_X_TRANS_SIZE_CTX1_OFFSET); }
static inline void hwce_x_trans_size_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_X_TRANS_SIZE_CTX1_OFFSET, value); }

static inline uint32_t hwce_x_line_stride_length_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_X_LINE_STRIDE_LENGTH_CTX1_OFFSET); }
static inline void hwce_x_line_stride_length_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_X_LINE_STRIDE_LENGTH_CTX1_OFFSET, value); }

static inline uint32_t hwce_x_feat_stride_length_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_X_FEAT_STRIDE_LENGTH_CTX1_OFFSET); }
static inline void hwce_x_feat_stride_length_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_X_FEAT_STRIDE_LENGTH_CTX1_OFFSET, value); }

static inline uint32_t hwce_x_in_base_addr_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_X_IN_BASE_ADDR_CTX1_OFFSET); }
static inline void hwce_x_in_base_addr_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_X_IN_BASE_ADDR_CTX1_OFFSET, value); }

static inline uint32_t hwce_w_base_addr_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_W_BASE_ADDR_CTX1_OFFSET); }
static inline void hwce_w_base_addr_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_W_BASE_ADDR_CTX1_OFFSET, value); }

static inline uint32_t hwce_job_config0_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_JOB_CONFIG0_CTX1_OFFSET); }
static inline void hwce_job_config0_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_JOB_CONFIG0_CTX1_OFFSET, value); }

static inline uint32_t hwce_job_config1_ctx1_get(uint32_t base) { return ARCHI_READ(base, HWCE_JOB_CONFIG1_CTX1_OFFSET); }
static inline void hwce_job_config1_ctx1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, HWCE_JOB_CONFIG1_CTX1_OFFSET, value); }

#endif



//
// REGISTERS FIELDS MACROS
//

#if !defined(LANGUAGE_ASSEMBLY) && !defined(__ASSEMBLER__)

#define HWCE_TRIGGER_ANY_GET(value)                        (ARCHI_BEXTRACTU((value),32,0))
#define HWCE_TRIGGER_ANY_GETS(value)                       (ARCHI_BEXTRACT((value),32,0))
#define HWCE_TRIGGER_ANY_SET(value,field)                  (ARCHI_BINSERT((value),(field),32,0))
#define HWCE_TRIGGER_ANY(val)                              ((val) << 0)

#define HWCE_ACQUIRE_ID_ERR_GET(value)                     (ARCHI_BEXTRACTU((value),8,0))
#define HWCE_ACQUIRE_ID_ERR_GETS(value)                    (ARCHI_BEXTRACT((value),8,0))
#define HWCE_ACQUIRE_ID_ERR_SET(value,field)               (ARCHI_BINSERT((value),(field),8,0))
#define HWCE_ACQUIRE_ID_ERR(val)                           ((val) << 0)

#define HWCE_ACQUIRE_ERR_GET(value)                        (ARCHI_BEXTRACTU((value),24,8))
#define HWCE_ACQUIRE_ERR_GETS(value)                       (ARCHI_BEXTRACT((value),24,8))
#define HWCE_ACQUIRE_ERR_SET(value,field)                  (ARCHI_BINSERT((value),(field),24,8))
#define HWCE_ACQUIRE_ERR(val)                              ((val) << 8)

#define HWCE_FINISHED_JOBS_JOBS_GET(value)                 (ARCHI_BEXTRACTU((value),32,0))
#define HWCE_FINISHED_JOBS_JOBS_GETS(value)                (ARCHI_BEXTRACT((value),32,0))
#define HWCE_FINISHED_JOBS_JOBS_SET(value,field)           (ARCHI_BINSERT((value),(field),32,0))
#define HWCE_FINISHED_JOBS_JOBS(val)                       ((val) << 0)

#define HWCE_STATUS_ST_GET(value)                          (ARCHI_BEXTRACTU((value),1,0))
#define HWCE_STATUS_ST_GETS(value)                         (ARCHI_BEXTRACT((value),1,0))
#define HWCE_STATUS_ST_SET(value,field)                    (ARCHI_BINSERT((value),(field),1,0))
#define HWCE_STATUS_ST(val)                                ((val) << 0)

#define HWCE_RUNNING_JOB_ID_GET(value)                     (ARCHI_BEXTRACTU((value),8,0))
#define HWCE_RUNNING_JOB_ID_GETS(value)                    (ARCHI_BEXTRACT((value),8,0))
#define HWCE_RUNNING_JOB_ID_SET(value,field)               (ARCHI_BINSERT((value),(field),8,0))
#define HWCE_RUNNING_JOB_ID(val)                           ((val) << 0)

#define HWCE_SOFT_CLEAR_ANY_GET(value)                     (ARCHI_BEXTRACTU((value),32,0))
#define HWCE_SOFT_CLEAR_ANY_GETS(value)                    (ARCHI_BEXTRACT((value),32,0))
#define HWCE_SOFT_CLEAR_ANY_SET(value,field)               (ARCHI_BINSERT((value),(field),32,0))
#define HWCE_SOFT_CLEAR_ANY(val)                           ((val) << 0)

#define HWCE_GEN_CONFIG0_QF_GET(value)                     (ARCHI_BEXTRACTU((value),6,0))
#define HWCE_GEN_CONFIG0_QF_GETS(value)                    (ARCHI_BEXTRACT((value),6,0))
#define HWCE_GEN_CONFIG0_QF_SET(value,field)               (ARCHI_BINSERT((value),(field),6,0))
#define HWCE_GEN_CONFIG0_QF(val)                           ((val) << 0)

#define HWCE_GEN_CONFIG0_NF_GET(value)                     (ARCHI_BEXTRACTU((value),1,6))
#define HWCE_GEN_CONFIG0_NF_GETS(value)                    (ARCHI_BEXTRACT((value),1,6))
#define HWCE_GEN_CONFIG0_NF_SET(value,field)               (ARCHI_BINSERT((value),(field),1,6))
#define HWCE_GEN_CONFIG0_NF(val)                           ((val) << 6)

#define HWCE_GEN_CONFIG0_NY_GET(value)                     (ARCHI_BEXTRACTU((value),1,7))
#define HWCE_GEN_CONFIG0_NY_GETS(value)                    (ARCHI_BEXTRACT((value),1,7))
#define HWCE_GEN_CONFIG0_NY_SET(value,field)               (ARCHI_BINSERT((value),(field),1,7))
#define HWCE_GEN_CONFIG0_NY(val)                           ((val) << 7)

#define HWCE_GEN_CONFIG0_UNS_GET(value)                    (ARCHI_BEXTRACTU((value),1,8))
#define HWCE_GEN_CONFIG0_UNS_GETS(value)                   (ARCHI_BEXTRACT((value),1,8))
#define HWCE_GEN_CONFIG0_UNS_SET(value,field)              (ARCHI_BINSERT((value),(field),1,8))
#define HWCE_GEN_CONFIG0_UNS(val)                          ((val) << 8)

#define HWCE_GEN_CONFIG0_VECT_GET(value)                   (ARCHI_BEXTRACTU((value),2,9))
#define HWCE_GEN_CONFIG0_VECT_GETS(value)                  (ARCHI_BEXTRACT((value),2,9))
#define HWCE_GEN_CONFIG0_VECT_SET(value,field)             (ARCHI_BINSERT((value),(field),2,9))
#define HWCE_GEN_CONFIG0_VECT(val)                         ((val) << 9)

#define HWCE_GEN_CONFIG0_CONV_GET(value)                   (ARCHI_BEXTRACTU((value),2,11))
#define HWCE_GEN_CONFIG0_CONV_GETS(value)                  (ARCHI_BEXTRACT((value),2,11))
#define HWCE_GEN_CONFIG0_CONV_SET(value,field)             (ARCHI_BINSERT((value),(field),2,11))
#define HWCE_GEN_CONFIG0_CONV(val)                         ((val) << 11)

#define HWCE_GEN_CONFIG0_NCP_GET(value)                    (ARCHI_BEXTRACTU((value),1,13))
#define HWCE_GEN_CONFIG0_NCP_GETS(value)                   (ARCHI_BEXTRACT((value),1,13))
#define HWCE_GEN_CONFIG0_NCP_SET(value,field)              (ARCHI_BINSERT((value),(field),1,13))
#define HWCE_GEN_CONFIG0_NCP(val)                          ((val) << 13)

#define HWCE_GEN_CONFIG0_WSTRIDE_GET(value)                (ARCHI_BEXTRACTU((value),16,16))
#define HWCE_GEN_CONFIG0_WSTRIDE_GETS(value)               (ARCHI_BEXTRACT((value),16,16))
#define HWCE_GEN_CONFIG0_WSTRIDE_SET(value,field)          (ARCHI_BINSERT((value),(field),16,16))
#define HWCE_GEN_CONFIG0_WSTRIDE(val)                      ((val) << 16)

#define HWCE_GEN_CONFIG1_PIXSHIFTL_GET(value)              (ARCHI_BEXTRACTU((value),5,0))
#define HWCE_GEN_CONFIG1_PIXSHIFTL_GETS(value)             (ARCHI_BEXTRACT((value),5,0))
#define HWCE_GEN_CONFIG1_PIXSHIFTL_SET(value,field)        (ARCHI_BINSERT((value),(field),5,0))
#define HWCE_GEN_CONFIG1_PIXSHIFTL(val)                    ((val) << 0)

#define HWCE_GEN_CONFIG1_PIXMODE_GET(value)                (ARCHI_BEXTRACTU((value),2,8))
#define HWCE_GEN_CONFIG1_PIXMODE_GETS(value)               (ARCHI_BEXTRACT((value),2,8))
#define HWCE_GEN_CONFIG1_PIXMODE_SET(value,field)          (ARCHI_BINSERT((value),(field),2,8))
#define HWCE_GEN_CONFIG1_PIXMODE(val)                      ((val) << 8)

#define HWCE_GEN_CONFIG1_PIXSHIFTR_GET(value)              (ARCHI_BEXTRACTU((value),5,16))
#define HWCE_GEN_CONFIG1_PIXSHIFTR_GETS(value)             (ARCHI_BEXTRACT((value),5,16))
#define HWCE_GEN_CONFIG1_PIXSHIFTR_SET(value,field)        (ARCHI_BINSERT((value),(field),5,16))
#define HWCE_GEN_CONFIG1_PIXSHIFTR(val)                    ((val) << 16)

#define HWCE_Y_TRANS_SIZE_SIZE_GET(value)                  (ARCHI_BEXTRACTU((value),32,0))
#define HWCE_Y_TRANS_SIZE_SIZE_GETS(value)                 (ARCHI_BEXTRACT((value),32,0))
#define HWCE_Y_TRANS_SIZE_SIZE_SET(value,field)            (ARCHI_BINSERT((value),(field),32,0))
#define HWCE_Y_TRANS_SIZE_SIZE(val)                        ((val) << 0)

#define HWCE_Y_LINE_STRIDE_LENGTH_LENGTH_GET(value)        (ARCHI_BEXTRACTU((value),16,0))
#define HWCE_Y_LINE_STRIDE_LENGTH_LENGTH_GETS(value)       (ARCHI_BEXTRACT((value),16,0))
#define HWCE_Y_LINE_STRIDE_LENGTH_LENGTH_SET(value,field)  (ARCHI_BINSERT((value),(field),16,0))
#define HWCE_Y_LINE_STRIDE_LENGTH_LENGTH(val)              ((val) << 0)

#define HWCE_Y_LINE_STRIDE_LENGTH_STRIDE_GET(value)        (ARCHI_BEXTRACTU((value),16,16))
#define HWCE_Y_LINE_STRIDE_LENGTH_STRIDE_GETS(value)       (ARCHI_BEXTRACT((value),16,16))
#define HWCE_Y_LINE_STRIDE_LENGTH_STRIDE_SET(value,field)  (ARCHI_BINSERT((value),(field),16,16))
#define HWCE_Y_LINE_STRIDE_LENGTH_STRIDE(val)              ((val) << 16)

#define HWCE_Y_FEAT_STRIDE_LENGTH_LENGTH_GET(value)        (ARCHI_BEXTRACTU((value),16,0))
#define HWCE_Y_FEAT_STRIDE_LENGTH_LENGTH_GETS(value)       (ARCHI_BEXTRACT((value),16,0))
#define HWCE_Y_FEAT_STRIDE_LENGTH_LENGTH_SET(value,field)  (ARCHI_BINSERT((value),(field),16,0))
#define HWCE_Y_FEAT_STRIDE_LENGTH_LENGTH(val)              ((val) << 0)

#define HWCE_Y_FEAT_STRIDE_LENGTH_STRIDE_GET(value)        (ARCHI_BEXTRACTU((value),16,16))
#define HWCE_Y_FEAT_STRIDE_LENGTH_STRIDE_GETS(value)       (ARCHI_BEXTRACT((value),16,16))
#define HWCE_Y_FEAT_STRIDE_LENGTH_STRIDE_SET(value,field)  (ARCHI_BINSERT((value),(field),16,16))
#define HWCE_Y_FEAT_STRIDE_LENGTH_STRIDE(val)              ((val) << 16)

#define HWCE_Y_OUT_3_BASE_ADDR_ADDR_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define HWCE_Y_OUT_3_BASE_ADDR_ADDR_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define HWCE_Y_OUT_3_BASE_ADDR_ADDR_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define HWCE_Y_OUT_3_BASE_ADDR_ADDR(val)                   ((val) << 0)

#define HWCE_Y_OUT_2_BASE_ADDR_ADDR_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define HWCE_Y_OUT_2_BASE_ADDR_ADDR_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define HWCE_Y_OUT_2_BASE_ADDR_ADDR_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define HWCE_Y_OUT_2_BASE_ADDR_ADDR(val)                   ((val) << 0)

#define HWCE_Y_OUT_1_BASE_ADDR_ADDR_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define HWCE_Y_OUT_1_BASE_ADDR_ADDR_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define HWCE_Y_OUT_1_BASE_ADDR_ADDR_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define HWCE_Y_OUT_1_BASE_ADDR_ADDR(val)                   ((val) << 0)

#define HWCE_Y_OUT_0_BASE_ADDR_ADDR_GET(value)             (ARCHI_BEXTRACTU((value),32,0))
#define HWCE_Y_OUT_0_BASE_ADDR_ADDR_GETS(value)            (ARCHI_BEXTRACT((value),32,0))
#define HWCE_Y_OUT_0_BASE_ADDR_ADDR_SET(value,field)       (ARCHI_BINSERT((value),(field),32,0))
#define HWCE_Y_OUT_0_BASE_ADDR_ADDR(val)                   ((val) << 0)

#define HWCE_Y_IN_3_BASE_ADDR_ADDR_GET(value)              (ARCHI_BEXTRACTU((value),32,0))
#define HWCE_Y_IN_3_BASE_ADDR_ADDR_GETS(value)             (ARCHI_BEXTRACT((value),32,0))
#define HWCE_Y_IN_3_BASE_ADDR_ADDR_SET(value,field)        (ARCHI_BINSERT((value),(field),32,0))
#define HWCE_Y_IN_3_BASE_ADDR_ADDR(val)                    ((val) << 0)

#define HWCE_Y_IN_2_BASE_ADDR_ADDR_GET(value)              (ARCHI_BEXTRACTU((value),32,0))
#define HWCE_Y_IN_2_BASE_ADDR_ADDR_GETS(value)             (ARCHI_BEXTRACT((value),32,0))
#define HWCE_Y_IN_2_BASE_ADDR_ADDR_SET(value,field)        (ARCHI_BINSERT((value),(field),32,0))
#define HWCE_Y_IN_2_BASE_ADDR_ADDR(val)                    ((val) << 0)

#define HWCE_Y_IN_1_BASE_ADDR_ADDR_GET(value)              (ARCHI_BEXTRACTU((value),32,0))
#define HWCE_Y_IN_1_BASE_ADDR_ADDR_GETS(value)             (ARCHI_BEXTRACT((value),32,0))
#define HWCE_Y_IN_1_BASE_ADDR_ADDR_SET(value,field)        (ARCHI_BINSERT((value),(field),32,0))
#define HWCE_Y_IN_1_BASE_ADDR_ADDR(val)                    ((val) << 0)

#define HWCE_Y_IN_0_BASE_ADDR_ADDR_GET(value)              (ARCHI_BEXTRACTU((value),32,0))
#define HWCE_Y_IN_0_BASE_ADDR_ADDR_GETS(value)             (ARCHI_BEXTRACT((value),32,0))
#define HWCE_Y_IN_0_BASE_ADDR_ADDR_SET(value,field)        (ARCHI_BINSERT((value),(field),32,0))
#define HWCE_Y_IN_0_BASE_ADDR_ADDR(val)                    ((val) << 0)

#define HWCE_X_TRANS_SIZE_SIZE_GET(value)                  (ARCHI_BEXTRACTU((value),32,0))
#define HWCE_X_TRANS_SIZE_SIZE_GETS(value)                 (ARCHI_BEXTRACT((value),32,0))
#define HWCE_X_TRANS_SIZE_SIZE_SET(value,field)            (ARCHI_BINSERT((value),(field),32,0))
#define HWCE_X_TRANS_SIZE_SIZE(val)                        ((val) << 0)

#define HWCE_X_LINE_STRIDE_LENGTH_LENGTH_GET(value)        (ARCHI_BEXTRACTU((value),16,0))
#define HWCE_X_LINE_STRIDE_LENGTH_LENGTH_GETS(value)       (ARCHI_BEXTRACT((value),16,0))
#define HWCE_X_LINE_STRIDE_LENGTH_LENGTH_SET(value,field)  (ARCHI_BINSERT((value),(field),16,0))
#define HWCE_X_LINE_STRIDE_LENGTH_LENGTH(val)              ((val) << 0)

#define HWCE_X_LINE_STRIDE_LENGTH_STRIDE_GET(value)        (ARCHI_BEXTRACTU((value),16,16))
#define HWCE_X_LINE_STRIDE_LENGTH_STRIDE_GETS(value)       (ARCHI_BEXTRACT((value),16,16))
#define HWCE_X_LINE_STRIDE_LENGTH_STRIDE_SET(value,field)  (ARCHI_BINSERT((value),(field),16,16))
#define HWCE_X_LINE_STRIDE_LENGTH_STRIDE(val)              ((val) << 16)

#define HWCE_X_FEAT_STRIDE_LENGTH_LENGTH_GET(value)        (ARCHI_BEXTRACTU((value),16,0))
#define HWCE_X_FEAT_STRIDE_LENGTH_LENGTH_GETS(value)       (ARCHI_BEXTRACT((value),16,0))
#define HWCE_X_FEAT_STRIDE_LENGTH_LENGTH_SET(value,field)  (ARCHI_BINSERT((value),(field),16,0))
#define HWCE_X_FEAT_STRIDE_LENGTH_LENGTH(val)              ((val) << 0)

#define HWCE_X_FEAT_STRIDE_LENGTH_STRIDE_GET(value)        (ARCHI_BEXTRACTU((value),16,16))
#define HWCE_X_FEAT_STRIDE_LENGTH_STRIDE_GETS(value)       (ARCHI_BEXTRACT((value),16,16))
#define HWCE_X_FEAT_STRIDE_LENGTH_STRIDE_SET(value,field)  (ARCHI_BINSERT((value),(field),16,16))
#define HWCE_X_FEAT_STRIDE_LENGTH_STRIDE(val)              ((val) << 16)

#define HWCE_X_IN_BASE_ADDR_ADDR_GET(value)                (ARCHI_BEXTRACTU((value),32,0))
#define HWCE_X_IN_BASE_ADDR_ADDR_GETS(value)               (ARCHI_BEXTRACT((value),32,0))
#define HWCE_X_IN_BASE_ADDR_ADDR_SET(value,field)          (ARCHI_BINSERT((value),(field),32,0))
#define HWCE_X_IN_BASE_ADDR_ADDR(val)                      ((val) << 0)

#define HWCE_W_BASE_ADDR_ADDR_GET(value)                   (ARCHI_BEXTRACTU((value),32,0))
#define HWCE_W_BASE_ADDR_ADDR_GETS(value)                  (ARCHI_BEXTRACT((value),32,0))
#define HWCE_W_BASE_ADDR_ADDR_SET(value,field)             (ARCHI_BINSERT((value),(field),32,0))
#define HWCE_W_BASE_ADDR_ADDR(val)                         ((val) << 0)

#define HWCE_JOB_CONFIG0_LBUFLEN_GET(value)                (ARCHI_BEXTRACTU((value),10,0))
#define HWCE_JOB_CONFIG0_LBUFLEN_GETS(value)               (ARCHI_BEXTRACT((value),10,0))
#define HWCE_JOB_CONFIG0_LBUFLEN_SET(value,field)          (ARCHI_BINSERT((value),(field),10,0))
#define HWCE_JOB_CONFIG0_LBUFLEN(val)                      ((val) << 0)

#define HWCE_JOB_CONFIG0_NOYCONST_GET(value)               (ARCHI_BEXTRACTU((value),16,16))
#define HWCE_JOB_CONFIG0_NOYCONST_GETS(value)              (ARCHI_BEXTRACT((value),16,16))
#define HWCE_JOB_CONFIG0_NOYCONST_SET(value,field)         (ARCHI_BINSERT((value),(field),16,16))
#define HWCE_JOB_CONFIG0_NOYCONST(val)                     ((val) << 16)

#define HWCE_JOB_CONFIG1_VECT_DISABLE_MASK_GET(value)      (ARCHI_BEXTRACTU((value),4,0))
#define HWCE_JOB_CONFIG1_VECT_DISABLE_MASK_GETS(value)     (ARCHI_BEXTRACT((value),4,0))
#define HWCE_JOB_CONFIG1_VECT_DISABLE_MASK_SET(value,field) (ARCHI_BINSERT((value),(field),4,0))
#define HWCE_JOB_CONFIG1_VECT_DISABLE_MASK(val)            ((val) << 0)

#define HWCE_JOB_CONFIG1_WOF_PARAM_GET(value)              (ARCHI_BEXTRACTU((value),6,8))
#define HWCE_JOB_CONFIG1_WOF_PARAM_GETS(value)             (ARCHI_BEXTRACT((value),6,8))
#define HWCE_JOB_CONFIG1_WOF_PARAM_SET(value,field)        (ARCHI_BINSERT((value),(field),6,8))
#define HWCE_JOB_CONFIG1_WOF_PARAM(val)                    ((val) << 8)

#define HWCE_JOB_CONFIG1_WIF_PARAM_GET(value)              (ARCHI_BEXTRACTU((value),6,16))
#define HWCE_JOB_CONFIG1_WIF_PARAM_GETS(value)             (ARCHI_BEXTRACT((value),6,16))
#define HWCE_JOB_CONFIG1_WIF_PARAM_SET(value,field)        (ARCHI_BINSERT((value),(field),6,16))
#define HWCE_JOB_CONFIG1_WIF_PARAM(val)                    ((val) << 16)

#define HWCE_JOB_CONFIG1_LO_GET(value)                     (ARCHI_BEXTRACTU((value),1,24))
#define HWCE_JOB_CONFIG1_LO_GETS(value)                    (ARCHI_BEXTRACT((value),1,24))
#define HWCE_JOB_CONFIG1_LO_SET(value,field)               (ARCHI_BINSERT((value),(field),1,24))
#define HWCE_JOB_CONFIG1_LO(val)                           ((val) << 24)

#define HWCE_JOB_CONFIG1_LN_GET(value)                     (ARCHI_BEXTRACTU((value),1,25))
#define HWCE_JOB_CONFIG1_LN_GETS(value)                    (ARCHI_BEXTRACT((value),1,25))
#define HWCE_JOB_CONFIG1_LN_SET(value,field)               (ARCHI_BINSERT((value),(field),1,25))
#define HWCE_JOB_CONFIG1_LN(val)                           ((val) << 25)

#endif

#endif
