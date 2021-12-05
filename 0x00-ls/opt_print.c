#include "ls.h"

/**
 * ls - reads directory and lists files
 * @node: node
 * @path: path
 * Return: void
 */
void ls(path_node *node, char *path)
{
	DIR *dir;
	struct dirent *read;
	char buf[BUFFER_SIZE] = {0};

	if (!path)
		return;
	dir = opendir(path);
	if (!dir)
	{
		if (errno == ENOENT)
			sprintf(buf, "%s: cannot access '%s'", NONAME, path);
		else if (errno == EACCES)
			sprintf(buf, "%s: cannot open directory '%s'", NONAME, path);
		perror(buf);
		node->status = 2;
		return;
	}
	if (node->mul_dirs)
	{
		printf("%s%s:\n", node->printed_d++ ? "\n" : "", path);
	}
	while ((read = readdir(dir)) != NULL)
	{
		if (*read->d_name != '.')
			printf("%s%c", read->d_name, node->options & OPTION_1 ? '\n' : '\t');
	}

	if (!node->options & OPTION_1)
		printf("\n");

	closedir(dir);
}

void choose_op(path_node *node, char *arg)
{
	while(*++arg)
	{
		switch(*arg)
		{
			case '1':
				node->options |= OPTION_1;
				break;

			default:
				bad_option(node, *arg);
				free_node(node);
				exit(2);
				break;
		}
	}

}


