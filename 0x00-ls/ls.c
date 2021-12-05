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
	path_node node = {NULL, 0, 0, NULL, EXIT_SUCCESS, 0, 0};

	node.files = _realloc(NULL, 0, sizeof(File));
	node.file_size = 1;


	if (argn > 1)
	{
		for (i = 1; i <= argn; i++)
		{
			dirname = args[i];
			if (dirname != NULL)
			{
				print_out(node, dirname, args, argn);
			}
		}
	}
	else
	{
		dirname = ".";
		print_out(node, dirname, NULL, 0);
	}
	return (1);
}
