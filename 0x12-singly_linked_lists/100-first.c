#include <stdio.h>

/**
 * first_main - prints a string before the
 *              main function is executed.
 *
 * Return: Always void.
 */

void __attribute__((constructor)) first_main(void)
{
	printf("You're beat! and yet, you must allow,\nI bore\
	 my house upon my back!\n");
}
