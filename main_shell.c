#include "holberton.h"
/**
 * main - function main to shell
 * Return: return value
 *
 */
int main(void)
{
	char *save_line = NULL, *src, **arr;
	size_t tm_line = 0, num_chars = 0;
	int i;
	int status;
	pid_t f;

	arr = malloc(50 * sizeof(char *));

	printf("$ ");

	num_chars = getline(&save_line, &tm_line, stdin);

	while (num_chars != 0)
	{
		src = strtok(save_line, " \n");

		for (i = 0; src != NULL; i++)
		{
			arr[i] = src;
			src = strtok(NULL, " \n");
		}
		arr[i + 1] = NULL;

		f = fork();

		if (f == 0)
		{
			if (execvp(arr[0], arr) == -1)
			{
				printf("No such file or directory\n");
				exit(1);
			}
		}
		if (f != 0)
			waitpid(f, &status, WUNTRACED);
		else
			exit(0);

		printf("$ ");
		
		num_chars = getline(&save_line, &tm_line, stdin);
	}
	free(arr);
	return (0);
}
