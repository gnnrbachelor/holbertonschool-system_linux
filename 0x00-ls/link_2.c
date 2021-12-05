#include "ls.h"


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


