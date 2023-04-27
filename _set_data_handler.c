#include "main.h"

/**
 * _set_data_handler - initialize data structure
 * @data: data structure
 * @av: argument vector
 */
void _set_data_handler(data_t *data, char **av)
{
	unsigned int i;

	data->av = av;
	data->input = NULL;
	data->args = NULL;
	data->status = 0;
	data->counter = 1;

	i = 0;
	while (environ[i])
	{
		i++;
	}

	data->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		data->_environ[i] = _strdup_handler(environ[i]);
	}

	data->_environ[i] = NULL;
	data->pid = _itoa_handler(getpid());
}

