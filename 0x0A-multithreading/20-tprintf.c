#include "multithreading.h"

static pthread_mutex_t mutex;


/**
 * begin - init mutex
 *
 */

__attribute__((constructor))void begin(void)
{
	if (pthread_mutex_init(&mutex, NULL) != 0)
		perror(NULL);
}

/**
 * end - destroy mutex
 *
 */

__attribute__((destructor))void end(void)
{
	if (pthread_mutex_destroy(&mutex))
		perror(NULL);
}


/**
 * tprintf - prints
 * @format: Format
 * Return: # Char printed
 *
 */

int tprintf(char const *format, ...)
{
	va_list args;
	int num_char;

	if (pthread_mutex_lock(&mutex) != 0)
		perror(NULL);

	va_start(args, format);
	num_char = printf("[%lu] ", pthread_self());
	num_char += vprintf(format, args);
	va_end(args);
	if (pthread_mutex_unlock(&mutex) != 0);
		perror(NULL);
	return (num_char);

}

