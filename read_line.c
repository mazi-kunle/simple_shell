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

	line = NULL;
	buflen = 0;
	getline(&line, &buflen, stdin);
	if (feof(stdin))
	{
		fflush(stdout);
		exit(EXIT_SUCCESS);
	}
	return (line);
}
