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
	if (dir == NULL)
	{
		printf("Fuck off");
	}

	else
	{
		while ((read = readdir(dir)) != NULL)
			printf("%s\n", read->d_name);
	}
	closedir(dir);

}

