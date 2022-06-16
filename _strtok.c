#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * _strtok- a string tokenizer function.
 * @str: string to tokenize.
 * @delim: delimeter.
 *
 * Return: the next token or null if no token found.
*/

char *_strtok(char *str, const char *delim)
{

	static char *input;
	char ptr[100];
	char *a;
	char *temp;
	int i;

	a = ptr;
	if (str != NULL)
	{
		input = str;
	}
	if (input == NULL)
	{
		return (NULL);
	}
	temp = malloc(strlen(input) + 1);

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] != delim[0])
		{
			temp[i] = input[i];
		}
		else
		{
			temp[i] = '\0';
			input = input + i + 1;
			strcpy(ptr, temp);
			free(temp);
			return (a);
		}
	}
	temp[i] = '\0';
	input = NULL;
	strcpy(ptr, temp);
	free(temp);
	return (a);
}

