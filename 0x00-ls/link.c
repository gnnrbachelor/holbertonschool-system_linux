#include "ls.h"


/**
 * add_node - Adds node at beginning
 *
 * @head: Current head
 * @file: data
 *
 * Return: NULL or address of new head
 */

list_t *add_node(list_t **head, File *file)
{
	list_t *n_node;

	if (head)
	{
		n_node = malloc(sizeof(list_t));
		if (n_node)
		{
			n_node->file = *file;
			n_node->next = *head;

			*head = n_node;
		}
		else
			return (NULL);
	}
	return (n_node);

}


/**
 * add_node_end - Adds node at end
 *
 * @head: Current head
 * @file: data
 *
 * Return: NULL or address of new head
 */

list_t *add_node_end(list_t **head, File *file)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *node = *head;

	if (!head || !new_node)
		return (NULL);
	_memset(new_node, 0, sizeof(*new_node));
	if (file)
	{
		new_node->file = *file;
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * free_list - Free a list_t list
 *
 * @head: pointer to head
 *
 * Return: Void
 */

void free_list(list_t *head)
{
	list_t *node, *next_node;

	if (!head)
		return;

	node = head;
	while (node)
	{
		next_node = node->next;
		free(node);
		node = next_node;
	}
}


/**
 * print_list - Prints elements of a list_t list
 *
 * @h: pointer to head
 *
 * Return: Number of nodes
 */

size_t print_list(list_t *h)
{
	unsigned int i;

	for (i = 0; h; i++)
	{
		printf("%s\n", h->file.name);
		h = h->next;

	}
	return (i);
}


