#include "main.h"

/**
 * _checkpath - Check if @command_path is an absolute/relative path.
 *
 * @command_path: Path/command.
 *
 * Return: VALID_COMMAND for valid path, IS_REL_PATH for command name.
*/
int _checkpath(char *command_path)
{
	return (_checkfile(command_path));
}

/**
 * _checkmode - Determine shell mode.
 *
 * Return: INTERACTIVE_MODE for interactive, NON_INTERACTIVE_MODE otherwise.
*/
int _checkmode(void)
{
	int mode;

	mode = isatty(STDIN_FILENO);
	if (mode == 1)
	{
		return (INTERACTIVE_MODE);
	}
	return (NON_INTERACTIVE_MODE);
}

/**
 * _checkfile - Checks for the exisitence of the specified file at @path
 *
 * @path: The path to the file to be executed
 *
 * Return: VALID_COMMAND if @path is a valid file,
 * NULL_FOUND if @path is NULL otherwise
 * INVALID_COMMAND
*/

int _checkfile(char *path)
{
	if (path == NULL)
	{
		return (NULL_FOUND);
	}
	if (_isexec(path) == IS_EXEC)
	{
		if (access(path, F_OK) == VALID_COMMAND)
		{
			return (VALID_COMMAND);
		}
		return (INVALID_COMMAND);
	}

	if (_isrelpath(path) == IS_REL_PATH)
	{
		return (IS_REL_PATH);
	}
	if (access(path, F_OK) == VALID_COMMAND)
	{
		return (VALID_COMMAND);
	}
	return (INVALID_COMMAND);
}
