#include "shell.h"

/**
 * **str_w - divide a string into words
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings or NULL if unsuccessful
 */

char **str_w(char *str, char *d)
{
	int i, j, k, m, wc = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!delim_check(str[i], d) && (delim_check(str[i + 1], d) || !str[i + 1]))
			wc++;

	if (wc == 0)
		return (NULL);
	s = malloc((1 + wc) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < wc; j++)
	{
		while (delim_check(str[i], d))
			i++;
		k = 0;
		while (!delim_check(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **str_w2 - split a string into individual words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL if unsuccessful
 */
char **str_w2(char *str, char d)
{
	int i, j, k, m, wc = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			wc++;
	if (wc == 0)
		return (NULL);
	s = malloc((1 + wc) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < wc; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
