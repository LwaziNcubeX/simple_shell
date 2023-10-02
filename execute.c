#include "shell.h"
/**
 * execute_cmd - Executes a command
 * @args: Array of arguments with command as the first argument
 *
 * Return: Returns 0 if the function succeeds, -1 if it fails.
 */
int execute_cmd(char **args)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Error forking process");
		return (-1);
	}
	else if (pid == 0)
	{
		char *env_path = getenv("PATH");
		char *path = strtok(env_path, ":");
		char full_path[MAX_CMD_LEN + 1];
		while (path != NULL)
		{
			snprintf(full_path, MAX_CMD_LEN, "%s/%s", path, args[0]);
			if (access(full_path, X_OK) == 0)
			{
				break;
			}
			path = strtok(NULL, ":");
		}

		if (path == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", args[0]);
			_exit(EXIT_FAILURE);
		}
		args[0] = full_path;
		execve(args[0], args, environ);
		perror(args[0]);
		_exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
	return (0);
}
