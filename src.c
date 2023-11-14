#include "shell.h"

/**
 * custom_exit - exit shell
 * @info: The structure that holds arguments.
 *
 * Return: exits if info.argv[0] != "exit"
 */
int custom_exit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = c_erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			error_print(info, "Illegal number: ");
			_cputs(info->argv[1]);
			_cputch('\n');
			return (1);
		}
		info->err_num = c_erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * custom_cd - changes the current directory of the process
 * @info: the structure that holds arguments.
 * Return: Always 0
 */
int custom_cd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		error_print(info, "can't cd to ");
		_cputs(info->argv[1]), _cputch('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * custom_help - help to change the current directory of the process
 * @info: The structure that holds arguments.
 *
 * Return: Always 0
 */
int custom_help(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}

