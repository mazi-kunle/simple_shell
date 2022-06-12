#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
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
	char *b, *token;
	char path[32];
	struct stat st;

	b = buffer;
	size_t characters, bufsize = 32;
	pid_t child_pid;
	char *args[10] = {NULL};

	while (1)
	{
		printf("#cisfun$ ");
		characters = getline(&b, &bufsize, stdin);
		buffer[characters - 1] = '\0';
		token = strtok(buffer, " ");
		if (*token == '/')
		{
			strcpy(path, token);
		}
		else
		{
			strcpy(path, "/usr/bin/");
			strcat(path, token);
		}
		if (stat(path, &st) != 0)
		{
			printf("%s: No such file or directory\n", argv[0]);
			continue;
		}
		args[0] = path;
		args[1] = strtok(NULL, " ");
		args[2] = strtok(NULL, " ");
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			return (argc);
		}
		if (child_pid == 0)
		{

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
