#include "main.h"
/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number to retrieve the bit from.
 * @index: The index of the bit to get.
 *
 * Return: The value of the bit at the specified index, or -1 if an error occurred.
 *
 * Description: This function retrieves the value of the bit at the specified index
 * in the given number by creating a mask, performing a bitwise AND operation to extract
 * the bit, and returning 1 if the bit is set, or 0 if it is not set. If the index is
 * out of range, -1 is returned to indicate an error.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return -1; // Invalid index

	unsigned long int mask = 1UL << index;
	unsigned long int bit = n & mask;

	return (bit != 0) ? 1 : 0;
}
