#include "main.h"

/**
 * _add_line_node_end_handler - adds a command at the end of list.
 * @head: head of list
 * @line: command line
 * Return: address of the head
 */

linel_t *_add_line_node_end_handler(linel_t **head, char *line)
{
	linel_t *new, *tmp;

	new = malloc(sizeof(linel_t));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	tmp = *head;

	if (tmp == NULL)
	{
		*head = new;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}

	return (*head);
}

