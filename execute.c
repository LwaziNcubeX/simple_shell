#include "shell.h"

int execute(void)
{
    char **argv = malloc(2 * sizeof(char *));

    if (argv)
    {
        argv[0] = cmd;
        argv[1] = NULL;

        if (execve(cmd, argv, environ) == -1)
        {
            perror("execve");
            free(argv);
        }
    }
        
    return 0; 
}