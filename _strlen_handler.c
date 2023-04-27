#include "main.h"

/**
 * _strlen_handler - gets the length of a string.
 * @str: string
 * Return: length.
 */

int _strlen_handler(const char *str)
{
	int s_len = 0;

	while (str[s_len] != 0)
	{
		s_len++;
	}
	return (s_len);
}

