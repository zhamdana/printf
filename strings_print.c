#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: -1 or 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - write all characters from string to stdout
 * @str: string to print
 * @ascii: enable ascii restriction
 * Return: return add
 */
int _puts(char *str, int ascii)
{
	char *s;
	int i = 0, add = 0;

	while (str[i])
	{
		if (((str[i] >= 0 && str[i] < 32) || str[i] >= 127) && ascii)
		{
			s = convert_base(str[i], 16, 1);
			add += write(1, "\\x", 2);
			if (str[i] >= 0 && str[i] < 16)
				add += _putchar('0');
			add += _puts(s, 0);
			free(s);
			i++;
		}
		else
		{
			add += _putchar(str[i]);
			i++;
		}
	}
	return (add);
}
/**
 * s_recursion - return string length
 * @s: character pointer
 * Return: return 0
 */
int s_recursion(char *s)
{
	if (*s != '\0')
	{
		return (s_recursion(s + 1) + 1);
	}
	else
	{
		return (0);
	}
}
/**
 * str_ptr - pointer to a new allocated space in memory
 * @str: char pointer
 * Return: return pointer
 */
char *str_ptr(char *str)
{
	char *s;
	int loop;

	if (str == NULL)
	{
		return (NULL);
	}
	s = malloc(sizeof(char) * (s_recursion(str) + 1));
	if (s == NULL)
	{
		return (NULL);
	}

	for (loop = 0; loop < s_recursion(str) + 1; loop++)
	{
		s[loop] = str[loop];
	}

	return (s);
}
