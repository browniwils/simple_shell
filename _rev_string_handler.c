#include "main.h"

/**
 * _rev_string_handler - reverses a string
 * @src: input string
 */

void _rev_string_handler(char *src)
{
	int count = 0, i, j;
	char *str, temp;

	while (count >= 0)
	{
		if (src[count] == '\0')
		{
			break;
		}
		count++;
	}
	str = src;
	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}

