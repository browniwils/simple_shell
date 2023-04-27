#include "main.h"

/**
 * _builtin_help_setenv_handler - information for the builtin setenv
 */

void _builtin_help_setenv_handler(void)
{
	char *help = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help, _strlen_handler(help));
	help = "int replace)\n\t";
	write(STDOUT_FILENO, help, _strlen_handler(help));
	help = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, help, _strlen_handler(help));
}
