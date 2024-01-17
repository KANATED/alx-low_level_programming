#include "main.h"

/**
 * _strspn - Get the length of a prefix substring
 * @s: The string to search
 * @accept: The substring containing accepted characters
 * Return: The number of accepted characters in the beginning of s
 */
unsigned int _strspn(char *s, char *accept)
{
    unsigned int count = 0;
    int i, j;
    int match;

    for (i = 0; s[i] != '\0'; i++)
    {
        match = 0;
        for (j = 0; accept[j] != '\0'; j++)
        {
            if (s[i] == accept[j])
            {
                match = 1;
                break;
            }
        }
        if (match == 0)
        {
            break;
        }
        count++;
    }

    return count;
}
