#include "signals.h"


/**
 * sigset_init - initializes a signal set
 * @set: pointer to signal set
 * @signals: array of signals
 * Return: 0 or -1
 */

int sigset_init(sigset_t *set, int *signals)
{
	int i;

	if (sigemptyset(set) == -1)
		return (-1);

	for (i = 0; signals[i]; i++)
	{
		if (sigaddset(set, signals[i]) != 0)
			return (-1);
	}

	return (0);
}


/**
 * signals_unblock - blocks signals
 * @signals: Signals
 * Return: 0 or -1
 */

int signals_unblock(int *signals)
{
	sigset_t set;

	if (sigset_init(&set, signals))
		return (-1);
	return (sigprocmask(SIG_UNBLOCK, &set, NULL));
}
