#include "shell.h"

/**
* main - Entry point for simple_shell
* Return: 0 on success
*/
int main(void)
{
	char *command;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}

		command = read_command();

		if (command == NULL) /* Handle Ctrl+D (EOF) */
		{
			break;
		}

		execute_command(command);
		free(command);
	}

	return (0);
}
