#include "main.h"

/**
 * _check_error_cmd_handler - checks if has access permissions
 * @directory: destination directory
 * @data: data
 * Return: 1 if there is an error otherwise 0
 */

int _check_error_cmd_handler(char *directory, data_t *data)
{
	if (directory == NULL)
	{
		_get_error_handler(data, 127);
		return (1);
	}

	if (_strcmp_handler(data->args[0], directory) != 0)
	{
		if (access(directory, X_OK) == -1)
		{
			_get_error_handler(data, 126);
			free(directory);
			return (1);
		}
		free(directory);
	}
	else
	{
		if (access(data->args[0], X_OK) == -1)
		{
			_get_error_handler(data, 126);
			return (1);
		}
	}

	return (0);
}

