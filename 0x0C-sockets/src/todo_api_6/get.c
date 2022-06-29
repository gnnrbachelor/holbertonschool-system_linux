#include "../../sockets.h"

void get_all(int client, todo_queue_t *tdq)
{
	char str1[BUFSIZ * 2], str2[BUFSIZ] = {'\0'};
	todo_node_t *current;
	size_t size = GET_CONST_SZ;

	if (tdq->start == NULL)
		sprintf(str1, "%s%s%i\r\n%s[]", GET_OK, "Content-Length: ", GET_CONST_SZ, CONTYPE);
	else
	{
		for (current = tdq->start; current; current = current->next)
		{
			size += current->size;
			if (current != tdq->start)
			{
				++size;
				sprintf(str1, ",%s%lu%s%s%s%s\"}", "{\"id\":",
						current->id, ",\"title\":\"",
						current->title,
						"\",\"description\":\"",
						current->desc);
				strcat(str2, str1);
			}
		}
		sprintf(str1, "%s%s%lu\r\n%s[%s%lu%s%s%s%s\"}%s]",
				GET_OK, "Content-Length: ",
				size, CONTYPE, "{\"id\":", tdq->start->id,
				",\"title\":\"", tdq->start->title,
				"\",\"description\":\"", tdq->start->desc,
				str2);
	}
	printf("GET /todos -> 200 OK\n");
	send(client, str1, strlen(str1), 0);
}

void get_resp(int client, todo_queue_t *tdq, size_t id)
{
	todo_node_t *current;
	char str[BUFSIZ];

	for (current = tdq->start; current && current->id != id; current = current->next)
		;

	if (!current)
	{
		printf("%s -> 404 Not Found\n", GET);
		send(client, RESP_NOTFOUND, RESP_NOTFOUND_SZ, 0);
		return;
	}
	sprintf(str, "%s%s%lu\r\n%s%s%lu%s%s%s%s\"}", GET_OK,
			"Content-Length: ", current->size, CONTYPE,
			"{\"id\":", current->id, ",\"title\":\"",
			current->title, "\",\"description\":\"",
			current->desc);
	printf("GET /todos -> 200 OK\n");
	send(client, str, strlen(str), 0);
}





