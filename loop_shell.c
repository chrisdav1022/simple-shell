#include "holberton.h"
/**
 * _getline - function that reads line from stdin
 * @buffer: line that is readed
 * @size: size of the buffer
 * Return: pointer to line
 **/
char *_getline(char *buffer, size_t size)
{
int checker = 0;

checker = getline(&buffer, &size, stdin);

if (checker == EOF) /* checking EOF */
{
free(buffer); /* free pointer memory */
write(STDOUT_FILENO, "\n", 1); /* puts new line and exit */
exit(0);
}
if (checker == 1 || checker == -1 || buffer == NULL)/*checking null & errors*/
{
free(buffer); /* free pointer memory and return */
return (NULL);
}
return (buffer);
}

/**
 * _tokenline - functions that tokeize a line
 * @buffer: buffer from _getline
 * Return: tokens (command + arguments)
 **/
char **_tokenline(char *buffer)
{
char *token = NULL;
char **tokens = NULL;
int iterator = 0;

tokens = malloc(sizeof(char *) * 5); /* memory for command + arguments */
if (tokens == NULL) /* checking error on memry allocation */
return (NULL);

token = strtok(buffer, DELIM); /* DELIM = \n \t \r */
while (token != NULL)
{
tokens[iterator] = token;
token = strtok(NULL, DELIM);
iterator++;
}
tokens[iterator] = NULL;
return (tokens);
}

/**
 * exe_command - function that execute commands
 * @args: command to execute
 * Return: 0 on success | -1 on error
 **/
int exe_command(char **args)
{
pid_t pid_child = 0;
int status = 0;

if (args == NULL) /* checking for command exist */
return (-1);

pid_child = fork(); /* fork process */
if (pid_child < 0) /* checking for error on fork */
{
write(STDOUT_FILENO, "Fork error", 10);
return (-1);
}
else if (pid_child == 0)
{
if (execve(args[0], args, NULL) == -1)
return (-1);
}
else
pid_child = wait(&status);

return (0);
}
