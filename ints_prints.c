#include "main.h"
/**
 * print_unsigned_number - print unsigned number
 * @n: unsigned
 * Return: return 0
 */
int print_unsigned_number(unsigned int n)
{
	int c = 0;
	unsigned int i = n;

	if (i <= 9)
	{
		_putchar(i + '0');
		return (1);
	}
	if (i > 9)
	{
		c = print_unsigned_number(i / 10) + 1;
		_putchar(i % 10 + '0');
		return (c);
	}
	return (0);
}
/**
 * print_number - display number
 * @n: integer
 * Return: return 0
 */
int print_number(int n)
{
	int c = 0;
	unsigned int i;

	i = n;
	if (n < 0)
	{
		_putchar('-');
		c++;
		i = -i;
	}
	if (i <= 9)
	{
		c += _putchar(i + '0');
		return (c);
	}
	if (i > 9)
	{
		c += print_number(i / 10) + 1;
		_putchar(i % 10 + '0');
		return (c);
	}
	return (0);
}
/**
 * nbr_len - number length
 * @prmNumber: number
 * Return: return loop
 */
int nbr_len(int prmNumber)
{
	int loop = 0, num;

	if (prmNumber == 0)
		return (1);

	num = prmNumber;

	if (num < 0)
	{
		num *= -1;
		loop++;	/* for the sign char */
	}

	while (num)
	{
		num /= 10;
		loop++;
	}

	return (loop);
}
/**
 * itoa - int to a string
 * @prmNumber: int
 * Return: return string
 */
char *itoa(int prmNumber)
{
	char *str;
	int loop;
	long num;

	num = prmNumber;
	loop = nbr_len(num);
	str = malloc(sizeof(char) * loop + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	str[loop] = '\0';
	if (num == 0)
	{
		str = "0";
	}
	else if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num)
	{
		str[--loop] = num % 10 + 48;
		num /= 10;
	}
	return (str);
}
