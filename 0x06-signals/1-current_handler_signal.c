#include "signals.h"

/**
 * current_handler_signal - Current handler
 * Return: handler
 *
 */

void (*current_handler_signal(void))(int)
{
	sighandler_t handler = signal(SIGINT, SIG_DFL);

	if (signal(SIGINT, handler) == SIG_ERR)
		return (NULL);
	else
		return (handler);

}



