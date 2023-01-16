/*
 * Copyright (C) 2021 ETH Zurich, University of Bologna
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

#ifndef __LIBC_H____
#define __LIBC_H____
/* stdio.h */
typedef int FILE;

extern FILE stdout;
extern FILE stdin;

size_t strlen(const char *str);
int isspace(int c);
int isalpha(int c);
int isupper(int c);
int isascii(int c);
int isdigit(int c);

int putchar(int c);
char *itoa(int value, char *str, int base);
long strtol(const char *nptr, char **endptr, int base);

int puts(const char *str);
int getchar(void);
int fflush(FILE *stream);

#endif /* __LIBC_H__ */
