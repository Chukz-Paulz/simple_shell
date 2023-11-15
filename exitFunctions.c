#include "shell.h"

/**
 * _strncpy - This copies a string.
 * @dest: The destination string to be copied to.
 * @src: The source string.
 * @n: The number of characters to be copied.
 *
 * Return: The concatenated string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	for (i = 0; src[i] != '\0' && i < n - 1; i++)
		dest[i] = src[i];

	for (j = i; j < n; j++)
		dest[j] = '\0';

	return (s);
}

/**
 * _strncat - This func concatenates two strings.
 * @dest: The first string.
 * @src: The second string.
 * @n: The number of bytes to be maximally used.
 *
 * Return: The concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	for (i = 0; dest[i] != '\0'; i++)
	;

	for (j = 0; src[j] != '\0' && j < n; i++, j++)
		dest[i] = src[j];

	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * _strchr - This func locates a character in a string.
 * @s: This is the string to be parsed.
 * @c: The character to look for.
 *
 * Return: (s) a pointer to the memory area s.
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
	if (*s == c)
		return (s);
	s++;
	}
	return (NULL);
}
