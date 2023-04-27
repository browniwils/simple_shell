#include "main.h"

/**
 * _which_handler - locates a command
 *
 * @cmd: command name
 * @env_var: environment variable
 * Return: location of the command.
 */

char *_which_handler(char *cmd, char **env_var)
{
	char *path, *path_ptr, *tok_path, *directory;
	int len_directory, len_cmd, i;
	struct stat st;

	path = _getenv_handler("PATH", env_var);
	if (path)
	{
		path_ptr = _strdup_handler(path);
		len_cmd = _strlen_handler(cmd);
		tok_path = _strtok_handler(path_ptr, ":");
		i = 0;
		while (tok_path != NULL)
		{
			if (_is_cdir_handler(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_directory = _strlen_handler(tok_path);
			directory = malloc(len_directory + len_cmd + 2);
			_strcpy_handler(directory, tok_path);
			_strcat_handler(directory, "/");
			_strcat_handler(directory, cmd);
			_strcat_handler(directory, "\0");
			if (stat(directory, &st) == 0)
			{
				free(path_ptr);
				return (directory);
			}
			free(directory);
			tok_path = _strtok_handler(NULL, ":");
		}
		free(path_ptr);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}
