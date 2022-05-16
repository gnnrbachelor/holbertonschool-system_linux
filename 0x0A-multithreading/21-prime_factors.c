#include "multithreading.h"


/**
 * prime_factors - Factors
 * @s: String
 * Return: List of prime #
 *
 */

list_t *prime_factors(char const *s)
{
	unsigned long n, i;
	list_t *primes = NULL;
	unsigned long *temp;

	if (!s)
		return (NULL);

	primes = malloc(sizeof(list_t));

	if (!primes)
		return (NULL);

	list_init(primes);

	n = strtoul(s, NULL, 10);

	for (i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			temp = malloc(sizeof(unsigned long));
			*temp = i;
			list_add(primes, (void *)temp);
			n /= i;
		}
	}

	if (n >= 2)
	{
		temp = malloc(sizeof(unsigned long));
		*temp = n;
		list_add(primes, (void *)temp);
	}
	return (primes);
}
