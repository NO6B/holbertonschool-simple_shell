#include "shell.h"

/**
 * execute_command - Execute a command
 * @command: The command to execute
 * @shell_name: Name of the shell program
 * @env: Environment variables
 */
void execute_command(char *command, char *shell_name, char **env)
{
	pid_t pid;
	int status;
	char *trimmed_command;
	char *args[2];

	/* Trim whitespace from command */
	trimmed_command = trim_whitespace(command);

	/* Skip if command is empty after trimming */
	if (!trimmed_command || *trimmed_command == '\0')
		return;

	/* Prepare arguments for execve */
	args[0] = trimmed_command;
	args[1] = NULL;

	/* Fork a child process */
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		/* Child process */
		if (execve(trimmed_command, args, env) == -1)
		{
			/* execve failed, print error and exit */
			fprintf(stderr, "%s: 1: %s: not found\n", shell_name, trimmed_command);
			_exit(127);
		}
	}
	else
	{
		/* Parent process - wait for child to complete */
		wait(&status);
	}
}
