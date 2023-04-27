#include "main.h"

/**
 * _strcmp_handler - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 0 otherwise other number
 */

int _strcmp_handler(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i])
	{
		i++;
	}

	if (s1[i] > s2[i])
	{
		return (1);
	}
	if (s1[i] < s2[i])
	{
		return (-1);
	}
	return (0);
}

