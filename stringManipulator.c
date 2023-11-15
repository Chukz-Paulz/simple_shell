#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	/*declaration*/
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	/*Return value*/
	return (i);
}

/**
 * _strcmp - Will perform lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	/*Return*/
	return (*s1 - *s2);
}

/**
 * starts_with - This checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle && *needle == *haystack)
	{
		needle++;
		haystack++;
	}
	/*Returns*/
	return (*needle == '\0' ? (char *)haystack : NULL);
}

/**
 * _strcat - This concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	/*Declaration*/
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	/*Return value*/
	return (ret);
}
