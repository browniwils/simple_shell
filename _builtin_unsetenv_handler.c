#include "main.h"

/**
 * _builtin_unsetenv_handler - information for the builtin unsetenv
 */

void _builtin_unsetenv_handler(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, _strlen_handler(help));
	help = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, help, _strlen_handler(help));
}
