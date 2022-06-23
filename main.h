#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

extern char **environ;

void printenv(char **envp);
char *_strtok(char *str, const char *delim);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);
char *path_search(char *cmd);
char *read_line(void);
char **split_line(char *str);
void exec(char **args, char *str);

#endif
