
#include "shell.h"



int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *argv;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			exit(0); /* Handle EOF (Ctrl+D) */
		}
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0'; /* Remove newline */

		if (line[0] == '\0')
			continue; /* Ignore empty lines */

		argv = tokenize_line(line);
		execute_command(argv);
		free(argv);
	}
	free(line);
	return (0);
}

