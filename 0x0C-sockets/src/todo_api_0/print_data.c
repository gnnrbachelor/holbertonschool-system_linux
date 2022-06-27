#include "../../sockets.h"

void print_data(char *buf)
{
	char *carry, *method, *path, *version;

	method = strtok_r(buf, " ", &carry);
	path = strtok_r(NULL, " ", &carry);
	version = strtok_r(NULL, "\r", &carry);
	printf("Method: %s\nPath: %s\nVersion %s\n", method, path, version);
}
