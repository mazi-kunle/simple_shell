#ifndef SHELL_H
#define SHELL_H

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

char *path_search(char *cmd);
char *_strncat(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);

#endif
