#include "shell.h"

int main(void)
{
    char *cmd = NULL;
    size_t len = 0;
    ssize_t bytesRead;
    char *args[MAX_ARGS+1];
    int arg_count;

    while(1)
    {
        prompt();

        bytesRead = getline(&cmd, &len, stdin);
        
        if(bytesRead == -1 || strcmp(cmd, "\n") == 0)
        {
            break;
        }

        arg_count = parse_cmd(cmd, args);
      
        if (strcmp(args[0], "exit") == 0)
        {
            exit_cmd(args);
        }
        else if (arg_count > 0 && strcmp(args[0], "cd") == 0)
        {
            if (chdir(args[1]) == -1)
            {
                perror("cd");
            }
        }
        else if (arg_count > 0 && strcmp(args[0], "help") == 0)
        {
            printf("This is a simple shell implementation.\n");
            printf("The following built-in commands are available:\n");
            printf("cd [DIRECTORY] - Change the current working directory.\n");
            printf("help - Display this help message.\n");
            printf("exit - Exit the shell.\n");
        }
        else
        {
            execute_cmd(args);
        }
        
        memset(cmd, 0, len);
        len = 0;
    }
    
    free(cmd);
    return 0;
}