#include "main.h"
/**
 * main- a simple shell function.
 * @argc: argument count.
 * @argv: argument array.
 * @envp: environmental variables array.
 * Return: 0 if successful.
*/
int main(__attribute__((unused)) int argc, char **argv)
{
	char *line, **tokens;

	while (1)
	{
		printf("#cisfun$ ");
		line = read_line();
		tokens = split_line(line);

		if (tokens[0] != NULL)
		{
			exec(tokens, argv[0]);
		}
		free(tokens);
		free(line);
	}
	return (0);
}
