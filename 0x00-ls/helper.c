#include "ls.h"


/**
 * _realloc - Reallocates a memory block
 *
 * @ptr: Pointer to old mem
 * @old_size: Old size
 * @new_size: New size
 *
 * Return: Pointer to new memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *cpy;
	char *p;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		p = malloc(new_size);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	p = malloc(new_size);
	cpy = p;

	if (p == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		p[i] = cpy[i];

	return (cpy);
}

/**
 * _strcmp - Compares two strings.
 *
 * @s1: String one
 * @s2: String two
 *
 * Return: Difference
 */

int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
		return (0);
	else
		return (*s1 - *s2);
}

/**
 * _memset - Fills memory with constant byte
 *
 * @s: memory address
 * @b: byte
 * @n: number to fill
 *
 * Return: s
 */

void *_memset(void *p, char b, unsigned int n)
{
	char *start = p; 
	char *stop = start + n;

	while (start < stop)
		*start++ = b;
	return (p);
}
