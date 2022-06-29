#include "../../sockets.h"

void print_data(char *buf)
{
	char *carry, *token, *value;
	int i;

	strtok_r(buf, " ", &carry);
	token = strtok_r(NULL, " ", &carry);
	printf("Path: %s\n", token);
	for (i = 0; i < 7; i++)
		token = strtok_r(NULL, "\n", &carry);
	while (1)
	{
		token = strtok_r(NULL, "=", &carry);
		value = strtok_r(NULL, "&\"", &carry);
		if (!value)
			break;
		printf("Body param: \"%s\" -> \"%s\"\n", token, value);
	}
}
