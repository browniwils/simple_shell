#include "main.h"

/**
 * _strcat_handler - concatenate two strings
 * @dest: destination string
 * @src: source string
 * Return: the dest
 */

char *_strcat_handler(char *dest, const char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

