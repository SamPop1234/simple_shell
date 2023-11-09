#include "shell.h"

/**
 * interact - returns true if shell is interactive mode
 * @info: struct address
 * Return: 1 if interactive mode, 0 if None
 */
int interact(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * delim_check - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int delim_check(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *alpha_check - alphabetic character check
 *@i: character inputs
 *Return: 1 if c is alphabetic, 0 if None
 */

int alpha_check(int i)
{
	if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *c_atoi - function that converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, convert number
 */

int c_atoi(char *s)
{
	int j, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (j = 0;  s[j] != '\0' && flag != 2; j++)
	{
		if (s[j] == '-')
			sign *= -1;

		if (s[j] >= '0' && s[j] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[j] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
