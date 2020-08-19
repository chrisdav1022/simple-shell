#include "holberton.h"
/**
 * findpath - searches the environment for PATH
 * Return: NULL
 */
char *findpath(void)
{
	char *token = NULL, *copy = NULL;
	char keyword[] = "PATH";
	int i = 0;

	while (environ[i] != NULL)
	{
		copy  = _strdup(environ[i]);
		if (copy == NULL)
			return (NULL);

		token = strtok(copy, "=");
		if (strcmp(token, keyword) == 0)
		{
			free(copy);
			return (environ[i]);
		}
		i++;
		free(copy);
	}
	return (NULL);
}
/**
 * fix_token - Function concatenates 2 strings adding a backslash and null byte
 *
 * @args: arguments given
 * @token: original token
 * Return: copy of @token
 */
char *fix_token(char *args, char *token)
{
	char *new_token = NULL;
	int i = 0, j = 0;
	unsigned int total_strlen = 0;

	if (args == NULL || token == NULL)
		return (NULL);

	total_strlen = (_strlen(args)) + (_strlen(token));
	new_token = malloc((total_strlen + 2) * sizeof(char *));
	if (new_token == NULL)
		return (NULL);

	while (token[i] != '\0')
	{
		new_token[i] = token[i];
		i++;
	}
	new_token[i] = '/';
	while (args[j] != '\0')
	{
		new_token[i + 1] = args[j];
		j++;
		i++;
	}
	new_token[i + 1] = '\0';
	return (new_token);
}
/**
 * pathfinder - finds the directory a command is located
 *
 * @args: arguments given
 * Return: NULL
 */
char *pathfinder(char *args)
{
	char *dir = NULL;
	char *token = NULL, *new_token = NULL, *holder_token = NULL;
	struct stat st;

	if (args == NULL)
		return (NULL);

	dir = findpath();
	if (dir == NULL)
		return (NULL);
	dir = _strdup(dir);
	if (dir == NULL)
		return (NULL);

	token = strtok(dir, "=:");
	while (token != NULL)
	{
		holder_token = token;
		new_token = fix_token(args, holder_token);
		if (new_token == NULL)
		{
			free(dir);
			return (NULL);
		}
		if (stat(new_token, &st) == 0)
		{
			free(dir);
			return (new_token);
		}
		token = strtok(NULL, "=:");
		free(new_token);
	}
	free(dir);
	return (NULL);
}
