#include "main.h"

/**
 * _atoi_handler - converts a string to an integer.
 * @str: input string.
 * Return: integer.
 */

int _atoi_handler(char *str)
{
	unsigned int count = 0, size = 0, toi = 0, n = 1, m = 1, i;

	while (*(str + count) != '\0')
	{
		if (size > 0 && (*(str + count) < '0' || *(str + count) > '9'))
			break;

		if (*(str + count) == '-')
			n *= -1;

		if ((*(str + count) >= '0') && (*(str + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		toi = toi + ((*(str + i) - 48) * m);
		m /= 10;
	}
	return (toi * n);
}
