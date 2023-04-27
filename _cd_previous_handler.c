#include "main.h"

/**
 * _cd_previous_handler - changes to the previous directory
 * @data: data
 */

void _cd_previous_handler(data_t *data)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *c_pwd, *c_oldpwd;

	getcwd(pwd, sizeof(pwd));
	c_pwd = _strdup_handler(pwd);

	p_oldpwd = _getenv_handler("OLDPWD", data->_environ);

	if (p_oldpwd == NULL)
		c_oldpwd = c_pwd;
	else
		c_oldpwd = _strdup_handler(p_oldpwd);

	_set_env_handler("OLDPWD", c_pwd, data);

	if (chdir(c_oldpwd) == -1)
		_set_env_handler("PWD", c_pwd, data);
	else
		_set_env_handler("PWD", c_oldpwd, data);

	p_pwd = _getenv_handler("PWD", data->_environ);

	write(STDOUT_FILENO, p_pwd, _strlen_handler(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(c_pwd);
	if (p_oldpwd)
		free(c_oldpwd);

	data->status = 0;

	chdir(p_pwd);
}

