#include "sockets.h"

void handle_error(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}

int main(void)
{
	int server, listen_stat, accept_fd, msg;
	struct sockaddr_in sock, client;
	socklen_t client_size;
	char buf[1024] = {0};

	server = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (server == -1)
		handle_error("Socket Error");
	sock.sin_family = AF_INET;
	sock.sin_port = htons(PORT);
	sock.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(server, (struct sockaddr *)&sock, sizeof(sock)) == -1)
		handle_error("Bind Error");
	listen_stat = listen(server, 5);
	if (listen_stat == -1)
		handle_error("Listen Error");
	printf("Server listening to port %d\n", ntohs(sock.sin_port));
	accept_fd = accept(server, (struct sockaddr *)&client,
		(socklen_t *) &client_size);
	if (accept_fd == -1)
		handle_error("Accept Failed");
	printf("Client connected: %s\n", inet_ntoa(client.sin_addr));
	msg = recv(accept_fd, buf, 1024, 0);
	if (msg == -1)
		handle_error("Receive Failure");
	close(accept_fd);
	close(server);
	printf("Message received: \"%s\"\n", buf);
	return (0);
}
