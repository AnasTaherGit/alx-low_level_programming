#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet 10 times
 *
 * Return: void
 */

void print_alphabet_x10(void)
{
	char c;
	int i;

	for (i = 0; i < 10; i++)
	{
		for (c = 'a'; c < 'z'; c++)
		{
			_putchar(c);
		}
		if (i != 9)
			_putchar('\n');
	}
}
