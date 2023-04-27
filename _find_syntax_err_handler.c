#include "main.h"

/**
 * _find_syntax_err_handler - finds syntax errors
 * @input: input string
 * @i: index
 * @last: last char
 * Return: index of error. otherwise 0
 */

int _find_syntax_err_handler(char *input, int i, char last)
{
	int cntr;

	cntr = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (_find_syntax_err_handler(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			cntr = _count_rep_char_handler(input, 0);
			if (cntr == 0 || cntr > 1)
				return (i);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			cntr = _count_rep_char_handler(input, 0);
			if (cntr == 0 || cntr > 1)
				return (i);
		}
	}
	return (_find_syntax_err_handler(input + 1, i + 1, *input));
}
