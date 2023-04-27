#include "main.h"

/**
 * _exit_shell_handler - exits the shell
 * @data: data
 * Return: 0 on success.
 */

int _exit_shell_handler(data_t *data)
{
	unsigned int status;
	int is_digit, len, big_n;

	if (data->args[1] != NULL)
	{
		status = _atoi_handler(data->args[1]);
		is_digit = _isdigit_handler(data->args[1]);
		len = _strlen_handler(data->args[1]);
		big_n = status > (unsigned int)INT_MAX;
		if (!is_digit || len > 10 || big_n)
		{
			_get_error_handler(data, 2);
			data->status = 2;
			return (1);
		}
		data->status = (status % 256);
	}
	return (0);
}
