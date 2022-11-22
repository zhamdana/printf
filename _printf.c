#include "main.h"
/**
 * choose_operation - choose function to convert character
 * @c: check character
 * Return: return NULL
 */
int (*choose_operation(const char c))(va_list)
{
	int k = 0;

	conv_func fp[] = {
		{"c", print_character},
		{"s", print_string},
		{"i", print_int},
		{"d", print_int},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hexa_l},
		{"X", print_hexa_u},
		{"u", print_unsigned},
		{"S", print_unprintable},
		{"r", print_reverse},
		{"p", print_ptr},
		{"R", print_rot13},
		{"%", print_percent}
	};
	while (k < 14)
	{
		if (c == fp[k].c[0])
		{
			return (fp[k].f);
		}
		k++;
	}
	return (NULL);
}
/**
 * _printf - the same as printf function
 * @format: string format
 * Return: return add
 */
int _printf(const char *format, ...)
{
	va_list op;
	int add = 0, k = 0;
	int (*func)();

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(op, format);
	while (format[k])
	{
		if (format[k] == '%')
		{
			if (format[k + 1] != '\0')
				func = choose_operation(format[k + 1]);
			if (func == NULL)
			{
				_putchar(format[k]);
				add++;
				k++;
			}
			else
			{
				add += func(op);
				k += 2;
				continue;
			}
		}
		else
		{
			_putchar(format[k]);
			add++;
			k++;
		}
	}
	va_end(op);
	return (add);
}
