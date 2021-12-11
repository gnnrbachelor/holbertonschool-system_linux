#include "_getline.h"

char *_getline(const int fd)
{
	char *input = NULL;
	buffer eoc_b = NULL;
	buffer temp = NULL;
	static buffer head;

	if (fd == -1)
	{
		handle_eof(buffer *head);
		return (NULL);
	}

	input = get_line(&head, fd);
	if (input != NULL && input[0] == '\n' && !input[1])
		input[0] = 0;
	return (input);
}

void handle_eof(buffer *head)
{
	buffer *eof_b = NULL;
	buffer *temp = NULL;

	if (head->buffer)
	{
		free(eof_b->buffer);
		head->buffer = NULL;
	}

	for (eof_b = head->next; eof_b;)
	{
		if (eof_b->buffer)
		{
			free(eof_b->buffer);
			eof_buffer = NULL;
		}

		temp = eof_b;
		eof_b = eof_b->next;
		free(temp);
	}

	memset(&head, 0, sizeof(head));
}

char *_strchr(char *s, char c, ssize_t size)
{
	if (s == NULL)
		return (NULL);
	do {
		if (*s == c)
			return (s);
		s++;
	} while (--size > 0 );
	return (NULL);
}

