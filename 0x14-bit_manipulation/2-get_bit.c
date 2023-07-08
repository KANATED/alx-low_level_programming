#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index in a decimal number.
 * @n: Number to search.
 * @index: Index of the bit.
 *
 * Return: Value of the bit at the given index.
 *
 * Description: This function retrieves the value of the bit at the specified
 * index in the given decimal number by performing a bitwise right shift
 * operation followed by a bitwise AND operation with 1.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
