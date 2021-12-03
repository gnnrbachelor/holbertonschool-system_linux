#ifndef LS_H
#define LS_H

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include "link.h"
#include <sys/types.h>
#include <sys/stat.h>


#define BUFFER_SIZE 1024

typedef struct file
{
	char *name;
	struct stat stat;
} File;

typedef struct file_node
{
	File file;
	struct file_node *next;
} list_t;

typedef struct path_node
{
	File *files;
	size_t file_size;
	size_t files_index;

	list_t *directories;
	
	int status;
	int mul_dirs;
	int printed_d;
	
} path_node;

/**
 * struct list_s - singly linked list
 *
 *  @str: string - (malloc'ed string)
 *  @len: length of the string
 *   @next: points to the next node
 *
 * Description: singly linked list node structure
 */

typedef struct path_list
{
	char *path_item;
	struct path_list *next;
} path_list;

int _strcmp(char *s1, char *s2);
int ls(int argn, char **args);
int print_out(char *path, char**args, int argn);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_memset(void *s, char b, unsigned int n);

size_t print_list(list_t *h);
list_t *add_node(list_t **head, File *file);
list_t *add_node_end(list_t **head, File *file);
void free_list(list_t *head);
void free_node(path_node *head);


#endif


