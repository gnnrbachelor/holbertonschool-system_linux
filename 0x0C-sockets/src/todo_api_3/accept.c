#include "../../sockets.h"

int accept_connect(int server)
{
	int client;
	char buf[BUFSIZ];

	while (1)
	{
		client = accept_rec(server, buf, 1);
		if (client < 0)
			return (EXIT_FAILURE);
		print_data(buf);
		send(client, RESP_OK, RESP_OK_LEN, 0);
		close(client);
	}
	return (EXIT_SUCCESS);
}

