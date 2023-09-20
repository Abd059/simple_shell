#include "main.h"


/**
 * _pathbuilder - Append @str to @src for path.
 *
 * @argc: Number of strings to append.
 *
 * Return: pointer to new memory address with combined path.
 */
char *_pathbuilder(int argc, ...)
{
	va_list args;
	char *str = NULL, *newstr = NULL;
	int args_found = 0, index = 0, str_index = 0, length = 0;

	va_start(args, argc);
	while (args_found < argc)
	{
		str = va_arg(args, char *);
		length += _strlen(str);
		args_found++;
	}
	va_end(args);
	args_found = 0;
	newstr = malloc(sizeof(char) * length);
	va_start(args, argc);
	while (args_found < argc)
	{
		str = va_arg(args, char *);
		str_index = 0;
		while (str[str_index] != '\0')
		{
			newstr[index++] = str[str_index++];
		}
		args_found++;
	}
	va_end(args);
	newstr[index] = '\0';
	return (newstr);
}

/**
 * _loadpaths - Get values for PATH.
 *
 * @head: Head node in env variable list.
 *
 * Return: Pointer to PATH values.
 */
char **_loadpaths(env_node_t *head)
{
	char **paths = NULL;
	char *var_name = NULL, *var_value = NULL;
	env_node_t *current = NULL;
	int length = 0;

	current = head;
	while (current != NULL)
	{
		var_name = current->name;
		if (_isenvvarpath(var_name) == IS_PATH)
		{
			length = _strlen(current->value);
			var_value = malloc(sizeof(char) * length);
			_strcpy(var_value, current->value);
			break;
		}
		current = current->next;
	}
	if (var_value != NULL)
	{
		paths = _tokenize(var_value, ":");
	}
		return (paths);
}

/**
 * _isrelpath - Check if @path is a relative path.
 *
 * @path: Path to the file to be exectud.
 *
 * Return: IS_ABS_PATH for absolute, IS_REL_PATH otherwise
 */
int _isrelpath(char *path)
{
	char first_character;

	first_character = *path;
	if (first_character != '/')
	{
		return (IS_REL_PATH);
	}
	return (IS_ABS_PATH);
}

/**
 * _relpath - Check for relative path in @commands.
 *
 * @file_info: Flag indicating relative command.
 * @envpath: Pointer to PATH variables.
 * @commands: Pointer to command.
 * @buffer: User input for forming full path
 * @exit_code: Pointer to shell's exit status
 */
void _relpath(int *file_info, char **envpath, char **commands
		, char *buffer, int *exit_code)
{
	int envpath_index = 0;

	if (*file_info == IS_REL_PATH)
	{
		while (envpath != NULL &&
		envpath[envpath_index] != NULL)
		{
			*exit_code = NULL_FOUND;
			commands[0] = _getfullpath(envpath[envpath_index],
					strtok(buffer, "\t\r\n"));
			if (_checkfile(commands[0]) == VALID_COMMAND)
			{
				*exit_code = EXIT_SUCCESS;
				break;
			}
			*exit_code = CTRL_C_SIGNAL_CODE;
			envpath_index++;
			_freestr(commands[0]);
		}
	}
}

