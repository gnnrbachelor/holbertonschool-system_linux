#include "../../sockets.h"

void print_data(char *buf)
{
	char *carry, *token, *value;

	token = strtok_r(buf, "\r", &carry);
	while (1)
	{
		token = strtok_r(NULL, ":", &carry) + 1;
		value = strtok_r(NULL, "\r", &carry);
		if (!value)
			break;
		printf("Header: \"%s\" -> \"%s\"\n", token, value);
	}
}
