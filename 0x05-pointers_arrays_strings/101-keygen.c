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
	char msg[] = "zzzzzzzzzzzzzzzzzzzzzzz";
	int rand_pos;

	srand(time(0));

	rand_pos = rand() % 24;
	// printf("%lu\n",sizeof(msg));
	msg[rand_pos] = 'X';
	printf("%s", msg);
	return (0);
}