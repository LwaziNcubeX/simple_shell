#include "shell.h"

int parse_cmd(char *cmd, char **args)
{
    int arg_count = 0;
    args[arg_count++] = strtok(cmd, " \n");

    while (arg_count < MAX_ARGS && args[arg_count-1] != NULL)
    {
        args[arg_count++] = strtok(NULL, " \n");
    }
    return arg_count;
}