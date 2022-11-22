#include "main.h"
/**
 * print_int - print number
 * @ap: arg list
 * Return: return printed character number
 */
int print_int(va_list ap)
{
	return (print_number(va_arg(ap, int)));
}
/**
 * print_binary - print number binary base
 * @ap: arg list
 * Return: return add
 */
int print_binary(va_list ap)
{
	char *str;
	int add = 0;
	unsigned int argt = va_arg(ap, unsigned int);

	if (!argt)
	{
		add += _puts("0", 0);
		return (add);
	}
	str = convert_base(argt, 2, 0);
	if (!str)
		return (0);
	add = _puts(str, 0);
	free(str);
	return (add);
}
/**
 * print_octal - print octal base
 * @ap: arg list
 * Return: return add
 */
int print_octal(va_list ap)
{
	char *str;
	int add;

	str = convert_base(va_arg(ap, unsigned int), 8, 0);
	add = _puts(str, 0);
	free(str);
	return (add);
}
/**
 * print_hexa_lower - print hexa lower
 * @ap: arg list
 * Return: return add
 */
int print_hexa_lower(va_list ap)
{
	char *str;
	int add;

	str = convert_base(va_arg(ap, unsigned int), 16, 0);
	add = _puts(str, 0);
	free(str);
	return (add);
}
/**
 * print_hexa_upper - print hexa upper
 * @ap: arg list
 * Return: return add
 */
int print_hexa_upper(va_list ap)
{
	char *str;
	int add;

	str = convert_base(va_arg(ap, unsigned int), 16, 1);
	add = _puts(str, 0);
	free(str);
	return (add);
}
