#include "shell.h"

/**
 * main - Entry point for the simple shell
 * @argc: Argument count
 * @argv: Argument vector
 * @env: Environment variables
 *
 * Return: Always 0 on success
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int interactive;

	(void)argc;

	/* Check if shell is running in interactive mode */
	interactive = isatty(STDIN_FILENO);

	while (1)
	{
		/* Display prompt in interactive mode */
		if (interactive)
		{
			printf("#cisfun$ ");
			fflush(stdout);
		}

		/* Read line from input */
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			/* Handle EOF (Ctrl+D) */
			if (interactive)
				printf("\n");
			break;
		}

		/* Remove newline character */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		/* Skip empty lines and lines with only spaces/tabs */
		if (is_empty_line(line))
			continue;

		/* Execute the command */
		execute_command(line, argv[0], env);
	}

	/* Free allocated memory */
	free(line);
	return (0);
}
