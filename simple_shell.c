#include "holberton.h"
/**
 * main - shell main function (calls read, token & exe)
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: 0
 **/
int main(int argc, char **argv)
{
char *line;
char **args;
int status;

do {
printf("$ ");
line = read_line();
args = token_line(line);
status = exe_line(args);

free(line);
free(args);
} while (status);

return (0);
}