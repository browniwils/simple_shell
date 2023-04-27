#include "main.h"

/**
 * _without_comment_handler - deletes comments from the input
 * @src: input string
 * Return: processed string
 */

char *_without_comment_handler(char *src)
{
	int i, next;

	next = 0;
	for (i = 0; src[i]; i++)
	{
		if (src[i] == '#')
		{
			if (i == 0)
			{
				free(src);
				return (NULL);
			}
			if (src[i - 1] == ' ' || src[i - 1] == '\t' || src[i - 1] == ';')
			{
				next = i;
			}
		}
	}
	if (next != 0)
	{
		src = _realloc_handler(src, i, next + 1);
		src[next] = '\0';
	}
	return (src);
}
