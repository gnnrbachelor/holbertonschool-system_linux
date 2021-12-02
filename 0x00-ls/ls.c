#include "ls.h"

/**
 * ls - implementation of ls
 * @args: double pointer to args
 * Return: 1 or 0
 */


int ls(char **args)
{
	DIR *dir;
	char *dirname;
	struct dirent *read;

	(void)args;

	if (args[1] != NULL)
	{
		dirname = args[1];
	}
	else
	{
		dirname = ".";
	}

	dir = opendir(dirname);

	if (!dir)
	{
		return (0);
	}

	else
	{
		while ((read = readdir(dir)) != NULL)
		{
			if (_strcmp(read->d_name, ".") != 0 && _strcmp(read->d_name, "..") != 0)
				printf("%s\n", read->d_name);
		}
	}
	closedir(dir);
	return (1);
}
