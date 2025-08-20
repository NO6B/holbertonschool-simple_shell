#include "shell.h"

/**
 * execute_command - Fork and execute a command with execve
 * @args : array of arguments (command + NULL)
 * @argv: Argument vector
 * @line_number: current line number
 * @envp: environment variables
 * Return: the status code of the child process
 */
void execute_command(char *argv, char **args, int line_number, char **envp)
{
	if (execve(args[0], args, envp) == -1)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", argv, line_number, args[0]);
		exit(127);
	}
}
