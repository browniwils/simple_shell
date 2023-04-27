#include "main.h"

/**
 * _builtin_help_cd_handler - information for the builtin cd
 */

void _builtin_help_cd_handler(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, _strlen_handler(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, _strlen_handler(help));
}
