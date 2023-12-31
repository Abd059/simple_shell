#include "main.h"

/**
 * _isexit - Check if the command is 'exit'.
 *
 * @commands: Pointers to commands.
 * @buffer: Pointer to input buffer.
 * @envpath: Pointer to PATH values.
 * @signal_received: Exit code.
 * @env_clone: Temporary env variable address.
 */
void _isexit(char **commands, char *buffer, char **envpath
		, int signal_received, char **env_clone)
{
	int index = 0;

	if (commands[0] == NULL)
	{
		return;
	}
	if (EXIT)
	{
		_freestr(buffer);
		_free(commands);
		if (envpath != NULL)
		{
			_freestr(envpath[0]);
		}
		while (env_clone[index] != NULL)
		{
			_freestr(env_clone[index++]);
		}
		_free(env_clone);
		_free(envpath);
		free_list(head);
		exit(signal_received);
	}
}
