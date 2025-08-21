#include "shell.h"

/**
 * is_empty_line - Check if line contains only spaces, tabs or is empty
 * @line: The line to check
 *
 * Return: 1 if line is empty or contains only whitespace, 0 otherwise
 */
int is_empty_line(char *line)
{
	int i = 0;

	if (!line)
		return (1);

	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

/**
 * trim_whitespace - Remove leading and trailing spaces/tabs from string
 * @str: String to trim
 *
 * Return: Pointer to trimmed string
 */
char *trim_whitespace(char *str)
{
	char *end;

	if (str == NULL)
		return (NULL);

	/* Trim leading space and tabs */
	while (*str == ' ' || *str == '\t')
		str++;

	/* All spaces/tabs? */
	if (*str == 0)
		return (str);

	/* Trim trailing space and tabs */
	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t'))
		end--;

	/* Write new null terminator character */
	end[1] = '\0';

	return (str);
}
