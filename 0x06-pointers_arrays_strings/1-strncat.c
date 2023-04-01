#include "main.h"
#include <string.h>

/**
 * _strncat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * @n: length to copy
 * Return: pointer to resulting string dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i;

	int destlen = strlen(dest);

	int srclen;

	if (strlen(src) > (size_t)n)
		srclen = n;
	else
		srclen = strlen(src);

	for (i = 0; i < srclen ; i++)
	{
		dest[destlen + i] = src[i];
	}

	dest[destlen + srclen] = '\0';

	return (dest);
}
