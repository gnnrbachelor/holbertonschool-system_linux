#include "../../sockets.h"

int accept_connection(int server, todo_queue_t *tdq)
{
	int client;
	char buf[BUFSIZ];

	while (1)
	{
		client = accept_rec(server, buf, 0);
		if (client < 0)
			return (EXIT_FAILURE);
		parse_request(buf, client, tdq);
		close(client);
	}
	return (EXIT_SUCCESS);
}

