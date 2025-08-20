#include "shell.h"

/**
 * handle_exit - free the memory and exit the progra
 * @argv: Command and argument.
 * @line: Line to free
 *
 * Return: nothing, exit 0.
 */
void handle_exit(char **argv, char *line)
{
	free_argv(argv);
	free(line);
	exit(0);
}
