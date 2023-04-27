#include "main.h"

/**
 * _get_error_handler - calls the error according the builtin
 * @data: data
 * @err_val: error value
 * Return: error
 */

int _get_error_handler(data_t *data, int err_val)
{
	char *error;

	switch (err_val)
	{
	case -1:
		error = _builtin_error_env_handler(data);
		break;
	case 126:
		error = _builtin_error_path_126_handler(data);
		break;
	case 127:
		error = _builtin_error_nf_handler(data);
		break;
	case 2:
		if (_strcmp_handler("exit", data->args[0]) == 0)
			error = _error_exit_shell_handler(data);
		else if (_strcmp_handler("cd", data->args[0]) == 0)
			error = _builtin_error_get_cd_handler(data);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen_handler(error));
		free(error);
	}

	data->status = err_val;
	return (err_val);
}
