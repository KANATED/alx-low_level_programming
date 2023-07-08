#include "main.h"

/**
 * flip_bits - Counts the number of bits to change
 * to get from one number to another.
 * @n: First number.
 * @m: Second number.
 *
 * Return: Number of bits to change.
 *
 * Description: This function calculates the number of bits that need to be
 * flipped in order to transform the first number into the second number. It
 * performs an exclusive OR (XOR) operation between the two numbers and counts
 * the number of resulting 1 bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int index, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (index = 63; index >= 0; index--)
	{
		current = exclusive >> index;
		if (current & 1)
			count++;
	}

	return (count);
}
