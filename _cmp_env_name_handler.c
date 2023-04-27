#include "main.h"

/**
 * _cmp_env_name_handler - compares env variables names
 * @env_name: name of the environment variable
 * @name: name passed
 * Return: 0 if not equal otherwise any other value
 */

int _cmp_env_name_handler(const char *env_name, const char *name)
{
	int i;

	for (i = 0; env_name[i] != '='; i++)
	{
		if (env_name[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

