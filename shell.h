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
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);
char *path_search(char *cmd);
char *_strncat(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);

#endif
