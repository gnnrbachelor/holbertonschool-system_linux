#include "ls.h"

/**
 * tokenize - parses args and inserts into array
 * @node: path node
 * @name: filename
 *
 */

void tokenize(path_node *node, char *name)
{
	File *file;

	if (node->files_index == node->file_size)
	{
		node->files = _realloc(node->files, node->file_size * sizeof(File),
					node->file_size * sizeof(File) * 2);
		node->file_size *= 2;
		if (!node->files)
			return;
		
	}

	file = &node->files[node->files_index++];
	file->name = name;

	if (lstat(name, &file->stat))
	{
		not_found_error(node, name);
		node->files_index--;
		return;
	}
}

void print_files(path_node *node)
{
	size_t i;
	
	for (i = 0; i < node->files_index; i++)
	{
		printf("%s%c", node->files[i].name,
			i + 1 == node->files_index ? '\n' : '\t');
	}
}

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


int is_dir(File *file)
{
	return (S_ISDIR(file->stat.st_mode));
}

void not_found_error(path_node *node, char *name)
{
	char buffer[BUFFER] = {0};

	node->status = 2;
	sprintf(buffer, "%s: cannot access '%s'", NONAME, name);
	perror(buffer);
}

