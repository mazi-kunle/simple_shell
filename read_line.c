#include "main.h"
/**
 * read_line- read lines from the user.
 *
 * Return: a pointer to the string.
*/

char *read_line(void)
{
	char *line;
	size_t buflen;

	buflen = 8;
	line = malloc(buflen * sizeof(char));
	getline(&line, &buflen, stdin);
	if (feof(stdin))
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}
