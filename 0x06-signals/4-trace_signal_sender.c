#include "signals.h"


/**
 * printer - Prints signal SIGQUIT
 * Return: 0 or -1
 *
 */

void sig_hand(int sig_num, siginfo_t *info, void *context)
{
	(void)context;

	if (sig_num == SIGQUIT)
		printf("SIGQUIT sent by %u\n", info->si_pid);
}


/**
 * trace_signal_sender - Handles signal SIGQUIT
 * Return: 0 or -1
 *
 */

int trace_signal_sender(void)
{

	struct sigaction sa;

	sa.sa_sigaction = sig_hand;

	return (sigaction(SIGQUIT, &sa, NULL));

}
