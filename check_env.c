#include "main.h"

/**
 * _checkenv - Check for the 'env' command and display env variables.
 *
 * @command: User's input command.
 *
 * Return: EXIT_SUCCESS for 'env', EXIT_FAILURE otherwise.
*/
int _checkenv(char *command)
{
char env[] = "env";
int index = 0;

if (command == NULL)
{
return (EXIT_FAILURE);
}
while (env[index] != '\0')
{
if (command[index] != env[index])
{
return (EXIT_FAILURE);
}
index++;
}

if (command[index] != '\0')
{
return (EXIT_FAILURE);
}
_printenv();
signal_received = EXIT_SUCCESS;
return (EXIT_SUCCESS);
}
