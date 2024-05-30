//-----------------------------------------------------------------------------
// Title         : SoC Memory Region Definitions
//-----------------------------------------------------------------------------
// File          : soc_mem_map.svh
// Author        : Manuel Eggimann  <meggimann@iis.ee.ethz.ch>
// Created       : 30.10.2020
//-----------------------------------------------------------------------------
// Description :
// This file contains start and end address definitions for the soc_interconnect.
//-----------------------------------------------------------------------------
// Copyright (C) 2013-2020 ETH Zurich, University of Bologna
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.
//-----------------------------------------------------------------------------

`define SOC_MEM_MAP_TCDM_START_ADDR          32'h1C01_0000
`define SOC_MEM_MAP_TCDM_END_ADDR            32'h1C09_0000

`define SOC_MEM_MAP_PRIVATE_BANK0_START_ADDR 32'h1C00_0000
`define SOC_MEM_MAP_PRIVATE_BANK0_END_ADDR   32'h1C00_8000

`define SOC_MEM_MAP_PRIVATE_BANK1_START_ADDR 32'h1C00_8000
`define SOC_MEM_MAP_PRIVATE_BANK1_END_ADDR   32'h1C01_0000

`define SOC_MEM_MAP_BOOT_ROM_START_ADDR      32'h1A00_0000
`define SOC_MEM_MAP_BOOT_ROM_END_ADDR        32'h1A04_0000

`define SOC_MEM_MAP_AXI_PLUG_START_ADDR      32'h1000_0000
`define SOC_MEM_MAP_AXI_PLUG_END_ADDR        32'h1040_0000

`define SOC_MEM_MAP_PERIPHERALS_START_ADDR   32'h1A10_0000
`define SOC_MEM_MAP_PERIPHERALS_END_ADDR     32'h1A40_0000

// Peripheral Bus Address Space
`define SOC_MEM_MAP_GPIO_START_ADDR                    32'h1A10_1000
`define SOC_MEM_MAP_GPIO_END_ADDR                      32'h1A10_2000

`define SOC_MEM_MAP_UDMA_START_ADDR                    32'h1A10_2000
`define SOC_MEM_MAP_UDMA_END_ADDR                      32'h1A10_4000

`define SOC_MEM_MAP_SOC_CTRL_START_ADDR                32'h1A10_4000
`define SOC_MEM_MAP_SOC_CTRL_END_ADDR                  32'h1A10_5000

`define SOC_MEM_MAP_ADV_TIMER_START_ADDR               32'h1A10_5000
`define SOC_MEM_MAP_ADV_TIMER_END_ADDR                 32'h1A10_6000

`define SOC_MEM_MAP_SOC_EVENT_GEN_START_ADDR           32'h1A10_6000
`define SOC_MEM_MAP_SOC_EVENT_GEN_END_ADDR             32'h1A10_7000

`define SOC_MEM_MAP_INTERRUPT_CTRL_START_ADDR          32'h1A10_9000
`define SOC_MEM_MAP_INTERRUPT_CTRL_END_ADDR            32'h1A10_B000

`define SOC_MEM_MAP_APB_TIMER_START_ADDR               32'h1A10_B000
`define SOC_MEM_MAP_APB_TIMER_END_ADDR                 32'h1A10_C000

`define SOC_MEM_MAP_HWPE_START_ADDR                    32'h1A10_C000
`define SOC_MEM_MAP_HWPE_END_ADDR                      32'h1A10_D000

`define SOC_MEM_MAP_VIRTUAL_STDOUT_START_ADDR          32'h1A10_F000
`define SOC_MEM_MAP_VIRTUAL_STDOUT_END_ADDR            32'h1A11_0000

`define SOC_MEM_MAP_DEBUG_START_ADDR                   32'h1A11_0000
`define SOC_MEM_MAP_DEBUG_END_ADDR                     32'h1A12_0000

`define SOC_MEM_MAP_CHIP_CTRL_START_ADDR               32'h1A12_0000
`define SOC_MEM_MAP_CHIP_CTRL_END_ADDR                 32'h1A14_0000


// Chip Control Address Region (This region is implementation specific)
`define SOC_MEM_MAP_CHIP_CTRL_FLL_START_ADDR           32'h1A12_0000
`define SOC_MEM_MAP_CHIP_CTRL_FLL_END_ADDR             32'h1A12_1000

`define SOC_MEM_MAP_CHIP_CTRL_PAD_CFG_START_ADDR       32'h1A12_1000
`define SOC_MEM_MAP_CHIP_CTRL_PAD_CFG_END_ADDR         32'h1A12_2000


// Cluster Address Regions
`define SOC_MEM_MAP_CLUSTER_START_ADDR                 32'h1000_0000 // This define is currently not used in the code and just here for documentation
`define SOC_MEM_MAP_CLUSTER_END_ADDR                   32'h2000_0000 // TODO Actually use the define in soc_mem_map.svh for cluster address space definition
