/*
 * Copyright (C) 2021 ETH Zurich, University of Bologna and GreenWaves
 * Technologies
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

#include <stdbool.h>
#include <stddef.h>

#include "config.h"
#include "hal/pulp.h"
#include "archi/pulp.h"

#include "libc.h"
#include "udma.h"
#include "kk_srec.h"
#include "io_mux.h"

#define BOOT_STACK_SIZE 1024
#define MAX_NB_AREA 16

#ifndef UART_TX_PAD
#define UART_TX_PAD PAD_GPIO00
#endif
#ifndef UART_RX_PAD
#define UART_RX_PAD PAD_GPIO01
#endif
#ifndef SPI_SCK_PAD
#define SPI_SCK_PAD PAD_GPIO02
#endif
#ifndef SPI_CSN_PAD
#define SPI_CSN_PAD PAD_GPIO03
#endif
#ifndef SPI_MOSI_PAD
#define SPI_MOSI_PAD PAD_GPIO04
#endif
#ifndef SPI_MISO_PAD
#define SPI_MISO_PAD PAD_GPIO05
#endif

void io_mux_expose_uart() {
  io_mux_mode_set(UART_TX_PAD, PAD_MODE_UART0_TX);
  io_mux_mode_set(UART_RX_PAD, PAD_MODE_UART0_RX);
}

void io_mux_expose_spi() {
  io_mux_mode_set(SPI_SCK_PAD, PAD_MODE_QSPIM0_SCK);
  io_mux_mode_set(SPI_CSN_PAD, PAD_MODE_QSPIM0_CSN0);
  io_mux_mode_set(SPI_MOSI_PAD, PAD_MODE_QSPIM0_SDIO0);
  io_mux_mode_set(SPI_MISO_PAD, PAD_MODE_QSPIM0_SDIO1);
}

#if FLASH_BLOCK_SIZE > HYPER_FLASH_BLOCK_SIZE
#    define BLOCK_SIZE FLASH_BLOCK_SIZE
#else
#    define BLOCK_SIZE HYPER_FLASH_BLOCK_SIZE
#endif

#ifndef SPI_MAX_CLK
#    error "SPI_MAX_CLK is not defined. Required for driving SPI correctly \
when using SPI boot."
#endif

void *memcpy(void *dest, const void *src, size_t n);
int __attribute__((noreturn)) zforth_main(void);

void pos_fll_constructor();
unsigned int pos_fll_set_freq(int fll, unsigned int frequency);
unsigned int pos_fll_init(int fll);

typedef struct {
    unsigned char flash_buffer[FLASH_BLOCK_SIZE];
    unsigned int udma_buffer[256];
    int spi_flash_id;
    int step;
    flash_v2_header_t header;
    flash_v2_mem_area_t mem_area[MAX_NB_AREA];
    char udma_uart_tx_buffer[1];
    unsigned char stack[BOOT_STACK_SIZE];
    int hyperflash;
    int blockSize;
    int qpi;
} boot_code_t;

__attribute__((section(".noinit"))) boot_code_t boot_code;


/* assembly */
__attribute__((noreturn)) void
change_stack(boot_code_t *data, unsigned int entry, unsigned int stack);

/* uart debugging for boot rom */
#ifdef DEBUG_BOOTROM
static void uart_sendchar(boot_code_t *data, const char c)
{
    /* setup next transfer */
    data->udma_uart_tx_buffer[0] = c;
    plp_udma_enqueue(UDMA_UART_TX_ADDR(0), (int)data->udma_uart_tx_buffer, 1,
                     UDMA_CHANNEL_CFG_EN);
    wait_soc_event(ARCHI_SOC_EVENT_UART_TX(0));
}

static void debug_putch(boot_code_t *data, char c)
{
    uart_sendchar(data, c);
}

static inline void debug_step_ok(boot_code_t *data)
{
    debug_putch(data, 'A' + data->step);
    data->step++;
    debug_putch(data, '\n');
}

static inline void debug_step_ko(boot_code_t *data)
{
    debug_putch(data, '!');
    debug_putch(data, '\n');
}

static inline void debug_step_done(boot_code_t *data)
{
    debug_putch(data, '.');
    debug_putch(data, '\n');
}
#endif

void wait_soc_event()
{
    hal_itc_enable_set(1 << ARCHI_FC_EVT_SOC_EVT);

    while (!((hal_itc_status_value_get() >> ARCHI_FC_EVT_SOC_EVT) & 1))
        hal_itc_wait_for_interrupt();

    hal_itc_fifo_pop();
    hal_itc_status_clr(1 << ARCHI_FC_EVT_SOC_EVT);
    hal_itc_enable_clr(1 << ARCHI_FC_EVT_SOC_EVT);
}

void wait_clock_ref(int nbTicks)
{
    hal_itc_enable_set(1 << ARCHI_FC_EVT_CLK_REF);
    for (int i = 0; i < nbTicks; i++) {
        hal_itc_wait_for_interrupt();
        hal_itc_status_clr(1 << ARCHI_FC_EVT_CLK_REF);
    }
    hal_itc_enable_clr(1 << ARCHI_FC_EVT_CLK_REF);
}

static inline void __attribute__((noreturn))
jump_to_address(unsigned int address)
{
    goto *(uint32_t *)address;

    for (;;)
        ;
}

static inline void __attribute__((noreturn))
jump_to_entry(flash_v2_header_t *header)
{

    apb_soc_bootaddr_set(header->bootaddr);
    jump_to_address(header->entry);

    for (;;)
        ;
}

static void flash_read(boot_code_t *data, unsigned int flash_addr,
                       unsigned int l2_addr, unsigned int size)
{
    if (!data->hyperflash) {
        unsigned int *buffer = data->udma_buffer;
        int buff_size        = 7 * 4;
        /* make sure we don't exceed the max allowed SPI clk frequency. Ceiling
         * division.*/
        int div = (PERIPH_FREQUENCY + SPI_MAX_CLK - 1) / SPI_MAX_CLK;
        *(volatile int *)&buffer[0] = SPI_CMD_CFG(div - 1, 0, 0);
        *(volatile int *)&buffer[1] = SPI_CMD_SOT(0);
        *(volatile int *)&buffer[2] =
            SPI_CMD_SEND_CMD(0x03, 8, SPI_CMD_QPI_DIS);
        *(volatile int *)&buffer[3] =
            SPI_CMD_SEND_BITS((flash_addr >> 8) & 0xFFFF, 16, SPI_CMD_QPI_DIS);
        *(volatile int *)&buffer[4] =
            SPI_CMD_SEND_BITS(flash_addr & 0xFF, 8, SPI_CMD_QPI_DIS);
        *(volatile int *)&buffer[5] =
            SPI_CMD_RX_DATA(size, SPI_CMD_4_WORD_PER_TRANSF, 8, SPI_CMD_QPI_DIS,
                            SPI_CMD_MSB_FIRST);
        *(volatile int *)&buffer[6] = SPI_CMD_EOT(1, 0);

        plp_udma_enqueue(UDMA_SPIM_RX_ADDR(SPI_ID), l2_addr, size,
                         UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
        plp_udma_enqueue(UDMA_SPIM_CMD_ADDR(SPI_ID),
                         (unsigned int)data->udma_buffer, buff_size,
                         UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
        wait_soc_event();
    } else {
#ifdef PLP_UDMA_HAS_HYPER
        hal_hyper_flash_ext_addr_set((flash_addr));
        plp_udma_enqueue(UDMA_HYPER_RX_ADDR(0), l2_addr, size,
                         UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
        wait_soc_event();
#endif
    }
}

#ifdef PLP_UDMA_HAS_HYPER
static void flash_enqueue_command(boot_code_t *data, unsigned short value,
                                  unsigned int addr)
{
    short *buffer = (short *)data->udma_buffer;
    *buffer       = value;
    hal_hyper_flash_ext_addr_set(addr << 1);
    plp_udma_enqueue(UDMA_HYPER_TX_ADDR(0), (int)buffer, 2,
                     UDMA_CHANNEL_CFG_EN | UDMA_CHANNEL_CFG_SIZE_32);
    wait_soc_event();
}
#endif

static void flash_conf(boot_code_t *data)
{
    if (!data->hyperflash) {

    } else {

#ifdef PLP_UDMA_HAS_HYPER
        plp_udma_cg_set(plp_udma_cg_get() | (1 << UDMA_HYPER_ID(0)));

        /* Set memory base address with RAM = 16M */
        hal_hyper_udma_mbr0_set(REG_MBR0);
        hal_hyper_udma_mbr1_set(REG_MBR1 >> 24);

        /* Device type of connected memory */
        /*  HyperRAM */
        hal_hyper_udma_dt0_set(1);
        /*  HyperFlash */
        hal_hyper_udma_dt1_set(0);

        /* When using flash, this bit should set to 0, always memory access */
        hal_hyper_udma_crt1_set(MEM_ACCESS);

        hal_hyper_udma_crt0_set(MEM_ACCESS);

#endif
    }
}

static void flash_init(boot_code_t *data)
{
    data->step = 0;

#ifdef DEBUG_BOOTROM
    // Expose UART
    io_mux_expose_uart();
    /* boot a srec dump of a binary over udma uart */
    uart_open(UART_ID, UART_BAUDRATE);
#endif

    plp_udma_cg_set(plp_udma_cg_get() | (1 << ARCHI_UDMA_SPIM_ID(SPI_ID)));

#ifdef SOC_EU_VERSION
    /* Deactivate all soc event to be able to wait on specific ones */
    soc_eu_eventMask_reset(SOC_FC_FIRST_MASK);
    soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_SPIM_EOT(SPI_ID));
    soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_UART_TX(0));
#    ifdef ARCHI_UDMA_HAS_HYPER
    soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_HYPER_RX(0));
    soc_eu_fcEventMask_setEvent(ARCHI_SOC_EVENT_HYPER_TX(0));
#    endif
#endif

    /* wait some time to have proper power up of external flash */
    wait_clock_ref(20);
}

static void flash_deinit(boot_code_t *data)
{
    hal_uart_disable(0);
    soc_eu_eventMask_reset(SOC_FC_FIRST_MASK);
    plp_udma_cg_set(0);
}

static void flash_load_section(boot_code_t *data, flash_v2_mem_area_t *area)
{
    unsigned int flash_addr = area->start;
    unsigned int area_addr  = area->ptr;
    unsigned int size       = area->size;
    unsigned int i;

    /* TODO: hardcoded */
    int is_l2_section = area_addr >= 0x1C000000 && area_addr < 0x1D000000;

    for (i = 0; i < area->blocks; i++) { // 4KB blocks

        unsigned int iter_size = data->blockSize;
        if (iter_size > size)
            iter_size = (size + 3) & 0xfffffffc;

        if (is_l2_section) {
            flash_read(data, flash_addr, area_addr, iter_size);
        } else {
            flash_read(data, flash_addr, (unsigned int)(long)data->flash_buffer,
                       iter_size);
            memcpy((void *)(long)area_addr, (void *)(long)data->flash_buffer,
                   iter_size);
        }

        area_addr += iter_size;
        flash_addr += iter_size;
        size -= iter_size;
    }
}

static void flash_get_mem_sections(boot_code_t *data)
{
    flash_read(data, 0, (unsigned int)(long)&data->header,
               sizeof(data->header));

    int nb_area = data->header.nbAreas;
    if (nb_area >= MAX_NB_AREA) {
        nb_area = MAX_NB_AREA;
    }

    if (nb_area)
        flash_read(data, sizeof(flash_v2_header_t),
                   (unsigned int)(long)data->mem_area,
                   nb_area * sizeof(flash_v2_mem_area_t));
}

static __attribute__((noreturn)) void flash_load_and_start(boot_code_t *data)
{

    flash_get_mem_sections(data);

    for (unsigned int i = 0; i < data->header.nbAreas; i++)
        flash_load_section(data, &data->mem_area[i]);

    flash_deinit(data);

    jump_to_entry(&data->header);
}

static boot_code_t *find_data_fit(boot_code_t *data)
{
    unsigned int addr = 0x1c000000;
    unsigned int i;

    for (i = 0; i < data->header.nbAreas; i++) {
        flash_v2_mem_area_t *area = &data->mem_area[i];
        if ((addr >= area->ptr && addr < area->ptr + area->size) ||
            (addr < area->ptr && addr + sizeof(boot_code_t) > area->ptr)) {
            addr = ((area->ptr + area->size) + data->blockSize - 1) &
                   ~(data->blockSize - 1);
        }
    }
    return (boot_code_t *)(long)addr;
}

/* srec: write program to l2 and jump to entry point */
void srec_data_read(struct srec_state *srec, srec_record_number_t record_type,
                    srec_address_t address, uint8_t *data, srec_count_t length,
                    srec_bool_t checksum_error)
{
    if (srec->length != srec->byte_count) {
        if (srec->byte_count > SREC_LINE_MAX_BYTE_COUNT) {
            puts("Error: Byte count too high");
        } else {
            puts("Error: Byte count mismatch");
        }
    }
    if (checksum_error)
        puts("Error: Checksum mismatch");

    if (SREC_IS_DATA(record_type)) {
        /* note that memcpy is incompatible with volatile arrays so we need to
         * loop. Also, we don't care if the compiler reorders these volatile
         * accesses which is why we don't play around with compiler barriers. */
        for (int i = 0; i < length; i++)
            *((volatile uint32_t*)(address+i)) = data[i];

    } else if (SREC_IS_TERMINATION(record_type)) {
        uint32_t *bootaddr = (uint32_t *)address;
        goto *bootaddr; /* gcc extension */
    } else if (record_type == 0){
	/* header record */
    }
}

void __attribute__((noreturn)) boot_qspi(int hyperflash, int qpi)
{
    /* TODO: verify this boot mode */
    boot_code_t *data = &boot_code;

    data->hyperflash = hyperflash;
    if (hyperflash)
        data->blockSize = HYPER_FLASH_BLOCK_SIZE;
    else
        data->blockSize = FLASH_BLOCK_SIZE;

    data->qpi = qpi;

    flash_init(data);

    flash_conf(data);

    flash_get_mem_sections(data);

    boot_code_t *new_data = find_data_fit(data);
    new_data->hyperflash  = hyperflash;
    new_data->qpi         = qpi;
    if (hyperflash)
        new_data->blockSize = HYPER_FLASH_BLOCK_SIZE;
    else
        new_data->blockSize = FLASH_BLOCK_SIZE;

    change_stack(new_data, (unsigned int)(long)flash_load_and_start,
                 ((unsigned int)(long)new_data->stack) + BOOT_STACK_SIZE);

    for (;;)
        ;
}

void __attribute__((noreturn)) boot_srec_uart(void)
{
    /* boot a srec dump of a binary over udma uart */
    uart_open(UART_ID, UART_BAUDRATE);

    struct srec_state srec;
    srec_begin_read(&srec);
    for (;;) {
        int c = getchar();
        putchar(c);
        srec_read_byte(&srec, (char)c);
    }
}

void __attribute__((noreturn)) boot_preloaded(void)
{
    /* load bootaddr and jump there */
    uint32_t *bootaddr = (uint32_t *)apb_soc_bootaddr_get();
    goto *bootaddr; /* gcc extension */
}

void __attribute__((noreturn)) boot_jtag_openocd(void)
{
    /* wait for openocd to take over */
    /* TODO: do we need this hal_itc_enable_value_set(0); */

    for (;;)
        asm volatile("wfi");
}

static void __attribute__((noreturn)) boot_zforth(void)
{
    zforth_main();
}
/* some default */
#define BOOT_MODE_DEFAULT 0
/* trigger fetch enable, busy loop. OpenOCD can take over the hart safely */
#define BOOT_MODE_JTAG_OPENOCD 1
/* trigger fetch enable, read binary from qspi, read entry point from
 * binary, execute */
#define BOOT_MODE_QSPI 2
/* preload the memory with binary, write entry point to BOOTADDR register,
 * trigger fetch enable register through write or signal */
#define BOOT_MODE_PRELOADED 3

void __attribute__((noreturn)) main(void)
{
    /*
     *  Current boot modes:
     *  bootsel     meaning
     *  2'b0        default boot (to be determined)
     *  2'b1        jtag boot for openocd (busy loop)
     *  2'b2        qspi boot (read from flash and jump to entry)
     *  2'b3        preloaded boot (jump to address in bootaddr register)
     */

    /* On the cv32e40p, we need to enable all interrupts in the core because we
     * intend to only use the apb_interrupt_cntrl to manage interrupts */
    hal_spr_write(CSR_MIE, 0xffffffff);

    switch (apb_soc_bootsel_get(ARCHI_APB_SOC_CTRL_ADDR) & 3) {
    case BOOT_MODE_DEFAULT:
#ifdef CONFIG_FLL
	      /* zforth/srec need a stable periperal frequency */
        pos_fll_constructor();
        pos_fll_init(POS_FLL_PERIPH);
        pos_fll_set_freq(POS_FLL_PERIPH, PERIPH_FREQUENCY);
#endif
#ifdef ENABLE_ZFORTH_BOOT
        // Both, zforth and uart boot need the UART peripheral to be exposed. Configure the padmux
        io_mux_expose_uart();
        boot_zforth();
#elif ENABLE_UART_BOOT
        // Both, zforth and uart boot need the UART peripheral to be exposed. Configure the padmux
        io_mux_expose_uart();
        boot_srec_uart();
#endif
        break;
    case BOOT_MODE_JTAG_OPENOCD:
        boot_jtag_openocd();
        break;
    case BOOT_MODE_QSPI:
#ifdef ENABLE_QSPI_BOOT
        // Expose to QSPI Pads
        io_mux_expose_spi();
        boot_qspi(0, 1);
#endif
        break;
    case BOOT_MODE_PRELOADED:
        boot_preloaded();
        break;
    default: /* not possible */
        break;
    }

    /* TODO: determine fallback boot mode */
    for (;;)
        ;
}
