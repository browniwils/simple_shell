#include "main.h"

/**
 * _signal_handler - handles crtl + c input
 * @sig: signal handler
 */
void _signal_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}
