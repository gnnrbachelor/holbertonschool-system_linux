#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#include "signals.h"

/* Our functions */
int sigset_init(sigset_t *set, int *signals);
int _signals_block(int *signals);
int _signals_unblock(int *signals);

/**
 * handler - Handler for pending signals
 * @signum: Signal number
 */
void handler(int signum)
{
    printf("\nCaught signal %d\n", signum);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    int signals[] = {
        SIGINT,
        SIGQUIT,
        SIGSEGV,
        SIGTRAP,
        0
    };

    if (_signals_block(signals) == -1)
    {
        fprintf(stderr, "Failed to block signals\n");
        return (EXIT_FAILURE);
    }

    sleep(5);
    if (handle_pending(&handler) == -1)
    {
        printf("Failed to set up handler for pending signals\n");
        return (EXIT_FAILURE);
    }

    if (_signals_unblock(signals) == -1)
    {
        fprintf(stderr, "Failed to unblock signals\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

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



int _signals_block(int *signals)
{
	sigset_t set;

	if (sigset_init(&set, signals))
		return (-1);
	return (sigprocmask(SIG_BLOCK, &set, NULL));
}

int _signals_unblock(int *signals)
{
	sigset_t set;

	if (sigset_init(&set, signals))
		return (-1);
	return (sigprocmask(SIG_UNBLOCK, &set, NULL));
}


