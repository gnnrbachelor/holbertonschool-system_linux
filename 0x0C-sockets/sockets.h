#ifndef _SOCKET_H
#define _SOCKET_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define RESP_OK			"HTTP/1.1 200 OK\r\n\r\n"
#define RESP_OK_LEN		strlen(RESP_OK)




void print_data(char *buf);
int accept_connect(int server);
int accept_rec(int server, char *buf, int verbose);
void handle_error(char *err);
int sock_init(void);


#endif
