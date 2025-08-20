#include "shell.h"

#define MAX_ARGS 64

char **tokenize_line(char *line)
{
	char **argv = malloc(sizeof(char *) * MAX_ARGS);
	char *token;
	int i = 0;

	if (!argv)
		return (NULL);

	token = strtok(line, " ");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;
	return (argv);
}