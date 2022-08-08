#include "main.h"
/**
 * exec- a function that forks a process and perfomr some
 * opereation on it.
 * @args: an array of strings.
 * @str: name of the executable file calling the function.
 * Return: void.
*/

void exec(char **args, char *str)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
	}
	if (child_pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror(str);
		}
		exit(0);
	}
	else
	{
		wait(&status);
	}
}
