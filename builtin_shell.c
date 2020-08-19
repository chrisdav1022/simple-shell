#include "holberton.h"
/**
 * builtins - lists of builtin commands
 * @args: arguments given
 * @buffer: storage space
 * Return: 0
 */
int builtins(char **args, char *buffer)
{
	int idx = 0;
	bin bin_list[] = {
		{"env", printenv},
		{"exit", exitfunc},
		{NULL, NULL}
	};
	if (args[0] == NULL)
		return (-1);
	while (bin_list[idx].name != NULL)
	{
		if (_strcmp(args[0], bin_list[idx].name) == 0)
			bin_list[idx].func(args, buffer);
		idx++;
	}
	if (bin_list[idx].name == NULL)
		return (-1);
	return (0);
}
/**
 * printenv - function called to print env
 *
 * @args: arguments given
 * @buffer: storage space
 * Return: 0
 */
int printenv(char **args, char *buffer)
{
	int idx;
	int len;
	(void) args;
	(void) buffer;

	idx = 0;
	len = 0;

	while (environ[idx] != NULL)
	{
		len = _strlen(environ[idx]);
		write(STDOUT_FILENO, environ[idx], len);
		write(STDOUT_FILENO, "\n", 1);
		idx++;
	}
	return (0);
}
/**
 * exitfunc - function called to exit shell
 *
 * @args: arguments given
 * @buffer: storage space
 * Return: 0 on success
*/
int exitfunc(char **args, char *buffer)
{
	free(buffer);
	free(args);
	exit(0);
}
