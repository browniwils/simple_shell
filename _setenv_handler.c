#include "main.h"

/**
 * _setenv_handler - compares env variables names
 * @data: data
 * Return: 1 on success.
 */

int _setenv_handler(data_t *data)
{

	if (data->args[1] == NULL || data->args[2] == NULL)
	{
		_get_error_handler(data, -1);
		return (1);
	}

	_set_env_handler(data->args[1], data->args[2], data);
	return (1);
}

