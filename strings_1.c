#include "holberton.h"
/**
 *_strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: k
 */
int _strcmp(char *s1, char *s2)
{
	int i, k;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	if (s1[i] < s2[i] || s1[i] > s2[i])
	{
		k = s1[i] - s2[i];
	}
	else
	{
		k = 0;
	}
	return (k);
}
/**
 * _strlen - returns a length of the string
 * @s: string to be evaluated
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 **_strdup - Function that returns a pointer to a newly allocated space in
 * memory, which contains a copy of the string given as a parameter
 * @str: string to be copied
 * Return: length of the string
 */
char *_strdup(char *str)
{
	char *p;

	if (str == NULL)
		return (NULL);
	p = malloc((_strlen(str) * sizeof(char)) + 1);
	if (p == NULL)
		return (NULL);
	_strcpy(p, str);
	return (p);
}
/**
 * *_strcpy - function that copies the string pointed to by src to dest
 * @src:  string to be copied
 * @dest: returns the copied string
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
