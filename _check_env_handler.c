#include "main.h"

/**
 * _check_env_handler - checks if string is environ variable
 * @head: head of list
 * @src: input
 * @data: data
 */

void _check_env_handler(var_t **head, char *src, data_t *data)
{
	int row, char_var, j, list_val;
	char **environ_var;

	environ_var = data->_environ;
	for (row = 0; environ_var[row]; row++)
	{
		for (j = 1, char_var = 0; environ_var[row][char_var]; char_var++)
		{
			if (environ_var[row][char_var] == '=')
			{
				list_val = _strlen_handler(environ_var[row] + char_var + 1);
				_add_node_end_handler(head, j, environ_var[row] + char_var + 1, list_val);
				return;
			}

			if (src[j] == environ_var[row][char_var])
			{
				j++;
			}
			else
			{
				break;
			}
		}
	}

	for (j = 0; src[j]; j++)
	{
		if (src[j] == ' ' || src[j] == '\t' || src[j] == ';' || src[j] == '\n')
		{
			break;
		}
	}
	_add_node_end_handler(head, j, NULL, 0);
}

