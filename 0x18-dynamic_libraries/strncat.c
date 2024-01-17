#include "main.h"

/**
 * _strncat - Concatenate n characters from source to destination
 * @dest: The destination string
 * @src: The source string
 * @n: The number of characters to concatenate
 * Return: Pointer to the resulting string
 */
char *_strncat(char *dest, char *src, int n)
{
    int i, j;

    for (i = 0; dest[i] != '\0'; i++)
        ;

    for (j = 0; src[j] != '\0' && j < n; j++)
    {
        dest[i] = src[j];
        i++;
    }

    dest[i] = '\0';

    return dest;
}
