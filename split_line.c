#include "main.h"
/**
 * split_line- this functions splits a string into an array of
 * substrings.
 * @str: string to be splitted.
 *
 * Return: an array of strings.
*/

char **split_line(char *str)
{
	int length, capacity;
	char **tokens, *token, *delimiters;

	length = 0;
	capacity = 16;
	tokens = malloc(capacity * sizeof(char *));
	delimiters = " \t\r\n";
	token = strtok(str, delimiters);

	while (token != NULL)
	{
		tokens[length] = token;
		length++;

		if (length >= capacity)
		{
			capacity = capacity * 2;
			tokens = realloc(tokens, capacity * sizeof(char *));
		}
		token = strtok(NULL, delimiters);
	}
	tokens[length] = NULL;
	return (tokens);
}
