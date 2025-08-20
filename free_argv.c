#include "shell.h"

/**
 * free_argv - Frees a NULL-terminated array of strings.
 * @argv: Array of strings to free.
 *
 * Return: Nothing.
 */
void free_argv(char **argv)
{
	int i = 0;

	if (!argv)
		return;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}
