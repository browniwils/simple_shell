#include "main.h"

/**
 * _cmp_chars_handler - compare strings
 * @str: input string
 * @delim: delimiter
 * Return: 1 if are equals otherwise 0
 */

int _cmp_chars_handler(char *str, const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
	{
		return (1);
	}
	return (0);
}

