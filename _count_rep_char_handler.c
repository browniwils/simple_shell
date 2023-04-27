#include "main.h"

/**
 * _count_rep_char_handler - counts the repetitions of a character
 * @input: input string
 * @i: index
 * Return: repetitions
 */

int _count_rep_char_handler(char *input, int i)
{
	if (*(input - 1) == *input)
	{
		return (_count_rep_char_handler(input - 1, i + 1));
	}

	return (i);
}

