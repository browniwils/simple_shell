#include "main.h"

/**
 * _strspn_handler - gets the length of a prefix substring
 * @src: initial segment.
 * @accept: accepted bytes.
 * Return: the number of accepted bytes.
 */

int _strspn_handler(char *src, char *accept)
{
	int i, j, b;

	for (i = 0; *(src + i) != '\0'; i++)
	{
		b = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(src + i) == *(accept + j))
			{
				b = 0;
				break;
			}
		}
		if (b == 1)
			break;
	}
	return (i);
}
