#include "shell.h"

int main(void)
{
    char *cmd = NULL;
    size_t len = 0;
    ssize_t bytesRead;

    while(1)
    {
        prompt();
        
        bytesRead = getline(&cmd, &len, stdin);

        if(bytesRead == -1 || strcmp(cmd, "\n") == 0)
        {
            break;
        }

        memset(cmd, 0, len);
        len = 0;

        if (cmd)
        {
            free(cmd);
        }
        
    }
    free(cmd);
    return 0;
}