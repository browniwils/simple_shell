#include "main.h"

/**
 * _unsetenv_handler - deletes environment variable
 * @data: data
 * Return: 1 on success.
 */

int _unsetenv_handler(data_t *data)
{
	int i, j, k;
	char **realloc_env, *var_env, *name_env;

	if (data->args[1] == NULL)
	{
		_get_error_handler(data, -1);
		return (1);
	}
	k = -1;
	for (i = 0; data->_environ[i]; i++)
	{
		var_env = _strdup_handler(data->_environ[i]);
		name_env = _strtok_handler(var_env, "=");
		if (_strcmp_handler(name_env, data->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		_get_error_handler(data, -1);
		return (1);
	}
	realloc_env = malloc(sizeof(char *) * (i));
	for (i = j = 0; data->_environ[i]; i++)
	{
		if (i != k)
		{
			realloc_env[j] = data->_environ[i];
			j++;
		}
	}
	realloc_env[j] = NULL;
	free(data->_environ[k]);
	free(data->_environ);
	data->_environ = realloc_env;
	return (1);
}
