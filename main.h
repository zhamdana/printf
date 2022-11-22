#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
int _printf(const char *format, ...);
int print_character(va_list ap);
int print_string(va_list ap);
int print_int(va_list ap);
int print_binary(va_list ap);
int print_octal(va_list ap);
int print_hexa_l(va_list ap);
int print_hexa_u(va_list ap);
int print_unsigned(va_list ap);
int print_unprintable(va_list ap);
int print_reverse(va_list ap);
int print_ptr(va_list ap);
int print_rot13(va_list ap);
int print_percent(va_list ap __attribute__((unused)));
int print_number(int n);
int print_unsigned_number(unsigned int n);
int _putchar(char c);
int _puts(char *str, int ascii);
int _nbr_len(int prmNumber);
int _strlen_recursion(char *s);
int convert_alpha_numeric(int nb, int upper);
char *convert_rot13(char *str);
char *convert_base(unsigned long nb, unsigned int base, int upper);
char *_strdup(char *str);
char *convert_base_pointer(unsigned long p);
/**
 * struct conv_printf - struct for function conversion
 * @c: string
 * @f: pointer to function
 */
typedef struct conv_printf
{
	char *c;
	int (*f)(va_list);
} conv_func;
#endif
