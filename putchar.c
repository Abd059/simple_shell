#include "main.h"

/**
 * _putchar - Write character c to stdout.
 *
 * @character: Character to print.
 * @file_descriptor: File descriptor for writing bytes.
 *
 * Return: 1 on success, -1 on error (sets errno).
*/
int _putchar(char character, int file_descriptor)
{
	return (write(file_descriptor, &character, 1));
}
