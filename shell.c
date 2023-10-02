#include "shell.h"

int main(void)
{
    char cmd[MAX_CMD_LEN];
    char *args[MAX_ARGS+1];
    int arg_count;

    while(1)
    {
        prompt();
        
        if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL)
        {
            break;
        }

        arg_count = parse_cmd(cmd, args);
      
        if (arg_count > 0 && strcmp(args[0], "exit") == 0)
        {
            break;
        }
        else
        {
            execute_cmd(args);
        }
    }

    return 0;
}