#include "shell.h"

size_t _strlen(const char *s)
{
	size_t len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char *_strdup(const char *s)
{
	size_t i;
	size_t len;
	char *copy;

	if (s == NULL)
		return (NULL);

	len = _strlen(s);
	copy = malloc(len + 1);

	if (!copy)
		return (NULL);

	for (i = 0; i <= len; i++)
		copy[i] = s[i];

	return (copy);
}
