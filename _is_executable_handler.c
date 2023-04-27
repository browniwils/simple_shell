#include "main.h"

/**
 * _is_executable_handler - determines cmd is an executable
 * @data: data
 * Return: 0 if not an executable otherwise any number
 */

int _is_executable_handler(data_t *data)
{
	struct stat st;
	int i;
	char *input;

	input = data->args[0];
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(input + i, &st) == 0)
	{
		return (i);
	}
	_get_error_handler(data, 127);
	return (-1);
}

