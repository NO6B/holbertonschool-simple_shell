#include "shell.h"


/**
* trim_whitespace - Removes leading and trailing whitespace from a string
* @str: The input string
* Return: The trimmed string (same pointer, modified in-place)
*/
char *trim_whitespace(char *str)
{
	char *end;

	if (!str)
		return (NULL);

	/* Skip leading spaces/tabs */
	while (*str && isspace((unsigned char)*str))

		str++;

	if (*str == '\0') /* String was all whitespace */
		return (str);

	/* Move to the end */
	end = str + _strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))

		end--;

	/* Null-terminate after the last non-space */
	*(end + 1) = '\0';

	return (str);
}

/**
* read_command - Reads a line from stdin and trims whitespace
* Return: malloc’d string containing the command, or NULL on EOF
*/
char *read_command(void)
{
	char *line = NULL;
	char *trimmed;
	char *result;

	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1) /* EOF (Ctrl+D) or error */
	{
		free(line);
		return (NULL);
	}

	/* Remove newline */
	if (nread > 0 && line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	/* Trim spaces/tabs */
	trimmed = trim_whitespace(line);

	if (*trimmed == '\0') /* Empty after trimming */
	{
		free(line);
		return (NULL);
	}

	/* strdup to return only the trimmed part (optional, keeps clean pointer) */
	result = _strdup(trimmed);

	free(line);
	return (result);
}
