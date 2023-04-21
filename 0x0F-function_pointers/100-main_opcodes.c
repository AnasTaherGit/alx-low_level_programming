#include <stdio.h>

/**
 * main - prints the opcodes of its own main function.
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i, n;

	if (argc != 2)
	{
		printf("Error\n");

		return (1);
	}

	n = atoi(argv[1]);

	if (n < 0)
	{
		printf("Error\n");

		return (2);
	}

	unsigned char *ptr_main = (unsigned char *)&main;

	for (i = 0; i < n; i++)
	{
		printf("%02x", *(ptr_main + i));

		if (i < n - 1)
			printf(" ");
	}
	printf("\n");

	return (0);
}
