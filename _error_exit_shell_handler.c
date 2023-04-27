#include "main.h"

/**
 * _error_exit_shell_handler - generic error message for exit in get_exit
 * @data: data
 * Return: error message
 */

char *_error_exit_shell_handler(data_t *data)
{
	int leng;
	char *error, *var_str;

	var_str = _itoa_handler(data->counter);
	leng = _strlen_handler(data->av[0]) + _strlen_handler(var_str);
	leng += _strlen_handler(data->args[0]) + _strlen_handler(data->args[1]) + 23;
	error = malloc(sizeof(char) * (leng + 1));
	if (error == 0)
	{
		free(var_str);
		return (NULL);
	}
	_strcpy_handler(error, data->av[0]);
	_strcat_handler(error, ": ");
	_strcat_handler(error, var_str);
	_strcat_handler(error, ": ");
	_strcat_handler(error, data->args[0]);
	_strcat_handler(error, ": Illegal number: ");
	_strcat_handler(error, data->args[1]);
	_strcat_handler(error, "\n\0");
	free(var_str);

	return (error);
}
