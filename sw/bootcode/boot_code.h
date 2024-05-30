/*
 * Copyright 2022 ETH Zurich
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
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __BOOT_CODE_H__
#define __BOOT_CODE_H__

void __attribute__((noreturn)) boot_qspi(int hyperflash, int qpi);
void __attribute__((noreturn)) boot_srec_uart(void);
void __attribute__((noreturn)) boot_preloaded(void);
void __attribute__((noreturn)) boot_jtag_openocd(void);

#endif /* __BOOT_CODE_H__ */
