#include "holberton.h"
/**
 * main - main
 * @argc: void
 * @argv: args
 * Return: 0
 **/
int main(int argc, char **argv)
{
	int status = 0, errors = 1, len = 0;
	pid_t child;
	char *buffer = NULL;
	size_t lenb = 0;
	(void)argc;

	while (1)
	{
		if (isatty(0) == 1)
			write(STDOUT_FILENO, "($) ", 4);
		signal(SIGINT, _signal);
		len = getline(&buffer, &lenb, stdin);
		if (((int)len == -1) || (_strcmp(buffer, "exit\n") == 0))
		{
			if ((int)len == -1 && isatty(0) == 1)
				write(1, "\n", 1);
			break;
		}
		if (_strcmp(buffer, "\n") == 0 || val_spaces(buffer) == 0)
			continue;
		child = fork();
		if (child == -1)
			free(buffer), perror("Error:");
		if (child == 0)
		{
			if (execute(buffer) == -1)
			{
				write_error(argv[0], &buffer, errors);
				free(buffer);
				exit(127);
			}
			exit(EXIT_SUCCESS);
		}
		else
			wait(&status), errors++;
	}
	free(buffer);
	return (0);
}

/**
 * write_error - write an error when no founds a file or directory
 * @name: name of executable
 * @buffer: address of command searched to execute and no found
 * @nerrors: Number of the error
 */
void write_error(char *name, char **buffer, size_t nerrors)
{
(void)nerrors;
	write(2, name, _strlen(name));
	write(2, ": ", 2);
	write(2, *buffer, _strlen(*buffer));
	write(2, ": No such file or directory\n", 28);
}

/**
 * val_spaces - validate is buffer contains only spaces
 * @buffer: string to validate
 * Return: 0 is only spaces or 1 is contain something more
 */
int val_spaces(char *buffer)
{
	int i = 0, nspaces = 0;
	int len = _strlen(buffer);

	while (buffer[i] != '\0')
	{
		if (buffer[i] == 32)
			nspaces++;
		i++;
	}
	if (nspaces == (len - 1))
		return (0);
	return (1);
}
