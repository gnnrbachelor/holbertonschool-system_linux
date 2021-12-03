#include "ls.h"

/**
 * print_out - Prints out folder contents
 * @path: path to file
 * Return: 0 or 1
 *
 */

int print_out(char *path, char **args, int argn)
{
	DIR *dir;
	struct dirent *read;

	(void)args;
	(void)argn;

	dir = opendir(path);

	if (!dir)
	{
		return (0);
	}

	else
	{
		while ((read = readdir(dir)) != NULL)
		{
			if (_strcmp(read->d_name, ".") != 0 && _strcmp(read->d_name, "..") != 0)
				printf("%s	", read->d_name);
		}
	}
	closedir(dir);
	return (1);
}


