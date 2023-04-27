#include "main.h"

/**
 * _strchr_handler - finds character in a string
 * @str: string
 * @c: character
 * Return: first occurrence of c
 */

char *_strchr_handler(char *str, char c)
{
	unsigned int i;

	for (i = 0; *(str + i) != '\0'; i++)
	{
		if (*(str + i) == c)
		{
			return (str + i);
		}
	}
	if (*(str + i) == c)
	{
		return (str + i);
	}
	return ('\0');
}

