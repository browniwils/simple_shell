#include "main.h"

/**
 * _add_s_node_handler - adds a separator
 * @head: head of list.
 * @s: separator
 * Return: address of the head
 */

list_t *_add_s_node_handler(list_t **head, char s)
{
	list_t *new, *temp;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->separator = s;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

