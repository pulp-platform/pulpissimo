// Copyright 2021 OpenHW Group
// Solderpad Hardware License, Version 2.1, see LICENSE.md for details.
// SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1


#ifndef PULP_PLATFORM_SIMJTAG_H_
#define PULP_PLATFORM_SIMJTAG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

int jtag_tick(int port, unsigned char *jtag_TCK, unsigned char *jtag_TMS,
              unsigned char *jtag_TDI, unsigned char *jtag_TRSTn,
              unsigned char jtag_TDO);

#ifdef __cplusplus
}
#endif
#endif  // PULP_PLATFORM_SIMJTAG_H_
