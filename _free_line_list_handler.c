#include "main.h"

/**
 * _free_line_list_handler - frees a list
 * @head: head of list
 */

void _free_line_list_handler(linel_t **head)
{
	linel_t *tmp;
	linel_t *current;

	if (head != NULL)
	{
		current = *head;
		while ((tmp = current) != NULL)
		{
			current = current->next;
			free(tmp);
		}
		*head = NULL;
	}
}
