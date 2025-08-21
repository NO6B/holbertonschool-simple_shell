#include "shell.h"

/*
* find_in_path - Search for a command in the PATH
* @cmd: Command name
* @env: Environment variables
* Return: Full path to command if found (must be freed), else NULL
*/
static char *search_path_dirs(const char *cmd, char *path_copy)
{

	char *dir, *full_path;

	size_t len;

	dir = strtok(path_copy, ":");
	while (dir)
	{
		len = strlen(dir) + strlen(cmd) + 2;
		full_path = malloc(len);
		if (!full_path)
			return (NULL);
		snprintf(full_path, len, "%s/%s", dir, cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}

char *find_in_path(const char *cmd, char **env)
{
	int i;

	char *path_env = NULL, *path_copy, *result;

	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path_env = env[i] + 5;
			break;
		}
	}
	if (!path_env)
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	result = search_path_dirs(cmd, path_copy);
	free(path_copy);
	return (result);
}
