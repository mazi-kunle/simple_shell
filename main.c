#include "main.h"
/**
 * main- a simple shell function.
 * @argc: argument count.
 * @argv: argument array.
 *
 * Return: 0 if successful.
*/
int main(__attribute__((unused)) int argc, char **argv)
{
	char *line, **tokens;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		line = read_line();
		tokens = split_line(line);

		if (tokens[0] != NULL)
		{
			exec(tokens, argv[0]);
		}
		free(line);
		free(tokens);
		line = NULL;
	}
	return (0);
}
