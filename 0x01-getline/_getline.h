#ifndef _GETLINE_H
#define _GETLINE_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1024

typedef struct fd
{
	int fd;
	char *buffer;
	size_t i;
	size_t len;
	struct fd *next;
} Buf;


char *_getline(const int fd);
char *_strchr(char *s, char c, ssize_t size);
Buf *get_buffer(Buf *head, const int fd);
char *read_buffer(Buf *f_buffer);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


#endif
