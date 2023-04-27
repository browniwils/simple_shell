#include "main.h"

/**
 * _first_char_handler - finds index of the first char
 * @input: input string
 * @i: index
 * Return: 1 otherwise 0
 */

int _first_char_handler(char *input, int *i)
{

	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
		{
			continue;
		}

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
		{
			return (-1);
		}

		break;
	}

	return (0);
}

