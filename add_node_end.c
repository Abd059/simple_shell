#include "main.h"

/**
 * _addnodeend -Add anew env variable to the list.
 *
 * @head: Head node in the list.
 * @name: Name for the new env variable.
 * @value: Value for the new env variable.
 *
 * Return: Address of the newly added node.
 */
env_node_t *_addnodeend(env_node_t **head, char *name, char *value)
{
	env_node_t *tail, *current;

	tail = malloc(sizeof(env_node_t));
	tail->name = name;
	tail->value = value;
	tail->next = NULL;
	if (*head == NULL)
	{
		*head = tail;
		return (tail);
	}
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = tail;
	return (tail);
}