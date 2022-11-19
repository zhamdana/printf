#include "main.h"
/**
 * conver_func - chooses function to convert character
 * @a: character requiring check
 * Return: NULL
 */
int (*conver_func(const char a))(va_list)
{
	int k = 0;

	op_t fp[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent}
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hex_l},
		{"X", print_hex_u},
		{"S", print_string_unprintable},
		{"p", print_ptr},
		{"r", print_string_reverse},
		{"R", print_R},
	};
	while (k < 14)
	{
		if (a == fp[k].a[0])
		{
			return (fp[k].f);
		}
		k++;
	}
	return (NULL);
}
/**
 * _printf - operates like printf function
 * @format: format string
 * Return: returns printed character value
 */
int _printf(const char *format, ...)
{
	va_list op;
	int add = 0, i = 0;
	int (*func)();

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(op, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
				func = conver_func(format[i + 1]);
			if (func == NULL)
			{
				_putchar(format[i]);
				add++;
				i++;
			}
			else
			{
				add += func(op);
				i += 2;
				continue;
			}
		}
		else
		{
			_putchar(format[i]);
			add++;
			i++;
		}
	}
	va_end(op);
	return (add);
}
