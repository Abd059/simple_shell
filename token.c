#include "main.h"

/**
 * _tokenize - create token array from @str using @delimiter.
 *
 * @str: Command with arguments.
 * @delimiter: Delimiter character(s).
 *
 * Return: Array of tokens.
 */
char **_tokenize(char *str, char *delimiter)
{
	char **tokens = NULL;
	int token_count = 0, token_found = 0;
	char *token = NULL;
	int strlen = 0;

	strlen = _strlen(str);
	token = malloc(sizeof(char) * strlen);
	_strcpy(token, str);
	token_count = _tokencount(token, delimiter);
	_freestr(token);
	tokens = malloc(sizeof(char *) * (token_count + 1));
	str = strtok(str, delimiter);
	while (str != NULL)
	{
		tokens[token_found++] = str;
		str = strtok(NULL, delimiter);
	}
	tokens[token_found] = str;
	return (tokens);
}

/**
 * _tokencount - Count tokens in given command.
 *
 * @str: Command with arguments.
 * @delimiter: Delimiter character(s).
 *
 * Return: Number of tokens.
*/
int _tokencount(char *str, char *delimiter)
{
	int token_count = 0, length = 0;
	char *token = NULL, *tmp = NULL;

	length = _strlen(str);
	tmp = malloc(sizeof(char) * length);
	_strcpy(tmp, str);
	token = strtok(tmp, delimiter);
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, delimiter);
	}
	_freestr(tmp);
	return (token_count);
}