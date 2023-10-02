#include "shell.h"

int exit_cmd(char **args)
{
    if (args[1] != NULL)
    {
        int status = atoi(args[1]);
        exit(status);
    }
    else 
    {
        exit(EXIT_SUCCESS);
    }
}