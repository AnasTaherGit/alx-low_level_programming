#include "main.h"
#include <string.h>
/**
 * _strncpy - Copy from dest to src
 * @dest: Destination
 * @src: Source
 * @n: Length to copy
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	int srclen = strlen(src);

	if (srclen > n)
		srclen = n;

	for (i = 0; i < srclen; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
