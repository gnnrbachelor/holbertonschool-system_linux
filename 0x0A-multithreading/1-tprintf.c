#include "multithreading.h"

/**
 * tprintf - prints out formatted string
 * @format: String
 * Return: return val
 */

int tprintf(char const *format, ...)
{
	pthread_t self = pthread_self();

	printf("[%lu] %s", self, format);
	return (0);
}
