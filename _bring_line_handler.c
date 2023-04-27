#include "main.h"

/**
 * _bring_line_handler - assigns get_line
 * @lineptr: input string
 * @buffer: string that is been called to line
 * @n: size of line
 * @j: size of buffer
 */
void _bring_line_handler(char **lineptr, size_t *n, char *buffer, size_t j)
{

	if (*lineptr == NULL)
	{
		if  (j > BUFSIZE)
		{
			*n = j;
		}
		else
		{
			*n = BUFSIZE;
		}
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
		{
			*n = j;
		}
		else
		{
			*n = BUFSIZE;
		}
		*lineptr = buffer;
	}
	else
	{
		_strcpy_handler(*lineptr, buffer);
		free(buffer);
	}
}

