#include "main.h"

/**
 * _print_syntax_error_handler - prints syntax error
 * @data: data
 * @input: input string
 * @i: index of the error
 * @b: to control message error
 */

void _print_syntax_error_handler(data_t *data, char *input, int i, int b)
{
	char *m1, *m2, *m3, *error, *counter;
	int len;

	if (input[i] == ';')
	{
		if (b == 0)
			m1 = (input[i + 1] == ';' ? ";;" : ";");
		else
			m1 = (input[i - 1] == ';' ? ";;" : ";");
	}
	if (input[i] == '|')
		m1 = (input[i + 1] == '|' ? "||" : "|");
	if (input[i] == '&')
		m1 = (input[i + 1] == '&' ? "&&" : "&");

	m2 = ": Syntax error: \"";
	m3 = "\" unexpected\n";
	counter = _itoa_handler(data->counter);
	len = _strlen_handler(data->av[0]) + _strlen_handler(counter);
	len += _strlen_handler(m1) + _strlen_handler(m2);
	len += _strlen_handler(m3) + 2;

	error = malloc(sizeof(char) * (len + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy_handler(error, data->av[0]);
	_strcat_handler(error, ": ");
	_strcat_handler(error, counter);
	_strcat_handler(error, m2);
	_strcat_handler(error, m1);
	_strcat_handler(error, m3);
	_strcat_handler(error, "\0");

	write(STDERR_FILENO, error, len);
	free(error);
	free(counter);
}
