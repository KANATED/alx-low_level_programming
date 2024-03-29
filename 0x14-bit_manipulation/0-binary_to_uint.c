#include "main.h"

/**
 * binary_to_uint - Converts a binary number string to an unsigned int
 * @b: The binary number string (0s and 1s)
 *
 * Return: The converted number, or 0 if there are non-binary characters
 *         or if b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (!b)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);
		result = (result * 2) + (*b - '0');
		b++;
	}

	return (result);
}
