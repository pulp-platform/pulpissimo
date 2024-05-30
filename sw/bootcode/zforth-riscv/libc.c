
/*-
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Copyright (c) 2020 ETH Zurich
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * From: @(#)strtol.c	8.1 (Berkeley) 6/4/93
 */

/* minimal additional symbols required to compile for risc-v withouth stdlib */

#include <stddef.h>
#include <limits.h>
#include <setjmp.h>
#include <stdint.h>

#include "libc.h"
#include "udma.h"

FILE stdout;
FILE stdin;

/* see setjmp.S
void longjmp(jmp_buf env, int val)
{
}
*/

/* see setjmp.S
int setjmp(jmp_buf env)
{
}
*/


size_t strlen(const char *str)
{
	const char *start = str;

	while (*str)
		str++;
	return str - start;
}

int isspace(int c)
{
	/* space, \f, \n, \r, \t and \v */
	return c == ' ' || (unsigned)c - '\t' < 5;
}

int isalpha(int c)
{
	return ((unsigned)c | 32) - 'a' < 26;
}

int isupper(int c)
{
	return (unsigned)c - 'A' < 26;
}

int isascii(int c)
{
	return !(c & ~0x7f);
}

int isdigit(int c)
{
	return (unsigned)c - '0' < 10;
}

/* freebsd strtol */
long strtol(const char *nptr, char **endptr, int base)
{
	const char *s = nptr;
	unsigned long acc;
	unsigned char c;
	unsigned long cutoff;
	int neg = 0, any, cutlim;

	/*
	 * Skip white space and pick up leading +/- sign if any.
	 * If base is 0, allow 0x for hex and 0 for octal, else
	 * assume decimal; if base is already 16, allow 0x.
	 */
	do {
		c = *s++;
	} while (isspace(c));
	if (c == '-') {
		neg = 1;
		c = *s++;
	} else if (c == '+')
		c = *s++;
	if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X')) {
		c = s[1];
		s += 2;
		base = 16;
	}
	if (base == 0)
		base = c == '0' ? 8 : 10;

	/*
	 * Compute the cutoff value between legal numbers and illegal
	 * numbers.  That is the largest legal value, divided by the
	 * base.  An input number that is greater than this value, if
	 * followed by a legal input character, is too big.  One that
	 * is equal to this value may be valid or not; the limit
	 * between valid and invalid numbers is then based on the last
	 * digit.  For instance, if the range for longs is
	 * [-2147483648..2147483647] and the input base is 10,
	 * cutoff will be set to 214748364 and cutlim to either
	 * 7 (neg==0) or 8 (neg==1), meaning that if we have accumulated
	 * a value > 214748364, or equal but the next digit is > 7 (or 8),
	 * the number is too big, and we will return a range error.
	 *
	 * Set any if any `digits' consumed; make it negative to indicate
	 * overflow.
	 */
	cutoff = neg ? -(unsigned long)LONG_MIN : LONG_MAX;
	cutlim = cutoff % (unsigned long)base;
	cutoff /= (unsigned long)base;
	for (acc = 0, any = 0;; c = *s++) {
		if (!isascii(c))
			break;
		if (isdigit(c))
			c -= '0';
		else if (isalpha(c))
			c -= isupper(c) ? 'A' - 10 : 'a' - 10;
		else
			break;
		if (c >= base)
			break;
		if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
			any = -1;
		else {
			any = 1;
			acc *= base;
			acc += c;
		}
	}
	if (any < 0) {
		acc = neg ? LONG_MIN : LONG_MAX;
	} else if (neg)
		acc = -acc;
	if (endptr != NULL)
		*endptr = __DECONST(char *, any ? s - 1 : nptr);
	return (acc);
}

char *__utoa(unsigned value, char *str, int base)
{
	const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	int i, j;
	unsigned remainder;
	char c;

	/* Check base is supported. */
	if ((base < 2) || (base > 36)) {
		str[0] = '\0';
		return NULL;
	}

	/* Convert to string. Digits are in reverse order.  */
	i = 0;
	do {
		remainder = value % base;
		str[i++] = digits[remainder];
		value = value / base;
	} while (value != 0);
	str[i] = '\0';

	/* Reverse string.  */
	for (j = 0, i--; j < i; j++, i--) {
		c = str[j];
		str[j] = str[i];
		str[i] = c;
	}

	return str;
}

char *itoa(int value, char *str, int base)
{
	unsigned uvalue;
	int i = 0;

	/* Check base is supported. */
	if ((base < 2) || (base > 36)) {
		str[0] = '\0';
		return NULL;
	}

	/* Negative numbers are only supported for decimal.
	 * Cast to unsigned to avoid overflow for maximum negative value.  */
	if ((base == 10) && (value < 0)) {
		str[i++] = '-';
		uvalue = (unsigned)-value;
	} else
		uvalue = (unsigned)value;

	__utoa(uvalue, &str[i], base);
	return str;
}


/* gcc is allowed to insert calls to memcpy in a freestanding environment, but
 * sometimes discards this function despite being used...
 * https://gcc.gnu.org/bugzilla/show_bug.cgi?id=65199
 */
__attribute__((used)) void *memcpy(void *dest, const void *src, size_t n)
{
	char *destc = dest;
	const char *srcc = src;

	while (n--)
		*destc++ = *srcc++;

	return dest;
}

int memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *l = s1, *r = s2;
	for (; n && *l == *r; n--, l++, r++)
		;
	return n ? *l - *r : 0;
}

int getchar(void)
{
	return uart_read_char(UART_ID);
}

static char write_buf[16] = {0};
static unsigned int write_cnt = 0;

int putchar(int c)
{
	if (write_cnt < sizeof(write_buf))
		write_buf[write_cnt++] = c;

	/* line or size buffer chars. Amortize the costs of launching a dma
	 * transfer. */
	if (write_cnt == sizeof(write_buf) || c == '\n')
		fflush(&stdout);

	return 0;
}

int puts(const char *str)
{
	char c;
	do {
		c = *str;
		if (c == 0) {
			putchar('\n');
			break;
		}
		putchar(c);
		str++;
	} while (1);
	return 0;
}

int fflush(FILE* stream)
{
	uart_write(UART_ID, &write_buf, write_cnt);
	write_cnt = 0;
	return 0;
}

__attribute__((noreturn)) void exit(int status)
{
	uintptr_t exit_reg = EXIT_REG_ADDR;
	/* top bit signals that exit was triggered, lower bits determine exit
	 * value*/
	*(volatile uint32_t *)exit_reg = status | 0x80000000;
	for (;;)
		;
}
