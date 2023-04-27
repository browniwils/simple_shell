#include "main.h"

/**
 * _get_help_handler - help messages according builtin
 * @data: data
 * Return: Return 0
*/

int _get_help_handler(data_t *data)
{
	if (data->args[1] == 0)
		_builtin_help_general_handler();
	else if (_strcmp_handler(data->args[1], "setenv") == 0)
		_builtin_help_setenv_handler();
	else if (_strcmp_handler(data->args[1], "env") == 0)
		_builtin_help_env_handler();
	else if (_strcmp_handler(data->args[1], "unsetenv") == 0)
		_builtin_unsetenv_handler();
	else if (_strcmp_handler(data->args[1], "help") == 0)
		_builtin_help_handler();
	else if (_strcmp_handler(data->args[1], "exit") == 0)
		_builtin_help_exit_handler();
	else if (_strcmp_handler(data->args[1], "cd") == 0)
		_builtin_help_cd_handler();
	else if (_strcmp_handler(data->args[1], "alias") == 0)
		_builtin_help_alias_handler();
	else
		write(STDERR_FILENO, data->args[0], _strlen_handler(data->args[0]));
	data->status = 0;
	return (1);
}

