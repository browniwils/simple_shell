#include "main.h"

/**
 * _set_env_handler - sets environment variable
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @data: data
 */

void _set_env_handler(char *name, char *value, data_t *data)
{
	int i;
	char *env_var, *env_name;

	for (i = 0; data->_environ[i]; i++)
	{
		env_var = _strdup_handler(data->_environ[i]);
		env_name = _strtok_handler(env_var, "=");
		if (_strcmp_handler(env_name, name) == 0)
		{
			free(data->_environ[i]);
			data->_environ[i] = _copy_info_handler(env_name, value);
			free(env_var);
			return;
		}
		free(env_var);
	}

	data->_environ = _reallocdp_handler(data->_environ, i,
		sizeof(char *) * (i + 2));
	data->_environ[i] = _copy_info_handler(name, value);
	data->_environ[i + 1] = NULL;
}
