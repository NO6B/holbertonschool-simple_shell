#include "shell.h"

void execute_command(char **argv)
{
	pid_t pid;

	if (!argv || !argv[0])
		return;

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
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
