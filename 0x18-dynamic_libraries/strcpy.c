#include "main.h"

/**
 * _strcpy - Copy a string from source to destination
 * @dest: The destination string
 * @src: The source string
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
    int i = 0;
    while ((dest[i] = src[i]) != '\0')
    {
        i++;
    }
    return dest;
}
