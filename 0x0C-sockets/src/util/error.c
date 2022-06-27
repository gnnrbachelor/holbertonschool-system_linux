#include "../../sockets.h"

void handle_error(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}


