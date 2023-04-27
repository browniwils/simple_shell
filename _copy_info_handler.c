#include "main.h"

/**
 * _copy_info_handler - copies info to create env or alias
 * @name: name
 * @value: value
 * Return: new env or alias.
 */

char *_copy_info_handler(char *name, char *value)
{
	char *new_env;
	int name_len, value_len, length;

	name_len = _strlen_handler(name);
	value_len = _strlen_handler(value);
	length = name_len + value_len + 2;
	new_env = malloc(sizeof(char) * (length));
	_strcpy_handler(new_env, name);
	_strcat_handler(new_env, "=");
	_strcat_handler(new_env, value);
	_strcat_handler(new_env, "\0");

	return (new_env);
}






