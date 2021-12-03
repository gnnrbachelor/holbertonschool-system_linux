#include "ls.h"

/**
 * ls - implementation of ls
 * @args: double pointer to args
 * Return: 1 or 0
 */


int ls(int argn, char **args)
{
	char *dirname;
	int i;

	if (argn > 1)
	{
		for (i = 1; i <= argn; i++)
		{
			dirname = args[i];
			if (dirname != NULL)
			{
				print_out(dirname, args, argn);
			}
		}
	}
	else
	{
		dirname = ".";
		print_out(dirname, NULL, 0);
	}
	return (1);
}
