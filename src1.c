#include "shell.h"

/**
 * custom_history - history list presenting each command on a seperate line
 * @info: Structure holding arguments.
 *
 *  Return: Always 0
 */
int custom_history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * alias_asig - assign alias to string
 * @info: parameter struct
 * @str: the alias string
 *
 * Return: 0 on success, 1 on error
 */
int alias_asig(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * alias_st - set alias to string
 * @info: parameter struct
 * @str: string alias
 *
 * Return: 0 on success, 1 on error
 */
int alias_st(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (alias_asig(info, str));

	alias_asig(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * alias_ptr - prints an alias string
 * @node: the alias node
 *
 * Return: 0 on success, 1 on error
 */
int alias_ptr(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * custom_alias - replicate the alias builtin
 * @info: Structure holding possible arguments
 *
 *  Return: Always 0
 */
int custom_alias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			alias_ptr(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			alias_st(info, info->argv[i]);
		else
			alias_ptr(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
