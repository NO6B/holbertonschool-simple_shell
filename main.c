#include "shell.h"

/**
 * main - Entry point for the simple shell
 * @argc: Argument count
 * @argv: Argument vector
 * @env: Environment variables
 * Return: Always 0 on success
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int interactive;

	(void)argc;

	interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
		{
			printf("#cisfun$ ");
			fflush(stdout);
		}

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (interactive)
				printf("\n");
			break;
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		if (is_empty_line(line))
			continue;

		execute_command(line, argv[0], env);
	}

	free(line);
	return (0);
}
