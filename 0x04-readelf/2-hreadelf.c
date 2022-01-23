#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - entry point
 * @argc: arg count
 * @argv: args
 * @env:  environment
 * Return: -1 or 0
 */
int main(int argc, char **argv, char **env)
{
	char *args[] = {"/usr/bin/readelf", "-W", "-l", "", NULL};

	(void)argc;
	args[3] = argv[1];
	if (execve("/usr/bin/readelf", args, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
