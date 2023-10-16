#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>

typedef struct format
{
	char * iden;
	int (*f)();
} match;
int _printf(const char *format, ...);
int _putchar(char c);
int printf_char(va_list val);
int printf_string(va_list val);
int str_lenc(const char *str);
int str_len(char *str);
int print_37(void);
int print_int(va_list args);
int print_dec(va_list args);
int print_bin(va_list val);
int print_unsigned(va_list args);
int print_oct(va_list val);
int print_hex(va_list val);
int print_HEX(va_list val);
int print_ex_str(va_list val);
int print_HEX_extra(unsigned int num);
int print_pointer(va_list val);
int print_hex_extra(unsigned long int num);
int print_rev_str(va_list val);
int print_rot13(va_list val);

#endif
