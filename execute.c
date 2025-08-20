#include "shell.h"

void execute_command(char *command)
{
	pid_t pid;
	char *argv[2];

	argv[0] = command;
	argv[1] = NULL;

	pid = fork();
	if (pid == 0)
	{
		if (execve(command, argv, environ) == -1)
		{
			perror("Error");
			exit(1);
		}
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("fork");
	}
}
