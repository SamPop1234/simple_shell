#include "shell.h"

/**
 *_cputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _cputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_cputch(str[i]);
		i++;
	}
}

/**
 * _cputch - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _cputch(char c)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(2, buf, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
		buf[k++] = c;
	return (1);
}

/**
 * _cputfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _cputfd(char c, int fd)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(fd, buf, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
		buf[k++] = c;
	return (1);
}

/**
 *_cputsfd - prints an input string
 * @str: the string to be printed
 * @i: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _cputsfd(char *str, int i)
{
	int j = 0;

	if (!str)
		return (0);
	while (*str)
	{
		j += _cputfd(*str++, i);
	}
	return (j);
}
