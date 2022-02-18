#include "signals.h"

/**
 * signal_handler - Prints gotcha
i* @sig: Signal
 * Return: Void
 */



void printer(int sig)
{
	printf("Gotcha! [%d]\n", sig);
	fflush(stdout);
}

/**
 * handle_signal - Handles ctr-c
 * Return: 1 or 0 
 */

int handle_signal(void)
{
	if (signal(SIGINT, printer) != SIG_ERR)
		return (0);
	else
		return (-1);

}
