#include "../../sockets.h"

void print_data(char *buf)
{
	char *carry, *token, *value;

	strtok_r(buf, " ", &carry);
	token = strtok_r(NULL, "?", &carry);
	printf("Path: %s\n", token);
	while (1)
	{
		token = strtok_r(NULL, "=", &carry);
		value = strtok_r(NULL, "& ", &carry);
		if (!value)
			break;
		printf("Query: \"%s\" -> \"%s\"\n", token, value);
	}
}
