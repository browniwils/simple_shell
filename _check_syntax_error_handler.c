#include "main.h"

/**
 * _check_syntax_error_handler - checks syntax error
 * @data: data
 * @input: input string
 * Return: 1 otherwise 0
 */

int _check_syntax_error_handler(data_t *data, char *input)
{
	int begin = 0, first_char = 0, i = 0;

	first_char = _first_char_handler(input, &begin);
	if (first_char == -1)
	{
		_print_syntax_error_handler(data, input, begin, 0);
		return (1);
	}

	i = _find_syntax_err_handler(input + begin, 0, *(input + begin));
	if (i != 0)
	{
		_print_syntax_error_handler(data, input, begin + i, 1);
		return (1);
	}
	return (0);
}
