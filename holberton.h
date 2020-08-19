#ifndef _HOLBERTON_
#define _HOLBERTON_
/* header files */
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* variables defined to use */
#define BUFFERSIZE 100
#define LIMIT " \t\r\n\a"
/* functions for simple shell loop */
char *read_line(void);
char **token_line(char *line);
int exe_line(char **args);
int launch_line(char **args);
/* functions for built in */
int built_exit(char **args);

#endif /* HOLBERTON */
