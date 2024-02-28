#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *str = "My first strlen!";
	int len;
	char s1[98] = "Hello ";
	char s2[] = "World!\n";
	char *ptr;
	char s3[] = "Hello";
	char s4[] = "World!";

	len = _strlen(str);
	printf("%d\n", len);
	
	printf("%s\n", s1);
	printf("%s", s2);
	ptr = _strcat(s1, s2);
	printf("%s", s1);
	printf("%s", s2);
	printf("%s", ptr);

	printf("%d\n", _strcmp(s3, s4));
	printf("%d\n", _strcmp(s4, s3));
	printf("%d\n", _strcmp(s3, s3));

	return (0);
}
