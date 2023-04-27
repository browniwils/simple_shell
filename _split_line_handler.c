#include "main.h"

/**
 * _split_line_handler - tokens input string
 * @input: input string
 * Return: splitted string
 */

char **_split_line_handler(char *input)
{
	size_t size, i;
	char **tokens, *token;

	size = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (size));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok_handler(input, TOK_DELIM);
	tokens[0] = token;
	for (i = 1; token != NULL; i++)
	{
		if (i == size)
		{
			size += TOK_BUFSIZE;
			tokens = _reallocdp_handler(tokens, i, sizeof(char *) * size);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok_handler(NULL, TOK_DELIM);
		tokens[i] = token;
	}
	return (tokens);
}

