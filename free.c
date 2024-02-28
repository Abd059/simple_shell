#include "main.h"

/**
 * _free - Free memory for executed commands.
 *
 * @commands: Executed commands.
 */
void _free(char **commands)
{
	free(commands);
	commands = NULL;
}

/**
 * _freestr - Free memory of allocated string.
 *
 * @str: String to free.
*/
void _freestr(char *str)
{
	free(str);
	str = NULL;
}

/**
 * free_list - Free linked list.
 *
 * @head: Head node of lost.
 */
void free_list(env_node_t *head)
{
	if (head == NULL)
		return;
	if (head->next == NULL)
	{
		free(head);
		return;
	}
	free_list(head->next);
	free(head);
}
