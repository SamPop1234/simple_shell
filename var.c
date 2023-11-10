#include "shell.h"

/**
 * chain_test - test if current character in buffer is a chain delimeter
 * @info: struct parameter
 * @buf: the char buffer
 * @p: pointer to the current position in buf
 *
 * Return: 1 if chain delimeter, else 0
 */
int chain_test(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * chain_check - checks chain based on last status
 * @info: the struct parameter
 * @buf: the char buffer
 * @p: pointer to the current position in buf
 * @i: starting position in buf
 * @len: length of buffer
 *
 * Return: Void
 */
void chain_check(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * rep_alias - replaces an aliase in the tokenized string
 * @info: the parameter structure
 *
 * Return: 1 if successfully replaced, else 0
 */
int rep_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * rep_vars - replaces variables in the tokenized string
 * @info: the parameter structure
 *
 * Return: 1 if successfully replaced, else 0
 */
int rep_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			rep_string(&(info->argv[i]),
				_strdup(num_conv(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			rep_string(&(info->argv[i]),
				_strdup(num_conv(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			rep_string(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		rep_string(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * rep_string - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int rep_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
