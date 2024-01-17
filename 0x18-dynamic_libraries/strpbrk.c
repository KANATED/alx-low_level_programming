#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - Search a string for any of a set of bytes
 * @s: The string to search
 * @accept: The set of bytes to search for
 * Return: Pointer to the first occurrence in s of any character in accept, or NULL if not found
 */
char *_strpbrk(char *s, char *accept)
{
    while (*s != '\0')
    {
        if (_strchr(accept, *s) != NULL)
            return s;
        s++;
    }
    return NULL;
}
