#include "main.h"

/**
 * _free_node_end_handler - frees a list
 * @head: head of list.
 */

void _free_node_end_handler(var_t **head)
{
	var_t *temp;
	var_t *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
