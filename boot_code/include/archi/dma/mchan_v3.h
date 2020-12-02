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

#ifndef ARCHI_DMA_MCHAN_V3_H
#define ARCHI_DMA_MCHAN_V3_H

#define TCDM_ADDR_REG_OFFSET      ( 0x0 )
#define EXT_ADDR_REG_OFFSET       ( 0x4 )
#define CMD_QUEUE_OFFSET          ( 0x8 )
#define CMD_QUEUE_BUSY_REG_OFFSET ( 0xC )

#define ST1     0x0001
#define ST2     0x0002
#define ST4     0x0004
#define ST8     0x0008
#define ST16    0x0010
#define ST32    0x0020
#define ST64    0x0040
#define ST128   0x0080
#define ST256   0x0100
#define ST512   0x0200
#define ST1024  0x0400
#define ST2048  0x0800
#define ST4096  0x1000
#define ST8192  0x2000
#define ST16384 0x4000

#define LD1     0x8001
#define LD2     0x8002
#define LD4     0x8004
#define LD8     0x8008
#define LD16    0x8010
#define LD32    0x8020
#define LD64    0x8040
#define LD128   0x8080
#define LD256   0x8100
#define LD512   0x8200
#define LD1024  0x8400
#define LD2048  0x8800
#define LD4096  0x9000
#define LD8192  0xA000
#define LD16384 0xC000

#define MCHAN_TYPE_OFFSET 15
#define MCHAN_TYPE(x) (((x) >> MCHAN_TYPE_OFFSET) & 1) 

#define MCHAN_SIZE_OFFSET 0
#define MCHAN_SIZE(x) (((x) >> MCHAN_SIZE_OFFSET) & 0x7fff)

#endif
