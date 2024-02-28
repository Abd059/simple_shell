#include "main.h"
/**
 * _strlen - return the length of a string
 * By Abdo&Mariam
 * @s: char to check
 * Description: _strlen will return the length of a string
 * Return: 0 is success
 */
int _strlen(char *s)
{
	int a = 0;

	for (; *s++;)
		a++;
	return (a);
}

/**
 * _strcat - concat 2 string
 * @dest:char
 * @src:char
 * Return:char
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}

/**
 * _strcmp - compare 2 string
 * @s1:string
 * @s2:strmp
 * Return:int
 * A&M
 */
int _strcmp(char *s1, char *s2)
{
	while (((*s1 != '\0') && (*s2 != '\0')) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
	{
		return (0);
	}

	else
	{
		return (*s1 - *s2);
	}
}
