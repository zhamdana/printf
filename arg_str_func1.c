#include "main.h"
/**
 * print_character - print single char
 * @ap: arg list
 * Return: return
 */
int print_character(va_list ap)
{
	char c = va_arg(ap, int);

	if (c == '\0')
	{
		return (write(1, &c, 1));
	}
	_putchar(c);
	return (1);
}
/**
 * print_string - print string
 * @ap: arg list
 * Return: return printed character number
 */
int print_string(va_list ap)
{
	char *argt = va_arg(ap, char *);
	int add = 0;

	if (!argt)
	{
		add += _puts("(null)", 0);
		return (add);
	}
	return (_puts(argt, 0));
}
/**
 * print_unprintable - unprinted characters
 * @ap: arg list
 * Return: return printed character number
 */
int print_unprintable(va_list ap)
{
	char *argt = va_arg(ap, char *);
	int add = 0;

	if (!argt)
	{
		add += _puts("(null)", 0);
		return (add);
	}
	return (_puts(argt, 1));
}
/**
 * print_reverse - reverse a string
 * @ap: arg list
 * Return: return add
 */
int print_reverse(va_list ap)
{
	char *argt = va_arg(ap, char *), *str;
	int i, j, k, l, add = 0;

	if (!argt)
	{
		add += _puts("%r", 0);
		return (add);
	}
	i = _strlen_recursion(argt);
	l = i - 1;
	k = (i % 2 == 0) ? (i + 1) / 2 : (i / 2);
	str = malloc(iof(char) * i + 1);
	if (str == NULL)
	{
		return (0);
	}
	if (i % 2 != 0)
	{
		str[k] = argt[k];
	}
	for (j = 0; j < k; j++)
	{
		str[j] = argt[l];
		str[l] = argt[j];
		l--;
	}
	str[i] = '\0';
	add = _puts(str, 0);
	free(str);
	return (add);
}
/**
 * print_rot13 - print string
 * @ap: arg list
 * Return: return add
 */
int print_rot13(va_list ap)
{
	int add = 0;
	char *str, *argt = va_arg(ap, char*);

	if (!argt)
	{
		add += _puts("%R", 0);
		return (add);
	}
	str = convert_rot13(argt);
	if (!str)
		return (0);
	add = _puts(str, 0);
	free(str);
	return (add);
}
