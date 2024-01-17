#include "main.h"

/**
 * _memset - Fill memory with a constant byte
 * @s: The memory area to fill
 * @b: The constant byte to fill with
 * @n: The number of bytes to fill
 * Return: Pointer to the filled memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;
    for (i = 0; i < n; i++)
        s[i] = b;
    return s;
}
