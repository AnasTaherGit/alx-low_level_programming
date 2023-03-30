#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates valid passwords for the program 101-crackme
 *
 * Return: Always 0.
 */

int main(void)
{
	char password[84];
	int i, sum, n;

	srand(time(NULL));
	for (i = 0; i < 2772; i++)
	{
		n = rand() % 128;
		password[i] = n;
	}
	password[i] = '\0';
	sum = 0;
	for (i = 0; password[i]; i++)
	{
		sum += password[i];
	}
	password[2772] = 2772 - sum;
	printf("%s", password);
	return (0);
}