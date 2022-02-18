#include "signals.h"

/**
 * print_hello - Prints hello
 * @sig: Signal
 */

void print_hello(int sig)
{
	(void)sig;
	printf("Gotcha![%d] \n", sig);
}

/**
 * handle_sigaction - handles signal action
 * Return: 0 or -1
 *
 *
 */


int handle_sigaction(void)
{
	struct sigaction sa;

	sa.sa_handler = print_hello;

	return (sigaction(SIGINT, &sa, NULL));
}
