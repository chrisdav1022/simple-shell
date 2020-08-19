#include "holberton.h"
/**
 * main - hsh shell main function
 *@void: void args
 * Return: 0
 */
int main(void)
{
char *buffer = NULL, *command = NULL;
char **args = NULL;
size_t size = 0;
struct stat st;
int iterator = 1, run = 0;

	while (1) /* infinite loop for the shell */
	{	write(STDOUT_FILENO, "hsh$ ", 5); /* prints the prompt */
		buffer = _getline(buffer, size); /* calls function to read the line */
		if (buffer == NULL)
		continue;
		args = _tokenline(buffer); /* calls function to tokenize the line readed */
		command = args[0]; /* command readed */

		if (builtins(args, buffer) == -1) /* struct reached null / matches */
		{
			if (stat(args[0], &st) == 0)
			run = exe_command(args);
			else if (stat(args[0], &st) == -1)
			{	args[0] = pathfinder(args[0]);
				if (args[0] == NULL)
			{
				print_error(command);
				iterator++;
			}
			else
run = exe_command(args);
}
if (run == -1)
{	print_error(command);
iterator++;
}
free(args); /* free pointers */
args = NULL;
free(buffer);
buffer = NULL;
}
}
return (0);
}

/**
 * print_error - prints error message
 * @command: command with error
 * Return: void
 **/
void print_error(char *command)
{
write(STDOUT_FILENO, "hsh$: command not found: ", 25);
write(STDOUT_FILENO, command, _strlen(command));
write(STDOUT_FILENO, "\n", 1);
}
