#include "main.h"

/**
 * _env_handler - prints the evironment variables
 * @data: data
 * Return: 1
 */

int _env_handler(data_t *data)
{
	int i, j;

	for (i = 0; data->_environ[i]; i++)
	{
		j = 0;
		while (data->_environ[i][j])
		{
			j++;
		}
		write(STDOUT_FILENO, data->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	data->status = 0;

	return (1);
}
