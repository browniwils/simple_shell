#include "main.h"

/**
 * _free_data_handler - frees data structure
 * @data: data structure
 */

void _free_data_handler(data_t *data)
{
	unsigned int i;

	for (i = 0; data->_environ[i]; i++)
	{
		free(data->_environ[i]);
	}

	free(data->_environ);
	free(data->pid);
}

