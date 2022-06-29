#include "../../sockets.h"

void delete(int client, todo_queue_t *tdq, size_t id)
{
	todo_node_t *current, *temp;

	for (current = tdq->start; current && current->id != id; current = current->next)
	{
		if (current->next && id == current->next->id)
			break;
	}
	if (!current)
	{
		printf("%s /todos -> 404 Not Found\n", DELETE);
		send(client, RESP_NOT_FOUND, RESP_NOT_FOUND_SZ, 0);
		return;
	}
	if (current == tdq->start)
	{
		current = current->next;
		free(tdq->start);
		tdq->start = current;
	}
	else if (current->next == tdq->end)
	{
		current->next = NULL;
		free(tdq->end);
		tdq->end = current;
	}
	else
	{
		temp = current->next;
		current->next = temp->next;
		free(temp);
	}
	printf("%s /todos -> 204 No content\n", DELETE);
	send(client, RESP_DEL, RESP_DEL_SZ, 0);
}
