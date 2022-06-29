#include "../../sockets.h"

int main(void)
{
	int server, ret;
	todo_queue_t *tdq;

	tdq = malloc(sizeof(*tdq));
	if (!tdq)
		return (EXIT_FAILURE);
	tdq->start = tdq->end = NULL;
	setbuf(stdout, NULL);
	server = sock_init();
	if (server < 0)
		return (EXIT_FAILURE);
	ret = accept_connection(server, tdq);
	close(server);
	return (ret);
}


