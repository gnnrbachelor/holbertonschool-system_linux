#include "_getline.h"

char *_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}


char *_getline(const int fd)
{
	static Buf head;
	Buf *f_buffer = NULL;
	char *line = NULL;

	f_buffer = get_buffer(&head, fd);
	line = read_buffer(f_buffer);
	return (line);
}

Buf *get_buffer(Buf *head, const int fd)
{
	Buf *node;

	if (!head->buffer)
	{
		head->buffer = NULL;
		head->fd = fd;
		return (head);
	}
	else if (fd < head->fd)
	{
		node = malloc(sizeof(*node));
		if (!node)
			exit(EXIT_FAILURE);
		memcpy(node, head, sizeof(*head));
		memset(head, 0, sizeof(*head));
		head->buffer = NULL;
		head->fd = fd;
		head->next = node;
		return (head);
	}
	for (; head->next && head->next->fd <= fd; head = head->next)
		;
	if (head->fd == fd)
		return (head);

	node = malloc(sizeof(*node));
	if (!node)
		exit(EXIT_FAILURE);
	memset(node, 0, sizeof(*node));
	node->buffer = NULL;
	node->fd = fd;
	node->next = head->next;
	head->next = node;
	return (node);

}

char *read_buffer(Buf *f_buffer)
{
	char buffer[BUFSIZE + 1];
	char *p = _strchr(f_buffer->buffer + f_buffer->i, '\n');
	char *line;
	ssize_t r = 0;

	if (!f_buffer->len || f_buffer->i + 1 == f_buffer->len || !p)
	{
		while (1)
		{
			r = read(f_buffer->fd, buffer, BUFSIZE);
			if (r <= 0)
				return (NULL);
			buffer[r] = 0;
			f_buffer->buffer = _realloc(f_buffer->buffer, f_buffer->len, (f_buffer->len ? f_buffer->len : 1) + r);
			if (!f_buffer->buffer)
				return (NULL);
			f_buffer->len = (f_buffer->len ? f_buffer->len : 1) + r;
			strcpy(f_buffer->buffer, buffer);
			p = _strchr(f_buffer->buffer, '\n');
			if (p)
				break;
		}
	}

	*p = '\0';
	line = strdup(f_buffer->buffer + f_buffer->i);
	f_buffer->i = (p - f_buffer->buffer) + 1;
	if (f_buffer->i + 1 == f_buffer->len)
	{
		f_buffer->i = f_buffer->len = 0;
		free(f_buffer->buffer);
		f_buffer->buffer = NULL;
	}
	return (line);
}

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
