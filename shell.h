#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> /*header for the use of struc stat*/
#include <sys/wait.h>
#include <sys/stat.h> /*header for the use of struc stat*/

extern struct stat buf;
char *_getenv(const char *name);
char **tokenize_line(char *line);
ssize_t read_line(char **line, size_t *len);
void free_argv(char **argv);
void handle_exit(char **argv, char *line);
void execute_command(char *av, char **argv, int line_number, char **envp);
void handle_path(char *argv, char **args, char **envp, int line_number);
void ispathname(char **argv, char **envp, int line_number);
void handle_env(char **argv, char **envp);
void launch_process(char *full_path, char *argv, char **args,
char **envp, int line_number, int free_after);
extern char **environ;

#endif
