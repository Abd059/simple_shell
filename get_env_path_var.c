#include "main.h"

/**
 * _getenvpathvar - Get PATH from env variables.
 *
 * Return: value of PATH variable.
 */

char *_getenvpathvar()
{
	char *path = NULL;
	char *path_value = NULL;
	env_node_t *current = NULL;

	current = head;

	while (current != NULL)
	{
		path = current->name;
		if (_isenvvarpath(path) == IS_PATH)
		{
			path_value = current->value;
			break;
		}
		current = current->next;
	}
	return (path_value);
}
