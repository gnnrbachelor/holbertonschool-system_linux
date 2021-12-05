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

/**
 * is_dir - Indicates if file is a directory
 * @file: file
 * Return: 0 if dir
 *
 */

int is_dir(File *file)
{
	return (S_ISDIR(file->stat.st_mode));
}

/**
 * not_found_error - Error
 * @node: node
 * @name: name
 * Return: void
 */

void not_found_error(path_node *node, char *name)
{
	char buffer[BUFFER] = {0};

	node->status = 2;
	sprintf(buffer, "%s: cannot access '%s'", NONAME, name);
	perror(buffer);
}

/**
 * bad_option - Error
 * @node: node
 * @name: name
 * Return: void
 */



void bad_option(path_node *node, char path)
{
	node->status = 2;
	fprintf(stderr, "%s: invalid option -- '%c'\n", NONAME, path);
}

