#include "holberton.h"
/**
 * main - simple_shell main function
 * @argv: arguments entry
 * @argc: arguments number
 * Return: 0 on success
 **/

int main(int argc, char *argv[])
{
(void)argc;
char *line;
char **args;
int status;

do {
write(STDOUT_FILENO, "$ ", 2); /* imprime prompt */
line = hsh_read(); /* lee la linea de entrada */
args = hsh_split(line); /* Tokeniza la linea */
status = hsh_exe(args); /* determina si es builtin, comando o salida */

free(line); /* libera puntero line */
free(args); /* libera puntero args */
} while (status); /* status es retorno de hsh_exe */
return (0);
}

