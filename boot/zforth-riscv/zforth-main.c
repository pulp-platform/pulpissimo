/*
 * zForth main app for RISC-V. This is about the smallest environment in
 * which zForth can be useful. Memory could be saved by leaving out
 * ZF_ENABLE_BOOTSTRAP and provide the basic dictionary through some other
 * method, but that would make this example overly complicated.
 */

#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>

#include "libc.h"
#include "config.h"

#include "udma.h"

#include "zforth.h"
#include "boot_code.h"

static FILE f;

static char buf[256];

int __attribute__((noreturn)) zforth_main(void)
{
	/* Setup stdin/stdout */

	uart_open(UART_ID, UART_BAUDRATE);
	stdout = stdin = f;


	/* Initialize zforth */
	puts("booting zforth...");

	zf_init(0);
	zf_bootstrap();
	puts("done");
	zf_eval(": . 1 sys ;");
	zf_eval(": uartboot 3 sys ;");

/* #define ZFORTH_TEST */
#ifdef ZFORTH_TEST
	zf_result r = 0;

	r = zf_eval("5 5 + . ;");
	r = zf_eval(": plus  42 + ;");
	r = zf_eval("42 plus . ;");
	if (r != ZF_OK)
		puts("A");
	else
		puts("G");

	r = zf_eval(": emit    0 sys ;");

	r = zf_eval(": .       1 sys ;");

	r = zf_eval(": tell    2 sys ;");

	r = zf_eval(": quit    128 sys ;");

	r = zf_eval(": sin     129 sys ;");

	r = zf_eval(": include 130 sys ;");

	r = zf_eval(": save    131 sys ;");

	puts("-1");
	r = zf_eval(": !    0 !! ;");

	r = zf_eval(": @    0 @@ ;");

	r = zf_eval(": ,    0 ,, ;");

	r = zf_eval(": #    0 ## ;");


	puts("-2");
	r = zf_eval(": [ 0 compiling ! ; immediate");
	if (r != ZF_OK)
		puts("A");
	else
		puts("G");

	r = zf_eval(": ] 1 compiling ! ;");
	if (r != ZF_OK)
		puts("A");
	else
		puts("G");

	r = zf_eval(": postpone 1 _postpone ! ; immediate");
	if (r != ZF_OK)
		puts("A");
	else
		puts("G");

	puts("-3");
	zf_eval(": over 1 pick ;");
	zf_eval(": +!   dup @ rot + swap ! ;");
	zf_eval(": inc  1 swap +! ;");
	zf_eval(": dec  -1 swap +! ;");
	zf_eval(": <    - <0 ;");
	zf_eval(": >    swap < ;");
	zf_eval(": <=   over over >r >r < r> r> = + ;");
	zf_eval(": >=   swap <= ;");
	zf_eval(": =0   0 = ;");
	zf_eval(": not  =0 ;");
	zf_eval(": !=   = not ;");
	zf_eval(": cr   10 emit ;");
	zf_eval(": ..   dup . ;");
	zf_eval(": here h @ ;");

	puts("-4");
	zf_eval(": allot  h +!  ;");
	r = zf_eval(
		": var : postpone [ ' lit , here dup 5 + , ' exit , here swap ! 5 allot ;");
	if (r != ZF_OK)
		puts("A");

	puts("-5");
	zf_eval(": begin   here ; immediate");
	zf_eval(": again   ' jmp , , ; immediate");
	zf_eval(": until   ' jmp0 , , ; immediate");
	r = zf_eval(
		": times ' 1 - , ' dup , ' =0 , postpone until ; immediate");
	if (r != ZF_OK)
		puts("A");

	puts("-6");
	zf_eval(": if      ' jmp0 , here 999 , ; immediate");
	zf_eval(": unless  ' not , postpone if ; immediate");
	zf_eval(": else    ' jmp , here 999 , swap here swap ! ; immediate");
	r = zf_eval(": fi      here swap ! ; immediate");
	if (r != ZF_OK)
		puts("A");

	puts("-7");
	zf_eval(": i ' lit , 0 , ' pickr , ; immediate");
	zf_eval(": j ' lit , 2 , ' pickr , ; immediate");
	zf_eval(": do ' swap , ' >r , ' >r , here ; immediate");
	zf_eval(": loop+ ' r> , ' + , ' dup , ' >r , ' lit , 1 , ' pickr , ' > , ' jmp0 , , ' r> , ' drop , ' r> , ' drop , ; immediate");
	r = zf_eval(": loop ' lit , 1 , postpone loop+ ;  immediate");
	if (r != ZF_OK)
		puts("A");

	puts("-8");
	r = zf_eval(
		": s\" compiling @ if ' lits , here 0 , fi here begin key dup 34 = if drop compiling @ if here swap - swap ! else dup here swap - fi exit else , fi again ; immediate");
	if (r != ZF_OK)
		puts("A");

	puts("-9");
	r = zf_eval(
		": .\" compiling @ if postpone s\" ' tell , else begin key dup 34 = if drop exit else emit fi again fi ; immediate");
	if (r != ZF_OK)
		puts("A");

	puts("-10");
	r = zf_eval(".\" Welcome to zForth, \" here . .\" bytes used\" cr ;");
	if (r != ZF_OK)
		puts("A");
	else
		puts("G");

	r = zf_eval(": inner  0 do .\" x\" loop ;");
	if (r != ZF_OK)
		puts("A");
	else
		puts("G");

	r = zf_eval("1 inner cr");
	if (r != ZF_OK)
		puts("A");
	else
		puts("G");

	r = zf_eval("10 inner");
	if (r != ZF_OK)
		puts("A");
	else
		puts("G");


	r = zf_eval(": outer  20 0 do i inner cr loop ;");
	if (r != ZF_OK)
		puts("A");
	else
		puts("G");


	r = zf_eval("outer");
	if (r != ZF_OK)
		puts("A");
	else
		puts("G");

#endif
	/* Main loop: read words and eval */

	uint8_t l = 0;

	for (;;) {
		int c = getchar();
		putchar(c);
		if (c == 10 || c == 13) {
			zf_result r = zf_eval(buf);

/* shorter error message are available to 1. lower uart output bandwidth 2.
 * smaller binary size (rodata section) */
#ifdef ZF_VERBOSE_ERRORS
#define ZF_ABORT_DSTACK_OVERRUN_MSG    "dstack of"
#define ZF_ABORT_DSTACK_UNDERRUN_MSG   "dstack uf"
#define ZF_ABORT_RSTACK_OVERRUN_MSG    "rstack of"
#define ZF_ABORT_RSTACK_UNDERRUN_MSG   "rstack uf"
#define ZF_ABORT_OUTSIDE_MEM_MSG       "outside mem"
#define ZF_ABORT_INVALID_SIZE_MSG      "invalid size"
#define ZF_ABORT_INTERNAL_ERROR_MSG    "internal error"
#define ZF_ABORT_DIVISION_BY_ZERO_MSG  "div by 0"
#define ZF_ABORT_NOT_A_WORD_MSG	       "not a word"
#define ZF_ABORT_COMPILE_ONLY_WORD_MSG "compile-only word"
#else
#define ZF_ABORT_DSTACK_OVERRUN_MSG    "O"
#define ZF_ABORT_DSTACK_UNDERRUN_MSG   "U"
#define ZF_ABORT_RSTACK_OVERRUN_MSG    "V"
#define ZF_ABORT_RSTACK_UNDERRUN_MSG   "P"
#define ZF_ABORT_OUTSIDE_MEM_MSG       "M"
#define ZF_ABORT_INVALID_SIZE_MSG      "S"
#define ZF_ABORT_INTERNAL_ERROR_MSG    "I"
#define ZF_ABORT_DIVISION_BY_ZERO_MSG  "Z"
#define ZF_ABORT_NOT_A_WORD_MSG	       "N"
#define ZF_ABORT_COMPILE_ONLY_WORD_MSG "W"
#endif
			switch (r) {
			case ZF_OK:
				break;
			case ZF_ABORT_DSTACK_OVERRUN:
				puts(ZF_ABORT_DSTACK_OVERRUN_MSG);
				break;
			case ZF_ABORT_DSTACK_UNDERRUN:
				puts(ZF_ABORT_DSTACK_UNDERRUN_MSG);
				break;
			case ZF_ABORT_RSTACK_OVERRUN:
				puts(ZF_ABORT_RSTACK_OVERRUN_MSG);
				break;
			case ZF_ABORT_RSTACK_UNDERRUN:
				puts(ZF_ABORT_RSTACK_UNDERRUN_MSG);
				break;
			case ZF_ABORT_OUTSIDE_MEM:
				puts(ZF_ABORT_OUTSIDE_MEM_MSG);
				break;
			case ZF_ABORT_INVALID_SIZE:
				puts(ZF_ABORT_INVALID_SIZE_MSG);
				break;
			case ZF_ABORT_INTERNAL_ERROR:
				puts(ZF_ABORT_INTERNAL_ERROR_MSG);
				break;
			case ZF_ABORT_DIVISION_BY_ZERO:
				puts(ZF_ABORT_DIVISION_BY_ZERO_MSG);
				break;
			case ZF_ABORT_NOT_A_WORD:
				puts(ZF_ABORT_NOT_A_WORD_MSG);
				break;
			case ZF_ABORT_COMPILE_ONLY_WORD:
				puts(ZF_ABORT_COMPILE_ONLY_WORD_MSG);
				break;
			default:
				puts("A");
			}

			l = 0;
		} else if (l < sizeof(buf) - 1) {
			buf[l++] = c;
		}

		buf[l] = '\0';
	}
}


zf_input_state zf_host_sys(zf_syscall_id id, const char *input)
{
	char buf[16];

	switch ((int)id) {

	case ZF_SYSCALL_EMIT:
		putchar((char)zf_pop());
		fflush(&stdout);
		break;

	case ZF_SYSCALL_PRINT:
		itoa(zf_pop(), buf, 16); /* prefer hex */
		puts(buf);
		break;

	case ZF_SYSCALL_TELL: {
		zf_cell len = zf_pop();
		uint8_t *buf = (uint8_t *)zf_dump(NULL) + (int)zf_pop();
		for (zf_cell i = 0; i < len; i++)
			putchar(buf[i]);
		fflush(&stdout);

	case ZF_SYSCALL_BOOT_UART:
		boot_srec_uart();
		break;

	case ZF_SYSCALL_BOOT_JTAG:
		boot_jtag_openocd();
		break;

	case ZF_SYSCALL_BOOT_FLASH:
		boot_qspi(0, 1);
		break;


	} break;
	}

	return 0;
}


zf_cell zf_host_parse_num(const char *buf)
{
	char *end;
	zf_cell v = strtol(buf, &end, 0);
	if (*end != '\0') {
		zf_abort(ZF_ABORT_NOT_A_WORD);
	}
	return v;
}
