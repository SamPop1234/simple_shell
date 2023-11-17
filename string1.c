#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination of copied string
 * @src: the source of a copied string
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int z = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[z])
	{
		dest[z] = src[z];
		z++;
	}
	dest[z] = 0;
	return (dest);
}

/**
 * _strdup - make an exact copy of a string
 * @str: the string to be changed
 *
 * Return: pointer to the changed string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts - print a string input
 *@str: the string to print
 *
 * Return: Null
 */
void _puts(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_putchar(str[j]);
		j++;
	}
}

/**
 * _putchar - write char c to stdout
 * @c: char to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
