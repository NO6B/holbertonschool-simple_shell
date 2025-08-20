#include "shell.h"

/**
 * main - Entry point of the super simple shell
 * @ac: Argument count
 * @argv: Argument vector
 * @envp: Environment variables
 * Return: 0 on success
 */
int main(int ac, char **argv, char **envp)
{
	char *line = NULL, **args;
	size_t len = 0;
	ssize_t nread;
	int status, line_number = 1;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;
		args = tokenize_line(line);
		if (!args || !args[0])
		{
			free_argv(args);
			line_number++;
			continue;
		}
		if (strcmp(args[0], "exit") == 0 && args[1] == NULL)  /* handling exit */
			handle_exit(args, line);

		if (strcmp(args[0], "env") == 0)   /*handling env*/
		{
			handle_env(args, envp);
			line_number++;
			continue;
		}
		if (strchr(args[0], '/'))       /* if a command is a pathname*/
			ispathname(args, envp, line_number);
		else
			handle_path(argv[0], args, envp, line_number);
		wait(&status);
		free_argv(args);
		line_number++;
	}
	free(line);
	return (0);
}
