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
#define POST			"POST"
#define POST_SZ			strlen(POST)
#define PATH			"/todos "
#define RESP_OK			"HTTP/1.1 200 OK\r\n\r\n"
#define RESP_OK_LEN		strlen(RESP_OK)
#define RESP_UNPROC		"HTTP/1.1 422 Unprocessable Entity\r\n\r\n"
#define RESP_UNPROC_SZ		strlen(RESP_UNPROC)
#define RESP_NOTFOUND		"HTTP/1.1 404 Not Found\r\n\r\n"
#define RESP_NOTFOUND_SZ	strlen(RESP_NOTFOUND)
#define POST_CONST_SZ		35
#define RESP_CREATED		"HTTP/1.1 201 Created\r\n"
#define CONTYPE			"Content-Type: application/json\r\n\r\n"
#define RESP_SZ_REQ		"HTTP/1.1 Length Required\r\n\r\n"
#define RESP_SZ_REQ_SZ		strlen(RESP_SZ_REQ)




typedef struct todo_node_s
{
	size_t id;
	char *title;
	char *desc;
	size_t size;
	struct todo_node_s *next;
} todo_node_t;

typedef struct todo_queue_s
{
	todo_node_t *start;
	todo_node_t *end;
} todo_queue_t;




void print_data(char *buf);
int accept_connect(int server);
int accept_connection(int server, todo_queue_t *tdq);
int accept_rec(int server, char *buf, int verbose);
void handle_error(char *err);
int sock_init(void);
todo_node_t *post(char *buf, todo_queue_t *tdq);
void parse_request(char *buf, int client, todo_queue_t *tdq);
int parse_error(char *buf, int client);
void post_response(int client, todo_queue_t *tdq);



#endif
