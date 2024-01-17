#include "main.h"
#include <stddef.h>
/**
 * _strchr - Locate character in string
 * @s: The string to search
 * @c: The character to locate
 * Return: Pointer to the first occurrence of c in s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return s;
        s++;
    }
    return (*s == c) ? s : NULL;
}
