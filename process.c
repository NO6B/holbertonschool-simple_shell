#include "shell.h"

/**
 * launch_process - Forks and runs a command.
 * @full_path: Full path to the command.
 * @argv: Name of the command (for errors).
 * @args: Command and arguments.
 * @envp: Environment variables.
 * @line_number: Line number for error messages.
 * @free_after: If true, frees full_path after execution.
 *
 * Return: Nothing.
 */
void launch_process(char *full_path, char *argv, char **args,
char **envp, int line_number, int free_after)
{
	pid_t pid = fork();
	int status;

	if (pid == 0)
	{
		execve(full_path, args, envp);
		execute_command(argv, args, line_number, envp);
	}
	else if (pid > 0)
	{
		wait(&status);
		if (free_after)
			free(full_path);
	}
}
