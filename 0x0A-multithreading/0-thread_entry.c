#include "multithreading.h"


/**
 * thread_entry - Entry to new thread
 * @arg: Args
 * Return: Void
 *
 */

void *thread_entry(void *arg)
{
	if (!arg)
		pthread_exit(NULL);

	printf("%s\n", (char *)arg);
	pthread_exit(NULL);
}

