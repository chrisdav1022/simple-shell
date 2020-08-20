#include "holberton.h"
/**
 * _printenv - prints environment like printenv
 *
 * Return: 0
 */
int _printenv(void)
{
	char *s = environ[0];
	int i = 0;

	while (s)
	{
		write(1, s, _strlen(s));
		write(1, "\n", 1);
		s = environ[++i];
	}
	return (0);
}

/**
 * _str_n_cmp - lexicographically compares not more than count chars
 * from two strings and returns an integer based on the result.
 * @s1: first string
 * @s2: second string to compare to first string
 * @n: count of the comparison between s1 and s2
 * Return: <0 if s1 is less than s2, 0 for equal, >0 if s1 is greater than s2
 * Description: Src code file like GNU C library
 */
int _str_n_cmp(char *s1, char *s2, int n)
{
	char c1, c2;

	while (n--)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 == '\0' || c1 != c2)
/* compare at most, first n bytes of both strings */
			return (c1 > c2 ? 1 : (c1 < c2 ? -1 : 0));
	}
				return (0);
}
/**
 * do_arguments - args
 * @input: input
 * Return: pointer
 **/
char **do_arguments(char *input)
{
	int i = 0, j = 0;
	char *path = input;
	char *tmpexe = _strdup(input);
	char **argv = NULL;

	path = strtok(path, " \n\t");
	while (path != NULL)
	{
		i++;
		path = strtok(NULL, " \n\t");
	}
	argv = (char **) malloc((sizeof(char *) * i) + 1);
	if (argv == NULL)
	{
		free(tmpexe);
		return (NULL);
	}
	tmpexe = strtok(tmpexe, " \n\t");
	while (tmpexe != NULL)
	{
		argv[j] = _strdup(tmpexe);
		j++;
		tmpexe = strtok(NULL, " \n\t");
	}
	argv[i + 1] = NULL;
	free(tmpexe);
	return (argv);

}
/**
 * execute_path - execute the command searching in each directory
 * of PATH variable
 * @name: command to execute
 * @options: options to execute with command
 * Return: 0 is success or -1 is error
 */
int execute_path(char *name, char **options)
{
	DIR *dir;
	int st = 0;
	struct dirent *pDirent;
	path_t *head = do_link();
	path_t *tmp = head;
	char *path = NULL;

	while (tmp->next != NULL)
	{
		dir = opendir(tmp->path);
		if (dir == NULL)
		{
			printf("Cannot open directory '%s'\n", head->path);
			return (1);
		}
		while ((pDirent = readdir(dir)) != NULL)
		{
			if ((_strcmp(pDirent->d_name, name)) == 0)
			{
				path = _strdup(tmp->path);
				path = _strcat(path, "/");
				path = _strcat(path, name);
				options[0] = malloc(_strlen(path) + 1);
				_strcpy(options[0], path);
				break;
			}
		}
		closedir(dir);
		if (path != NULL)
			break;
		tmp = tmp->next;
	}
	if ((execve(path, options, NULL)) == -1)
		st = -1;
	free(path);
	free_list(head);
	return (st);
}
