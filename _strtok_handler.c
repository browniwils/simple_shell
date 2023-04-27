#include "main.h"

/**
 * _strtok_handler - splits a string by delimiter
 * @str: input string
 * @delim: delimiter
 * Return: tokenized string
 */

char *_strtok_handler(char *str, const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, b;

	if (str != NULL)
	{
		if (_cmp_chars_handler(str, delim))
			return (NULL);
		splitted = str; /*Store first address*/
		i = _strlen_handler(str);
		str_end = &str[i]; /*Store last address*/
	}
	str_start = splitted;
	if (str_start == str_end) /*Reaching the end*/
		return (NULL);

	for (b = 0; *splitted; splitted++)
	{
		/*Breaking loop finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (b == 0 && *splitted) /*Str != Delim*/
			b = 1;
	}
	if (b == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

