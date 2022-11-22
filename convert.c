#include "main.h"
/**
 * convert_alpha_numeric - convert digits to character
 * @nb: digit
 * @upper: upper case check
 * Return: converted value
 */
int convert_alpha_numeric(int nb, int upper)
{
	if (nb >= 10)
		return (nb - 10 + ((upper) ? 'A' : 'a'));
	else
		return (nb + '0');
}
/**
 * convert_base - convert unsigned from base 10 to base
 * @nb: decimal number
 * @base: base to convert from
 * @upper: upper case check
 * Return: converted number to string
 */
char *convert_base(unsigned long nb, unsigned int base, int upper)
{
	int i = 0;
	char *str;
	unsigned long num = nb;

	while (num >= base)
	{
		num /= base;
		i++;
	}
	str = malloc(sizeof(char) * i + 2);
	if (!str)
		return (0);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		num = nb % base;
		str[i] = convert_alpha_numeric(num, upper);
		nb /= base;
		i--;
	}
	return (str);
}
/**
 * convert_base_pointer - convert pointer void to ul
 * @p: pointer
 * Return: converted string
 */
char *convert_base_pointer(unsigned long p)
{
	unsigned long address;
	char *str;

	address = p;
	if (address == 0)
		return ("0");
	str = convert_base(address, 16, 0);
	return (str);
}
/**
 * convert_rot13 - encode using rot13
 * @str: string to encode
 * Return: encoded string
 */
char *convert_rot13(char *str)
{
	int i = 0;
	char *s;
	int sz = _strlen_recursion(str);

	s = malloc(sizeof(char) * sz + 1);
	if (!s)
		return (0);
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
			s[i] = str[i] + 13;
		else if ((str[i] >= 'n' && str[i] <= 'z')
				|| (str[i] >= 'N' && str[i] <= 'Z'))
			s[i] = str[i] - 13;
		else
			s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
