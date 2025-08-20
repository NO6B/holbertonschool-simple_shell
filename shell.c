#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

size_t my_strcspn(const char *s, const char *reject)
{
	size_t j = 0;
	size_t i = 0;

	while (s[i] != '\0')
	{
	for (j = 0 ; reject[j] != '\0'; j++)
	{
	if (s[i] == reject[j])
		return (i);
	}
	i++;
	}
	return (i);
}

int main()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    pid_t pid;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			break;
		}

		line[my_strcspn(line, "\n")] = '\0';


		pid = fork();
		if (pid == 0)
		{
			char *argv[2]; argv[0] = line; NULL;
			execve(line, argv, environ);


			perror("./shell");
			exit(-1);
		}
		else if (pid > 0)
		{
			wait(NULL);
		}

		else
		{
			perror("fork");
		}
	}

	free(line);
	return (0);
}

