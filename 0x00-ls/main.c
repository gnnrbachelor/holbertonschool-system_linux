#include "ls.h"

/**
 * main - entry
 * @argc: num
 * @args: pointer to args
 * Return: 0
 *
 */


int main(int argc, char **args)
{

	path_node node = NODE_INIT;

	node.files = _realloc(NULL, 0, START * sizeof(File));
	node.file_size = START;

	(void)argc;

	while (*++args)
	{
		if (**args == '-')
			choose_op(&node, *args);
		else
			tokenize(&node, *args);
	}

	if (!node.files_index)
		tokenize(&node, ".");

	get_dirs(&node);
	print_files(&node);
	print_dirs(&node);
	free_node(&node);
	return (node.status);

}

