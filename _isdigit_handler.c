#include "main.h"

/**
 * _isdigit_handler - check string if its a number
 * @str: input string
 * Return: 1 if string is a number otherwise 0
 */

int _isdigit_handler(const char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 48 || str[i] > 57)
		{
			return (0);
		}
	}
	return (1);
}
