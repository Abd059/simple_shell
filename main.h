#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#include <signal.h>

/**
 * struct env_node - Node pointing to environment variable.
 *
 * @name: Variable's name.
 * @value: Variable's value.
 * @next: Next environment variable node.
 *
 * Description: Stores user's environment variables.
*/
typedef struct env_node
{
	char *name;
	char *value;
	struct env_node *next;
} env_node_t;

#define INTERACTIVE_MODE 1
#define NON_INTERACTIVE_MODE 0
#define NULL_FOUND -2
#define INVALID_COMMAND 127
#define VALID_COMMAND 0
#define CTRL_C_SIGNAL_CODE 130
#define IS_ABS_PATH 1
#define IS_REL_PATH 2
#define IS_EXEC 1
#define IS_PATH 1
#define IS_NOT_PATH 0
#define ERROR_OCCURED -1
#define SHLVL_NAME "SHLVL"
#define SHLVL_VAL "1"
#define EQUAL_STRING 0
#define OVERWRITE 1
#define IGNORE 0
#define EXIT (_strcmp(commands[0], "exit") == EQUAL_STRING)

extern char **environ;

char *_strcpy(char *dest, char *src);
int _strlen(char *str);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
const char *_strstr(const char *haystack, const char *needle);
int _checkenv(char *command);
int _checkfile(char *path);
int _checkmode(void);
int _checkpath(char *command_path);
int _prompt(char **buffer, size_t *bytes_read);
int _execute(char **commands, int commands_executed,
	      char *program, char **env);
int _exitshell(char **envpath, char **env_clone, char *buffer);
void handle_sigint(int signum);
char *_getfullpath(char *path, char *command);
char **_getenvs(char **env);
char *_getenvpathvar();
int main(int argc __attribute__((unused)), char *argv[], char *env[]);
int _putchar(char character, int file_descriptor);
char **_tokenize(char *str, char *delimiter);
int _tokencount(char *str, char *delimiter);
void _free(char **commands);
void free_list(env_node_t *head);
void _freestr(char *str);
int _setenv(const char *name, const char *value, int overwrite);
int _isenvvarpath(char *env_variable);
void _isexit(char **commands, char *buffer,
		char **envpath, int signal_received, char **env_clone);
int _isexec(char *path);
char *_pathbuilder(int argc, ...);
char **_loadpaths(env_node_t *head);
int _isrelpath(char *path);
void _relpath(int *file_info, char **envpath,
		char **commands, char *buffer, int *exit_code);
void _printenv(void);
void _printerror(int commands_executed, int param_count, ...);
void print_number(int number);
extern int signal_received;
extern env_node_t *head;

env_node_t *_addnodeend(env_node_t **head, char *name, char *value);
env_node_t *_findnode(env_node_t *head, char *name);


/* 1-MemFun.c */
int _atoi(char *s);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif
