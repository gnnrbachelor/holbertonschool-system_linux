#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - entry to main
 * @argc: argc
 * @argv: argv
 * @env:  environ
 * Return: -1 or 0
 */
int main(int argc, char **argv, char **env)
{
	char *args[] = {"/usr/bin/readelf", "-W", "-S", "", NULL};

	if (argc != 2)
		exit(0);

	args[3] = argv[1];
	if (execve(args[0], args, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
