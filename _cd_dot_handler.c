#include "main.h"

/**
 * _cd_dot_handler - changes to the parent directory
 * @data: data
 */

void _cd_dot_handler(data_t *data)
{
	char pwd[PATH_MAX], *directory, *c_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	c_pwd = _strdup_handler(pwd);
	_set_env_handler("OLDPWD", c_pwd, data);
	directory = data->args[1];
	if (_strcmp_handler(".", directory) == 0)
	{
		_set_env_handler("PWD", c_pwd, data);
		free(c_pwd);
		return;
	}
	if (_strcmp_handler("/", c_pwd) == 0)
	{
		free(c_pwd);
		return;
	}
	cp_strtok_pwd = c_pwd;
	_rev_string_handler(cp_strtok_pwd);
	cp_strtok_pwd = _strtok_handler(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _strtok_handler(NULL, "\0");
		if (cp_strtok_pwd != NULL)
			_rev_string_handler(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		_set_env_handler("PWD", cp_strtok_pwd, data);
	}
	else
	{
		chdir("/");
		_set_env_handler("PWD", "/", data);
	}
	data->status = 0;
	free(c_pwd);
}
