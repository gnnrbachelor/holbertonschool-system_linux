#include "signals.h"

/**
 * main - entry
 * @ac: arg count
 * @argv: Args
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *sig;
	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	sig = strsignal(atoi(argv[1]));
	printf("%s: %s\n", argv[1], sig);
	return (0);
}

