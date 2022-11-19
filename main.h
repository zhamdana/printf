#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdarg.h>
int _printf(const char *format, ...);
int print_char(va_list ap);
int print_string(va_list ap);
int print_percent(va_list ap __attribute__((unused)));
int print_int(va_list ap);
int print_binary(va_list ap);
int print_octal(va_list ap);
int print_hex_l(va_list ap);
int print_hex_u(va_list ap);
int print_string_unprintable(va_list ap);
int print_ptr(va_list ap);
int print_string_reverse(va_list ap);
int print_R(va_list ap);
int print_unsigned(va_list ap);
int print_number(int n);
int print_unsigned_number(unsigned int n);
int _putchar(char c);
int _puts(char *str, int ascii);
int nbr_len(int prmNumber);
int s_recursion(char *s);
int convert_alpha_numeric(int nb, int upper);
char *convert_rot13(char *str);
char *convert_base(unsigned long nb, unsigned int base, int upper);
char *_strdup(char *str);
char *convert_base_pointer(unsigned long p);
/**
 * struct flags_printf - convert struct to function
 * @a: flag string
 * @f: pointer to function
 */
typedef struct flags_printf
{
	char *a;
	int (*f)(va_list);
} op_t;
#endif
