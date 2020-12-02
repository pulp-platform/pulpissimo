/*
 * Copyright (C) 2015 ETH Zurich, University of Bologna and GreenWaves Technologies
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

#include "config.h"
#include "hal/pulp.h"
#include "archi/pulp.h"
#include <stddef.h>

#define BOOT_STACK_SIZE  1024
#define MAX_NB_AREA 16

#if FLASH_BLOCK_SIZE > HYPER_FLASH_BLOCK_SIZE
#define BLOCK_SIZE FLASH_BLOCK_SIZE
#else
#define BLOCK_SIZE HYPER_FLASH_BLOCK_SIZE
#endif


typedef struct {
  unsigned char flashBuffer[FLASH_BLOCK_SIZE];
  unsigned int udma_buffer[256];
  int spi_flash_id;
  int step;
  flash_v2_header_t header;
  flash_v2_mem_area_t memArea[MAX_NB_AREA];
  char udma_uart_tx_buffer[1];
  unsigned char stack[BOOT_STACK_SIZE];
  int hyperflash;
  int blockSize;
  int qpi;

} boot_code_t;

#define PLP_L2_DATA      __attribute__((section(".ram")))

PLP_L2_DATA static boot_code_t    bootCode;

static void __attribute__((noreturn)) bootFromOther(int platform);

static void boot_abort() {
  hal_itc_enable_value_set(0);
  while(1)
  {
    hal_itc_wait_for_interrupt();
  }
}



#ifdef DEBUG

static void uart_sendchar(boot_code_t *data, const char c) {
  // setup next transfer
  data->udma_uart_tx_buffer[0] = c;
  plp_udma_enqueue(UDMA_UART_TX_ADDR(0), (int)data->udma_uart_tx_buffer, 1, UDMA_CHANNEL_CFG_EN);
  wait_soc_event(ARCHI_SOC_EVENT_UART_TX(0));
}

static void putch(boot_code_t *data, char c) {
  uart_sendchar(data, c);
}

static inline void step_ok(boot_code_t *data) {
  putch(data, 'A' + data->step);
  data->step++;
  putch(data, '\n');
}

static inline void step_ko(boot_code_t *data) {
  putch(data, '!');
  putch(data, '\n');
}

static inline void step_done(boot_code_t *data) {
  putch(data, '.');
  putch(data, '\n');
}

#endif




void wait_soc_event()
{
  hal_itc_enable_set(1 << ARCHI_FC_EVT_SOC_EVT);
  while(!((hal_itc_status_value_get() >> ARCHI_FC_EVT_SOC_EVT) & 1)) {
    hal_itc_wait_for_interrupt();
  }
  hal_itc_fifo_pop();
  hal_itc_status_clr(1 << ARCHI_FC_EVT_SOC_EVT);
  hal_itc_enable_clr(1 << ARCHI_FC_EVT_SOC_EVT);
}

static void flash_read(boot_code_t *data, unsigned int flashAddr, unsigned int l2Addr, unsigned int size)
{
  if (!data->hyperflash) {
    unsigned int *buffer = data->udma_buffer;
    int buff_size;
    buff_size = 7 * 4;
    *(volatile int *)&buffer[0] = SPI_CMD_CFG       (0, 0, 0);
    *(volatile int *)&buffer[1] = SPI_CMD_SOT       (0);
    *(volatile int *)&buffer[2] = SPI_CMD_SEND_CMD  (0x03, 8, SPI_CMD_QPI_DIS);
    *(volatile int *)&buffer[3] = SPI_CMD_SEND_BITS ((flashAddr>>8) & 0xFFFF,16, SPI_CMD_QPI_DIS);
    *(volatile int *)&buffer[4] = SPI_CMD_SEND_BITS (flashAddr & 0xFF,8, SPI_CMD_QPI_DIS);
    *(volatile int *)&buffer[5] = SPI_CMD_RX_DATA(size, SPI_CMD_4_WORD_PER_TRANSF, 8, SPI_CMD_QPI_DIS, SPI_CMD_MSB_FIRST);
    *(volatile int *)&buffer[6] = SPI_CMD_EOT       (1, 0);

    plp_udma_enqueue(UDMA_SPIM_RX_ADDR(0), l2Addr, size, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
    plp_udma_enqueue(UDMA_SPIM_CMD_ADDR(0), (unsigned int)data->udma_buffer, buff_size, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
    wait_soc_event();
  } else {
#ifdef PLP_UDMA_HAS_HYPER
    hal_hyper_flash_ext_addr_set((flashAddr));
    plp_udma_enqueue(UDMA_HYPER_RX_ADDR(0), l2Addr, size, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
    wait_soc_event();
#endif
  }
}



#ifdef PLP_UDMA_HAS_HYPER
static void flash_enqueueCommand(boot_code_t *data, unsigned short value, unsigned int addr) {
  short *buffer = (short *)data->udma_buffer;
  *buffer = value;
  hal_hyper_flash_ext_addr_set(addr<<1);
  plp_udma_enqueue(UDMA_HYPER_TX_ADDR(0), (int)buffer, 2, UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
  wait_soc_event();
}
#endif

static void flash_checkAndConf(boot_code_t *data)
{
  if (!data->hyperflash) {
  } else {

#ifdef PLP_UDMA_HAS_HYPER

    plp_udma_cg_set(plp_udma_cg_get() | (1<<UDMA_HYPER_ID(0)));

    // Set memory base address with RAM = 16M
    hal_hyper_udma_mbr0_set(REG_MBR0);
    hal_hyper_udma_mbr1_set(REG_MBR1>>24);

    /* Device type of connected memory */
    // HyperRAM
    hal_hyper_udma_dt0_set(1);
    // HyperFlash
    hal_hyper_udma_dt1_set(0);

    // When using flash, this bit should set to 0, always memory access
    hal_hyper_udma_crt1_set(MEM_ACCESS);

    hal_hyper_udma_crt0_set(MEM_ACCESS);

#endif

  }
}

void wait_clock_ref(int nbTicks) {
  hal_itc_enable_set(1<<ARCHI_FC_EVT_CLK_REF);
  for (int i=0; i<nbTicks; i++) {
    hal_itc_wait_for_interrupt();
    hal_itc_status_clr(1<<ARCHI_FC_EVT_CLK_REF);
  }
  hal_itc_enable_clr(1<<ARCHI_FC_EVT_CLK_REF);
}

static void init(boot_code_t *data)
{

  data->step = 0;

#ifdef DEBUG
  plp_udma_cg_set((1<<UDMA_UART_ID(0)));
  plp_uart_setup(0, UART_CLK_DIVIDER);
#endif

  plp_udma_cg_set(plp_udma_cg_get() | (1<<ARCHI_UDMA_SPIM_ID(0)));

#ifdef SOC_EU_VERSION
  // Deactivate all soc event to be able to wait on specific ones
  soc_eu_eventMask_reset(SOC_FC_FIRST_MASK);
  soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_SPIM0_EOT);
  soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_UART_TX(0));
#ifdef ARCHI_UDMA_HAS_HYPER
  soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_HYPER_RX(0));
  soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_HYPER_TX(0));
#endif
#endif

  // wait some time to have proper power up of external flash
  wait_clock_ref(20);

}

static void deinit(boot_code_t *data) {
  plp_uart_disable(0);
  soc_eu_eventMask_reset(SOC_FC_FIRST_MASK);
  plp_udma_cg_set(0);
}

void *memcpy(void *dest, const void *src, size_t len) {
  char *d = dest;
  const char *s = src;
  while (len--)
    *d++ = *s++;
  return dest;
}

static void load_section(boot_code_t *data, flash_v2_mem_area_t *area) {
  unsigned int flash_addr = area->start;
  unsigned int area_addr = area->ptr;
  unsigned int size = area->size;
  unsigned int i;

  int isL2Section = area_addr >= 0x1C000000 && area_addr < 0x1D000000;

  for (i = 0; i < area->blocks; i++) { // 4KB blocks

    unsigned int iterSize = data->blockSize;
    if (iterSize > size) iterSize = (size + 3) & 0xfffffffc;

    if (isL2Section) {
      flash_read(data, flash_addr, area_addr, iterSize);
    } else {
      flash_read(data, flash_addr, (unsigned int)(long)data->flashBuffer, iterSize);
      memcpy((void *)(long)area_addr, (void *)(long)data->flashBuffer, iterSize);
    }

    area_addr  += iterSize;
    flash_addr += iterSize;
    size       -= iterSize;
  }

}

static inline void __attribute__((noreturn)) jump_to_address(unsigned int address) {
  void (*entry)() = (void (*)())((long)address);
  entry();
  while(1);
}

static inline void __attribute__((noreturn)) jump_to_entry(flash_v2_header_t *header) {

  apb_soc_bootaddr_set(header->bootaddr);
  jump_to_address(header->entry);
  while(1);
}

__attribute__((noreturn)) void changeStack(boot_code_t *data, unsigned int entry, unsigned int stack);

static void getMemAreas(boot_code_t *data)
{
  flash_read(data, 0, (unsigned int)(long)&data->header, sizeof(data->header));

  int nbArea = data->header.nbAreas;
  if (nbArea >= MAX_NB_AREA) {
    nbArea = MAX_NB_AREA;
  }

  if (nbArea) flash_read(data, sizeof(flash_v2_header_t), (unsigned int)(long)data->memArea, nbArea*sizeof(flash_v2_mem_area_t));
}

static __attribute__((noreturn)) void loadBinaryAndStart(boot_code_t *data)
{

  getMemAreas(data);

  unsigned int i;
  for (i=0; i<data->header.nbAreas; i++) {
    load_section(data, &data->memArea[i]);
  }

  deinit(data);

  jump_to_entry(&data->header);
}

static __attribute__((noreturn)) void loadBinaryAndStart_newStack(boot_code_t *data)
{
  changeStack(data, (unsigned int)(long)loadBinaryAndStart, ((unsigned int)(long)data->stack) + BOOT_STACK_SIZE);
}


static boot_code_t *findDataFit(boot_code_t *data)
{
  unsigned int addr = 0x1c000000;
  unsigned int i;

  for (i=0; i<data->header.nbAreas; i++) {
    flash_v2_mem_area_t *area = &data->memArea[i];
    if ((addr >= area->ptr && addr < area->ptr + area->size)
      || (addr < area->ptr && addr + sizeof(boot_code_t) > area->ptr)) {
	addr = ((area->ptr + area->size) + data->blockSize - 1) & ~(data->blockSize - 1);
      }
  }
  return (boot_code_t *)(long)addr;
}

static void bootFromRom(int hyperflash, int qpi)
{
  boot_code_t *data = &bootCode;

  data->hyperflash = hyperflash;
  if (hyperflash) data->blockSize = HYPER_FLASH_BLOCK_SIZE;
  else data->blockSize = FLASH_BLOCK_SIZE;
  data->qpi = qpi;

  init(data);

  flash_checkAndConf(data);

  getMemAreas(data);

  boot_code_t *newData = findDataFit(data);
  newData->hyperflash = hyperflash;
  newData->qpi = qpi;
  if (hyperflash) newData->blockSize = HYPER_FLASH_BLOCK_SIZE;
  else newData->blockSize = FLASH_BLOCK_SIZE;

  loadBinaryAndStart_newStack(newData);

}

static void __attribute__((noreturn)) bootFromJtag()
{
  // Notify external env that we are ready for the loading
  apb_soc_jtag_reg_write(1);

  // Just wait until the external env notify us that the binary is loaded
  while(1) {
    unsigned int value = apb_soc_jtag_reg_read();
    if (apb_soc_jtag_reg_ext(value) & 1) break;
    wait_clock_ref(1);
  }

  // And jump to the loaded code
  jump_to_address(0x1c008080);

}

static __attribute__((noreturn)) void choose_boot_mode(int mode, int platform)
{
  switch (mode) {

    case APB_SOC_BOOT_SPIM:
      bootFromRom(0, 0);
      break;

    case APB_SOC_BOOT_JTAG:
      bootFromJtag();
      break;

    case APB_SOC_BOOT_OTHER:
      bootFromOther(platform);
      break;
  }
  while(1);
}

static void __attribute__((noreturn)) bootFromOther(int platform)
{
  // First jtag bit tell us what to do
  unsigned int value = apb_soc_jtag_reg_ext(apb_soc_jtag_reg_read());
  if (value) {
    // Value is not zero, check it to see how to boot
    unsigned int mode = ARCHI_REG_FIELD_GET(value, 1, APB_SOC_JTAG_REG_EXT_WIDTH-1);

    choose_boot_mode(mode, platform);

  }

  if (apb_soc_bootsel_get(ARCHI_APB_SOC_CTRL_ADDR))
  {
    // If bootsel pad is 1, it means an external loader wants us to stop so that it can take over
    boot_abort();
  }
  else
  {
    // Nothing was specified or something incorrect, just do the normal boot from rom
    bootFromRom(0, 1);
  }

  while(1);
}

void __attribute__((noreturn)) main()
{

  bootFromOther(APB_SOC_PLT_OTHER);

  while(1);
}
