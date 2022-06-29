#include "../../sockets.h"

void parse_request(char *buf, int client, todo_queue_t *tdq)
{
	char *carry;
	int req_ret;

	req_ret = parse_req_imp(buf, client, GET);
	if (req_ret == -1)
		return;

	if (strncmp(buf, GET, GET_SZ) == 0)
	{
		if (req_ret == GETALL)
			get_all(client, tdq);
		if (req_ret > -1)
			get_resp(client, tdq, req_ret);

	}
	else if (strncmp(buf, POST, POST_SZ) == 0)
	{
		if (parse_req_imp(buf, client, POST) == 1)
			return;
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



int parse_req_imp(char *buf, int client, char *res_type)
{
	char *carry, *token;

	if (*res_type == *GET)
	{
		if (strstr(buf, PATH) != NULL)
			return (GETALL);
		if (strstr(buf, PATHID) != NULL)
		{
			strtok_r(buf, "=", &carry);
			token = strtok_r(NULL, " ", &carry);
			if (*token >= '0' && *token <= '9')
				return (atoi(token));
		}
		strtok_r(buf, " ", &carry);
		printf("%s %s -> 404 Not Found\n", POST,
		strtok_r(NULL, " ", &carry));
		send(client, RESP_NOTFOUND, RESP_NOTFOUND_SZ, 0);
		return (-1);
	}
	if (*res_type == *POST && strstr(buf, "Content-Length") == NULL)
	{
		strtok_r(buf, " ", &carry);
		printf("%s %s -> 411 Length Required\n", POST,
			strtok_r(NULL, " ", &carry));
		send(client, RESP_SZ_REQ, RESP_SZ_REQ_SZ, 0);
		return (-1);
	}
	return (0);
}
