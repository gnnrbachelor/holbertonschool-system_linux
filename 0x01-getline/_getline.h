#ifndef _GETLINE_H
#define _GETLINE_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFSIZE 1024

typedef struct fd
{
	int fd;
	char *buffer;
	size_t i;
	size_t len;
	struct fd *next;
} buffer;


char *_getline(const int fd);
char *_strchr(char *s, char c, ssize_t size);
char *get_line(buffer *head, const int fd);
void handle_eof(buffer *head);


#endif
