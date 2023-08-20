#include "shell.h"

int execute(void)
{
    char **argv = malloc(2 * sizeof(char *));
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork: ");
        free(argv);
        exit(EXIT_FAILURE);
    }
    if (child_pid == 0)
    {
        argv[0] = cmd;
        argv[1] = NULL;

        if (execve(cmd, argv, environ) == -1)
        {
            perror("execve");
            free(argv);
            exit(EXIT_FAILURE);
        }
        exit(0);
    }
    else
    {
        wait(&status);
        free(argv);
    }
    return 0; 
}