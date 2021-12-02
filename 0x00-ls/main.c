#include "ls.h"

/**
 * main - entry
 * @argc: num
 * @argv: pointer to args
 * Return: 0
 *
 */


int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	DIR *dir;
	struct dirent *read;
	char *dirname;

	dirname = ".";
	dir = opendir(dirname);

	if (!dir)
	{
		return (0);
	}

	else
	{
		while ((read = readdir(dir)) != NULL)
		{
			if (strcmp(read->d_name, ".") != 0 && strcmp(read->d_name, "..") != 0)
				printf("%s\n", read->d_name);
		}
	}
	closedir(dir);

}

