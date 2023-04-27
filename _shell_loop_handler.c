#include "main.h"

/**
 * _shell_loop_handler - shell looping
 * @data: data
 * Return: no return.
 */

void _shell_loop_handler(data_t *data)
{
	int loop, i;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "#cisfun$ ", 9);
		input = _read_line_handler(&i);
		if (i != -1)
		{
			input = _without_comment_handler(input);
			if (input == NULL)
				continue;

			if (_check_syntax_error_handler(data, input) == 1)
			{
				data->status = 2;
				free(input);
				continue;
			}
			input = _rep_var_handler(input, data);
			loop = _split_commands_handler(data, input);
			data->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}

