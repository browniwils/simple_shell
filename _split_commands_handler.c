#include "main.h"

/**
 * _split_commands_handler - splits command lines with separators ;, | and &
 * @data: data
 * @input: input string
 * Return: 0 to exit, 1 to continue
 */

int _split_commands_handler(data_t *data, char *input)
{
	list_t *s_head, *list_s;
	linel_t *l_head, *list_l;
	int loop;

	s_head = NULL;
	l_head = NULL;
	_add_nodes_handler(&s_head, &l_head, input);
	list_s = s_head;
	list_l = l_head;
	while (list_l != NULL)
	{
		data->input = list_l->line;
		data->args = _split_line_handler(data->input);
		loop = _exec_line_handler(data);
		free(data->args);
		if (loop == 0)
		{
			break;
		}
		_next_handler(&list_s, &list_l, data);
		if (list_l != NULL)
		{
			list_l = list_l->next;
		}
	}

	_free_s_node_handler(&s_head);
	_free_line_list_handler(&l_head);
	if (loop == 0)
	{
		return (0);
	}
	return (1);
}

