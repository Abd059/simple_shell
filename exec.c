#include "main.h"

/**
 * _isexec - Check if @path is an executable.
 * @path: Path to the file.
 *
 * Return: IS_EXEC for executable, IS_REL_PATH otherwise.
 */
int _isexec(char *path)
{
	char first_character;

	first_character = path[0];
	if (first_character == '.')
	{
		return (IS_EXEC);
	}
	return (IS_REL_PATH);
}
