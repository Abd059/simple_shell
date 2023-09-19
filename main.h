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
int _execute(char **commands, int commands_executed, char *program, char **env);
int _exitshell(char **envpath, char **env_clone, char *buffer);
void handle_sigint(int signum _attribute_((unused)));
char *_getfullpath(char *path, char *command);
char **_getenvs(char **env);

#endif
