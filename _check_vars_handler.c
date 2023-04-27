#include "main.h"

/**
 * _check_vars_handler - check if the string is $$ or $?
 * @head: head of the linked list
 * @src: input string
 * @status: last status of the Shell
 * @data: data
 * Return: var index
 */

int _check_vars_handler(var_t **head, char *src, char *status, data_t *data)
{
	int i, l_status, l_pid;

	l_status = _strlen_handler(status);
	l_pid = _strlen_handler(data->pid);
	for (i = 0; src[i]; i++)
	{
		if (src[i] == '$')
		{
			if (src[i + 1] == '?')
			{
				_add_node_end_handler(head, 2, status, l_status), i++;
			}
			else if (src[i + 1] == '$')
			{
				_add_node_end_handler(head, 2, data->pid, l_pid), i++;
			}
			else if (src[i + 1] == '\n' || src[i + 1] == '\0')
			{
				_add_node_end_handler(head, 0, NULL, 0);
			}
			else if (src[i + 1] == ' ' || src[i + 1] == '\t')
			{
				_add_node_end_handler(head, 0, NULL, 0);
			}
			else if (src[i + 1] == ';')
			{
				_add_node_end_handler(head, 0, NULL, 0);
			}
			else
			{
				_check_env_handler(head, src + i, data);
			}
		}
	}
	return (i);
}

