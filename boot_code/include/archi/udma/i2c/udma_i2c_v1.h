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

#ifndef __ARCHI_UDMA_UDMA_I2C_V1_H__
#define __ARCHI_UDMA_UDMA_I2C_V1_H__

#define ARCHI_I2C_SETUP_OFFSET          0x0

#define I2C_CMD_START   0x02
#define I2C_CMD_STOP    0x04
#define I2C_CMD_RD_ACK  0x08
#define I2C_CMD_RD_NACK 0x10
#define I2C_CMD_WR      0x20
#define I2C_CMD_WAIT    0x40
#define I2C_CMD_RPT     0x80

#define I2C_CMD_SETUP_ENABLE_BIT           8
#define I2C_CMD_SETUP_DIV_BIT              16

#endif