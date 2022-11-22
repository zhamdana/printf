#include "main.h"
/**
 * print_unsigned_number - print unsigned number
 * @n: unsigned int to print
 * Return: return 0
 */
int print_unsigned_number(unsigned int n)
{
	int c = 0;
	unsigned int op = n;

	if (op <= 9)
	{
		_putchar(op + '0');
		return (1);
	}
	if (op > 9)
	{
		c = print_unsigned_number(op / 10) + 1;
		_putchar(op % 10 + '0');
		return (c);
	}
	return (0);
}
/**
 * print_number - display the number contained in an int
 * @n: int to print
 * Return: number of char
 */
int print_number(int n)
{
	unsigned int op;
	int c = 0;

	op = n;
	if (n < 0)
	{
		_putchar('-');
		c++;
		op = -op;
	}
	if (op <= 9)
	{
		c += _putchar(op + '0');
		return (c);
	}
	if (op > 9)
	{
		c += print_number(op / 10) + 1;
		_putchar(op % 10 + '0');
		return (c);
	}
	return (0);
}
/**
 * _nbr_len - length of a number
 * @prmNumber: number
 * Return: length of the number
 */
int _nbr_len(int prmNumber)
{
	int loop = 0, numr;

	if (prmNumber == 0)
		return (1);

	numr = prmNumber;

	if (numr < 0)
	{
		numr *= -1;
		loop++;
	}
	while (numr)
	{
		numr /= 10;
		loop++;
	}
	return (loop);
}
/**
 * _itoa - Convert an int to a string
 * @prmNumber: int to convert
 * Return: converted string
 */
char *_itoa(int prmNumber)
{
	char *s;
	int loop;
	long numr;

	numr = prmNumber;
	loop = _nbr_len(numr);
	s = malloc(sizeof(char) * loop + 1);
	if (s == NULL)
	{
		return (NULL);
	}
	s[loop] = '\0';

	if (numr == 0)
	{
		s = "0";
	}
	else if (numr < 0)
	{
		s[0] = '-';
		numr *= -1;
	}
	while (numr)
	{
		s[--loop] = numr % 10 + 48;
		numr /= 10;
	}
	return (s);
}
