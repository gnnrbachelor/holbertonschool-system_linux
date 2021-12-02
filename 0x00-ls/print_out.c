#include "ls.h"

/**
 * print_out - Prints out folder contents
 * @path: path to file
 * Return: 0 or 1
 *
 */

int print_out(char *path)
{
	DIR *dir;
	struct dirent *read;

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
				printf("%s\n", read->d_name);
		}
	}
	closedir(dir);
	return (1);
}


