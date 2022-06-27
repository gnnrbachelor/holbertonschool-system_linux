#include "../../sockets.h"

int accept_rec(int server, char *buf, int verbose)
{
	int client;
	struct sockaddr_in client_addr;
	socklen_t client_size = sizeof(client_addr);

	client = accept(server, (struct sockaddr *)&client_addr, &client_size);
	if (client < 0)
		handle_error("Accept Failure");

	memset(&*buf, 0, BUFSIZ);
	if (recv(client, buf, BUFSIZ, 0) < 0)
		handle_error("Receive Failed");
	if (verbose)
	{
		printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));
		printf("Raw request: \"%s\"\n", buf);
	}
	return (client);
}
