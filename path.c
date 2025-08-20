#include "shell.h"

/**
 * handle_path - Finds and executes a command from the PATH.
 * @args: Array of command and arguments.
 * @argv: Argument vector
 * @envp: Environment variables.
 * @line_number: Line number for error messages.
 *
 * Return: Nothing.
 */
void handle_path(char *argv, char **args, char **envp, int line_number)
{
	char *path = strdup(_getenv("PATH"));
	char *token;
	int found = 0;
	size_t total_len;
	char *full_path;
	struct stat buf;

	token = strtok(path, ":");
	while (token)
	{
		total_len = strlen(token) + strlen(args[0]) + 2;
		full_path = malloc(sizeof(char) * total_len);

		if (!full_path)
		{
			free(path);
			return;
		}
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, args[0]);

		if (stat(full_path, &buf) == 0)    /* if the path is valid*/
		{
			launch_process(full_path, argv, args, envp, line_number, 1);
			found = 1;
			free(path);
			return;
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	if (!found)
		launch_process(args[0], argv, args, envp, line_number, 0);

	free(path);
}
