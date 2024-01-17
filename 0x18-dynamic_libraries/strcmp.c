#include "main.h"

/**
 * _strcmp - Compare two strings
 * @s1: The first string
 * @s2: The second string
 * Return: 0 if s1 and s2 are equal, < 0 if s1 < s2, > 0 if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
    {
        i++;
    }
    return s1[i] - s2[i];
}
