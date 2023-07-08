#include "main.h"

/**
 * set_bit - Sets a bit at a given index to 1.
 * @n: Pointer to the number to change.
 * @index: Index of the bit to set to 1.
 *
 * Return: 1 for success, -1 for failure.
 *
 * Description: This function sets the bit at the specified index in the given
 * number to 1 by performing a bitwise OR operation with a mask that has a 1
 * at the desired index and 0s elsewhere.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);

