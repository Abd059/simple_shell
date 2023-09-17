#include "shell.h"

/**
 * _csti - converts a string into an integer
 *@s: pointer to a string
 *Return: the integer
 */
int _csti(char *s)
{
	int x, num, symbol = 1;

	x = 0;
	num = 0;
	while (!((s[x] >= '0') && (s[x] <= '9')) && (s[x] != '\0'))
	{
		if (s[x] == '-')
		{
			symbol = symbol * (-1);
		}
		x++;
	}
	while ((s[x] >= '0') && (s[x] <= '9'))
	{
		num = (num * 10) + (symbol * (s[x] - '0'));
		x++;
	}
	return (num);
}
