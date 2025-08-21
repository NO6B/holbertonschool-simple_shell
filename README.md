Simple Shell
A basic UNIX command-line interpreter written in C that mimics the functionality of /bin/sh.

Authors
Abdelrahman
Sunny
Description
This simple shell is a command-line interpreter that allows users to execute commands in both interactive and non-interactive modes. It provides basic shell functionality including command parsing, PATH resolution, and process execution.

Features
Interactive Mode: Displays a prompt (#cisfun$ ) and waits for user input
Non-Interactive Mode: Executes commands from standard input or files
Command Parsing: Tokenizes input commands and arguments
PATH Resolution: Searches for executables in PATH environment variable
Process Management: Uses fork() and execve() for command execution
Error Handling: Provides appropriate error messages for invalid commands
Compilation
bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Usage
Interactive Mode
bash
./hsh
#cisfun$ ls -la
#cisfun$ pwd
#cisfun$ exit
Non-Interactive Mode
bash
echo "ls -la" | ./hsh
File Structure
simple_shell/
├── shell.h           # Header file with function prototypes and includes
├── main.c            # Main program entry point
├── execute_command.c # Command execution functions
├── utils.c           # Utility functions for string manipulation
├── README.md         # This file
└── man_1_hsh         # Manual page
Functions
Main Functions
main() - Entry point and main shell loop
execute_command() - Main command execution handler
run_command() - Fork and execute command
tokenize_args() - Parse command line into arguments
Utility Functions
is_empty_line() - Check if input line is empty or whitespace only
trim_whitespace() - Remove leading and trailing whitespace
find_in_path() - Search for executable in PATH (implementation needed)
Implementation Details
Command Resolution
If command contains /, treat as absolute/relative path
Otherwise, search in PATH environment variable
Execute with execve() system call
Process Management
Uses fork() to create child process
Parent process waits for child completion
Child process executes command with execve()
Error Handling
Commands not found return exit status 127
Fork failures are handled with perror()
Invalid file permissions are checked with access()
Environment
Language: C (C89/C90 standard)
System: Linux/Unix systems
Compiler: GCC with strict compilation flags
Exit Status
0 - Successful execution
127 - Command not found
Other values depend on executed command
Known Limitations
Does not support command history
No support for aliases or shell functions
Limited built-in commands
No support for input/output redirection
No support for pipes or command chaining
Testing
The shell can be tested with various commands:

bash
# Basic commands
./hsh
#cisfun$ ls
#cisfun$ pwd
#cisfun$ whoami

# Commands with arguments
#cisfun$ ls -la /tmp
#cisfun$ grep "pattern" file.txt

# Non-existent commands (should show error)
#cisfun$ nonexistent_command
Contributing
When contributing to this project:

Follow the existing code style (Betty style)
Ensure all functions are properly documented
Test thoroughly in both interactive and non-interactive modes
Handle edge cases and error conditions
License
This project is part of a learning exercise and follows educational use guidelines.

