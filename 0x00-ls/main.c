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

/*	path_node node = {NULL, 0, 0, NULL, EXIT_SUCCESS, 0, 0};

	node.files = _realloc(NULL, 0, sizeof(File));
	node.file_size = 1;
*/

	if (argc == 1)
	{
		ls(argc, argv);		
	}

	else
	{
		ls(argc, argv);
	}
	
	return (0);

}

