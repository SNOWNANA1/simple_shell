#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /* If there is an exit argument */
	{
		exitcheck = atoi(info->argv[1]);
		if (exitcheck == 0 && info->argv[1][0] != '0')
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->status = exitcheck;
		return (-2);
	}
	info->status = 0;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _mycd(info_t *info)
{
	char *dir;
	int chdir_ret;

	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		dir = _getenv(info, "OLDPWD=");
		if (!dir)
		{
			_puts("OLDPWD not set\n");
			return (1);
		}
		chdir_ret = chdir(dir);
		_puts(dir), _putchar('\n');
	}
	else
		chdir_ret = chdir(info->argv[1]);

	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(NULL, 0));
	}
	return (0);
}

/**
 * _myhelp - displays help message
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	(void)info;
	_puts("Shell Help\n");
	_puts("This is a simple shell program.\n");
	_puts("Implemented built-in commands:\n");
	_puts("1. exit [status]\t- Exit the shell. If a status is provided, it sets the exit status.\n");
	_puts("2. cd [directory]\t- Change the current directory. If no directory is provided, it goes to the home directory.\n");
	_puts("3. help\t\t\t- Display this help message.\n");
	return (0);
}
