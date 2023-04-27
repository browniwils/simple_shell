#include "main.h"

/**
 * _free_s_node_handler - frees a list
 * @head: head of the list
 */

void _free_s_node_handler(list_t **head)
{
	list_t *temp;
	list_t *current;

	if (head != NULL)
	{
		current = *head;
		while ((temp = current) != NULL)
		{
			current = current->next;
			free(temp);
		}
		*head = NULL;
	}
}

