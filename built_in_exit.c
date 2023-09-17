#include "shell.h"

/**
 * exit -to exit the shell
 * @ary: array of words of the entered line
 *
 */
void exit(char **ary)
{
	int x, num;

	if (ary[1])
	{
		num = _atoi(ary[1]);
		if (num <= -1)
			num = 2;
		emptyary(ary);
		exit(num);
	}
	for (x = 0; ary[x]; x++)
		free(ary[x]);
	free(ary);
	exit(0);
}
