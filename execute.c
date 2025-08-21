#include "shell.h"

/**
* execute_command - Execute a command
* @command: The command to execute
* @shell_name: Name of the shell program
* @env: Environment variables
*/
void tokenize_args(char *command, char *args[], int max_args)
{
	int i = 0;

	char *token = strtok(command, " \t");

	while (token && i < max_args - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " \t");
	}
	args[i] = NULL;
}

void run_command(char **args, char *shell_name, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", shell_name, args[0]);
			_exit(127);
		}
	}
	else
	{
		wait(&status);
	}
}

void execute_command(char *command, char *shell_name, char **env)
{
	char *trimmed_command;

	char *args[64];

	trimmed_command = trim_whitespace(command);

	if (!trimmed_command || *trimmed_command == '\0')
		return;

	tokenize_args(trimmed_command, args, 64);
	run_command(args, shell_name, env);
}
