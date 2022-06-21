#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define PORT 12345

int main(void)
{
	int socket_fd;
	struct sockaddr_in addr;

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd < 0)
	{
		close(socket_fd);
		exit(EXIT_FAILURE);
	}
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		close(socket_fd);
		exit(EXIT_FAILURE);
	}
	if (listen(socket_fd, 10) < 0)
	{
		close(socket_fd);
		exit(EXIT_FAILURE);
	}
	printf("Server listening on port %i\n", PORT);
	while (1)
		;
	return (0);
}
