#include "main.h"

/**
 * _prompt - Display prompt and accept command.
 *
 * @buffer: Memory address for command storage.
 * @bytes_read: Number of bytes written to @buffer.
 *
 * Return: EXIT_SUCCESS if @buffer has value, EOF if end of file.
*/
int _prompt(char **buffer, size_t *bytes_read)
{
	int read = 0;
	int mode = NON_INTERACTIVE_MODE;

	mode = _checkmode();
	if (mode == INTERACTIVE_MODE)
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	read = getline(buffer, bytes_read, stdin);
	if (read == EOF)
	{
		if (mode == INTERACTIVE_MODE)
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		return (EOF);
	}
	return (EXIT_SUCCESS);
}
