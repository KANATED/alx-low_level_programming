/**
 * print_binary - Prints the binary representation of a decimal number.
 * @n: Number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int current;

	for (i = 63; i >= 0; i--)
	{
		current = n >> i;

		if (current & 1)
		{
			/* Print '1' if the current bit is set to 1. */
			_putchar('1');
			count++;
		}
		else if (count)
		{
			/* Print '0' only if there was at least one previous '1' bit. */
			_putchar('0');
		}
	}

	if (!count)
	{
		/* If no '1' bit was found, print '0'. */
		_putchar('0');
	}
}
