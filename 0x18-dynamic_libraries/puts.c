#include "main.h"

/**
 * _puts - Write a string to the standard output followed by a newline
 * @s: The string to write
 */
void _puts(char *s)
{
    while (*s)
    {
        _putchar(*s);
        s++;
    }
    _putchar('\n');
}
