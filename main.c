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
	char buffer[32];
	char *b, *token;
	char path[32];
	struct stat st;
	size_t characters, bufsize;
	pid_t child_pid;
	char *args[10];

	b = buffer;
	bufsize = 32;
	while (1)
	{
		printf("#cisfun$ ");
		characters = getline(&b, &bufsize, stdin);
		buffer[characters - 1] = '\0';
		token = _strtok(buffer, " ");
		if (strcmp(token, "exit") == 0)
			exit(0);
		if (strcmp(token, "env") == 0)
			printenv(envp);
		if (*token == '/')
			strcpy(path, token);
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
		args[1] = _strtok(NULL, " ");
		args[2] = _strtok(NULL, " ");
		args[3] = NULL;
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			return (argc);
		}
		if (child_pid == 0)
		{

			if (execve(args[0], args, NULL) == -1)
				printf("%s: No such file or directory\n", argv[0]);

		}
		else
			wait(NULL);
	}
	return (0);
}
