#include "main.h"

/**
 * _builtin_help_alias_handler - information for the builtin alias.
 */

void _builtin_help_alias_handler(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, _strlen_handler(help));
	help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help, _strlen_handler(help));
}

