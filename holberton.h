#ifndef SHELL_H_
#define SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#define DELIM "\n \t \r"

/**
 * struct builtins - Struct for built-ins
 *
 * @name: name of the built-in
 * @func: function pointer
 */
typedef struct builtins
{
	char *name;
	int (*func)(char **args, char *buffer);
} bin;

extern char **environ;
char *findpath(void);
char *fix_token(char *args, char *token);
char *pathfinder(char *args);
int exe_command(char **args);
char **_tokenline(char *buffer);
int builtins(char **args, char *buffer);
int printenv(char **args, char *buffer);
int exitfunc(char **args, char *buffer);
void free_func(char **args);
char *_getline(char *buffer, size_t size);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *s);
int _putchar(char c);
void print_error(char *real_arg);

#endif
