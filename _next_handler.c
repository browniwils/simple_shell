#include "main.h"

/**
 * _next_handler - go to the next command line stored
 * @s_list: separator list
 * @c_list: command line list
 * @data: data structure
 */

void _next_handler(list_t **s_list, linel_t **c_list, data_t *data)
{
	int loop_sep;
	list_t *sl;
	linel_t *ll;

	loop_sep = 1;
	sl = *s_list;
	ll = *c_list;

	while (sl != NULL && loop_sep)
	{
		if (data->status == 0)
		{
			if (sl->separator == '&' || sl->separator == ';')
			{
				loop_sep = 0;
			}
			if (sl->separator == '|')
			{
				ll = ll->next, sl = sl->next;
			}
		}
		else
		{
			if (sl->separator == '|' || sl->separator == ';')
			{
				loop_sep = 0;
			}
			if (sl->separator == '&')
			{
				ll = ll->next, sl = sl->next;
			}
		}
		if (sl != NULL && !loop_sep)
		{
			sl = sl->next;
		}
	}

	*s_list = sl;
	*c_list = ll;
}

