#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: return
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - write all character from string to stdout
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
 * _strlen_recursion - return string length
 * @s: character pointer
 * Return: return 0
 */
int _strlen_recursion(char *s)
{
	if (*s != '\0')
	{
		return (_strlen_recursion(s + 1) + 1);
	}
	else
	{
		return (0);
	}
}
/**
 * _strdup - a pointer to a newly allocated space in memory
 * @str: char pointer to copy
 * Return: return character
 */
char *_strdup(char *str)
{
	char *s;
	int loop;

	if (str == NULL)
	{
		return (NULL);
	}
	s = malloc(sizeof(char) * (_strlen_recursion(str) + 1));
	if (s == NULL)
	{
		return (NULL);
	}
	for (loop = 0; loop < _strlen_recursion(str) + 1; loop++)
	{
		s[loop] = str[loop];
	}
	return (s);
}
