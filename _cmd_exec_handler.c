#include "main.h"

/**
 * _cmd_exec_handler - executes command
 * @data: data
 * Return: 1 on success.
 */

int _cmd_exec_handler(data_t *data)
{
	pid_t pid, w_pid;
	int state, execu;
	char *dir;
	(void) w_pid;

	execu = _is_executable_handler(data);
	if (execu == -1)
		return (1);
	if (execu == 0)
	{
		dir = _which_handler(data->args[0], data->_environ);
		if (_check_error_cmd_handler(dir, data) == 1)
			return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execu == 0)
		{
			dir = _which_handler(data->args[0], data->_environ);
		}
		else
		{
			dir = data->args[0];
		}
		execve(dir + execu, data->args, data->_environ);
	}
	else if (pid < 0)
	{
		perror(data->av[0]);
		return (1);
	}
	else
	{
		do {
			w_pid = waitpid(pid, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}
	data->status = state / 256;
	return (1);
}
