#include "main.h"

/**
 * _getenv_handler - get environment variable
 * @name: name
 * @env_var: environment variable
 * Return: value of the environment variable if found otherwise NULL
 */

char *_getenv_handler(const char *name, char **env_var)
{
	char *env_ptr;
	int i, n;

	env_ptr = NULL;
	n = 0;
	for (i = 0; env_var[i]; i++)
	{
		n = _cmp_env_name_handler(env_var[i], name);
		if (n)
		{
			env_ptr = env_var[i];
			break;
		}
	}
	return (env_ptr + n);
}

