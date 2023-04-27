#include "main.h"

/**
 * _builtin_help_exit_handler - information fot the builint exit
 */

void _builtin_help_exit_handler(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, _strlen_handler(help));
	help = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, help, _strlen_handler(help));
	help = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, help, _strlen_handler(help));
}
