#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string containing the binary number.
 *
 * Return: The converted unsigned int value, or 0 if an error occurs.
 */
unsigned int binary_to_uint(const char *b)
{
    unsigned int result = 0;

    if (b == NULL)
        return 0;

    for (; *b; b++)
    {
        if (*b != '0' && *b != '1')
            return 0;

        result = (result * 2) + (*b - '0');
    }

    return result;
}