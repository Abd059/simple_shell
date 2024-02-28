#include "main.h"

/**
 * _exitshell - Clean up memory before exiting.
 *
 * @envpath: Pointer to PAth variables
 * @env_clone: Pointer to env variables copy
 * @buffer: User's input command
 *
 * Return: Exit code of last successful command.
 */

int _exitshell(char **envpath, char **env_clone, char *buffer)
{
	int index = 0;

	if (envpath != NULL)
	{
		_freestr(envpath[0]);
	}
	while (env_clone[index] != NULL)
	{
		_freestr(env_clone[index++]);
	}
	_free(env_clone);
	_freestr(buffer);
	_free(envpath);
	free_list(head);
	return (signal_received);
}
