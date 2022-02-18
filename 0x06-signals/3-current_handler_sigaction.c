#include "signals.h"

/**
 * current_handler_sigaction - Handles signal
 * Return: pointer to sig handler or NULL
 *
 *
 */

void (*current_handler_sigaction(void))(int)
{
	struct sigaction sa;

	return (sigaction(SIGINT, NULL, &sa) ? NULL : sa.sa_handler);
}
