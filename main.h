#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int nutshell(char *command, char *program, char **env);
void nutty(void);
char *walnut(void);
char **nutcracker(const char *input, int *wordCount);

#endif /* MAIN_H */
