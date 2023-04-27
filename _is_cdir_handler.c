#include "main.h"

/**
 * _is_cdir_handler - checks colon in current directory
 * @path: path string
 * @i: index
 * Return: 1 if the path is in the current directory otherwise 0
 */

int _is_cdir_handler(char *path, int *i)
{
	if (path[*i] == ':')
	{
		return (1);
	}

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;

	return (0);
}

