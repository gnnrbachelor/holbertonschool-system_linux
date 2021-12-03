#include "ls.h"


/**
 * add_node - Adds node at beginning
 *
 * @head: Current head
 * @str: data
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
	list_t *n_node;
	list_t *temp;

	if (file)
	{
		n_node = malloc(sizeof(list_t));
		if (n_node)
		{
			_memset(n_node, 0, sizeof(*n_node));
			n_node->next = NULL;
		}
		else
			return (NULL);

		if (!*head)
		{
			*head = n_node;
			return (*head);
		}
		else
		{
			temp = *head;
			while (temp->next)
				temp = temp->next;
			temp->next = n_node;
		}
	}
	return (n_node);
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
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
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


/**
 * pop_node - pops head node of list
 * @head: address of pointer to first node
 *
 * Return: value of popped node
 */
char *pop_node(list_t **head)
{
	list_t *node;
	char *name;

	if (!head || !*head)
		return (0);

	node = (*head)->next;
	name = (*head)->file.name;
	free(*head);
	*head = node;
	return (name);
}



/**
 * free_node - frees node data
 * @head: address to node
 */
void free_node(path_node *head)
{
	if (head->files)
		free(head->files);
		head->files = NULL;
}


