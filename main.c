#include "main.h"
/**
 * main- a simple shell function.
 * @argc: argument count.
 * @argv: argument array.
 * @envp: environmental variables array.
 * Return: 0 if successful.
*/
int main(int argc, char **argv, char **envp)
{
	char *line, **tokens;
	char path[16];

	while (1)
	{
		printf("#cisfun$ ");
		line = read_line();
		tokens = split_line(line, path);

		if (tokens[0] != NULL)
		{
			exec(tokens, argv[0]);
		}
		free(tokens);
		free(line);
	}
	return (0);
}
