#include "main.h"

/**
 * _add_nodes_handler - handles addition of separators and commands in list
 * @sn_head: head of separator list
 * @ln_head: head of command list
 * @input: input string
 */

void _add_nodes_handler(list_t **sn_head, linel_t **ln_head, char *input)
{
	int i;
	char *line_input;

	input = _swap_char_handler(input, 0);
	for (i = 0; input[i]; i++)
	{
		if (input[i] == ';')
		{
			_add_s_node_handler(sn_head, input[i]);
		}

		if (input[i] == '|' || input[i] == '&')
		{
			_add_s_node_handler(sn_head, input[i]);
			i++;
		}
	}

	line_input = _strtok_handler(input, ";|&");
	do {
		line_input = _swap_char_handler(line_input, 1);
		_add_line_node_end_handler(ln_head, line_input);
		line_input = _strtok_handler(NULL, ";|&");
	} while (line_input != NULL);

}

