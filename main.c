nn#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main- a simple shell function.
 * @argc: argument count.
 * @argv: argument array.
 *
 * Return: 0 if successful.
*/
int main(int argc, char **argv)
{
	char buffer[32];
	char *b = buffer;
	size_t characters, bufsize = 32;
	pid_t child_pid;
	char *args[10] = {NULL};

	args[0] = buffer;
	while (1)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			return (argc);
		}
		if (child_pid == 0)
		{
			printf("#cisfun$ ");
			characters = getline(&b, &bufsize, stdin);
			buffer[characters - 1] = '\0';
			if (execve(args[0], args, NULL) == -1)
			{
				printf("%s: No such file or directory\n", argv[0]);
			}

		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
