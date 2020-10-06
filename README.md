# SIMPLE SHELL


![N|Solid](https://www.profesionalreview.com/wp-content/uploads/2017/03/Shell-Script-Linux.png)

# DESCRIPTION

This project consists of taking the commands that the user writes to interpret and execute them, the result may be what the user requires or it may be one of the errors captured by the system.
Finally, it gives the user the possibility to continue writing and executing commands in the shell or to finish.
Possible errors when executing commands are:

- use an illegal command
- can't find a command


# INSTALATION

To install the simple shell developed in the project:  

1- clone the git hub of https://github.com/chrisdav1022/shell.git.

2- compile the file using <gcc file.c -Wall -Werror -Wextra and -pedantic -o file>, where file is the name of the compiled file.

3- Use the shell in non-interactive mode:

```bash
Example: 
$ echo "/bin/ls" | ./hsh
AUTHORS  README.md  builtin_shell.c  holberton.h  hsh  loop_shell.c  man_1_simple_shell  path.c  simple_shell.c  strings_1.c
```
4- Use the shell in interactive mode:
```bash
Example: 
$ ./hsh
($) /bin/ls
AUTHORS  README.md  builtin_shell.c  holberton.h  hsh  loop_shell.c  man_1_simple_shell  path.c  simple_shell.c  strings_1.c
```

# USAGE EXAMPLES

Initially, the user enters the command to execute.
Among the most used commands we have:
- ls: lists
- pwd: print the working directory
- env: prints the envoiroment variables
- rm: delete files and directories
- exit: exits the shell

in the same command line the user can use the different options that belong to each command, for example:
- ls -la where "-la" is the ls option to print a list with specifications and hidden files.

# AUTHORS

Christian bedoya <1642@holbertonschool.com> | 
Daniel Lorenzo <2054@holbertonschool.com>
