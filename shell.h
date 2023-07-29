#ifndef  SIMPLE_SHELL_H
#define  SIMPLE_SHELL_H

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
} arg_list;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} separator_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} list_string;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} var_list;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(arg_list *shell_data);
} built_ins;

int _isdigit(const char *s);
void ptr_memcpy(void *newptr, const void *ptr, unsigned int size);
list_string *line_node(list_string **head, char *line);
int count_chars_rep(char *input, int i);
void free_list_string(list_string **head);
var_list *add_var_node(var_list **head, int lvar, char *var, int lval);
char *_strdup(const char *s);
int _strlen(const char *s);
int syntax_error(char *input, int i, char last);
int first_character(char *input, int *i);
void reverse_str(char *s);
separator_list *separator_node(separator_list **head, char sep);
void free_seperator(separator_list **head);
char *_strtok(char str[], const char *delim);
void syntax_error_print(arg_list *shell_data, char *input, int i, int bool);
int syntax_err_checker(arg_list *shell_data, char *input);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int chars_comp(char str[], const char *delim);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_realloc_dup(char **ptr, unsigned int old_size, unsigned int new_size);
void node_add(separator_list **head_s, list_string **head_l, char *input);
void env_checker(var_list **h, char *in, arg_list *data);
char **tokenize(char *input);
int print_env(arg_list *shell_data);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
char *comment_del(char *in);
void free_variable_list(var_list **head);
char *cd_strcat_err(arg_list *, char *, char *, char *);
char *fetch_cd_err(arg_list *shell_data);
int variable_checker(var_list **h, char *in, char *st, arg_list *data);
char *str_to_var_input(var_list **head, char *input, char *new_input, int nlen);
char *replace_variable(char *input, arg_list *shell_data);
void loop_sh(arg_list *shell_data);
char *read_line(int *eof_input);
char *character_swap(char *input, int bool);
void assign_line_var(char **lineptr, size_t *n, char *buffer, size_t j);
void next_command(separator_list **list_s, list_string **list_l, arg_list *shell_data);
int cmd_separator(arg_list *shell_data, char *input);
ssize_t _get_line(char **lineptr, size_t *n, FILE *stream);
int find_builtin(arg_list *shell_data);
int if_current_dir(char *path, int *i);
char *handle_cmd_unfound(arg_list *shell_data);
char *exit_err(arg_list *shell_data);
char *locate_cmd(char *cmd, char **_environ);
void cd_back(arg_list *shell_data);
int (*_fetch_builtin(char *cmd))(arg_list *shell_data);
int sh_exit(arg_list *shell_data);
int find_len(int n);
int _atoi(char *s);
char *_getenv(const char *name, char **_environ);
void handle_signal(int sig);
void cd_pathdir(arg_list *shell_data);
char *info_cpy(char *name, char *value);
char *_itoa(int n);
int _unsetenv(arg_list *shell_data);
void cd_parentdir(arg_list *shell_data);
int check_exec_perm(char *dir, arg_list *shell_data);
int execute_cmd(arg_list *shell_data);
int fetch_error(arg_list *shell_data, int eval);
void _sets_env(char *name, char *value, arg_list *shell_data);
int cmp_setenv(arg_list *shell_data);
char *handle_path_err(arg_list *shell_data);
void cd_home(arg_list *shell_data);
int if_exec(arg_list *shell_data);
int sh_cd(arg_list *shell_data);
char *handle_getenv_err(arg_list *shell_data);

#endif
