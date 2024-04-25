#ifndef shell
#define shell
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
char **tokenizar(char *str);
extern char **environ;
#endif
