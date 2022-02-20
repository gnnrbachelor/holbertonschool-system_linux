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
	(void)info;

	printf("Caught %d\n", sig_num);
	fflush(stdout);
}


/**
 * handle_signal - Handles signal SIGQUIT
 * Return: 0 or -1
 *
 */

int handle_signal(void)
{

	struct sigaction sa;

	sa.sa_sigaction = sig_print;
	sa.sa_flags |= SA_SIGINFO;

	return (sigaction(SIGINT, &sa, NULL));

}

/**
 * main - entry
 * Return: 0
 */

int main(void)
{
	handle_signal();
	pause();
	printf("Signal received\n");
	return (EXIT_SUCCESS);
}
