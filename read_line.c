#include "shell.h"

/**
 * read_line - Reads a line of input from the user.
 * @line: Pointer to the buffer that will hold the input.
 * @len: Pointer to the size of the buffer.
 *
 * Return: Number of characters read, or -1 on failure.
 */
ssize_t read_line(char **line, size_t *len)
{
	printf("$ ");
	return (getline(line, len, stdin));
}
