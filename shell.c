#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

size_t my_strcspn(const char *s, const char *reject)
{
    size_t i = 0, j;
    while (s[i] != '\0')
    {
        for (j = 0; reject[j] != '\0'; j++)
        {
            if (s[i] == reject[j])
                return i;
        }
        i++;
    }
    return i;
}

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    pid_t pid;

    while (1)
    {

        if (isatty(STDIN_FILENO))
        {
            printf("$ ");
            fflush(stdout);
        }


        nread = getline(&line, &len, stdin);
        if (nread == -1)
            break;


        line[my_strcspn(line, "\n")] = '\0';


           
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            free(line);
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            char *argv[2];
            argv[0] = line;
            argv[1] = NULL;

            execve(line, argv, environ);

            perror("./shell");
            exit(127);
        }
        else
        {
            wait(NULL);
        }
    }

    free(line);
    return 0;
}

