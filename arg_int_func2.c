#include "main.h"
/**
 * print_unsigned - manage unsigned int
 * @ap: arg list
 * Return: value number of printed chars
 */
int print_unsigned(va_list ap)
{
	unsigned int argument = va_arg(ap, unsigned int);

	return (print_unsigned_number(argument));
}
/**
 * print_ptr - print adress
 * @ap: arg void
 * Return: return add
 */
int print_ptr(va_list ap)
{
	char *str;
	int add = 0;
	unsigned long ptr = (unsigned long) va_arg(ap, void*);

	if (!ptr)
	{
		add += _puts("(nil)", 0);
		return (add);
	}
	str = convert_base_pointer(ptr);
	if (!str)
		return (0);
	add += _puts("0x", 0);
	add += _puts(str, 0);
	free(str);
	return (add);
}
