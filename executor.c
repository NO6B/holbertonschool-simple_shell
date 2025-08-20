#include "shell.h"


extern char **environ;

/**
* execute_command - Forks and executes a command
* @command: the command string (absolute or relative path)
*/
void execute_command(char *command)
{
	pid_t pid;
	int status;

	if (command == NULL || _strlen(command) == 0)
		return;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0) /* Child process */
	{
		char *argv[2];

		argv[0] = command;
		argv[1] = NULL;

		if (execve(command, argv, environ) == -1)
		{
			perror("simple_shell");
			exit(EXIT_FAILURE);
		}
	}
	else /* Parent process */
	{
		waitpid(pid, &status, 0);
	}
}
