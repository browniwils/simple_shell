#include "main.h"

/**
 * _cd_to_handler - change directory to another
 * @data: data
 */

void _cd_to_handler(data_t *data)
{
	char pwd[PATH_MAX];
	char *directory, *c_pwd, *c_dir;

	getcwd(pwd, sizeof(pwd));
	directory = data->args[1];
	if (chdir(directory) == -1)
	{
		_get_error_handler(data, 2);
		return;
	}

	c_pwd = _strdup_handler(pwd);
	_set_env_handler("OLDPWD", c_pwd, data);
	c_dir = _strdup_handler(directory);
	_set_env_handler("PWD", c_dir, data);

	free(c_pwd);
	free(c_dir);

	data->status = 0;
	chdir(directory);
}

