#include "signals.h"


/**
 * sig_print - Prints signal SIGQUIT
 * @sig_num: Signal number
 * @info: Info
 * @context: Context
 * Return: 0 or -1
 *
 */

void sig_print(int sig_num, siginfo_t *info, void *context)
{
	(void)context;
	(void)sig_num;

	psiginfo(info, "Caught");
}


/**
 * all_in_one - Handles all signals
 */

void all_in_one(void)
{

	struct sigaction sa;
	int sg;

	sa.sa_sigaction = sig_print;
	sa.sa_flags |= SA_SIGINFO;
	for (sg = 0; sg < 64; sg++)
		sigaction(sg, &sa, NULL);
}

