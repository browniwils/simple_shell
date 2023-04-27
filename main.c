#include "main.h"

/**
 * main - entry point
 * @argc: number of argument
 * @argv: list argument
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	data_t data;
	(void) argc;

	signal(SIGINT, _signal_handler);
	_set_data_handler(&data, argv);
	_shell_loop_handler(&data);
	_free_data_handler(&data);
	if (data.status < 0)
	{
		return (255);
	}
	return (data.status);
}
