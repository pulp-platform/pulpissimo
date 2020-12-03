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

#ifndef __HAL_UDMA_UDMA_PERIPH_HYPER_V1_H__
#define __HAL_UDMA_UDMA_PERIPH_HYPER_V1_H__

#include <archi/pulp.h>

#define UDMA_HYPER_OFFSET(id)         UDMA_PERIPH_OFFSET(ARCHI_UDMA_HYPER_ID(id))
#define UDMA_HYPER_RX_ADDR(id)         (ARCHI_UDMA_ADDR + UDMA_HYPER_OFFSET(id) + UDMA_CHANNEL_RX_OFFSET)
#define UDMA_HYPER_TX_ADDR(id)         (ARCHI_UDMA_ADDR + UDMA_HYPER_OFFSET(id) + UDMA_CHANNEL_TX_OFFSET)
#define UDMA_HYPER_CUSTOM_ADDR(id)     (ARCHI_UDMA_ADDR + UDMA_HYPER_OFFSET(id) + UDMA_CHANNEL_CUSTOM_OFFSET)
#define ARCHI_SOC_EVENT_HYPER_RX(id)    (ARCHI_SOC_EVENT_PERIPH_FIRST_EVT(ARCHI_UDMA_HYPER_ID(id)) + ARCHI_UDMA_HYPER_RX_EVT)
#define ARCHI_SOC_EVENT_HYPER_TX(id)    (ARCHI_SOC_EVENT_PERIPH_FIRST_EVT(ARCHI_UDMA_HYPER_ID(id)) + ARCHI_UDMA_HYPER_TX_EVT)

#include "archi/udma/hyper/udma_hyper_v1.h"
/*
 * set Hyper IP ext_addr configuration with value
 */
static inline void hal_hyper_udma_ext_addr_set(unsigned int value)
{
    pulp_write32(HYPER_EXT_ADDR, value & HYPER_EXT_ADDR_MASK);
}

/*
 * get Hyper IP configuration ext_addr value
 */
static inline unsigned int hal_hyper_udma_ext_addr_get()
{
    return (unsigned int)pulp_read32(HYPER_EXT_ADDR);
}

/*
 * set Hyper IP configuration mem_cfg0
 */
static inline void hal_hyper_udma_mem_cfg0_set(unsigned short value)
{
    pulp_write32(HYPER_MEM_CFG0, value & HYPER_MEM_CFG0_MASK);
}

/*
 * get Hyper IP configuration mem_cfg0 value
 */
static inline unsigned short hal_hyper_udma_mem_cfg0_get()
{
    return (unsigned short) (pulp_read32(HYPER_MEM_CFG0) & HYPER_MEM_CFG0_MASK);
}

/*
 * set Hyper IP configuration mem_cfg1
 */
static inline void hal_hyper_udma_mem_cfg1_set(unsigned int value)
{
    pulp_write32(HYPER_MEM_CFG1, value & HYPER_MEM_CFG1_MASK);
}

/*
 * get Hyper IP configuration mem_cfg1 value
 */
static inline unsigned int hal_hyper_udma_mem_cfg1_get()
{
    return (unsigned int) (pulp_read32(HYPER_MEM_CFG1) & HYPER_MEM_CFG1_MASK);
}

/*
 * set Hyper IP configuration mem_cfg2 with value
 */
static inline void hal_hyper_udma_mem_cfg2_set(unsigned int value)
{
    pulp_write32(HYPER_MEM_CFG2, value & HYPER_MEM_CFG2_MASK);
}

/*
 * get Hyper IP configuration mem_cfg2 value
 */
static inline unsigned int hal_hyper_udma_mem_cfg2_get()
{
    return (unsigned int) (pulp_read32(HYPER_MEM_CFG2) & HYPER_MEM_CFG2_MASK);
}

/*
 * set Hyper IP configuration mem_cfg3 with value
 */
static inline void hal_hyper_udma_mem_cfg3_set(unsigned short value)
{
    pulp_write32(HYPER_MEM_CFG3, value & HYPER_MEM_CFG3_MASK);
}

/*
 * get Hyper IP configuration mem_cfg3 value
 */
static inline unsigned short hal_hyper_udma_mem_cfg3_get()
{
    return (unsigned short) (pulp_read32(HYPER_MEM_CFG3) & HYPER_MEM_CFG3_MASK);
}

/*
 * set Hyper IP configuration mem_cfg4 with value
 */
static inline void hal_hyper_udma_mem_cfg4_set(unsigned short value)
{
    pulp_write32(HYPER_MEM_CFG4, value & HYPER_MEM_CFG4_MASK);
}

/*
 * get Hyper IP configuration mem_cfg4 value
 */
static inline unsigned short hal_hyper_udma_mem_cfg4_get()
{
    return (unsigned short) (pulp_read32(HYPER_MEM_CFG4) & HYPER_MEM_CFG4_MASK);
}

/*
 * set Hyper IP configuration mem_cfg5 with value
 */
static inline void hal_hyper_udma_mem_cfg5_set(unsigned int value)
{
    pulp_write32(HYPER_MEM_CFG5, value & HYPER_MEM_CFG5_MASK);
}

/*
 * get Hyper IP configuration mem_cfg5 value
 */
static inline unsigned int hal_hyper_udma_mem_cfg5_get()
{
    return (unsigned int) (pulp_read32(HYPER_MEM_CFG5) & HYPER_MEM_CFG5_MASK);
}

/*
 * set Hyper IP configuration mem_cfg6 with value
 */
static inline void hal_hyper_udma_mem_cfg6_set(unsigned int value)
{
    pulp_write32(HYPER_MEM_CFG6, value & HYPER_MEM_CFG6_MASK);
}

/*
 * get Hyper IP configuration mem_cfg6 value
 */
static inline unsigned int hal_hyper_udma_mem_cfg6_get()
{
    return (unsigned int) (pulp_read32(HYPER_MEM_CFG6) & HYPER_MEM_CFG6_MASK);
}

/*
 * set Hyper IP configuration mem_cfg7 with value
 */
static inline void hal_hyper_udma_mem_cfg7_set(unsigned char value)
{
    pulp_write32(HYPER_MEM_CFG7, value & HYPER_MEM_CFG7_MASK);
}

/*
 * get Hyper IP configuration mem_cfg7 value
 */
static inline unsigned char hal_hyper_udma_mem_cfg7_get()
{
    return (unsigned char) (pulp_read32(HYPER_MEM_CFG7) & HYPER_MEM_CFG7_MASK);
}

/*
 * set write read address for both ram and flash
 * address[31:24]
 * mbr1 <= mbr0, always select csn0
 * mbr0 <= addr < mbr1,  chip select csn0
 * mbr1 <= addr,         chip select csn1
 */
static inline void hal_hyper_udma_addr_set(unsigned int addr)
{
    hal_hyper_udma_ext_addr_set(addr);
}

/*
 * set hyper0 base address
 */
static inline void hal_hyper_udma_mbr0_set(unsigned char mbr0)
{
    hal_hyper_udma_mem_cfg0_set((hal_hyper_udma_mem_cfg0_get()
                                 & HYPER_MEM_CFG0_MBR0_MASK_BYTE)
                                | (mbr0 << HYPER_MEM_CFG0_MBR0_OFFSET));
}

/*
 * set hyper0 latency
 */
static inline void hal_hyper_udma_latency0_set(unsigned char latency0)
{
    hal_hyper_udma_mem_cfg0_set((hal_hyper_udma_mem_cfg0_get()
                                 & HYPER_MEM_CFG0_LATENCY0_MASK_HB)
                                | (latency0 << HYPER_MEM_CFG0_LATENCY0_OFFSET));
}

/*
 * set hyper0 wrap size
 */
static inline void hal_hyper_udma_wrap_size0_set(unsigned char wrapsize)
{
    hal_hyper_udma_mem_cfg0_set((hal_hyper_udma_mem_cfg0_get()
                                 & HYPER_MEM_CFG0_WRAP_SIZE0_MASK_TB)
                                | (wrapsize << HYPER_MEM_CFG0_WRAP_SIZE0_OFFSET));
}

/*
 * set hyper0 rd cshi
 */
static inline void hal_hyper_udma_rd_cshi0_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg1_set((hal_hyper_udma_mem_cfg1_get()
                                 & HYPER_MEM_CFG1_RD_CSHI0_MASK_HB)
                                | (value << HYPER_MEM_CFG1_RD_CSHI0_OFFSET));
}

/*
 * set hyper0 rd css
 */
static inline void hal_hyper_udma_rd_css0_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg1_set((hal_hyper_udma_mem_cfg1_get()
                                 & HYPER_MEM_CFG1_RD_CSS0_MASK_HB)
                                | (value << HYPER_MEM_CFG1_RD_CSS0_OFFSET));
}

/*
 * set hyper0 rd csh
 */
static inline void hal_hyper_udma_rd_csh0_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg1_set((hal_hyper_udma_mem_cfg1_get()
                                 & HYPER_MEM_CFG1_RD_CSH0_MASK_HB)
                                | (value << HYPER_MEM_CFG1_RD_CSH0_OFFSET));
}


/*
 * set hyper0 wr cshi
 */
static inline void hal_hyper_udma_wr_cshi0_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg1_set((hal_hyper_udma_mem_cfg1_get()
                                 & HYPER_MEM_CFG1_WR_CSHI0_MASK_HB)
                                | (value << HYPER_MEM_CFG1_WR_CSHI0_OFFSET));
}

/*
 * set hyper0 wr css
 */
static inline void hal_hyper_udma_wr_css0_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg1_set((hal_hyper_udma_mem_cfg1_get()
                                 & HYPER_MEM_CFG1_WR_CSS0_MASK_HB)
                                | (value << HYPER_MEM_CFG1_WR_CSS0_OFFSET));
}

/*
 * set hyper0 wr csh
 */
static inline void hal_hyper_udma_wr_csh0_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg1_set((hal_hyper_udma_mem_cfg1_get()
                                 & HYPER_MEM_CFG1_WR_CSH0_MASK_HB)
                                | (value << HYPER_MEM_CFG1_WR_CSH0_OFFSET));
}

/*
 * set hyper0 rd max length
 */
static inline void hal_hyper_udma_rd_max_length0_set(unsigned short value)
{
    hal_hyper_udma_mem_cfg2_set((hal_hyper_udma_mem_cfg2_get()
                                 & HYPER_MEM_CFG2_RD_MAX_LENGTH0_MASK_NB)
                                | (value << HYPER_MEM_CFG2_RD_MAX_LENGTH0_OFFSET));
}

/*
 * set hyper0 wr max length
 */
static inline void hal_hyper_udma_wr_max_length0_set(unsigned short value)
{
    hal_hyper_udma_mem_cfg2_set((hal_hyper_udma_mem_cfg2_get()
                                 & HYPER_MEM_CFG2_WR_MAX_LENGTH0_MASK_NB)
                                | (value << HYPER_MEM_CFG2_WR_MAX_LENGTH0_OFFSET));
}

/*
 * set hyper0 acs0
 */
static inline void hal_hyper_udma_acs0_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg3_set((hal_hyper_udma_mem_cfg3_get()
                                 & HYPER_MEM_CFG3_ACS0_MASK_B)
                                | (value << HYPER_MEM_CFG3_ACS0_OFFSET));
}

/*
 * set hyper0 tco0
 */
static inline void hal_hyper_udma_tco0_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg3_set((hal_hyper_udma_mem_cfg3_get()
                                 & HYPER_MEM_CFG3_TCO0_MASK_B)
                                | (value << HYPER_MEM_CFG3_TCO0_OFFSET));
}

/*
 * set hyper0 dt0
 */
static inline void hal_hyper_udma_dt0_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg3_set((hal_hyper_udma_mem_cfg3_get()
                                 & HYPER_MEM_CFG3_DT0_MASK_B)
                                | (value << HYPER_MEM_CFG3_DT0_OFFSET));
}

/*
 * set hyper0 crt
 */
static inline void hal_hyper_udma_crt0_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg3_set((hal_hyper_udma_mem_cfg3_get()
                                 & HYPER_MEM_CFG3_CRT0_MASK_B)
                                | (value << HYPER_MEM_CFG3_CRT0_OFFSET));
}


/*
 * set hyper0 rd max len en
 */
static inline void hal_hyper_udma_rd_maxlen_en0_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg3_set((hal_hyper_udma_mem_cfg3_get()
                                 & HYPER_MEM_CFG3_RD_MAX_LEN_EN0_MASK_B)
                                | (value << HYPER_MEM_CFG3_RD_MAX_LEN_EN0_OFFSET));
}


/*
 * set hyper0 wr max len en
 */
static inline void hal_hyper_udma_wr_maxlen_en0_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg3_set((hal_hyper_udma_mem_cfg3_get()
                                 & HYPER_MEM_CFG3_WR_MAX_LEN_EN0_MASK_B)
                                | (value << HYPER_MEM_CFG3_WR_MAX_LEN_EN0_OFFSET));
}

/*
 * set hyper0 rds delay adj
 */
static inline void hal_hyper_udma_rds_delay_adj_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg3_set((hal_hyper_udma_mem_cfg3_get()
                                 & HYPER_MEM_CFG3_RDS_DELAY_ADJ_MASK_THB)
                                | (value << HYPER_MEM_CFG3_RDS_DELAY_ADJ_OFFSET));
}

/*
 * set hyper1 base address
 */
static inline void hal_hyper_udma_mbr1_set(unsigned char mbr1)
{
    hal_hyper_udma_mem_cfg4_set((hal_hyper_udma_mem_cfg4_get()
                                 & HYPER_MEM_CFG4_MBR1_MASK_BYTE)
                                | (mbr1 << HYPER_MEM_CFG4_MBR1_OFFSET));
}

/*
 * set hyper1 wrap size
 */
static inline void hal_hyper_udma_wrap_size1_set(unsigned char wrapsize)
{
    hal_hyper_udma_mem_cfg4_set((hal_hyper_udma_mem_cfg4_get()
                                 & HYPER_MEM_CFG4_WRAP_SIZE1_MASK_TB)
                                | (wrapsize << HYPER_MEM_CFG4_WRAP_SIZE1_OFFSET));
}

/*
 * set hyper1 rd cshi
 */
static inline void hal_hyper_udma_rd_cshi1_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg5_set((hal_hyper_udma_mem_cfg5_get()
                                 & HYPER_MEM_CFG5_RD_CSHI1_MASK_HB)
                                | (value << HYPER_MEM_CFG5_RD_CSHI1_OFFSET));
}

/*
 * set hyper1 rd css
 */
static inline void hal_hyper_udma_rd_css1_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg5_set((hal_hyper_udma_mem_cfg5_get()
                                 & HYPER_MEM_CFG5_RD_CSS1_MASK_HB)
                                | (value << HYPER_MEM_CFG5_RD_CSS1_OFFSET));
}

/*
 * set hyper1 rd csh
 */
static inline void hal_hyper_udma_rd_csh1_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg5_set((hal_hyper_udma_mem_cfg5_get()
                                 & HYPER_MEM_CFG5_RD_CSH1_MASK_HB)
                                | (value << HYPER_MEM_CFG5_RD_CSH1_OFFSET));
}


/*
 * set hyper1 wr cshi
 */
static inline void hal_hyper_udma_wr_cshi1_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg5_set((hal_hyper_udma_mem_cfg5_get()
                                 & HYPER_MEM_CFG5_WR_CSHI1_MASK_HB)
                                | (value << HYPER_MEM_CFG5_WR_CSHI1_OFFSET));
}

/*
 * set hyper1 wr css
 */
static inline void hal_hyper_udma_wr_css1_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg5_set((hal_hyper_udma_mem_cfg5_get()
                                 & HYPER_MEM_CFG5_WR_CSS1_MASK_HB)
                                | (value << HYPER_MEM_CFG5_WR_CSS1_OFFSET));
}

/*
 * set hyper1 wr csh
 */
static inline void hal_hyper_udma_wr_csh1_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg5_set((hal_hyper_udma_mem_cfg5_get()
                                 & HYPER_MEM_CFG5_WR_CSH1_MASK_HB)
                                | (value << HYPER_MEM_CFG5_WR_CSH1_OFFSET));
}


/*
 * set hyper1 rd max length
 */
static inline void hal_hyper_udma_rd_max_length1_set(unsigned short value)
{
    hal_hyper_udma_mem_cfg6_set((hal_hyper_udma_mem_cfg6_get()
                                 & HYPER_MEM_CFG6_RD_MAX_LENGTH1_MASK_NB)
                                | (value << HYPER_MEM_CFG6_RD_MAX_LENGTH1_OFFSET));
}

/*
 * set hyper1 wr max length
 */
static inline void hal_hyper_udma_wr_max_length1_set(unsigned short value)
{
    hal_hyper_udma_mem_cfg6_set((hal_hyper_udma_mem_cfg6_get()
                                 & HYPER_MEM_CFG6_WR_MAX_LENGTH1_MASK_NB)
                                | (value << HYPER_MEM_CFG6_WR_MAX_LENGTH1_OFFSET));
}


/*
 * set hyper1 acs1
 */
static inline void hal_hyper_udma_acs1_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg7_set((hal_hyper_udma_mem_cfg7_get()
                                 & HYPER_MEM_CFG7_ACS1_MASK_B)
                                | (value << HYPER_MEM_CFG7_ACS1_OFFSET));
}

/*
 * set hyper1 tco1
 */
static inline void hal_hyper_udma_tco1_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg7_set((hal_hyper_udma_mem_cfg7_get()
                                 & HYPER_MEM_CFG7_TCO1_MASK_B)
                                | (value << HYPER_MEM_CFG7_TCO1_OFFSET));
}

/*
 * set hyper1 dt1
 */
static inline void hal_hyper_udma_dt1_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg7_set((hal_hyper_udma_mem_cfg7_get()
                                 & HYPER_MEM_CFG7_DT1_MASK_B)
                                | (value << HYPER_MEM_CFG7_DT1_OFFSET));
}

/*
 * set hyper1 crt
 */
static inline void hal_hyper_udma_crt1_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg7_set((hal_hyper_udma_mem_cfg7_get()
                                 & HYPER_MEM_CFG7_CRT1_MASK_B)
                                | (value << HYPER_MEM_CFG7_CRT1_OFFSET));
}


/*
 * set hyper1 rd max len en
 */
static inline void hal_hyper_udma_rd_maxlen_en1_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg7_set((hal_hyper_udma_mem_cfg7_get()
                                 & HYPER_MEM_CFG7_RD_MAX_LEN_EN1_MASK_B)
                                | (value << HYPER_MEM_CFG7_RD_MAX_LEN_EN1_OFFSET));
}


/*
 * set hyper1 wr max len en
 */
static inline void hal_hyper_udma_wr_maxlen_en1_set(unsigned char value)
{
    hal_hyper_udma_mem_cfg7_set((hal_hyper_udma_mem_cfg7_get()
                                 & HYPER_MEM_CFG7_WR_MAX_LEN_EN1_MASK_B)
                                | (value << HYPER_MEM_CFG7_WR_MAX_LEN_EN1_OFFSET));
}

/*
 * Enable the clock to the whole hyper IP
 * Needed prior to all other configuration of this IP
 */
static inline void hal_hyper_start_ip()
{
    plp_udma_cg_set(plp_udma_cg_get() | (1<<ARCHI_UDMA_HYPER_ID(0)));
}

/*
 * Disable the clock to the whole hyper IP
 */
static inline void hal_hyper_stop_ip()
{
    plp_udma_cg_set(plp_udma_cg_get() & (~(1 << ARCHI_UDMA_HYPER_ID(0))) & 0xffffffff);
}

/*
 * Hyper IP boot initialization
 */
/*
  PLP_BOOT_CODE __attribute__((constructor)) void plp_hyper_ip_init()
  {
  plp_trace(RT_TRACE_INIT, "Hyper IP driver initialization\n");

  plp_trace(RT_TRACE_INIT, "Hyper driver initialization done\n");
  }
*/


static inline void hal_hyper_ext_addr_set(unsigned int value)
{
    pulp_write32(ARCHI_UDMA_ADDR + HYPER_EXT_ADDR_OFFSET, value);
}

static inline void hal_hyper_ram_ext_addr_set(unsigned int value) {return hal_hyper_ext_addr_set(REG_MBR0 | value);}

static inline void hal_hyper_flash_ext_addr_set(unsigned int value) {return hal_hyper_ext_addr_set(REG_MBR1 | value);}

static inline void hal_hyper_enqueue(unsigned channelBase, unsigned int l2Addr, unsigned int ext_addr, unsigned int size, unsigned int cfg) {
  hal_hyper_ext_addr_set(ext_addr);
  plp_udma_enqueue(channelBase, l2Addr, size, cfg);
}

static inline void hal_hyper_ram_enqueue(unsigned channelBase, unsigned int l2Addr, unsigned int ext_addr, unsigned int size, unsigned int cfg) {
  hal_hyper_ram_ext_addr_set(ext_addr);
  plp_udma_enqueue(channelBase, l2Addr, size, cfg);
}

static inline void hal_hyper_flash_enqueue(unsigned channelBase, unsigned int l2Addr, unsigned int ext_addr, unsigned int size, unsigned int cfg) {
  hal_hyper_flash_ext_addr_set(ext_addr);
  plp_udma_enqueue(channelBase, l2Addr, size, cfg);
}


#endif
