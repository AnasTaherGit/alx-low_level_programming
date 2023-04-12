#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the product of two numbers.
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int j;
	int change;
	int coins[5] = {25, 10, 5, 2, 1};
	int result = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	if (atoi(argv[1]) <= 0)
	{
		printf("0\n");
		return (0);
	}
	change = atoi(argv[1]);

	j = 0;

	while (1)
	{
		result += (change / coins[j]);
		change = change % coins[j];
		j++;
		if (j == 5)
			break;
	}
	printf("%d\n", result);

	return (0);
}
