#include "main.h"

/**
 * get_endianness - Checks if a machine is little or big endian.
 *
 * Return: 0 for big endian, 1 for little endian.
 *
 * Description: This function determines the endianness of the machine by
 * examining the value stored in an unsigned int and checking the least
 * significant byte.
 */
int get_endianness(void)
{
	unsigned int value = 1;
	char *byte_ptr = (char *)&value;

	return (*byte_ptr);
}
