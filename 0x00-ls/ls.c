#include "ls.h"

/**
 * ls - implementation of ls
 * @args: double pointer to args
 * Return: 1 or 0
 */


int ls(char **args)
{
	char *dirname;
	(void)args;

	if (args[1] != NULL)
	{
		dirname = args[1];
	}
	else
	{
		dirname = ".";
	}

	print_out(dirname);
	return (1);
}
