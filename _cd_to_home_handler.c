#include "main.h"

/**
 * _cd_to_home_handler - change to home directory
 * @data: data
 */

void _cd_to_home_handler(data_t *data)
{
	char *p_pwd, *d_home, pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _strdup_handler(pwd);

	d_home = _getenv_handler("HOME", data->_environ);

	if (d_home == NULL)
	{
		_set_env_handler("OLDPWD", p_pwd, data);
		free(p_pwd);
		return;
	}

	if (chdir(d_home) == -1)
	{
		_get_error_handler(data, 2);
		free(p_pwd);
		return;
	}

	_set_env_handler("OLDPWD", p_pwd, data);
	_set_env_handler("PWD", d_home, data);
	free(p_pwd);
	data->status = 0;
}
