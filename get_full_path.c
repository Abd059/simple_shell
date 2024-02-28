#include "main.h"

/**
 * _getfullpath -Get full PATH to @command
 *
 * @path: A PATH enviroment variable path
 * @command: Command to be executed
 *
 * Return: Full path to @command
 */

char *_getfullpath(char *path, char *command)
{
	return (_pathbuilder(3, path, "/", command));
}