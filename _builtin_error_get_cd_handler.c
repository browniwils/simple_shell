#include "main.h"

/**
 * _builtin_error_get_cd_handler - error message for cd command in get_cd
 * @data: data
 * Return: error message
 */

char *_builtin_error_get_cd_handler(data_t *data)
{
	int length, len_id;
	char *error, *var_str, *ms;

	var_str = _itoa_handler(data->counter);
	if (data->args[1][0] == '-')
	{
		ms = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		ms = ": can't cd to ";
		len_id = _strlen_handler(data->args[1]);
	}

	length = _strlen_handler(data->av[0]) + _strlen_handler(data->args[0]);
	length += _strlen_handler(var_str) + _strlen_handler(ms) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(var_str);
		return (NULL);
	}
	error = _strcat_cd_handler(data, ms, error, var_str);
	free(var_str);

	return (error);
}

