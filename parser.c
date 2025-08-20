#include "shell.h"

/**
* read_command - Reads a line from stdin
* Return: malloc’d string containing the command (without \n), or NULL on EOF
*/
char *read_command(void)
{
	char *line = NULL;

	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1) /* EOF (Ctrl+D) or error */
	{
		free(line);
		return (NULL);
	}

	/* Remove newline */
	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return (line);
}
