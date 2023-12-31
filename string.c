#include "main.h"


/**
 * _strstr - Find first occurrence of substring.
 *
 * @haystack: String to search.
 * @needle: Substring to find.
 *
 * Return: Pointer to located substring's start or NULL.
*/

const char *_strstr(const char *haystack, const char *needle)
{
	int count = 0, j = 0, ii = 0, s = 0;

	if (needle[ii] == '\0')
	{
		return (&haystack[ii]);
	}
	for ( ; needle[s]; s++)
	{
	}
	for ( ; needle[ii]; ii++)
	{
		j = ii;
		for ( ; haystack[j]; j++)
		{
			if (needle[ii] == haystack[j])
			{
				count++;
				j++;
				break;
			}
		}
	}
	if (count == s)
	{
		return (&haystack[j - s]);
	}
	return (NULL);
}

/**
 * _strlen - Return length of string (including NULL terminator).
 *
 * @str: Given string.
 *
 * Return: Size of string.
*/
int _strlen(char *str)
{
	int total_characters = 0;

	while (str[total_characters] != '\0')
	{
		total_characters++;
	}
	return (total_characters + 1);
}

/**
 * _strdup - Create duplicate of given string.
 *
 * @str: String to duplicate.
 *
 * Return: Memory address of newly allocated string.
*/
char *_strdup(char *str)
{
	char *duplicate = NULL;
	int length = 0;

	length = _strlen(str);
	duplicate = malloc(sizeof(char) * length);
	_strcpy(duplicate, str);
	return (duplicate);
}

/**
 * _strcpy - Copy source to destination.
 *
 * @src: Source string.
 * @dest: Destination string.
 *
 * Return: Pointer to destination string.
*/
char *_strcpy(char *dest, char *src)
{
	int index = 0;

	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

/**
 * _strcmp - Compare two strings.
 *
 * @s1: String 1.
 * @s2: String 2.
 *
 * Return: <0 if s1 < s2, >0 if s1 > s2, 0 if s1 == s2.
*/
int _strcmp(char *s1, char *s2)
{
	int q;

	for (q = 0; s1[q] || s2[q]; q++)
	{
		if (s1[q] != s2[q])
		break;
	}
	return (s1[q] - s2[q]);
}
