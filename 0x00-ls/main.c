#include "ls.h"

/**
 * main - entry
 * @argc: num
 * @args: pointer to args
 * Return: 0
 *
 */


int main(int ac, char **args)
{

/*	ls(argc, argv); */

	path_node node = NODE_INIT;

	node.files = _realloc(NULL, 0, START * sizeof(File));
	node.file_size = START;

	if (ac == 1)
		tokenize(&node, ".");

	while (*++args)
		tokenize(&node, *args);
	get_dirs(&node);
	print_files(&node);
	print_dirs(&node);
	free_node(&node);
	return (node.status);

}

