#include "ls.h"

/**
 * main - entry
 * @argc: num
 * @argv: pointer to args
 * Return: 0
 *
 */


int main(int argc, char **args)
{

/*	ls(argc, argv); */

	path_node node = NODE_INIT;

	node.files = _realloc(NULL, 0, START * sizeof(File));
	node.file_size = START;

	if (argc == 1)
		tokenize(&node, ".");
	
	while (*++args)
		tokenize(&node, *args);
	
	print_files(&node); 

	return (0);

}

