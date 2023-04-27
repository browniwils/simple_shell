#include "main.h"

/**
 * _get_builtin_cmd_handler - builtin cmd that pairs the command in the arg
 * @cmd: command
 * Return: function pointer of the builtin command
 */
int (*_get_builtin_cmd_handler(char *cmd))(data_t *)
{
	builtin_t command[] = {
		{ "exit", _exit_shell_handler },
		{ "env", _env_handler },
		{ "cd", _cd_shell_handler },
		{ "setenv", _setenv_handler },
		{ "help", _get_help_handler },
		{ "unsetenv", _unsetenv_handler },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; command[i].name; i++)
	{
		if (_strcmp_handler(command[i].name, cmd) == 0)
		{
			break;
		}
	}
	return (command[i].f);
}
