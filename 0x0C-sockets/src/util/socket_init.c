#include "../../sockets.h"

int sock_init(void)
{
	int server, opt = 1;
	struct sockaddr_in server_addr;

	server = socket(AF_INET, SOCK_STREAM, 0);
	if (server < 0)
		handle_error("Socket Failure");
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	if (bind(server, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
		handle_error("Bind Failure");

	if (listen(server, 10) < 0)
		handle_error("Listen Failure");
	printf("Server listening on port %i\n", PORT);
	return (server);
}
