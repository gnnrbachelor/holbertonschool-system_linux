#include "ls.h"

/**
 * print_files - Prints files
 * @node: node
 * Return: void
 */

void print_files(path_node *node)
{
	size_t i;

	for (i = 0; i < node->files_index; i++)
	{
		if (!is_dir(&node->files[i]))
		{
			printf("%s%c", node->files[i].name,
				(i + 1 == node->files_index) || (node->options & OPTION_1) ? '\n' : '\t');
		}
	}
}

/**
 * get_dirs - Gets directories
 * @node: node
 * Return: void
 */

void get_dirs(path_node *node)
{
	size_t i;

	for (i = 0; i < node->files_index; i++)
	{
		if (is_dir(&node->files[i]))
		{
			add_node_end(&node->directories, &node->files[i]);
		}
	}
}


/**
 * print_dirs - prints from linked list
 * @node: node
 */
void print_dirs(path_node *node)
{
	list_t *temp = node->directories;
	char *name;

	node->mul_dirs = temp && temp->next;
	while (temp)
	{
		name = pop_node(&temp);
		ls(node, name);
	}
}
