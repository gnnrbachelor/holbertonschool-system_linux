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
#define NODE_INIT {NULL, 0, 0, NULL, EXIT_SUCCESS, 0, 0}
#define START 1
#define NONAME "hls"
#define BUFFER 1024

typedef struct File
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


int _strcmp(char *s1, char *s2);
int ols(int argn, char **args);
int print_out(path_node node, char *path, char**args, int argn);
void *_memset(void *s, char b, unsigned int n);

size_t print_list(list_t *h);
list_t *add_node(list_t **head, File *file);
list_t *add_node_end(list_t **head, File *file);
void free_list(list_t *head);
void free_node(path_node *head);
void tokenize(path_node *node, char *name);
void print_files(path_node *node);
int is_dir(File *file);
void append_file(path_node *node, char *name);
void not_found_error(path_node *node, char *name);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void get_dirs(path_node *node);
char *pop_node(list_t **head);
void ls(path_node *node, char *path);
void print_dirs(path_node *node);
char *pop_node(list_t **head);


#endif


