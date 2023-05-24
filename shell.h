#ifndef SHELL_H
#define SHELL_H

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

/* This Points to an array of pointers to the strings called  "environment" */
extern char **environ;


/**
 * struct data - The structure that contains all important data on runtime
 * @av: argument vector
 * @input:user written command line
 * @args: tokens of the command line
 * @status: This is the last status of the shell
 * @counter: This rep lines counter
 * @_environ: This rep environment variable
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
} data_shell;

/**
 * struct sep__list_s - single linked list
 * @separator: ; | &
 * @next: This rep the next node
 * Description: single linked list to store separators
 */
typedef struct sep__list_s
{
	char separator;
	struct sep__list_s *next;
} sep__list;

/**
 * struct line__list_s - single linked list
 * @line: command line
 * @next: This rep the next node
 * Description: single linked list to store command lines
 */
typedef struct line__list_s
{
	char *line;
	struct line__list_s *next;
} line__list;

/**
 * struct r__var_list - single linked list
 * @len_var: shows the length of the variable
 * @val: shows value of the variable
 * @len_val: shows length of the value
 * @next: This rep next node
 * Description: single linked list to store variables
 */
typedef struct r__var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r__var_list *next;
} r__var;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: The data type of  pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

/* aux__str functions */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/* aux__str1.c */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

/* aux__str2.c */
void rev_string(char *s);

/* shell__loop.c */
char *without_comment(char *in);
void shell__loop(data_shell *datash);

/* read__line.c */
char *read__line(int *i_eof);

/* rep__var.c */
void check_env(r__var **h, char *in, data_shell *data);
int check_vars(r__var **h, char *in, char *st, data_shell *data);
char *replaced_input(r__var **head, char *input, char *new_input, int nlen);
char *rep__var(char *input, data_shell *datash);

/* aux__mem.c */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* checks__syntax_error.c */
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(data_shell *datash, char *input, int i, int bool);
int checks__syntax_error(data_shell *datash, char *input);

/* split_now.c */
char *swap_char(char *input, int bool);
void add_nodes(sep__list **head_s, line__list **head_l, char *input);
void go_next(sep__list **list_s, line__list **list_l, data_shell *datash);
int split_commands(data_shell *datash, char *input);
char **split_line(char *input);

/* get_nwline.c */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_nwline(char **lineptr, size_t *n, FILE *stream);

/* exec__line */
int exec_line(data_shell *datash);

/* cd__shell.c */
int cd__shell(data_shell *datash);

/* get__builtin */
int (*get__builtin(char *cmd))(data_shell *datash);

/* exit__shell.c */
int exit__shell(data_shell *datash);

/* getin__error.c */
int getin__error(data_shell *datash, int eval);

/* getin__sigint.c */
void getin__sigint(int sig);

/* aux_lists0.c */
sep__list *add_sep_node_end(sep__list **head, char sep);
void free_sep_list(sep__list **head);
line__list *add_line_node_end(line__list **head, char *line);
void free_line_list(line__list **head);

/* aux_lists1.c */
r__var *add_rvar_node(r__var **head, int lvar, char *var, int lval);
void free_rvar_list(r__var **head);

/* cmd_exec.c */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(data_shell *datash);
int check_error_cmd(char *dir, data_shell *datash);
int cmd_exec(data_shell *datash);

/* env00.c */
char *_getenv(const char *name, char **_environ);
int _env(data_shell *datash);

/* env01.c */
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);

/* aux__stdlib.c */
int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);

/* aux__error00.c */
char *strcat_cd(data_shell *, char *, char *, char *);
char *error_get_cd(data_shell *datash);
char *error_not_found(data_shell *datash);
char *error_exit_shell(data_shell *datash);

/* aux__error01.c */
char *error_get_alias(char **args);
char *error_env(data_shell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(data_shell *datash);

#endif
