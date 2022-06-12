#include <stdio.h>
/**
 * printenv- a function that prints environmental variables.
 * @envp: parameter.
 * Return: void.
*/

void printenv(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}
