#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_t;

/**
 * struct list_s - list
 * @separator: ; | &
 * @next: next node
 */
typedef struct list_s
{
	char separator;
	struct list_s *next;
} list_t;

/**
 * struct line__s - list
 * @line: command line
 * @next: next node
 */
typedef struct line__s
{
	char *line;
	struct line__s *next;
} linel_t;

/**
 * struct var_l - list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 */
typedef struct var_l
{
	int len_var;
	char *val;
	int len_val;
	struct var_l *next;
} var_t;

/**
 * struct builtin_s - builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_t *data);
} builtin_t;

void _free_s_node_handler(list_t **head);
void _free_line_list_handler(linel_t **head);
var_t *_add_node_end_handler(var_t **head, int var, char *val, int lval);
void _free_node_end_handler(var_t **head);
char *_strcat_handler(char *dest, const char *src);
list_t *_add_s_node_handler(list_t **head, char s);
linel_t *_add_line_node_end_handler(linel_t **head, char *line);
int _strcmp_handler(char *s1, char *s2);
char *_strchr_handler(char *str, char c);
char *_strcpy_handler(char *dest, char *src);
int _strspn_handler(char *src, char *accept);
void *_realloc_handler(void *ptr, unsigned int o_size, unsigned int n_size);
char **_reallocdp_handler(char **ptr, unsigned int o_size, unsigned int n_size);
char *_strdup_handler(const char *str);
void _memcpy_handler(void *newptr, const void *ptr, unsigned int size);
int _strlen_handler(const char *str);
char *_strtok_handler(char *str, const char *delim);
int _isdigit_handler(const char *str);
int _cmp_chars_handler(char *str, const char *delim);
void _rev_string_handler(char *src);
int _count_rep_char_handler(char *input, int i);
int _first_char_handler(char *input, int *i);
void _print_syntax_error_handler(data_t *data, char *input, int i, int b);
int _check_syntax_error_handler(data_t *data, char *input);
int _find_syntax_err_handler(char *input, int i, char last);
void _next_handler(list_t **s_list, linel_t **c_list, data_t *data);
void _shell_loop_handler(data_t *data);
void _add_nodes_handler(list_t **s_node_head, linel_t **l_node_head, char *input);
char *_read_line_handler(int *i);
void _check_env_handler(var_t **head, char *src, data_t *data);
int _split_commands_handler(data_t *data, char *input);
char *_without_comment_handler(char *src);
char *_swap_char_handler(char *input, int b);
int _check_vars_handler(var_t **head, char *src, char *status, data_t *data);
char *_rep_var_handler(char *input, data_t *data);
char *_replaced_input_handler(var_t **head, char *input, char *rep_input, int len);
char **_split_line_handler(char *input);
ssize_t _get_line_handler(char **lineptr, size_t *n, FILE *stream);
int _exec_line_handler(data_t *data);
int _is_cdir_handler(char *path, int *i);
char *_which_handler(char *cmd, char **env_var);
void _bring_line_handler(char **lineptr, size_t *n, char *buffer, size_t j);
int _check_error_cmd_handler(char *directory, data_t *data);
int _cmd_exec_handler(data_t *data);
void _set_env_handler(char *name, char *value, data_t *data);
char *_getenv_handler(const char *name, char **env_var);
int _is_executable_handler(data_t *data);
char *_copy_info_handler(char *name, char *value);
void _cd_dot_handler(data_t *data);
int _setenv_handler(data_t *data);
int _env_handler(data_t *data);
int _cmp_env_name_handler(const char *env_name, const char *name);
void _cd_to_home_handler(data_t *data);
void _cd_to_handler(data_t *data);
int _unsetenv_handler(data_t *data);
void _cd_previous_handler(data_t *data);
int _cd_shell_handler(data_t *data);
int (*_get_builtin_cmd_handler(char *cmd))(data_t *);
int _atoi_handler(char *str);
int _get_len_handler(int n);
char *_itoa_handler(int n);
int _exit_shell_handler(data_t *data);
void _set_data_handler(data_t *data, char **av);
char *_strcat_cd_handler(data_t *data, char *ms, char *error, char *var_str);
char *_builtin_error_env_handler(data_t *data);
void _free_data_handler(data_t *data);
char *_error_exit_shell_handler(data_t *data);
char *error_get_alias(char **args);
char *error_syntax(char **args);
void _builtin_help_alias_handler(void);
char *error_permission(char **args);
char *_builtin_error_path_126_handler(data_t *data);
char *_builtin_error_nf_handler(data_t *data);
char *_builtin_error_get_cd_handler(data_t *data);
void _signal_handler(int sig);
void _builtin_help_env_handler(void);
void _builtin_help_setenv_handler(void);
void _builtin_unsetenv_handler(void);
int _get_error_handler(data_t *data, int err_val);
void _builtin_help_exit_handler(void);
void _builtin_help_handler(void);
void _builtin_help_general_handler(void);
void _builtin_help_cd_handler(void);
int _get_help_handler(data_t *data);

#endif
