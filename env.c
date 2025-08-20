#include "shell.h"

/**
 * handle_env - Dispalys environment variables
 * @argv: Argument's array (free here)
 * @envp: Environment variables
 */
void handle_env(char **argv, char **envp)
{
	int i = 0;

	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
	free_argv(argv);
}
