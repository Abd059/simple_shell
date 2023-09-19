#include "main.h"

/**
 * _findnode - Locate node by name in env list.
 *
 * @head: Head node in env list.
 * @name: Varible name.
 *
 * Return: NOde whit matching name.
 */

env_node_t *findnode(env_node_t *head, char *name)
{
	env_node_t *current = NULL;

	current = head;
	while (current->next != NULL)
	{
		if (_strcmp(current->name, name) == EQUAL_STRING)
		{
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}
