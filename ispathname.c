#include "shell.h"

/**
 * ispathname - Runs a command with a full or relative path.
 * @argv: Command and arguments.
 * @envp: Environment variables.
 * @line_number : Current line number
 *
 * Return: Nothing. Exits with 127 if it fails.
 */
void ispathname(char **argv, char **envp, int line_number)
{
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
	execve(argv[0], argv, envp);
	execute_command(argv[0], argv, line_number, envp);
	}
}
