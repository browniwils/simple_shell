#include "main.h"

/**
 * _builtin_error_path_126_handler - error message
 * @data: data
 * Return: error string
 */

char *_builtin_error_path_126_handler(data_t *data)
{
	int length;
	char *var_str, *error;

	var_str = _itoa_handler(data->counter);
	length = _strlen_handler(data->av[0]) + _strlen_handler(var_str);
	length += _strlen_handler(data->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(var_str);
		return (NULL);
	}
	_strcpy_handler(error, data->av[0]);
	_strcat_handler(error, ": ");
	_strcat_handler(error, var_str);
	_strcat_handler(error, ": ");
	_strcat_handler(error, data->args[0]);
	_strcat_handler(error, ": Permission denied\n");
	_strcat_handler(error, "\0");
	free(var_str);
	return (error);
}
