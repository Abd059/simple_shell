#include "main.h"

/**
 *  _execute -Execute the given command.
 *
 *  @commands_executed: Number of executed commands.
 *  @commands: ginen commands.
 *  @program: Shell's name.
 *  @env: Cloned enviroment variables.
 *
 *  Return: child process exit code or error code.
 */

int _execute(char **commands, int commands_executed, char *program, char **env)
{
	char *pathname = NULL;
	int status = 0;
	pid_t pid;
	int file_info = VALID_COMMAND;

	pathname = commands[0];
	file_info = _checkfile(pathname);
	if (file_info == VALID_COMMAND)
	{
		pid = fork();
		if (pid == -1)
		{
			return (errno);
		}
		if (pid == 0)
		{
			signal_received = EXIT_SUCCESS;
			if (execve(pathname, commands, env) == ERROR_OCCURED)
			{
				signal_received = status;
				exit(EXIT_FAILURE);
			}
		}
		wait(&status);
		if (WIFEXITED(status))
		{
			signal_received = (WEXITSTATUS(status));
			return (WEXITSTATUS(status));
		}
	}
	else if (file_info == INVALID_COMMAND || file_info == IS_REL_PATH)
	{
		_printerror(commands_executed, 5, program, ": ", ": ",
				pathname, ": not found\n");
		signal_received = INVALID_COMMAND;
		return (INVALID_COMMAND);
	}
	return (status);
}
