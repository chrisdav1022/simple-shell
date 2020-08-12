#include "holberton.h"
/* cambiar a struct para funciones built in */
char *builtin_struct[] = {
"exit",
"NULL"
};
/* temporal - puntero a funciones built in */
int (*builtin_f[]) (char **) = {
&built_exit
};

/**
 * read_line - reads a line from stdin
 * Return: line readed
 **/
char *read_line(void)
{
char *line = NULL;
ssize_t bufsize = 0;

if (getline(&line, &bufsize, stdin) == -1)
  {
  if (feof(stdin))
  {
  exit(EXIT_SUCCESS); /* EOF */
  }
  else
  {
perror("hsh: getline\n");
exit(EXIT_FAILURE);
}
}
return (line);/* retorna linea leida */
}

/**
 * token_line - convert a line into tokens
 * @line: to tokenize
 * Return: tokens
 **/
char **token_line(char *line)
{
int position = 0;
char **tokens = malloc(BUFFERSIZE * sizeof(char *));
char *token;

if (!tokens) /* comprobar asignacion de memoria */
{
fprintf(stderr, "lsh: allocation error\n");
exit(EXIT_FAILURE);
}

token = strtok(line, LIMIT);
while (token != NULL)
{
tokens[position] = token;
position++;
token = strtok(NULL, LIMIT);
}
tokens[position] = NULL;
return (tokens);
}

/**
 * exe_line - search for matches on built in functions
 * @args: tokens to match
 * Return: position of the match
 **/
int exe_line(char **args)
{
int i;

if (args[0] == NULL)
return (1);

for (i = 0; builtin_struct[i] != NULL; i++)
{
if (strcmp(args[0], builtin_struct[i]) == 0) /* busca f en built in struct */
{
return ((*builtin_f[i])(args));
}
}
return (launch_line(args)); /* si no es built in, ejecuta proceso */
}

/**
 * launch_line - execute the commands
 * @args: tokens to execute
 * Return: status updated
 **/
int launch_line(char **args)
{
pid_t pid;
int status;

pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("hsh");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("hsh");
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}
