#include "main.h"

/**
 * _get_line_handler - reads inptu from stream
 * @lineptr: input
 * @n: size of lineptr
 * @stream: source of read
 * Return: bytes
 */

ssize_t _get_line_handler(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t ret_val;
	char *buffer, t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;
	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
		{
			buffer = _realloc_handler(buffer, input, input + 1);
		}
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	_bring_line_handler(lineptr, n, buffer, input);
	ret_val = input;
	if (i != 0)
		input = 0;
	return (ret_val);
}
