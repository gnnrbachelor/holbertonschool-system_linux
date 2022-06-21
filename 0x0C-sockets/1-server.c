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
	int socket_fd, stat;
	struct sockaddr_in server, client;
	socklen_t client_len;

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd < 0)
	{
		close(socket_fd);
		exit(1);
	}
	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(socket_fd, (struct sockaddr *)&server, sizeof(server)) < 0)
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
	client_len = sizeof(client);
	while (1)
	{
		stat = accept(socket_fd, (struct sockaddr *) &server, &client_len);
		if (stat < 0)
		{
			close(socket_fd);
			exit(EXIT_FAILURE);
		}
		printf("Client connected: %s\n", inet_ntoa(server.sin_addr));
		close(stat);
		exit(EXIT_SUCCESS);
	}

	return (0);
}
