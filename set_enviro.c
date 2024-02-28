#include "main.h"

/**
 * _setenv - Add/update an environment variable.
 *
 * @name: Name of environment variable.
 * @value: Value to set.
 * @overwrite: OVERWRITE to set, IGNORE otherwise.
 *
 * Return: EXIT_SUCCESS on success, ERROR_OCCURED on error (sets errno).
*/
int _setenv(const char *name, const char *value, int overwrite)
{
	const char *matcher = NULL;
	env_node_t *node = NULL;

	matcher = _strstr(name, "=");
	if (name == NULL || matcher != NULL)
	{
		errno = EINVAL;
		return (ERROR_OCCURED);
	}
	if (head != NULL)
	{
		node = _findnode(head,  (char *)name);
	}
	if (node == NULL)
	{
		_addnodeend(&head, (char *)name, (char *)value);
	}
	else
	{
		if (overwrite == OVERWRITE)
		{
			node->value = (char *)value;
		}
	}
	return (EXIT_SUCCESS);
}

