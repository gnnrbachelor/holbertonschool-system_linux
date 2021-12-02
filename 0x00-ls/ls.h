#ifndef LS_H
#define LS_H

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>


#define BUFFER_SIZE 1024

int _strcmp(char *s1, char *s2);
int ls(char **args);

#endif


