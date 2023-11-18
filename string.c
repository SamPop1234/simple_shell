#include "shell.h"

/**
 * _strlen - the length of a string to be returned
 * @s: string len to be checked
 *
 * Return: length of string (integer)
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - create lexicogarphic comparison of two str.
 * @s1: first str
 * @s2: second str
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - check wethe rneedle starts with haystack
 * @haystack: to search string
 * @needle: find substring
 *
 * Return: next char address of haystack or return NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - two strings to be concatenated
 * @dest: the buff dest
 * @src: the buff source
 *
 * Return: destination buff pointer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
