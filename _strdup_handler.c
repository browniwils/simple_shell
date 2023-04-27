#include "main.h"

/**
 * _strdup_handler - duplicates string
 * @str: string
 * Return: string
 */

char *_strdup_handler(const char *str)
{
	char *new_str;
	size_t str_len;

	str_len = _strlen_handler(str);
	new_str = malloc(sizeof(char) * (str_len + 1));
	if (new_str == NULL)
	{
		return (NULL);
	}
	_memcpy_handler(new_str, str, str_len + 1);
	return (new_str);
}

