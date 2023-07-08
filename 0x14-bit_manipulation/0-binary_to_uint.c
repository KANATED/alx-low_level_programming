#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: String containing the binary number.
 *
 * Return: The converted unsigned int value.
 *
 * Description: This function converts a binary number represented as a string
 * to its equivalent unsigned int value by iterating through each character and
 * performing the conversion based on the binary representation.
 */
unsigned int binary_to_uint(const char *b)
{
	int index;
	unsigned int decimal_value = 0;

	if (!b)
		return (0);

	for (index = 0; b[index]; index++)
	{
		if (b[index] < '0' || b[index] > '1')
			return (0);
		decimal_value = (decimal_value * 2) + (b[index] - '0');
	}

	return (decimal_value);
}
