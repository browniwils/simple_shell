#include "main.h"

/**
 * _cd_shell_handler - changes current directory
 * @data: data
 * Return: 1
 */

int _cd_shell_handler(data_t *data)
{
	char *directory;
	int i_shome, i_shome_2, is_dash;

	directory = data->args[1];
	if (directory != NULL)
	{
		i_shome = _strcmp_handler("$HOME", directory);
		i_shome_2 = _strcmp_handler("~", directory);
		is_dash = _strcmp_handler("--", directory);
	}

	if (directory == NULL || !i_shome || !i_shome_2 || !is_dash)
	{
		_cd_to_home_handler(data);
		return (1);
	}

	if (_strcmp_handler("-", directory) == 0)
	{
		_cd_previous_handler(data);
		return (1);
	}

	if (_strcmp_handler(".", directory) == 0)
	{
		_cd_dot_handler(data);
		return (1);
	}
	if (_strcmp_handler("..", directory) == 0)
	{
		_cd_dot_handler(data);
	}
	_cd_to_home_handler(data);
	return (1);
}
