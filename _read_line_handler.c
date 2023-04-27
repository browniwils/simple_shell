#include "main.h"

/**
 * _read_line_handler - reads the input string
 * @i: input
 * Return: input string
 */

char *_read_line_handler(int *i)
{
	char *input = NULL;
	size_t b_size = 0;

	*i = getline(&input, &b_size, stdin);
	return (input);
}
