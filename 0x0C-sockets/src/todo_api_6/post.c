#include "../../sockets.h"


todo_node_t *post(char *buf, todo_queue_t *tdq)
{
	char *carry, *token, *title, *desc;
	int i = 0;
	todo_node_t *n_node;

	for (i = 0, strtok_r(buf, "\n", &carry); i < 7; i++)
		token = strtok_r(NULL, "\n", &carry);
	title = strstr(token, "title");
	if (!title)
		return (NULL);
	desc = strstr(token, "description");
	if (!desc)
		return (NULL);
	n_node = malloc(sizeof(*n_node));
	if (!n_node)
		handle_error("Malloc failed");

	strtok_r(title, "=", &carry);
	n_node->title = strdup(strtok_r(NULL, "&\0", &carry));
	strtok_r(desc, "=", &carry);
	n_node->desc = strdup(strtok_r(NULL, "&\0", &carry));
	if (tdq->start == NULL)
	{
		n_node->id = 0;
		tdq->start = n_node;
		tdq->end = n_node;
	}
	else
	{
		n_node->id = tdq->end->id + 1;
		tdq->end->next = n_node;
		tdq->end = n_node;
	}
	n_node->next = NULL;
	return (n_node);

}


void post_response(int client, todo_queue_t *tdq)
{
	char str[BUFSIZ];
	sprintf(str, "%lu", tdq->end->id);
	tdq->end->size = strlen(str) + strlen(tdq->end->title) + strlen(tdq->end->desc)
	+ POST_CONST_SZ;

	sprintf(str, "%s%s%lu\r\n%s%s%lu%s%s%s%s\"}", RESP_CREATED,
		"Content-Length: ", tdq->end->size, CONTYPE,
		"{\"id\": ", tdq->end->id, ",\"title\":\"",
		tdq->end->title, "\",\"description\":\"",
		tdq->end->desc);
	printf("POST /todos -> 201 Created\n");
	send(client, str, strlen(str), 0);
}

