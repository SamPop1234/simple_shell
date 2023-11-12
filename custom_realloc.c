#include "shell.h"

/**
 **custom_memset - fills memory with a constant byte
 *@m: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *custom_memset(char *m, char b, unsigned int j)
{
	unsigned int i;

	for (i = 0; i < j; i++)
		m[i] = b;
	return (m);
}

/**
 * strfree - frees a string of strings
 * @str: string of strings
 */
void strfree(char **str)
{
	char **c = str;

	if (!str)
		return;
	while (*c)
		free(*str++);
	free(c);
}

/**
 * custom_realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @os: byte size of previous block
 * @ns: byte size of new block
 * Return: pointer to da ol'block nameen.
 */
void *custom_realloc(void *ptr, unsigned int os, unsigned int ns)
{
	char *c;

	if (!ptr)
		return (malloc(ns));
	if (!ns)
		return (free(ptr), NULL);
	if (ns == os)
		return (ptr);

	c = malloc(ns);
	if (!c)
		return (NULL);

	os = os < ns ? os : ns;
	while (os--)
		c[os] = ((char *)ptr)[os];
	free(ptr);
	return (c);
}
