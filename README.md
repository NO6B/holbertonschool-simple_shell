Simple Shell

A basic UNIX command-line interpreter written in C that mimics the functionality of /bin/sh.

👥 Authors

Abdelrahman

Sunny

📜 Description

Simple Shell is a minimalist command-line interpreter that allows users to execute commands in both interactive and non-interactive modes. It includes essential shell functionalities such as command parsing, PATH resolution, and process management.

✨ Features

Interactive Mode
Displays a prompt (#cisfun$ ) and waits for user input.

Non-Interactive Mode
Executes commands provided via standard input or redirected from a file.

Command Parsing
Splits user input into commands and arguments.

PATH Resolution
Searches for executables using the PATH environment variable.

Process Management
Uses fork() and execve() to create and manage child processes.

Error Handling
Provides meaningful error messages for invalid or unknown commands.

🛠️ Compilation
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

🚀 Usage
Interactive Mode
./hsh
#cisfun$ ls -la
#cisfun$ pwd
#cisfun$ exit

Non-Interactive Mode
echo "ls -la" | ./hsh

📁 File Structure
simple_shell/
├── shell.h             # Header file with includes and function prototypes
├── main.c              # Entry point and main shell loop
├── execute_command.c   # Handles command execution logic
├── utils.c             # Utility functions (e.g., string handling)
├── man_1_hsh           # Manual page for the shell
└── README.md           # Project documentation

🔧 Core Functions
Main Functions

main() - Entry point and shell loop

execute_command() - Handles execution logic

run_command() - Forks and executes a given command

tokenize_args() - Parses input into arguments

Utility Functions

is_empty_line() - Checks for empty or whitespace-only input

trim_whitespace() - Removes leading/trailing whitespace

find_in_path() - Searches for executable in PATH (to be implemented)

⚙️ Implementation Details
Command Resolution

If command contains /, it's treated as an absolute or relative path.

Otherwise, the shell searches in directories listed in the PATH variable.

Commands are executed using execve().

Process Management

A child process is created using fork().

The parent waits for the child to complete.

The child executes the command using execve().

Error Handling

Unknown commands return exit status 127.

fork() errors are reported with perror().

Permissions are verified using access().

💻 Environment

Language: C (ANSI C / C89)

OS: Linux / UNIX-based systems

Compiler: GCC with strict flags (-Wall -Werror -Wextra -pedantic)

🚪 Exit Status Codes
Code	Description
0	Successful execution
127	Command not found
n	Exit code of failed command
⚠️ Known Limitations

No command history

No support for aliases or shell functions

Limited built-in commands

No redirection (>, <, >>)

No piping (|) or command chaining (&&, ||)

🧪 Testing

Test the shell in both modes:

# Interactive
./hsh
#cisfun$ ls
#cisfun$ pwd
#cisfun$ whoami

# With arguments
#cisfun$ ls -la /tmp
#cisfun$ grep "pattern" file.txt

# Invalid command
#cisfun$ nonexistent_command

🤝 Contributing

To contribute:

Follow the existing code style (Betty coding style)

Document all functions clearly

Test thoroughly in all modes

Handle edge cases and input errors

📄 License

This project is developed as part of a learning exercise and intended for educational purposes.
