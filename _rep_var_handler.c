#include "main.h"

/**
 * _rep_var_handler - replace string into vars
 * @input: string
 * @data: data
 * Return: string
 */

char *_rep_var_handler(char *input, data_t *data)
{
	var_t *head, *index;
	char *status, *new_input;
	int o_len, n_len;

	status = _itoa_handler(data->status);
	head = NULL;
	o_len = _check_vars_handler(&head, input, status, data);
	if (head == NULL)
	{
		free(status);
		return (input);
	}

	index = head;
	n_len = 0;
	while (index != NULL)
	{
		n_len += (index->len_val - index->len_var);
		index = index->next;
	}
	n_len += o_len;
	new_input = malloc(sizeof(char) * (n_len + 1));
	new_input[n_len] = '\0';
	new_input = _replaced_input_handler(&head, input, new_input, n_len);
	free(input);
	free(status);
	_free_node_end_handler(&head);

	return (new_input);
}

