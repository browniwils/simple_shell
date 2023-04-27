#include "main.h"

/**
 * *_strcpy_handler - copies string
 * @dest: destination string
 * @src: source string
 * Return: the dest
 */

char *_strcpy_handler(char *dest, char *src)
{

	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

