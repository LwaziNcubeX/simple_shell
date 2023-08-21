#include "shell.h"
int execute_cmd(char **args)
{
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("Error forking process");
        return -1;
    }
    else if (pid == 0)
    {
        execve(args[0], args, NULL);
        perror("./hsh");
        _exit(EXIT_FAILURE);
    }
    else 
    {
        waitpid(pid, NULL, 0);
    }
    return 0;
}