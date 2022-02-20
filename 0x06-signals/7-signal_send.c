#include "signals.h"

/**
 * main - entry
 * @argc: Arg count
 * @argv: Args
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	if (kill(atoi(argv[1]), SIGINT) == 0)
		return (EXIT_SUCCESS);

	return (EXIT_FAILURE);
}
