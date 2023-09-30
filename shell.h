#ifndef SHELL_H
#define SHELL_H

/*INCLUDED HEADERS*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_CMD_LEN 100
extern char **environ;

/*FUNCTION PROTOTYPES*/
void prompt(void);
int parse_cmd(char *cmd, char **args);
int execute_cmd(char **args);


#endif /* SHELL_H */