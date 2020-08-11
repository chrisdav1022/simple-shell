#include <stdio.h>
#include <stdlib.h>

/**
 * main - main to code shell
 */

int main()
{
	char* save_line = NULL;
	size_t tm_line = 0;
	size_t nums_chars = 0;
	int i;

	printf("$ "); 

	nums_chars = getline(&save_line, &tm_line, stdin);

	while (nums_chars != -1)
	{
		for (i = 0; save_line[i] != '\0'; i++)
			printf ("%c", save_line[i]);
		nums_chars = getline(&save_line, &tm_line, stdin);
	}
	free (save_line);
}
