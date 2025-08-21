#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

/* Function prototypes */
void execute_command(char *command, char *shell_name, char **env);
int is_empty_line(char *line);
char *trim_whitespace(char *str);
char *find_in_path(const char *cmd, char **env);

#endif /* SHELL_H */
