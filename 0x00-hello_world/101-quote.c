#include <stdio.h>
#include <unistd.h>
/**
 * main - A program that prints a line to the standard error
 * Return: 1 (Sucess)
 */
int main(void)
{
write(2, "and that peice of art is useful\" -Dora Korpar, 2015-10-18\n", stdout);
return (1);
}
