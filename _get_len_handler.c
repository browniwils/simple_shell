#include "main.h"

/**
 * _get_len_handler - gets the lenght of number
 * @n: number.
 * Return: length
 */

int _get_len_handler(int n)
{
	unsigned int n1;
	int lenght = 1;

	if (n < 0)
	{
		lenght++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}
	while (n1 > 9)
	{
		lenght++;
		n1 = n1 / 10;
	}

	return (lenght);
}

