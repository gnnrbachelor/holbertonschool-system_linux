#include "../../sockets.h"

void parse_request(char *buf, int client, todo_queue_t *tdq)
{
	char *carry;

	if (parse_error(buf, client) == 1)
		return;

	if (strncmp(buf, POST, POST_SZ) == 0)
	{
		if (post(buf, tdq) == NULL)
		{
			strtok_r(buf, " ", &carry);
			printf("%s %s -> 422 Unprocessable Entity\n", POST,
				strtok_r(NULL, " ", &carry));
			send(client, RESP_UNPROC,
				RESP_UNPROC_SZ, 0);
			return;
		}
		post_response(client, tdq);
	}
	else
	{
		strtok_r(buf, " ", &carry);
		printf("method %s -> 404 Not found\n",
			strtok_r(NULL, " ", &carry));
		send(client, RESP_NOTFOUND, RESP_NOTFOUND_SZ, 0);
		return;
	}
}


int parse_error(char *buf, int client)
{
	char *carry;

	if (strstr(buf, PATH) == NULL)
	{
		strtok_r(buf, " ", &carry);
		printf("%s %s -> 404 Not Found\n", POST,
			strtok_r(NULL, " ", &carry));
		send(client, RESP_NOTFOUND, RESP_NOTFOUND_SZ, 0);
		return (1);
	}
	if (strstr(buf, "Content-Length") == NULL)
	{
		strtok_r(buf, " ", &carry);
		printf("%s %s -> 411 Length Required\n", POST,
			strtok_r(NULL, " ", &carry));
		send(client, RESP_SZ_REQ, RESP_SZ_REQ_SZ, 0);
		return (1);
	}
	return (0);
}
