#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - entry point for simple calculator program
 * @argc: number of arguments passed
 * @argv: array of arguments passed
 *
 * Return: 0 if successful, other error codes if errors encountered
 */
int main(int argc, char *argv[])
{
	int num1, num2;
	int (*op)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	op = get_op_func(argv[2]);

	if (op == NULL)
	{
		printf("Error\n");
		return (99);
	}

	if ((op == op_div || op == op_mod) && num2 == 0)
	{
		printf("Error\n");
		return (100);
	}

	printf("%d\n", op(num1, num2));
	return (0);
}
