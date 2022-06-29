#include "../../sockets.h"

int main(void)
{
	int server, accept_payload;

	setbuf(stdout, NULL);
	server = sock_init();
	if (server < 0)
		return (EXIT_FAILURE);
	accept_payload = accept_connect(server);
	close(server);
	return (accept_payload);
}


