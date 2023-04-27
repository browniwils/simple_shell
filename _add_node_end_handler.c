#include "main.h"

/**
 * _add_node_end_handler - adds a variable at the end of list.
 * @head: head of list.
 * @var: length of the variable
 * @val: value of the variable
 * @lval: length of the value
 * Return: address of the head
 */

var_t *_add_node_end_handler(var_t **head, int var, char *val, int lval)
{
	var_t *new, *temp;

	new = malloc(sizeof(var_t));
	if (new == NULL)
		return (NULL);

	new->len_var = var;
	new->val = val;
	new->len_val = lval;

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

