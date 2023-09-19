#include "main.h"

/**
 * _isenvvarpath - Check if @env_variable is path.
 *
 * @env_variable: Given env variable.
 *
 * Return: IS_PATH if @env_variable is PATH, IS_NOT_PATH otherwise.
 */
int _isenvvarpath(char *env_variable)
{
	char path[] = "PATH";
	int index = 0;

	while (index < 4)
	{
		if (env_variable[index] != path[index])
		{
			return (IS_NOT_PATH);
		}
		index++;
	}
	return (IS_PATH);
}

