#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>


int main(int argc, char *argv[])
{
	int sock_fd = 0;
	struct sockaddr_in sock;
	char *host = NULL, *host_num = NULL;
	unsigned long port = 0;

	if (argc != 3)
	{
		printf("Usage: %s <host> <port>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	host = argv[1];
	port = atoi(argv[2]);
	if (sock_fd == -1)
	{
		perror("Socket failed");
		return (EXIT_FAILURE);
	}
	if (strcmp(host, "localhost") == 0)
		host_num = "127.0.0.1";
	else
		host_num = host;

	sock.sin_family = AF_INET;
	sock.sin_port = htons(port);
	sock.sin_addr.s_addr = inet_addr(host_num);
	if (connect(sock_fd, (struct sockaddr *)&sock, sizeof(sock)) == -1)
	{
		perror("Connection Failure");
		return (EXIT_FAILURE);
	}
	printf("Connected to %s:%s\n", argv[1], argv[2]);
	close(sock_fd);
	return (EXIT_SUCCESS);
}
