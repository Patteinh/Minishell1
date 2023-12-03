# minishell1 ⌨️

Welcome to **minishell1**.

Your step into the world of Unix system programming.

This project serves as an introduction to building a `UNIX command interpreter`, paving the way towards more complex shell programming like the `42sh` project.

## Language and Tools 🛠️

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

- **Language:** C
- **Compilation:** Via Makefile, including `re`, `clean`, and `fclean` rules.
- **Binary Name:** mysh

## Project Overview 🔎

The goal of `minishell1` is to create a simple UNIX command interpreter.

This interpreter should display a prompt (e.g., `$>`), wait for the user to enter a command, and then execute it. The project's focus is on executing basic command lines without pipes, redirections, or other advanced features.

### Authorized Functions
Memory and Directory Operations: `malloc`, `free`, `exit`, `opendir`, `readdir`, `closedir`, `getcwd`, `chdir`

File and Process Management: `fork`, `stat`, `lstat`, `fstat`, `open`, `close`, `getline`, `read`, `write`, `execve`, `access`, `isatty`, `wait`, `waitpid`, `wait3`, `wait4`

Signal and Error Handling: `signal`, `kill`, `getpid`, `strerror`, `perror`, `strsignal`

### Key Features

- Displays a prompt and waits for command input.
- Executes executables found in the PATH environment variable.
- Handles errors and displays appropriate messages.
- Manages PATH and the environment effectively.
- Implements builtins: `cd`, `setenv`, `unsetenv`, `env`, `exit`.
- `env` builtin takes no arguments; `unsetenv` doesn't support the "*" wildcard.
- The reference shell for this project is TCSH.

### Usage Example

```
~> ./mysh
$> pwd
/tmp
$> cd test
$> pwd
/tmp/test

∼> ./mysh
$> ls -l /usr /var
/usr:
total 72
drwxr-xr-x 2 root root 36864 Jan 6 17:24 bin
drwxr-xr-x 2 root root 4096 May 13 2019 games
drwxr-xr-x 36 root root 4096 Dec 14 11:15 include
drwxr-xr-x 54 root root 4096 Dec 14 11:15 lib
drwxr-xr-x 3 root root 4096 Apr 2 2020 libexec
drwxr-xr-x 10 root root 4096 Aug 3 2019 local
drwxr-xr-x 2 root root 4096 Jan 6 17:24 sbin
drwxr-xr-x 108 root root 4096 Jan 6 17:24 share
drwxr-xr-x 5 root root 4096 Apr 2 2020 src
/var:
total 40
drwxr-xr-x 2 root root 4096 May 13 2019 backups
drwxr-xr-x 11 root root 4096 Jan 6 17:24 cache
drwxr-xr-x 29 root root 4096 Jan 6 17:24 lib
drwxrwsr-x 2 root staff 4096 May 13 2019 local
lrwxrwxrwx 1 root root 9 Aug 3 2019 lock -> /run/lock
drwxr-xr-x 6 root root 4096 Apr 2 2020 log
drwxrwsr-x 2 root mail 4096 May 11 2020 mail
drwxr-xr-x 2 root root 4096 Aug 3 2019 opt
lrwxrwxrwx 1 root root 4 Aug 3 2019 run -> /run
drwxr-xr-x 5 root root 4096 Jan 13 2020 spool
drwxrwxrwt 2 root root 4096 Apr 2 2020 tmp
drwxr-xr-x 3 root root 4096 Jan 31 2020 www
```

## Installation and Usage 💾

1. Clone the repository.
2. Compile the program using the provided Makefile.
3. Run the program: `./mysh`.
4. For detailed guidelines, refer to `minishell1.pdf`.


## License ⚖️

This project is released under the MIT License. See `LICENSE` for more details.
