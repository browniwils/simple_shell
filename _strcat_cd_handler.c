#include "main.h"

/**
 * _strcat_cd_handler - concatenates error message for cd
 * @data: data
 * @ms: message to print
 * @error: output message
 * @var_str: counter lines
 * Return: error message
 */

char *_strcat_cd_handler(data_t *data, char *ms, char *error, char *var_str)
{
	char *ill_flag;

	_strcpy_handler(error, data->av[0]);
	_strcat_handler(error, ": ");
	_strcat_handler(error, var_str);
	_strcat_handler(error, ": ");
	_strcat_handler(error, data->args[0]);
	_strcat_handler(error, ms);
	if (data->args[1][0] == '-')
	{
		ill_flag = malloc(3);
		ill_flag[0] = '-';
		ill_flag[1] = data->args[1][1];
		ill_flag[2] = '\0';
		_strcat_handler(error, ill_flag);
		free(ill_flag);
	}
	else
	{
		_strcat_handler(error, data->args[1]);
	}

	_strcat_handler(error, "\n");
	_strcat_handler(error, "\0");
	return (error);
}

