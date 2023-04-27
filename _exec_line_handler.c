#include "main.h"

/**
 * _exec_line_handler - locate builtin and commands
 * @data: data
 * Return: 1 on success.
 */

int _exec_line_handler(data_t *data)
{
	int (*builtin)(data_t *data);

	if (data->args[0] == NULL)
	{
		return (1);
	}

	builtin = _get_builtin_cmd_handler(data->args[0]);
	if (builtin != NULL)
	{
		return (builtin(data));
	}

	return (_cmd_exec_handler(data));
}
