#include "signals.h"

/**
 * handle_pending - Handles pending signals
 * @handler: handler
 * Return: 0 or -1
 */

int handle_pending(void (*handler)(int))
{
	sigset_t set;
	struct sigaction sa;
	int i;

	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = handler;
	sigemptyset(&set);
	sigpending(&set);
	for (i = 1; i < 65; i++)
		if (sigismember(&set, i))
			if (sigaction(i, &sa, NULL))
				return (-1);
	return (0);
}
