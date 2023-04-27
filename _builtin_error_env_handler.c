#include "main.h"

/**
 * _builtin_error_env_handler - error message for env in get_env
 * @data: data
 * Return: error message
 */

char *_builtin_error_env_handler(data_t *data)
{
	int length;
	char *error, *var_srt, *ms;

	var_srt = _itoa_handler(data->counter);
	ms = ": Unable to add/remove from environment\n";
	length = _strlen_handler(data->av[0]) + _strlen_handler(var_srt);
	length += _strlen_handler(data->args[0]) + _strlen_handler(ms) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(var_srt);
		return (NULL);
	}

	_strcpy_handler(error, data->av[0]);
	_strcat_handler(error, ": ");
	_strcat_handler(error, var_srt);
	_strcat_handler(error, ": ");
	_strcat_handler(error, data->args[0]);
	_strcat_handler(error, ms);
	_strcat_handler(error, "\0");
	free(var_srt);

	return (error);
}

