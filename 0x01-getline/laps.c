#include "laps.h"

/**
 * race_state - Records race state
 * @id: Id
 * @size: Size
 * Return: Void
 */

void race_state(int *id, size_t size)
{
	static Car *head = NULL;
	Car *temp = NULL;
	size_t i;

	if (!size)
	{
		while (head)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
		return;
	}

	for (i = 0; i < size; i++)
		add_car(&head, id[i]);
/*
	{
		if (!head)
		{
			n_node = malloc(sizeof(Car));
			if (!n_node)
				exit(EXIT_FAILURE);
			n_node->id = id[i];
			n_node->lap_n = 0;
			n_node->next = NULL;
			head = n_node;
			printf("Car %d joined the race\n", n_node->id);
			return;
		}

		for (n_node = head; n_node->next && n_node->next->id <= id[i]; n_node = n_node->next)
		;
		if (n_node->id == id[i])
		{
			n_node->lap_n++;
			return;
		}

		temp = malloc(sizeof(Car));
		if (!temp)
			exit(EXIT_FAILURE);
		temp->id = id[i];
		temp->lap_n = 0;
		temp->next = temp->next;
		n_node->next = temp;
		printf("Car %d joined the race\n", n_node->id);

	}
*/


	printf("Race state:\n");
	for (temp = head; temp; temp = temp->next)
		printf("Car %d [%d laps]\n", temp->id, temp->lap_n);

}


void add_car(Car **head, int id)
{
	Car *temp = NULL;
	Car *n_node = NULL;

	if (!*head)
	{
		n_node = malloc(sizeof(Car));
		if (!n_node)
			exit(EXIT_FAILURE);
		n_node->id = id;
		n_node->lap_n = 0;
		n_node->next = NULL;
		*head = n_node;
		printf("Car %d joined the race\n", n_node->id);
		return;
	}

	for (n_node = *head; n_node->next && n_node->next->id <= id; n_node = n_node->next)
		;

	if (n_node->id == id)
	{
		n_node->lap_n++;
		return;
	}

	temp = malloc(sizeof(Car));
	if (!temp)
		exit(EXIT_FAILURE);
	temp->id = id;
	temp->lap_n = 0;
	temp->next = n_node->next;
	n_node->next = temp;
	printf("Car %d joined the race\n", n_node->id);

	}
