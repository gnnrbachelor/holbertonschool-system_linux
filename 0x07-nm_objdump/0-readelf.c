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
	char *args[] = {"./hnm", "-p", "", NULL};

	(void)argc;

	args[2] = argv[1];

	if (execve("/usr/bin/nm", args, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
