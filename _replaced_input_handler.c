#include "main.h"

/**
 * _replaced_input_handler - replaces string into variables
 *
 * @head: head of the linked list
 * @input: input string
 * @rep_i: input string replace
 * @len: length
 * Return: replaced string
 */

char *_replaced_input_handler(var_t **head, char *input, char *rep_i, int len)
{
	var_t *index;
	int i, j, k;

	index = *head;
	for (j = i = 0; i < len; i++)
	{
		if (input[j] == '$')
		{
			if (!(index->len_var) && !(index->len_val))
			{
				rep_i[i] = input[j];
				j++;
			}
			else if (index->len_var && !(index->len_val))
			{
				for (k = 0; k < index->len_var; k++)
				{
					j++;
				}
				i--;
			}
			else
			{
				for (k = 0; k < index->len_val; k++)
				{
					rep_i[i] = index->val[k];
					i++;
				}
				j += (index->len_var);
				i--;
			}
			index = index->next;
		}
		else
		{
			rep_i[i] = input[j];
			j++;
		}
	}
	return (rep_i);
}

