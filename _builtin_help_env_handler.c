#include "main.h"

/**
 * _builtin_help_env_handler - information for the builtin env
 */

void _builtin_help_env_handler(void)
{
	char *help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help, _strlen_handler(help));
	help = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, help, _strlen_handler(help));
}
